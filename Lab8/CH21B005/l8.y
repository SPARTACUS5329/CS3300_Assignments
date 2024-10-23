%{
#include "l8.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void yyerror(char *);
int yylex(void);

char mytext;
extern char *yytext;
static int numVariables = 0;
static int numNodes = 0;
char variables[MAX_VARIABLES];
node_t *root;
variable_t *rootVariable;
variable_t *leafOne;
variable_t *leafZero;
hash_table_item_t *hashTable[MAX_VARIABLES];
%}

%token AND OR NOT
%token OPEN_PAREN CLOSE_PAREN
%token VARIABLE

%left AND OR
%right NOT 
%left OPEN_PAREN CLOSE_PAREN

%union {
  node_t *node;
}

%type <node> expression
%%

program:
  expression {
	root = $1;
  }
;

expression:
  expression AND expression {
	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->value = '&';
	node->left = $1;
	node->right = $3;
	$$ = node;
  }
  | expression OR expression {
	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->value = '|';
	node->left = $1;
	node->right = $3;
	$$ = node;
  }
  | NOT expression {
	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->value = '~';
	node->left = $2;
	$$ = node;
  }
  | OPEN_PAREN expression CLOSE_PAREN {
	$$ = $2;
  }
  | VARIABLE {
	node_t *node = (node_t *)malloc(sizeof(node_t));
	node->value = mytext;
	hash_table_item_t *item = searchSymbol(&node->value);
	if (item == NULL) {
	  variables[numVariables++] = mytext;
	  insertSymbol(&node->value, 0);
	}
	$$ = node;
  }
;

%%

void yyerror(char *message) {
  fprintf(stderr, "syntax error");
  exit(1);
}

void error(char *message) {
  perror(message);
  exit(1);
}

int main() {
  node_t *root = (node_t *)malloc(sizeof(node_t));
  yyparse();

  leafOne = (variable_t *)malloc(sizeof(variable_t));
  leafOne->value = '1';
  leafOne->onZero = leafOne;
  leafOne->onOne = leafOne;

  leafZero = (variable_t *)malloc(sizeof(variable_t));
  leafZero->value = '0';
  leafZero->onZero = leafZero;
  leafZero->onOne = leafZero;

  rootVariable = createBDT(0);

  int tempNumNodes = numNodes;
  while (true) {
	removeRedundantNodes(rootVariable);
	if (tempNumNodes == numNodes)
	  break;
	tempNumNodes = numNodes;
  }
  printBDD(rootVariable);

  return 0;
}

void removeRedundantNodes(variable_t *root) {
  variable_t **queue = (variable_t **)malloc(MAX_VARIABLES * sizeof(variable_t));
  queue[0] = root;
  int queueSize = 1;
  while (queueSize > 0) {
	int queueSize2 = 0;
	variable_t **levelNodes = (variable_t **)malloc(MAX_VARIABLES * sizeof(variable_t));
	int levelCount = 0;
	variable_t **queue2 = (variable_t **)malloc(MAX_VARIABLES * sizeof(variable_t));
	for (int i = 0; i < queueSize; i++) {
	  variable_t *node = queue[i];
	  if (node->value == '1' || node->value == '0')
		continue;
	  levelNodes[levelCount++] = node;
	  queue2[queueSize2++] = node->onZero;
	  queue2[queueSize2++] = node->onOne;
	}
	int tempNumNodes = numNodes;
	while (true) {
	  for (int i = 0; i < levelCount; i++) {
		if (levelNodes[i] == NULL)
		  continue;
		for (int j = i + 1; j < levelCount; j++) {
		  if (levelNodes[j] == NULL)
			continue;
			  
		  bool merged = mergeEquivalentNodes(levelNodes[i], levelNodes[j]);
		  if (merged)
			levelNodes[j] = NULL;
		}
	  }
	  if (tempNumNodes == numNodes)
		break;
	  tempNumNodes = numNodes;
	}
	free(queue);
	queue = queue2;
	queueSize = queueSize2;
  }
}

