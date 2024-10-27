#pragma once
#include <stdbool.h>
#define MAX_STRING_LITERAL_LENGTH 10000
#define MAX_IDENTIFIERS 2000
#define MAX_ARGS 2000
#define MAX_ARG_SIZE 2000
#define MAX_FUNCTION_CALLS 2000
#define MAX_IDENTIFIER_LENGTH 200
#define MAX_EXPRESSION_LENGTH 200
#define MAX_LINES 2000
#define MAX_TAC_INSTRUCTIONS 2000
#define MAX_X86_INSTRUCTIONS 10000
#define MAX_DEPTH 20
#define MAX_ASSEMBLY_INSTRUCTIONS 2000
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
typedef struct TACList tac_list_t;
typedef struct TACGlobalDec tac_global_dec_t;
typedef struct TACAssignment tac_ass_t;
typedef struct TACLabel tac_label_t;
typedef struct TACGoto tac_goto_t;
typedef struct TACExp tac_exp_t;
typedef struct TACTerm tac_term_t;
typedef struct TACCall tac_call_t;
typedef struct TACReturn tac_return_t;
typedef struct Assembly assembly_t;
typedef struct AssemblyBSS assembly_bss_t;
typedef struct AssemblyData assembly_data_t;
typedef struct AssemblyText assembly_text_t;
typedef struct AssemblyBSSList assembly_bss_list_t;
typedef struct AssemblyDataList assembly_data_list_t;
typedef struct AssemblyTextList assembly_text_list_t;
typedef struct AssemblyLabel assembly_label_t;
typedef struct AssemblyAssignment assembly_assignment_t;
typedef struct AssemblyCall assembly_call_t;
typedef struct AssemblyGoto assembly_goto_t;
typedef struct AssemblyReturn assembly_return_t;
typedef struct AssemblyExp assembly_exp_t;
typedef struct AssemblyTerm assembly_term_t;
typedef struct X86Instruction x86_t;
typedef struct X86DataMovement x86_data_movement_t;
typedef struct X86Arithmetic x86_arithmetic_t;
typedef struct X86Logic x86_logic_t;
typedef struct X86ControlFlow x86_control_flow_t;
typedef struct X86Jump x86_jump_t;
typedef struct X86Compar x86_compar_t;
typedef struct X86Stack x86_stack_t;
typedef struct X86Section x86_section_t;
typedef struct X86Label x86_label_t;
typedef struct X86Location x86_location_t;
typedef struct X86SpaceAllocation x86_space_allocation_t;

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
  ASSEMBLY_LABEL,
  ASSEMBLY_ASSIGNMENT,
  ASSEMBLY_GOTO,
  ASSEMBLY_CALL,
  ASSEMBLY_RETURN
} assembly_text_e;

typedef enum {
  TAC_ASSIGNMENT,
  TAC_LABEL,
  TAC_GOTO,
  TAC_CALL,
  TAC_RETURN,
  TAC_GLOBAL_DEC
} tac_e;

typedef enum {
  X86_SPACE_ALLOCATION,
  X86_DATA_MOVEMENT,
  X86_ARITHMETIC,
  X86_LOGIC,
  X86_CONTROL_FLOW,
  X86_JUMP,
  X86_COMPAR,
  X86_STACK,
  X86_SECTION,
  X86_LABEL
} x86_e;

typedef enum { X86_SPACE, X86_ASCIZ } x86_format_e;

typedef enum {
  X86_MOV,
  X86_LEA,
  X86_SETE,
  X86_SETNE,
  X86_SETL,
  X86_SETG,
  X86_SETLE,
  X86_SETGE
} x86_data_movement_e;

typedef enum { X86_ADD, X86_SUB, X86_MUL, X86_DIV } x86_arithmetic_e;

typedef enum { X86_AND, X86_OR, X86_NOT, X86_XOR } x86_logic_e;

typedef enum { X86_CALL, X86_RET, X86_LEAVE } x86_control_flow_e;

typedef enum {
  X86_JE,
  X86_JNE,
  X86_JG,
  X86_JL,
  X86_JGE,
  X86_JLE,
  X86_JMP
} x86_jump_e;

typedef enum { X86_CMP } x86_compare_e;

typedef enum { X86_PUSH, X86_POP } x86_stack_e;

typedef enum { X86_DATA, X86_BSS, X86_TEXT, X86_GLOBL } x86_section_e;

typedef enum {
  X86_REGISTER,
  X86_MEMORY,
  X86_DATA_FMT,
  X86_GLOBAL,
  X86_CHAR_IMMEDIATE,
  X86_INT_IMMEDIATE
} x86_location_e;

typedef enum {
  ASSEMBLY_DATA_SECTION,
  ASSEMBLY_BSS_SECTION,
  ASSEMBLY_TEXT_SECTION
} assembly_sec_e;

typedef enum { FUNCTION_LABEL, JUMP_LABEL } label_e;

typedef enum { TAC_BIN_OP, TAC_CONSTANT } tac_exp_e;

