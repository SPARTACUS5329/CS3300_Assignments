%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "l9.h"
#include "l9.tab.h"

void yyerror(char *);
extern char mytext[];
%}

%%
"+"	{ return PLUS; }
"-"	{ return MINUS; }
"^"	{ return EXPONENT; }

"="	{ return EQ; }
":"	{ return COLON; }
","	{ return COMMA; }

"-"?[0-9]+	{ strcpy(mytext, yytext); return NUMBER; }
[x|y|z]	{ strcpy(mytext, yytext); return VARIABLE; }
[p][0-9]+	{ strcpy(mytext, yytext); return IDENTIFIER; }

[\n] 	{}
[ \t] 	{}
. 	{ yyerror("unknown character"); }
%%

int yywrap(void) {
	return 1;
}
