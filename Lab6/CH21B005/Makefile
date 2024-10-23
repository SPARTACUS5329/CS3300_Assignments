LEX = flex
YACC = bison -d
CC = gcc
LEX_SRC = l6.l
YACC_SRC = l6.y
LEX_OUT = lex.yy.c
YACC_OUT = l6.tab.c
YACC_HEADER = l6.tab.h
LIBS = -ll -ly

all: $(LEX_OUT) $(YACC_OUT)
	$(CC) $(LEX_OUT) $(YACC_OUT) $(LIBS)

$(LEX_OUT): $(LEX_SRC)
	$(LEX) $(LEX_SRC)

$(YACC_OUT): $(YACC_SRC)
	$(YACC) $(YACC_SRC)

clean:
	rm -f $(LEX_OUT) $(YACC_OUT) $(YACC_HEADER) a.out
