%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "a2.h"

void yyerror(char *);
int yylex(void);
char mytext[100];
char currType[10];
char currScope[MAX_IDENTIFIER_LENGTH] = "global";
expression_t args[MAX_FUNCTION_CALLS][MAX_ARGS];
int lineNumber = 1;
static int tCount = 1;
static int lCount = 1;

hash_table_item_t *symbolTable[MAX_IDENTIFIERS];
program_t *program;
%}

%token OPEN_PAREN CLOSE_PAREN OPEN_BRACE CLOSE_BRACE OPEN_SQUARE CLOSE_SQUARE COMMA COMPAR SEMI_COLON
%token EQ PLUS_TOK MINUS_TOK MULTIPLY_TOK DIVIDE_TOK EXPONENT_TOK
%token VALID_TYPE IDENTIFIER NUMBER STRING_TOK
%token SHORT_AND_TOK SHORT_OR_TOK NOT_TOK
%token IF_TOK ELSE_TOK
%token WHILE_TOK FOR_TOK
%token RETURN_TOK MAIN

%left PLUS_TOK MINUS_TOK COMPAR
%left MULTIPLY_TOK DIVIDE_TOK
%left SHORT_AND_TOK SHORT_OR_TOK
%right NOT_TOK
%right UMINUS EXPONENT_TOK
%left OPEN_PAREN CLOSE_PAREN
%left ELSE_TOK


