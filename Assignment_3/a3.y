%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "a3.h"

void yyerror(char *);
int yylex(void);
char mytext[100];
char currType[10];
char currScope[MAX_IDENTIFIER_LENGTH] = "global";
char currTACFunction[MAX_IDENTIFIER_LENGTH] = "global";
expression_t args[MAX_FUNCTION_CALLS][MAX_ARGS];
int lineNumber = 1;
static int tCount = 1;
static int lCount = 1;
static int globalDataCount = 0;

symbol_table_item_t *symbolTable[MAX_IDENTIFIERS];
program_t *program;
tac_list_t *tacList;
x86_list_t *x86List;
x86_location_t *EBP_REGISTER, *ESP_REGISTER, *EAX_REGISTER, *EBX_REGISTER, *ECX_REGISTER, *EDX_REGISTER, *ZEROF_REGISTER, *ONE;

%}

%token OPEN_PAREN CLOSE_PAREN OPEN_BRACE CLOSE_BRACE OPEN_SQUARE CLOSE_SQUARE COMMA COMPAR SEMI_COLON
%token EQ PLUS_TOK MINUS_TOK MULTIPLY_TOK DIVIDE_TOK EXPONENT_TOK
%token VALID_TYPE IDENTIFIER NUMBER STRING_TOK CHAR_TOK
%token SHORT_AND_TOK SHORT_OR_TOK NOT_TOK
%token IF_TOK ELSE_TOK
%token WHILE_TOK FOR_TOK
%token RETURN_TOK MAIN
%token INCLUDE LIB_NAME

%left PLUS_TOK MINUS_TOK COMPAR
%left MULTIPLY_TOK DIVIDE_TOK
%left SHORT_OR_TOK 
%left SHORT_AND_TOK 
%right NOT_TOK
%right UMINUS UPLUS EXPONENT_TOK
%left OPEN_PAREN CLOSE_PAREN
%left ELSE_TOK


%union {
	char *str;
	int val;
	identifier_t *id;
	subscript_list_t *subscriptList;
	expression_t *exp; 
	line_t *line;
	line_list_t *lineList;
	declaration_statement_t *declarationStatement;
	assignment_statement_t *assignmentStatement;
	if_else_statement_t *ifElseStatement;
	return_statement_t *returnStatement;
	loop_statement_t *loopStatement;
	function_def_t *funDef;
	combined_function_definitions_t *combinedFunDefList;
	while_loop_t *whileLoop;
	for_loop_t *forLoop;
	declaration_list_t *decList;
	declaration_t *dec;
	function_call_t *funCall;
	arg_t *arg;
	param_t *param;
	arg_list_t *argList;
	param_list_t *paramList;
	data_type_e dataType;
	condition_t *con;
}

%type <str> identifier functionIdentifier compar
%type <subscriptList> subscripts
%type <id> assignable term
%type <exp> expression subscript computable
%type <arg> argument
%type <param> parameter
%type <argList> arguments
%type <paramList> parameters
%type <funCall> functionCall
%type <funDef> functionDefinition mainFunction
%type <combinedFunDefList> functionDefinitions
%type <line> line
%type <lineList> lines body globalDeclarations
%type <declarationStatement> declarationStatement
%type <decList> declarations
%type <dec> declaration
%type <assignmentStatement> assignmentStatement
%type <ifElseStatement> ifStatement
%type <returnStatement> returnStatement
%type <loopStatement> loopStatement
%type <whileLoop> whileStatement
%type <forLoop> forStatement
%type <dataType> validType
%type <con> condition

%%
program:
	libs globalDeclarations functionDefinitions {
		function_def_list_t *funDefList = (function_def_list_t *)malloc(sizeof(function_def_list_t));
		funDefList->functions = (function_def_t **)malloc(MAX_IDENTIFIERS * sizeof(function_def_t *));
		funDefList->functionCount = $3->functionCount;
		for (int i = 0; i < funDefList->functionCount; i++) {
		    funDefList->functions[i] = $3->functions[$3->functionCount - i - 1];
		}
		funDefList->stringify = &stringifyFunctionDefList;
		program->globalDeclarations = $2;
		program->funDefList = funDefList;
		program->main = $3->main;
	}
;

libs:
	INCLUDE LIB_NAME
;

globalDeclarations:
    globalDeclarations declarationStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = DECLARATION;
		line->statement.declaration = $2;
		line->stringify = &stringifyLine;
		$1->lines[$1->lineCount++] = line;
		$$ = $1;
	}
	| {
		line_list_t *lineList = (line_list_t *)malloc(sizeof(line_list_t));
		lineList->lines = (line_t **)malloc(MAX_LINES * sizeof(line_t *));
		lineList->stringify = &stringifyLineList;
		$$ = lineList;
	}
;

functionDefinitions:
	functionDefinition functionDefinitions {
		$2->functions[$2->functionCount++] = $1;
		$$ = $2;
	}
	| mainFunction {
		combined_function_definitions_t *combinedFunctions = (combined_function_definitions_t *)malloc(sizeof(combined_function_definitions_t));
		combinedFunctions->functions = (function_def_t **)malloc(MAX_LINES * sizeof(function_def_t *));
		combinedFunctions->main = $1;
		$$ = combinedFunctions;
	}
;

mainFunction:
	validType mainIdentifier OPEN_PAREN parameters CLOSE_PAREN body {
		function_def_t *fun = (function_def_t *)malloc(sizeof(function_def_t));
		strcpy(fun->name, "main");
		fun->paramList = $4;
		fun->lineList = $6;
		fun->stringify = &stringifyFunDef;
		$$ = fun;
	}
;

mainIdentifier:
	MAIN {
		strcpy(currScope, "main");
	}
;

lines:
	line {
		line_list_t *lineList = (line_list_t *)malloc(sizeof(line_list_t));
		lineList->lines = (line_t **)malloc(MAX_LINES * sizeof(line_t *));
		lineList->lines[lineList->lineCount++] = $1;
		lineList->stringify = &stringifyLineList;
		$$ = lineList;
	}
	| lines line {
		$1->lines[$1->lineCount++] = $2;
		$$ = $1;
	}
;


line:
	declarationStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = DECLARATION;
		line->statement.declaration = $1;
		line->stringify = &stringifyLine;
		$$ = line;
	}
    | assignmentStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = ASSIGNMENT;
		line->statement.assignment = $1;
		line->stringify = &stringifyLine;
		$$ = line;
	}
    | expression SEMI_COLON {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = EXPRESSION_STATEMENT;
		line->statement.expression = $1;
		line->stringify = &stringifyLine;
		$$ = line;
	}
    | returnStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = RETURN;
		line->statement.ret = $1;
		line->stringify = &stringifyLine;
		$$ = line;
	}
    | ifStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = IF_ELSE;
		line->statement.ifElse = $1;
		line->stringify = &stringifyLine;
		$$ = line;
	}
    | loopStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = LOOP;
		line->statement.loop = $1;
		line->stringify = &stringifyLine;
		$$ = line;
	}
    | functionDefinition {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = FUNCTION;
		line->statement.function = $1;
		line->stringify = &stringifyLine;
		$$ = line;
	}
;

declarationStatement:
    validType declarations SEMI_COLON {
		declaration_statement_t *dec = (declaration_statement_t *)malloc(sizeof(declaration_statement_t));
		dec->type = $1;
		dec->declarationList = $2;
		dec->stringify = &stringifyDeclarationStatement;
		$$ = dec;
    }
;

declarations:
    declaration {
		declaration_list_t *decList = (declaration_list_t *)malloc(sizeof(declaration_list_t));
		decList->declarations = (declaration_t **)malloc(MAX_LINES * sizeof(declaration_t *));
		decList->declarations[decList->decCount++] = $1;
		$$ = decList;
	}
	| declaration COMMA declarations {
		$3->declarations[$3->decCount++] = $1;
		$$ = $3;
	}
;

declaration:
    assignable EQ expression {
		declaration_t *dec = (declaration_t *)malloc(sizeof(declaration_t));
		dec->lValue = $1;
		dec->exp = $3;
		$$ = dec;
	}
	| assignable {
		declaration_t *dec = (declaration_t *)malloc(sizeof(declaration_t));
		dec->lValue = $1;
		$$ = dec;
	}
;

assignmentStatement:
    assignable EQ computable SEMI_COLON {
		symbol_table_item_t *item = searchSymbol($1->name, symbolTable);
		if (item == NULL)
		    error("Undefined variable");
		if (item->data->depth != $1->depth)
		    error("Invalid location");

		assignment_statement_t *ass = (assignment_statement_t *)malloc(sizeof(assignment_statement_t));
		ass->type = item->data->type;
		ass->lValue = $1;
		ass->exp = $3;
		ass->stringify = &stringifyAssignmentStatement;
		$$ = ass;
	}
;

assignable:
	identifier {
		char tempStr[MAX_IDENTIFIER_LENGTH];
		sprintf(tempStr, "global_%s", $1);
		symbol_table_item_t *item = searchSymbol(tempStr, symbolTable);
		if (item != NULL) {
		    $$ = item->data;
		} else {
		    identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		    strcpy(id->name, currScope);
	        strcat(id->name, "_");
	        strcat(id->name, $1);
	        strcpy(id->displayName, $1);
		    if (streq(currType, "int", 3))
		        id->type = INT;
		    else if (streq(currType, "float", 5))
		        id->type = FLOAT;
		    else if (streq(currType, "char", 4))
		        id->type = CHAR;
	        id->depth = 0;
		    insertSymbol(id->name, id, symbolTable);
		    $$ = id;
		}
	}
	| identifier subscripts {
		char tempStr[MAX_IDENTIFIER_LENGTH];
		sprintf(tempStr, "global_%s", $1);
		symbol_table_item_t *item = searchSymbol(tempStr, symbolTable);
		if (item != NULL) {
		    $$ = item->data;
		} else {
	        identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		    strcpy(id->name, currScope);
	        strcat(id->name, "_");
	        strcat(id->name, $1);
	        strcpy(id->displayName, $1);

		    if (streq(currType, "int", 3))
		        id->type = INT;
		    else if (streq(currType, "float", 5))
		        id->type = FLOAT;
		    else if (streq(currType, "char", 4))
		        id->type = CHAR;

	        id->depth = $2->depth;
	        id->subscripts = $2->subscripts;
			id->isPointer = true;
		    insertSymbol(id->name, id, symbolTable);
		    $$ = id;
		}
	}
;

subscripts:
	subscript {
		subscript_list_t *subscriptList = (subscript_list_t *)malloc(sizeof(subscript_list_t));
		subscriptList->depth = 1;
		subscriptList->subscripts = (expression_t **)malloc(MAX_DEPTH * sizeof(expression_t *));
		subscriptList->subscripts[0] = $1;
		$$ = subscriptList;
	}
	| subscripts subscript {
		$1->subscripts[$1->depth++] = $2;
		$$ = $1;
    }
;

subscript:
	OPEN_SQUARE expression CLOSE_SQUARE {
		$$ = $2;
	}
;

functionCall:
	identifier OPEN_PAREN arguments CLOSE_PAREN {
		arg_list_t *argList = $3;
		function_call_t *fun = (function_call_t *)malloc(sizeof(function_call_t));
		strcpy(fun->name, $1);
		fun->argList = $3;
		fun->stringify = &stringifyFunctionCall;
		$$ = fun;
	}
;

arguments:
	argument {
		$$ = (arg_list_t *)malloc(sizeof(arg_list_t));
		$$->args = (arg_t **)malloc(MAX_ARGS * sizeof(arg_t *));
		$$->args[$$->argCount++] = $1;
	}
	| arguments COMMA argument {
		$1->args[$1->argCount++] = $3;
		$$ = $1;
	}
	| {
		$$ = (arg_list_t *)malloc(sizeof(arg_list_t));
		$$->args = (arg_t **)malloc(MAX_ARGS * sizeof(arg_t *));
	}
