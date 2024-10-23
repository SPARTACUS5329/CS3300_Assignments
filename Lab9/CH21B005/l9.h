#pragma once
#include <stdbool.h>
#define MAX_IDENTIFIER_LENGTH 2000
#define MAX_TERMS 2000
#define MAX_VARIABLES 2000
#define MAX_ARGS 2000
#define MAX_DEFINITIONS 2000
#define MAX_QUERIES 2000
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)

typedef struct HashTableItem def_table_item_t;
typedef struct Expression expression_t;
typedef struct Term term_t;
typedef struct Definition definition_t;
typedef struct Query query_t;
typedef struct ArgList arg_list_t;
typedef struct Arg arg_t;

typedef struct Expression {
	term_t **terms;
	int termCount;
} expression_t;

typedef struct Term {
	bool isConstant;
	int coefficient;
	char variable;
	int power;
} term_t;

typedef struct Definition {
	char identifier[MAX_IDENTIFIER_LENGTH];
	expression_t *exp;
} definition_t;

typedef struct Query {
	char identifier[MAX_IDENTIFIER_LENGTH];
	int argCount;
	arg_t **args;
} query_t;

typedef struct ArgList {
	int argCount;
	arg_t **args;
} arg_list_t;

typedef struct Arg {
	char variable;
	int value;
} arg_t;

typedef struct HashTableItem {
  definition_t *data;
  int key;
} def_table_item_t;

typedef struct VarTableItem {
  int data;
  int key;
} var_table_item_t;

void error(char *message);
unsigned long hash(char *str);
def_table_item_t *searchDefinition(char *key);
void insertDefinition(char *key, definition_t *data);
var_table_item_t *searchVar(char *key);
void insertVar(char *key, int data);
