#pragma once
#include <stdbool.h>
#define MAX_VARIABLES 26

typedef struct Node {
  char value;
  struct Node *left;
  struct Node *right;
} node_t;

typedef struct Variable {
  int id;
  char value;
  bool printed;
  struct Variable *onZero;
  struct Variable *onOne;
  struct Variable *parent;
  int parentIndex;
} variable_t;

typedef struct HasTableItem {
  int value;
  int key;
} hash_table_item_t;

variable_t *createBDT(int varIndex);
bool evaluateExpression(node_t *node);
unsigned long hash(char *str);
hash_table_item_t *searchSymbol(char *key);
void insertSymbol(char *key, int data);
bool mergeEquivalentNodes(variable_t *var1, variable_t *var2);
void removeRedundantNodes(variable_t *root);
void printBDD(variable_t *variable);
