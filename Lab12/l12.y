%{
#include "l12.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void yyerror(char *);
int yylex(void);
char mytext[100];
extern char *yytext;
char currScope[MAX_IDENTIFIER_LENGTH];

fun_t *currFun;
symbol_table_item_t *varTable[MAX_IDENTIFIERS];
symbol_table_item_t *funTable[MAX_IDENTIFIERS];
fun_list_t *funList;
query_list_t *queryList;
int scopeReachability[MAX_DEPTH] = { 1 };
static int scopeCount = 1;
%}

%token PLUS MINUS COMPAR
%token RETURN INT MAIN
%token EQ OPEN_PAREN CLOSE_PAREN OPEN_BRACE CLOSE_BRACE
%token SEMI_COLON SHORT_OR SHORT_AND
%token VOID IF ELSE
%token IDENTIFIER NUMBER
%token DEAD_TOK REACHABLE_TOK SELF_RECURSIVE_TOK EVENTUALLY_RECURSIVE_TOK CO_RECURSIVE_TOK DEPTH_TOK
%token COMMA SEPARATOR

%left PLUS MINUS

%left SHORT_OR 
%left SHORT_AND

%left ELSE

%union {
	char *str;
	int val;
	cmp_e cmp;
	fun_t *fun;
	fun_list_t *funList;
	query_list_t *queryList;
	query_t *query;
}

%type <str> identifier functionName
%type <val> expression condition number ifCondition
%type <cmp> compar
%type <fun> functionCall functionDefinition mainFunction
%type <funList> statement statements ifStatement ifThenStatement ifThenElseStatement body functionDefinitions
%type <queryList> queries;
%type <query> query;

%%

program:
	functionDefinitions SEPARATOR queries {
		funList = $1;
		queryList = $3;
	}
;

queries:
	queries query {
		$1->queries[$1->queryCount++] = $2;
		$$ = $1;
	}
	| query {
		query_list_t *queryList = (query_list_t *)malloc(sizeof(query_list_t));
		queryList->queries = (query_t **)malloc(MAX_QUERIES * sizeof(query_t *));
		queryList->queries[queryList->queryCount++] = $1;
		$$ = queryList;
	}
;

