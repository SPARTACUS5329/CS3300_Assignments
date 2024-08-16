%{
#include "a1.tab.h"
#include <stdlib.h>
void yyerror(char *);
extern char mytext[];
%}

%%
"("		{ return OPEN_PAREN; }
")"		{ return CLOSE_PAREN; }
"{"		{ return OPEN_BRACE; }
"}"		{ return CLOSE_BRACE; }
","		{ return COMMA; }

"="		{ return EQ; }
"+"		{ return PLUS; }
"-"		{ return MINUS; }
"*"		{ return MULTIPLY; }
"/"		{ return DIVIDE; }
";"		{ return SEMI_COLON; }

int		{ return VALID_TYPE; }
char		{ return VALID_TYPE; }
float		{ return VALID_TYPE; }

"=="		{ return COMPAR; }
"!="		{ return COMPAR; }
"<"		{ return COMPAR; }
"<="		{ return COMPAR; }
">="		{ return COMPAR; }

if		{ return IF; }
else		{ return ELSE; }

[0-9]+         { strcpy(mytext, yytext); return NUMBER; }
[a-zA-Z][a-zA-Z0-9]* { strcpy(mytext, yytext); return IDENTIFIER; }

[ \n\t]	{ }

.	{yyerror("unknown character");}
%%

int yywrap(void) {
    return 1;
}
