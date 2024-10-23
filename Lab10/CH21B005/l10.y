%{
#include "l10.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void yyerror(char *);
int yylex(void);

char mytext[100];
extern char *yytext;
line_list_t *lineList;
int K;
%}

%token PLUS MINUS LT
%token EQ OPEN_PAREN CLOSE_PAREN OPEN_BRACE CLOSE_BRACE
%token IF ELSE WHILE PRINT
%token VARIABLE NUMBER

%left PLUS MINUS

%left ELSE

%union {
	char *str;
	int val;
	line_list_t *lineList;
	line_t *line;
	expression_t *exp;
	if_else_t *ifElse;
	condition_t *con;
}

%type <str> variable
%type <val> number
%type <lineList> body lines
%type <line> line
%type <exp> expression
%type <ifElse> ifStatement whileStatement
%type <con> condition

%%

program:
	lines number {
		lineList = $1;
		K = $2;
	}
;

lines:
	line {
		line_list_t *lines = (line_list_t *)malloc(sizeof(line_list_t));
		lines->lines = (line_t **)malloc(MAX_LINES * sizeof(line_t *));
		lines->lines[lines->lineCount++] = $1;
		$$ = lines;
	}
	| line lines {
		$2->lines[$2->lineCount++] = $1;
		$$ = $2;
	}
;

line:
	variable EQ expression {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		char var[MAX_VARIABLE_LENGTH];
		for (int i = 0; i < $3->variableCount; i++) {
			strcpy(var, $3->variables[i]);
			symbol_table_item_t *item = searchSymbol((char *)var, $3->symbolTable);
			if (item == NULL)
				error("Invalid symbol");
			int prevCount = item->data;
			insertSymbol(var, prevCount, line->symbolTable);
			strcpy(line->variables[line->variableCount++], var);
		}
		insertSymbol($1, 1, line->symbolTable);
		strcpy(line->variables[line->variableCount++], $1);
		char set[MAX_VARIABLES][MAX_VARIABLE_LENGTH];
		line->variableCount = convertToSet(line->variables, line->variableCount, set);
		$$ = line;
	}
	| PRINT variable {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		insertSymbol($2, 1, line->symbolTable);
		strcpy(line->variables[line->variableCount++], $2);
		$$ = line;
	}
	| ifStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		char var[MAX_VARIABLE_LENGTH];

		if ($1->isLHSVar) {
			insertSymbol((char *)$1->condLHS, 1, line->symbolTable);
			strcpy(line->variables[line->variableCount++], (char *)$1->condLHS);
		}

		if ($1->isRHSVar) {
			insertSymbol((char *)$1->condRHS, 1, line->symbolTable);
			strcpy(line->variables[line->variableCount++], (char *)$1->condRHS);
		}

		int combinedVariableCount = 0;
		char combinedVariables[MAX_VARIABLES][MAX_VARIABLE_LENGTH];

		symbol_table_item_t **ifSymbolTable = (symbol_table_item_t **)malloc(MAX_VARIABLES * sizeof(symbol_table_item_t *));
		symbol_table_item_t **elseSymbolTable = (symbol_table_item_t **)malloc(MAX_VARIABLES * sizeof(symbol_table_item_t *));

		for (int i = 0; i < $1->ifLineCount; i++) {
			line_t *ifLine = $1->ifLines[i];
			for (int j = 0; j < ifLine->variableCount; j++) {
				strcpy(var, ifLine->variables[j]);
				symbol_table_item_t *item = searchSymbol((char *)var, ifLine->symbolTable);
				if (item == NULL)
					error("Invalid symbol");
				int prevCount = item->data;
				insertSymbol(var, prevCount, ifSymbolTable);
				strcpy(combinedVariables[combinedVariableCount++], var);
			}
		}

		if ($1->isMatched) {
			for (int i = 0; i < $1->elseLineCount; i++) {
				line_t *elseLine = $1->elseLines[i];
				for (int j = 0; j < elseLine->variableCount; j++) {
					strcpy(var, elseLine->variables[j]);
					symbol_table_item_t *item = searchSymbol((char *)var, elseLine->symbolTable);
					if (item == NULL)
						error("Invalid symbol");
					int prevCount = item->data;
					insertSymbol(var, prevCount, elseSymbolTable);
					strcpy(combinedVariables[combinedVariableCount++], var);
				}
			}
		}

		char combinedVariableSet[MAX_VARIABLES][MAX_VARIABLE_LENGTH];
		combinedVariableCount = convertToSet(combinedVariables, combinedVariableCount, combinedVariableSet);
		for (int i = 0; i < combinedVariableCount; i++) {
			int count = 0;
			strcpy(var, combinedVariables[i]);
			symbol_table_item_t *item = searchSymbol(var, ifSymbolTable);
			if (item != NULL)
				count = item->data;
			item = searchSymbol(var, elseSymbolTable);
			if (item != NULL)
				count = max(count, item->data);
			
			insertSymbol(var, count, line->symbolTable);
			strcpy(line->variables[line->variableCount++], var);
		}

		char set[MAX_VARIABLES][MAX_VARIABLE_LENGTH];
		line->variableCount = convertToSet(line->variables, line->variableCount, set);
		$$ = line;
	}
	| whileStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		char var[MAX_VARIABLE_LENGTH];
		if ($1->isLHSVar) {
			insertSymbol((char *)$1->condLHS, 11, line->symbolTable);
			strcpy(line->variables[line->variableCount++], (char *)$1->condLHS);
		}
		if ($1->isRHSVar) {
			insertSymbol((char *)$1->condRHS, 11, line->symbolTable);
			strcpy(line->variables[line->variableCount++], (char *)$1->condRHS);
		}
		for (int i = 0; i < $1->ifLineCount; i++) {
			line_t *ifLine = $1->ifLines[i];
			for (int j = 0; j < ifLine->variableCount; j++) {
				strcpy(var, ifLine->variables[j]);
				symbol_table_item_t *item = searchSymbol((char *)var, ifLine->symbolTable);
				if (item == NULL)
					error("Invalid symbol");
				int prevCount = item->data;
				insertSymbol(var, 10 * prevCount, line->symbolTable);
				strcpy(line->variables[line->variableCount++], var);
			}
		}
		char set[MAX_VARIABLES][MAX_VARIABLE_LENGTH];
		line->variableCount = convertToSet(line->variables, line->variableCount, set);
		$$ = line;
	}
