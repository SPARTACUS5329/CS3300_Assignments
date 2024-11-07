#pragma once
#include <set>
#include <stdbool.h>
#define MAX_IDENTIFIERS 2000
#define MAX_IDENTIFIER_LENGTH 200
#define MAX_EXPRESSION_LENGTH 200
#define MAX_LINES 2000
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)

typedef struct Program program_t;
typedef struct LineList line_list_t;
typedef struct Line line_t;
typedef struct AssignmentStatement ass_t;
typedef struct UnaryAssignmentStatement u_ass_t;
typedef struct Expression exp_t;
typedef struct ConditionalJump cond_jump_t;
typedef struct UnconditionalJump uncond_jump_t;
typedef struct LabelDefinition label_def_t;
typedef struct IOStatement io_t;
typedef struct Identifier identifier_t;

typedef enum { IDENTIFIER, NUMBER } term_e;

typedef enum { ASS, UASS, COND_JUMP, UNCOND_JUMP, LABEL_DEF, IO } line_e;

typedef struct Program {
  line_list_t *lineList;
} program_t;

typedef struct LineList {
  int lineCount;
  line_t **lines;
} line_list_t;

typedef struct Line {
  line_e type;
  int lineNumber;
  union {
    ass_t *ass;
    u_ass_t *uass;
    cond_jump_t *condJump;
    uncond_jump_t *uncondJump;
    label_def_t *labelDef;
    io_t *io;
  } line;
  std::set<int> in;
  std::set<int> out;
  std::set<int> use;
  std::set<int> def;
  line_list_t *prev;
  line_list_t *next;
} line_t;

typedef struct AssignmentStatement {
  identifier_t *id;
  exp_t *exp;
} ass_t;

typedef struct UnaryAssignmentStatement {
  identifier_t *lid;
  identifier_t *rid;
} u_ass_t;

typedef struct Expression {
  bool isBinOp;
  term_e lType;
  term_e rType;
  union {
    identifier_t *id;
    int val;
  } lValue;
  union {
    identifier_t *id;
    int val;
  } rValue;
} exp_t;

typedef struct ConditionalJump {
  identifier_t *lid;
  identifier_t *rid;
  identifier_t *label;
} cond_jump_t;

typedef struct UnconditionalJump {
  identifier_t *label;
} uncond_jump_t;

typedef struct LabelDefinition {
  identifier_t *value;
} label_def_t;

typedef struct IOStatement {
  identifier_t *id;
} io_t;

typedef struct Identifier {
  char value[MAX_IDENTIFIER_LENGTH];
} identifier_t;

typedef struct SymbolTableItem {
  void *data;
  int key;
} symbol_table_item_t;

void error(char *message);
unsigned long hash(char *str);
symbol_table_item_t *searchSymbol(char *key, symbol_table_item_t *hashTable[]);
void insertSymbol(char *key, void *data, symbol_table_item_t *hashTable[]);
void constructCFG(line_list_t *lineList);
void stringifyCFG(line_t *root, int maxNodes);
void dfs(line_t *node, int *visited);
