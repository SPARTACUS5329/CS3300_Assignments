%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "l13.h"
#include "l13.tab.h"
void yyerror(char *);

extern char mytext[];
%}

%%
"*"		{ return STAR_TOK; }
"&"		{ return AND_TOK; }
"="		{ return EQ; }
";"		{ return SEMI_COLON; }
","		{ return COMMA; }

"%%"		{ return SEPARATOR; }

"PRINTSET"	{ return PRINTSET_TOK; }
"POINTSTO"	{ return POINTSTO_TOK; }
"DEREFERENCEABLE"	{ return DEREFERENCEABLE_TOK; }

[a-zA-Z_][a-zA-Z0-9_]* { strcpy(mytext, yytext); return IDENTIFIER; }

[ \n\t]	{}
. 		{ yyerror("unknown character"); }
%%

int yywrap(void) {
	return 1;
}
