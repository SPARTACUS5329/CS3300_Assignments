%union{
    char* strval;
    int intval;
}

%token<strval> NAME TYPE
%token MAIN PRINTF STRING_INP IF ELSE COND FOR WHILE RETURN

%type <intval> body decl assgn

%{
    #include <bits/stdc++.h>
    using namespace std;

    extern char* yytext;

    void yyerror(char* s);
    int yylex(void);
    extern int ln;

    set<string> arr1D;
    set<string> arr2D;
%}

%left '+' '-'
%left '*' '/'
%right '^'

%start program

%%
program: TYPE MAIN '(' ')' '{' body '}' {
    if(string($1) != "int"){
        yyerror("invalid type of main function");
    }
};
    |   decl ';' program
    |   func program

func:   TYPE NAME '('  args ')' '{' body '}'
args: 
    |   singlearg
    |   singlearg ',' args
singlearg: TYPE NAME
    |   TYPE NAME '['']'
    |   TYPE NAME '['']' '['']'
    |   TYPE NAME '['expr']'
    |   TYPE NAME '['expr']' '['expr']'

body: line {};
    |   body line {};

line: decl ';' | assgn ';' | printf ';' | funccall ';' | ifelse | for | while | return ';'

decl: TYPE names {};
    |   TYPE NAME '=' expr  {};

names: NAME
    |   NAME '[' expr ']' { arr1D.insert(string($1));};
    |   NAME '[' expr ']' '[' expr ']' { arr2D.insert(string($1)); };
    |   NAME ',' names
    |   NAME '[' expr ']' ',' names { arr1D.insert(string($1)); };
    |   NAME '[' expr ']' '[' expr ']' ',' names { arr2D.insert(string($1)); };

expr: identifier {};
    |   funccall {};
    |   '(' expr ')' 
    |   expr '+' expr
    |   expr '-' expr
    |   expr '*' expr
    |   expr '/' expr
    |   expr '^' expr

assgn: identifier '=' expr {};

identifier: NAME {};
    |   NAME '[' expr ']'
    |   NAME '[' expr ']' '[' expr ']' 

printf: PRINTF '(' STRING_INP printfparams ')'
printfparams: 
    |   ',' expr printfparams

funccall: NAME '(' params ')'
params: 
    |   expr
    |   expr ',' params

ifelse: IF '(' cond ')' statement 
    |   IF '(' cond ')' statement ELSE statement 

cond: ifexpr COND ifexpr

ifexpr: NAME { 
        string name = string($1);
        if(arr1D.find(name) != arr1D.end()){
            yyerror("1D array indexing incorrect");
        }
        if(arr2D.find(name) != arr2D.end()){
            yyerror("2D array indexing incorrect");
        }
    };
    |   NAME '[' expr ']' { 
        string name = string($1);
        if(arr2D.find(name) != arr2D.end()){
            yyerror("2D array indexing incorrect");
        }
    };
    |   NAME '[' expr ']' '[' expr ']'
    |   '(' ifexpr ')'
    |   ifexpr '+' ifexpr
    |   ifexpr '-' ifexpr
    |   ifexpr '*' ifexpr
    |   ifexpr '/' ifexpr
    |   ifexpr '^' ifexpr

for: FOR '(' fordecl ';' forcond ';' forassgn ')' statement
fordecl:
    |   assgn
    |   decl
forcond:
    |   cond
forassgn:
    |   assgn

while: WHILE '(' cond ')' statement

statement: line
    |   '{' body '}'

return: RETURN
    |   RETURN expr 

%%

void yyerror(char* s){
    cerr<<ln;
    exit(1);
}

int main(){
    yyparse();
    return 0;
}