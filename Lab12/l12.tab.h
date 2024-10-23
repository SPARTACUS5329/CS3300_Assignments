/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PLUS = 258,
     MINUS = 259,
     COMPAR = 260,
     RETURN = 261,
     INT = 262,
     MAIN = 263,
     EQ = 264,
     OPEN_PAREN = 265,
     CLOSE_PAREN = 266,
     OPEN_BRACE = 267,
     CLOSE_BRACE = 268,
     SEMI_COLON = 269,
     SHORT_OR = 270,
     SHORT_AND = 271,
     VOID = 272,
     IF = 273,
     ELSE = 274,
     IDENTIFIER = 275,
     NUMBER = 276,
     DEAD_TOK = 277,
     REACHABLE_TOK = 278,
     SELF_RECURSIVE_TOK = 279,
     EVENTUALLY_RECURSIVE_TOK = 280,
     CO_RECURSIVE_TOK = 281,
     DEPTH_TOK = 282,
     COMMA = 283,
     SEPARATOR = 284
   };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define COMPAR 260
#define RETURN 261
#define INT 262
#define MAIN 263
#define EQ 264
#define OPEN_PAREN 265
#define CLOSE_PAREN 266
#define OPEN_BRACE 267
#define CLOSE_BRACE 268
#define SEMI_COLON 269
#define SHORT_OR 270
#define SHORT_AND 271
#define VOID 272
#define IF 273
#define ELSE 274
#define IDENTIFIER 275
#define NUMBER 276
#define DEAD_TOK 277
#define REACHABLE_TOK 278
#define SELF_RECURSIVE_TOK 279
#define EVENTUALLY_RECURSIVE_TOK 280
#define CO_RECURSIVE_TOK 281
#define DEPTH_TOK 282
#define COMMA 283
#define SEPARATOR 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 40 "l12.y"
{
	char *str;
	int val;
	cmp_e cmp;
	fun_t *fun;
	fun_list_t *funList;
	query_list_t *queryList;
	query_t *query;
}
/* Line 1529 of yacc.c.  */
#line 117 "l12.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

