%{
	#include <stdlib.h>
	#include "a3.tab.h"
	void yyerror(char *);
%}

%%
"//".*\n ;
"/*"(["*"[^/]|[^*]])*"*/"  ;
\#include[ ]*\<stdio.h\>	{return HEADER;}
"int"		{return INT; }
"char"      {return CHAR;}
"main"      {return MAIN;}
"printf"    {return PRINTF;}
"if"        {return IF;}
"else"      {return ELSE;}
"while"     {return WHILE;}
"return"    {return RETURN;}

"&&" {return AND;}
"||" {return OR;}
"<=" {return LE;}
">=" {return GE;}
"<" {return LT;}
">" {return GT;}
"==" {return EQEQ;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return TIMES;}
"/" {return DIV;}
"[" {return LBRACK;}
"]" {return RBRACK;}
"!=" {return NE;}
"{"  {return LBRACE;}
"}"  {return RBRACE;}
"("  {return LPAREN;}
")"  {return RPAREN;}
"!" {return NOT;}
";" {return SEMI;}
"," {return COMMA;}
"=" {return EQ;}

\"([^\"]|\\\")*\"  { yylval.str = strdup(yytext); return QUOTED_STRING; }
\'([^\']|\\\'|\\0|\\\\|\\n)\'  { yylval.str = strdup(yytext); return CONST_CHAR; }
[a-zA-Z_][a-zA-Z0-9_]* {yylval.str = strdup(yytext);return ID;}
[1-9][0-9]* {yylval.str = strdup(yytext);return INTLIT;}
"0" {yylval.str = strdup(yytext);return INTLIT;}

[ \n\t\r\f]	{ }
.	{printf("%s: ",yytext);yyerror("unknown character");}
%%

int yywrap(void) {
    return 1;
}

