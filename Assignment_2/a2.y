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
%}

%token OPEN_PAREN CLOSE_PAREN OPEN_BRACE CLOSE_BRACE OPEN_SQUARE CLOSE_SQUARE COMMA COMPAR SEMI_COLON
%token EQ PLUS_TOK MINUS_TOK MULTIPLY_TOK DIVIDE_TOK EXPONENT_TOK
%token VALID_TYPE IDENTIFIER NUMBER STRING_TOK
%token IF_TOK ELSE_TOK
%token WHILE_TOK FOR_TOK
%token RETURN_TOK MAIN

%left PLUS_TOK MINUS_TOK COMPAR
%left MULTIPLY_TOK DIVIDE_TOK
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
}

%type <str> identifier
%type <val> subscripts
%type <id> assignable term
%type <exp> expression
%type <arg> argument
%type <param> parameter
%type <argList> arguments
%type <paramList> parameters
%type <funCall> functionCall
%type <funDef> functionDefinition mainFunction
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

%%
program:
	functionDefinitions mainFunction
;

functionDefinitions:
	| functionDefinitions functionDefinition
;

mainFunction:
	validType mainIdentifier OPEN_PAREN parameters CLOSE_PAREN body {
		function_def_t *fun = (function_def_t *)malloc(sizeof(function_def_t));
		strcpy(fun->name, "main");
		fun->paramList = $4;
		fun->lineList = $6;
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
		$$ = lineList;
	}
	| line lines {
		$2->lines[$2->lineCount++] = $1;
		$$ = $2;
	}
;


line:
	declarationStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = DECLARATION;
		line->statement.declaration = $1;
		$$ = line;
	}
    | assignmentStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = ASSIGNMENT;
		line->statement.assignment = $1;
		$$ = line;
	}
    | expression SEMI_COLON {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = EXPRESSION_STATEMENT;
		line->statement.expression = $1;
		$$ = line;
	}
    | returnStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = RETURN;
		line->statement.ret = $1;
		$$ = line;
	}
    | ifStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = IF_ELSE;
		line->statement.ifElse = $1;
		$$ = line;
	}
    | loopStatement {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = LOOP;
		line->statement.loop = $1;
		$$ = line;
	}
    | functionDefinition {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = FUNCTION;
		line->statement.function = $1;
		$$ = line;
	}
;

declarationStatement:
    validType declarations SEMI_COLON {
		declaration_statement_t *dec = (declaration_statement_t *)malloc(sizeof(declaration_statement_t));
		dec->type = $1;
		dec->declarationList = $2;
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
		ass->exp = $3;
		$$ = ass;
	}
;

assignable: identifier {
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

subscripts: subscript {
		$$ = 1;
	}
	| subscript subscripts {
	    $$ = 1 + $2;
    }
;

subscript: OPEN_SQUARE index CLOSE_SQUARE
;

functionCall:
	identifier OPEN_PAREN arguments CLOSE_PAREN {
		arg_list_t *argList = $3;
		function_call_t *fun = (function_call_t *)malloc(sizeof(function_call_t));
		strcpy(fun->name, $1);
		fun->argList = $3;
		$$ = fun;
	}
;

arguments:
	argument {
		$$ = (arg_list_t *)malloc(sizeof(arg_list_t));
		$$->args = (arg_t **)malloc(MAX_ARGS * sizeof(arg_t *));
		$$->args[$$->argCount++] = $1;
	}
	| argument COMMA arguments {
		$3->args[$3->argCount++] = $1;
		$$ = $3;
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
		arg->value.expression = $1;
	}
	| STRING_TOK {
		arg_t *arg = (arg_t *)malloc(sizeof(arg_t));
		arg->type = STRING;
		strcpy(arg->value.str, mytext);
	}
;

expression:
    expression PLUS_TOK expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		sprintf(exp->lValue, "t%d", tCount++);
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = PLUS;
		binOp->left = $1;
		binOp->right = $3;
		exp->child.binOp = binOp;
		$$ = exp;
    }
    | expression MINUS_TOK expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		sprintf(exp->lValue, "t%d", tCount++);
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = MINUS;
		binOp->left = $1;
		binOp->right = $3;
		exp->child.binOp = binOp;
		$$ = exp;
    }
    | expression COMPAR expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		sprintf(exp->lValue, "t%d", tCount++);
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = MINUS;
		binOp->left = $1;
		binOp->right = $3;
		if (streq(mytext, "==", 2))
		    binOp->type = COMPAR_EQ;
		else if (streq(mytext, "!=", 2))
		    binOp->type = COMPAR_NE;
		else if (streq(mytext, "<", 1))
		    binOp->type = COMPAR_LT;
		else if (streq(mytext, ">", 1))
		    binOp->type = COMPAR_GT;
		else if (streq(mytext, "<=", 2))
		    binOp->type = COMPAR_LE;
		else if (streq(mytext, ">=", 2))
		    binOp->type = COMPAR_GE;
		exp->child.binOp = binOp;
		$$ = exp;
    }
    | expression MULTIPLY_TOK expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		sprintf(exp->lValue, "t%d", tCount++);
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = MULTIPLY;
		binOp->left = $1;
		binOp->right = $3;
		exp->child.binOp = binOp;
		$$ = exp;
    }
    | expression DIVIDE_TOK expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		sprintf(exp->lValue, "t%d", tCount++);
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = DIVIDE;
		binOp->left = $1;
		binOp->right = $3;
		exp->child.binOp = binOp;
		$$ = exp;
    }
    | expression EXPONENT_TOK expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		sprintf(exp->lValue, "t%d", tCount++);
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = EXPONENT;
		binOp->left = $1;
		binOp->right = $3;
		exp->child.binOp = binOp;
		$$ = exp;
    }
    | MINUS_TOK expression %prec UMINUS {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = CONSTANT;
		exp->child.binOp->type = EXPONENT;
		sprintf(exp->lValue, "%s", $2->lValue);
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
		$$ = exp;
    }
    | term {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));

		if (!$1->isConstant) {
		    sprintf(mytext, "%s_%s", currScope, $1->name);
			hash_table_item_t *item = searchSymbol(mytext, symbolTable);
			if (item == NULL)
				error("Undefined identifier");
		}

		sprintf(exp->lValue, "%s", $1->name);
		exp->type = CONSTANT;
		$$ = exp;
    }
