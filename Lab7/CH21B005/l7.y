%{
#include "l7.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void yyerror(char *);
int yylex(void);

char mytext[100];
char queries[MAX_QUERIES][MAX_QUERY_SIZE];
production_t *currProduction;
production_t **productions = NULL;
static int numProductions = 0;
static int numQueries = 0;
extern char *yytext;
symbol_table_item_t *symbolTable[MAX_PRODUCTIONS];
parsing_table_item_t *parsingTable[MAX_PRODUCTIONS * MAX_RULES];

%}

%token PLUS MINUS MULTIPLY DIVIDE DOLLAR
%token UNION SEMI_COLON ASSIGN OPEN_PAREN CLOSE_PAREN
%token EPS
%token NON_TERMINAL TERMINAL
%token GRAMMAR QUERY FIRST FOLLOW PROD

%left PLUS MINUS
%left MULTIPLY DIVIDE
%nonassoc TERMINAL NON_TERMINAL

%union {
	char str[MAX_RULE_SIZE];
}

%type <str> alt terminal nonTerminal factor terminalSymbol

%%

program: grammar queries
;

grammar: GRAMMAR productions
;

queries: QUERY queryStatements
;

queryStatements: queryStatement
				| queryStatement queryStatements
;

queryStatement: firstQuery 
			  | followQuery
			  | prodQuery
;

firstQuery: FIRST nonTerminal {
				strcpy(queries[numQueries], "FIRST ");
				strcat(queries[numQueries++], $2);
			  }
;

followQuery: FOLLOW nonTerminal {
				strcpy(queries[numQueries], "FOLLOW ");
				strcat(queries[numQueries++], $2);
			  }
;

prodQuery: PROD nonTerminal terminalSymbol {
				strcpy(queries[numQueries], "PROD ");
				strcat(queries[numQueries], $2);
				strcat(queries[numQueries], " ");
				strcat(queries[numQueries++], $3);
			  }
;

terminalSymbol: PLUS { strcpy($$, "+"); }
			  | MINUS { strcpy($$, "-"); }
			  | MULTIPLY { strcpy($$, "*"); }
			  | DIVIDE { strcpy($$, "/"); }
			  | OPEN_PAREN { strcpy($$, "("); }
			  | CLOSE_PAREN { strcpy($$, ")"); }
			  | DOLLAR { strcpy($$, "$"); }
			  | terminal { strcpy($$, $1); }
;

productions: production
	| production productions
;

production: nonTerminalRule ASSIGN altList SEMI_COLON
;

nonTerminalRule: nonTerminal {
		production_t *prod = (production_t *)malloc(sizeof(production_t));
		strcpy(prod->value, mytext);
		prod->id = numProductions;
		productions[numProductions++] = prod;
		currProduction = prod;
		insertSymbol(currProduction->value, currProduction);
	}
;

altList: alt {
		strcpy(currProduction->rules[currProduction->numRules++], $1);
	}
	| altList UNION alt {
		strcpy(currProduction->rules[currProduction->numRules++], $3);
	}
;

alt: alt factor {
		strcpy($$, $1);
		strcat($$, $2);
	}
	| factor {
		strcpy($$, $1);
	}
	| EPS {
		strcpy($$, "eps");
		currProduction->nullable = true;
		currProduction->epsIndex = currProduction->numRules;
	}
;

factor: PLUS { strcat($$, "+"); }
	| MINUS { strcat($$, "-"); }
	| MULTIPLY { strcat($$, "*"); }
	| DIVIDE { strcat($$, "/"); }
	| OPEN_PAREN { strcat($$, "("); }
	| CLOSE_PAREN { strcat($$, ")"); }
	| terminal { strcpy($$, $1); }
	| nonTerminal { strcpy($$, $1); }
;


nonTerminal: NON_TERMINAL {
		strcpy($$, mytext);
	}
;

