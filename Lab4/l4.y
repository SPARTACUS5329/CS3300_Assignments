%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SYMBOLS 200
#define SIZE 500

void yyerror(char *);
int yylex(void);
char mytext[100];
extern char *yytext;
static int depth = 0;

typedef struct HashTableItem {
	int key;
	int value;
} hash_table_item_t;

typedef struct Block {
	int depth;
	struct Block *parent;
	hash_table_item_t *symbolTable[MAX_SYMBOLS];
} block_t;

static block_t *currBlock;

unsigned long hash(char *);
hash_table_item_t *searchSymbol(char *, hash_table_item_t *hashTable[]);
void insertSymbol(char *, int, hash_table_item_t *hashTable[]);
%}

%token NUMBER IDENTIFIER PRINT
%token OPEN_BRACE CLOSE_BRACE
%token PLUS MINUS EQ

%right PLUS MINUS

%union {
	char *str;
	int val;
}

%type <str> identifier
%type <val> expression term

%%
program: lines
;

lines: line
	| line lines
;

line: assignment
	| printStatement
	| block
;

assignment: identifier EQ expression {
		insertSymbol($1, $3, currBlock->symbolTable);
	}
;

expression:
	expression PLUS expression { $$ = $1 + $3; }
	| expression MINUS expression { $$ = $1 - $3; }
	| term
;

term: identifier {
		hash_table_item_t *item = NULL;
		block_t *tempBlock = currBlock;
		while (tempBlock != NULL) {
			item = searchSymbol(mytext, tempBlock->symbolTable);
			if (item == NULL) {
				tempBlock = tempBlock->parent;
				continue;
			}
			$$ = item->value;
			break;
		}
		if (item == NULL) {
			printf("read from undefined variable %s\n", mytext);
			exit(1);
		}
	}
	| NUMBER {
		$$ = atoi(mytext);
	}
;

printStatement: PRINT identifier {
		hash_table_item_t *item = NULL;
		block_t *tempBlock = currBlock;
		while (tempBlock != NULL) {
			item = searchSymbol(mytext, tempBlock->symbolTable);
			if (item == NULL) {
				tempBlock = tempBlock->parent;
				continue;
			}
			break;
		}
		if (item == NULL) {
			printf("read from undefined variable %s\n", mytext);
			exit(1);
		}
		printf("%d\n", item->value);
	}
;

block: startBlock
	lines
	CLOSE_BRACE {
		currBlock = currBlock->parent;
	}
;

startBlock: OPEN_BRACE {
		block_t *newBlock = (block_t *) malloc(sizeof(block_t));
		newBlock->depth = currBlock->depth + 1;
		newBlock->parent = currBlock;
		currBlock = newBlock;
	}
;

identifier: IDENTIFIER {
		$$ = strdup(mytext);
	}
;

%%

void yyerror(char *message) {
	perror(message);
	exit(1);
}

int main() {
	currBlock = (block_t *) malloc(sizeof(block_t));
	currBlock->depth = depth;
	currBlock->parent = NULL;

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

hash_table_item_t *searchSymbol(char *key, hash_table_item_t *hashTable[]) {
	int hashIndex = hash(key);
	
	while (hashTable[hashIndex] != NULL) {
		if (hashTable[hashIndex]->key == hashIndex)
			return hashTable[hashIndex];
		++hashIndex;
		hashIndex %= SIZE;
	}
	return NULL;
}

void insertSymbol(char *key, int value, hash_table_item_t *hashTable[]) {
	hash_table_item_t *item;
	item = searchSymbol(key, hashTable);
	if (item != NULL) {
		item->value = value;
		return;
	}	
	int hashIndex = hash(key);
	item = (hash_table_item_t *) malloc(sizeof(hash_table_item_t));
	item->value = value;
	item->key = hashIndex;
	
	while (hashTable[hashIndex] != NULL) {
		++hashIndex;
		hashIndex %= SIZE;
	}
	hashTable[hashIndex] = item;
}