;

argument:
	expression {
		arg_t *arg = (arg_t *)malloc(sizeof(arg_t));
		arg->type = EXPRESSION;
		arg->value.exp = $1;
		$$ = arg;
	}
	| STRING_TOK {
		arg_t *arg = (arg_t *)malloc(sizeof(arg_t));
		arg->type = STRING;
		arg->value.str = (char *)malloc(MAX_IDENTIFIER_LENGTH * sizeof(char));
		strcpy(arg->value.str, mytext);
		$$ = arg;
	}
;

expression:
    expression PLUS_TOK expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = PLUS;
		binOp->left = $1;
		binOp->right = $3;
		binOp->stringify = &stringifyBinOp;
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		$$ = exp;
    }
    | expression MINUS_TOK expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = MINUS;
		binOp->left = $1;
		binOp->right = $3;
		binOp->stringify = &stringifyBinOp;
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		$$ = exp;
    }
    | expression MULTIPLY_TOK expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = MULTIPLY;
		binOp->left = $1;
		binOp->right = $3;
		binOp->stringify = &stringifyBinOp;
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		$$ = exp;
    }
    | expression DIVIDE_TOK expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = DIVIDE;
		binOp->left = $1;
		binOp->right = $3;
		binOp->stringify = &stringifyBinOp;
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		$$ = exp;
    }
    | expression EXPONENT_TOK expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = EXPONENT;
		binOp->left = $1;
		binOp->right = $3;
		binOp->stringify = &stringifyBinOp;
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		$$ = exp;
    }
    | PLUS_TOK expression %prec UPLUS {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = INT_CONSTANT;
		sprintf(exp->lValue, "%s", $2->lValue);
		exp->stringify = &stringifyExpression;
		$$ = exp;
    }
    | MINUS_TOK expression %prec UMINUS {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = INT_CONSTANT;
		sprintf(exp->lValue, "-%s", $2->lValue);
		exp->stringify = &stringifyExpression;
		$$ = exp;
    }
    | OPEN_PAREN expression CLOSE_PAREN {
		$$ = $2;
    }
    | functionCall {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		strcpy(exp->lValue, "retval");
		exp->type = FUNCTION_CALL;
		exp->child.functionCall = $1;
		exp->stringify = &stringifyExpression;
		$$ = exp;
    }
    | term {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));

		if (!$1->isConstant) {
			char temp[2 * MAX_IDENTIFIER_LENGTH];
		    sprintf(temp, "%s_%s", currScope, $1->name);
			symbol_table_item_t *item = searchSymbol(temp, symbolTable);
			if (item == NULL) {
			    sprintf(temp, "global_%s", $1->name);
			    item = searchSymbol(temp, symbolTable);
			    if (item == NULL)
			    	error("Undefined identifier");
			}
			if (item->data->type == INT && item->data->depth != $1->depth)
				error("Invalid location");
		    exp->type = VAR_CONSTANT;
		} else {
		    exp->type = $1->type == INT ? INT_CONSTANT : CHAR_CONSTANT;
		}

		sprintf(exp->lValue, "%s", $1->name);
		exp->stringify = &stringifyExpression;
		$$ = exp;
    }
;

functionDefinition:
    validType functionIdentifier OPEN_PAREN parameters CLOSE_PAREN body {
		function_def_t *fun = (function_def_t *)malloc(sizeof(function_def_t));
		strcpy(fun->name, $2);
		fun->paramList = $4;
		fun->lineList = $6;
		fun->stringify = &stringifyFunDef;
		$$ = fun;
    }
;

functionIdentifier:
	identifier {
		strcpy(currScope, $1);
		$$ = $1;
	}
;

returnStatement:
	RETURN_TOK computable SEMI_COLON {
		return_statement_t *ret = (return_statement_t *)malloc(sizeof(return_statement_t));
		ret->exp = $2;
		ret->stringify = &stringifyReturnStatement;
		$$ = ret;
	}
	| RETURN_TOK SEMI_COLON {
		return_statement_t *ret = (return_statement_t *)malloc(sizeof(return_statement_t));
		ret->stringify = &stringifyReturnStatement;
		$$ = ret;
	}
;

parameters: 
	 parameter {
		param_list_t *paramList = (param_list_t *)malloc(sizeof(param_list_t));
		paramList->params = (param_t **)malloc(MAX_ARGS * sizeof(param_t *));
		paramList->params[paramList->paramCount++] = $1;
		paramList->stringify = &stringifyParamList;
		$$ = paramList;
	 }
	 | parameters COMMA parameter {
		$1->params[$1->paramCount++] = $3;
		$$ = $1;
	 }
	 | {
		param_list_t *paramList = (param_list_t *)malloc(sizeof(param_list_t));
		paramList->params = (param_t **)malloc(MAX_ARGS * sizeof(param_t *));
		paramList->stringify = &stringifyParamList;
		$$ = paramList;
	 }
;

parameter:
    validType assignable {
		param_t *param = (param_t *)malloc(sizeof(param_t));
		param->type = $1;
		strcpy(param->name, $2->displayName);
		$$ = param;
    }
;

ifStatement:
    IF_TOK OPEN_PAREN condition CLOSE_PAREN body ELSE_TOK body {
		if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
		ifElse->isMatched = true;
		ifElse->condition = $3;
		ifElse->ifLineList = $5;
		ifElse->elseLineList = $7;
		ifElse->stringify = &stringifyIfElseStatement;
		$$ = ifElse;
	}
	| IF_TOK OPEN_PAREN condition CLOSE_PAREN body {
		if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
		ifElse->isMatched = false;
		ifElse->condition = $3;
		ifElse->ifLineList = $5;
		ifElse->stringify = &stringifyIfElseStatement;
		$$ = ifElse;
	}
;

condition:
	condition SHORT_AND_TOK condition {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = SHORT_AND;
		con->base = $1;
		con->chain = $3;
		$$ = con;
	}
	| condition SHORT_OR_TOK condition {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = SHORT_OR;
		con->base = $1;
		con->chain = $3;
		$$ = con;
	}
	| NOT_TOK condition {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = NOT;
		con->base = $2;
		$$ = con;
	}
	| OPEN_PAREN condition CLOSE_PAREN {
		$$ = $2;
	}
    | expression compar expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->left = $1;
		binOp->right = $3;
		binOp->stringify = &stringifyBinOp;
		if (streq($2, "==", 2))
		    binOp->type = COMPAR_EQ;
		else if (streq($2, "!=", 2))
		    binOp->type = COMPAR_NE;
		else if (streq($2, "<=", 2))
		    binOp->type = COMPAR_LE;
		else if (streq($2, ">=", 2))
		    binOp->type = COMPAR_GE;
		else if (streq($2, "<", 1))
		    binOp->type = COMPAR_LT;
		else if (streq($2, ">", 1))
		    binOp->type = COMPAR_GT;
		else {
			printf("%s\n", $1->lValue);
		    error("Invalid comparison operator");
		}
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = SINGLE;
		con->exp = exp;
		$$ = con;
    }
;

computable:
    expression {
		$$ = $1;
	}
	| condition {
		$$ = $1->exp;
	}
;

loopStatement:
    whileStatement {
		loop_statement_t *loop = (loop_statement_t *)malloc(sizeof(loop_statement_t));
		loop->type = WHILE;
		loop->loop.whileLoop = $1;
		loop->stringify = &stringifyLoopStatement;
		$$ = loop;
    }
	| forStatement {
		loop_statement_t *loop = (loop_statement_t *)malloc(sizeof(loop_statement_t));
		loop->type = FOR;
		loop->loop.forLoop = $1;
		loop->stringify = &stringifyLoopStatement;
		$$ = loop;
	}
;

whileStatement:
    WHILE_TOK OPEN_PAREN condition CLOSE_PAREN body {
		while_loop_t *loop = (while_loop_t *)malloc(sizeof(while_loop_t));
		loop->condition = $3;
		loop->lineList = $5;
		loop->stringify = &stringifyWhileLoop;
		$$ = loop;
    }
;

forStatement:
    FOR_TOK OPEN_PAREN assignmentStatement condition SEMI_COLON assignable EQ expression CLOSE_PAREN body {
		for_loop_t *loop = (for_loop_t *)malloc(sizeof(for_loop_t));
		loop->initial = $3;
		loop->condition = $4;
		assignment_statement_t *update = (assignment_statement_t *)malloc(sizeof(assignment_statement_t));
		update->type = $6->type;
		update->lValue = $6;
		update->exp = $8;
		update->stringify = &stringifyAssignmentStatement;
		loop->update = update;
		loop->lineList = $10;
		loop->stringify = &stringifyForLoop;
		$$ = loop;
	}
;

body:
	line {
		line_list_t *lineList = (line_list_t *)malloc(sizeof(line_list_t));
		lineList->lines = (line_t **)malloc(MAX_LINES * sizeof(line_t *));
		lineList->lines[lineList->lineCount++] = $1;
		lineList->stringify = &stringifyLineList;
		$$ = lineList;
	}
    | OPEN_BRACE lines CLOSE_BRACE {
		$$ = $2;
	}
;

term:
	identifier {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, $1);
		id->depth = 0;
		$$ = id;
    }
    | identifier subscripts {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, $1);
		id->depth = $2->depth;
		id->subscripts = $2->subscripts;
		$$ = id;
    }
    | NUMBER {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, mytext);
		id->depth = 0;
		id->type = INT;
		id->isConstant = true;
		$$ = id;
    }
	| CHAR_TOK {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, mytext);
		id->depth = 0;
		id->type = CHAR;
		id->isConstant = true;
		$$ = id;
	}
;

compar:
    COMPAR {
		$$ = strdup(mytext);
	}
;

validType:
    VALID_TYPE {
		strcpy(currType, mytext);
		if (streq(mytext, "int", 3))
		    $$ = INT;
		else if (streq(mytext, "float", 5))
		    $$ = FLOAT;
		else if (streq(mytext, "char", 4))
		    $$ = CHAR;
    }
;

identifier: IDENTIFIER {
		$$ = strdup(mytext);
	}
;

%%

void yyerror(char *message) {
    fprintf(stderr, "syntax error: %d\n", lineNumber);
    exit(1);
}

void error(char *message) {
    perror(message);
	exit(1);
}

int main(int argc, char *argv[]) {
    program = (program_t *)malloc(sizeof(program_t));
	tacList = (tac_list_t *)malloc(sizeof(tac_list_t));
	tacList->instructions = (tac_t **)calloc(MAX_TAC_INSTRUCTIONS, sizeof(tac_t *));
	x86List = (x86_list_t *)malloc(sizeof(x86_list_t));
	x86List->instructions = (x86_t **)calloc(MAX_X86_INSTRUCTIONS, sizeof(x86_t *));

	yyparse();

	stringifyProgram(program);

	int saved_stdout = dup(fileno(stdout));

    FILE *file = freopen("tac.txt", "w", stdout);
    if (file == NULL)
        error("Error opening file");

	for (int i = 0; i < tacList->tacCount; i++) {
		tac_t *tac = tacList->instructions[i];
		stringifyTAC(tac);
	}

    fflush(stdout);
    dup2(saved_stdout, fileno(stdout));
    close(saved_stdout);

	firstPassTACs(tacList);

	strcpy(currScope, "global");
    assembly_list_t *assList = parseTACs(tacList);

	EBP_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	EBP_REGISTER->type = X86_REGISTER;
	EBP_REGISTER->value.reg = 'B';

	ESP_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	ESP_REGISTER->type = X86_REGISTER;
	ESP_REGISTER->value.reg = 'S';

	EAX_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	EAX_REGISTER->type = X86_REGISTER;
	EAX_REGISTER->value.reg = 'a';

	EBX_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	EBX_REGISTER->type = X86_REGISTER;
	EBX_REGISTER->value.reg = 'b';

	ECX_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	ECX_REGISTER->type = X86_REGISTER;
	ECX_REGISTER->value.reg = 'c';

	EDX_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	EDX_REGISTER->type = X86_REGISTER;
	EDX_REGISTER->value.reg = 'd';

	ZEROF_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	ZEROF_REGISTER->type = X86_REGISTER;
	ZEROF_REGISTER->value.reg = 'Z';

	ONE = (x86_location_t *)malloc(sizeof(x86_location_t));
	ONE->type = X86_INT_IMMEDIATE;
	ONE->value.intImmediate = 1;

    file = freopen("a.s", "w", stdout);
    if (file == NULL)
        error("Error opening file");

	stringifyAssList(assList);

    return 0;
}

