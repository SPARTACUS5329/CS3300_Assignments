%{
#include "a1.tab.h"
#include <stdlib.h>
void yyerror(char *);
extern char mytext[];
extern int lineNumber;
%}

%%
"("		{ return OPEN_PAREN; }
")"		{ return CLOSE_PAREN; }
"{"		{ return OPEN_BRACE; }
"}"		{ return CLOSE_BRACE; }
"["		{ return OPEN_SQUARE; }
"]"		{ return CLOSE_SQUARE; }
","		{ return COMMA; }

"="		{ return EQ; }
"+"		{ return PLUS; }
"-"		{ return MINUS; }
"*"		{ return MULTIPLY; }
"/"		{ return DIVIDE; }
"**"		{ return EXPONENT; }
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

while		{ return WHILE; }

return		{ return RETURN; }

[0-9]+         { strcpy(mytext, yytext); return NUMBER; }
\"[^\"]*\"          { strcpy(mytext, yytext); return STRING; }
[a-zA-Z][a-zA-Z0-9]* { strcpy(mytext, yytext); return IDENTIFIER; }

[ \t]	{ }
[\n]	{ lineNumber++; }

.	{yyerror("unknown character");}
%%

int yywrap(void) {
    return 1;
}