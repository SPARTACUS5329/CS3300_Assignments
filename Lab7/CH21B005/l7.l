%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "l7.h"
#include "l7.tab.h"
void yyerror(char *);

extern char mytext[];
%}

%%
"+"			{ return PLUS; }
"-"			{ return MINUS; }
"*"			{ return MULTIPLY; }
"/"			{ return DIVIDE; }
"("			{ return OPEN_PAREN; }
")"			{ return CLOSE_PAREN; }
"$"			{ return DOLLAR; }

"->"		{ return ASSIGN; }
";"			{ return SEMI_COLON; }
"|"			{ return UNION; }

"eps"		{ return EPS; }

"GRAMMAR"		{ return GRAMMAR; }
"QUERY"		{ return QUERY; }
"FIRST"		{ return FIRST; }
"FOLLOW"		{ return FOLLOW; }
"PROD"		{ return PROD; }

[a-z]		{ strcpy(mytext, yytext); return TERMINAL; }
[A-Z]'+?	{ strcpy(mytext, yytext); return NON_TERMINAL; }

[ \n\t]		{}
.			{ yyerror("unknown character"); }
%%

int yywrap(void) {
	return 1;
}
