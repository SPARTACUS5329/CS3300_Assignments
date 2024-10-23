#pragma once
#define MAX_PRODUCTIONS 2000
#define MAX_RULES 2000
#define MAX_RULE_SIZE 2000

typedef struct Production {
  char value[4];
  char rules[MAX_RULES][MAX_RULE_SIZE];
  int numRules;
} production_t;

void replaceIndirectLeftRecursion(production_t *Ai, production_t *Aj);
production_t *eliminateImmediateLeftRecursion(production_t *Ai);
