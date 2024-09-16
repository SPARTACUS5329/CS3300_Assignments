a.out: a1.tab.c lex.yy.c
	g++ -O3 lex.yy.c a1.tab.c

a1.tab.c: a1.y
	bison -d a1.y

lex.yy.c: a1.l a1.tab.h
	flex a1.l

clean:
	@rm lex.yy.c a1.tab.h a1.tab.c a.exe
