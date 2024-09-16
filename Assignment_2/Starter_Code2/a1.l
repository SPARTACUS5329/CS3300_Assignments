%{
	#include "y.tab.h"
    #include <stdlib.h>
    using namespace std;

    extern char mytext[];
    void yyerror(char *);
    extern int line_number;
%}

digit   [0-9]
letter  [a-zA-Z_]
int_const   {digit}+
float_const {digit}+("."{digit}+)
char_const  ['].[']

string   [\"].*[\"]

%%

"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"return"    { return RETURN; }
"printf"    { return PRINTF; }
"void"      { return VOID; }
"int"       { return INT; }
"char"      { return CHAR; }
"float"     { return FLOAT; }

"=="        { return EQ_OP; }
"!="        { return NE_OP; }
"<="        { return LE_OP; }
">="        { return GE_OP; }
"<"         { return '<'; }
">"         { return '>'; }

"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"**"        { return EXP_OP; }
"++"        { return INC_OP; }
"--"        { return DEC_OP; }

"||"        { return OR; }
"&&"        { return AND; }

"="         { return '='; }
";"         { return ';'; }
","         { return ','; }
"("         { return '('; }
")"         { return ')'; }
"{"         { return '{'; }
"}"         { return '}'; }
"["         { return '['; }
"]"         { return ']'; }


{int_const}      { yylval.int_val = atoi(yytext); return INT_CONST; }
{float_const}    { yylval.float_val = atof(yytext); return FLOAT_CONST; }
{char_const}     { yylval.char_val = yytext[1]; return CHAR_CONST; }

{letter}({letter}|{digit})*  { yylval.str_val = strdup(yytext); return IDENTIFIER; }

{string}    { yylval.str_val = strdup(yytext); return STRING_LITERAL; }

[ \t]+  ; // ignore whitespace

[\n\r]      { line_number++; }

.           { return *yytext; }

%%

int yywrap(void) {
    return 1;
}