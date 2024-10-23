%{
#include "l6.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void yyerror(char *);
int yylex(void);

char mytext[100];
production_t *currProduction;
static int numAlts = 0;
production_t **productions = NULL;
static int numProductions = 0;
extern char *yytext;
%}

%token PLUS MINUS MULTIPLY DIVIDE
%token UNION SEMI_COLON ASSIGN
%token EPS
%token NON_TERMINAL TERMINAL

%left PLUS MINUS
%left MULTIPLY DIVIDE
%nonassoc TERMINAL NON_TERMINAL

%union {
	char str[MAX_RULE_SIZE];
}

%type <str> alt terminal nonTerminal

%%

program: productions
;

productions: production
	| production productions
;

production: nonTerminalRule ASSIGN altList SEMI_COLON {
		currProduction->numRules = numAlts;
		numAlts = 0;
	}
;

nonTerminalRule: NON_TERMINAL {
		production_t *prod = (production_t *)malloc(sizeof(production_t));
		strcpy(prod->value, mytext);
		productions[numProductions++] = prod;
		currProduction = prod;
	}
;

altList: alt {
		strcpy(currProduction->rules[numAlts++], $1);
	}
	| altList UNION alt {
		strcpy(currProduction->rules[numAlts++], $3);
	}

alt: alt PLUS { strcpy($$, $1); strcat($$, "+"); }
	| alt MINUS { strcpy($$, $1); strcat($$, "-"); }
	| alt MULTIPLY { strcpy($$, $1); strcat($$, "*"); }
	| alt DIVIDE { strcpy($$, $1); strcat($$, "/"); }
	| alt terminal { strcpy($$, $1); strcat($$, $2); }
	| alt nonTerminal { strcpy($$, $1); strcat($$, $2); }
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

int main() {
	productions = (production_t **)malloc(MAX_PRODUCTIONS * sizeof(production_t));
	yyparse();

	production_t **finalProductions = (production_t **)malloc(MAX_PRODUCTIONS * sizeof(production_t));
	int numFinalProductions = 0;

	for (int i = 0; i < numProductions; i++) {
		for (int j = 0; j < i; j++) {
            replaceIndirectLeftRecursion(productions[i], productions[j]);
		}
		finalProductions[numFinalProductions++] = productions[i];
		production_t *newProduction = eliminateImmediateLeftRecursion(productions[i]);
		if (newProduction != NULL)
			finalProductions[numFinalProductions++] = newProduction;
	}

	for (int i = 0; i < numFinalProductions; i++) {
        printf("%s -> ", finalProductions[i]->value);
        for (int j = 0; j < finalProductions[i]->numRules; j++) {
            printf("%s", finalProductions[i]->rules[j]);
            if (j < finalProductions[i]->numRules - 1)
                printf(" | ");
        }
        printf(";\n");
    }
	return 0;
}

void replaceIndirectLeftRecursion(production_t *Ai, production_t *Aj) {
	int i = 0;
	char newRules[MAX_RULES][MAX_RULE_SIZE];
	int numNewRules = 0;

    while (i < Ai->numRules) {
        if (Ai->rules[i][0] != Aj->value[0])  {
			strcpy(newRules[numNewRules++], Ai->rules[i]);
			i++;
			continue;
		}

		char alpha[MAX_RULE_SIZE];
		strcpy(alpha, Ai->rules[i] + 1);

		for (int j = 0; j < Aj->numRules; j++) {
			char newRule[MAX_RULE_SIZE];
			sprintf(newRule, "%s%s", Aj->rules[j], alpha);
			strcpy(newRules[numNewRules++], newRule);
		}
		i++;
    }

	for (int i = 0; i < numNewRules; i++)
		sprintf(Ai->rules[i], "%s", newRules[i]);

	Ai->numRules = numNewRules;
}

production_t *eliminateImmediateLeftRecursion(production_t *Ai) {
    char newProductionValue[4];
	sprintf(newProductionValue, "%c'", Ai->value[0]);

    production_t *newProduction = (production_t *) malloc(sizeof(production_t));
	strcpy(newProduction->value, newProductionValue);
    newProduction->numRules = 0;

    char nonRecursive[MAX_RULES][MAX_RULE_SIZE];
    char recursive[MAX_RULES][MAX_RULE_SIZE];
    int numNonRecursive = 0, numRecursive = 0;

    for (int i = 0; i < Ai->numRules; i++) {
        if (Ai->rules[i][0] == Ai->value[0])
            strcpy(recursive[numRecursive++], Ai->rules[i] + 1);
        else
            strcpy(nonRecursive[numNonRecursive++], Ai->rules[i]);
    }

    if (numRecursive == 0) return NULL;

	Ai->numRules = 0;
	for (int i = 0; i < numNonRecursive; i++) {
		char newRule[MAX_RULE_SIZE];
		sprintf(newRule, "%s%s", nonRecursive[i], newProductionValue);
		strcpy(Ai->rules[Ai->numRules++], newRule);
	}

	for (int i = 0; i < numRecursive; i++) {
		char newRule[MAX_RULE_SIZE];
		sprintf(newRule, "%s%s", recursive[i], newProductionValue);
		strcpy(newProduction->rules[newProduction->numRules++], newRule);
	}

	strcpy(newProduction->rules[newProduction->numRules++], "eps");
	return newProduction;
}