void stringifyProgram(program_t *program) {
	line_list_t *globalDecs = program->globalDeclarations;
	for (int i = 0; i < globalDecs->lineCount; i++) {
		declaration_list_t *globalDecList = globalDecs->lines[i]->statement.declaration->declarationList;
		for (int j = 0; j < globalDecList->decCount; j++)
			newTACGlobalDec(globalDecList->declarations[j]->lValue->displayName);
	}
	program->globalDeclarations->stringify(program->globalDeclarations);
	program->funDefList->stringify(program->funDefList);
	program->main->stringify(program->main);
}

void stringifyFunctionDefList(function_def_list_t *funDefList) {
	function_def_t **functions = funDefList->functions;
	int functionCount = funDefList->functionCount;
	for (int i = 0; i < functionCount; i++)
		functions[i]->stringify(functions[i]);
}

void stringifyFunDef(function_def_t *fun) {
	newTACLabel(FUNCTION_LABEL, fun->name);
	fun->paramList->stringify(fun->paramList);
	fun->lineList->stringify(fun->lineList);
}

void stringifyParamList(param_list_t *paramList) {
	param_t **params = paramList->params;
	char tempString[MAX_IDENTIFIER_LENGTH];
	int paramCount = paramList->paramCount;
	for (int i = 0; i < paramCount; i++) {
		tac_term_t *lValue = newTACTerm(VARIABLE, 0, NULL, params[i]->name);
		sprintf(tempString, "param%d", i + 1);
		tac_term_t *lTerm = newTACTerm(PARAM, 0, NULL, tempString);
		tac_exp_t *rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		newTACAssignment(lValue, rValue);
	}
}

void stringifyLineList(line_list_t *lineList) {
	line_t **lines = lineList->lines;
	int lineCount = lineList->lineCount;
	for (int i = 0; i < lineCount; i++)
		lines[i]->stringify(lines[i]);
}

void stringifyLine(line_t *line) {
    switch (line->type) {
		case DECLARATION:
		    line->statement.declaration->stringify(line->statement.declaration);
			break;
		case ASSIGNMENT:
		    line->statement.assignment->stringify(line->statement.assignment);
			break;
		case EXPRESSION_STATEMENT:
		    line->statement.expression->stringify(line->statement.expression);
			break;
		case RETURN:
		    line->statement.ret->stringify(line->statement.ret);
			break;
		case IF_ELSE:
		    line->statement.ifElse->stringify(line->statement.ifElse);
			break;
		case LOOP:
		    line->statement.loop->stringify(line->statement.loop);
			break;
		case FUNCTION:
		    line->statement.function->stringify(line->statement.function);
			break;
		default:
		    error("Invalid line type");
	} 
}

void stringifyDeclarationStatement(declaration_statement_t *decList) {
	declaration_t **decs = decList->declarationList->declarations;
	int decCount = decList->declarationList->decCount;
	char tempString[MAX_IDENTIFIER_LENGTH];
    for (int i = 0; i < decCount; i++) {
		declaration_t *dec = decs[i];
		if (dec->exp == NULL)
			continue;
		dec->exp->stringify(dec->exp);
		tac_term_t *lValue = newTACTerm(VARIABLE, 0, NULL, dec->lValue->displayName);
		sprintf(tempString, "t%d", tCount - 1);
		tac_term_t *lTerm = newTACTerm(TEMPORARY, 0, NULL, tempString);
		tac_exp_t *rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		newTACAssignment(lValue, rValue);
	}
}

void stringifyAssignmentStatement(assignment_statement_t *ass) {
	ass->exp->stringify(ass->exp);
	for (int i = 0; i < ass->lValue->depth; i++) {
		ass->lValue->subscripts[i]->stringify(ass->lValue->subscripts[i]);
	}

	tac_term_t *lValue = newTACTerm(VARIABLE, ass->lValue->depth, ass->lValue->subscripts, ass->lValue->displayName);
	tac_term_t *lTerm = newTACTerm(VARIABLE, 0, NULL, ass->exp->lValue);
    tac_exp_t *rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
	newTACAssignment(lValue, rValue);
}

void stringifyExpression(expression_t *exp) {
    char tempString[MAX_IDENTIFIER_LENGTH];
	tac_term_t *lValue;
	tac_term_t *lTerm;
	tac_exp_t *rValue;
    switch (exp->type) {
		case INT_CONSTANT:
			sprintf(tempString, "t%d", tCount++);
			lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
			lTerm = newTACTerm(INT_LITERAL, 0, NULL, exp->lValue);
			rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		    newTACAssignment(lValue, rValue);

			sprintf(exp->lValue, "t%d", tCount - 1);
			break;
		case CHAR_CONSTANT:
			sprintf(tempString, "t%d", tCount++);
			lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
			lTerm = newTACTerm(CHAR_LITERAL, 0, NULL, exp->lValue);
			rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		    newTACAssignment(lValue, rValue);

			sprintf(exp->lValue, "t%d", tCount - 1);
			break;
		case VAR_CONSTANT:
			sprintf(tempString, "t%d", tCount++);
			lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
			lTerm = newTACTerm(VARIABLE, 0, NULL, exp->lValue);
			rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		    newTACAssignment(lValue, rValue);

			sprintf(exp->lValue, "t%d", tCount - 1);
			break;
		case BIN_OP:
			exp->child.binOp->stringify(exp, exp->child.binOp);
			sprintf(exp->lValue, "t%d", tCount - 1);
			break;
		case FUNCTION_CALL:
			exp->child.functionCall->stringify(exp->child.functionCall);

			sprintf(tempString, "t%d", tCount++);
			lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
			lTerm = newTACTerm(RETVAL, 0, NULL, "retval");
			rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		    newTACAssignment(lValue, rValue);

			sprintf(exp->lValue, "t%d", tCount - 1);
			break;
		default:
			error("Invalid expression");
	}
}

void stringifyReturnStatement(return_statement_t *ret) {
    if (ret->exp != NULL) {
		tac_term_t *lValue;
		tac_term_t *lTerm;
		tac_exp_t *rValue;
		switch (ret->exp->type) {
			case INT_CONSTANT:
				lValue = newTACTerm(RETVAL, 0, NULL, "retval");
				lTerm = newTACTerm(INT_LITERAL, 0, NULL, ret->exp->lValue);
				rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
				newTACAssignment(lValue, rValue);
				break;
			case CHAR_CONSTANT:
				lValue = newTACTerm(RETVAL, 0, NULL, "retval");
				lTerm = newTACTerm(CHAR_LITERAL, 0, NULL, ret->exp->lValue);
				rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
				newTACAssignment(lValue, rValue);
				break;
			case VAR_CONSTANT:
				lValue = newTACTerm(RETVAL, 0, NULL, "retval");
				lTerm = newTACTerm(VARIABLE, 0, NULL, ret->exp->lValue);
				rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
				newTACAssignment(lValue, rValue);
				break;
			default:
				ret->exp->stringify(ret->exp);
				lValue = newTACTerm(RETVAL, 0, NULL, "retval");
				char tempString[MAX_IDENTIFIER_LENGTH];
				sprintf(tempString, "t%d", tCount - 1);
				lTerm = newTACTerm(TEMPORARY, 0, NULL, tempString);
				rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
				newTACAssignment(lValue, rValue);
		}
	}

	newTACReturn("return");
}

void stringifyIfElseStatement(if_else_statement_t *ifElse) {
	condition_t *baseCon = ifElse->condition;
	bool rootIfElse = ifElse->trueLabel == 0 && ifElse->falseLabel == 0;
	char tempString[MAX_IDENTIFIER_LENGTH];

	if (ifElse->trueLabel == 0)
		ifElse->trueLabel = lCount++;
	if (ifElse->falseLabel == 0)
		ifElse->falseLabel = lCount++;

    if_else_statement_t *chainIfElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
    if_else_statement_t *baseIfElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));

	int tempLabel;
	char tempLabelString[MAX_IDENTIFIER_LENGTH];

	switch (baseCon->op) {
		case NOT:
			baseIfElse->condition = baseCon->base;
			baseIfElse->trueLabel = 0;
			baseIfElse->falseLabel = 0;
			baseIfElse->ifLineList = ifElse->elseLineList;
			baseIfElse->elseLineList = ifElse->ifLineList;
			baseIfElse->stringify = &stringifyIfElseStatement;
			baseIfElse->isMatched = ifElse->isMatched;
			baseIfElse->stringify(baseIfElse);
			return;
		case SHORT_AND:
			tempLabel = lCount++;
			baseIfElse->condition = baseCon->base;
			baseIfElse->trueLabel = tempLabel;
			baseIfElse->falseLabel = ifElse->falseLabel;
			baseIfElse->stringify = &stringifyIfElseStatement;
			baseIfElse->stringify(baseIfElse);


			sprintf(tempLabelString, "L%d", tempLabel);
			newTACLabel(JUMP_LABEL, tempLabelString);

			chainIfElse->condition = baseCon->chain;
			chainIfElse->trueLabel = ifElse->trueLabel;
			chainIfElse->falseLabel = ifElse->falseLabel;
			chainIfElse->stringify = &stringifyIfElseStatement;
			chainIfElse->stringify(chainIfElse);
			break;
		case SHORT_OR:
			tempLabel = lCount++;
			baseIfElse->condition = baseCon->base;
			baseIfElse->trueLabel = ifElse->trueLabel;
			baseIfElse->falseLabel = tempLabel;
			baseIfElse->stringify = &stringifyIfElseStatement;
			baseIfElse->stringify(baseIfElse);

			sprintf(tempLabelString, "L%d", tempLabel);
			newTACLabel(JUMP_LABEL, tempLabelString);

			chainIfElse->condition = baseCon->chain;
			chainIfElse->trueLabel = ifElse->trueLabel;
			chainIfElse->falseLabel = ifElse->falseLabel;
			chainIfElse->stringify = &stringifyIfElseStatement;
			chainIfElse->stringify(chainIfElse);
			break;
		case SINGLE:
			baseCon->exp->stringify(baseCon->exp);
			sprintf(tempLabelString, "L%d", ifElse->trueLabel);
			newTACGoto(IF_GOTO, tempLabelString, baseCon->exp->lValue);

			sprintf(tempLabelString, "L%d", ifElse->falseLabel);
			newTACGoto(GOTO, tempLabelString, NULL);
			break;
		default:
		    error("Invalid condition chaining");
	}

	if (ifElse->ifLineList != NULL) {
		sprintf(tempString, "L%d", ifElse->trueLabel);
		newTACLabel(JUMP_LABEL, tempString);
		ifElse->ifLineList->stringify(ifElse->ifLineList);
	}

	int exitLabel;

	if (ifElse->ifLineList != NULL & ifElse->elseLineList != NULL)
		exitLabel = lCount++;
	else if (ifElse->elseLineList != NULL)
		exitLabel = ifElse->trueLabel;
	else if (ifElse->ifLineList != NULL)
		exitLabel = ifElse->falseLabel;

	if (rootIfElse && ifElse->isMatched) {
		sprintf(tempLabelString, "L%d", exitLabel);
		newTACGoto(GOTO, tempLabelString, NULL);
	}

	if (ifElse->elseLineList != NULL) {
		sprintf(tempString, "L%d", ifElse->falseLabel);
		newTACLabel(JUMP_LABEL, tempString);
		ifElse->elseLineList->stringify(ifElse->elseLineList);
	}

	if (rootIfElse) {
		sprintf(tempString, "L%d", exitLabel);
		newTACLabel(JUMP_LABEL, tempString);
	}
}

