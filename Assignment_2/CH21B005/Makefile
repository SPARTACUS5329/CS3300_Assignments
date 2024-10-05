LEX_FILE = a2.l
YACC_FILE = a2.y
YACC_TAB_C = a2.tab.c
YACC_TAB_H = a2.tab.h

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