typedef enum { ASSEMBLY_BIN_OP, ASSEMBLY_CONSTANT } assembly_exp_e;

typedef enum {
  TEMPORARY,
  PARAM,
  RETVAL,
  VARIABLE,
  STRING_LITERAL,
  CHAR_LITERAL,
  INT_LITERAL
} tac_term_e;

typedef enum {
  ASSEMBLY_VARIABLE,
  EAX,
  FMT,
  CHAR_IMMEDIATE,
  INT_IMMEDIATE
} assembly_term_e;

typedef enum { IF_GOTO, GOTO } goto_e;

typedef enum {
  CHAR_CONSTANT,
  INT_CONSTANT,
  VAR_CONSTANT,
  BIN_OP,
  FUNCTION_CALL
} expr_e;

typedef enum { INT, FLOAT, CHAR, DATA_STRING } data_type_e;

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
  data_type_e type;
  bool isPointer;
  char name[MAX_IDENTIFIER_LENGTH];
  char displayName[MAX_IDENTIFIER_LENGTH];
  int depth;
  expression_t **subscripts;
  bool isConstant;
  int stackOffset;
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

typedef struct TACList {
  int tacCount;
  tac_t **instructions;
} tac_list_t;

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

typedef struct TACExp {
  tac_exp_e type;
  bin_op_e op;
  tac_term_t *lTerm;
  tac_term_t *rTerm;
  void (*stringify)(tac_exp_t *);
} tac_exp_t;

typedef struct TACTerm {
  tac_term_e type;
  char value[MAX_IDENTIFIER_LENGTH];
  int depth;
  expression_t **subscripts;
  void (*stringify)(tac_term_t *);
} tac_term_t;

typedef struct TACLabel {
  label_e type;
  char value[MAX_IDENTIFIER_LENGTH];
  void (*stringify)(tac_label_t *);
} tac_label_t;

