%{
#include <stdlib.h>
#include "a3.h"
#include "a3.tab.h"

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
"+"		{ return PLUS_TOK; }
"-"		{ return MINUS_TOK; }
"*"		{ return MULTIPLY_TOK; }
"/"		{ return DIVIDE_TOK; }
"**"		{ return EXPONENT_TOK; }
";"		{ return SEMI_COLON; }

"int"		{ strcpy(mytext, yytext); return VALID_TYPE; }
"char"		{ strcpy(mytext, yytext); return VALID_TYPE; }
"float"		{ strcpy(mytext, yytext); return VALID_TYPE; }

"main"		{ strcpy(mytext, yytext); return MAIN; }

"=="		{ strcpy(mytext, yytext); return COMPAR; }
"!="		{ strcpy(mytext, yytext); return COMPAR; }
"<"		{ strcpy(mytext, yytext); return COMPAR; }
">"		{ strcpy(mytext, yytext); return COMPAR; }
"<="		{ strcpy(mytext, yytext); return COMPAR; }
">="		{ strcpy(mytext, yytext); return COMPAR; }

"&&"		{ strcpy(mytext, yytext); return SHORT_AND_TOK; }
"||"		{ strcpy(mytext, yytext); return SHORT_OR_TOK; }
"!"		{ strcpy(mytext, yytext); return NOT_TOK; }

"if"		{ return IF_TOK; }
"else"		{ return ELSE_TOK; }

"while"		{ return WHILE_TOK; }
"for"		{ return FOR_TOK; }

"return"		{ return RETURN_TOK; }

"#include"		{ return INCLUDE; }
"<stdio.h>"		{ return LIB_NAME; }

[0-9]+         { strcpy(mytext, yytext); return NUMBER; }
\"[^\"]*\"          { strcpy(mytext, yytext); return STRING_TOK; }
\'([^\']|\\\'|\\0|\\\\|\\n)\'          { strcpy(mytext, yytext); return CHAR_TOK; }
[a-zA-Z_][a-zA-Z0-9_]* { strcpy(mytext, yytext); return IDENTIFIER; }

"//".* {}
"/*"([^*]|\*+[^*/])*\*+"/"  {}

[ \t]	{ }
[\n]	{ lineNumber++; }
[\0]	{ return CHAR_TOK; }

.	{yyerror("unknown character");}
%%

int yywrap(void) {
    return 1;
}
