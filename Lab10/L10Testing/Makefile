LEX = flex
YACC = bison -d
CC = gcc
LEX_SRC = l10.l
YACC_SRC = l10.y
LEX_OUT = lex.yy.c
YACC_OUT = l10.tab.c
YACC_HEADER = l10.tab.h

all: $(LEX_OUT) $(YACC_OUT)
	$(CC) $(LEX_OUT) $(YACC_OUT)

$(LEX_OUT): $(LEX_SRC)
	$(LEX) $(LEX_SRC)

$(YACC_OUT): $(YACC_SRC)
	$(YACC) $(YACC_SRC)

clean:
	rm -f $(LEX_OUT) $(YACC_OUT) $(YACC_HEADER) a.out
