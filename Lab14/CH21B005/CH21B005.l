%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CH21B005.h"
#include "CH21B005.tab.h"
void yyerror(char *);

extern char mytext[];
%}

%%
[a-z][0-9][0-9] { strcpy(mytext, yytext); return IDENTIFIER; }
[0-9][0-9]* { strcpy(mytext, yytext); return NUMBER; }

[ \n\t]	{}
. 		{ yyerror("unknown character"); }
%%

int yywrap(void) {
	return 1;
}
