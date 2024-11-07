%{
#include <stdlib.h>
#define MAX_IDENTIFIERS 2000
#define MAX_IDENTIFIER_LENGTH 200

#include "a4.h"
#include "a4.tab.h"

void yyerror(char *);
extern char mytext[];
extern int lineNumber;
%}

%option c++

%%

"+"	{ return PLUS; }
"-"	{ return MINUS; }
"*"	{ return MULTIPLY; }
"/"	{ return DIVIDE; }

"<"	{ return COMPAR; }
">"	{ return COMPAR; }
"<="	{ return COMPAR; }
">="	{ return COMPAR; }

"!"	{ return NOT; }

"if"	{ return IF; }
"goto"	{ return GOTO; }

"print"	{ return PRINT; }
"read"	{ return READ; }

"="	{ return EQ; }
":"	{ return COLON; }
[0-9]+  { strcpy(mytext, yytext); return NUMBER_TOK; }
[a-zA-Z_][a-zA-Z0-9_]*	{ strcpy(mytext, yytext); return IDENTIFIER_TOK; }

[ \t]	{ }
[\n]	{ lineNumber++; }

.	{yyerror("unknown character");}
%%

int yywrap(void) {
    return 1;
}
