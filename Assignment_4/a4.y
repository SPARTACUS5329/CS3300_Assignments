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

hash_table_item_t *symbolTable[MAX_IDENTIFIERS];
%}

%token PLUS MINUS MULTIPLY DIVIDE NOT
%token COMPAR
%token COLON EQ
%token IF GOTO
%token PRINT READ
%token NUMBER IDENTIFIER

%%
program:
    lines
;

lines:
    | line lines
;

line:
	assignmentStatement
	| unaryAssignmentStatement
	| conditionalJump
	| unconditionalJump
	| labelDefinition
	| ioStatement
;

assignmentStatement:
    identifier EQ expression
;

expression:
    identifier operator identifier
	| identifier operator number
	| number operator identifier
	| number operator number
	| identifier
	| number
;

unaryAssignmentStatement:
    identifier EQ unaryOperator identifier
;

unaryOperator:
    MINUS
	| NOT
;

conditionalJump:
    IF identifier COMPAR identifier GOTO identifier
;

unconditionalJump:
    GOTO identifier
;

labelDefinition:
    identifier COLON
;

ioStatement:
    PRINT identifier
	| READ identifier
;

number:
    NUMBER
;

identifier:
    IDENTIFIER
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
	if (item != NULL)
		return;
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
