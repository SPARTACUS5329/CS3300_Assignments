#pragma once
#define MAX_IDENTIFIERS 2000
#define MAX_IDENTIFIER_LENGTH 200

typedef struct Identifier {
  char name[MAX_IDENTIFIER_LENGTH];
  char type[10];
  int depth;
} identifier_t;

typedef struct HashTableItem {
  identifier_t *data;
  int key;
} hash_table_item_t;

unsigned long hash(char *str);
hash_table_item_t *searchSymbol(char *key, hash_table_item_t *hashTable[]);
void insertSymbol(char *key, identifier_t *data,
                  hash_table_item_t *hashTable[]);