;

expression:
	expression PLUS expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		char var[MAX_VARIABLE_LENGTH];
		for (int j = 0; j < $1->variableCount; j++) {
			strcpy(var, $1->variables[j]);
			symbol_table_item_t *item = searchSymbol((char *)var, $1->symbolTable);
			if (item == NULL)
				error("Invalid symbol");
			int prevCount = item->data;
			insertSymbol(var, prevCount, exp->symbolTable);
			strcpy(exp->variables[exp->variableCount++], var);
		}
		for (int j = 0; j < $3->variableCount; j++) {
			strcpy(var, $3->variables[j]);
			symbol_table_item_t *item = searchSymbol((char *)var, $3->symbolTable);
			if (item == NULL)
				error("Invalid symbol");
			int prevCount = item->data;
			insertSymbol(var, prevCount, exp->symbolTable);
			strcpy(exp->variables[exp->variableCount++], var);
		}
		char set[MAX_VARIABLES][MAX_VARIABLE_LENGTH];
		exp->variableCount = convertToSet(exp->variables, exp->variableCount, set);
		$$ = exp;
	}
	| expression MINUS expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		char var[MAX_VARIABLE_LENGTH];
		for (int j = 0; j < $1->variableCount; j++) {
			strcpy(var, $1->variables[j]);
			symbol_table_item_t *item = searchSymbol((char *)var, $1->symbolTable);
			if (item == NULL)
				error("Invalid symbol");
			int prevCount = item->data;
			insertSymbol(var, prevCount, exp->symbolTable);
			strcpy(exp->variables[exp->variableCount++], var);
		}
		for (int j = 0; j < $3->variableCount; j++) {
			strcpy(var, $3->variables[j]);
			symbol_table_item_t *item = searchSymbol((char *)var, $3->symbolTable);
			if (item == NULL)
				error("Invalid symbol");
			int prevCount = item->data;
			insertSymbol(var, prevCount, exp->symbolTable);
			strcpy(exp->variables[exp->variableCount++], var);
		}
		char set[MAX_VARIABLES][MAX_VARIABLE_LENGTH];
		exp->variableCount = convertToSet(exp->variables, exp->variableCount, set);
		$$ = exp;
	}
	| number {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		$$ = exp;
	}
	| variable {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		insertSymbol($1, 1, exp->symbolTable);
		strcpy(exp->variables[exp->variableCount++], $1);
		$$ = exp;
	}
