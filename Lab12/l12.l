%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "l12.h"
#include "l12.tab.h"
void yyerror(char *);

extern char mytext[];
%}

%%
"+"		{ return PLUS; }
"-"		{ return MINUS; }

"<"		{ strcpy(mytext, yytext); return COMPAR; }
">"		{ strcpy(mytext, yytext); return COMPAR; }
"=="		{ strcpy(mytext, yytext); return COMPAR; }

"&&"		{ return SHORT_AND; }
"||"		{ return SHORT_OR; }

"="		{ return EQ; }
";"		{ return SEMI_COLON; }
","		{ return COMMA; }
"("		{ return OPEN_PAREN; }
")"		{ return CLOSE_PAREN; }
"{"		{ return OPEN_BRACE; }
"}"		{ return CLOSE_BRACE; }

"int"	{ return INT; }
"if"	{ return IF; }
"else"	{ return ELSE; }
"void"	{ return VOID; }
"main"	{ return MAIN; }
"return"	{ return RETURN; }

"%%"	{ return SEPARATOR; }
"DEAD"	{ return DEAD_TOK; }
"REACHABLE"	{ return REACHABLE_TOK; }
"SELF-RECURSIVE"	{ return SELF_RECURSIVE_TOK; }
"EVENTUALLY-RECURSIVE"	{ return EVENTUALLY_RECURSIVE_TOK; }
"CO-RECURSIVE"	{ return CO_RECURSIVE_TOK; }
"DEPTH"	{ return DEPTH_TOK; }

[0-9]+	{ strcpy(mytext, yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { strcpy(mytext, yytext); return IDENTIFIER; }

[ \n\t]	{}
. 		{ yyerror("unknown character"); }
%%

int yywrap(void) {
	return 1;
}
