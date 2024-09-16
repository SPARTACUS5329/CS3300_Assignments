%{
    #include <bits/stdc++.h>
    #include <string.h>
    #include "y.tab.h"
    using namespace std;
    extern int lineno;
%}

alpha [a-zA-Z]
digit [0-9]

%%
int     {return INT;}
char    {return CHAR;}
float   {return FLOAT;}
void    {return VOID;}
if      {return IF;}
else    {return ELSE;}
for     {return FOR;}
while   {return WHILE;}
printf  {return PRINTF;}
return  {return RETURN;}
\"(.*)\"                        {return STRING;}
\'(.*)\'                        {return CH;}
({alpha}|[_])({alpha}|{digit}|[_])*       {yylval.str = strdup(yytext); return VAR;}
({digit})+                      {return POSNUM;}
({digit})+[\.]({digit})+[fF]?   {return POSFLOAT;}
\/\/.*\n                        { /* One-line comment*/ }
\*\*    {return POW;}
[\[]    {return '[';}
[\]]    {return ']';}
[\{]    {return '{';}
[\}]    {return '}';}
=       {return '=';}
\+\=    {return PEQ;}
\-\=    {return MEQ;}
==      {return EQ;}
!=      {return NEQ;}
\+\+    {return PP;}
\-\-    {return NN;}
\<=     {return LEQ;}
\>=     {return GEQ;}
\<      {return LT;}
\>      {return GT;}
\/      {return DIV;}
\*      {return MUL;}
\+      {return ADD;}
-       {return SUB;}
,       {return ',';}
[\']    {return '\'';}
[\"]    {return '\"';}
[(]     {return '(';}
[)]     {return ')';}
[;]     {return ';';}
[ \t]   {}
[\n\r]  {lineno++;}
.       {return *yytext;}
%%

int yywrap() {
    return 1;
}