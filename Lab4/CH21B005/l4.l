%{
#include <stdio.h>
#include <stdlib.h>
#include "l4.tab.h"
void yyerror(char *);
extern char mytext[];
%}

%%
"+"	{ return PLUS; }
"-"	{ return MINUS; }

"="	{ return EQ; }

"{"	{ return OPEN_BRACE; }
"}"	{ return CLOSE_BRACE; }

print	{ return PRINT; }

[A-Za-z_][A-Za-z0-9_]{0,30} { strcpy(mytext, yytext); return IDENTIFIER; }
[0-9]*	{ strcpy(mytext, yytext); return NUMBER; }

[ \n\t] {}
. 	{ yyerror("unknown character"); }
%%

int yywrap(void) {
	return 1;
}
