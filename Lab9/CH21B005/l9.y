%{
#include "l9.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void yyerror(char *);
int yylex(void);

char mytext[100];
extern char *yytext;
definition_t **definitions;
query_t **queries;
static int definitionCount = 0;
static int queryCount = 0;
def_table_item_t *defTable[MAX_DEFINITIONS];
var_table_item_t *varTable[MAX_VARIABLES];
%}

%token PLUS MINUS EXPONENT
%token EQ COLON COMMA
%token VARIABLE NUMBER IDENTIFIER

%left PLUS MINUS
%right UPLUS UMINUS

%union {
	char *str;
	char c;
	int val;
	expression_t *exp;
	term_t *term;
	arg_list_t *argList;
	arg_t *arg;
}

%type <str> identifier
%type <val> coefficient power
%type <c> variable
%type <exp> expression
%type <term> term
%type <argList> args
%type <arg> arg

%%

program:
	definitions queries
;

definitions:
	definition
	| definitions definition
;

definition:
	identifier EQ expression {
		definition_t *def = (definition_t *)malloc(sizeof(definition_t));
		strcpy(def->identifier, $1);
		def->exp = $3;
		definitions[definitionCount++] = def;
		insertDefinition(def->identifier, def);
	}
;

expression:
	expression PLUS expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->terms = (term_t **)malloc(MAX_TERMS * sizeof(term_t *));
		for (int i = 0; i < $1->termCount; i++)
			exp->terms[exp->termCount++] = $1->terms[i];
		for (int i = 0; i < $3->termCount; i++)
			exp->terms[exp->termCount++] = $3->terms[i];
		$$ = exp;
	}
	| expression MINUS expression {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->terms = (term_t **)malloc(MAX_TERMS * sizeof(term_t *));
		for (int i = 0; i < $1->termCount; i++)
			exp->terms[exp->termCount++] = $1->terms[i];
		for (int i = 0; i < $3->termCount; i++) {
			term_t *term = (term_t *)malloc(sizeof(term_t));
			term_t *oldTerm = $3->terms[i];
			term->coefficient = -oldTerm->coefficient;
			term->variable = oldTerm->variable;
			term->power = oldTerm->power;
			term->isConstant = oldTerm->isConstant;
			exp->terms[exp->termCount++] = term;
		}
		$$ = exp;
	}
	| PLUS expression %prec UPLUS {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->terms = (term_t **)malloc(MAX_TERMS * sizeof(term_t *));
		for (int i = 0; i < $2->termCount; i++)
			exp->terms[exp->termCount++] = $2->terms[i];
		$$ = exp;
	}
	| MINUS expression %prec UMINUS {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->terms = (term_t **)malloc(MAX_TERMS * sizeof(term_t *));
		for (int i = 0; i < $2->termCount; i++) {
			term_t *term = (term_t *)malloc(sizeof(term_t));
			term_t *oldTerm = $2->terms[i];
			term->coefficient = -oldTerm->coefficient;
			term->variable = oldTerm->variable;
			term->power = oldTerm->power;
			term->isConstant = oldTerm->isConstant;
			exp->terms[exp->termCount++] = term;
		}
		$$ = exp;
	}
	| term {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->terms = (term_t **)malloc(MAX_TERMS * sizeof(term_t *));
		exp->terms[exp->termCount++] = $1;
		$$ = exp;
	}
	| identifier {
		def_table_item_t *item = searchDefinition($1);
		if (item == NULL)
			error("Undefined identifier");
		$$ = item->data->exp;
	}
;

term:
	coefficient variable power {
		term_t *term = (term_t *)malloc(sizeof(term_t));
		term->coefficient = $1;
		if ($2 == '\0')
			term->isConstant = true;
		term->variable = $2;
		term->power = $3;
		$$ = term;
	}
	| coefficient {
		term_t *term = (term_t *)malloc(sizeof(term_t));
		term->coefficient = $1;
		term->isConstant = true;
		$$ = term;
	}
	| variable power {
		term_t *term = (term_t *)malloc(sizeof(term_t));
		term->coefficient = 1;
		term->variable = $1;
		term->power = $2;
		$$ = term;
	}
;

coefficient:
	NUMBER {
		$$ = atoi(mytext);
	}
;

variable:
	VARIABLE {
		$$ = mytext[0];
	}
;

