%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "l6.h"
#include "l6.tab.h"
void yyerror(char *);

extern char mytext[];
%}

%%
"+"	{ return PLUS; }
"-"	{ return MINUS; }
"*"	{ return MULTIPLY; }
"/"	{ return DIVIDE; }

"->"	{ return ASSIGN; }
";"	{ return SEMI_COLON; }
"|"	{ return UNION; }

"eps"	{ return EPS; }

[a-z]	{ strcpy(mytext, yytext); return TERMINAL; }
[A-Z]	{ strcpy(mytext, yytext); return NON_TERMINAL; }

[ \n\t] {}
. 	{ yyerror("unknown character"); }
%%

int yywrap(void) {
	return 1;
}
