%{
#include "l3.tab.h"
#include <stdlib.h>
void yyerror(char *);
extern char mytext[];
%}

%%
"="		{ return EQ; }

"+"		{ return PLUS; }

"-"		{ return MINUS; }

"*"		{ return MULTIPLY; }

"/"		{ return DIVIDE; }

"#"		{ return MINOP; }

"@"		{ return MAXOP; }

[0-9]+         { strcpy(mytext, yytext); return NUMBER; }

print { return PRINT; }

[a-zA-Z][a-zA-Z0-9]* { strcpy(mytext, yytext); return IDENTIFIER; }

[ \n\t]	{ }

.	{yyerror("unknown character");}
%%

int yywrap(void) {
    return 1;
}
