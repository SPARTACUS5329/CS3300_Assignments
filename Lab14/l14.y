%{
#include "l14.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void yyerror(char *);
int yylex(void);
char mytext[100];
extern char *yytext;

symbol_table_item_t *symbolTable[MAX_IDENTIFIERS];
program_t *program;
int maxTime;
%}

%token IDENTIFIER NUMBER

%union {
	char *str;
	int val;
	identifier_t *id;
	id_list_t *idList;
}

%type <id> identifier interval
%type <idList> intervals
%type <val> number

%%

program:
	number number intervals {
		program->K = $1;
		program->N = $2;
		program->idList = $3;
	}
;

intervals:
	intervals interval {
		$1->ids[$1->idCount++] = $2;
		$$ = $1;
	}
	| {
		id_list_t *idList = (id_list_t *)calloc(1, sizeof(id_list_t));
		idList->ids = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));
		$$ = idList;
	}
;

interval:
	identifier number number {
		$1->startTime = $2;
		$1->endTime = $3;
		$$ = $1;
	}
;

identifier:
	IDENTIFIER {
		identifier_t *id = (identifier_t *)calloc(1, sizeof(identifier_t));
		strcpy(id->value, mytext);
		id->neighbours = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));
		symbol_table_item_t *item = insertSymbol(id->value, id, symbolTable);
		$$ = item->data;
	}
;

number:
	NUMBER {
		int num = atoi(mytext);
		if (num > maxTime);
			maxTime = num;
		$$ = num;
	}
;

%%

void yyerror(char *message) {
	fprintf(stderr, "syntax error\n");
	exit(1);
}

void error(char *message) {
	perror(message);
	exit(1);
}

int main() {
	program = (program_t *)calloc(1, sizeof(program_t));
	yyparse();
	reg_list_t *regList = (reg_list_t *)calloc(1, sizeof(reg_list_t));
	regList->regs = (reg_t **)calloc(program->K, sizeof(reg_t *));
	for (int i = 0; i < program->K; i++) {
		reg_t *reg = (reg_t *)malloc(sizeof(reg_t));
		reg->id = i + 1;
		reg->available = true;
		regList->regs[i] = reg;
	}

	program->regList = regList;
	linearScan();
}

void linearScan() {
	qsort(program->idList->ids, program->N, sizeof(identifier_t *), compareId);
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

symbol_table_item_t *insertSymbol(char *key, identifier_t *data, symbol_table_item_t* hashTable[]) {
	symbol_table_item_t *item;
	item = searchSymbol(key, hashTable);
	if (item != NULL)
		return item;

	int hashIndex = hash(key);
	item = (symbol_table_item_t*) malloc(sizeof(symbol_table_item_t));
	item->data = data;
	item->key = hashIndex;

	while(hashTable[hashIndex] != NULL) {
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}

	hashTable[hashIndex] = item;
	return item;
}

int compareId(const void *a, const void *b) {
	identifier_t *id1 = *(identifier_t **)a;
    identifier_t *id2 = *(identifier_t **)b;
    return strcmp(id1->value, id2->value);
}
