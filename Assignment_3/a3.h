#pragma once
#include <stdbool.h>
#define MAX_IDENTIFIERS 2000
#define MAX_ARGS 2000
#define MAX_ARG_SIZE 2000
#define MAX_FUNCTION_CALLS 2000
#define MAX_IDENTIFIER_LENGTH 200
#define MAX_EXPRESSION_LENGTH 200
#define MAX_LINES 2000
#define MAX_TAC_INSTRUCTIONS 2000
#define MAX_DEPTH 20
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)

typedef struct Identifier identifier_t;
typedef struct SubscriptList subscript_list_t;
typedef struct Subscript subscript_t;
typedef struct DeclarationStatement declaration_statement_t;
typedef struct Declaration declaration_t;
typedef struct DeclarationList declaration_list_t;
typedef struct AssignmentStatement assignment_statement_t;
typedef struct ReturnStatement return_statement_t;
typedef struct IfElseStatement if_else_statement_t;
typedef struct LoopStatement loop_statement_t;
typedef struct FunctionDefinition function_def_t;
typedef struct FunctionDefinitionList function_def_list_t;
typedef struct CombinedFunctionDefinitions combined_function_definitions_t;
typedef struct Expression expression_t;
typedef struct FunctionCall function_call_t;
typedef struct Parameter param_t;
typedef struct ParamList param_list_t;
typedef struct Arg arg_t;
typedef struct ArgList arg_list_t;
typedef struct BinOp bin_op_t;
typedef struct Line line_t;
typedef struct LineList line_list_t;
typedef struct WhileLoop while_loop_t;
typedef struct ForLoop for_loop_t;
typedef struct Program program_t;
typedef struct Condition condition_t;
typedef struct TAC tac_t;
typedef struct TACGlobalDec tac_global_dec_t;
typedef struct TACAssignment tac_ass_t;
typedef struct TACLabel tac_label_t;
typedef struct TACGoto tac_goto_t;
typedef struct TACAssTerm tac_term_t;
typedef struct TACAssExp tac_exp_t;
typedef struct TACCall tac_call_t;
typedef struct TACReturn tac_return_t;

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

typedef enum { SINGLE, SHORT_AND, SHORT_OR, NOT } condition_op_e;

typedef enum {
  TAC_ASSIGNMENT,
  TAC_LABEL,
  TAC_GOTO,
  TAC_CALL,
  TAC_RETURN,
  TAC_GLOBAL_DEC
} tac_e;

typedef enum { FUNCTION_LABEL, JUMP_LABEL } tac_label_e;

typedef enum { TAC_BIN_OP, TAC_CONSTANT } tac_exp_e;

typedef enum {
  TEMPORARY,
  PARAM,
  RETVAL,
  VARIABLE,
  STRING_LITERAL,
  INTEGER_CONSTANT
} tac_term_e;

typedef enum { IF_GOTO, GOTO } tac_goto_e;

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
  expression_t **subscripts;
  bool isConstant;
  data_type_e type;
} identifier_t;

typedef struct SubscriptList {
  int depth;
  expression_t **subscripts;
} subscript_list_t;

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
  void (*stringify)(line_t *);
} line_t;

typedef struct LineList {
  int lineCount;
  line_t **lines;
  void (*stringify)(line_list_t *);
} line_list_t;

typedef struct DeclarationStatement {
  data_type_e type;
  declaration_list_t *declarationList;
  void (*stringify)(declaration_statement_t *);
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
  identifier_t *lValue;
  expression_t *exp;
  void (*stringify)(assignment_statement_t *);
} assignment_statement_t;

typedef struct ReturnStatement {
  expression_t *exp;
  void (*stringify)(return_statement_t *);
} return_statement_t;

typedef struct LoopStatement {
  loop_e type;
  union {
    while_loop_t *whileLoop;
    for_loop_t *forLoop;
  } loop;
  void (*stringify)(loop_statement_t *);
} loop_statement_t;

typedef struct WhileLoop {
  int startLabel;
  int trueLabel;
  int falseLabel;
  condition_t *condition;
  line_list_t *lineList;
  void (*stringify)(while_loop_t *);
} while_loop_t;

typedef struct ForLoop {
  int startLabel;
  int trueLabel;
  int falseLabel;
  assignment_statement_t *initial;
  condition_t *condition;
  assignment_statement_t *update;
  line_list_t *lineList;
  void (*stringify)(for_loop_t *);
} for_loop_t;

typedef struct BinOp {
  bin_op_e type;
  expression_t *left;
  expression_t *right;
  void (*stringify)(expression_t *, bin_op_t *);
} bin_op_t;

typedef struct Expression {
  char lValue[MAX_EXPRESSION_LENGTH];
  expr_e type;
  union {
    bin_op_t *binOp;
    function_call_t *functionCall;
  } child;
  void (*stringify)(expression_t *);
} expression_t;

typedef struct FunctionCall {
  char name[MAX_IDENTIFIER_LENGTH];
  arg_list_t *argList;
  void (*stringify)(function_call_t *);
} function_call_t;

typedef struct FunctionDefinition {
  char name[MAX_IDENTIFIER_LENGTH];
  param_list_t *paramList;
  line_list_t *lineList;
  void (*stringify)(function_def_t *);
} function_def_t;

typedef struct CombinedFunctionDefinitions {
  int functionCount;
  function_def_t **functions;
  function_def_t *main;
} combined_function_definitions_t;

typedef struct FunctionDefinitionList {
  int functionCount;
  function_def_t **functions;
  void (*stringify)(function_def_list_t *);
} function_def_list_t;

typedef struct Parameter {
  data_type_e type;
  char name[MAX_IDENTIFIER_LENGTH];
} param_t;