void stringifyLoopStatement(loop_statement_t *loop) {
	switch (loop->type) {
		case WHILE:
		    loop->loop.whileLoop->stringify(loop->loop.whileLoop);
			break;
		case FOR:
		    loop->loop.forLoop->stringify(loop->loop.forLoop);
			break;
		default:
		    error("Invalid loop type");
	}
}

void stringifyWhileLoop(while_loop_t *loop) {
    loop->startLabel = lCount++;
    loop->trueLabel = lCount++;
    loop->falseLabel = lCount++;
	char tempString[MAX_IDENTIFIER_LENGTH];
	sprintf(tempString, "L%d", loop->startLabel);
	newTACLabel(JUMP_LABEL, tempString);
	if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
	ifElse->condition = loop->condition;
	ifElse->ifLineList = loop->lineList;
	ifElse->trueLabel = loop->trueLabel;
	ifElse->falseLabel = loop->falseLabel;
	ifElse->stringify = &stringifyIfElseStatement;
	ifElse->stringify(ifElse);

	sprintf(tempString, "L%d", loop->startLabel);
	newTACGoto(GOTO, tempString, NULL);
	
	sprintf(tempString, "L%d", loop->falseLabel);
	newTACLabel(JUMP_LABEL, tempString);
}

void stringifyForLoop(for_loop_t *loop) {
    loop->startLabel = lCount++;
    loop->trueLabel = lCount++;
    loop->falseLabel = lCount++;
	loop->initial->stringify(loop->initial);
	char tempString[MAX_IDENTIFIER_LENGTH];
	sprintf(tempString, "L%d", loop->startLabel);
	newTACLabel(JUMP_LABEL, tempString);
	if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
	ifElse->condition = loop->condition;
	ifElse->ifLineList = loop->lineList;
	ifElse->trueLabel = loop->trueLabel;
	ifElse->falseLabel = loop->falseLabel;
	ifElse->stringify = &stringifyIfElseStatement;
	ifElse->stringify(ifElse);
	loop->update->stringify(loop->update);

	sprintf(tempString, "L%d", loop->startLabel);
	newTACGoto(GOTO, tempString, NULL);

	sprintf(tempString, "L%d", loop->falseLabel);
	newTACLabel(JUMP_LABEL, tempString);
}

void stringifyBinOp(expression_t *exp, bin_op_t *binOp) {
	sprintf(exp->lValue, "t%d", tCount);
	expression_t *left = binOp->left;
	expression_t *right = binOp->right;

	tac_term_e leftType;
	tac_term_e rightType;

	switch (left->type) {
		case BIN_OP:
		    left->stringify(left);
			leftType = TEMPORARY;
			break;
		case FUNCTION_CALL:
		    left->stringify(left);
			leftType = TEMPORARY;
			break;
		case CHAR_CONSTANT:
			leftType = CHAR_LITERAL;
			break;
		case INT_CONSTANT:
			leftType = INT_LITERAL;
			break;
		case VAR_CONSTANT:
			leftType = VARIABLE;
			break;
		default:
		    error("Invalid expression type");
	}

	switch (right->type) {
		case BIN_OP:
		    right->stringify(right);
			rightType = TEMPORARY;
			break;
		case FUNCTION_CALL:
		    right->stringify(right);
			rightType = TEMPORARY;
			break;
		case CHAR_CONSTANT:
			rightType = CHAR_LITERAL;
			break;
		case INT_CONSTANT:
			rightType = INT_LITERAL;
			break;
		case VAR_CONSTANT:
			rightType = VARIABLE;
			break;
		default:
		    error("Invalid expression type");

	}

    char tempString[MAX_IDENTIFIER_LENGTH];
	sprintf(tempString, "t%d", tCount++);
	tac_term_t *lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
	tac_term_t *lTerm = newTACTerm(leftType, 0, NULL, left->lValue);
	tac_term_t *rTerm = newTACTerm(rightType, 0, NULL, right->lValue);
	tac_exp_t *rValue = newTACExp(TAC_BIN_OP, PLUS, lTerm, rTerm);

	switch (binOp->type) {
		case PLUS:
			rValue->op = PLUS;
			break;
		case MINUS:
			rValue->op = MINUS;
			break;
		case COMPAR_EQ:
			rValue->op = COMPAR_EQ;
			break;
		case COMPAR_NE:
			rValue->op = COMPAR_NE;
			break;
		case COMPAR_LT:
			rValue->op = COMPAR_LT;
			break;
		case COMPAR_GT:
			rValue->op = COMPAR_GT;
			break;
		case COMPAR_LE:
			rValue->op = COMPAR_LE;
			break;
		case COMPAR_GE:
			rValue->op = COMPAR_GE;
			break;
		case MULTIPLY:
			rValue->op = MULTIPLY;
			break;
		case DIVIDE:
			rValue->op = DIVIDE;
			break;
		case EXPONENT:
			rValue->op = EXPONENT;
			break;
		default:
			error("Invalid binary operation");
	}

	newTACAssignment(lValue, rValue);
}

void stringifyFunctionCall(function_call_t *fun) {
	arg_t **args = fun->argList->args;
	int argCount = fun->argList->argCount;
	char **passedParams = (char **)malloc(MAX_ARGS * sizeof(char *));
	int passedParamCount = 0;
	char tempString[MAX_IDENTIFIER_LENGTH];
	tac_term_t *lValue;
	tac_term_t *lTerm;
	tac_exp_t *rValue;

	for (int i = 0; i < argCount; i++) {
		arg_t *arg = args[i];
		passedParams[passedParamCount] = malloc(MAX_IDENTIFIER_LENGTH * sizeof(char));

		switch (arg->type) {
			case STRING:
				sprintf(tempString, "t%d", tCount);
				lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
				lTerm = newTACTerm(STRING_LITERAL, 0, NULL, arg->value.str);
				rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
				newTACAssignment(lValue, rValue);
				sprintf(passedParams[passedParamCount++], "t%d", tCount++);
				break;
			case EXPRESSION:
				switch(arg->value.exp->type) {
				    case CHAR_CONSTANT:
						lTerm = newTACTerm(CHAR_LITERAL, 0, NULL, arg->value.exp->lValue);
						break;
				    case INT_CONSTANT:
						lTerm = newTACTerm(INT_LITERAL, 0, NULL, arg->value.exp->lValue);
						break;
				    case VAR_CONSTANT:
						lTerm = newTACTerm(VARIABLE, 0, NULL, arg->value.exp->lValue);
						break;
				    default:
					    arg->value.exp->stringify(arg->value.exp);
						lTerm = newTACTerm(VARIABLE, 0, NULL, arg->value.exp->lValue);
				}

				sprintf(tempString, "t%d", tCount);
				lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
				rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
				newTACAssignment(lValue, rValue);
				sprintf(passedParams[passedParamCount++], "t%d", tCount++);
				break;
			default:
				error("Invalid argument");
		}
	}

	for (int i = 0; i < passedParamCount; i++) {
		sprintf(tempString, "param%d", i + 1);
		tac_term_t *lValue = newTACTerm(PARAM, 0, NULL, tempString);
		tac_term_t *lTerm = newTACTerm(TEMPORARY, 0, NULL, passedParams[i]);
		tac_exp_t *rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		newTACAssignment(lValue, rValue);
	}
	newTACCall(fun->name);
}

void newTAC(tac_e type, void *instruction) {
    tac_t *tac = (tac_t *)malloc(sizeof(tac_t *));
	tac->type = type;
	tac->stringify = &stringifyTAC;
	switch(tac->type) {
		case TAC_GLOBAL_DEC:
			tac->instruction.global = instruction;
		    break;
		case TAC_ASSIGNMENT:
			tac->instruction.assignment = instruction;
		    break;
		case TAC_LABEL:
			tac->instruction.label = instruction;
		    break;
		case TAC_GOTO:
			tac->instruction.jump = instruction;
		    break;
		case TAC_CALL:
			tac->instruction.call = instruction;
		    break;
		case TAC_RETURN:
			tac->instruction.ret = instruction;
		    break;
		default:
		    error("Invalid TAC type");

	}
	tacList->instructions[tacList->tacCount++] = tac;
}

void newTACGlobalDec(char value[MAX_IDENTIFIER_LENGTH]) {
    tac_global_dec_t *tacGlobal = (tac_global_dec_t *)malloc(sizeof(tac_global_dec_t));
	strcpy(tacGlobal->value, value);
	tacGlobal->stringify = &stringifyTACGlobalDec;
	newTAC(TAC_GLOBAL_DEC, tacGlobal);
}

void newTACAssignment(tac_term_t *lValue, tac_exp_t *rValue) {
    tac_ass_t *tacAss = (tac_ass_t *)malloc(sizeof(tac_ass_t));
	tacAss->lValue = lValue;
	tacAss->rValue = rValue;
	tacAss->stringify = &stringifyTACAssignment;
	newTAC(TAC_ASSIGNMENT, tacAss);
}

tac_term_t *newTACTerm(tac_term_e type, int depth, expression_t **subscripts,
                       char value[MAX_IDENTIFIER_LENGTH]) {
    tac_term_t *tacTerm = (tac_term_t *)calloc(1, sizeof(tac_term_t));
	tacTerm->type = type;
	tacTerm->depth = depth;
	tacTerm->subscripts = subscripts;
	strcpy(tacTerm->value, value);
	tacTerm->stringify = &stringifyTACTerm;

	return tacTerm;
}

tac_exp_t *newTACExp(tac_exp_e type, bin_op_e op, tac_term_t *lTerm,
                     tac_term_t *rTerm) {
    tac_exp_t *tacExp = (tac_exp_t *)malloc(sizeof(tac_exp_t));
	tacExp->type = type;
	tacExp->op = op;
	tacExp->lTerm = lTerm;
	tacExp->rTerm = rTerm;
	tacExp->stringify = &stringifyTACExp;
	return tacExp;
}

void newTACLabel(label_e type, char value[MAX_IDENTIFIER_LENGTH]) {
    tac_label_t *tacLabel = (tac_label_t *)malloc(sizeof(tac_label_t));
	tacLabel->type = type;
	strcpy(tacLabel->value, value);
	tacLabel->stringify = &stringifyTACLabel;
	newTAC(TAC_LABEL, tacLabel);
}

void newTACGoto(goto_e type, char label[MAX_IDENTIFIER_LENGTH],
                char condition[MAX_IDENTIFIER_LENGTH]) {
    tac_goto_t *tacGoto = (tac_goto_t *)calloc(1, sizeof(tac_goto_t));
	tacGoto->type = type;
	strcpy(tacGoto->label, label);
	if (tacGoto->type == IF_GOTO)
		strcpy(tacGoto->condition, condition);
	tacGoto->stringify = &stringifyTACGoto;
	newTAC(TAC_GOTO, tacGoto);
}

