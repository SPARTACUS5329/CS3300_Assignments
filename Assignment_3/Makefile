LEX_FILE = a3.l
YACC_FILE = a3.y
YACC_TAB_C = a3.tab.c
YACC_TAB_H = a3.tab.h

CC = gcc
LEX = flex
YACC = bison
LEX_FLAGS = 
YACC_FLAGS = -d

all: a.out

$(YACC_TAB_C): $(YACC_FILE)
	$(YACC) $(YACC_FLAGS) $(YACC_FILE)

lex.yy.c: $(LEX_FILE)
	$(LEX) $(LEX_FILE)

a.out: lex.yy.c $(YACC_TAB_C)
	$(CC) lex.yy.c $(YACC_TAB_C)

clean:
	rm -f lex.yy.c *.tab.* a.out
