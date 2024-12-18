%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "a4.h"

void yyerror(char *);
char mytext[100];
extern int yylex(void);
extern FILE *yyin;
int lineNumber = 1;

program_t *program;
symbol_table_item_t *labelTable[MAX_LINES];
symbol_table_item_t *symbolTable[MAX_IDENTIFIERS];
%}

%token PLUS MINUS MULTIPLY DIVIDE NOT
%token COMPAR
%token COLON EQ
%token IF GOTO
%token PRINT READ
%token NUMBER_TOK IDENTIFIER_TOK

%union {
    int val;
	identifier_t *id;
	line_list_t *lineList;
	line_t *line;
	ass_t *ass;
	u_ass_t *uass;
	exp_t *exp;
	cond_jump_t *condJump;
	uncond_jump_t *ucondJump;
	label_def_t *labelDef;
	io_t *io;
}

%type <val> number
%type <id> identifier
%type <lineList> lines
%type <line> line
%type <ass> assignmentStatement
%type <uass> unaryAssignmentStatement
%type <exp> expression
%type <condJump> conditionalJump
%type <ucondJump> unconditionalJump
%type <labelDef> labelDefinition
%type <io> ioStatement

%%
program:
    lines {
		program->lineList = $1;
	}
;

lines:
    lines line {
		$2->prev = (line_list_t *)calloc(1, sizeof(line_list_t));
		$2->prev->lines = (line_t **)calloc(MAX_LINES, sizeof(line_t *));
		$2->next = (line_list_t *)calloc(1, sizeof(line_list_t));
		$2->next->lines = (line_t **)calloc(MAX_LINES, sizeof(line_t *));
		$2->in = (id_list_t *)calloc(1, sizeof(id_list_t));
		$2->in->ids = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));
		$2->out = (id_list_t *)calloc(1, sizeof(id_list_t));
		$2->out->ids = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));
		$2->use = (id_list_t *)calloc(1, sizeof(id_list_t));
		$2->use->ids = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));
		$2->def = (id_list_t *)calloc(1, sizeof(id_list_t));
		$2->def->ids = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));

		$1->lines[$1->lineCount++] = $2;
		lineNumber++;
	}
	| {
		line_list_t *lineList = (line_list_t *)calloc(1, sizeof(line_list_t));
		lineList->lines = (line_t **)calloc(MAX_LINES, sizeof(line_t *));
		$$ = lineList;
	}
;

line:
	assignmentStatement {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = ASS;
		line->line.ass = $1;
		line->lineNumber = lineNumber;
		$$ = line;
	}
	| unaryAssignmentStatement {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = UASS;
		line->line.uass = $1;
		line->lineNumber = lineNumber;
		$$ = line;
	}
	| conditionalJump {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = COND_JUMP;
		line->line.condJump = $1;
		line->lineNumber = lineNumber;
		$$ = line;
	}
	| unconditionalJump {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = UNCOND_JUMP;
		line->line.uncondJump = $1;
		line->lineNumber = lineNumber;
		$$ = line;
	}
	| labelDefinition {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = LABEL_DEF;
		line->line.labelDef = $1;
		line->lineNumber = lineNumber;
		insertSymbol(line->line.labelDef->value->value, line, labelTable);
		$$ = line;
	}
	| ioStatement {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = IO;
		line->line.io = $1;
		line->lineNumber = lineNumber;
		$$ = line;
	}
;

assignmentStatement:
    identifier EQ expression {
		ass_t *ass = (ass_t *)calloc(1, sizeof(ass_t));
		ass->id = $1;
		ass->exp = $3;
		$$ = ass;
	}
;

expression:
    identifier operator identifier {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = IDENTIFIER;
		exp->rType = IDENTIFIER;
		exp->isBinOp = true;
		exp->lValue.id = $1;
		exp->rValue.id = $3;
		$$ = exp;
	}
	| identifier operator number {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = IDENTIFIER;
		exp->rType = NUMBER;
		exp->isBinOp = true;
		exp->lValue.id = $1;
		exp->rValue.val = $3;
		$$ = exp;
	}
	| number operator identifier {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = NUMBER;
		exp->rType = IDENTIFIER;
		exp->isBinOp = true;
		exp->lValue.val = $1;
		exp->rValue.id = $3;
		$$ = exp;
	}
	| number operator number {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = NUMBER;
		exp->rType = NUMBER;
		exp->isBinOp = true;
		exp->lValue.val = $1;
		exp->rValue.val = $3;
		$$ = exp;
	}
	| identifier {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = IDENTIFIER;
		exp->isBinOp = false;
		exp->lValue.id = $1;
		$$ = exp;
	}
	| number {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = NUMBER;
		exp->isBinOp = false;
		exp->lValue.val = $1;
		$$ = exp;
	}