;

ifStatement:
	IF OPEN_PAREN condition CLOSE_PAREN body {
		if_else_t *ifElse = (if_else_t *)malloc(sizeof(if_else_t));
		ifElse->isLHSVar = $3->isLHSVar;
		ifElse->isRHSVar = $3->isRHSVar;
		strcpy(ifElse->condLHS, $3->lhs);
		strcpy(ifElse->condRHS, $3->rhs);
		ifElse->ifLineCount = $5->lineCount;
		ifElse->ifLines = $5->lines;
		$$ = ifElse;
	}
	| ifStatement ELSE body {
		if_else_t *ifElse = (if_else_t *)malloc(sizeof(if_else_t));
		ifElse->isLHSVar = $1->isLHSVar;
		ifElse->isRHSVar = $1->isRHSVar;
		strcpy(ifElse->condLHS, $1->condLHS);
		strcpy(ifElse->condRHS, $1->condRHS);
		ifElse->ifLineCount = $1->ifLineCount;
		ifElse->ifLines = $1->ifLines;
		ifElse->elseLineCount = $3->lineCount;
		ifElse->elseLines = $3->lines;
		ifElse->isMatched = true;
		$$ = ifElse;
	}
;

whileStatement:
	WHILE OPEN_PAREN condition CLOSE_PAREN body {
		if_else_t *whileStatement = (if_else_t *)malloc(sizeof(if_else_t));
		whileStatement->isLHSVar = $3->isLHSVar;
		whileStatement->isRHSVar = $3->isRHSVar;
		strcpy(whileStatement->condLHS, $3->lhs);
		strcpy(whileStatement->condRHS, $3->rhs);
		whileStatement->ifLineCount = $5->lineCount;
		whileStatement->ifLines = $5->lines;
		$$ = whileStatement;
	}
;

body:
	OPEN_BRACE lines CLOSE_BRACE {
		line_list_t *lines = (line_list_t *)malloc(sizeof(line_list_t));
		lines->lineCount = $2->lineCount;
		lines->lines = $2->lines;
		$$ = lines;
	}
;

condition:
	variable LT variable {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->isLHSVar = true;
		con->isRHSVar = true;
		strcpy(con->lhs, $1);
		strcpy(con->rhs, $3);
		$$ = con;
	}
	| number LT variable {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->isRHSVar = true;
		con->isLHSVar = false;
		sprintf(con->lhs, "%d", $1);
		strcpy(con->rhs, $3);
		$$ = con;
	}
	| variable LT number {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->isLHSVar = true;
		con->isRHSVar = false;
		strcpy(con->lhs, $1);
		sprintf(con->rhs, "%d", $3);
		$$ = con;
	}
	| number LT number {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->isLHSVar = false;
		con->isRHSVar = false;
		sprintf(con->lhs, "%d", $1);
		sprintf(con->rhs, "%d", $3);
		$$ = con;
	}
;

number:
	NUMBER {
		$$ = atoi(mytext);
	}
;

