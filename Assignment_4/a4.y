%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "a4.h"

void yyerror(char *);
int yylex(void);
char mytext[100];
int lineNumber = 1;

program_t *program;
symbol_table_item_t *symbolTable[MAX_IDENTIFIERS];
%}

%token PLUS MINUS MULTIPLY DIVIDE NOT
%token COMPAR
%token COLON EQ
%token IF GOTO
%token PRINT READ
%token NUMBER_TOK IDENTIFIER_TOK

%union {
    int val;
	identifier_t *id;
	line_list_t *lineList;
	line_t *line;
	ass_t *ass;
	u_ass_t *uass;
	exp_t *exp;
	cond_jump_t *condJump;
	uncond_jump_t *ucondJump;
	label_def_t *labelDef;
	io_t *io;
}

%type <val> number
%type <id> identifier
%type <lineList> lines
%type <line> line
%type <ass> assignmentStatement
%type <uass> unaryAssignmentStatement
%type <exp> expression
%type <condJump> conditionalJump
%type <ucondJump> unconditionalJump
%type <labelDef> labelDefinition
%type <io> ioStatement

%%
program:
    lines {
		program->lineList = $1;
	}
;

lines:
    lines line {
		$1->lines[$1->lineCount++] = $2;
	}
	| {
		line_list_t *lineList = (line_list_t *)calloc(1, sizeof(line_list_t));
		lineList->lines = (line_t **)calloc(MAX_LINES, sizeof(line_t *));
		$$ = lineList;
	}
;

line:
	assignmentStatement {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = ASS;
		line->line.ass = $1;
		$$ = line;
	}
	| unaryAssignmentStatement {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = UASS;
		line->line.uass = $1;
		$$ = line;
	}
	| conditionalJump {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = COND_JUMP;
		line->line.condJump = $1;
		$$ = line;
	}
	| unconditionalJump {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = UNCOND_JUMP;
		line->line.uncondJump = $1;
		$$ = line;
	}
	| labelDefinition {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = LABEL_DEF;
		line->line.labelDef = $1;
		$$ = line;
	}
	| ioStatement {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = IO;
		line->line.io = $1;
		$$ = line;
	}
;

assignmentStatement:
    identifier EQ expression {
		ass_t *ass = (ass_t *)calloc(1, sizeof(ass_t));
		ass->id = $1;
		ass->exp = $3;
		$$ = ass;
	}
;

expression:
    identifier operator identifier {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = IDENTIFIER;
		exp->rType = IDENTIFIER;
		exp->lValue.id = $1;
		exp->rValue.id = $3;
		$$ = exp;
	}
	| identifier operator number {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = IDENTIFIER;
		exp->rType = NUMBER;
		exp->lValue.id = $1;
		exp->rValue.val = $3;
		$$ = exp;
	}
	| number operator identifier {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = NUMBER;
		exp->rType = IDENTIFIER;
		exp->lValue.val = $1;
		exp->rValue.id = $3;
		$$ = exp;
	}
	| number operator number {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = NUMBER;
		exp->rType = NUMBER;
		exp->lValue.val = $1;
		exp->rValue.val = $3;
		$$ = exp;
	}
	| identifier {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = IDENTIFIER;
		exp->lValue.id = $1;
		$$ = exp;
	}
	| number {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = NUMBER;
		exp->lValue.val = $1;
		$$ = exp;
	}
;

unaryAssignmentStatement:
    identifier EQ unaryOperator identifier {
		u_ass_t *ass = (u_ass_t *)calloc(1, sizeof(u_ass_t));
		ass->lid = $1;
		ass->rid = $4;
		$$ = ass;
	}
;

unaryOperator:
    MINUS
	| NOT
;

conditionalJump:
    IF identifier COMPAR identifier GOTO identifier {
		cond_jump_t *jump = (cond_jump_t *)calloc(1, sizeof(cond_jump_t));
		jump->lid = $2;
		jump->rid = $4;
		jump->label = $6;
		$$ = jump;
	}
;

unconditionalJump:
    GOTO identifier {
		uncond_jump_t *jump = (uncond_jump_t *)calloc(1, sizeof(uncond_jump_t));
		jump->label = $2;
		$$ = jump;
	}
;

labelDefinition:
    identifier COLON {
		label_def_t *labelDef = (label_def_t *)calloc(1, sizeof(label_def_t));
		labelDef->value = $1;
		$$ = labelDef;
	}
;

ioStatement:
    PRINT identifier {
		io_t *io = (io_t *)calloc(1, sizeof(io_t));
		io->id = $2;
		$$ = io;
	}
	| READ identifier {
		io_t *io = (io_t *)calloc(1, sizeof(io_t));
		io->id = $2;
		$$ = io;
	}
;

number:
    NUMBER_TOK {
		$$ = atoi(mytext);
	}
;

identifier:
    IDENTIFIER_TOK {
		identifier_t *id = (identifier_t *)calloc(1, sizeof(identifier_t));
		strcpy(id->value, mytext);
		$$ = id;
	}
;

operator:
    PLUS
	| MINUS
	| MULTIPLY
	| DIVIDE
;

%%

void yyerror(char *message) {
    fprintf(stderr, "syntax error: %d\n", lineNumber);
    exit(1);
}

void error(char *message) {
    perror(message);
	exit(1);
}

int main(void) {
    program = (program_t *)calloc(1, sizeof(program_t));
    yyparse();

    return 0;
}

unsigned long hash(char *str) {
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return hash % MAX_IDENTIFIERS;
}

symbol_table_item_t *searchSymbol(char *key, symbol_table_item_t* hashTable[]) {

	int hashIndex = hash(key);

	while(hashTable[hashIndex] != NULL) {
	  if(hashTable[hashIndex]->key == hashIndex)
		 return hashTable[hashIndex]; 
			
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}        

	return NULL;        
}

void insertSymbol(char *key, identifier_t *data, symbol_table_item_t* hashTable[]) {
	symbol_table_item_t *item;
	item = searchSymbol(key, hashTable);
	if (item != NULL)
		return;
	int hashIndex = hash(key);
	item = (symbol_table_item_t*) malloc(sizeof(symbol_table_item_t));
	item->data = data;
	item->key = hashIndex;

	while(hashTable[hashIndex] != NULL) {
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}

	hashTable[hashIndex] = item;
}