terminal: TERMINAL {
		strcpy($$, mytext);
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
  productions = (production_t **)malloc(MAX_PRODUCTIONS * sizeof(production_t));
  yyparse();

  for (int i = 0; i < numProductions; i++) {
    production_t *production = productions[i];
    createFirstSet(production);
    char firstSet[production->numFirst];
    int firstSetSize =
        charArrayToSet(production->first, production->numFirst, firstSet);
    production->numFirst = 0;

    for (int j = 0; j < firstSetSize; j++) {
      if (i == 0 && firstSetSize > 1 && firstSet[j] == '.') continue;
      production->first[production->numFirst++] = firstSet[j];
    }
  }

  production_t *firstProduction = productions[0];
  firstProduction->follow[firstProduction->numFollow++] = '$';

  for (int n = 0; n < 2; n++)
    for (int i = 0; i < numProductions; i++)
      createFollowSet(productions[i]);

  for (int i = 0; i < numProductions; i++) {
    production_t *production = productions[i];
    char followSet[production->numFollow];
    int followSetSize =
        charArrayToSet(production->follow, production->numFollow, followSet);
    production->numFollow = 0;

    int j = 0;
    while (j < followSetSize) {
      if (followSet[j] == '.') {
        j++;
        continue;
      }
      production->follow[production->numFollow++] = followSet[j++];
      if (production->nullable) {
        char *tokenPair = (char *)malloc(4 * sizeof(char));
        sprintf(tokenPair, "%s%c", production->value,
                production->follow[production->numFollow - 1]);
        insertParsingSymbol(tokenPair, production->epsIndex);
      }
    }
  }

  for (int i = 0; i < numQueries; i++) {
    if (strstr(queries[i], "FIRST") != NULL ||
        strstr(queries[i], "FOLLOW") != NULL) {
      char *space = strstr(queries[i], " ");
      char *nonTerminal = ++space;
      symbol_table_item_t *item =
          (symbol_table_item_t *)searchSymbol(nonTerminal);
      if (item == NULL)
        error("Symbol not found");
      production_t *production = item->data;
      if (strstr(queries[i], "FIRST") != NULL)
        queryFirst(production);
      else
        queryFollow(production);
    } else if (strstr(queries[i], "PROD") != NULL) {
      char *firstSpace = strstr(queries[i], " ");
      char *nonTerminalStart = firstSpace + 1;
      char *secondSpace = strstr(nonTerminalStart, " ");
      char *nonTerminal = (char *)malloc(4 * sizeof(char));
      strncpy(nonTerminal, nonTerminalStart, secondSpace - nonTerminalStart);
      nonTerminal[secondSpace - firstSpace] = '\0';
      char *terminal = ++secondSpace;
      if (strlen(nonTerminal) == strlen(firstProduction->value) &&
          streq(nonTerminal, firstProduction->value, strlen(nonTerminal)) &&
          streq(terminal, "$", 1)) {
        printf("Accept\n");
        continue;
      }
      symbol_table_item_t *item =
          (symbol_table_item_t *)searchSymbol(nonTerminal);
      if (item == NULL)
        error("Symbol not found");
      production_t *production = item->data;
      queryProd(production, terminal);
    }
  }

  return 0;
}

void createFirstSet(production_t *production) {
  if (production->numFirst > 0)
    return;
  char c;
  char *nonTerminal = (char *)malloc(4 * sizeof(char));
  for (int i = 0; i < production->numRules; i++) {
    int ruleIndex = i;
    char tokenPair[4] = "\0";
    if (streq(production->rules[i], "eps", 3)) {
      production->first[production->numFirst++] = '.';
      continue;
    }

    int j = 0;
    bool nonNullableFound = false;
    while ((c = production->rules[i][j]) != '\0' && isalpha(c) && isupper(c)) {
      if (production->rules[i][++j] == '\'') {
        sprintf(nonTerminal, "%c'", c);
        j++;
      } else
        sprintf(nonTerminal, "%c", c);

      symbol_table_item_t *item =
          (symbol_table_item_t *)searchSymbol(nonTerminal);
      if (item == NULL)
        printf("Symbol not found: %s\n", nonTerminal);

      production_t *nextProduction = item->data;
      if (nextProduction->numFirst == 0)
        createFirstSet(nextProduction);

      for (int k = 0; k < nextProduction->numFirst; k++) {
        production->first[production->numFirst++] = nextProduction->first[k];
        sprintf(tokenPair, "%s%c", production->value,
                production->first[production->numFirst - 1]);
        insertParsingSymbol(tokenPair, ruleIndex);
      }

      bzero(nonTerminal, 4);
      if (!nextProduction->nullable) {
        nonNullableFound = true;
        break;
      }
    }

    if (!nonNullableFound && (c = production->rules[i][j]) != '\0' &&
        !isupper(c)) {
      production->first[production->numFirst++] = c;
      sprintf(tokenPair, "%s%c", production->value,
              production->first[production->numFirst - 1]);
      insertParsingSymbol(tokenPair, ruleIndex);
    }
  }
}

