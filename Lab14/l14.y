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
		if (num > program->maxTime)
			program->maxTime = num;
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
		reg_t *reg = (reg_t *)calloc(1, sizeof(reg_t));
		reg->id = i + 1;
		regList->regs[regList->regCount++] = reg;
	}

	program->regList = regList;
	linearScan();
	identifier_t *id;

	for (int i = 0; i < program->maxTime; i++) {
		for (int j = 0; j < program->idList->idCount; j++) {
			id = program->idList->ids[j];
			if (i < id->startTime || i >= id->endTime)
				continue;

			printf("%s %d ", id->value, i);
			if (id->reg != NULL)
				printf("%d", id->reg->id);
			else
				printf("memory");
			printf("\n");
		}
	}
}

void linearScan() {
	qsort(program->idList->ids, program->N, sizeof(identifier_t *), compareId);
	int idCount = program->idList->idCount;
	identifier_t **ids = program->idList->ids;
	identifier_t *id;
	reg_t **regs = program->regList->regs;
	int regCount = program->regList->regCount;
	reg_t *reg;

	for (int i = 1; i <= program->maxTime; i++) {
		for (int j = 0; j < regCount; j++) {
			reg = regs[j];

			if (reg->var != NULL) {
				if (reg->var->endTime == i)
					reg->var = NULL;
				else
					continue;
			}

			for (int k = 0; k < idCount; k++) {
				id = ids[k];
				if (id->startTime == i && id->reg == NULL) {
					id->reg = reg;
					reg->var = id;
					break;
				}
			}
		}
	}
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