void newTACCall(char label[MAX_IDENTIFIER_LENGTH]) {
    tac_call_t *tacCall = (tac_call_t *)malloc(sizeof(tac_call_t));
	strcpy(tacCall->label, label);
	tacCall->stringify = &stringifyTACCall;
	newTAC(TAC_CALL, tacCall);
}

void newTACReturn(char label[MAX_IDENTIFIER_LENGTH]) {
    tac_return_t *tacRet = (tac_return_t *)malloc(sizeof(tac_return_t));
	strcpy(tacRet->label, label);
	tacRet->stringify = &stringifyTACReturn;
	newTAC(TAC_RETURN, tacRet);
}

void stringifyTAC(tac_t *tac) {
    switch (tac->type) {
		case TAC_GLOBAL_DEC:
			tac->instruction.global->stringify(tac->instruction.global);
		    break;
		case TAC_ASSIGNMENT:
			tac->instruction.assignment->stringify(tac->instruction.assignment);
		    break;
		case TAC_LABEL:
			tac->instruction.label->stringify(tac->instruction.label);
		    break;
		case TAC_GOTO:
			tac->instruction.jump->stringify(tac->instruction.jump);
		    break;
		case TAC_CALL:
			tac->instruction.call->stringify(tac->instruction.call);
		    break;
		case TAC_RETURN:
			tac->instruction.ret->stringify(tac->instruction.ret);
		    break;
		default:
		    error("Invalid TAC type");
	}
}

void stringifyTACGlobalDec(tac_global_dec_t *tac) {
    printf("global %s\n", tac->value);
}

void stringifyTACAssignment(tac_ass_t *tac) {
    tac->lValue->stringify(tac->lValue);
	printf(" = ");
    tac->rValue->stringify(tac->rValue);
	printf("\n");
}

void stringifyTACTerm(tac_term_t *term) {
	printf("%s", term->value);
	for (int i = 0; i < term->depth; i++) {
		printf("[%s]", term->subscripts[i]->lValue);
	}
}

void stringifyTACExp(tac_exp_t *exp) {
    switch (exp->type) {
		case TAC_CONSTANT:
		    exp->lTerm->stringify(exp->lTerm);
			break;
		case TAC_BIN_OP:
		    exp->lTerm->stringify(exp->lTerm);
			switch (exp->op) {
				case PLUS:
					printf(" + ");
				    break;
				case MINUS:
					printf(" - ");
				    break;
				case COMPAR_EQ:
					printf(" == ");
				    break;
				case COMPAR_NE:
					printf(" != ");
				    break;
				case COMPAR_LT:
					printf(" < ");
				    break;
				case COMPAR_GT:
					printf(" > ");
				    break;
				case COMPAR_LE:
					printf(" <= ");
				    break;
				case COMPAR_GE:
					printf(" >= ");
				    break;
				case MULTIPLY:
					printf(" * ");
				    break;
				case DIVIDE:
					printf(" / ");
				    break;
				case EXPONENT:
					printf(" ** ");
				    break;
				default:
				    error("Invalid TAC binary operation");
			}
		    exp->rTerm->stringify(exp->rTerm);
		    break;
		default:
		    error("Invalid TAC expression");
	}
}

void stringifyTACLabel(tac_label_t *tac) {
    printf("%s:\n", tac->value);
}

void stringifyTACGoto(tac_goto_t *tac) {
    switch(tac->type) {
		case IF_GOTO:
		    printf("if (%s) goto %s\n", tac->condition, tac->label);
			break;
		case GOTO:
		    printf("goto %s\n", tac->label);
			break;
		default:
		    error("Invalid jump type");
	}
}

void stringifyTACCall(tac_call_t *tac) {
    printf("call %s\n", tac->label);
}

void stringifyTACReturn(tac_return_t *tac) {
    printf("%s\n", tac->label);
}

unsigned long hash(char *str) {
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return hash % MAX_IDENTIFIERS;
}

symbol_table_item_t *searchSymbol(char *key, symbol_table_item_t* hashTable[]) {

	int hashIndex = hash(key);

	while(hashTable[hashIndex] != NULL) {
	  if(hashTable[hashIndex]->key == hashIndex)
		 return hashTable[hashIndex]; 
			
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}        

	return NULL;        
}

void insertSymbol(char *key, identifier_t *data, symbol_table_item_t* hashTable[]) {
	symbol_table_item_t *item;
	item = searchSymbol(key, hashTable);
	if (item != NULL)
		return;

	int hashIndex = hash(key);
	item = (symbol_table_item_t*) malloc(sizeof(symbol_table_item_t));
	item->data = data;
	item->key = hashIndex;

	while(hashTable[hashIndex] != NULL) {
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}

	hashTable[hashIndex] = item;
}

void firstPassTACs(tac_list_t *tacList) {
	tac_t *tac;
	int i = 0;
	char tempStr[MAX_IDENTIFIER_LENGTH];
	int currStackOffset = 0;

	while (i < tacList->tacCount) {
		tac = tacList->instructions[i];
		if (tac->type == TAC_LABEL && tac->instruction.label->type == FUNCTION_LABEL) {
			strcpy(currTACFunction, tac->instruction.label->value);
			currStackOffset = 0;
		}

		else if (tac->type == TAC_RETURN) {
			identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
			id->type = INT;
			strcpy(id->name, currTACFunction);
			strcpy(id->displayName, currTACFunction);
			id->stackOffset = currStackOffset + 4;
			insertSymbol(currTACFunction, id, symbolTable);
		    bzero(currTACFunction, MAX_IDENTIFIER_LENGTH);
		}

		else if (tac->type == TAC_ASSIGNMENT) {
			tac_ass_t *ass = tac->instruction.assignment;
			if (ass->lValue->type != TEMPORARY && ass->lValue->type != VARIABLE)
				goto continue_first_pass;

			if (ass->rValue->lTerm->type == PARAM) {
				int baseOffset = 8;
				while (tacList->instructions[i]->type == TAC_ASSIGNMENT && tacList->instructions[i]->instruction.assignment->rValue->lTerm->type == PARAM) {
					sprintf(tempStr, "%s_%s", currTACFunction, tacList->instructions[i]->instruction.assignment->lValue->value);
					symbol_table_item_t *item = searchSymbol(tempStr, symbolTable);
					if (item == NULL)
						error("Undefined parameter");

					item->data->stackOffset = baseOffset;
					baseOffset += 4;
				    i++;
				}
				continue;
			}

		    sprintf(tempStr, "%s_%s", currTACFunction, ass->lValue->value);
			symbol_table_item_t *item = searchSymbol(tempStr, symbolTable);

			if (item != NULL) {
				if (item->data->stackOffset == 0) {
				    item->data->stackOffset = -(currStackOffset + 4);
					currStackOffset += 4;
					for (int k = 0; k < item->data->depth; k++)
						switch (item->data->type) {
						    case INT:
								currStackOffset += 4 * (atoi(item->data->subscripts[k]->lValue));
								break;
						    case CHAR:
								currStackOffset += 1 * (atoi(item->data->subscripts[k]->lValue));
								break;
						    default:
								error("Arrays supported only with INT and CHAR");
						}
				}
				goto continue_first_pass;
		    } else {
				sprintf(tempStr, "global_%s", ass->lValue->value);
				item = searchSymbol(tempStr, symbolTable);
				if (item != NULL)
				    goto continue_first_pass;
			}

			bool isPointer = false;

		    sprintf(tempStr, "%s_%s", currTACFunction, ass->rValue->lTerm->value);
			if (ass->rValue->lTerm->type == TEMPORARY || ass->rValue->lTerm->type == VARIABLE) {
				symbol_table_item_t *rItem = searchSymbol(tempStr, symbolTable);

				if (rItem == NULL) {
				    sprintf(tempStr, "global_%s", ass->rValue->lTerm->value);
					rItem = searchSymbol(tempStr, symbolTable);
					if (rItem == NULL)
						error("[firstPassTAC] Undefined variable used to read");
				}

				isPointer = rItem->data->isPointer;
			}

			identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
			tac_term_e rType = ass->rValue->lTerm->type;
			if (rType == STRING_LITERAL) {
				sprintf(tempStr, "global_%s", ass->lValue->value);
				id->type = DATA_STRING;
			} else {
				sprintf(tempStr, "%s_%s", currTACFunction, ass->lValue->value);
				id->type = rType == CHAR_LITERAL ? CHAR : INT;
			}

			strcpy(id->name, tempStr);
			strcpy(id->displayName, ass->lValue->value);
			id->stackOffset = -(currStackOffset + 4);
			id->isPointer = isPointer;
			currStackOffset += 4;
			insertSymbol(tempStr, id, symbolTable);
		}

continue_first_pass:
		i++;
	}
}

assembly_list_t *parseTACs(tac_list_t *tacList) {
	tac_t *tac;
	assembly_list_t *assList = (assembly_list_t *)calloc(1, sizeof(assembly_list_t));
	assList->instructions = (assembly_t **)calloc(MAX_ASSEMBLY_INSTRUCTIONS, sizeof(assembly_t *));

    int i = 0, j;
	char callArgs[MAX_ARGS][MAX_IDENTIFIER_LENGTH];
	int callArgCount = 0;

    while (i < tacList->tacCount) {
		tac = tacList->instructions[i];
		switch(tac->type) {
		    case TAC_GLOBAL_DEC:
				assList->instructions[assList->assCount++] = newAssemblyGlobalDec(tac->instruction.global);
				break;
		    case TAC_ASSIGNMENT:
				if (tac->instruction.assignment->lValue->type == PARAM || tac->instruction.assignment->rValue->lTerm->type == PARAM)
				    break;
				if (streq(currScope, "global", 6) && tac->instruction.assignment->lValue->type == TEMPORARY)
					newTACGlobalDec(tac->instruction.assignment->lValue->value);

				assList->instructions[assList->assCount++] = newAssemblyAssignment(tac->instruction.assignment);
				break;
		    case TAC_LABEL:
				if (tac->instruction.label->type == FUNCTION_LABEL)
				    strcpy(currScope, tac->instruction.label->value);
				assList->instructions[assList->assCount++] = newAssemblyLabel(tac->instruction.label);
				break;
		    case TAC_GOTO:
				assList->instructions[assList->assCount++] = newAssemblyGoto(tac->instruction.jump);
				break;
		    case TAC_CALL:
				j = i - 1;
				while (j >= 0 && tacList->instructions[j]->type == TAC_ASSIGNMENT &&
				    tacList->instructions[j]->instruction.assignment->lValue->type == PARAM) {
				    strcpy(callArgs[callArgCount++],
				    tacList->instructions[j]->instruction.assignment->rValue->lTerm->value);
				    j--;
				}
				assList->instructions[assList->assCount++] = newAssemblyCall(callArgCount, callArgs, tac->instruction.call);
				callArgCount = 0;
				break;
		    case TAC_RETURN:
				assList->instructions[assList->assCount++] = newAssemblyReturn(tac->instruction.ret);
				break;
		}
		i++;
	}

	return assList;
}

assembly_t *newAssemblyGlobalDec(tac_global_dec_t *tac) {
	char temp[MAX_IDENTIFIER_LENGTH];
	sprintf(temp, "global_%s", tac->value);
	symbol_table_item_t *item = searchSymbol(temp, symbolTable);
	if (item == NULL)
		error("Global variable not found");

    assembly_bss_t *bss = (assembly_bss_t *)malloc(sizeof(assembly_bss_t));
	bss->var = item->data;
	bss->stringify = &stringifyBSS;

	assembly_t *ass = (assembly_t *)malloc(sizeof(assembly_t));
	ass->section = ASSEMBLY_BSS_SECTION;
	ass->instruction.bss = bss;

	return ass;
}