variable:
	VARIABLE {
		$$ = strdup(mytext);
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
	lineList = (line_list_t *)malloc(sizeof(line_list_t));
	yyparse();

	int combinedVariableCount = 0;
	char combinedVariables[MAX_VARIABLES][MAX_VARIABLE_LENGTH];
	symbol_table_item_t *combinedSymbolTable[MAX_VARIABLES];
	char var[MAX_VARIABLE_LENGTH];

	for (int i = 0; i < lineList->lineCount; i++) {
		line_t *line = lineList->lines[i];
		for (int j = 0; j < line->variableCount; j++) {
			strcpy(var, line->variables[j]);
			symbol_table_item_t *item = searchSymbol(var, line->symbolTable);
			if (item == NULL)
				error("Invalid symbol");

			insertSymbol(var, item->data, combinedSymbolTable);
			strcpy(combinedVariables[combinedVariableCount++], var);
		}
	}

	char set[MAX_VARIABLES][MAX_VARIABLE_LENGTH];
	combinedVariableCount = convertToSet(combinedVariables, combinedVariableCount, set);
	variable_t *variables = (variable_t *)malloc(combinedVariableCount * sizeof(variable_t));
	for (int i = 0; i < combinedVariableCount; i++) {
		strcpy(var, combinedVariables[i]);
		symbol_table_item_t *item = searchSymbol(var, combinedSymbolTable);
		if (item == NULL)
			error("Invalid symbol");
		variables[i].use = item->data;
		strcpy(variables[i].var, var);
	}

	if (combinedVariableCount < K)
		K = combinedVariableCount;
	qsort(variables, combinedVariableCount, sizeof(variable_t), compareUses);

	char finalVars[K][MAX_VARIABLE_LENGTH];
	for (int i = 0; i < combinedVariableCount; i++) {
		strcpy(finalVars[i], variables[i].var);
	}

	qsort(finalVars, K, MAX_VARIABLE_LENGTH, compareLex);
	for (int i = 0; i < K; i++)
        printf("%s ", finalVars[i]);
}

unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash % MAX_VARIABLES;
}

symbol_table_item_t *searchSymbol(char *key, symbol_table_item_t *symbolTable[]) {
  int hashIndex = hash(key);

  while (symbolTable[hashIndex] != NULL) {
    if (symbolTable[hashIndex]->key == hashIndex)
      return symbolTable[hashIndex];

    ++hashIndex;
    hashIndex %= MAX_VARIABLES;
  }

  return NULL;
}   

void insertSymbol(char *key, int data, symbol_table_item_t *symbolTable[]) {
	int hashIndex = hash(key);
	symbol_table_item_t *item = searchSymbol(key, symbolTable);
	if (item != NULL) {
		item->data += data;
		return;
	}
	item = (symbol_table_item_t *)malloc(sizeof(symbol_table_item_t));
	item->data = data;
	item->key = hashIndex;
	while (symbolTable[hashIndex] != NULL) {
		++hashIndex;
		hashIndex %= MAX_VARIABLES;
	}
	symbolTable[hashIndex] = item;
}

bool existsInSet(char set[][MAX_VARIABLE_LENGTH], int setSize, const char *str) {
    for (int i = 0; i < setSize; i++) {
        if (strcmp(set[i], str) == 0)
            return true;
    }
    return false;
}

int convertToSet(char list[MAX_VARIABLES][MAX_VARIABLE_LENGTH], int listSize, char set[][MAX_VARIABLE_LENGTH]) {
    int setSize = 0;

    for (int i = 0; i < listSize; i++) {
        if (!existsInSet(set, setSize, list[i])) {
            strcpy(set[setSize], list[i]);
            setSize++;
        }
    }
	
	for (int i = 0; i < setSize; i++)
		strcpy(list[i], set[i]);

    return setSize;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int compareUses(const void *a, const void *b) {
    const variable_t *itemA = (const variable_t *)a;
    const variable_t *itemB = (const variable_t *)b;
	if (itemB->use != itemA->use)
		return itemB->use - itemA->use;

	return strcmp(itemA->var, itemB->var);
}

int compareLex(const void *a, const void *b) {
    const char *strA = (const char *)a;
    const char *strB = (const char *)b;
    return strcmp(strA, strB);
}
