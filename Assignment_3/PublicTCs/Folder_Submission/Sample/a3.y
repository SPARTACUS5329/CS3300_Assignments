%{
	#include<iostream>
	void yyerror(char *);
	int yylex(void);
    using namespace std;
%}

%token PRINTF SEMI COMMA LBRACK RBRACK LPAREN RPAREN LBRACE RBRACE AND 
%token OR NOT NE LE GE PLUS MINUS TIMES DIV EQEQ EQ LT GT
%token HEADER IF ELSE WHILE RETURN INT MAIN CHAR
%token ID INTLIT QUOTED_STRING CONST_CHAR

%union
{
    char* str;
    int val;
}

%type<str> INTLIT QUOTED_STRING ID 
%type<val> Intlit

%%

Goal: Program 
    {
        string s = ".data \n"
"fmt:	.asciz \"c = %d\\n\" \n"
"    \n"
"	.text\n"
"	.globl main\n"
"main:\n"
"	pushl %ebp                 # Prologue\n"
"	movl %esp, %ebp                \n"
"	subl $12, %esp             # Space for local variables (3)\n"
"\n"
"	movl $10, -12(%ebp)        # Assign a = 10 \n"
"	movl $20, -8(%ebp)         # Assign b = 20 \n"
"\n"
"	movl -12(%ebp), %eax       # Load a \n"
"	addl -8(%ebp), %eax        # b with a \n"
"\n"
"	movl %eax, -4(%ebp)        # Store the sum to c \n"
"\n"
"	pushl -4(%ebp)             # Push c as second arg \n"
"	pushl $fmt                 # Push address of fmt as arg \n"
"	call printf                # Function call \n"
"\n"
"	movl $0, %eax              # Return value 0 \n"
"	leave                      # Epilogue \n"
"	ret\n";
    cout << s<< '\n';
    }
;

Program: HEADER Main {}
    | HEADER manyVariableDeclaration Main {}
    | HEADER manyFunctionDefinition Main {}
    | HEADER manyVariableDeclaration manyFunctionDefinition Main {}
;

manyVariableDeclaration:  manyVariableDeclaration VariableDeclaration{}
                        | VariableDeclaration   {}
;

manyFunctionDefinition:  manyFunctionDefinition FunctionDefinition {}
                        | FunctionDefinition  {}
;

manyStatement:  manyStatement Statement {}
                        | Statement  {}
;

Statement_star: Statement_star Statement {}
              | /* ε */ {}
;

VariableDeclaration: IntDeclaration {}
                   | CharArrayDeclaration {}
;

IntDeclaration: INT ID SEMI {}
;

CharArrayDeclaration: CHAR ID LBRACK Intlit RBRACK SEMI {}
;

FunctionDefinition: INT ID LPAREN FormalParameterList RPAREN FunctionBody {}
                  | INT ID LPAREN RPAREN FunctionBody {}
;

FormalParameterList: FormalParameter FormalParameterRest_star {}
;

FormalParameterRest_star: FormalParameterRest_star FormalParameterRest {}
                        | /* ε */ {}
;

FormalParameterRest: COMMA FormalParameter {}
;

FormalParameter: IntParameter {}
               | CharArrayParameter {}
;

IntParameter: INT ID {}
;


CharArrayParameter: CHAR ID LBRACK RBRACK {}
;         

FunctionBody: LBRACE manyVariableDeclaration RETURN Expression SEMI RBRACE {}
        | LBRACE manyStatement RETURN Expression SEMI RBRACE {}
        | LBRACE manyVariableDeclaration manyStatement RETURN Expression SEMI RBRACE {}
        | LBRACE RETURN Expression SEMI RBRACE {}
;

Statement: AssignmentStatement {}
         | CharArrayIndexAssignmentStatement {}
         | IfStatement {}
         | WhileStatement {}
         | FunctionCallStatement {}
         | PrintStatement {}
;

WhileStatement: WHILE LPAREN BooleanExpression RPAREN LBRACE Statement_star RBRACE {}
;

FunctionCallStatement: ID LPAREN ArgumentList RPAREN SEMI {}
                     | ID LPAREN RPAREN SEMI {}
;

PrintStatement: PRINTF LPAREN QUOTED_STRING PrintfArgument_star RPAREN SEMI {}
;

PrintfArgument_star:  PrintfArgument_star PrintfArgument {}
                   | /* ε */ {}
;

PrintfArgument: COMMA Argument {}
;

AssignmentStatement: ID EQ Expression SEMI {}
;

CharArrayIndexAssignmentStatement: ID LBRACK Expression RBRACK EQ CONST_CHAR SEMI {}
                                 | ID LBRACK Expression RBRACK EQ ID LBRACK Expression RBRACK SEMI {}
;

IfStatement: IfthenElseStatement {}
           | IfthenStatement{}
;

IfthenElseStatement: IF LPAREN BooleanExpression RPAREN LBRACE Statement_star RBRACE ELSE LBRACE Statement_star RBRACE {}
;

IfthenStatement: IF LPAREN BooleanExpression RPAREN LBRACE Statement_star RBRACE {}
;

BooleanExpression : BooleanOrExpressionList {}
;

BooleanOrExpressionList : BooleanAndExpressionList {}
                        | BooleanAndExpressionList OR BooleanOrExpressionList {}
;

BooleanAndExpressionList : BooleanPrimaryExpression {}
                        |  BooleanPrimaryExpression AND BooleanAndExpressionList {}
;

BooleanPrimaryExpression : Expression RelationalOperator Expression {}
                         | LPAREN BooleanExpression RPAREN {}
                         | NOT LPAREN BooleanExpression RPAREN {}
;

RelationalOperator  :   LE   {}
                    |   EQEQ {}
                    |   GE   {}
                    |   NE   {}
                    |   GT   {}
                    |   LT   {}
;


Main: INT MAIN LPAREN RPAREN MainBody {}
;

MainBody: LBRACE manyVariableDeclaration mainReturnExpression RBRACE {}
        | LBRACE manyStatement mainReturnExpression RBRACE {}
        | LBRACE manyVariableDeclaration manyStatement mainReturnExpression RBRACE {}
        | LBRACE mainReturnExpression RBRACE {}
;

Expression: ReturnOfFunctionCall {}
          | BinaryOperation {}
          | PrimaryExpression {}
;

ReturnOfFunctionCall: ID LPAREN ArgumentList RPAREN {}
                    | ID LPAREN RPAREN {}
;

BinaryOperation: PrimaryExpression BinaryOperator PrimaryExpression {}
;

BinaryOperator: PLUS  {}
              | MINUS {}
              | TIMES {}
              | DIV   {}  
;

PrimaryExpression: LPAREN Expression RPAREN {}
                 | ID {}
                 | Intlit {}
;

ArgumentList: Argument ArgumentRest_star {}
;

ArgumentRest_star: ArgumentRest_star ArgumentRest {}
                 | /* ε */ {}
;

ArgumentRest: COMMA Argument {}
;

Argument: Expression {}
;

mainReturnExpression: RETURN Intlit SEMI {if($2 != 0){yyerror("syntax error"); exit(0);}}
;

Intlit: INTLIT {$$ = stoi($1);}
    |  PLUS INTLIT{$$ = stoi($2);}
    |  MINUS INTLIT{$$ = -1*stoi($2);}
;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
