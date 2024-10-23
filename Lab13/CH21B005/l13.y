%{
#include "l13.h"
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
id_list_t *idList;
%}

%token STAR_TOK AND_TOK EQ SEMI_COLON COMMA
%token IDENTIFIER
%token POINTSTO_TOK PRINTSET_TOK DEREFERENCEABLE_TOK
%token SEPARATOR

%union {
	char *str;
	int val;
	identifier_t *id;
	ass_t *ass;
	ass_list_t *assList;
	query_t *query;
	query_list_t *queryList;
}

%type <id> identifier;
%type <assList> statements;
%type <ass> statement;
%type <queryList> queries;
%type <query> query;

%%

program:
	statements SEPARATOR queries {
		program->assList = $1;
		program->queryList = $3;
	}
;

queries:
	queries query {
		$1->queries[$1->queryCount++] = $2;
		$$ = $1;
	}
	| {
		query_list_t *queryList = (query_list_t *)calloc(1, sizeof(query_list_t));
		queryList->queries = (query_t **)calloc(MAX_QUERIES, sizeof(query_t *));
		$$ = queryList;
	}
;

query:
	PRINTSET_TOK identifier {
		query_t *query = (query_t *)calloc(1, sizeof(query_t));
		query->type = PRINTSET;
		query->id1 = $2;
		$$ = query;
	}
	| POINTSTO_TOK identifier COMMA identifier {
		query_t *query = (query_t *)calloc(1, sizeof(query_t));
		query->type = POINTSTO;
		query->id1 = $2;
		query->id2 = $4;
		$$ = query;
	}
	| DEREFERENCEABLE_TOK identifier COMMA identifier {
		query_t *query = (query_t *)calloc(1, sizeof(query_t));
		query->type = DEREFERENCEABLE;
		query->id1 = $2;
		query->id2 = $4;
		$$ = query;
	}
;

statements:
	statements statement {
		$1->lines[$1->assCount++] = $2;
		$$ = $1;
	}
	| {
		ass_list_t *assList = (ass_list_t *)calloc(1, sizeof(ass_list_t));
		assList->lines = (ass_t **)calloc(MAX_LINES, sizeof(ass_t *));
		$$ = assList;
	}
;

statement:
	identifier EQ identifier SEMI_COLON {
		ass_t *ass = (ass_t *)calloc(1, sizeof(ass_t));
		ass->leftOp = NONE;
		ass->rightOp = NONE;
		symbol_table_item_t *item = searchSymbol($1->value, symbolTable);
		if (item == NULL)
			error("Identifier not found");
		ass->lValue = item->data;
		item = searchSymbol($3->value, symbolTable);
		if (item == NULL)
			error("Identifier not found");
		ass->rValue = item->data;
		$$ = ass;
	}
	| STAR_TOK identifier EQ identifier SEMI_COLON {
		ass_t *ass = (ass_t *)malloc(sizeof(ass_t));
		ass->leftOp = STAR;
		ass->rightOp = NONE;
		symbol_table_item_t *item = searchSymbol($2->value, symbolTable);
		if (item == NULL)
			error("Identifier not found");
		ass->lValue = item->data;
		item = searchSymbol($4->value, symbolTable);
		if (item == NULL)
			error("Identifier not found");
		ass->rValue = item->data;
		$$ = ass;
	}
	| identifier EQ STAR_TOK identifier SEMI_COLON {
		ass_t *ass = (ass_t *)malloc(sizeof(ass_t));
		ass->leftOp = NONE;
		ass->rightOp = STAR;
		symbol_table_item_t *item = searchSymbol($1->value, symbolTable);
		if (item == NULL)
			error("Identifier not found");
		ass->lValue = item->data;
		item = searchSymbol($4->value, symbolTable);
		if (item == NULL)
			error("Identifier not found");
		ass->rValue = item->data;
		$$ = ass;
	}
	| identifier EQ AND_TOK identifier SEMI_COLON {
		ass_t *ass = (ass_t *)malloc(sizeof(ass_t));
		ass->leftOp = NONE;
		ass->rightOp = AND;
		symbol_table_item_t *item = searchSymbol($1->value, symbolTable);
		if (item == NULL)
			error("Identifier not found");
		ass->lValue = item->data;
		item = searchSymbol($4->value, symbolTable);
		if (item == NULL)
			error("Identifier not found");
		ass->rValue = item->data;
		$$ = ass;
	}