assembly_t *newAssemblyAssignment(tac_ass_t *tac) {
    assembly_t *ass = (assembly_t *)malloc(sizeof(assembly_t));

	if (tac->rValue->lTerm->type == STRING_LITERAL) {
		assembly_data_t *data = (assembly_data_t *)malloc(sizeof(assembly_data_t));
		data->id = globalDataCount++;
		strcpy(data->key, tac->lValue->value);
		strcpy(data->value, tac->rValue->lTerm->value);
		data->stringify = &stringifyData;

		ass->section = ASSEMBLY_DATA_SECTION;
		ass->instruction.data = data;
		return ass;
	}

	assembly_assignment_t *assign = (assembly_assignment_t *)malloc(sizeof(assembly_assignment_t));
	assign->lValue = newAssemblyTerm(tac->lValue);
	assembly_term_t *lTerm = newAssemblyTerm(tac->rValue->lTerm);
	assembly_term_t *rTerm;

	if (tac->rValue->type == TAC_BIN_OP)
		rTerm = newAssemblyTerm(tac->rValue->rTerm);
    else
		rTerm = NULL;

	assign->rValue = newAssemblyExp(tac->rValue->type, tac->rValue->op, lTerm, rTerm);
	assign->stringify = &stringifyAssemblyAssignment;

    assembly_text_t *text = (assembly_text_t *)malloc(sizeof(assembly_text_t));
	text->type = ASSEMBLY_ASSIGNMENT;
	text->instruction.assignment = assign;
	text->stringify = &stringifyText;

	ass->section = ASSEMBLY_TEXT_SECTION;
	ass->instruction.text = text;

	return ass;
}

assembly_t *newAssemblyLabel(tac_label_t *tac) {
	assembly_label_t *label = (assembly_label_t *)malloc(sizeof(assembly_label_t));
	label->type = tac->type;
	strcpy(label->value, tac->value);
	label->stringify = &stringifyAssemblyLabel;

    assembly_text_t *text = (assembly_text_t *)malloc(sizeof(assembly_text_t));
	text->type = ASSEMBLY_LABEL;
	text->instruction.label = label;
	text->stringify = &stringifyText;

	assembly_t *ass = (assembly_t *)malloc(sizeof(assembly_t));
	ass->section = ASSEMBLY_TEXT_SECTION;
	ass->instruction.text = text;

	return ass;
}

assembly_t *newAssemblyCall(int argCount, char arguments[MAX_ARGS][MAX_IDENTIFIER_LENGTH], tac_call_t *tac) {
	assembly_call_t *call = (assembly_call_t *)calloc(1, sizeof(assembly_call_t));

	for (int i = 0; i < argCount; i++)
		strcpy(call->arguments[call->argCount++], arguments[i]);

	strcpy(call->scope, currScope);
	strcpy(call->label, tac->label);
	call->stringify = &stringifyAssemblyCall;

    assembly_text_t *text = (assembly_text_t *)malloc(sizeof(assembly_text_t));
	text->type = ASSEMBLY_CALL;
	text->instruction.call = call;
	text->stringify = &stringifyText;

	assembly_t *ass = (assembly_t *)malloc(sizeof(assembly_t));
	ass->section = ASSEMBLY_TEXT_SECTION;
	ass->instruction.text = text;

	return ass;
}

assembly_t *newAssemblyReturn(tac_return_t *tac) {
	assembly_return_t *ret = (assembly_return_t *)malloc(sizeof(assembly_return_t));
	strcpy(ret->label, tac->label);
	ret->stringify = &stringifyAssemblyReturn;

    assembly_text_t *text = (assembly_text_t *)malloc(sizeof(assembly_text_t));
	text->type = ASSEMBLY_RETURN;
	text->instruction.ret = ret;
	text->stringify = &stringifyText;

	assembly_t *ass = (assembly_t *)malloc(sizeof(assembly_t));
	ass->section = ASSEMBLY_TEXT_SECTION;
	ass->instruction.text = text;

	return ass;
}

assembly_t *newAssemblyGoto(tac_goto_t *tac) {
	assembly_goto_t *jump = (assembly_goto_t *)malloc(sizeof(assembly_goto_t));
	jump->type = tac->type;
	strcpy(jump->label, tac->label);
	strcpy(jump->scope, currScope);
	if (jump->type == IF_GOTO)
		strcpy(jump->condition, tac->condition);
	jump->stringify = &stringifyAssemblyJump;

    assembly_text_t *text = (assembly_text_t *)malloc(sizeof(assembly_text_t));
	text->type = ASSEMBLY_GOTO;
	text->instruction.jump = jump;
	text->stringify = &stringifyText;

	assembly_t *ass = (assembly_t *)malloc(sizeof(assembly_t));
	ass->section = ASSEMBLY_TEXT_SECTION;
	ass->instruction.text = text;

	return ass;
}

assembly_exp_t *newAssemblyExp(tac_exp_e type, bin_op_e op, assembly_term_t *lTerm, assembly_term_t *rTerm) {
    assembly_exp_t *exp = (assembly_exp_t *)calloc(1, sizeof(assembly_exp_t));
	switch (type) {
		case TAC_BIN_OP:
			exp->type = ASSEMBLY_BIN_OP;
		    break;
		case TAC_CONSTANT:
			exp->type = ASSEMBLY_CONSTANT;
		    break;
	}
	exp->op = op;
	exp->lTerm = lTerm;
	exp->rTerm = rTerm;
	exp->stringify = &stringifyAssemblyExp;
	return exp;
}

assembly_term_t *newAssemblyTerm(tac_term_t *tac) {
    assembly_term_t *term = (assembly_term_t *)calloc(1, sizeof(assembly_term_t));
	bool updateScope = false;

	switch (tac->type) {
		case TEMPORARY:	
		    term->type = ASSEMBLY_VARIABLE;
			updateScope = true;
			break;
		case VARIABLE:	
		    term->type = ASSEMBLY_VARIABLE;
			updateScope = true;
			break;
		case RETVAL:	
		    term->type = EAX;
			break;
		case STRING_LITERAL:	
		    term->type = FMT;
			break;
		case CHAR_LITERAL:	
		    term->type = CHAR_IMMEDIATE;
			break;
		case INT_LITERAL:
		    term->type = INT_IMMEDIATE;
			break;
		default:
		    error("Invalid term type");
	}

	term->depth = tac->depth;
	term->subscripts = tac->subscripts;
	strcpy(term->value, tac->value);

	if (!updateScope)
		goto return_term;

	char tempStr[MAX_IDENTIFIER_LENGTH];
	sprintf(tempStr, "global_%s", tac->value);
	symbol_table_item_t *item = searchSymbol(tempStr, symbolTable);
	if (item == NULL) {
		sprintf(tempStr, "%s_%s", currScope, tac->value);
		item = searchSymbol(tempStr, symbolTable);
		if (item == NULL) {
			printf("%s\n", tempStr);
		    error("[newAssemblyTerm] Undefined variable");
		}
		strcpy(term->scope, currScope);
	} else {
		strcpy(term->scope, "global");
	}

return_term:
	return term;
}

void stringifyAssList(assembly_list_t *assList) {
    assembly_t *ass;
	assembly_bss_list_t *bssList = (assembly_bss_list_t *)calloc(1, sizeof(assembly_bss_list_t));
	bssList->instructions = (assembly_bss_t **)calloc(MAX_ASSEMBLY_INSTRUCTIONS, sizeof(assembly_bss_t *));
	assembly_data_list_t *dataList = (assembly_data_list_t *)calloc(1, sizeof(assembly_data_list_t));
	dataList->instructions = (assembly_data_t **)calloc(MAX_ASSEMBLY_INSTRUCTIONS, sizeof(assembly_data_t *));
	assembly_text_list_t *textList = (assembly_text_list_t *)calloc(1, sizeof(assembly_text_list_t));
	textList->instructions = (assembly_text_t **)calloc(MAX_ASSEMBLY_INSTRUCTIONS, sizeof(assembly_text_t *));

    for (int i = 0; i < assList->assCount; i++) {
		ass = assList->instructions[i];
		switch(ass->section) {
		    case ASSEMBLY_BSS_SECTION:
				bssList->instructions[bssList->assCount++] = ass->instruction.bss;
				break;
		    case ASSEMBLY_DATA_SECTION:
				dataList->instructions[dataList->assCount++] = ass->instruction.data;
				break;
		    case ASSEMBLY_TEXT_SECTION:
				textList->instructions[textList->assCount++] = ass->instruction.text;
				break;
		}
	}

	stringifyBSSList(bssList);
	stringifyDataList(dataList);
	stringifyTextList(textList);
	stringifyX86List(x86List);
}

void stringifyBSSList(assembly_bss_list_t *bssList) {
    x86_section_t *x86Section = (x86_section_t *)malloc(sizeof(x86_section_t));
	x86Section->type = X86_BSS;
	addX86Instruction(x86Section, X86_SECTION);

	for (int i = 0; i < bssList->assCount; i++)
		bssList->instructions[i]->stringify(bssList->instructions[i]);
}

void stringifyDataList(assembly_data_list_t *dataList) {
    x86_section_t *x86Section = (x86_section_t *)malloc(sizeof(x86_section_t));
	x86Section->type = X86_DATA;
	addX86Instruction(x86Section, X86_SECTION);

	for (int i = 0; i < dataList->assCount; i++) {
		dataList->instructions[i]->stringify(dataList->instructions[i]);
	}
}

void stringifyTextList(assembly_text_list_t *textList) {
    x86_section_t *x86Section = (x86_section_t *)malloc(sizeof(x86_section_t));
	x86Section->type = X86_TEXT;
	addX86Instruction(x86Section, X86_SECTION);

	assembly_text_t *text;
	for (int i = 0; i < textList->assCount; i++) {
		text = textList->instructions[i];
		text->stringify(text);
	}
}

void stringifyBSS(assembly_bss_t *ass) {
	identifier_t *var = ass->var;
	int space;
	switch(var->type) {
		case INT:
			space = 4 * (1 + var->depth);
			break;
		case CHAR:
			space = 1 * (1 + var->depth);
			break;
		default:
		    error("Unsupported data type");
	}

	x86_space_allocation_t *x86 = (x86_space_allocation_t *)malloc(sizeof(x86_space_allocation_t));
	x86->type = X86_SPACE;
	x86->allocation.space = space;
	strcpy(x86->value, ass->var->displayName);
	addX86Instruction(x86, X86_SPACE_ALLOCATION);
}

void stringifyData(assembly_data_t *ass) {
    x86_space_allocation_t *x86 = (x86_space_allocation_t *)malloc(sizeof(x86_space_allocation_t));
	x86->type = X86_ASCIZ;
	strcpy(x86->allocation.str, ass->value);
	strcpy(x86->value, ass->key);
	addX86Instruction(x86, X86_SPACE_ALLOCATION);
}

void stringifyText(assembly_text_t *text) {
    switch (text->type) {
		case ASSEMBLY_LABEL:
		    text->instruction.label->stringify(text->instruction.label);
			break;
	    case ASSEMBLY_ASSIGNMENT:
		    text->instruction.assignment->stringify(text->instruction.assignment);
			break;
	    case ASSEMBLY_GOTO:
		    text->instruction.jump->stringify(text->instruction.jump);
			break;
	    case ASSEMBLY_CALL:
		    text->instruction.call->stringify(text->instruction.call);
			break;
	    case ASSEMBLY_RETURN:
		    text->instruction.ret->stringify(text->instruction.ret);
			break;
    }
}

