%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "a4.h"

void yyerror(char *);
char mytext[100];
extern int yylex(void);
int lineNumber = 1;

program_t *program;
symbol_table_item_t *labelTable[MAX_LINES];
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
		$2->prev = (line_list_t *)calloc(1, sizeof(line_list_t));
		$2->prev->lines = (line_t **)calloc(MAX_LINES, sizeof(line_t *));
		$2->next = (line_list_t *)calloc(1, sizeof(line_list_t));
		$2->next->lines = (line_t **)calloc(MAX_LINES, sizeof(line_t *));

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
		line->lineNumber = lineNumber;
		$$ = line;
	}
	| unaryAssignmentStatement {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = UASS;
		line->line.uass = $1;
		line->lineNumber = lineNumber;
		$$ = line;
	}
	| conditionalJump {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = COND_JUMP;
		line->line.condJump = $1;
		line->lineNumber = lineNumber;
		$$ = line;
	}
	| unconditionalJump {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = UNCOND_JUMP;
		line->line.uncondJump = $1;
		line->lineNumber = lineNumber;
		$$ = line;
	}
	| labelDefinition {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = LABEL_DEF;
		line->line.labelDef = $1;
		line->lineNumber = lineNumber;
		insertSymbol(line->line.labelDef->value->value, line, labelTable);
		$$ = line;
	}
	| ioStatement {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = IO;
		line->line.io = $1;
		line->lineNumber = lineNumber;
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
	constructCFG(program->lineList);
	stringifyCFG(program->lineList->lines[0], program->lineList->lineCount);

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

void insertSymbol(char *key, void *data, symbol_table_item_t* hashTable[]) {
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

void constructCFG(line_list_t *lineList) {
	line_t *line;
	symbol_table_item_t *item;
    for (int i = 0; i < lineList->lineCount; i++) {
		line = lineList->lines[i];
		switch (line->type) {
		case ASS:
			if (i < lineList->lineCount - 1)
				line->next->lines[line->next->lineCount++] = lineList->lines[i + 1];
		    break;
		case UASS:
			if (i < lineList->lineCount - 1)
				line->next->lines[line->next->lineCount++] = lineList->lines[i + 1];
		    break;
		case COND_JUMP:
			if (i < lineList->lineCount - 1)
				line->next->lines[line->next->lineCount++] = lineList->lines[i + 1];
			item = searchSymbol(line->line.condJump->label->value, labelTable);
			line->next->lines[line->next->lineCount++] = (line_t *) item->data;
		    break;
		case UNCOND_JUMP:
			item = searchSymbol(line->line.uncondJump->label->value, labelTable);
			line->next->lines[line->next->lineCount++] = (line_t *) item->data;
		    break;
		case LABEL_DEF:
			if (i < lineList->lineCount - 1)
				line->next->lines[line->next->lineCount++] = lineList->lines[i + 1];
		    break;
		case IO:
			if (i < lineList->lineCount - 1)
				line->next->lines[line->next->lineCount++] = lineList->lines[i + 1];
		    break;
		}
	}
}

void dfs(line_t *node, int *visited) {
    if (node == NULL || visited[node->lineNumber]) {
        return;
    }

    visited[node->lineNumber] = 1;

    printf("  Node%d [label=\"Line %d\"];\n", node->lineNumber, node->lineNumber);

    if (node->next != NULL) {
        for (int i = 0; i < node->next->lineCount; i++) {
            line_t *nextLine = node->next->lines[i];
            if (nextLine != NULL) {
                printf("  Node%d -> Node%d;\n", node->lineNumber, nextLine->lineNumber);
                
                dfs(nextLine, visited);
            }
        }
    }
}

void stringifyCFG(line_t *root, int maxNodes) {
    printf("digraph CFG {\n");
    printf("  node [shape=box];\n");

    int *visited = (int *)calloc(maxNodes, sizeof(int));

    dfs(root, visited);

    printf("}\n");

    free(visited);
}
