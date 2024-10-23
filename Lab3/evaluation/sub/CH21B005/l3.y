%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50
void yyerror(char *);
int yylex(void);
char mytext[100];
char var[100];
int num = 0;

typedef struct hashTableItem {
    int data;
    int key;
} hash_table_item_t;

hash_table_item_t *symbolTable[500];

unsigned long hash(char *str);
hash_table_item_t *searchSymbol(char *key, hash_table_item_t* hashTable[]);
void insertSymbol(char *key, int data, hash_table_item_t* hashTable[]);
%}

%token IDENTIFIER EQ NUMBER PRINT
%token PLUS MINUS MULTIPLY DIVIDE MINOP MAXOP

%right MINOP MAXOP
%left MULTIPLY DIVIDE
%right PLUS MINUS
%right UMINUS


%union {
    char *str;
	int val;
}

%type <str> identifier
%type <val> expression factor

%%

program: lines
;

lines: line
	 | line lines
;

line: assignment
	| printStatement
;

assignment: identifier EQ expression {
			insertSymbol($1, $3, symbolTable);
		  }
;

expression:
    expression PLUS expression    { $$ = $1 + $3; }
    | expression MINUS expression { $$ = $1 - $3; }
	| expression MINOP expression { $$ = ($1 < $3) ? $1 : $3; }
    | expression MAXOP expression { $$ = ($1 > $3) ? $1 : $3; }
    | expression MULTIPLY expression { $$ = $1 * $3; }
    | expression DIVIDE expression { 
		if ($3 == 0) yyerror("divide by zero not allowed");
		$$ = $1 / $3;
	}
	| MINUS expression %prec UMINUS  { $$ = -$2; }
    | factor
;

factor:
    NUMBER { $$ = atoi(mytext); }
    | identifier {
		hash_table_item_t* variable = searchSymbol(mytext, symbolTable);
		if (variable == NULL) {
			printf("read from undefined variable %s\n", mytext);
			exit(1);
		}
		$$ = variable->data;
	}
;

identifier: IDENTIFIER {
		$$ = strdup(mytext);
	  }
;

printStatement: PRINT identifier {
				hash_table_item_t* variable = searchSymbol(mytext, symbolTable);
				if (variable == NULL) {
					printf("read from undefined variable %s\n", mytext);
					exit(1);
				}
			  	printf("%d\n", variable->data);
			  }
;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
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

	return hash % SIZE;
}

hash_table_item_t *searchSymbol(char *key, hash_table_item_t* hashTable[]) {
	int hashIndex = hash(key);

	while(hashTable[hashIndex] != NULL) {
	  if(hashTable[hashIndex]->key == hashIndex)
		 return hashTable[hashIndex]; 
			
	  ++hashIndex;
	  hashIndex %= SIZE;
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
	  hashIndex %= SIZE;
	}

	hashTable[hashIndex] = item;
}