void stringifyAssemblyLabel(assembly_label_t *label) {
	if (label->type == FUNCTION_LABEL) {
		x86_section_t *x86Section = (x86_section_t *)malloc(sizeof(x86_section_t));
		x86Section->type = X86_GLOBL;
		strcpy(x86Section->label, label->value);
		addX86Instruction(x86Section, X86_SECTION);
	}

    x86_label_t *x86Label = (x86_label_t *)malloc(sizeof(x86_label_t));
	x86Label->type = label->type;
    strcpy(x86Label->label, label->value);
    addX86Instruction(x86Label, X86_LABEL);

	if (label->type == FUNCTION_LABEL) {
		newX86Stack(X86_PUSH, EBP_REGISTER);
		
		x86_data_movement_t *x86DataMovement = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
		x86DataMovement->op = X86_MOV;
		x86DataMovement->src = ESP_REGISTER;
		x86DataMovement->isDestAddress = false;
		x86DataMovement->dest = EBP_REGISTER;
		addX86Instruction(x86DataMovement, X86_DATA_MOVEMENT);

		symbol_table_item_t *item = searchSymbol(label->value, symbolTable);
		if (item == NULL)
		    error("Function not found");

		int stackOffset = item->data->stackOffset;
		x86_location_t *x86Location = (x86_location_t *)malloc(sizeof(x86_location_t));
		x86Location->type = X86_INT_IMMEDIATE;
		x86Location->value.intImmediate = stackOffset;
		newX86Arithmetic(X86_SUB, x86Location, ESP_REGISTER);
	}
}

void stringifyAssemblyAssignment(assembly_assignment_t *assignment) {
	x86_location_t *x86Location = getX86Location(assignment->lValue);
	expression_t *exp;
	bool hasSubscripts = false;

	for (int i = 0; i < assignment->lValue->depth; i++) {
		exp = assignment->lValue->subscripts[i];
		tac_term_t *tacTerm = newTACTerm(VARIABLE, 0, NULL, exp->lValue);
		assembly_term_t *assTerm = newAssemblyTerm(tacTerm);

		x86_data_movement_t *x86Mov = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
		x86Mov->op = X86_MOV;
		x86Mov->isDestAddress = false;
		x86Mov->src = getX86Location(assTerm);
		x86Mov->dest = EAX_REGISTER;
		addX86Instruction(x86Mov, X86_DATA_MOVEMENT);

		x86_data_movement_t *x86Lea = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
		x86Lea->op = X86_LEA;
		x86Lea->isDestAddress = false;
		x86Lea->src = x86Location;
		x86Lea->opReg = EAX_REGISTER;
		x86Lea->dest = EBX_REGISTER;
		hasSubscripts = true;
		addX86Instruction(x86Lea, X86_DATA_MOVEMENT);
	}

    assignment->rValue->stringify(assignment->rValue);

	x86_data_movement_t *x86DataMovement = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
	x86DataMovement->op = X86_MOV;
	x86DataMovement->src = EAX_REGISTER;

	if (hasSubscripts) {
		x86DataMovement->isDestAddress = true;
		x86DataMovement->dest = EBX_REGISTER;
	}
	else {
		x86DataMovement->isDestAddress = false;
		x86DataMovement->dest = x86Location;
	}

	addX86Instruction(x86DataMovement, X86_DATA_MOVEMENT);
}

void stringifyAssemblyCall(assembly_call_t *call) {
	symbol_table_item_t *item;
	char tempStr[MAX_IDENTIFIER_LENGTH];
    for (int i = 0; i < call->argCount; i++) {
		sprintf(tempStr, "%s_%s", call->scope, call->arguments[i]);
		item = searchSymbol(tempStr, symbolTable);

		if (item != NULL) {
		    x86_location_t *x86Location = (x86_location_t *)malloc(sizeof(x86_location_t));
		    x86Location->type = X86_MEMORY;
			x86Location->value.stackOffset = item->data->stackOffset;

			if (item->data->depth == 0) {
				newX86Stack(X86_PUSH, x86Location);
				continue;
		    }

			x86_data_movement_t *x86Lea = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
			x86Lea->op = X86_LEA;
			x86Lea->isDestAddress = false;
			x86Lea->src = x86Location;
			x86Lea->opReg = NULL;
			x86Lea->dest = EAX_REGISTER;
			addX86Instruction(x86Lea, X86_DATA_MOVEMENT);

			newX86Stack(X86_PUSH, EAX_REGISTER);

			continue;
		}

		sprintf(tempStr, "global_%s", call->arguments[i]);
		item = searchSymbol(tempStr, symbolTable);
		if (item == NULL)
		    error("Undefined variable");

		x86_stack_t *x86Stack = (x86_stack_t *)malloc(sizeof(x86_stack_t));
		x86Stack->op = X86_PUSH;

		x86_location_t *x86Location = (x86_location_t *)malloc(sizeof(x86_location_t));
		if (item->data->type == DATA_STRING)
		    x86Location->type = X86_DATA_FMT;
		else
		    x86Location->type = X86_GLOBAL;

		strcpy(x86Location->value.var, item->data->displayName);

		x86Stack->location = x86Location;
		addX86Instruction(x86Stack, X86_STACK);
	}

	x86_control_flow_t *x86Call = (x86_control_flow_t *)malloc(sizeof(x86_control_flow_t));
	x86Call->op = X86_CALL;
	strcpy(x86Call->label, call->label);
	addX86Instruction(x86Call, X86_CONTROL_FLOW);

	x86_location_t *x86Location = (x86_location_t *)malloc(sizeof(x86_location_t));
	x86Location->type = X86_INT_IMMEDIATE;
	x86Location->value.intImmediate = 4 * call->argCount;
	newX86Arithmetic(X86_ADD, x86Location, ESP_REGISTER);
}

void stringifyAssemblyJump(assembly_goto_t *jump) {
    x86_jump_t *x86Jump = (x86_jump_t *)malloc(sizeof(x86_jump_t));
	x86_compar_t *x86Compar = (x86_compar_t *)malloc(sizeof(x86_compar_t));
	x86_location_t *x86Location = (x86_location_t *)malloc(sizeof(x86_location_t));
	symbol_table_item_t *item;
	char tempStr[MAX_IDENTIFIER_LENGTH];
	x86_data_movement_t *x86DataMovementIntermediate = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
	x86DataMovementIntermediate->isDestAddress = false;

	strcpy(x86Jump->label, jump->label);

    switch(jump->type) {
		case IF_GOTO:
			sprintf(tempStr, "%s_%s", jump->scope, jump->condition);
			item = searchSymbol(tempStr, symbolTable);
			if (item == NULL)
				error("IF_GOTO condition not found");

		    int stackOffset = item->data->stackOffset;
			x86Location->type = X86_MEMORY;
			x86Location->value.stackOffset = stackOffset;

			x86DataMovementIntermediate->op = X86_MOV;
			x86DataMovementIntermediate->src = x86Location;
			x86DataMovementIntermediate->dest = ECX_REGISTER;
			addX86Instruction(x86DataMovementIntermediate, X86_DATA_MOVEMENT);

		    x86Compar->op = X86_CMP;
			x86Compar->src = ONE;
			x86Compar->dest = ECX_REGISTER;
			addX86Instruction(x86Compar, X86_COMPAR);
			addX86Instruction(x86Jump, X86_JUMP);
		    break;
		case GOTO:
			x86Jump->op = X86_JMP;
			addX86Instruction(x86Jump, X86_JUMP);
		    break;
		default:
		    error("Unsupported jump");
	}
}

void stringifyAssemblyReturn(assembly_return_t *ret) {
	x86_control_flow_t *leave = (x86_control_flow_t *)malloc(sizeof(x86_control_flow_t));
	leave->op = X86_LEAVE;
	addX86Instruction(leave, X86_CONTROL_FLOW);

	x86_control_flow_t *x86Ret = (x86_control_flow_t *)malloc(sizeof(x86_control_flow_t));
	x86Ret->op = X86_RET;
	addX86Instruction(x86Ret, X86_CONTROL_FLOW);
}

void stringifyAssemblyExp(assembly_exp_t *exp) {
	x86_location_t *x86LocationLTerm = getX86Location(exp->lTerm);
	x86_location_t *x86LocationRTerm = getX86Location(exp->rTerm);

	x86_data_movement_t *x86DataMovement = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
	x86DataMovement->isDestAddress = false;

	x86_data_movement_t *x86DataMovementIntermediate1 = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
	x86DataMovementIntermediate1->isDestAddress = false;

	x86_data_movement_t *x86DataMovementIntermediate2 = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
	x86DataMovementIntermediate2->isDestAddress = false;

	x86_compar_t *x86Compar = (x86_compar_t *)malloc(sizeof(x86_compar_t));
	x86_jump_t *x86Jump = (x86_jump_t *)malloc(sizeof(x86_jump_t));
	x86_arithmetic_t *x86Arithmetic = (x86_arithmetic_t *)malloc(sizeof(x86_arithmetic_t));
	x86_logic_t *x86Logic = (x86_logic_t *)malloc(sizeof(x86_logic_t));

    switch (exp->type) {
		case ASSEMBLY_BIN_OP:
			if (isComparison(exp->op)) {
				x86Logic->op = X86_XOR;
				x86Logic->src = EAX_REGISTER;
				x86Logic->dest = EAX_REGISTER;
				addX86Instruction(x86Logic, X86_LOGIC);

				x86DataMovementIntermediate1->op = X86_MOV;
				x86DataMovementIntermediate1->src = x86LocationLTerm;
				x86DataMovementIntermediate1->dest = ECX_REGISTER;
				addX86Instruction(x86DataMovementIntermediate1, X86_DATA_MOVEMENT);

				x86DataMovementIntermediate2->op = X86_MOV;
				x86DataMovementIntermediate2->src = x86LocationRTerm;
				x86DataMovementIntermediate2->dest = EDX_REGISTER;
				addX86Instruction(x86DataMovementIntermediate2, X86_DATA_MOVEMENT);

				x86Compar->op = X86_CMP;
				x86Compar->src = ECX_REGISTER;
				x86Compar->dest = EDX_REGISTER;
				addX86Instruction(x86Compar, X86_COMPAR);

				switch (exp->op) {
				    case COMPAR_EQ:
						x86DataMovement->op = X86_SETE;
						break;
				    case COMPAR_NE:
						x86DataMovement->op = X86_SETNE;
						break;
				    case COMPAR_LT:
						x86DataMovement->op = X86_SETL;
						break;
				    case COMPAR_GT:
						x86DataMovement->op = X86_SETG;
						break;
				    case COMPAR_LE:
						x86DataMovement->op = X86_SETLE;
						break;
				    case COMPAR_GE:
						x86DataMovement->op = X86_SETGE;
						break;
				    default:
						error("Invalid comparison operator");
				}

				x86DataMovement->src = ZEROF_REGISTER;
				x86DataMovement->dest = EAX_REGISTER;
				addX86Instruction(x86DataMovement, X86_DATA_MOVEMENT);
			} else {
				x86DataMovement->op = X86_MOV;
				x86DataMovement->src = x86LocationLTerm;
				x86DataMovement->dest = EAX_REGISTER;
				addX86Instruction(x86DataMovement, X86_DATA_MOVEMENT);

				switch (exp->op) {
				    case PLUS:
						x86Arithmetic = newX86Arithmetic(X86_ADD, x86LocationRTerm, EAX_REGISTER);
						break;
				    case MINUS:
						x86Arithmetic = newX86Arithmetic(X86_SUB, x86LocationRTerm, EAX_REGISTER);
						break;
				    case MULTIPLY:
						x86Arithmetic = newX86Arithmetic(X86_MUL, x86LocationRTerm, NULL);
						break;
				    case DIVIDE:
						x86Arithmetic = newX86Arithmetic(X86_DIV, x86LocationRTerm, NULL);
						break;
				    default:
						error("Invalid binary arithmetic operation");
				}
			}
		    break;
		case ASSEMBLY_CONSTANT:
			if (x86LocationLTerm->isPointer)
				x86DataMovement->op = X86_LEA;
			else
				x86DataMovement->op = X86_MOV;

			x86DataMovement->src = x86LocationLTerm;
			x86DataMovement->opReg = NULL;
			x86DataMovement->dest = EAX_REGISTER;
			addX86Instruction(x86DataMovement, X86_DATA_MOVEMENT);
		    break;
	}
}