query:
	DEAD_TOK functionName {
		symbol_table_item_t *item = searchSymbol($2, funTable);
		if (item == NULL)
			error("Function not found");

		fun_t *fun = item->data->data.fun;

		dead_query_t *dead = (dead_query_t *)malloc(sizeof(dead_query_t));
		dead->fun = fun;

		query_t *query = (query_t *)malloc(sizeof(query_t));
		query->type = DEAD;
		query->query.dead = dead;
		$$ = query;
	}
	| REACHABLE_TOK functionName COMMA functionName {
		symbol_table_item_t *item = searchSymbol($2, funTable);
		if (item == NULL)
			error("Source function not found");

		fun_t *src = item->data->data.fun;

		item = searchSymbol($4, funTable);
		if (item == NULL)
			error("Destination function not found");

		fun_t *dest = item->data->data.fun;

		reach_query_t *reach = (reach_query_t *)malloc(sizeof(reach_query_t));
		reach->src = src;
		reach->dest = dest;
		
		query_t *query = (query_t *)malloc(sizeof(query_t));
		query->type = REACHABLE;
		query->query.reach = reach;
		$$ = query;
	}
	| SELF_RECURSIVE_TOK functionName {
		symbol_table_item_t *item = searchSymbol($2, funTable);
		if (item == NULL)
			error("Function not found");

		fun_t *fun = item->data->data.fun;

		self_recursive_query_t *selfRecursive = (self_recursive_query_t *)malloc(sizeof(self_recursive_query_t));
		selfRecursive->fun = fun;

		query_t *query = (query_t *)malloc(sizeof(query_t));
		query->type = SELF_RECURSIVE;
		query->query.selfRecursive = selfRecursive;
		$$ = query;
	}
	| EVENTUALLY_RECURSIVE_TOK functionName {
		symbol_table_item_t *item = searchSymbol($2, funTable);
		if (item == NULL)
			error("Function not found");

		fun_t *fun = item->data->data.fun;

		eventually_recursive_query_t *eventuallyRecursive = (eventually_recursive_query_t *)malloc(sizeof(eventually_recursive_query_t));
		eventuallyRecursive->fun = fun;

		query_t *query = (query_t *)malloc(sizeof(query_t));
		query->type = EVENTUALLY_RECURSIVE;
		query->query.eventuallyRecursive = eventuallyRecursive;
		$$ = query;
	}
	| CO_RECURSIVE_TOK functionName COMMA functionName {
		symbol_table_item_t *item = searchSymbol($2, funTable);
		if (item == NULL)
			error("Source function not found");

		fun_t *fun1 = item->data->data.fun;

		item = searchSymbol($4, funTable);
		if (item == NULL)
			error("Destination function not found");

		fun_t *fun2 = item->data->data.fun;

		co_recursive_query_t *coRecursive = (co_recursive_query_t *)malloc(sizeof(co_recursive_query_t));
		coRecursive->fun1 = fun1;
		coRecursive->fun2 = fun2;
		
		query_t *query = (query_t *)malloc(sizeof(query_t));
		query->type = CO_RECURSIVE;
		query->query.coRecursive = coRecursive;
		$$ = query;
	}
	| DEPTH_TOK functionName {
		symbol_table_item_t *item = searchSymbol($2, funTable);
		if (item == NULL)
			error("Function not found");

		fun_t *fun = item->data->data.fun;

		depth_query_t *depth = (depth_query_t *)malloc(sizeof(depth_query_t));
		depth->fun = fun;

		query_t *query = (query_t *)malloc(sizeof(query_t));
		query->type = DEPTH;
		query->query.depth = depth;
		$$ = query;
	}
;

functionName:
	identifier {
		$$ = $1;
	}
	| MAIN {
		$$ = "main";
	}

functionDefinitions:
	functionDefinition functionDefinitions {
		$2->funs[$2->numFuns++] = $1;
		$$ = $2;
	}
	| mainFunction {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_IDENTIFIERS * sizeof(fun_t *));
		funList->funs[funList->numFuns++] = $1;
		$$ = funList;
	}
;

functionDefinition:
	VOID identifier { 
		symbol_table_item_t *item = searchSymbol($2, funTable);
		if (item == NULL) {
			currFun = (fun_t *)malloc(sizeof(fun_t));
			strcpy(currFun->name, $2);

			identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
			id->type = FUN;
			id->data.fun = currFun;
			insertSymbol(currFun->name, id, funTable);
		} else {
			currFun = item->data->data.fun;
		}

		strcpy(currScope, currFun->name);
	} OPEN_PAREN CLOSE_PAREN body {
		currFun->neighbours = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		for (int i = 0; i < $6->numFuns; i++)
			currFun->neighbours[currFun->numNeighbours++] = $6->funs[i];

		$$ = currFun;
	}
;

mainFunction:
	INT MAIN { 
		currFun = (fun_t *)malloc(sizeof(fun_t));
		strcpy(currFun->name, "main");

		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		id->type = FUN;
		id->data.fun = currFun;
		insertSymbol(currFun->name, id, funTable);

		strcpy(currScope, currFun->name);
	} OPEN_PAREN CLOSE_PAREN body {
		currFun->neighbours = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		for (int i = 0; i < $6->numFuns; i++)
			currFun->neighbours[currFun->numNeighbours++] = $6->funs[i];
		$$ = currFun;
	}
;

body:
	OPEN_BRACE intDeclarations statements returnStatement CLOSE_BRACE {
		$$ = $3;
	}
;

intDeclarations:
	| intDeclaration intDeclarations
;

intDeclaration:
	INT identifier SEMI_COLON {
		char varStr[MAX_IDENTIFIER_LENGTH];
		sprintf(varStr, "%s_%s", currScope, $2);

		var_t *var = (var_t *)malloc(sizeof(var_t));
		strcpy(var->name, $2);

		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		id->type = VAR;
		id->data.var = var;
		insertSymbol(varStr, id, varTable);
	}
