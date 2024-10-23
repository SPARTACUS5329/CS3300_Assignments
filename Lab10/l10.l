%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "l10.h"
#include "l10.tab.h"
void yyerror(char *);

extern char mytext[];
%}

%%
"+"		{ return PLUS; }
"-"		{ return MINUS; }
"<"		{ return LT; }

"="		{ return EQ; }
"("		{ return OPEN_PAREN; }
")"		{ return CLOSE_PAREN; }
"{"		{ return OPEN_BRACE; }
"}"		{ return CLOSE_BRACE; }

"if"	{ return IF; }
"else"	{ return ELSE; }
"while"	{ return WHILE; }
"print"	{ return PRINT; }

[0-9]+	{ strcpy(mytext, yytext); return NUMBER; }
[a-z]{1,32}	{ strcpy(mytext, yytext); return VARIABLE; }

[ \n\t]	{}
. 		{ yyerror("unknown character"); }
%%

int yywrap(void) {
	return 1;
}
