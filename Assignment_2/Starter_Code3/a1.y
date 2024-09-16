%{
    #include <bits/stdc++.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    using namespace std;

    void yyerror(const char *s);
    int yylex();
    int yywrap();
    int lineno = 1;
    extern char* yytext;
    set<string> notArray;
    set<string> oneDarray;
    set<string> twoDarray;
    set<string> vars;
%}

%union {
    int num;
    float fnum;
    char c;
    char* str;
}

%token INT CHAR FLOAT STRING VOID
%token POSNUM CH POSFLOAT
%token PEQ MEQ
%token POW DIV MUL ADD SUB PP NN 
%token EQ NEQ LT GT GEQ LEQ
%token IF ELSE FOR WHILE PRINTF RETURN
%type<num> arraydcl
%token<str> VAR
%left EQ NEQ LT GT GEQ LEQ
%nonassoc PP NN
%left ADD SUB
%left MUL DIV
%right POW

%start program
%%

program: program function
| program declaration decl_extend ';'
|
;

function: int_funct | char_funct | void_funct | float_funct
;

int_funct: INT VAR '(' function_params ')' '{' lines '}'
;

float_funct: FLOAT VAR '(' function_params ')' '{' lines '}'
;

void_funct: VOID VAR '(' function_params ')' '{' lines '}'
;

char_funct: CHAR VAR '(' function_params ')' '{' lines '}'
;

function_params: 
| declaration fp_extend
| special_decl fp_extend
;

fp_extend: ',' function_params
|
;

lines: lines stmt
|
;

stmt : matchedstmt     
    | unmatchedstmt                 
    ;
matchedstmt : IF '(' conditional ')' matchedstmt ELSE matchedstmt 
    | otherstmt                 
    ;
unmatchedstmt : IF '(' conditional ')' stmt 
    | IF '(' conditional ')' matchedstmt ELSE unmatchedstmt   
    ;

otherstmt: scope
    | statement ';'
    | for
    | while
    | printf
    | ';'
    ;

scope: '{' lines '}'

statement: declaration decl_extend
| assignment
| declassign
| return
| unary
| VAR '(' function_args ')'
;

return: RETURN expr
| RETURN
;

declassign: declaration '=' expr 
;

decl_extend: ',' VAR {notArray.insert($2); vars.insert($2);} decl_extend
| ',' VAR arraydcl {if($3 == 1) oneDarray.insert($2); else if ($3 == 2) twoDarray.insert($2); vars.insert($2);} decl_extend
|
;

declaration: INT VAR {notArray.insert($2); vars.insert($2);}
| CHAR VAR {notArray.insert($2); vars.insert($2);}
| FLOAT VAR {notArray.insert($2); vars.insert($2);}
| INT VAR arraydcl {if($3 == 1) oneDarray.insert($2); else if ($3 == 2) twoDarray.insert($2); vars.insert($2);}
| CHAR VAR arraydcl {if($3 == 1) oneDarray.insert($2); else if ($3 == 2) twoDarray.insert($2); vars.insert($2);}
| FLOAT VAR arraydcl {if($3 == 1) oneDarray.insert($2); else if ($3 == 2) twoDarray.insert($2); vars.insert($2);}
;

special_decl: INT VAR '[' ']' {oneDarray.insert($2); vars.insert($2);}
| CHAR VAR '[' ']' {oneDarray.insert($2); vars.insert($2);}
| FLOAT VAR '[' ']' {oneDarray.insert($2); vars.insert($2);}
;

arraydcl: '[' index ']' {$$ = 1;}
| '[' index ']' '[' index ']' {$$ = 2;}
;

assignment: VAR '=' expr 
| VAR arraydcl '=' expr 
| VAR PEQ expr 
| VAR arraydcl PEQ expr 
| VAR MEQ expr 
| VAR arraydcl MEQ expr 
;

index: expr;

expr: '(' expr ')'
| expr POW expr
| expr MUL expr | expr DIV expr
| expr ADD expr | expr SUB expr
| unary
| VAR
| VAR '[' index ']'
| VAR '[' index ']' '[' index ']'
| func
| num
| float
| CH
;

cexpr: '(' expr ')'
| expr POW expr
| expr MUL expr | expr DIV expr
| expr ADD expr | expr SUB expr
| unary
| func
| num
| float
| CH
;

unary: PP expr
| expr PP
| NN expr
| expr NN
;

var: VAR {if (vars.find($1)!=vars.end() && notArray.find($1)==notArray.end()) yyerror("Incompatible types");}
| VAR '[' index ']' {if (vars.find($1)!=vars.end() && oneDarray.find($1)==oneDarray.end()) yyerror("Incompatible types");}
| VAR '[' index ']' '[' index ']' {if (vars.find($1)!=vars.end() && twoDarray.find($1)==twoDarray.end()) yyerror("Incompatible types");}
;

while: WHILE '(' cexpr ')' stmt
| WHILE '(' var ')' stmt
| WHILE '(' fcomp ')' stmt
;

for: FOR '(' fini ';' fcomp ';' fasgn ')' stmt
;

fini: assignment
| expr
| declassign
|
;

conditional: cexpr comp cexpr
| var comp cexpr
| cexpr comp var
| var comp var
;

fcomp: conditional
| 
;

fasgn: assignment
| expr
|
;

printf: PRINTF '(' STRING fa_extend ')' ';' 
;


function_args: expr fa_extend
|
;

fa_extend: ',' function_args
|
;

func: VAR '(' function_args ')';
num: POSNUM | SUB POSNUM;
float: POSFLOAT | SUB POSFLOAT; // We can even return INTEGERS: just concat a ".0" to the end
comp: EQ | NEQ | LEQ | GEQ | LT | GT;
%%

int main()
{
    yyparse();
    return 0;
}

void yyerror(const char* msg) {
    cout << lineno << endl;
    exit(1);
}