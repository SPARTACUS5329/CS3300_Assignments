%{
	#include <iostream>
	#include <string.h>
	#include <stdlib.h>
    #include <bits/stdc++.h>
    using namespace std;
	void yyerror(char *);
	int yylex(void);
    extern char *yytext;
    string lvalue;
    int dimension;
    unordered_map<string, int> dimensionality;
    int line_number = 1;
%}

%union {
    int int_val;
    float float_val;
    char char_val;
    char *str_val;
}

%token <int_val> INT_CONST
%token <float_val> FLOAT_CONST
%token <char_val> CHAR_CONST
%token <str_val> IDENTIFIER STRING_LITERAL

%token IF ELSE WHILE FOR RETURN PRINTF
%token INT CHAR FLOAT VOID
%token EQ_OP NE_OP LE_OP GE_OP
%token EXP_OP INC_OP DEC_OP
%token OR AND

%right  '<' '>' EQ_OP NE_OP LE_OP GE_OP
%left   '+' '-'
%left   '*' '/'
%left   EXP_OP INC_OP DEC_OP

%start program

%%

program: lines

lines:
    oneline
    | lines oneline 

oneline:
    variable_declaration ';'
    | function_declaration

type_specifier: VOID
    | INT
    | CHAR
    | FLOAT

function_declaration:
    type_specifier IDENTIFIER '(' parameter_list ')' '{' statements '}' 

variable_declaration:
    type_specifier declaration_list

declaration_list:
    declaration_list ',' variable {dimensionality[lvalue]=dimension;}
    | declaration_list ',' assignment_statement
    | variable {dimensionality[lvalue]=dimension;}
    | assignment_statement

variable: 
    IDENTIFIER {lvalue = (string)$1; dimension=0; }
    | IDENTIFIER '[' expression ']' { lvalue = (string)$1; dimension=1;}
    | IDENTIFIER '[' expression ']' '[' expression ']' {lvalue = (string)$1; dimension=2;}

parameter_list:
    | parameter_list ',' function_parameter
    | function_parameter

function_parameter:
    type_specifier IDENTIFIER
    | type_specifier IDENTIFIER '[' function_array_1D ']'
    | type_specifier IDENTIFIER '[' function_array_1D ']' '[' expression ']'

function_array_1D: 
    | expression

statements: 
    | statements statement
 
statement:
    assignment_statement ';'    
    | condition_statement       
    | iteration_statement       
    | return_statement ';'      
    | printf_statement ';'
    | variable_declaration ';'  
    | function_call ';'         
    | unary_expression ';'      

assignment_statement:
    variable '=' expression

condition_statement:
    IF '(' condition_list ')' body ELSE body
    | IF '(' condition_list ')' body

condition_list:
    condition_list OR condition
    | condition_list AND condition
    | condition

condition: 
    condition_expression EQ_OP condition_expression
    | condition_expression NE_OP condition_expression
    | condition_expression LE_OP condition_expression
    | condition_expression GE_OP condition_expression
    | condition_expression '<' condition_expression
    | condition_expression '>' condition_expression

condition_expression:
    constant
    | variable {
        if(dimensionality[lvalue] - dimension > 0)
        {
            yyerror("syntax error");
        }
    }
    | condition_expression '+' condition_expression
    | condition_expression '-' condition_expression
    | condition_expression '*' condition_expression
    | condition_expression '/' condition_expression
    | condition_expression EXP_OP condition_expression

body:
    '{' statements '}'
    | statement

iteration_statement:
    WHILE '(' expression ')' body
    | FOR '(' for_assign ';' for_condition ';' for_change ')' body

for_assign:
    | assignment_statement
    | type_specifier assignment_statement

for_condition:
    | condition

for_change:
    | unary_expression
    | assignment_statement

return_statement:
    RETURN expression
    | RETURN

printf_statement:
    PRINTF '(' STRING_LITERAL print_parameters ')'

print_parameters:
    | ',' rvalue print_parameters
 
expression:
    rvalue
    | function_call
    | '(' expression ')'
    | arithmetic_expression
    | comparison_expression

arithmetic_expression:
    unary_expression
    | expression '+' expression
    | expression '-' expression
    | expression '*' expression 
    | expression '/' expression 
    | expression EXP_OP expression

comparison_expression:
    expression EQ_OP expression
    | expression NE_OP expression
    | expression LE_OP expression
    | expression GE_OP expression
    | expression '<' expression
    | expression '>' expression

function_call:
    IDENTIFIER '(' function_call_params ')'

function_call_params:
    | function_call_params ',' expression
    | expression

unary_expression: 
    IDENTIFIER INC_OP
    | IDENTIFIER DEC_OP 
    | INC_OP IDENTIFIER 
    | DEC_OP IDENTIFIER

constant: 
    INT_CONST 
    | '-' INT_CONST 
    | FLOAT_CONST 
    | '-' FLOAT_CONST 
    | CHAR_CONST 

rvalue: 
    variable 
    | constant

%%

void yyerror(char *s) {
    fprintf(stderr, "%d\n", line_number);
    exit(1);
}

int main() {
    yyparse();
    return 0;
}