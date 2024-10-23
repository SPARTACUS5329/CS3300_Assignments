#pragma once
#include <stdbool.h>
#define MAX_DEPTH 2000
#define MAX_FUNCTIONS 2000
#define MAX_IDENTIFIERS 2000
#define MAX_IDENTIFIER_LENGTH 200
#define MAX_QUERIES 2000
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)

typedef struct Id identifier_t;
typedef struct SymbolTableItem symbol_table_item_t;
typedef struct FunList fun_list_t;
typedef struct Fun fun_t;
typedef struct Var var_t;
typedef struct QueryList query_list_t;
typedef struct Query query_t;
typedef struct DeadQuery dead_query_t;
typedef struct ReachQuery reach_query_t;
typedef struct SelfRecursive self_recursive_query_t;
typedef struct EventuallyRecursive eventually_recursive_query_t;
typedef struct CoRecursive co_recursive_query_t;
typedef struct DepthQuery depth_query_t;
typedef struct AssignmentList ass_list_t;
typedef struct Assignment ass_t;

typedef enum { VAR, FUN } id_e;
typedef enum { COMPAR_EQ, COMPAR_LT, COMPAR_GT } cmp_e;
typedef enum {
  DEAD,
  REACHABLE,
  SELF_RECURSIVE,
  EVENTUALLY_RECURSIVE,
  CO_RECURSIVE,
  DEPTH
} query_e;

typedef struct SymbolTableItem {
  identifier_t *data;
  int key;
} symbol_table_item_t;

typedef struct Id {
  id_e type;
  union {
    var_t *var;
    fun_t *fun;
  } data;
} identifier_t;

typedef struct Var {
  char name[MAX_IDENTIFIER_LENGTH];
  int value;
} var_t;

typedef struct FunList {
  int numFuns;
  fun_t **funs;
} fun_list_t;

typedef struct Fun {
  bool visited;
  char name[MAX_IDENTIFIER_LENGTH];
  int numNeighbours;
  fun_t **neighbours;
} fun_t;

typedef struct DeadQuery {
  fun_t *fun;
} dead_query_t;

typedef struct DepthQuery {
  fun_t *fun;
} depth_query_t;

typedef struct SelfRecursive {
  fun_t *fun;
} self_recursive_query_t;

typedef struct CoRecursive {
  fun_t *fun1;
  fun_t *fun2;
} co_recursive_query_t;

typedef struct EventuallyRecursive {
  fun_t *fun;
} eventually_recursive_query_t;

typedef struct ReachQuery {
  fun_t *src;
  fun_t *dest;
} reach_query_t;

typedef struct QueryList {
  int queryCount;
  query_t **queries;
} query_list_t;

typedef struct Query {
  query_e type;
  union {
    dead_query_t *dead;
    reach_query_t *reach;
    self_recursive_query_t *selfRecursive;
    eventually_recursive_query_t *eventuallyRecursive;
    co_recursive_query_t *coRecursive;
    depth_query_t *depth;
  } query;
} query_t;

typedef struct AssignmentList {
  int assCount;
  ass_t **assignments;
} ass_list_t;

typedef struct Assignment {
  var_t *var;
  int value;
} ass_t;

void error(char *message);
unsigned long hash(char *str);
symbol_table_item_t *searchSymbol(char *key, symbol_table_item_t *hashTable[]);
void insertSymbol(char *key, identifier_t *data,
                  symbol_table_item_t *hashTable[]);
bool reachable(fun_t *start, fun_t *target);
bool isSelfRecursive(fun_t *fun);
bool isCoRecursive(fun_t *fun1, fun_t *fun2);
int depth(fun_t *fun);
void flushVisited();
int max(int a, int b);