;

functionDefinition:
    validType identifier OPEN_PAREN parameters CLOSE_PAREN body {
		function_def_t *fun = (function_def_t *)malloc(sizeof(function_def_t));
		strcpy(fun->name, $2);
		fun->paramList = $4;
		fun->lineList = $6;
		$$ = fun;
    }
;

returnStatement:
	RETURN_TOK expression SEMI_COLON {
		return_statement_t *ret = (return_statement_t *)malloc(sizeof(return_statement_t));
		ret->exp = $2;
		$$ = ret;
	}
	| RETURN_TOK SEMI_COLON {
		return_statement_t *ret = (return_statement_t *)malloc(sizeof(return_statement_t));
		$$ = ret;
	}
;

parameters: 
	 parameter {
		param_list_t *paramList = (param_list_t *)malloc(sizeof(param_list_t));
		paramList->params = (param_t **)malloc(MAX_ARGS * sizeof(param_t *));
		paramList->params[paramList->paramCount++] = $1;
		$$ = paramList;
	 }
	 | parameter COMMA parameters {
		$3->params[$3->paramCount++] = $1;
		$$ = $3;
	 }
	 | {
		param_list_t *paramList = (param_list_t *)malloc(sizeof(param_list_t));
		paramList->params = (param_t **)malloc(MAX_ARGS * sizeof(param_t *));
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
    IF_TOK OPEN_PAREN expression CLOSE_PAREN body ELSE_TOK body {
		if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
		ifElse->isMatched = true;
		ifElse->condition = $3;
		ifElse->ifLineList = $5;
		ifElse->elseLineList = $7;
		$$ = ifElse;
	}
	| IF_TOK OPEN_PAREN expression CLOSE_PAREN body {
		if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
		ifElse->isMatched = false;
		ifElse->condition = $3;
		ifElse->ifLineList = $5;
		$$ = ifElse;
	}
;

loopStatement:
    whileStatement {
		loop_statement_t *loop = (loop_statement_t *)malloc(sizeof(loop_statement_t));
		loop->type = WHILE;
		loop->loop.whileLoop = $1;
		$$ = loop;
    }
	| forStatement {
		loop_statement_t *loop = (loop_statement_t *)malloc(sizeof(loop_statement_t));
		loop->type = FOR;
		loop->loop.forLoop = $1;
		$$ = loop;
	}
;

whileStatement:
    WHILE_TOK OPEN_PAREN expression CLOSE_PAREN body {
		while_loop_t *loop = (while_loop_t *)malloc(sizeof(while_loop_t));
		loop->condition = $3;
		loop->lineList = $5;
		$$ = loop;
    }
;

forStatement:
    FOR_TOK OPEN_PAREN assignmentStatement expression SEMI_COLON assignable EQ expression CLOSE_PAREN body {
		for_loop_t *loop = (for_loop_t *)malloc(sizeof(for_loop_t));
		loop->initial = $3;
		loop->condition = $4;
		assignment_statement_t *update = (assignment_statement_t *)malloc(sizeof(assignment_statement_t));
		update->type = $6->type;
		update->exp = $8;
		loop->update = update;
		$$ = loop;
	}
;

body:
	line {
		line_list_t *lineList = (line_list_t *)malloc(sizeof(line_list_t));
		lineList->lines = (line_t **)malloc(MAX_LINES * sizeof(line_t *));
		lineList->lines[lineList->lineCount++] = $1;
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
    yyparse();
    return 0;
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
