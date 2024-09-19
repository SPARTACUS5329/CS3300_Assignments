%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "a2.h"
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)

void yyerror(char *);
int yylex(void);
char mytext[100];
char currType[10];
char currScope[MAX_IDENTIFIER_LENGTH] = "global";
int lineNumber = 1;
static int tCount = 0;
static int lCount = 0;

hash_table_item_t *symbolTable[MAX_IDENTIFIERS];
%}

%token OPEN_PAREN CLOSE_PAREN OPEN_BRACE CLOSE_BRACE OPEN_SQUARE CLOSE_SQUARE COMMA COMPAR SEMI_COLON
%token EQ PLUS MINUS MULTIPLY DIVIDE EXPONENT
%token VALID_TYPE IDENTIFIER NUMBER STRING
%token IF ELSE
%token WHILE FOR
%token RETURN MAIN

%left PLUS MINUS COMPAR
%left MULTIPLY DIVIDE
%right UMINUS EXPONENT
%left OPEN_PAREN CLOSE_PAREN
%left ELSE

%union {
    char *str;
    int val;
    identifier_t id;
    expression_t exp;
}

%type <str> identifier validType
%type <val> subscripts
%type <id> assignable term
%type <exp> expression

%%
program:
	functionBlocks mainFunction
;

functionBlocks:
	| functionBlocks functionBlock
;

mainFunction:
	validType MAIN OPEN_PAREN parameters CLOSE_PAREN body
;

lines:
	line
	| line lines
;


line:
	declarationStatement
    | assignment
    | expression SEMI_COLON
    | returnStatement
    | ifStatement
    | loopStatement
    | functionBlock
;

declarationStatement: validType declarations SEMI_COLON
;

declarations: declaration
	| declaration COMMA declarations
;

declaration: assignable EQ expression SEMI_COLON
	| assignable
;

assignment: assignable EQ expression SEMI_COLON {
	    hash_table_item_t *item = searchSymbol($1.name, symbolTable);
	    if (item != NULL)
		if (item->data->depth != $1.depth)
		    yyerror("Invalid location");
		printf("%s = %s\n", $1.displayName, $3.value);
	}
;

assignable: identifier {
	    identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, currScope);
	    strcat(id->name, "_");
	    strcat(id->name, $1);
	    strcpy(id->displayName, $1);
	    strcpy(id->type, currType);
	    id->depth = 0;
		insertSymbol(id->name, id, symbolTable);
		$$ = *id;
	  }
	  | identifier subscripts {
	    identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, currScope);
	    strcat(id->name, "_");
	    strcat(id->name, $1);
	    strcpy(id->displayName, $1);
	    strcpy(id->type, currType);
	    id->depth = $2;
		insertSymbol(id->name, id, symbolTable);
		$$ = *id;
	  }
;

subscripts: subscript {
		$$ = 1;
	}
	| subscript subscripts {
	    $$ = 1 + $2;
    }
;

subscript: OPEN_SQUARE index CLOSE_SQUARE
;

functionCall: identifier OPEN_PAREN arguments CLOSE_PAREN
;

arguments: 
	| argument
	| argument COMMA arguments
;

argument: expression
	| STRING
;

