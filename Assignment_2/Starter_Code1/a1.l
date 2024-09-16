
%{
    #include<bits/stdc++.h>
    using namespace std;

    #include "a1.tab.h"

    void yyerror(char* s);

    int ln = 1;
%}

%%

\"(.*)\" {return STRING_INP;}

main {return MAIN;}

int {yylval.strval = strdup(yytext); return TYPE;}
char {yylval.strval = strdup(yytext); return TYPE;}
float {yylval.strval = strdup(yytext); return TYPE;}

printf {return PRINTF;}

if {return IF;}
else {return ELSE;}

"<=" {return COND;}
"==" {return COND;}
">=" {return COND;}
"<" {return COND;}
">" {return COND;}

for {return FOR;}
while {return WHILE;}

return {return RETURN;}

\*[ \t]*\* {return '^';}

[+\-\*\/] {return *yytext;}

[a-zA-Z_0-9]* {yylval.strval = strdup(yytext); return NAME;}

[\{\}\(\)\;\=\,] {return *yytext;}
"[" {return *yytext;}
"]" {return *yytext;}

[ \t]
[\n] {ln++;}

. {yyerror("syntax error");}

%%

int yywrap(void){
    return 1;
}