typedef struct TACGoto {
  goto_e type;
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

typedef struct AssemblyList {
  int assCount;
  assembly_t **instructions;
} assembly_list_t;

typedef struct AssemblyBSSList {
  int assCount;
  assembly_bss_t **instructions;
} assembly_bss_list_t;

typedef struct AssemblyDataList {
  int assCount;
  assembly_data_t **instructions;
} assembly_data_list_t;

typedef struct AssemblyTextList {
  int assCount;
  assembly_text_t **instructions;
} assembly_text_list_t;

typedef struct Assembly {
  assembly_sec_e section;
  union {
    assembly_bss_t *bss;
    assembly_data_t *data;
    assembly_text_t *text;
  } instruction;
} assembly_t;

typedef struct AssemblyBSS {
  identifier_t *var;
  void (*stringify)(assembly_bss_t *);
} assembly_bss_t;

typedef struct AssemblyData {
  int id;
  char value[MAX_STRING_LITERAL_LENGTH];
  char key[MAX_IDENTIFIER_LENGTH];
  void (*stringify)(assembly_data_t *);
} assembly_data_t;

typedef struct AssemblyText {
  assembly_text_e type;
  union {
    assembly_label_t *label;
    assembly_assignment_t *assignment;
    assembly_call_t *call;
    assembly_goto_t *jump;
    assembly_return_t *ret;
  } instruction;
  void (*stringify)(assembly_text_t *);
} assembly_text_t;

typedef struct AssemblyAssignment {
  assembly_term_t *lValue;
  assembly_exp_t *rValue;
  void (*stringify)(assembly_assignment_t *);
} assembly_assignment_t;

typedef struct AssemblyExp {
  assembly_exp_e type;
  bin_op_e op;
  assembly_term_t *lTerm;
  assembly_term_t *rTerm;
  void (*stringify)(assembly_exp_t *);
} assembly_exp_t;

typedef struct AssemblyTerm {
  assembly_term_e type;
  char scope[MAX_IDENTIFIER_LENGTH];
  char value[MAX_IDENTIFIER_LENGTH];
  int depth;
  expression_t **subscripts;
} assembly_term_t;

typedef struct AssemblyCall {
  int argCount;
  char scope[MAX_IDENTIFIER_LENGTH];
  char arguments[MAX_ARGS][MAX_IDENTIFIER_LENGTH];
  char label[MAX_IDENTIFIER_LENGTH];
  void (*stringify)(assembly_call_t *);
} assembly_call_t;

typedef struct AssemblyGoto {
  goto_e type;
  char scope[MAX_IDENTIFIER_LENGTH];
  char condition[MAX_IDENTIFIER_LENGTH];
  char label[MAX_IDENTIFIER_LENGTH];
  void (*stringify)(assembly_goto_t *);
} assembly_goto_t;

typedef struct AssemblyReturn {
  char label[MAX_IDENTIFIER_LENGTH];
  void (*stringify)(assembly_return_t *);
} assembly_return_t;

typedef struct AssemblyLabel {
  label_e type;
  char value[MAX_IDENTIFIER_LENGTH];
  void (*stringify)(assembly_label_t *);
} assembly_label_t;

typedef struct X86List {
  int x86Count;
  x86_t **instructions;
} x86_list_t;

typedef struct X86Instruction {
  x86_e type;
  union {
    x86_space_allocation_t *spaceAllocation;
    x86_data_movement_t *dataMovement;
    x86_arithmetic_t *arithmetic;
    x86_logic_t *logic;
    x86_control_flow_t *controlFlow;
    x86_jump_t *jump;
    x86_compar_t *compar;
    x86_stack_t *stack;
    x86_section_t *section;
    x86_label_t *label;
  } instruction;
} x86_t;

typedef struct X86SpaceAllocation {
  x86_format_e type;
  union {
    int space;
    char str[MAX_STRING_LITERAL_LENGTH];
  } allocation;
  char value[MAX_IDENTIFIER_LENGTH];
} x86_space_allocation_t;

typedef struct X86DataMovement {
  x86_data_movement_e op;
  x86_location_t *src;
  x86_location_t *opReg;
  bool isDestAddress;
  x86_location_t *dest;
} x86_data_movement_t;

typedef struct X86Arithmetic {
  x86_arithmetic_e op;
  x86_location_t *src;
  x86_location_t *dest;
} x86_arithmetic_t;

typedef struct X86Logic {
  x86_logic_e op;
  x86_location_t *src;
  x86_location_t *dest;
} x86_logic_t;

typedef struct X86ControlFlow {
  x86_control_flow_e op;
  char label[MAX_IDENTIFIER_LENGTH];
} x86_control_flow_t;

typedef struct X86Jump {
  x86_jump_e op;
  char label[MAX_IDENTIFIER_LENGTH];
} x86_jump_t;

typedef struct X86Compar {
  x86_compare_e op;
  x86_location_t *src;
  x86_location_t *dest;
} x86_compar_t;

typedef struct X86Stack {
  x86_stack_e op;
  x86_location_t *location;
} x86_stack_t;

typedef struct X86Section {
  x86_section_e type;
  char label[MAX_IDENTIFIER_LENGTH];
} x86_section_t;

typedef struct X86Label {
  label_e type;
  char label[MAX_IDENTIFIER_LENGTH];
} x86_label_t;

typedef struct X86Location {
  x86_location_e type;
  bool isPointer;
  union {
    int intImmediate;
    char charImmediate;
    char reg;
    int stackOffset;
    char var[MAX_IDENTIFIER_LENGTH];
  } value;
} x86_location_t;

typedef struct SymbolTableItem {
  identifier_t *data;
  int key;
} symbol_table_item_t;

void error(char *message);
unsigned long hash(char *str);
symbol_table_item_t *searchSymbol(char *key, symbol_table_item_t *hashTable[]);
void insertSymbol(char *key, identifier_t *data,
                  symbol_table_item_t *hashTable[]);
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
void newTACLabel(label_e type, char value[MAX_IDENTIFIER_LENGTH]);
void newTACGoto(goto_e type, char label[MAX_IDENTIFIER_LENGTH],
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
void firstPassTACs(tac_list_t *tacList);
assembly_list_t *parseTACs(tac_list_t *tacList);
assembly_t *newAssemblyGlobalDec(tac_global_dec_t *tac);
assembly_t *newAssemblyLabel(tac_label_t *tac);
assembly_t *newAssemblyReturn(tac_return_t *tac);
assembly_t *newAssemblyGoto(tac_goto_t *tac);
assembly_t *newAssemblyCall(int argCount,
                            char arguments[MAX_ARGS][MAX_IDENTIFIER_LENGTH],
                            tac_call_t *tac);
assembly_t *newAssemblyAssignment(tac_ass_t *tac);
assembly_term_t *newAssemblyTerm(tac_term_t *tac);
assembly_exp_t *newAssemblyExp(tac_exp_e type, bin_op_e op,
                               assembly_term_t *lTerm, assembly_term_t *rTerm);
void stringifyAssList(assembly_list_t *assList);
void stringifyBSSList(assembly_bss_list_t *bssList);
void stringifyDataList(assembly_data_list_t *dataList);
void stringifyTextList(assembly_text_list_t *textList);
void stringifyBSS(assembly_bss_t *ass);
void stringifyData(assembly_data_t *ass);
void stringifyText(assembly_text_t *ass);
void stringifyAssemblyLabel(assembly_label_t *label);
void stringifyAssemblyAssignment(assembly_assignment_t *assignment);
void stringifyAssemblyCall(assembly_call_t *call);
void stringifyAssemblyJump(assembly_goto_t *jump);
void stringifyAssemblyReturn(assembly_return_t *ret);
void stringifyAssemblyExp(assembly_exp_t *exp);
bool isComparison(bin_op_e op);
void newX86Stack(x86_stack_e op, x86_location_t *location);
x86_arithmetic_t *newX86Arithmetic(x86_arithmetic_e op, x86_location_t *src,
                                   x86_location_t *dest);
void addX86Instruction(void *instruction, x86_e type);
void stringifyX86List(x86_list_t *x86List);
void stringifyX86Location(x86_location_t *location);
x86_location_t *getX86Location(assembly_term_t *term);
