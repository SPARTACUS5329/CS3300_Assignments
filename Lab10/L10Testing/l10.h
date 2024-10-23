#pragma once
#include <stdbool.h>
#define MAX_LINES 2000
#define MAX_VARIABLES 2000
#define MAX_VARIABLE_LENGTH 200
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)

typedef struct Variable variable_t;
typedef struct HashTableItem symbol_table_item_t;
typedef struct LineList line_list_t;
typedef struct Line line_t;
typedef struct Expression expression_t;
typedef struct IfElse if_else_t;
typedef struct Condition condition_t;

typedef struct Variable {
  char var[MAX_VARIABLE_LENGTH];
  int use;
} variable_t;

typedef struct HashTableItem {
  int data;
  int key;
} symbol_table_item_t;

typedef struct LineList {
  int lineCount;
  line_t **lines;
} line_list_t;

typedef struct Line {
  int variableCount;
  char variables[MAX_VARIABLES][MAX_VARIABLE_LENGTH];
  symbol_table_item_t *symbolTable[MAX_VARIABLES];
} line_t;

typedef struct Expression {
  int variableCount;
  char variables[MAX_VARIABLES][MAX_VARIABLE_LENGTH];
  symbol_table_item_t *symbolTable[MAX_VARIABLES];
} expression;

typedef struct IfElse {
  bool isMatched;
  bool isLHSVar;
  bool isRHSVar;
  char condLHS[MAX_VARIABLE_LENGTH];
  char condRHS[MAX_VARIABLE_LENGTH];
  int ifLineCount;
  int elseLineCount;
  line_t **ifLines;
  line_t **elseLines;
  symbol_table_item_t *symbolTable[MAX_VARIABLES];
} if_else_t;

typedef struct Condition {
  bool isLHSVar;
  bool isRHSVar;
  char lhs[MAX_VARIABLE_LENGTH];
  char rhs[MAX_VARIABLE_LENGTH];
} condition_t;

void error(char *message);
unsigned long hash(char *str);
symbol_table_item_t *searchSymbol(char *key,
                                  symbol_table_item_t *symbolTable[]);
void insertSymbol(char *key, int data, symbol_table_item_t *symbolTable[]);
bool existsInSet(char set[][MAX_VARIABLE_LENGTH], int setSize, const char *str);
int convertToSet(char list[MAX_VARIABLES][MAX_VARIABLE_LENGTH], int listSize,
                 char set[][MAX_VARIABLE_LENGTH]);
int max(int a, int b);
int compareUses(const void *a, const void *b);
