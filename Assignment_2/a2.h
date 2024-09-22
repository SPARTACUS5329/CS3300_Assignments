#pragma once
#include <stdbool.h>
#define MAX_IDENTIFIERS 2000
#define MAX_ARGS 2000
#define MAX_ARG_SIZE 2000
#define MAX_FUNCTION_CALLS 2000
#define MAX_IDENTIFIER_LENGTH 200
#define MAX_EXPRESSION_LENGTH 200
#define MAX_LINES 2000
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)

typedef struct Identifier identifier_t;
typedef struct DeclarationStatement declaration_statement_t;
typedef struct Declaration declaration_t;
typedef struct DeclarationList declaration_list_t;
typedef struct AssignmentStatement assignment_statement_t;
typedef struct ReturnStatement return_statement_t;
typedef struct IfElseStatement if_else_statement_t;
typedef struct LoopStatement loop_statement_t;
typedef struct FunctionDefinition function_def_t;
typedef struct Expression expression_t;
typedef struct FunctionCall function_call_t;
typedef struct Parameter param_t;
typedef struct ParamList param_list_t;
typedef struct Arg arg_t;
typedef struct ArgList arg_list_t;
typedef struct Line line_t;
typedef struct LineList line_list_t;
typedef struct WhileLoop while_loop_t;
typedef struct ForLoop for_loop_t;

typedef enum {
  PLUS,
  MINUS,
  COMPAR_EQ,
  COMPAR_NE,
  COMPAR_LT,
  COMPAR_GT,
  COMPAR_LE,
  COMPAR_GE,
  MULTIPLY,
  DIVIDE,
  EXPONENT
} bin_op_e;

typedef enum { CONSTANT, BIN_OP, FUNCTION_CALL } expr_e;

typedef enum { INT, FLOAT, CHAR } data_type_e;

typedef enum { WHILE, FOR } loop_e;

typedef enum { STRING, EXPRESSION } arg_e;

typedef enum {
  DECLARATION,
  ASSIGNMENT,
  EXPRESSION_STATEMENT,
  RETURN,
  IF_ELSE,
  LOOP,
  FUNCTION
} statement_e;

typedef struct Identifier {
  char name[MAX_IDENTIFIER_LENGTH];
  char displayName[MAX_IDENTIFIER_LENGTH];
  int depth;
  bool isConstant;
  data_type_e type;
} identifier_t;

typedef struct Line {
  statement_e type;
  union {
    declaration_statement_t *declaration;
    assignment_statement_t *assignment;
    expression_t *expression;
    return_statement_t *ret;
    if_else_statement_t *ifElse;
    loop_statement_t *loop;
    function_def_t *function;
  } statement;
} line_t;

typedef struct LineList {
  int lineCount;
  line_t **lines;
} line_list_t;

typedef struct DeclarationStatement {
  data_type_e type;
  declaration_list_t *declarationList;
} declaration_statement_t;

typedef struct DeclarationList {
  int decCount;
  declaration_t **declarations;
} declaration_list_t;

typedef struct Declaration {
  identifier_t *lValue;
  expression_t *exp;
} declaration_t;

typedef struct AssignmentStatement {
  data_type_e type;
  expression_t *exp;
} assignment_statement_t;

typedef struct ReturnStatement {
  expression_t *exp;
} return_statement_t;

typedef struct LoopStatement {
  loop_e type;
  union {
    while_loop_t *whileLoop;
    for_loop_t *forLoop;
  } loop;
} loop_statement_t;

typedef struct WhileLoop {
  expression_t *condition;
  line_list_t *lineList;
} while_loop_t;

typedef struct ForLoop {
  assignment_statement_t *initial;
  expression_t *condition;
  assignment_statement_t *update;
  line_list_t *lineList;
} for_loop_t;

typedef struct BinOp {
  bin_op_e type;
  expression_t *left;
  expression_t *right;
} bin_op_t;

typedef struct Expression {
  char lValue[MAX_EXPRESSION_LENGTH];
  expr_e type;
  union {
    bin_op_t *binOp;
    function_call_t *functionCall;
  } child;
} expression_t;

typedef struct FunctionCall {
  char name[MAX_IDENTIFIER_LENGTH];
  arg_list_t *argList;
} function_call_t;

typedef struct FunctionDefinition {
  char name[MAX_IDENTIFIER_LENGTH];
  param_list_t *paramList;
  line_list_t *lineList;
} function_def_t;

typedef struct Parameter {
  data_type_e type;
  char name[MAX_IDENTIFIER_LENGTH];
} param_t;

typedef struct ParamList {
  int paramCount;
  param_t **params;
} param_list_t;

typedef struct Arg {
  arg_e type;
  union {
    char *str;
    expression_t *expression;
  } value;
} arg_t;

typedef struct ArgList {
  int argCount;
  arg_t **args;
} arg_list_t;

typedef struct IfElseStatement {
  bool isMatched;
  expression_t *condition;
  line_list_t *ifLineList;
  line_list_t *elseLineList;
} if_else_statement_t;

typedef struct HashTableItem {
  identifier_t *data;
  int key;
} hash_table_item_t;

void error(char *message);
unsigned long hash(char *str);
hash_table_item_t *searchSymbol(char *key, hash_table_item_t *hashTable[]);
void insertSymbol(char *key, identifier_t *data,
                  hash_table_item_t *hashTable[]);
