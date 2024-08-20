%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50
void yyerror(char *);
int yylex(void);
char mytext[100];
char var[100];
int num = 0;
%}

%token OPEN_PAREN CLOSE_PAREN OPEN_BRACE CLOSE_BRACE COMMA COMPAR SEMI_COLON
%token EQ PLUS MINUS MULTIPLY DIVIDE EXPONENT
%token VALID_TYPE
%token IDENTIFIER NUMBER STRING
%token IF ELSE
%token WHILE
%token RETURN

%left PLUS MINUS
%left MULTIPLY DIVIDE
%right UMINUS EXPONENT
%left OPEN_PAREN CLOSE_PAREN

%union {
    char *str;
    int val;
}

%type <str> identifier

%%

program: blocks
;

blocks: block
	 | block blocks
	 | lines
;

block: functionBlock
     | ifBlock
     | loopBlock
;

lines: line
     | line lines
;

line: declaration
    | assignment
    | functionCall
;

declaration: VALID_TYPE identifier SEMI_COLON
	   | VALID_TYPE identifier EQ expression SEMI_COLON;
;

assignment: identifier EQ expression SEMI_COLON
;

functionCall: identifier OPEN_PAREN arguments CLOSE_PAREN SEMI_COLON
;

arguments:| argument
	 | argument COMMA arguments
;

argument: term | STRING
;

expression:
    expression PLUS expression
    | expression MINUS expression
    | expression MULTIPLY expression
    | expression DIVIDE expression
    | expression EXPONENT expression
    | MINUS expression %prec UMINUS
    | OPEN_PAREN expression CLOSE_PAREN
    | term
;

functionBlock: VALID_TYPE identifier OPEN_PAREN parameters CLOSE_PAREN
	     OPEN_BRACE
		blocks
		returnStatement
	     CLOSE_BRACE
;

returnStatement: | RETURN term SEMI_COLON
;

parameters:| parameter
	 | parameter COMMA parameters
;

parameter: VALID_TYPE identifier
;

ifBlock: ifStatement elseStatement
;

ifStatement: IF OPEN_PAREN term COMPAR term CLOSE_PAREN
       OPEN_BRACE
	blocks
       CLOSE_BRACE
;

elseStatement: | ELSE OPEN_BRACE
		    blocks
		CLOSE_BRACE
;

loopBlock: whileStatement
;

whileStatement: WHILE OPEN_PAREN term COMPAR term CLOSE_PAREN
	      OPEN_BRACE
		blocks
	      CLOSE_BRACE
;

term: identifier
    | NUMBER
;

identifier: IDENTIFIER {
		$$ = strdup(mytext);
	  }
;
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

int main(void) {
    yyparse();
    return 0;
}
