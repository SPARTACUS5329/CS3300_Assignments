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
     LT = 260,
     EQ = 261,
     OPEN_PAREN = 262,
     CLOSE_PAREN = 263,
     OPEN_BRACE = 264,
     CLOSE_BRACE = 265,
     IF = 266,
     ELSE = 267,
     WHILE = 268,
     PRINT = 269,
     VARIABLE = 270,
     NUMBER = 271
   };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define LT 260
#define EQ 261
#define OPEN_PAREN 262
#define CLOSE_PAREN 263
#define OPEN_BRACE 264
#define CLOSE_BRACE 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define PRINT 269
#define VARIABLE 270
#define NUMBER 271




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "l10.y"
{
	char *str;
	int val;
	line_list_t *lineList;
	line_t *line;
	expression_t *exp;
	if_else_t *ifElse;
	condition_t *con;
}
/* Line 1529 of yacc.c.  */
#line 91 "l10.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

