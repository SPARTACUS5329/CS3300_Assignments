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
typedef struct SymbolTableItem symbol_table_item_t;
typedef struct AssignmentList ass_list_t;
typedef struct Assignment ass_t;
typedef struct QueryList query_list_t;
typedef struct Query query_t;

typedef enum { POINTSTO, PRINTSET, DEREFERENCEABLE } query_e;

typedef enum { AND, STAR, NONE } op_e;

typedef struct Program {
  ass_list_t *assList;
  query_list_t *queryList;
} program_t;

typedef struct SymbolTableItem {
  identifier_t *data;
  int key;
} symbol_table_item_t;

typedef struct IdList {
  int idCount;
  identifier_t **ids;
} id_list_t;

typedef struct Id {
  bool visited;
  char value[MAX_IDENTIFIER_LENGTH];
  int numPoints;
  identifier_t **points;
} identifier_t;

typedef struct AssignmentList {
  int assCount;
  ass_t **lines;
} ass_list_t;

typedef struct Assignment {
  op_e leftOp;
  op_e rightOp;
  identifier_t *lValue;
  identifier_t *rValue;
} ass_t;

typedef struct QueryList {
  int queryCount;
  query_t **queries;
} query_list_t;

typedef struct Query {
  query_e type;
  identifier_t *id1;
  identifier_t *id2;
} query_t;

void error(char *message);
unsigned long hash(char *str);
symbol_table_item_t *searchSymbol(char *key, symbol_table_item_t *hashTable[]);
symbol_table_item_t *insertSymbol(char *key, identifier_t *data,
                                  symbol_table_item_t *hashTable[]);
bool transferPoints(identifier_t *lValue, identifier_t *rValue);
bool addPoint(identifier_t *lValue, identifier_t *rValue);
bool parseAssignments(ass_list_t *assList);
void printSet(identifier_t *id);
bool pointsTo(identifier_t *id1, identifier_t *id2);
bool dereferenceable(identifier_t *id1, identifier_t *id2);
void flushVisited();
int compareLex(const void *a, const void *b);