;

unaryAssignmentStatement:
    identifier EQ unaryOperator identifier {
		u_ass_t *ass = (u_ass_t *)calloc(1, sizeof(u_ass_t));
		ass->lid = $1;
		ass->rid = $4;
		$$ = ass;
	}
;

unaryOperator:
    MINUS
	| NOT
;

conditionalJump:
    IF identifier COMPAR identifier GOTO identifier {
		cond_jump_t *jump = (cond_jump_t *)calloc(1, sizeof(cond_jump_t));
		jump->lid = $2;
		jump->rid = $4;
		jump->label = $6;
		$$ = jump;
	}
;

unconditionalJump:
    GOTO identifier {
		uncond_jump_t *jump = (uncond_jump_t *)calloc(1, sizeof(uncond_jump_t));
		jump->label = $2;
		$$ = jump;
	}
;

labelDefinition:
    identifier COLON {
		label_def_t *labelDef = (label_def_t *)calloc(1, sizeof(label_def_t));
		labelDef->value = $1;
		$$ = labelDef;
	}
;

ioStatement:
    PRINT identifier {
		io_t *io = (io_t *)calloc(1, sizeof(io_t));
		io->id = $2;
		io->type = IO_PRINT;
		$$ = io;
	}
	| READ identifier {
		io_t *io = (io_t *)calloc(1, sizeof(io_t));
		io->id = $2;
		io->type = IO_READ;
		$$ = io;
	}
;

number:
    NUMBER_TOK {
		$$ = atoi(mytext);
	}
;

identifier:
    IDENTIFIER_TOK {
		symbol_table_item_t *item = searchSymbol(mytext, symbolTable);
		identifier_t *id;
		if (item == NULL) {
			id = (identifier_t *)calloc(1, sizeof(identifier_t));
			strcpy(id->value, mytext);
			insertSymbol(id->value, id, symbolTable);
		} else {
		    id = (identifier_t *) item->data;
		}
		$$ = id;
	}
;

operator:
    PLUS
	| MINUS
	| MULTIPLY
	| DIVIDE
;

%%

void yyerror(char *message) {
    fprintf(stderr, "syntax error: %d\n", lineNumber);
    exit(1);
}

void error(char *message) {
    perror(message);
	exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3)
        error("Incorrect input arguments");

	const char *tacFileName = argv[1];
	const char *queryFileName = argv[2];

    FILE *tacFile = fopen(tacFileName, "r");
    if (tacFile == NULL)
        error("Error opening TAC file");

    program = (program_t *)calloc(1, sizeof(program_t));

	yyin = tacFile;
    yyparse();
	fclose(tacFile);

    FILE *queryFile = fopen(queryFileName, "r");
    if (queryFile == NULL)
        error("Error opening query file");

    int value;
    while (fscanf(queryFile, "%d", &value) == 1)
        program->queries[program->queryCount++] = value;

	constructCFG(program->lineList);
	// stringifyCFG(program->lineList->lines[0], program->lineList->lineCount);

	firstPass(program->lineList);
	secondPass(program->lineList);
	fixupPass(program->lineList);
	flushVisited();

	optimiseTAC(program->lineList->lines[program->lineList->lineCount - 1]);

	resolveQueries();

    return 0;
}

void resolveQueries() {
	int query;
	line_t *line;
	for (int i = 0; i < program->queryCount; i++) {
		query = program->queries[i];
		line = program->lineList->lines[query - 1];
		if (line->isDeleted)
		    printf("Line removed in optimized TAC\n");
		else
		    printSet(line->out);
	}
}

unsigned long hash(char *str) {
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return hash % MAX_IDENTIFIERS;
}

symbol_table_item_t *searchSymbol(char *key, symbol_table_item_t* hashTable[]) {

	int hashIndex = hash(key);

	while(hashTable[hashIndex] != NULL) {
	  if(hashTable[hashIndex]->key == hashIndex)
		 return hashTable[hashIndex]; 
			
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}        

	return NULL;        
}

void insertSymbol(char *key, void *data, symbol_table_item_t* hashTable[]) {
	symbol_table_item_t *item;
	item = searchSymbol(key, hashTable);
	if (item != NULL)
		return;
	int hashIndex = hash(key);
	item = (symbol_table_item_t*) malloc(sizeof(symbol_table_item_t));
	item->data = data;
	item->key = hashIndex;

	while(hashTable[hashIndex] != NULL) {
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}

	hashTable[hashIndex] = item;
}

