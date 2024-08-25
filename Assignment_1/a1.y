%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)
#define MAX_IDENTIFIERS 2000
#define MAX_IDENTIFIER_LENGTH 200

typedef struct {
  char name[MAX_IDENTIFIER_LENGTH];
  int depth;
} identifier_t;

typedef struct hashTableItem {
  int data;
  int key;
} hash_table_item_t;

unsigned long hash(char *str);
hash_table_item_t *searchSymbol(char *key, hash_table_item_t *hashTable[]);
void insertSymbol(char *key, int data, hash_table_item_t *hashTable[]);

void yyerror(char *);
int yylex(void);
char mytext[100];
int lineNumber = 1;

hash_table_item_t *symbolTable[MAX_IDENTIFIERS];
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
    int val;
    identifier_t id;
}

%type <str> identifier
%type <val> subscripts expression
%type <id> assignable term

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

declaration: assignable EQ expression SEMI_COLON {
		insertSymbol($1.name, $1.depth, symbolTable);
	  }
	   | assignable {
		insertSymbol($1.name, $1.depth, symbolTable);
	  }
;

assignment: assignable EQ expression SEMI_COLON {
	    hash_table_item_t *item = searchSymbol($1.name, symbolTable);
	    if (item != NULL)
		if (item->data != $1.depth)
		    yyerror("Invalid location");
	  }
;

assignable: identifier {
	    identifier_t id;
	    strncpy(id.name, (char *) $1, sizeof(id.name) - 1);
	    id.name[sizeof(id.name) - 1] = '\0';
	    id.depth = 0;
	    $$ = id;
	  }
	  | identifier subscripts {
	    identifier_t id;
	    strncpy(id.name, (char *) $1, sizeof(id.name) - 1);
	    id.name[sizeof(id.name) - 1] = '\0';
	    id.depth = $2;
	    $$ = id;
	  }
;

subscripts: subscript {
	    $$ = 1;
	  }
       | subscript subscripts {
	    $$ = 1 + $2;
       }
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
    expression PLUS expression {
	if ($1 != $3) yyerror("Invalid location");
	$$ = $1;
    }
    | expression MINUS expression {
	if ($1 != $3) yyerror("Invalid location");
	$$ = $1;
    }
    | expression COMPAR expression {
	if ($1 != $3) yyerror("Invalid location");
	$$ = $1;
    }
    | expression MULTIPLY expression {
	if ($1 != $3) yyerror("Invalid location");
	$$ = $1;
    }
    | expression DIVIDE expression {
	if ($1 != $3) yyerror("Invalid location");
	$$ = $1;
    }
    | expression EXPONENT expression {
	if ($1 != $3) yyerror("Invalid location");
	$$ = $1;
    }
    | MINUS expression %prec UMINUS {
	$$ = $2;
    }
    | OPEN_PAREN expression CLOSE_PAREN {
	$$ = $2;
    }
    | functionCall {
	$$ = 0;
    }
    | term {
	hash_table_item_t *item = searchSymbol($1.name, symbolTable);
	if (item != NULL) $$ = item->data - $1.depth;
	else $$ = 0;
      }
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

forStatement: FOR OPEN_PAREN assignment expression SEMI_COLON assignable EQ expression CLOSE_PAREN body
;


body: line
      | OPEN_BRACE lines CLOSE_BRACE
;


term: identifier {
	identifier_t id;
	strncpy(id.name, (char *) $1, sizeof(id.name) - 1);
	id.name[sizeof(id.name) - 1] = '\0';
	id.depth = 0;
	$$ = id;
      }
    | identifier subscripts {
	identifier_t id;
	strncpy(id.name, (char *) $1, sizeof(id.name) - 1);
	id.name[sizeof(id.name) - 1] = '\0';
	id.depth = $2;
	$$ = id;
      }
    | NUMBER {
	identifier_t id;
	id.name[0] = '\0';
	id.depth = 0;
	$$ = id;
      }
;

index: identifier
     | NUMBER
;

validType: VALID_TYPE
;

identifier: IDENTIFIER {
		$$ = strdup(mytext);
	  }
;
%%

void yyerror(char *message) {
    fprintf(stderr, "%d\n", lineNumber);
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

void insertSymbol(char *key, int data, hash_table_item_t* hashTable[]) {
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
