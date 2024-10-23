#pragma once
#include <stdbool.h>
#define MAX_PRODUCTIONS 2000
#define MAX_RULES 2000
#define MAX_RULE_SIZE 2000
#define MAX_QUERIES 2000
#define MAX_QUERY_SIZE 20
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)

typedef struct Terminal terminal_t;
typedef struct Production production_t;

struct Production {
  int id;
  char value[4];
  char rules[MAX_RULES][MAX_RULE_SIZE];
  int numRules;
  bool nullable;
  int numFirst;
  int numFollow;
  int epsIndex;
  char first[MAX_RULES];
  char follow[MAX_RULES];
};

typedef struct SymbolTableItem {
  production_t *data;
  int key;
} symbol_table_item_t;

typedef struct ParsingTableItem {
  int data;
  int key;
} parsing_table_item_t;

unsigned long hash(char *str);
symbol_table_item_t *searchSymbol(char *key);
parsing_table_item_t *searchParsingSymbol(char *key);
void insertSymbol(char *key, production_t *data);
void insertParsingSymbol(char *key, int data);
void createFirstSet(production_t *production);
void createFollowSet(production_t *production);
void error(char *message);
bool existsInSet(char set[], int setSize, char ch);
int charArrayToSet(char input[], int inputSize, char set[]);
void queryFirst(production_t *production);
void queryFollow(production_t *production);
void queryProd(production_t *production, char *terminal);