bool mergeEquivalentNodes(variable_t *var1, variable_t *var2) {
  if (var1->value == '1' || var1->value == '0' || var2->value == '1' ||
	  var2->value == '0' || var1->value != var2->value ||
	  var1->onOne != var2->onOne || var1->onZero != var2->onZero ||
	  var1->id == var2->id)
	return false;

  variable_t *parent2 = var2->parent;
  int parentIndex2 = var2->parentIndex;
  if (parentIndex2 == 1)
	parent2->onOne = var1;
  else
	parent2->onZero = var1;
  
  var2->onOne->parent = var1;
  var2->onOne->parentIndex = 1;
  var2->onZero->parent = var1;
  var2->onZero->parentIndex = 0;

  variable_t *parent = var2->parent;
  if (parent->onOne == parent->onZero) {
	if (parent == rootVariable) {
	  rootVariable = var1;
	} else {
	  variable_t *grandParent = parent->parent;
	  int grandParentIndex = parent->parentIndex;
	  if (grandParentIndex == 1)
		grandParent->onOne = var1;
	  else
		grandParent->onZero = var1;
	}
	numNodes--;
  }

  numNodes--;
  return true;
}

variable_t *createBDT(int varIndex) {
  variable_t *variable = (variable_t *)malloc(sizeof(variable_t));

  if (varIndex == numVariables) {
	int res = (int) evaluateExpression(root);
	variable = res == 1 ? leafOne : leafZero;
	return variable;
  }

  variable->value = variables[varIndex];

  insertSymbol(&variable->value, 0);
  variable->onZero = createBDT(varIndex + 1);
  
  insertSymbol(&variable->value, 1);
  variable->onOne = createBDT(varIndex + 1);
  
  if (variable->onZero == variable->onOne) {
	variable = variable->onZero;
  }
  else {
	variable->onOne->parent = variable;
	variable->onOne->parentIndex = 1;
	variable->onZero->parent = variable;
	variable->onZero->parentIndex = 0;
	numNodes++;
  }

  variable->id = numNodes;
  return variable;
}

bool evaluateExpression(node_t *node) {
  if (islower(node->value)) {
	hash_table_item_t *item = searchSymbol(&node->value);
	if (item == NULL) error("Invalid node");
	return item->value;
  }

  if (node->value == '&')
	return evaluateExpression(node->left) && evaluateExpression(node->right);

  if (node->value == '|')
	return evaluateExpression(node->left) || evaluateExpression(node->right);

  if (node->value == '~')
	return !evaluateExpression(node->left);

  error("Invalid node");
  return NULL;
}

unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash % MAX_VARIABLES;
}

hash_table_item_t *searchSymbol(char *key) {
  int hashIndex = hash(key);

  while (hashTable[hashIndex] != NULL) {
    if (hashTable[hashIndex]->key == hashIndex)
      return hashTable[hashIndex];

    ++hashIndex;
    hashIndex %= MAX_VARIABLES;
  }

  return NULL;
}

void insertSymbol(char *key, int data) {
  hash_table_item_t *item = searchSymbol(key);
  if (item != NULL) {
	item->value = data;
	return;
  }

  int hashIndex = hash(key);
  item = (hash_table_item_t *)malloc(sizeof(hash_table_item_t));
  item->value = data;
  item->key = hashIndex;

  while (hashTable[hashIndex] != NULL) {
    ++hashIndex;
    hashIndex %= MAX_VARIABLES;
  }

  hashTable[hashIndex] = item;
}

void printBDD(variable_t *root) {
  variable_t **queue = (variable_t **)malloc(MAX_VARIABLES * sizeof(variable_t));
  queue[0] = root;
  int queueSize = 1;
  while (queueSize > 0) {
	int queueSize2 = 0;
	variable_t **queue2 = (variable_t **)malloc(MAX_VARIABLES * sizeof(variable_t));
	for (int i = 0; i < queueSize; i++) {
	  variable_t *variable = queue[i];
	  if (variable->value == '1' || variable->value == '0' || variable->printed)
		continue;

	  printf("(%c, 0) -> %c\n", variable->value, variable->onZero->value);
	  printf("(%c, 1) -> %c\n", variable->value, variable->onOne->value);
	  variable->printed = true;
	  queue2[queueSize2++] = variable->onZero;
	  queue2[queueSize2++] = variable->onOne;
	}
	free(queue);
	queue = queue2;
	queueSize = queueSize2;
  }
}