void createFollowSet(production_t *production) {
  int ruleIndex;
  for (int i = 0; i < production->numRules; i++) {
    if (streq(production->rules[i], "eps", 3))
      continue;

    ruleIndex = i;
    int j = strlen(production->rules[i]);
    char c, nextChar = '\0';
    char *nonTerminal = (char *)malloc(4 * sizeof(char));
    production_t *nextProduction = NULL, *prevProduction = NULL;

    while (j-- != 0) {
      c = production->rules[i][j];
      if (c != '\'' && !isupper(c)) {
        nextChar = c;
        prevProduction = NULL;
        continue;
      }

      if (c == '\'')
        sprintf(nonTerminal, "%c'", production->rules[i][--j]);
      else
        sprintf(nonTerminal, "%c", c);

      symbol_table_item_t *item =
          (symbol_table_item_t *)searchSymbol(nonTerminal);
      if (item == NULL)
        error("Symbol not found\n");
      nextProduction = item->data;

      if (nextChar != '\0') {
        nextProduction->follow[nextProduction->numFollow++] = nextChar;
      } else if (prevProduction == NULL &&
                 nextProduction->id != production->id) {
        for (int k = 0; k < production->numFollow; k++) {
          nextProduction->follow[nextProduction->numFollow++] =
              production->follow[k];
        }
      } else if (prevProduction != NULL) {
        for (int k = 0; k < prevProduction->numFirst; k++) {
          nextProduction->follow[nextProduction->numFollow++] =
              prevProduction->first[k];
        }

        if (prevProduction->nullable) {
          for (int k = 0; k < prevProduction->numFollow; k++) {
            nextProduction->follow[nextProduction->numFollow++] =
                prevProduction->follow[k];
          }
        }
      }

      prevProduction = nextProduction;
      nextChar = '\0';
      bzero(nonTerminal, 4);
    }
  }
}

unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash % MAX_PRODUCTIONS;
}

symbol_table_item_t *searchSymbol(char *key) {
  int hashIndex = hash(key);

  while (symbolTable[hashIndex] != NULL) {
    if (symbolTable[hashIndex]->key == hashIndex)
      return symbolTable[hashIndex];

    ++hashIndex;
    hashIndex %= MAX_PRODUCTIONS;
  }

  return NULL;
}

parsing_table_item_t *searchParsingSymbol(char *key) {
  int hashIndex = hash(key);

  while (parsingTable[hashIndex] != NULL) {
    if (parsingTable[hashIndex]->key == hashIndex)
      return parsingTable[hashIndex];

    ++hashIndex;
    hashIndex %= MAX_PRODUCTIONS;
  }

  return NULL;
}

void insertSymbol(char *key, production_t *data) {
  int hashIndex = hash(key);
  symbol_table_item_t *item =
      (symbol_table_item_t *)malloc(sizeof(symbol_table_item_t));
  item->data = data;
  item->key = hashIndex;

  while (symbolTable[hashIndex] != NULL) {
    ++hashIndex;
    hashIndex %= MAX_PRODUCTIONS;
  }

  symbolTable[hashIndex] = item;
}

void insertParsingSymbol(char *key, int data) {
  int hashIndex = hash(key);
  parsing_table_item_t *item =
      (parsing_table_item_t *)malloc(sizeof(parsing_table_item_t));
  item->data = data;
  item->key = hashIndex;

  while (parsingTable[hashIndex] != NULL) {
    ++hashIndex;
    hashIndex %= MAX_PRODUCTIONS;
  }

  parsingTable[hashIndex] = item;
}

bool existsInSet(char set[], int setSize, char ch) {
  for (int i = 0; i < setSize; i++)
    if (set[i] == ch)
      return true;

  return false;
}

int charArrayToSet(char input[], int inputSize, char set[]) {
  int setSize = 0;

  for (int i = 0; i < inputSize; i++)
    if (!existsInSet(set, setSize, input[i]))
      set[setSize++] = input[i];

  return setSize;
}

void queryFirst(production_t *production) {
  printf("{");
  for (int i = 0; i < production->numFirst; i++) {
    if (production->first[i] == '.')
      printf("eps");
    else
      printf("%c", production->first[i]);
    if (i < production->numFirst - 1)
      printf(" , ");
  }
  printf("}\n");
}

void queryFollow(production_t *production) {
  printf("{");
  for (int i = 0; i < production->numFollow; i++) {
    printf("%c", production->follow[i]);
    if (i < production->numFollow - 1)
      printf(" , ");
  }
  printf("}\n");
}

void queryProd(production_t *production, char *terminal) {
  char *tokenPair = (char *)malloc(4 * sizeof(char));
  sprintf(tokenPair, "%s%s", production->value, terminal);
  parsing_table_item_t *item = searchParsingSymbol(tokenPair);
  if (item == NULL)
    printf(".\n");
  else {
    int ruleIndex = item->data;
    if (streq(production->rules[ruleIndex], ".", 1))
      printf("%s -> eps\n", production->value);
    else
      printf("%s -> %s\n", production->value, production->rules[ruleIndex]);
  }
}
