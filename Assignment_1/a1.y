%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_IDENTIFIERS 2000
#define MAX_IDENTIFIER_LENGTH 200
void yyerror(char *);
int yylex(void);
char mytext[100];
int lineNumber = 0;

typedef struct hashTableItem {
    int data;
    int key;
} hash_table_item_t;

typedef struct Identifier {
    char type[5];
    char name[MAX_IDENTIFIER_LENGTH];
} identifier_t;

hash_table_item_t *symbolTable[500];

unsigned long hash(char *str);
hash_table_item_t *searchSymbol(char *key, hash_table_item_t* hashTable[]);
void insertSymbol(char *key, int data, hash_table_item_t* hashTable[]);
%}

%token OPEN_PAREN CLOSE_PAREN OPEN_BRACE CLOSE_BRACE OPEN_SQUARE CLOSE_SQUARE COMMA COMPAR SEMI_COLON
%token EQ PLUS MINUS MULTIPLY DIVIDE EXPONENT
%token VALID_TYPE
%token IDENTIFIER NUMBER STRING
%token IF ELSE
%token WHILE
%token RETURN

%left PLUS MINUS COMPAR
%left MULTIPLY DIVIDE
%right UMINUS EXPONENT
%left OPEN_PAREN CLOSE_PAREN
%right ELSE

%union {
    char *str;
    int val;
}

%type <str> identifier

%%

program: lines
;

lines: line
     | line lines
;

line: declaration
    | assignment
    | expression SEMI_COLON
    | block
;

block: functionBlock
     | ifBlock
     | loopBlock
;

declaration: VALID_TYPE assignable SEMI_COLON
	   | VALID_TYPE assignable EQ expression SEMI_COLON;
;

assignment: assignable EQ expression SEMI_COLON
;

assignable: identifier
	  | identifier subscripts
;

subscripts: subscript
       | subscript subscripts
;

subscript: OPEN_SQUARE index CLOSE_SQUARE 
;

functionCall: identifier OPEN_PAREN arguments CLOSE_PAREN
;

arguments:| argument
	 | argument COMMA arguments
;

argument: term | STRING
;

expression:
    expression PLUS expression
    | expression MINUS expression
    | expression COMPAR expression
    | expression MULTIPLY expression
    | expression DIVIDE expression
    | expression EXPONENT expression
    | MINUS expression %prec UMINUS
    | OPEN_PAREN expression CLOSE_PAREN
    | functionCall
    | term
;

functionBlock: VALID_TYPE identifier OPEN_PAREN parameters CLOSE_PAREN
	     OPEN_BRACE
		lines
		returnStatement
	     CLOSE_BRACE
;

returnStatement: | RETURN term SEMI_COLON
;

parameters:| parameter
	 | parameter COMMA parameters
;

parameter: VALID_TYPE identifier
;

ifBlock: ifStatement elsePart
;

ifStatement: IF OPEN_PAREN expression CLOSE_PAREN
             OPEN_BRACE lines CLOSE_BRACE
           ;

elsePart:
        | ELSE ifBlock
        | ELSE OPEN_BRACE lines CLOSE_BRACE
;

loopBlock: whileStatement
;

whileStatement: WHILE OPEN_PAREN expression CLOSE_PAREN
	      OPEN_BRACE
		lines
	      CLOSE_BRACE
;

term: identifier
    | identifier subscripts
    | NUMBER
;

index: identifier
     | NUMBER
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

void insertSymbol(char *key, int data, hash_table_item_t* hashTable[]) {
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