void constructCFG(line_list_t *lineList) {
	line_t *line;
	line_t *nextLine;
	symbol_table_item_t *item;
    for (int i = 0; i < lineList->lineCount; i++) {
		line = lineList->lines[i];
		if (i < lineList->lineCount - 1)
		    nextLine = lineList->lines[i + 1];
		else
		    nextLine = NULL;

		switch (line->type) {
		case ASS:
			if (nextLine != NULL) {
				line->next->lines[line->next->lineCount++] = nextLine;
				nextLine->prev->lines[nextLine->prev->lineCount++] = line;
			}
		    break;
		case UASS:
			if (nextLine != NULL) {
				line->next->lines[line->next->lineCount++] = nextLine;
				nextLine->prev->lines[nextLine->prev->lineCount++] = line;
			}
		    break;
		case COND_JUMP:
			if (nextLine != NULL) {
				line->next->lines[line->next->lineCount++] = nextLine;
				nextLine->prev->lines[nextLine->prev->lineCount++] = line;
			}
			item = searchSymbol(line->line.condJump->label->value, labelTable);
			nextLine = (line_t *)item->data;
			line->next->lines[line->next->lineCount++] = nextLine;
			nextLine->prev->lines[nextLine->prev->lineCount++] = line;
		    break;
		case UNCOND_JUMP:
			item = searchSymbol(line->line.uncondJump->label->value, labelTable);
			nextLine = (line_t *)item->data;
			line->next->lines[line->next->lineCount++] = nextLine;
			nextLine->prev->lines[nextLine->prev->lineCount++] = line;
		    break;
		case LABEL_DEF:
			if (nextLine != NULL) {
				line->next->lines[line->next->lineCount++] = nextLine;
				nextLine->prev->lines[nextLine->prev->lineCount++] = line;
			}
		    break;
		case IO:
			if (nextLine != NULL) {
				line->next->lines[line->next->lineCount++] = nextLine;
				nextLine->prev->lines[nextLine->prev->lineCount++] = line;
			}
		    break;
		}
	}
}

void dfs(line_t *node, int *visited) {
    if (node == NULL || visited[node->lineNumber]) {
        return;
    }

    visited[node->lineNumber] = 1;

    printf("  Node%d [label=\"Line %d\"];\n", node->lineNumber, node->lineNumber);

    if (node->next != NULL) {
        for (int i = 0; i < node->next->lineCount; i++) {
            line_t *nextLine = node->next->lines[i];
            if (nextLine != NULL) {
                printf("  Node%d -> Node%d;\n", node->lineNumber, nextLine->lineNumber);
                
                dfs(nextLine, visited);
            }
        }
    }
}

void stringifyCFG(line_t *root, int maxNodes) {
    printf("digraph CFG {\n");
    printf("  node [shape=box];\n");

    int *visited = (int *)calloc(maxNodes, sizeof(int));

    dfs(root, visited);

    printf("}\n");

    free(visited);
}

void firstPass(line_list_t *lineList) {
	line_t *line;
    for (int i = 0; i < lineList->lineCount; i++) {
		line = lineList->lines[i];
		computeUseDefSets(line);
	}
}

void secondPass(line_list_t *lineList) {
	line_t *line;
	bool printFound = false;
	for (int i = lineList->lineCount - 1; i >= 0; i--) {
		line = lineList->lines[i];
		if ((line->type != IO || line->line.io->type == IO_READ) && !printFound) {
			line->isDeleted = true;
			continue;
		}

		printFound = true;
		computeOutSet(line);
		computeInSet(line);
	}
}

void fixupPass(line_list_t *lineList) {
	line_t *line;
    for (int i = 0; i < lineList->lineCount; i++) {
		line = lineList->lines[i];
		if (line->type == COND_JUMP || line->type == UNCOND_JUMP) {
		    computeOutSet(line);
		    computeInSet(line);
			for (int j = 0; j < line->prev->lineCount; j++) {
				backProp(line->prev->lines[j]);
				flushVisited();
		    }
		}
	}
}

void computeOutSet(line_t *line) {
	line->out->idCount = 0;
	line_t *nextLine;
    for (int i = 0; i < line->next->lineCount; i++) {
		nextLine = line->next->lines[i];
		combineSets(line->out, nextLine->in);
	}
}

void computeInSet(line_t *line) {
	line->in->idCount = 0;
    combineSets(line->in, line->use);
	id_list_t *outDefDiff = diffSets(line->out, line->def);
    combineSets(line->in, outDefDiff);
}

void combineSets(id_list_t *set1, id_list_t *set2) {
	identifier_t *id;
    for (int i = 0; i < set2->idCount; i++) {
		bool elementFound = false;
		id = set2->ids[i];
		for (int j = 0; j < set1->idCount; j++) {
		    if (set1->ids[j] == id) {
				elementFound = true;
				break;
			}
		}
		if (!elementFound) {
		    set1->ids[set1->idCount++] = id;
		}
	}
}

