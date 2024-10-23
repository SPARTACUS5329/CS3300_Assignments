LEX = flex
YACC = bison -d
CC = gcc
LEX_SRC = l4.l
YACC_SRC = l4.y
LEX_OUT = lex.yy.c
YACC_OUT = l4.tab.c
YACC_HEADER = l4.tab.h
LIBS = -ll -ly

all: $(LEX_OUT) $(YACC_OUT)
	$(CC) $(LEX_OUT) $(YACC_OUT) $(LIBS)

$(LEX_OUT): $(LEX_SRC)
	$(LEX) $(LEX_SRC)

$(YACC_OUT): $(YACC_SRC)
	$(YACC) $(YACC_SRC)

clean:
	rm -f $(LEX_OUT) $(YACC_OUT) $(YACC_HEADER) a.out