;

statements:
	statement statements {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		for (int i = 0; i < $1->numFuns; i++)
			funList->funs[funList->numFuns++] = $1->funs[i];
		for (int i = 0; i < $2->numFuns; i++)
			funList->funs[funList->numFuns++] = $2->funs[i];
		$$ = funList;
	}
	| {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		$$ = funList;
	}
;

statement:
	assignment {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		$$ = funList;
	}
	| ifStatement {
		$$ = $1;
	}
	| functionCall {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		funList->funs[funList->numFuns++] = $1;
		$$ = funList;
	}
;

assignment:
	identifier EQ expression SEMI_COLON {
		if (scopeReachability[scopeCount - 1]) {
			char varStr[MAX_IDENTIFIER_LENGTH];
			sprintf(varStr, "%s_%s", currScope, $1);

			symbol_table_item_t *item = searchSymbol(varStr, varTable);
			if (item == NULL)
				error("Undeclared variable");

			var_t *var = item->data->data.var;
			var->value = $3;
		}
	}
;

ifStatement:
	ifThenElseStatement {
		$$ = $1;
	}
	| ifThenStatement {
		$$ = $1;
	}
;

ifCondition:
	OPEN_PAREN condition CLOSE_PAREN {
		if (!scopeReachability[scopeCount - 1])
			scopeReachability[scopeCount++] = 0;
		else
			scopeReachability[scopeCount++] = $2;
		$$ = $2;
	}
;

ifThenStatement:
	IF ifCondition OPEN_BRACE statements CLOSE_BRACE {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		if ($2 == 1)
			for (int i = 0; i < $4->numFuns; i++)
				funList->funs[funList->numFuns++] = $4->funs[i];
		scopeCount--;
		$$ = funList;
	}
;

ifThenElseStatement:
	IF ifCondition OPEN_BRACE statements CLOSE_BRACE {
		scopeCount--;
	} ELSE OPEN_BRACE statements CLOSE_BRACE {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		if ($2 == 1)
			for (int i = 0; i < $4->numFuns; i++)
				funList->funs[funList->numFuns++] = $4->funs[i];
		else
			for (int i = 0; i < $9->numFuns; i++)
				funList->funs[funList->numFuns++] = $9->funs[i];
		scopeCount--;
		$$ = funList;
	}
;

functionCall:
	identifier OPEN_PAREN CLOSE_PAREN SEMI_COLON {
		symbol_table_item_t *item = searchSymbol($1, funTable);
		fun_t *fun;
		if (item == NULL) {
			fun = (fun_t *)malloc(sizeof(fun_t));
			strcpy(fun->name, $1);
			identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
			id->type = FUN;
			id->data.fun = fun;
			insertSymbol(fun->name, id, funTable);
		} else {
			fun = item->data->data.fun;
		}
		$$ = fun;
	}
;

condition:
	condition SHORT_AND condition {
		$$ = $1 && $3;
	}
	| condition SHORT_OR condition {
		$$ = $1 || $3;
	}
	| OPEN_PAREN condition CLOSE_PAREN {
		$$ = $2;
	}
	| expression compar expression {
		switch ($2) {
			case COMPAR_EQ:
				$$ = $1 == $3;
				break;
			case COMPAR_LT:
				$$ = $1 < $3;
				break;
			case COMPAR_GT:
				$$ = $1 > $3;
				break;
			default:
				error("Invalid comparison operation");
		}
	}
;

expression:
	expression PLUS expression {
		$$ = $1 + $3;
	}
	| expression MINUS expression {
		$$ = $1 - $3;
	}
	| OPEN_PAREN expression CLOSE_PAREN {
		$$ = $2;
	}
	| identifier {
		char varStr[MAX_IDENTIFIER_LENGTH];
		sprintf(varStr, "%s_%s", currScope, $1);

		symbol_table_item_t *item = searchSymbol(varStr, varTable);
		if (item == NULL)
			error("Undeclared variable");
		var_t *var = item->data->data.var;
		$$ = var->value;
	}
	| number {
		$$ = $1;
	}