%union {
    char *str;
    int val;
    identifier_t *id;
	expression_t *exp; 
	line_t *line;
	line_list_t *lineList;
	declaration_statement_t *declarationStatement;
	assignment_statement_t *assignmentStatement;
	if_else_statement_t *ifElseStatement;
	return_statement_t *returnStatement;
	loop_statement_t *loopStatement;
	function_def_t *funDef;
	function_def_list_t *funDefList;
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
%type <val> subscripts
%type <id> assignable term
%type <exp> expression
%type <arg> argument
%type <param> parameter
%type <argList> arguments
%type <paramList> parameters
%type <funCall> functionCall
%type <funDef> functionDefinition mainFunction
%type <funDefList> functionDefinitions
%type <line> line
%type <lineList> lines body
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
	functionDefinitions mainFunction {
		program->funDefList = $1;
		program->main = $2;
	}
;

functionDefinitions:
	functionDefinitions functionDefinition {
		$1->functions[$1->functionCount++] = $2;
		$$ = $1;
	}
	| {
		function_def_list_t *funDefList = (function_def_list_t *)malloc(sizeof(function_def_list_t));
		funDefList->functions = (function_def_t **)malloc(MAX_LINES * sizeof(function_def_t *));
		funDefList->stringify = &stringifyFunctionDefList;
		$$ = funDefList;
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
    assignable EQ expression SEMI_COLON {
		hash_table_item_t *item = searchSymbol($1->name, symbolTable);
		if (item == NULL) error("Undefined identifier");
		if (item->data->depth != $1->depth)
		    yyerror("Invalid location");

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
	| identifier subscripts {
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
	    id->depth = $2;
		insertSymbol(id->name, id, symbolTable);
		$$ = id;
	}
;

subscripts:
	subscript {
		$$ = 1;
	}
	| subscript subscripts {
	    $$ = 1 + $2;
    }
;

subscript:
	OPEN_SQUARE index CLOSE_SQUARE
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
    | MINUS_TOK expression %prec UMINUS {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = CONSTANT;
		exp->child.binOp->type = EXPONENT;
		sprintf(exp->lValue, "%s", $2->lValue);
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
			hash_table_item_t *item = searchSymbol(temp, symbolTable);
			if (item == NULL)
				error("Undefined identifier");
		}

		sprintf(exp->lValue, "%s", $1->name);
		exp->type = CONSTANT;
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

returnStatement:
	RETURN_TOK expression SEMI_COLON {
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
		con->exp = $1->exp;
		con->chain = $3;
		$$ = con;
	}
	| condition SHORT_OR_TOK condition {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = SHORT_OR;
		con->exp = $1->exp;
		con->chain = $3;
		$$ = con;
	}
	| NOT_TOK condition {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = NOT;
		con->exp = $2->exp;
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
		else if (streq($2, "<", 1))
		    binOp->type = COMPAR_LT;
		else if (streq($2, ">", 1))
		    binOp->type = COMPAR_GT;
		else if (streq($2, "<=", 2))
		    binOp->type = COMPAR_LE;
		else if (streq($2, ">=", 2))
		    binOp->type = COMPAR_GE;
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
		id->depth = $2;
		$$ = id;
    }
    | NUMBER {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, mytext);
		id->depth = 0;
		id->isConstant = true;
		$$ = id;
    }
;

index:
    identifier
    | NUMBER
;

compar:
    COMPAR {
		$$ = strdup(mytext);
	}
;

validType:
    VALID_TYPE {
		if (streq(mytext, "int", 3))
		    $$ = INT;
		else if (streq(mytext, "float", 5))
		    $$ = FLOAT;
		else if (streq(mytext, "char", 4))
		    $$ = CHAR;
		strcpy(currType, mytext);
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

int main(void) {
    program = (program_t *)malloc(sizeof(program_t));
	yyparse();
	stringifyProgram(program);
    return 0;
}

void stringifyProgram(program_t *program) {
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
    printf("%s:\n", fun->name);
	fun->paramList->stringify(fun->paramList);
	fun->lineList->stringify(fun->lineList);
}

void stringifyParamList(param_list_t *paramList) {
	param_t **params = paramList->params;
	int paramCount = paramList->paramCount;
	for (int i = 0; i < paramCount; i++)
		printf("%s = param%d\n", params[i]->name, i + 1);
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
    for (int i = 0; i < decCount; i++) {
		declaration_t *dec = decs[i];
		if (dec->exp == NULL)
			continue;
		dec->exp->stringify(dec->exp);
		printf("%s = t%d\n", dec->lValue->displayName, tCount - 1);
	}
}

void stringifyAssignmentStatement(assignment_statement_t *ass) {
	ass->exp->stringify(ass->exp);
	printf("%s = t%d\n", ass->lValue->displayName, tCount - 1);
}

void stringifyExpression(expression_t *exp) {
    switch (exp->type) {
		case CONSTANT:
			printf("t%d = %s\n", tCount++, exp->lValue);
			break;
		case BIN_OP:
			exp->child.binOp->stringify(exp, exp->child.binOp);
			break;
		case FUNCTION_CALL:
			exp->child.functionCall->stringify(exp->child.functionCall);
			break;
		default:
			error("Invalid expression");
	}
}

void stringifyReturnStatement(return_statement_t *ret) {
    if (ret->exp != NULL) {
		switch (ret->exp->type) {
			case CONSTANT:
				printf("retval = %s\n", ret->exp->lValue);
				break;
			default:
				ret->exp->stringify(ret->exp);
				printf("retval = t%d\n", tCount++);
		}
	}
	printf("return\n");
}

void stringifyIfElseStatement(if_else_statement_t *ifElse) {
	condition_t *baseCon = ifElse->condition;
	baseCon->exp->stringify(baseCon->exp);
	bool rootIfElse = ifElse->trueLabel == 0 && ifElse->falseLabel == 0;
	if (ifElse->trueLabel == 0)
		ifElse->trueLabel = lCount++;
	if (ifElse->falseLabel == 0)
		ifElse->falseLabel = lCount++;

    if_else_statement_t *chainIfElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
	switch (baseCon->op) {
		case NOT:
		    printf("t%d = not %s\n", tCount, baseCon->exp->lValue);
			printf("if (t%d) goto L%d\n", tCount++, ifElse->trueLabel);
			printf("goto L%d\n", ifElse->falseLabel);
			printf("L%d:\n", ifElse->trueLabel);
			ifElse->ifLineList->stringify(ifElse->ifLineList);
			break;
		case SHORT_AND:
		    printf("if (%s) goto L%d\n", baseCon->exp->lValue, ifElse->trueLabel);
			printf("goto L%d\n", ifElse->falseLabel);
			printf("L%d:\n", ifElse->trueLabel);
			chainIfElse->condition = baseCon->chain;
			chainIfElse->falseLabel = ifElse->falseLabel;
			chainIfElse->ifLineList = ifElse->ifLineList;
			chainIfElse->stringify = &stringifyIfElseStatement;
			chainIfElse->stringify(chainIfElse);
			break;
		case SHORT_OR:
		    printf("if (%s) goto L%d\n", baseCon->exp->lValue, ifElse->trueLabel);
			chainIfElse->condition = baseCon->chain;
			chainIfElse->trueLabel = ifElse->trueLabel;
			chainIfElse->falseLabel = ifElse->falseLabel;
			chainIfElse->ifLineList = ifElse->ifLineList;
			chainIfElse->stringify = &stringifyIfElseStatement;
			chainIfElse->stringify(chainIfElse);
			break;
		case SINGLE:
		    printf("if (%s) goto L%d\n", baseCon->exp->lValue, ifElse->trueLabel);
			printf("goto L%d\n", ifElse->falseLabel);
			printf("L%d:\n", ifElse->trueLabel);
			ifElse->ifLineList->stringify(ifElse->ifLineList);
			break;
		default:
		    error("Invalid condition chaining");
	}
	int exitLabel = ifElse->isMatched ? lCount++ : ifElse->falseLabel;
	if (rootIfElse && ifElse->isMatched)
		printf("goto L%d\n", exitLabel);
	if (ifElse->isMatched) {
		printf("L%d:\n", ifElse->falseLabel);
		ifElse->elseLineList->stringify(ifElse->elseLineList);
	}
	if (rootIfElse)
		printf("L%d:\n", exitLabel);
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
	printf("L%d:\n", loop->startLabel);
	if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
	ifElse->condition = loop->condition;
	ifElse->ifLineList = loop->lineList;
	ifElse->trueLabel = loop->trueLabel;
	ifElse->falseLabel = loop->falseLabel;
	ifElse->stringify = &stringifyIfElseStatement;
	ifElse->stringify(ifElse);
	printf("goto L%d\n", loop->startLabel);
	printf("L%d:\n", loop->falseLabel);
}

void stringifyForLoop(for_loop_t *loop) {
    loop->startLabel = lCount++;
    loop->trueLabel = lCount++;
    loop->falseLabel = lCount++;
	loop->initial->stringify(loop->initial);
	printf("L%d:\n", loop->startLabel);
	if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
	ifElse->condition = loop->condition;
	ifElse->ifLineList = loop->lineList;
	ifElse->trueLabel = loop->trueLabel;
	ifElse->falseLabel = loop->falseLabel;
	ifElse->stringify = &stringifyIfElseStatement;
	ifElse->stringify(ifElse);
	loop->update->stringify(loop->update);
	printf("goto L%d\n", loop->startLabel);
	printf("L%d:\n", loop->falseLabel);
}

void stringifyBinOp(expression_t *exp, bin_op_t *binOp) {
	sprintf(exp->lValue, "t%d", tCount);
	expression_t *left = binOp->left;
	expression_t *right = binOp->right;
	if (left->type != CONSTANT)
		left->stringify(left);
	if (right->type != CONSTANT)
		right->stringify(right);

	switch (binOp->type) {
		case PLUS:
			printf("t%d = %s + %s\n", tCount++, left->lValue, right->lValue);
			break;
		case MINUS:
			printf("t%d = %s - %s\n", tCount++, left->lValue, right->lValue);
			break;
		case COMPAR_EQ:
			printf("t%d = %s == %s\n", tCount++, left->lValue, right->lValue);
			break;
		case COMPAR_NE:
			printf("t%d = %s != %s\n", tCount++, left->lValue, right->lValue);
			break;
		case COMPAR_LT:
			printf("t%d = %s < %s\n", tCount++, left->lValue, right->lValue);
			break;
		case COMPAR_GT:
			printf("t%d = %s > %s\n", tCount++, left->lValue, right->lValue);
			break;
		case COMPAR_LE:
			printf("t%d = %s <= %s\n", tCount++, left->lValue, right->lValue);
			break;
		case COMPAR_GE:
			printf("t%d = %s >= %s\n", tCount++, left->lValue, right->lValue);
			break;
		case MULTIPLY:
			printf("t%d = %s * %s\n", tCount++, left->lValue, right->lValue);
			break;
		case DIVIDE:
			printf("t%d = %s / %s\n", tCount++, left->lValue, right->lValue);
			break;
		case EXPONENT:
			printf("t%d = %s ** %s\n", tCount++, left->lValue, right->lValue);
			break;
		default:
			error("Invalid binary operation");
	}
}

void stringifyFunctionCall(function_call_t *fun) {
	arg_t **args = fun->argList->args;
	int argCount = fun->argList->argCount;
	char **passedParams = (char **)malloc(MAX_ARGS * sizeof(char *));
	int passedParamCount = 0;
	for (int i = 0; i < argCount; i++) {
		arg_t *arg = args[i];
		passedParams[passedParamCount] = malloc(MAX_IDENTIFIER_LENGTH * sizeof(char));
		switch (arg->type) {
			case STRING:
				printf("t%d = \"%s\"", tCount, arg->value.str);
				sprintf(passedParams[passedParamCount++], "t%d", tCount++);
				break;
			case EXPRESSION:
				if (arg->value.exp->type != CONSTANT)
					arg->value.exp->stringify(arg->value.exp);
				printf("t%d = %s\n", tCount, arg->value.exp->lValue);
				sprintf(passedParams[passedParamCount++], "t%d", tCount++);
				break;
			default:
				error("Invalid argument");
		}
	}
	for (int i = 0; i < passedParamCount; i++)
		printf("param%d = %s\n", i + 1, passedParams[i]);
	printf("call %s\n", fun->name);
}

unsigned long hash(char *str) {
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return hash % MAX_IDENTIFIERS;
}

hash_table_item_t *searchSymbol(char *key, hash_table_item_t* hashTable[]) {

	int hashIndex = hash(key);

	while(hashTable[hashIndex] != NULL) {
	  if(hashTable[hashIndex]->key == hashIndex)
		 return hashTable[hashIndex]; 
			
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}        

	return NULL;        
}

void insertSymbol(char *key, identifier_t *data, hash_table_item_t* hashTable[]) {
	hash_table_item_t *item;
	item = searchSymbol(key, hashTable);
	if (item != NULL) {
		item->data = data;
		return;
	}
	int hashIndex = hash(key);
	item = (hash_table_item_t*) malloc(sizeof(hash_table_item_t));
	item->data = data;
	item->key = hashIndex;

	while(hashTable[hashIndex] != NULL) {
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}

	hashTable[hashIndex] = item;
}
