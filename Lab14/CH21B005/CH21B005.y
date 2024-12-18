%{
#include "CH21B005.h"
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
		id->neighbours = (id_list_t *)calloc(1, sizeof(id_list_t));
		id->neighbours->ids = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));
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

	printf("Linear Scan:\n");
	printAllocations();

	flushAllocations();

	constructGraph();
	printf("Graph Coloring:\n");
	graphColor();
	printAllocations();
}

void flushAllocations() {
	for (int i = 0; i < program->idList->idCount; i++)
		program->idList->ids[i]->reg = NULL;
	for (int i = 0; i < program->regList->regCount; i++)
		program->regList->regs[i]->var = NULL;
}

void printAllocations() {
	qsort(program->idList->ids, program->N, sizeof(identifier_t *), compareId);
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

void constructGraph() {
	identifier_t *id1, *id2;
	for (int i = 0; i < program->idList->idCount; i++) {
		id1 = program->idList->ids[i];
		for (int j = i + 1; j < program->idList->idCount; j++) {
			id2 = program->idList->ids[j];
			if (overlap(id1, id2)) {
				id1->neighbours->ids[id1->neighbours->idCount++] = id2;
				id2->neighbours->ids[id2->neighbours->idCount++] = id1;
			}
		}
	}

}

void graphColor() {
	qsort(program->idList->ids, program->N, sizeof(identifier_t *), compareDegree);
	identifier_t *id1, *id2, *id3;
	int currRegIndex = 0;
	reg_t **regs = program->regList->regs;
	reg_t *currReg;
	int regCount = program->regList->regCount;

	for (int i = 0; i < program->idList->idCount; i++) {
		if (currRegIndex == regCount)
			break;

		currReg = regs[currRegIndex++];
		id1 = program->idList->ids[i];
		if (id1->reg != NULL)
			continue;
		id1->reg = currReg;
		currReg->var = id1;
		for (int j = 0; j < program->idList->idCount; j++) {
			id2 = program->idList->ids[j];

			if (id2->reg != NULL || overlap(id1, id2))
				continue;

			for (int k = 0; k < program->idList->idCount; k++)
				if (program->idList->ids[k]->reg == currReg)
					break;

			id2->reg = currReg;
			currReg->var = id2;
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

bool overlap(identifier_t *id1, identifier_t *id2) {
	return (id1->startTime < id2->endTime && id1->endTime > id2->startTime) || (id2->startTime < id1->endTime && id2->endTime > id1->startTime);
}

int compareDegree(const void *a, const void *b) {
	identifier_t *id1 = *(identifier_t **)a;
    identifier_t *id2 = *(identifier_t **)b;
	int use1 = id1->endTime - id1->startTime;
	int use2 = id2->endTime - id2->startTime;
    return use2 - use1;
}