;

compar:
	COMPAR {
		if (streq(mytext, "==", 2))
			$$ = COMPAR_EQ;
		else if (streq(mytext, "<", 1))
			$$ = COMPAR_LT;
		else if (streq(mytext, ">", 1))
			$$ = COMPAR_GT;
		else {
			printf("%s\n", mytext);
			error("Unsupported comparison operator");
		}
	}
;

identifier:
	IDENTIFIER {
		$$ = strdup(mytext);
	}
;

number:
	NUMBER {
		$$ = atoi(mytext);
	}
;

returnStatement:
	RETURN SEMI_COLON
	| RETURN NUMBER SEMI_COLON
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
	funList = (fun_list_t *)malloc(sizeof(fun_list_t));
	queryList = (query_list_t *)malloc(sizeof(query_list_t));
	yyparse();

	symbol_table_item_t *item = searchSymbol("main", funTable);
	if (item == NULL)
		error("Main function not found");

	fun_t *mainFunction = item->data->data.fun;
	query_t *query;
	bool res;
	for (int i = 0; i < queryList->queryCount; i++) {
		query = queryList->queries[i];
		switch (query->type) {
			case DEAD:
				reachable(mainFunction, query->query.dead->fun)
				? printf("No") : printf("Yes");
				break;
			case REACHABLE:
				reachable(query->query.reach->src, query->query.reach->dest)
				? printf("Yes") : printf("No");
				break;
			case SELF_RECURSIVE:
				isSelfRecursive(query->query.selfRecursive->fun)
				? printf("Yes") : printf("No");
				break;
			case EVENTUALLY_RECURSIVE:
				!isSelfRecursive(query->query.selfRecursive->fun)
				&& reachable(query->query.selfRecursive->fun, query->query.selfRecursive->fun)
				? printf("Yes") : printf("No");
				break;
			case CO_RECURSIVE:
				isCoRecursive(query->query.coRecursive->fun1, query->query.coRecursive->fun2)
				? printf("Yes") : printf("No");
				break;
			case DEPTH:
				printf("%d", depth(query->query.depth->fun));
				break;
		}
		printf("\n");
		flushVisited();
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

void flushVisited() {
	for (int i = 0; i < funList->numFuns; i++)
		funList->funs[i]->visited = false;
}

bool reachable(fun_t *start, fun_t *target) {
	if (start->visited)
		return false;

	start->visited = true;

	for (int i = 0; i < start->numNeighbours; i++) {
		fun_t *neighbour = start->neighbours[i];
		if (neighbour == target)
			return true;
		if (reachable(neighbour, target))
			return true;
	}
	return false;
}

bool isSelfRecursive(fun_t *fun) {
	for (int i = 0; i < fun->numNeighbours; i++)
		if (fun->neighbours[i] == fun)
			return true;
	return false;
}

bool isCoRecursive(fun_t *fun1, fun_t *fun2) {
	bool flag = false;
	for (int i = 0; i < fun1->numNeighbours; i++)
		if (fun1->neighbours[i] == fun2) {
			flag = true;
			break;
		}

	if (!flag)
		return false;

	for (int i = 0; i < fun2->numNeighbours; i++)
		if (fun2->neighbours[i] == fun1)
			return true;

	return false;
}

int depth(fun_t *fun) {
	if (isSelfRecursive(fun) || reachable(fun, fun)) {
		flushVisited();
		return -1;
	}

	fun->visited = true;

	int d = 0;
	for (int i = 0; i < fun->numNeighbours; i++) {
		fun_t *neighbour = fun->neighbours[i];
		int res = depth(neighbour);
		if (res == -1)
			return -1;

		d = max(d, 1 + res);
	}

	return d;
}

int max(int a, int b) {
	return a > b ? a : b;
}