;

identifier:
	IDENTIFIER {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->value, mytext);
		id->points = (identifier_t **)malloc(MAX_IDENTIFIERS * sizeof(identifier_t *));
		symbol_table_item_t *item = insertSymbol(id->value, id, symbolTable);
		$$ = item->data;
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
	idList = (id_list_t *)malloc(sizeof(id_list_t *));
	idList->ids = (identifier_t **)malloc(MAX_IDENTIFIERS * sizeof(identifier_t *));
	program = (program_t *)calloc(1, sizeof(program_t));

	yyparse();

	while (parseAssignments(program->assList));

	query_t *query;
	bool res;

	for (int i = 0; i < program->queryList->queryCount; i++) {
		query = program->queryList->queries[i];
		switch (query->type) {
			case PRINTSET:
				printSet(query->id1);
				break;
			case POINTSTO:
				res = pointsTo(query->id1, query->id2);
				res ? printf("Yes") : printf("No");
				break;
			case DEREFERENCEABLE:
				res = dereferenceable(query->id1, query->id2);
				res ? printf("Yes") : printf("No");
				break;
		}
		printf("\n");
		flushVisited();
	}
}

void flushVisited() {
	for (int i = 0; i < idList->idCount; i++)
		idList->ids[i]->visited = false;
}

void printSet(identifier_t *id) {
	char set[id->numPoints][MAX_IDENTIFIER_LENGTH];
	for (int i = 0; i < id->numPoints; i++)
		strcpy(set[i], id->points[i]->value);

	qsort(set, id->numPoints, MAX_IDENTIFIER_LENGTH, compareLex);
	printf("{");

	for (int i = 0; i < id->numPoints; i++) {
		printf("%s", set[i]);
		if (i < id->numPoints - 1)
			printf(",");
	}

	printf("}");
}

bool pointsTo(identifier_t *id1, identifier_t *id2) {
	for (int i = 0; i < id1->numPoints; i++)
		if (id1->points[i] == id2)
			return true;
	return false;
} 

bool dereferenceable(identifier_t *id1, identifier_t *id2) {
	if (id2->visited)
		return false;

	id2->visited = true;
	for (int i = 0; i < id2->numPoints; i++) {
		if (id2->points[i] == id1)
			return true;

		if (dereferenceable(id1, id2->points[i]))
			return true;
	}

	return false;
}

bool parseAssignments(ass_list_t *assList) {
	ass_t *ass;
	identifier_t *lValue, *rValue;
	op_e leftOp, rightOp;
	bool res = false;

	for (int i = 0; i < assList->assCount; i++) {
		ass = assList->lines[i];
		leftOp = ass->leftOp;
		rightOp = ass->rightOp;
		lValue = ass->lValue;
		rValue = ass->rValue;
		if (leftOp == NONE && rightOp == NONE) {
			if (transferPoints(lValue, rValue))  {
				res = true;
			}
		}
		else if (leftOp == NONE && rightOp == AND) {
			if (addPoint(lValue, rValue)) {
				res = true;
			}
		}
		else if (leftOp == STAR && rightOp == NONE) {
			for (int j = 0; j < lValue->numPoints; j++) {
				if (transferPoints(lValue->points[j], rValue)) {
					res = true;
				}
			}
		}
		else if (leftOp == NONE && rightOp == STAR) {
			for (int j = 0; j < rValue->numPoints; j++) {
				if (transferPoints(lValue, rValue->points[j])) {
					res = true;
				}
			}
		}
		else {
			error("Invalid operation");
		}
	}

	return res;
}

bool transferPoints(identifier_t *lValue, identifier_t *rValue) {
	bool res = false;
	for (int i = 0; i < rValue->numPoints; i++)
		if (addPoint(lValue, rValue->points[i]))
			res = true;

	return res;
}

bool addPoint(identifier_t *lValue, identifier_t *rValue) {
	for (int i = 0; i < lValue->numPoints; i++)
		if (lValue->points[i] == rValue)
			return false;

	lValue->points[lValue->numPoints++] = rValue;
	return true;
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
	idList->ids[idList->idCount++] = item->data;
	return item;
}

int compareLex(const void *a, const void *b) {
    const char *strA = (const char *)a;
    const char *strB = (const char *)b;
    return strcmp(strA, strB);
}
