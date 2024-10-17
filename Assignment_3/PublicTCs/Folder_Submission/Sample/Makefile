# Makefile for compiling and running a3.y and a3.l

## Usage Instructions
# make 			(To just Compile)
# make run		(To Compile and run)
# make clear	(To clear all compiled files)
# make fresh	(To clear all compiled files and compile again)
# make freshRun (To clear all compiled files ,   compile again and run)

## ## ## ## ## ## ## ##


# Compiler
CC = g++

# Bison and Flex
BISON = bison
FLEX = flex

# Output executable name
OUTPUT = a.out

# Compiler flags
CFLAGS = -O3 -std=c++20

# Name of File
NAME = a3
INP = a3.c

all: $(OUTPUT)

$(OUTPUT): $(NAME).tab.c lex.yy.c
	$(CC) -o $(OUTPUT) $(CFLAGS) $(NAME).tab.c lex.yy.c

$(NAME).tab.c: $(NAME).y
	$(BISON) -d $(NAME).y

lex.yy.c: $(NAME).l
	$(FLEX) $(NAME).l 

clean:
	rm -f $(OUTPUT) $(NAME).tab.c $(NAME).tab.h lex.yy.c

run: $(OUTPUT)
	./$(OUTPUT) < $(INP)

clear:
	rm -f $(OUTPUT) $(NAME).tab.c $(NAME).tab.h lex.yy.c
	@clear

fresh: clear all

freshRun: fresh run

.PHONY: all clean run