expression: expression PLUS expression {
		  if ($1.depth != $3.depth) error("Invalid operation");
		  expression_t exp = { "\0", $1.depth };
		  printf("t%d = %s + %s\n", tCount, $1.value, $3.value);
		  sprintf(exp.value, "t%d", tCount++);
		  $$ = exp;
    }
    | expression MINUS expression {
		  if ($1.depth != $3.depth) error("Invalid operation");
		  expression_t exp = { "\0", $1.depth };
		  printf("t%d = %s - %s\n", tCount, $1.value, $3.value);
		  sprintf(exp.value, "t%d", tCount++);
		  $$ = exp;
    }
    | expression COMPAR expression {
		  if ($1.depth != $3.depth) error("Invalid operation");
		  expression_t exp = { "\0", $1.depth };
		  printf("t%d = %s %s %s\n", tCount, $1.value, mytext, $3.value);
		  sprintf(exp.value, "t%d", tCount++);
		  $$ = exp;
    }
    | expression MULTIPLY expression {
		  if ($1.depth != $3.depth) error("Invalid operation");
		  expression_t exp = { "\0", $1.depth };
		  printf("t%d = %s * %s\n", tCount, $1.value, $3.value);
		  sprintf(exp.value, "t%d", tCount++);
		  $$ = exp;
    }
    | expression DIVIDE expression {
		  if ($1.depth != $3.depth) error("Invalid operation");
		  expression_t exp = { "\0", $1.depth };
		  printf("t%d = %s / %s\n", tCount, $1.value, $3.value);
		  sprintf(exp.value, "t%d", tCount++);
		  $$ = exp;
    }
    | expression EXPONENT expression {
		  if ($1.depth != $3.depth) error("Invalid operation");
		  expression_t exp = { "\0", $1.depth };
		  printf("t%d = %s ** %s\n", tCount, $1.value, $3.value);
		  sprintf(exp.value, "t%d", tCount++);
		  $$ = exp;
    }
    | MINUS expression %prec UMINUS {
		  expression_t exp = { "\0", $2.depth };
		  printf("t%d = -%s\n", tCount++, $2.value);
		  sprintf(exp.value, "%s", $2.value);
		  $$ = exp;
    }
    | OPEN_PAREN expression CLOSE_PAREN {
		  expression_t exp = { "\0", $2.depth }; 
		  sprintf(exp.value, "%s", $2.value);
		  $$ = exp;
    }
    | functionCall {
		expression_t exp = { "\n", 0 };
		$$ = exp;
    }
    | term {
		expression_t exp = { "\0", 0 };

		if (!$1.isConstant) {
				hash_table_item_t *item = searchSymbol($1.name, symbolTable);
				if (item == NULL)
						error("Undefined identifier");
				exp.depth = item->data->depth - $1.depth;
		}
		printf("t%d = %s\n", tCount++, $1.name);
		sprintf(exp.value, "%s", $1.name);
		$$ = exp;
    }
;

functionBlock: validType functionIdentifier OPEN_PAREN parameters CLOSE_PAREN body
;

functionIdentifier:
		identifier {
				strcpy(currScope, mytext);
		}

returnStatement:
	RETURN expression SEMI_COLON
	| RETURN SEMI_COLON
;

parameters: 
	 | parameter
	 | parameter COMMA parameters
;

parameter: validType assignable
;

ifStatement: IF OPEN_PAREN expression CLOSE_PAREN body ELSE body
	| IF OPEN_PAREN expression CLOSE_PAREN body
;

loopStatement: whileStatement
	| forStatement
;

whileStatement: WHILE OPEN_PAREN expression CLOSE_PAREN body
;

forStatement: FOR OPEN_PAREN assignment expression SEMI_COLON assignable EQ expression CLOSE_PAREN body
;

body: line
    | OPEN_BRACE lines CLOSE_BRACE
;

term: identifier {
		identifier_t id;
		strncpy(id.name, (char *) $1, sizeof(id.name) - 1);
		id.name[sizeof(id.name) - 1] = '\0';
		id.depth = 0;
		$$ = id;
    }
    | identifier subscripts {
		identifier_t id;
		strncpy(id.name, (char *) $1, sizeof(id.name) - 1);
		id.name[sizeof(id.name) - 1] = '\0';
		id.depth = $2;
		$$ = id;
    }
    | NUMBER {
		identifier_t id;
		strcpy(id.name, mytext);
		id.depth = 0;
		id.isConstant = true;
		$$ = id;
    }
;

index: identifier
    | NUMBER
;

validType: VALID_TYPE {
		 $$ = malloc(5 * sizeof(char));
		 strcpy($$, mytext);
		 strcpy(currType, mytext);
		}
;

identifier: IDENTIFIER {
		$$ = strdup(mytext);
	}
;

%%

void yyerror(char *message) {
    fprintf(stderr, "%d\n", lineNumber);
    exit(1);
}

void error(char *message) {
		perror(message);
		exit(1);
}

int main(void) {
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

hash_table_item_t *searchSymbol(char *key, hash_table_item_t* hashTable[]) {

	int hashIndex = hash(key);

	while(hashTable[hashIndex] != NULL) {
	  if(hashTable[hashIndex]->key == hashIndex)
		 return hashTable[hashIndex]; 
			
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}        

	return NULL;        
}

void insertSymbol(char *key, identifier_t *data, hash_table_item_t* hashTable[]) {
	hash_table_item_t *item;
	item = searchSymbol(key, hashTable);
	if (item != NULL) {
		item->data = data;
		return;
	}
	int hashIndex = hash(key);
	item = (hash_table_item_t*) malloc(sizeof(hash_table_item_t));
	item->data = data;
	item->key = hashIndex;

	while(hashTable[hashIndex] != NULL) {
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}

	hashTable[hashIndex] = item;
}
