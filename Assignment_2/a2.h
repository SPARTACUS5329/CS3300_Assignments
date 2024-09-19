#pragma once
#include <stdbool.h>
#define MAX_IDENTIFIERS 2000
#define MAX_IDENTIFIER_LENGTH 200
#define MAX_EXPRESSION_LENGTH 200

typedef struct Identifier {
  char name[MAX_IDENTIFIER_LENGTH];
  char displayName[MAX_IDENTIFIER_LENGTH];
  char type[10];
  int depth;
  bool isConstant;
} identifier_t;

typedef struct Expression {
  char value[MAX_EXPRESSION_LENGTH];
  int depth;
  bool isConstant;
} expression_t;

typedef struct HashTableItem {
  identifier_t *data;
  int key;
} hash_table_item_t;

void error(char *message);
unsigned long hash(char *str);
hash_table_item_t *searchSymbol(char *key, hash_table_item_t *hashTable[]);
void insertSymbol(char *key, identifier_t *data,
                  hash_table_item_t *hashTable[]);
