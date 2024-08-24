%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50
void yyerror(char *);
int yylex(void);
char mytext[100];
int lineNumber = 0;
%}

%token OPEN_PAREN CLOSE_PAREN OPEN_BRACE CLOSE_BRACE OPEN_SQUARE CLOSE_SQUARE COMMA COMPAR SEMI_COLON
%token EQ PLUS MINUS MULTIPLY DIVIDE EXPONENT
%token VALID_TYPE
%token IDENTIFIER NUMBER STRING
%token IF ELSE
%token WHILE
%token RETURN

%left PLUS MINUS COMPAR
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
    | expression SEMI_COLON
;

declaration: VALID_TYPE assignable SEMI_COLON
	   | VALID_TYPE assignable EQ expression SEMI_COLON;
;

assignment: assignable EQ expression SEMI_COLON
;

assignable: identifier
	  | identifier OPEN_SQUARE index CLOSE_SQUARE 
;

functionCall: identifier OPEN_PAREN arguments CLOSE_PAREN
;

arguments:| argument
	 | argument COMMA arguments
;

argument: term | STRING
;

expression:
    expression PLUS expression
    | expression MINUS expression
    | expression COMPAR expression
    | expression MULTIPLY expression
    | expression DIVIDE expression
    | expression EXPONENT expression
    | MINUS expression %prec UMINUS
    | OPEN_PAREN expression CLOSE_PAREN
    | functionCall
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

ifStatement: IF OPEN_PAREN expression CLOSE_PAREN
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

whileStatement: WHILE OPEN_PAREN expression CLOSE_PAREN
	      OPEN_BRACE
		blocks
	      CLOSE_BRACE
;

term: identifier
    | identifier OPEN_SQUARE index CLOSE_SQUARE
    | NUMBER
;

index: identifier
     | NUMBER
;

identifier: IDENTIFIER {
		$$ = strdup(mytext);
	  }
;
%%

void yyerror(char *message) {
    fprintf(stderr, "%d\n", lineNumber);
    exit(1);
}

int main(void) {
    yyparse();
    return 0;
}