typedef struct ParamList {
  int paramCount;
  param_t **params;
  void (*stringify)(param_list_t *);
} param_list_t;

typedef struct Arg {
  arg_e type;
  union {
    char *str;
    expression_t *exp;
  } value;
} arg_t;

typedef struct ArgList {
  int argCount;
  arg_t **args;
} arg_list_t;

typedef struct IfElseStatement {
  bool isMatched;
  int trueLabel;
  int falseLabel;
  condition_t *condition;
  line_list_t *ifLineList;
  line_list_t *elseLineList;
  void (*stringify)(if_else_statement_t *);
} if_else_statement_t;

typedef struct Program {
  line_list_t *globalDeclarations;
  function_def_list_t *funDefList;
  function_def_t *main;
} program_t;

typedef struct Condition {
  condition_op_e op;
  condition_t *base;
  expression_t *exp;
  condition_t *chain;
} condition_t;

typedef struct TAC {
  tac_e type;
  union {
    tac_global_dec_t *global;
    tac_ass_t *assignment;
    tac_label_t *label;
    tac_goto_t *jump;
    tac_call_t *call;
    tac_return_t *ret;
  } instruction;
  void (*stringify)(tac_t *);
} tac_t;

typedef struct TACGlobalDec {
  char value[MAX_IDENTIFIER_LENGTH];
  void (*stringify)(tac_global_dec_t *);
} tac_global_dec_t;

typedef struct TACAssignment {
  tac_term_t *lValue;
  tac_exp_t *rValue;
  void (*stringify)(tac_ass_t *);
} tac_ass_t;

typedef struct TACAssExp {
  tac_exp_e type;
  bin_op_e op;
  tac_term_t *lTerm;
  tac_term_t *rTerm;
  void (*stringify)(tac_exp_t *);
} tac_exp_t;

typedef struct TACAssTerm {
  tac_term_e type;
  int depth;
  expression_t **subscripts;
  char value[MAX_IDENTIFIER_LENGTH];
  void (*stringify)(tac_term_t *);
} tac_term_t;

typedef struct TACLabel {
  tac_label_e type;
  char value[MAX_IDENTIFIER_LENGTH];
  void (*stringify)(tac_label_t *);
} tac_label_t;

typedef struct TACGoto {
  tac_goto_e type;
  char condition[MAX_IDENTIFIER_LENGTH];
  char label[MAX_IDENTIFIER_LENGTH];
  void (*stringify)(tac_goto_t *);
} tac_goto_t;

typedef struct TACCall {
  char label[MAX_IDENTIFIER_LENGTH];
  void (*stringify)(tac_call_t *);
} tac_call_t;

typedef struct TACReturn {
  char label[MAX_IDENTIFIER_LENGTH];
  void (*stringify)(tac_return_t *);
} tac_return_t;

typedef struct HashTableItem {
  identifier_t *data;
  int key;
} hash_table_item_t;

void error(char *message);
unsigned long hash(char *str);
hash_table_item_t *searchSymbol(char *key, hash_table_item_t *hashTable[]);
void insertSymbol(char *key, identifier_t *data,
                  hash_table_item_t *hashTable[]);
void stringifyProgram(program_t *program);
void stringifyFunctionDefList(function_def_list_t *funDefList);
void stringifyFunDef(function_def_t *fun);
void stringifyParamList(param_list_t *paramList);
void stringifyLineList(line_list_t *lineList);
void stringifyDeclarationStatement(declaration_statement_t *decList);
void stringifyAssignmentStatement(assignment_statement_t *ass);
void stringifyExpression(expression_t *exp);
void stringifyReturnStatement(return_statement_t *ret);
void stringifyIfElseStatement(if_else_statement_t *ifElseStatement);
void stringifyLoopStatement(loop_statement_t *loopStatement);
void stringifyWhileLoop(while_loop_t *loop);
void stringifyForLoop(for_loop_t *loop);
void stringifyBinOp(expression_t *exp, bin_op_t *binOp);
void stringifyFunctionCall(function_call_t *fun);
void stringifyLine(line_t *line);
void newTACGlobalDec(char value[MAX_IDENTIFIER_LENGTH]);
void newTACAssignment(tac_term_t *lValue, tac_exp_t *rValue);
void newTACGlobalDec(char value[MAX_IDENTIFIER_LENGTH]);
void newTACAssignment(tac_term_t *lValue, tac_exp_t *rValue);
tac_term_t *newTACTerm(tac_term_e type, int depth, expression_t **subscripts,
                       char value[MAX_IDENTIFIER_LENGTH]);
tac_exp_t *newTACExp(tac_exp_e type, bin_op_e op, tac_term_t *lTerm,
                     tac_term_t *rTerm);
void newTACLabel(tac_label_e type, char value[MAX_IDENTIFIER_LENGTH]);
void newTACGoto(tac_goto_e type, char label[MAX_IDENTIFIER_LENGTH],
                char condition[MAX_IDENTIFIER_LENGTH]);
void newTACCall(char label[MAX_IDENTIFIER_LENGTH]);
void newTACReturn(char label[MAX_IDENTIFIER_LENGTH]);
void stringifyTAC(tac_t *tac);
void stringifyTACGlobalDec(tac_global_dec_t *tac);
void stringifyTACAssignment(tac_ass_t *tac);
void stringifyTACTerm(tac_term_t *term);
void stringifyTACExp(tac_exp_t *exp);
void stringifyTACLabel(tac_label_t *tac);
void stringifyTACGoto(tac_goto_t *tac);
void stringifyTACCall(tac_call_t *tac);
void stringifyTACReturn(tac_return_t *tac);
