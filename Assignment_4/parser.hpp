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
     MULTIPLY = 260,
     DIVIDE = 261,
     NOT = 262,
     COMPAR = 263,
     COLON = 264,
     EQ = 265,
     IF = 266,
     GOTO = 267,
     PRINT = 268,
     READ = 269,
     NUMBER_TOK = 270,
     IDENTIFIER_TOK = 271
   };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define MULTIPLY 260
#define DIVIDE 261
#define NOT 262
#define COMPAR 263
#define COLON 264
#define EQ 265
#define IF 266
#define GOTO 267
#define PRINT 268
#define READ 269
#define NUMBER_TOK 270
#define IDENTIFIER_TOK 271




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "a4.y"
{
    int val;
	identifier_t *id;
	line_list_t *lineList;
	line_t *line;
	ass_t *ass;
	u_ass_t *uass;
	exp_t *exp;
	cond_jump_t *condJump;
	uncond_jump_t *ucondJump;
	label_def_t *labelDef;
	io_t *io;
}
/* Line 1529 of yacc.c.  */
#line 95 "parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

