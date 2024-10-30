#pragma once
#include <stdbool.h>
#define MAX_LINES 2000
#define MAX_IDENTIFIERS 2000
#define MAX_IDENTIFIER_LENGTH 200
#define MAX_QUERIES 2000
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)

typedef struct Program program_t;
typedef struct IdList id_list_t;
typedef struct Id identifier_t;
typedef struct RegList reg_list_t;
typedef struct Reg reg_t;
typedef struct SymbolTableItem symbol_table_item_t;

typedef struct Program {
  int K;
  int N;
  int maxTime;
  id_list_t *idList;
  reg_list_t *regList;
} program_t;

typedef struct IdList {
  int idCount;
  identifier_t **ids;
} id_list_t;

typedef struct Id {
  char value[MAX_IDENTIFIER_LENGTH];
  int startTime;
  int endTime;
  reg_t *reg;
  identifier_t **neighbours;
} identifier_t;

typedef struct RegList {
  int regCount;
  reg_t **regs;
} reg_list_t;

typedef struct Reg {
  int id;
  identifier_t *var;
} reg_t;

typedef struct SymbolTableItem {
  identifier_t *data;
  int key;
} symbol_table_item_t;

void error(char *message);
unsigned long hash(char *str);
symbol_table_item_t *searchSymbol(char *key, symbol_table_item_t *hashTable[]);
symbol_table_item_t *insertSymbol(char *key, identifier_t *data,
                                  symbol_table_item_t *hashTable[]);
void linearScan();
int compareId(const void *id1, const void *id2);
