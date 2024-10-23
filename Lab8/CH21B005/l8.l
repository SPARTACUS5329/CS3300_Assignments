%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "l8.h"
#include "l8.tab.h"
void yyerror(char *);

extern char mytext;
%}

%%
"&"			{ return AND; }
"|"			{ return OR; }
"~"			{ return NOT; }
"("			{ return OPEN_PAREN; }
")"			{ return CLOSE_PAREN; }

[a-z]		{ mytext = *yytext; return VARIABLE; }

[ \n\t]		{}
.			{ yyerror("unknown character"); }
%%

int yywrap(void) {
	return 1;
}
