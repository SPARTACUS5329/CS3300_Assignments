l3: l3.l l3.y
	bison -d l3.y
	flex l3.l
	g++ -o $@ l3.tab.c lex.yy.c -lfl
