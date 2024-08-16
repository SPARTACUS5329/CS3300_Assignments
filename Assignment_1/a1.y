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
%token EQ PLUS MINUS MULTIPLY DIVIDE
%token VALID_TYPE
%token IDENTIFIER NUMBER
%token IF ELSE

%left PLUS MINUS
%left MULTIPLY DIVIDE
%right UMINUS

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
;

lines: line
     | line lines
;

line: declaration
    | assignment
;

declaration: VALID_TYPE identifier SEMI_COLON
	   | VALID_TYPE identifier EQ expression SEMI_COLON;
;

assignment: identifier EQ expression SEMI_COLON
;

expression:
    expression PLUS expression
    | expression MINUS expression
    | expression MULTIPLY expression
    | expression DIVIDE expression
    | MINUS expression %prec UMINUS
    | term
;

functionBlock: VALID_TYPE identifier OPEN_PAREN arguments CLOSE_PAREN
	     OPEN_BRACE
		blocks
	     CLOSE_BRACE
;

arguments:| argument
	 | argument COMMA arguments
;

argument: VALID_TYPE identifier
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