id_list_t *diffSets(id_list_t *set1, id_list_t *set2) {
	id_list_t *idList = (id_list_t *)calloc(1, sizeof(id_list_t));
	idList->ids = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));
	identifier_t *id;
    for (int i = 0; i < set1->idCount; i++) {
		bool elementFound = false;
		id = set1->ids[i];
		for (int j = 0; j < set2->idCount; j++) {
		    if (set2->ids[j] == id) {
				elementFound = true;
				break;
			}
		}
		if (!elementFound)
		    idList->ids[idList->idCount++] = id;
	}
	return idList;
}

void printSet(id_list_t *idList) {
	qsort(idList->ids, idList->idCount, sizeof(identifier_t *), compareLex);
    for (int i = 0; i < idList->idCount; i++)
		printf("%s ", idList->ids[i]->value);
    printf("\n");
}

void optimiseTAC(line_t *line) {
	if (line->optimised)
		return;

	line->optimised = true;
    if (removable(line)) {
		deleteLine(line);
		for (int i = 0; i < line->prev->lineCount; i++) {
		    backProp(line->prev->lines[i]);
			flushVisited();
		}
	}
	for (int i = 0; i < line->prev->lineCount; i++) {
		optimiseTAC(line->prev->lines[i]);
	}
}

void flushVisited() {
    for (int i = 0; i < program->lineList->lineCount; i++)
		program->lineList->lines[i]->visited = false;
}

bool removable(line_t *line) {
    if (line->type != ASS && line->type != UASS)
		return false;

    identifier_t *defElement = line->def->ids[0];
	for (int i = 0; i < line->out->idCount; i++)
		if (line->out->ids[i] == defElement)
		    return false;

    return true;
}

void backProp(line_t *line) {
	if (line->visited)
		return;

	line->visited = true;
	computeUseDefSets(line);
	computeOutSet(line);
	computeInSet(line);
	for (int i = 0; i < line->prev->lineCount; i++)
		backProp(line->prev->lines[i]);
}

void computeUseDefSets(line_t *line) {
	line->use->idCount = 0;
	line->def->idCount = 0;

    if (line->type == ASS) {
	    line->def->ids[line->def->idCount++] = line->line.ass->id;
	    if (line->line.ass->exp->lType == IDENTIFIER)
		    line->use->ids[line->use->idCount++] = line->line.ass->exp->lValue.id;
	    if (line->line.ass->exp->isBinOp && line->line.ass->exp->rType == IDENTIFIER)
		    line->use->ids[line->use->idCount++] = line->line.ass->exp->rValue.id;
    } else if (line->type == IO && line->line.io->type == IO_READ) {
	    line->def->ids[line->def->idCount++] = line->line.io->id;
    } else if (line->type == IO && line->line.io->type == IO_PRINT) {
	    line->use->ids[line->use->idCount++] = line->line.io->id;
    } else if (line->type == UASS) {
	    line->def->ids[line->def->idCount++] = line->line.uass->lid;
	    line->use->ids[line->use->idCount++] = line->line.uass->rid;
    } else if (line->type == COND_JUMP) {
	    line->use->ids[line->use->idCount++] = line->line.condJump->lid;
	    line->use->ids[line->use->idCount++] = line->line.condJump->rid;
    }
}

void deleteLine(line_t *line) {
    line->isDeleted = true;
	line->in->idCount = 0;
	line->out->idCount = 0;
	line->use->idCount = 0;
	line->def->idCount = 0;

	line_t *prevLine = line->prev->lines[0];
	line_t *nextLine = line->next->lines[0];

	if (prevLine != NULL) {
		for (int i = 0; i < prevLine->next->lineCount; i++) {
			if (prevLine->next->lines[i] != line)
				continue;

		    if (nextLine != NULL) {
				prevLine->next->lines[i] = nextLine;
		    } else {
				prevLine->next->lines[i] = prevLine->next->lines[prevLine->next->lineCount - 1];
				prevLine->next->lineCount--;
		    }
			break;
		}
	}

	if (nextLine != NULL) {
		for (int i = 0; i < nextLine->prev->lineCount; i++) {
			if (nextLine->prev->lines[i] != line)
				continue;

		    if (prevLine != NULL) {
				nextLine->prev->lines[i] = prevLine;
		    } else {
				nextLine->prev->lines[i] = nextLine->prev->lines[nextLine->prev->lineCount - 1];
				nextLine->prev->lineCount--;
		    }
			break;
		}
	}
}

int compareLex(const void *a, const void *b) {
    identifier_t *idA = *(identifier_t **)a;
    identifier_t *idB = *(identifier_t **)b;
    return strcmp(idA->value, idB->value);
}