power:
	EXPONENT NUMBER {
		$$ = atoi(mytext);
	}
	| {
		$$ = 1;
	}
;

queries:
	| query queries 
;

query:
	identifier COLON args {
		query_t *query = (query_t *)malloc(sizeof(query_t));
		strcpy(query->identifier, $1);
		query->args = $3->args;
		query->argCount = $3->argCount;
		queries[queryCount++] = query;
	}
;

args:
	arg {
		arg_list_t *argList = (arg_list_t *)malloc(sizeof(arg_list_t));
		argList->args = (arg_t **)malloc(MAX_ARGS * sizeof(arg_t));
		if ($1 != NULL) {
			argList->args[argList->argCount++] = $1;
		}
		$$ = argList;
	}
	| arg COMMA args {
		if ($1 != NULL) {
			$3->args[$3->argCount++] = $1;
		}
		$$ = $3;
	}
;

arg:
	variable EQ NUMBER {
		arg_t *arg = (arg_t *)malloc(sizeof(arg_t));
		arg->variable = $1;
		arg->value = atoi(mytext);
		$$ = arg;
	}
	| {
		$$ = NULL;
	}
;

identifier:
	IDENTIFIER {
		$$ = (char *)malloc(MAX_IDENTIFIER_LENGTH * sizeof(char));
		strcpy($$, mytext);
	}
;

%%

void yyerror(char *message) {
	fprintf(stderr, "syntax error\n");
	exit(1);
}

void error(char *message) {
	perror(message);
	exit(1);
}

int main() {
	definitions = (definition_t **)malloc(MAX_DEFINITIONS * sizeof(definition_t *));
	queries = (query_t **)malloc(MAX_QUERIES * sizeof(query_t *));
	yyparse();
	for (int i = 0; i < queryCount; i++) {
		int result = 0;
		query_t *query = queries[i];
		for (int j = 0; j < query->argCount; j++) {
			arg_t *arg = query->args[j];
			insertVar(&arg->variable, arg->value);
		}
		def_table_item_t *defItem = searchDefinition((char *) &query->identifier);
		if (defItem == NULL)
			error("Undefined identifier");
		definition_t *def  = defItem->data;
		expression_t *exp = def->exp;
		for (int j = 0; j < exp->termCount; j++) {
			term_t *term = exp->terms[j];
			if (term->isConstant) {
				result += term->coefficient;
				continue;
			}
			var_table_item_t *varItem = searchVar((char *) &term->variable);
			if (varItem == NULL)
				error("Invalid variable");
			int termValue = varItem->data;
			result += term->coefficient * pow(termValue, term->power);
		}
		printf("%s: %d\n", query->identifier, result);
	}
	return 0;
}

unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash % MAX_DEFINITIONS;
}

def_table_item_t *searchDefinition(char *key) {
  int hashIndex = hash(key);

  while (defTable[hashIndex] != NULL) {
    if (defTable[hashIndex]->key == hashIndex)
      return defTable[hashIndex];

    ++hashIndex;
    hashIndex %= MAX_DEFINITIONS;
  }

  return NULL;
}   

void insertDefinition(char *key, definition_t *data) {
  int hashIndex = hash(key);
  def_table_item_t *item =
      (def_table_item_t *)malloc(sizeof(def_table_item_t));
  item->data = data;
  item->key = hashIndex;

  while (defTable[hashIndex] != NULL) {
    ++hashIndex;
    hashIndex %= MAX_DEFINITIONS;
  }

  defTable[hashIndex] = item;
}

var_table_item_t *searchVar(char *key) {
  int hashIndex = hash(key);

  while (varTable[hashIndex] != NULL) {
    if (varTable[hashIndex]->key == hashIndex)
      return varTable[hashIndex];

    ++hashIndex;
    hashIndex %= MAX_VARIABLES;
  }

  return NULL;
}   

void insertVar(char *key, int data) {
  var_table_item_t *item = searchVar(key);
  if (item != NULL) {
	item->data = data;
	return;
  }
  int hashIndex = hash(key);
  item =
      (var_table_item_t *)malloc(sizeof(var_table_item_t));
  item->data = data;
  item->key = hashIndex;

  while (varTable[hashIndex] != NULL) {
    ++hashIndex;
    hashIndex %= MAX_VARIABLES;
  }

  varTable[hashIndex] = item;
}
