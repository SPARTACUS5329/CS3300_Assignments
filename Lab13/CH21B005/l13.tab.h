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
     STAR_TOK = 258,
     AND_TOK = 259,
     EQ = 260,
     SEMI_COLON = 261,
     COMMA = 262,
     IDENTIFIER = 263,
     POINTSTO_TOK = 264,
     PRINTSET_TOK = 265,
     DEREFERENCEABLE_TOK = 266,
     SEPARATOR = 267
   };
#endif
/* Tokens.  */
#define STAR_TOK 258
#define AND_TOK 259
#define EQ 260
#define SEMI_COLON 261
#define COMMA 262
#define IDENTIFIER 263
#define POINTSTO_TOK 264
#define PRINTSET_TOK 265
#define DEREFERENCEABLE_TOK 266
#define SEPARATOR 267




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "l13.y"
{
	char *str;
	int val;
	identifier_t *id;
	ass_t *ass;
	ass_list_t *assList;
	query_t *query;
	query_list_t *queryList;
}
/* Line 1529 of yacc.c.  */
#line 83 "l13.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

