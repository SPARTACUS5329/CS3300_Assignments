#pragma once
#include <stdbool.h>
#define MAX_IDENTIFIERS 2000
#define MAX_IDENTIFIER_LENGTH 200
#define MAX_EXPRESSION_LENGTH 200
#define MAX_LINES 2000
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)

typedef struct Identifier identifier_t;

typedef struct Identifier {
} identifier_t;

typedef struct HashTableItem {
  identifier_t *data;
  int key;
} hash_table_item_t;

void error(char *message);
unsigned long hash(char *str);
hash_table_item_t *searchSymbol(char *key, hash_table_item_t *hashTable[]);
void insertSymbol(char *key, identifier_t *data,
                  hash_table_item_t *hashTable[]);
