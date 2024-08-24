%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_IDENTIFIERS 2000
#define MAX_IDENTIFIER_LENGTH 200
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)
void yyerror(char *);
int yylex(void);
char mytext[100];
int lineNumber = 1;

typedef struct Identifier {
    char type[5];
    char name[MAX_IDENTIFIER_LENGTH];
} identifier_t;

typedef struct hashTableItem {
    identifier_t data;
    int key;
} hash_table_item_t;

hash_table_item_t *symbolTable[MAX_IDENTIFIERS];

unsigned long hash(char *str);
hash_table_item_t *searchSymbol(char *key, hash_table_item_t* hashTable[]);
void insertSymbol(char *key, identifier_t data, hash_table_item_t* hashTable[]);
%}

%token OPEN_PAREN CLOSE_PAREN OPEN_BRACE CLOSE_BRACE OPEN_SQUARE CLOSE_SQUARE COMMA COMPAR SEMI_COLON
%token EQ PLUS MINUS MULTIPLY DIVIDE EXPONENT
%token VALID_TYPE IDENTIFIER NUMBER STRING
%token IF ELSE
%token WHILE FOR
%token RETURN

%left PLUS MINUS COMPAR
%left MULTIPLY DIVIDE
%right UMINUS EXPONENT
%left OPEN_PAREN CLOSE_PAREN
%left ELSE

%union {
    char *str;
}

%type <str> identifier assignable validType

%%

program: lines
;

lines: line
     | line lines
;

line: declarationStatement
    | assignment
    | expression SEMI_COLON
    | returnStatement
    | ifStatement
    | loopStatement
    | functionBlock
;

declarationStatement: validType declarations SEMI_COLON
;

declarations: declaration
	    | declaration COMMA declarations
;

declaration: assignment
	   | assignable
;

assignment: assignable EQ expression SEMI_COLON
;

assignable: identifier {
	    $$ = $1;
	  }
	  | identifier subscripts {
	    $$ = $1;
	  }
;

subscripts: subscript
       | subscript subscripts
;

subscript: OPEN_SQUARE index CLOSE_SQUARE 
;

functionCall: identifier OPEN_PAREN arguments CLOSE_PAREN
;

arguments:| argument
	 | argument COMMA arguments
;

argument: expression | STRING
;

expression:
    expression PLUS expression
    | expression MINUS expression
    | expression COMPAR expression
    | expression MULTIPLY expression
    | expression DIVIDE expression
    | expression EXPONENT expression
    | MINUS expression %prec UMINUS
    | OPEN_PAREN expression CLOSE_PAREN
    | functionCall
    | term
;

functionBlock: validType identifier OPEN_PAREN parameters CLOSE_PAREN body
;

returnStatement: RETURN expression SEMI_COLON
	       | RETURN SEMI_COLON;
;

parameters:| parameter
	 | parameter COMMA parameters
;

parameter: validType assignable
;

ifStatement: IF OPEN_PAREN expression CLOSE_PAREN body ELSE body
	   | IF OPEN_PAREN expression CLOSE_PAREN body
;

loopStatement: whileStatement | forStatement
;

whileStatement: WHILE OPEN_PAREN expression CLOSE_PAREN body
;

forStatement: FOR OPEN_PAREN assignment expression SEMI_COLON assignable EQ expression CLOSE_PAREN
;


body: line
      | OPEN_BRACE lines CLOSE_BRACE
;


term: identifier
    | identifier subscripts
    | NUMBER
;

index: identifier
     | NUMBER
;

validType: VALID_TYPE {
		$$ = strdup(mytext);
	  }
;

identifier: IDENTIFIER {
		$$ = strdup(mytext);
	  }
;
%%

void yyerror(char *message) {
    fprintf(stderr, "%s: %d\n", message, lineNumber);
    exit(1);
}

int main(void) {
    yyparse();
    return 0;
}

unsigned long hash(char *str) {
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return hash % MAX_IDENTIFIERS;
}

hash_table_item_t *searchSymbol(char *key, hash_table_item_t* hashTable[]) {

	int hashIndex = hash(key);

	while(hashTable[hashIndex] != NULL) {
	  if(hashTable[hashIndex]->key == hashIndex)
		 return hashTable[hashIndex]; 
			
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}        

	return NULL;        
}

void insertSymbol(char *key, identifier_t data, hash_table_item_t* hashTable[]) {
	hash_table_item_t *item;
	item = searchSymbol(key, hashTable);
	if (item != NULL) {
		item->data = data;
		return;
	}
	int hashIndex = hash(key);
	item = (hash_table_item_t*) malloc(sizeof(hash_table_item_t));
	item->data = data;
	item->key = hashIndex;

	while(hashTable[hashIndex] != NULL) {
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}

	hashTable[hashIndex] = item;
}