bool isComparison(bin_op_e op) {
    return op == COMPAR_EQ || op == COMPAR_NE || op == COMPAR_LT || op == COMPAR_GT || op == COMPAR_LE || op == COMPAR_GE;
}

void newX86Stack(x86_stack_e op, x86_location_t *location) {
	x86_stack_t *x86 = (x86_stack_t *)malloc(sizeof(x86_stack_t));
	x86->op = op;
	x86->location = location;
	addX86Instruction(x86, X86_STACK);
}

x86_arithmetic_t *newX86Arithmetic(x86_arithmetic_e op, x86_location_t *src, x86_location_t *dest) {
	x86_arithmetic_t *x86 = (x86_arithmetic_t *)calloc(1, sizeof(x86_arithmetic_t));
	x86->op = op;
	x86->src = src;
	x86->dest = dest;
	addX86Instruction(x86, X86_ARITHMETIC);
	return x86;
}

void addX86Instruction(void *instruction, x86_e type) {
    x86_t *x86 = (x86_t *)malloc(sizeof(x86_t));
	x86->type = type;

	switch (x86->type) {
		case X86_SPACE_ALLOCATION:
			x86->instruction.spaceAllocation = (x86_space_allocation_t *)instruction;
		    break;
		case X86_DATA_MOVEMENT:
			x86->instruction.dataMovement = (x86_data_movement_t *)instruction;
		    break;
		case X86_ARITHMETIC:
			x86->instruction.arithmetic = (x86_arithmetic_t *)instruction;
		    break;
		case X86_LOGIC:
			x86->instruction.logic = (x86_logic_t *)instruction;
		    break;
		case X86_CONTROL_FLOW:
			x86->instruction.controlFlow = (x86_control_flow_t *)instruction;
		    break;
		case X86_JUMP:
			x86->instruction.jump = (x86_jump_t *)instruction;
		    break;
		case X86_COMPAR:
			x86->instruction.compar = (x86_compar_t *)instruction;
		    break;
		case X86_STACK:
			x86->instruction.stack = (x86_stack_t *)instruction;
		    break;
		case X86_SECTION:
			x86->instruction.section = (x86_section_t *)instruction;
		    break;
		case X86_LABEL:
			x86->instruction.label = (x86_label_t *)instruction;
		    break;
	}

	x86List->instructions[x86List->x86Count++] = x86;
}

void stringifyX86List(x86_list_t *x86List) {
	x86_t *x86;
    for (int i = 0; i < x86List->x86Count; i++) {
		x86 = x86List->instructions[i];
		switch (x86->type) {
		    case X86_SPACE_ALLOCATION:
				printf("%s: ", x86->instruction.spaceAllocation->value);
				switch (x86->instruction.spaceAllocation->type) {
				    case X86_SPACE:
						printf(".space %d", x86->instruction.spaceAllocation->allocation.space);
						break;
					case X86_ASCIZ:
						printf(".asciz %s", x86->instruction.spaceAllocation->allocation.str);
						break;
				}
				break;
		    case X86_DATA_MOVEMENT:
				if (x86->instruction.dataMovement->src == x86->instruction.dataMovement->dest)
				    break;

				switch (x86->instruction.dataMovement->op) {
				    case X86_MOV:
						switch (x86->instruction.dataMovement->src->type) {
						    case X86_CHAR_IMMEDIATE:
								printf("movb");
								break;
						    default:
								printf("movl");
						}
						printf(" ");
						stringifyX86Location(x86->instruction.dataMovement->src);
						printf(", ");
						if (x86->instruction.dataMovement->isDestAddress)
						    printf("(");
						stringifyX86Location(x86->instruction.dataMovement->dest);
						if (x86->instruction.dataMovement->isDestAddress)
						    printf(")");

						break;
				    case X86_LEA:
						printf("leal");
						printf(" ");
						if (x86->instruction.dataMovement->src->type == X86_MEMORY) {
						    printf("%d(%%ebp", x86->instruction.dataMovement->src->value.stackOffset);
							if (x86->instruction.dataMovement->opReg != NULL) {
								printf(", ");
								stringifyX86Location(x86->instruction.dataMovement->opReg);
							}
							printf(")");
						} else {
						    stringifyX86Location(x86->instruction.dataMovement->src);
						}
						printf(", ");
						stringifyX86Location(x86->instruction.dataMovement->dest);
						break;
				    case X86_SETE:
						printf("sete %%al\n");
						break;
				    case X86_SETNE:
						printf("setne %%al\n");
						break;
				    case X86_SETL:
						printf("setl %%al\n");
						break;
				    case X86_SETG:
						printf("setg %%al\n");
						break;
				    case X86_SETGE:
						printf("setge %%al\n");
						break;
				    case X86_SETLE:
						printf("setle %%al\n");
						break;
				}
				break;
		    case X86_ARITHMETIC:
				switch (x86->instruction.arithmetic->op) {
				    case X86_ADD:
						printf("addl");
						break;
					case X86_SUB:
						printf("subl");
						break;
					case X86_MUL:
						printf("imull");
						break;
					case X86_DIV:
						printf("idivl");
						break;
				}
				printf(" ");
				stringifyX86Location(x86->instruction.arithmetic->src);
				if (x86->instruction.arithmetic->dest != NULL) {
				    printf(", ");
					stringifyX86Location(x86->instruction.arithmetic->dest);
				}
				break;
		    case X86_LOGIC:
				switch (x86->instruction.logic->op) {
				    case X86_AND:
						printf("andl");
						break;
					case X86_NOT:
						printf("notl");
						break;
					case X86_OR:
						printf("orl");
						break;
					case X86_XOR:
						printf("xorl");
						break;
				}
				printf(" ");
				stringifyX86Location(x86->instruction.logic->src);
				if (x86->instruction.logic->dest != NULL) {
				    printf(", ");
					stringifyX86Location(x86->instruction.arithmetic->dest);
				}
				break;
		    case X86_CONTROL_FLOW:
				switch (x86->instruction.controlFlow->op) {
				    case X86_CALL:
						printf("call %s", x86->instruction.controlFlow->label);
						break;
				    case X86_RET:
						printf("ret");
						break;
				    case X86_LEAVE:
						printf("leave");
						break;
				}
				break;
		    case X86_JUMP:
				switch (x86->instruction.jump->op) {
				    case X86_JE:
						printf("je");
						break;
				    case X86_JNE:
						printf("jne");
						break;
				    case X86_JG:
						printf("jg");
						break;
				    case X86_JL:
						printf("jl");
						break;
				    case X86_JGE:
						printf("jge");
						break;
				    case X86_JLE:
						printf("jle");
						break;
				    case X86_JMP:
						printf("jmp");
						break;
				}
				printf(" .%s", x86->instruction.jump->label);
				break;
		    case X86_COMPAR:
				printf("cmpl ");
				stringifyX86Location(x86->instruction.compar->src);
				printf(", ");
				stringifyX86Location(x86->instruction.compar->dest);
				break;
		    case X86_STACK:
				switch (x86->instruction.stack->op) {
				    case X86_PUSH:
						printf("pushl");
						break;
				    case X86_POP:
						printf("popl");
						break;
				}
				printf(" ");
				stringifyX86Location(x86->instruction.stack->location);
				break;
		    case X86_SECTION:
				switch (x86->instruction.section->type) {
				    case X86_DATA:
						printf(".data");
						break;
					case X86_BSS:
						printf(".bss");
						break;
					case X86_TEXT:
						printf(".text");
						break;
					case X86_GLOBL:
						printf(".globl %s", x86->instruction.section->label);
						break;
				}
				break;
		    case X86_LABEL:
				if (x86->instruction.label->type == JUMP_LABEL)
				    printf(".");
				printf("%s:", x86->instruction.label->label);
				break;
		}
		printf("\n");
	}
}

x86_location_t *getX86Location(assembly_term_t *term) {
	if (term == NULL)
		return NULL;

	char tempStr[MAX_IDENTIFIER_LENGTH];
	x86_location_t *x86Location = (x86_location_t *)calloc(1, sizeof(x86_location_t));
	symbol_table_item_t *item;

	switch (term->type) {
		case ASSEMBLY_VARIABLE:
			sprintf(tempStr, "%s_%s", term->scope, term->value);
			item = searchSymbol(tempStr, symbolTable);
			x86Location->isPointer = item->data->isPointer;

			if (item == NULL)
				error("Assembly assignment lValue not found");

		    if (streq(term->scope, "global", 6)) {
				if (item->data->type == DATA_STRING)
				    x86Location->type = X86_DATA_FMT;
				else
				    x86Location->type = X86_GLOBAL;

				strcpy(x86Location->value.var, term->value);
			} else {
				x86Location->type = X86_MEMORY;
				x86Location->value.stackOffset = item->data->stackOffset;
			}

		    break;
		case EAX:
		    x86Location = EAX_REGISTER;
		    break;
		case CHAR_IMMEDIATE:
		    x86Location->type = X86_CHAR_IMMEDIATE;

			if (term->value[1] != '\\')
				x86Location->value.charImmediate = term->value[1];
				break;

		    switch (term->value[2]) {
				case '0':
				    x86Location->value.charImmediate = '\0';
					break;
				case 'n':
				    x86Location->value.charImmediate = '\n';
					break;
				case '\\':
				    x86Location->value.charImmediate = '\\';
					break;
		    }

		    break;
		case INT_IMMEDIATE:
		    x86Location->type = X86_INT_IMMEDIATE;
			x86Location->value.intImmediate = atoi(term->value);
		    break;
		default:
		    error("Invalid type term type");
	}

	return x86Location;
}

void stringifyX86Location(x86_location_t *location) {
    switch (location->type) {
		case X86_REGISTER:
			switch (location->value.reg) {
				case 'S':
				    printf("%%esp");
					break;
				case 'B':
				    printf("%%ebp");
					break;
				case 'a':
				    printf("%%eax");
					break;
				case 'b':
				    printf("%%ebx");
					break;
				case 'c':
				    printf("%%ecx");
					break;
				case 'd':
				    printf("%%edx");
					break;
				default:
				    error("Register type not supported");
			}
		    break;
		case X86_MEMORY:
			printf("%d(%%ebp)", location->value.stackOffset);
		    break;
		case X86_GLOBAL:
			printf("%s", location->value.var);
		    break;
		case X86_DATA_FMT:
			printf("$%s", location->value.var);
		    break;
		case X86_INT_IMMEDIATE:
			printf("$%d", location->value.intImmediate);
		    break;
		case X86_CHAR_IMMEDIATE:
			switch (location->value.charImmediate) {
				case '\0':
				    printf("$0");
					break;
				case '\n':
				    printf("$10");
					break;
				case '\\':
				    printf("$92");
					break;
				default:
				    printf("$\'%c\'", location->value.charImmediate);
			}
		    break;
	}
}
