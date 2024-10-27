/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OPEN_PAREN = 258,
     CLOSE_PAREN = 259,
     OPEN_BRACE = 260,
     CLOSE_BRACE = 261,
     OPEN_SQUARE = 262,
     CLOSE_SQUARE = 263,
     COMMA = 264,
     COMPAR = 265,
     SEMI_COLON = 266,
     EQ = 267,
     PLUS_TOK = 268,
     MINUS_TOK = 269,
     MULTIPLY_TOK = 270,
     DIVIDE_TOK = 271,
     EXPONENT_TOK = 272,
     VALID_TYPE = 273,
     IDENTIFIER = 274,
     NUMBER = 275,
     STRING_TOK = 276,
     CHAR_TOK = 277,
     SHORT_AND_TOK = 278,
     SHORT_OR_TOK = 279,
     NOT_TOK = 280,
     IF_TOK = 281,
     ELSE_TOK = 282,
     WHILE_TOK = 283,
     FOR_TOK = 284,
     RETURN_TOK = 285,
     MAIN = 286,
     INCLUDE = 287,
     LIB_NAME = 288,
     UPLUS = 289,
     UMINUS = 290
   };
#endif
/* Tokens.  */
#define OPEN_PAREN 258
#define CLOSE_PAREN 259
#define OPEN_BRACE 260
#define CLOSE_BRACE 261
#define OPEN_SQUARE 262
#define CLOSE_SQUARE 263
#define COMMA 264
#define COMPAR 265
#define SEMI_COLON 266
#define EQ 267
#define PLUS_TOK 268
#define MINUS_TOK 269
#define MULTIPLY_TOK 270
#define DIVIDE_TOK 271
#define EXPONENT_TOK 272
#define VALID_TYPE 273
#define IDENTIFIER 274
#define NUMBER 275
#define STRING_TOK 276
#define CHAR_TOK 277
#define SHORT_AND_TOK 278
#define SHORT_OR_TOK 279
#define NOT_TOK 280
#define IF_TOK 281
#define ELSE_TOK 282
#define WHILE_TOK 283
#define FOR_TOK 284
#define RETURN_TOK 285
#define MAIN 286
#define INCLUDE 287
#define LIB_NAME 288
#define UPLUS 289
#define UMINUS 290




/* Copy the first part of user declarations.  */
#line 1 "a3.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "a3.h"

void yyerror(char *);
int yylex(void);
char mytext[100];
char currType[10];
char currScope[MAX_IDENTIFIER_LENGTH] = "global";
char currTACFunction[MAX_IDENTIFIER_LENGTH] = "global";
expression_t args[MAX_FUNCTION_CALLS][MAX_ARGS];
int lineNumber = 1;
static int tCount = 1;
static int lCount = 1;
static int globalDataCount = 0;

symbol_table_item_t *symbolTable[MAX_IDENTIFIERS];
program_t *program;
tac_list_t *tacList;
x86_list_t *x86List;
x86_location_t *EBP_REGISTER, *ESP_REGISTER, *EAX_REGISTER, *EBX_REGISTER, *ECX_REGISTER, *EDX_REGISTER, *ZEROF_REGISTER, *ONE;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 48 "a3.y"
{
	char *str;
	int val;
	identifier_t *id;
	subscript_list_t *subscriptList;
	expression_t *exp; 
	line_t *line;
	line_list_t *lineList;
	declaration_statement_t *declarationStatement;
	assignment_statement_t *assignmentStatement;
	if_else_statement_t *ifElseStatement;
	return_statement_t *returnStatement;
	loop_statement_t *loopStatement;
	function_def_t *funDef;
	combined_function_definitions_t *combinedFunDefList;
	while_loop_t *whileLoop;
	for_loop_t *forLoop;
	declaration_list_t *decList;
	declaration_t *dec;
	function_call_t *funCall;
	arg_t *arg;
	param_t *param;
	arg_list_t *argList;
	param_list_t *paramList;
	data_type_e dataType;
	condition_t *con;
}
/* Line 193 of yacc.c.  */
#line 222 "a3.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 235 "a3.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   266

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    13,    14,    17,    19,    26,
      28,    31,    32,    34,    36,    39,    41,    43,    45,    47,
      51,    53,    57,    61,    63,    68,    70,    73,    75,    78,
      82,    85,    90,    92,    96,    97,    99,   101,   105,   109,
     113,   117,   121,   124,   127,   131,   133,   135,   142,   144,
     148,   151,   153,   157,   158,   161,   169,   175,   179,   183,
     186,   190,   194,   196,   198,   200,   202,   208,   219,   221,
     225,   227,   230,   232,   234,   236,   238
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    39,    40,    -1,    32,    33,    -1,
      39,    45,    -1,    -1,    56,    40,    -1,    41,    -1,    70,
      42,     3,    59,     4,    67,    -1,    31,    -1,    43,    44,
      -1,    -1,    45,    -1,    48,    -1,    55,    11,    -1,    58,
      -1,    61,    -1,    64,    -1,    56,    -1,    70,    46,    11,
      -1,    47,    -1,    47,     9,    46,    -1,    49,    12,    55,
      -1,    49,    -1,    49,    12,    63,    11,    -1,    71,    -1,
      71,    50,    -1,    51,    -1,    50,    51,    -1,     7,    55,
       8,    -1,     7,     8,    -1,    71,     3,    53,     4,    -1,
      54,    -1,    53,     9,    54,    -1,    -1,    55,    -1,    21,
      -1,    55,    13,    55,    -1,    55,    14,    55,    -1,    55,
      15,    55,    -1,    55,    16,    55,    -1,    55,    17,    55,
      -1,    13,    55,    -1,    14,    55,    -1,     3,    55,     4,
      -1,    52,    -1,    68,    -1,    70,    57,     3,    59,     4,
      67,    -1,    71,    -1,    30,    63,    11,    -1,    30,    11,
      -1,    60,    -1,    59,     9,    60,    -1,    -1,    70,    49,
      -1,    26,     3,    62,     4,    67,    27,    67,    -1,    26,
       3,    62,     4,    67,    -1,    62,    23,    62,    -1,    62,
      24,    62,    -1,    25,    62,    -1,     3,    62,     4,    -1,
      55,    69,    55,    -1,    55,    -1,    62,    -1,    65,    -1,
      66,    -1,    28,     3,    62,     4,    67,    -1,    29,     3,
      48,    62,    11,    49,    12,    55,     4,    67,    -1,    44,
      -1,     5,    43,     6,    -1,    71,    -1,    71,    50,    -1,
      20,    -1,    22,    -1,    10,    -1,    18,    -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   118,   122,   130,   139,   143,   152,   163,
     169,   173,   183,   190,   197,   204,   211,   218,   225,   235,
     245,   251,   258,   264,   272,   289,   312,   343,   350,   357,
     360,   369,   380,   385,   389,   396,   402,   412,   424,   436,
     448,   460,   472,   479,   486,   489,   497,   524,   535,   542,
     548,   556,   563,   567,   576,   585,   594,   605,   612,   619,
     625,   628,   661,   664,   670,   677,   687,   697,   714,   721,
     727,   733,   740,   748,   759,   765,   776
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPEN_PAREN", "CLOSE_PAREN",
  "OPEN_BRACE", "CLOSE_BRACE", "OPEN_SQUARE", "CLOSE_SQUARE", "COMMA",
  "COMPAR", "SEMI_COLON", "EQ", "PLUS_TOK", "MINUS_TOK", "MULTIPLY_TOK",
  "DIVIDE_TOK", "EXPONENT_TOK", "VALID_TYPE", "IDENTIFIER", "NUMBER",
  "STRING_TOK", "CHAR_TOK", "SHORT_AND_TOK", "SHORT_OR_TOK", "NOT_TOK",
  "IF_TOK", "ELSE_TOK", "WHILE_TOK", "FOR_TOK", "RETURN_TOK", "MAIN",
  "INCLUDE", "LIB_NAME", "UPLUS", "UMINUS", "$accept", "program", "libs",
  "globalDeclarations", "functionDefinitions", "mainFunction",
  "mainIdentifier", "lines", "line", "declarationStatement",
  "declarations", "declaration", "assignmentStatement", "assignable",
  "subscripts", "subscript", "functionCall", "arguments", "argument",
  "expression", "functionDefinition", "functionIdentifier",
  "returnStatement", "parameters", "parameter", "ifStatement", "condition",
  "computable", "loopStatement", "whileStatement", "forStatement", "body",
  "term", "compar", "validType", "identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    39,    39,    40,    40,    41,    42,
      43,    43,    44,    44,    44,    44,    44,    44,    44,    45,
      46,    46,    47,    47,    48,    49,    49,    50,    50,    51,
      51,    52,    53,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    57,    58,
      58,    59,    59,    59,    60,    61,    61,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    65,    66,    67,    67,
      68,    68,    68,    68,    69,    70,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     0,     2,     1,     6,     1,
       2,     0,     1,     1,     2,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     4,     1,     2,     1,     2,     3,
       2,     4,     1,     3,     0,     1,     1,     3,     3,     3,
       3,     3,     2,     2,     3,     1,     1,     6,     1,     3,
       2,     1,     3,     0,     2,     7,     5,     3,     3,     2,
       3,     3,     1,     1,     1,     1,     5,    10,     1,     3,
       1,     2,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     3,     1,     0,    75,     2,     7,
       4,     0,     0,     6,     0,    76,     9,     0,     0,    20,
      23,     0,    25,    48,    53,    19,     0,     0,    53,     0,
      26,    27,     0,    51,     0,    21,    25,     0,     0,     0,
      72,    73,    45,    22,    46,    70,     0,    30,     0,    28,
       0,     0,    54,     0,    42,    43,     0,     0,     0,     0,
       0,    34,    71,     0,    29,    11,     0,     0,     0,     0,
      68,    12,    13,     0,     0,    18,    15,    16,    17,    64,
      65,     8,     0,    70,    52,    44,    37,    38,    39,    40,
      41,    36,     0,    32,    35,    47,     0,     0,     0,     0,
       0,    50,     0,    62,    63,     0,     0,    14,    71,    31,
       0,    69,    10,     0,     0,     0,     0,     0,     0,    59,
      74,     0,     0,     0,    49,     0,    33,     0,     0,     0,
      60,    61,    57,    58,    24,    56,    66,     0,     0,     0,
      55,     0,     0,     0,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,     8,     9,    17,    96,    70,    71,
      18,    19,    72,    73,    30,    31,    42,    92,    93,    74,
      75,    21,    76,    32,    33,    77,   104,   105,    78,    79,
      80,    81,    44,   121,    82,    45
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -54
static const yytype_int16 yypact[] =
{
     -27,    -4,    50,   -54,   -54,   -54,    34,   -54,   -54,   -54,
     -54,    34,   -10,   -54,   -10,   -54,   -54,    59,    54,    67,
      55,    78,    56,   -54,    34,   -54,    63,   208,    34,   184,
      81,   -54,     3,   -54,    63,   -54,    81,   208,   208,   208,
     -54,   -54,   -54,   249,   -54,    57,     4,   -54,   237,   -54,
     127,    34,   -54,   120,    69,    69,   208,   208,   208,   208,
     208,   196,    81,   127,   -54,   -54,    88,    89,    93,    58,
     -54,   -54,   -54,    92,   244,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,    63,    86,   -54,   -54,    85,    85,    69,    69,
      69,   -54,    28,   -54,   249,   -54,   145,   169,   169,    63,
     169,   -54,   169,    95,    -8,   103,   169,   -54,    36,   -54,
     196,   -54,   -54,    95,     7,    16,   169,   219,    23,   -54,
     -54,   208,   169,   169,   -54,   106,   -54,   127,   127,    -5,
     -54,   249,   -54,    83,   -54,    94,   -54,    63,   127,   110,
     -54,   208,   227,   127,   -54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,   -54,   -54,   112,   -54,   -54,   -54,    31,   123,
     113,   -54,    43,    -9,   -41,   -29,   -54,   -54,    33,    -3,
      38,   -54,   -54,   116,    99,   -54,    79,    46,   -54,   -54,
     -54,   -53,   -54,   -54,    17,   -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const yytype_int16 yytable[] =
{
      22,    49,    23,    20,    62,     1,   137,    50,    63,    15,
      95,   127,    51,    51,    36,   122,   123,    20,   122,   123,
     128,    16,    36,    12,    43,    52,    48,   130,    14,     4,
     122,   123,   109,    49,    53,    54,    55,   110,    83,   122,
     123,    34,   108,    29,    11,    34,   122,   123,   -26,    11,
       5,    83,     7,    86,    87,    88,    89,    90,    94,   -48,
      61,   100,    24,    29,    29,    25,   103,    27,    34,   101,
      22,    38,    39,    20,   135,   136,    26,    15,    40,    49,
      41,    28,    15,   102,    83,   140,    60,    36,    29,    61,
     144,    97,    98,    29,   113,   113,    99,   117,   -25,   113,
      58,    59,    60,   103,   106,   120,   122,    94,    56,    57,
      58,    59,    60,   113,   124,    83,    83,   134,   131,   113,
     113,   138,   141,    13,    85,    36,    83,   112,   139,    10,
      37,    83,    65,    56,    57,    58,    59,    60,   142,    35,
      38,    39,   116,   126,    46,     7,    15,    40,    37,    41,
      84,   111,   125,    66,     0,    67,    68,    69,    38,    39,
       0,     0,     0,     7,    15,    40,     0,    41,     0,     0,
       0,    66,   100,    67,    68,    69,   114,   115,     0,   118,
       0,   119,    38,    39,     0,     0,     0,    37,    15,    40,
       0,    41,    47,     0,   102,   129,     0,    38,    39,    37,
       0,   132,   133,    15,    40,     0,    41,     0,     0,    38,
      39,    37,     0,     0,     0,    15,    40,    91,    41,     0,
       0,    38,    39,    85,     0,     0,     0,    15,    40,   120,
      41,   143,    56,    57,    58,    59,    60,     0,     0,     0,
      56,    57,    58,    59,    60,    64,     0,     0,     0,     0,
      56,    57,    58,    59,    60,   107,     0,    56,    57,    58,
      59,    60,    56,    57,    58,    59,    60
};

static const yytype_int16 yycheck[] =
{
      12,    30,    14,    12,    45,    32,    11,     4,     4,    19,
      63,     4,     9,     9,    26,    23,    24,    26,    23,    24,
       4,    31,    34,     6,    27,    34,    29,     4,    11,    33,
      23,    24,     4,    62,    37,    38,    39,     9,    50,    23,
      24,    24,    83,     7,     6,    28,    23,    24,    12,    11,
       0,    63,    18,    56,    57,    58,    59,    60,    61,     3,
       3,     3,     3,     7,     7,    11,    69,    12,    51,    11,
      82,    13,    14,    82,   127,   128,     9,    19,    20,   108,
      22,     3,    19,    25,    96,   138,    17,    99,     7,     3,
     143,     3,     3,     7,    97,    98,     3,   100,    12,   102,
      15,    16,    17,   106,    12,    10,    23,   110,    13,    14,
      15,    16,    17,   116,    11,   127,   128,    11,   121,   122,
     123,    27,    12,    11,     4,   137,   138,    96,   137,     6,
       3,   143,     5,    13,    14,    15,    16,    17,   141,    26,
      13,    14,    99,   110,    28,    18,    19,    20,     3,    22,
      51,     6,   106,    26,    -1,    28,    29,    30,    13,    14,
      -1,    -1,    -1,    18,    19,    20,    -1,    22,    -1,    -1,
      -1,    26,     3,    28,    29,    30,    97,    98,    -1,   100,
      -1,   102,    13,    14,    -1,    -1,    -1,     3,    19,    20,
      -1,    22,     8,    -1,    25,   116,    -1,    13,    14,     3,
      -1,   122,   123,    19,    20,    -1,    22,    -1,    -1,    13,
      14,     3,    -1,    -1,    -1,    19,    20,    21,    22,    -1,
      -1,    13,    14,     4,    -1,    -1,    -1,    19,    20,    10,
      22,     4,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      13,    14,    15,    16,    17,     8,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    11,    -1,    13,    14,    15,
      16,    17,    13,    14,    15,    16,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    37,    38,    33,     0,    39,    18,    40,    41,
      45,    56,    70,    40,    70,    19,    31,    42,    46,    47,
      49,    57,    71,    71,     3,    11,     9,    12,     3,     7,
      50,    51,    59,    60,    70,    46,    71,     3,    13,    14,
      20,    22,    52,    55,    68,    71,    59,     8,    55,    51,
       4,     9,    49,    55,    55,    55,    13,    14,    15,    16,
      17,     3,    50,     4,     8,     5,    26,    28,    29,    30,
      44,    45,    48,    49,    55,    56,    58,    61,    64,    65,
      66,    67,    70,    71,    60,     4,    55,    55,    55,    55,
      55,    21,    53,    54,    55,    67,    43,     3,     3,     3,
       3,    11,    25,    55,    62,    63,    12,    11,    50,     4,
       9,     6,    44,    55,    62,    62,    48,    55,    62,    62,
      10,    69,    23,    24,    11,    63,    54,     4,     4,    62,
       4,    55,    62,    62,    11,    67,    67,    11,    27,    49,
      67,    12,    55,     4,    67
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 103 "a3.y"
    {
		function_def_list_t *funDefList = (function_def_list_t *)malloc(sizeof(function_def_list_t));
		funDefList->functions = (function_def_t **)malloc(MAX_IDENTIFIERS * sizeof(function_def_t *));
		funDefList->functionCount = (yyvsp[(3) - (3)].combinedFunDefList)->functionCount;
		for (int i = 0; i < funDefList->functionCount; i++) {
		    funDefList->functions[i] = (yyvsp[(3) - (3)].combinedFunDefList)->functions[(yyvsp[(3) - (3)].combinedFunDefList)->functionCount - i - 1];
		}
		funDefList->stringify = &stringifyFunctionDefList;
		program->globalDeclarations = (yyvsp[(2) - (3)].lineList);
		program->funDefList = funDefList;
		program->main = (yyvsp[(3) - (3)].combinedFunDefList)->main;
	;}
    break;

  case 4:
#line 122 "a3.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = DECLARATION;
		line->statement.declaration = (yyvsp[(2) - (2)].declarationStatement);
		line->stringify = &stringifyLine;
		(yyvsp[(1) - (2)].lineList)->lines[(yyvsp[(1) - (2)].lineList)->lineCount++] = line;
		(yyval.lineList) = (yyvsp[(1) - (2)].lineList);
	;}
    break;

  case 5:
#line 130 "a3.y"
    {
		line_list_t *lineList = (line_list_t *)malloc(sizeof(line_list_t));
		lineList->lines = (line_t **)malloc(MAX_LINES * sizeof(line_t *));
		lineList->stringify = &stringifyLineList;
		(yyval.lineList) = lineList;
	;}
    break;

  case 6:
#line 139 "a3.y"
    {
		(yyvsp[(2) - (2)].combinedFunDefList)->functions[(yyvsp[(2) - (2)].combinedFunDefList)->functionCount++] = (yyvsp[(1) - (2)].funDef);
		(yyval.combinedFunDefList) = (yyvsp[(2) - (2)].combinedFunDefList);
	;}
    break;

  case 7:
#line 143 "a3.y"
    {
		combined_function_definitions_t *combinedFunctions = (combined_function_definitions_t *)malloc(sizeof(combined_function_definitions_t));
		combinedFunctions->functions = (function_def_t **)malloc(MAX_LINES * sizeof(function_def_t *));
		combinedFunctions->main = (yyvsp[(1) - (1)].funDef);
		(yyval.combinedFunDefList) = combinedFunctions;
	;}
    break;

  case 8:
#line 152 "a3.y"
    {
		function_def_t *fun = (function_def_t *)malloc(sizeof(function_def_t));
		strcpy(fun->name, "main");
		fun->paramList = (yyvsp[(4) - (6)].paramList);
		fun->lineList = (yyvsp[(6) - (6)].lineList);
		fun->stringify = &stringifyFunDef;
		(yyval.funDef) = fun;
	;}
    break;

  case 9:
#line 163 "a3.y"
    {
		strcpy(currScope, "main");
	;}
    break;

  case 10:
#line 169 "a3.y"
    {
		(yyvsp[(1) - (2)].lineList)->lines[(yyvsp[(1) - (2)].lineList)->lineCount++] = (yyvsp[(2) - (2)].line);
		(yyval.lineList) = (yyvsp[(1) - (2)].lineList);
	;}
    break;

  case 11:
#line 173 "a3.y"
    {
		line_list_t *lineList = (line_list_t *)malloc(sizeof(line_list_t));
		lineList->lines = (line_t **)malloc(MAX_LINES * sizeof(line_t *));
		lineList->stringify = &stringifyLineList;
		(yyval.lineList) = lineList;
	;}
    break;

  case 12:
#line 183 "a3.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = DECLARATION;
		line->statement.declaration = (yyvsp[(1) - (1)].declarationStatement);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 13:
#line 190 "a3.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = ASSIGNMENT;
		line->statement.assignment = (yyvsp[(1) - (1)].assignmentStatement);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 14:
#line 197 "a3.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = EXPRESSION_STATEMENT;
		line->statement.expression = (yyvsp[(1) - (2)].exp);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 15:
#line 204 "a3.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = RETURN;
		line->statement.ret = (yyvsp[(1) - (1)].returnStatement);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 16:
#line 211 "a3.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = IF_ELSE;
		line->statement.ifElse = (yyvsp[(1) - (1)].ifElseStatement);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 17:
#line 218 "a3.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = LOOP;
		line->statement.loop = (yyvsp[(1) - (1)].loopStatement);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 18:
#line 225 "a3.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = FUNCTION;
		line->statement.function = (yyvsp[(1) - (1)].funDef);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 19:
#line 235 "a3.y"
    {
		declaration_statement_t *dec = (declaration_statement_t *)malloc(sizeof(declaration_statement_t));
		dec->type = (yyvsp[(1) - (3)].dataType);
		dec->declarationList = (yyvsp[(2) - (3)].decList);
		dec->stringify = &stringifyDeclarationStatement;
		(yyval.declarationStatement) = dec;
    ;}
    break;

  case 20:
#line 245 "a3.y"
    {
		declaration_list_t *decList = (declaration_list_t *)malloc(sizeof(declaration_list_t));
		decList->declarations = (declaration_t **)malloc(MAX_LINES * sizeof(declaration_t *));
		decList->declarations[decList->decCount++] = (yyvsp[(1) - (1)].dec);
		(yyval.decList) = decList;
	;}
    break;

  case 21:
#line 251 "a3.y"
    {
		(yyvsp[(3) - (3)].decList)->declarations[(yyvsp[(3) - (3)].decList)->decCount++] = (yyvsp[(1) - (3)].dec);
		(yyval.decList) = (yyvsp[(3) - (3)].decList);
	;}
    break;

  case 22:
#line 258 "a3.y"
    {
		declaration_t *dec = (declaration_t *)malloc(sizeof(declaration_t));
		dec->lValue = (yyvsp[(1) - (3)].id);
		dec->exp = (yyvsp[(3) - (3)].exp);
		(yyval.dec) = dec;
	;}
    break;

  case 23:
#line 264 "a3.y"
    {
		declaration_t *dec = (declaration_t *)malloc(sizeof(declaration_t));
		dec->lValue = (yyvsp[(1) - (1)].id);
		(yyval.dec) = dec;
	;}
    break;

  case 24:
#line 272 "a3.y"
    {
		symbol_table_item_t *item = searchSymbol((yyvsp[(1) - (4)].id)->name, symbolTable);
		if (item == NULL)
		    error("Undefined variable");
		if (item->data->depth != (yyvsp[(1) - (4)].id)->depth)
		    error("Invalid location");

		assignment_statement_t *ass = (assignment_statement_t *)malloc(sizeof(assignment_statement_t));
		ass->type = item->data->type;
		ass->lValue = (yyvsp[(1) - (4)].id);
		ass->exp = (yyvsp[(3) - (4)].exp);
		ass->stringify = &stringifyAssignmentStatement;
		(yyval.assignmentStatement) = ass;
	;}
    break;

  case 25:
#line 289 "a3.y"
    {
		char tempStr[MAX_IDENTIFIER_LENGTH];
		sprintf(tempStr, "global_%s", (yyvsp[(1) - (1)].str));
		symbol_table_item_t *item = searchSymbol(tempStr, symbolTable);
		if (item != NULL) {
		    (yyval.id) = item->data;
		} else {
		    identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		    strcpy(id->name, currScope);
	        strcat(id->name, "_");
	        strcat(id->name, (yyvsp[(1) - (1)].str));
	        strcpy(id->displayName, (yyvsp[(1) - (1)].str));
		    if (streq(currType, "int", 3))
		        id->type = INT;
		    else if (streq(currType, "float", 5))
		        id->type = FLOAT;
		    else if (streq(currType, "char", 4))
		        id->type = CHAR;
	        id->depth = 0;
		    insertSymbol(id->name, id, symbolTable);
		    (yyval.id) = id;
		}
	;}
    break;

  case 26:
#line 312 "a3.y"
    {
		char tempStr[MAX_IDENTIFIER_LENGTH];
		sprintf(tempStr, "global_%s", (yyvsp[(1) - (2)].str));
		symbol_table_item_t *item = searchSymbol(tempStr, symbolTable);
	    identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));


		if (streq(currType, "int", 3))
		    id->type = INT;
		else if (streq(currType, "float", 5))
		    id->type = FLOAT;
		else if (streq(currType, "char", 4))
		    id->type = CHAR;

	    id->depth = (yyvsp[(2) - (2)].subscriptList)->depth;
	    id->subscripts = (yyvsp[(2) - (2)].subscriptList)->subscripts;
		id->isPointer = true;

		if (item != NULL) {
		    sprintf(id->name, "global_%s", (yyvsp[(1) - (2)].str));
		} else {
		    sprintf(id->name, "%s_%s", currScope, (yyvsp[(1) - (2)].str));
		    insertSymbol(id->name, id, symbolTable);
		}

	    strcpy(id->displayName, (yyvsp[(1) - (2)].str));
		(yyval.id) = id;
	;}
    break;

  case 27:
#line 343 "a3.y"
    {
		subscript_list_t *subscriptList = (subscript_list_t *)malloc(sizeof(subscript_list_t));
		subscriptList->depth = 1;
		subscriptList->subscripts = (expression_t **)malloc(MAX_DEPTH * sizeof(expression_t *));
		subscriptList->subscripts[0] = (yyvsp[(1) - (1)].exp);
		(yyval.subscriptList) = subscriptList;
	;}
    break;

  case 28:
#line 350 "a3.y"
    {
		(yyvsp[(1) - (2)].subscriptList)->subscripts[(yyvsp[(1) - (2)].subscriptList)->depth++] = (yyvsp[(2) - (2)].exp);
		(yyval.subscriptList) = (yyvsp[(1) - (2)].subscriptList);
    ;}
    break;

  case 29:
#line 357 "a3.y"
    {
		(yyval.exp) = (yyvsp[(2) - (3)].exp);
	;}
    break;

  case 30:
#line 360 "a3.y"
    {
		expression_t *exp = (expression_t *)calloc(1, sizeof(expression_t));
		strcpy(exp->lValue, "0");
		exp->type = INT_CONSTANT;
		(yyval.exp) = exp;
	;}
    break;

  case 31:
#line 369 "a3.y"
    {
		arg_list_t *argList = (yyvsp[(3) - (4)].argList);
		function_call_t *fun = (function_call_t *)malloc(sizeof(function_call_t));
		strcpy(fun->name, (yyvsp[(1) - (4)].str));
		fun->argList = (yyvsp[(3) - (4)].argList);
		fun->stringify = &stringifyFunctionCall;
		(yyval.funCall) = fun;
	;}
    break;

  case 32:
#line 380 "a3.y"
    {
		(yyval.argList) = (arg_list_t *)malloc(sizeof(arg_list_t));
		(yyval.argList)->args = (arg_t **)malloc(MAX_ARGS * sizeof(arg_t *));
		(yyval.argList)->args[(yyval.argList)->argCount++] = (yyvsp[(1) - (1)].arg);
	;}
    break;

  case 33:
#line 385 "a3.y"
    {
		(yyvsp[(1) - (3)].argList)->args[(yyvsp[(1) - (3)].argList)->argCount++] = (yyvsp[(3) - (3)].arg);
		(yyval.argList) = (yyvsp[(1) - (3)].argList);
	;}
    break;

  case 34:
#line 389 "a3.y"
    {
		(yyval.argList) = (arg_list_t *)malloc(sizeof(arg_list_t));
		(yyval.argList)->args = (arg_t **)malloc(MAX_ARGS * sizeof(arg_t *));
	;}
    break;

  case 35:
#line 396 "a3.y"
    {
		arg_t *arg = (arg_t *)malloc(sizeof(arg_t));
		arg->type = EXPRESSION;
		arg->value.exp = (yyvsp[(1) - (1)].exp);
		(yyval.arg) = arg;
	;}
    break;

  case 36:
#line 402 "a3.y"
    {
		arg_t *arg = (arg_t *)malloc(sizeof(arg_t));
		arg->type = STRING;
		arg->value.str = (char *)malloc(MAX_IDENTIFIER_LENGTH * sizeof(char));
		strcpy(arg->value.str, mytext);
		(yyval.arg) = arg;
	;}
    break;

  case 37:
#line 412 "a3.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = PLUS;
		binOp->left = (yyvsp[(1) - (3)].exp);
		binOp->right = (yyvsp[(3) - (3)].exp);
		binOp->stringify = &stringifyBinOp;
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		(yyval.exp) = exp;
    ;}
    break;

  case 38:
#line 424 "a3.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = MINUS;
		binOp->left = (yyvsp[(1) - (3)].exp);
		binOp->right = (yyvsp[(3) - (3)].exp);
		binOp->stringify = &stringifyBinOp;
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		(yyval.exp) = exp;
    ;}
    break;

  case 39:
#line 436 "a3.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = MULTIPLY;
		binOp->left = (yyvsp[(1) - (3)].exp);
		binOp->right = (yyvsp[(3) - (3)].exp);
		binOp->stringify = &stringifyBinOp;
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		(yyval.exp) = exp;
    ;}
    break;

  case 40:
#line 448 "a3.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = DIVIDE;
		binOp->left = (yyvsp[(1) - (3)].exp);
		binOp->right = (yyvsp[(3) - (3)].exp);
		binOp->stringify = &stringifyBinOp;
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		(yyval.exp) = exp;
    ;}
    break;

  case 41:
#line 460 "a3.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->type = EXPONENT;
		binOp->left = (yyvsp[(1) - (3)].exp);
		binOp->right = (yyvsp[(3) - (3)].exp);
		binOp->stringify = &stringifyBinOp;
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		(yyval.exp) = exp;
    ;}
    break;

  case 42:
#line 472 "a3.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = INT_CONSTANT;
		sprintf(exp->lValue, "%s", (yyvsp[(2) - (2)].exp)->lValue);
		exp->stringify = &stringifyExpression;
		(yyval.exp) = exp;
    ;}
    break;

  case 43:
#line 479 "a3.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = INT_CONSTANT;
		sprintf(exp->lValue, "-%s", (yyvsp[(2) - (2)].exp)->lValue);
		exp->stringify = &stringifyExpression;
		(yyval.exp) = exp;
    ;}
    break;

  case 44:
#line 486 "a3.y"
    {
		(yyval.exp) = (yyvsp[(2) - (3)].exp);
    ;}
    break;

  case 45:
#line 489 "a3.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		strcpy(exp->lValue, "retval");
		exp->type = FUNCTION_CALL;
		exp->child.functionCall = (yyvsp[(1) - (1)].funCall);
		exp->stringify = &stringifyExpression;
		(yyval.exp) = exp;
    ;}
    break;

  case 46:
#line 497 "a3.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));

		if (!(yyvsp[(1) - (1)].id)->isConstant) {
			char temp[2 * MAX_IDENTIFIER_LENGTH];
		    sprintf(temp, "%s_%s", currScope, (yyvsp[(1) - (1)].id)->name);
			symbol_table_item_t *item = searchSymbol(temp, symbolTable);
			if (item == NULL) {
			    sprintf(temp, "global_%s", (yyvsp[(1) - (1)].id)->name);
			    item = searchSymbol(temp, symbolTable);
			    if (item == NULL)
			    	error("Undefined identifier");
			}
			if (item->data->type == INT && item->data->depth != (yyvsp[(1) - (1)].id)->depth)
				error("Invalid location");
		    exp->type = VAR_CONSTANT;
		} else {
		    exp->type = (yyvsp[(1) - (1)].id)->type == INT ? INT_CONSTANT : CHAR_CONSTANT;
		}

		sprintf(exp->lValue, "%s", (yyvsp[(1) - (1)].id)->name);
		exp->stringify = &stringifyExpression;
		(yyval.exp) = exp;
    ;}
    break;

  case 47:
#line 524 "a3.y"
    {
		function_def_t *fun = (function_def_t *)malloc(sizeof(function_def_t));
		strcpy(fun->name, (yyvsp[(2) - (6)].str));
		fun->paramList = (yyvsp[(4) - (6)].paramList);
		fun->lineList = (yyvsp[(6) - (6)].lineList);
		fun->stringify = &stringifyFunDef;
		(yyval.funDef) = fun;
    ;}
    break;

  case 48:
#line 535 "a3.y"
    {
		strcpy(currScope, (yyvsp[(1) - (1)].str));
		(yyval.str) = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 49:
#line 542 "a3.y"
    {
		return_statement_t *ret = (return_statement_t *)malloc(sizeof(return_statement_t));
		ret->exp = (yyvsp[(2) - (3)].exp);
		ret->stringify = &stringifyReturnStatement;
		(yyval.returnStatement) = ret;
	;}
    break;

  case 50:
#line 548 "a3.y"
    {
		return_statement_t *ret = (return_statement_t *)malloc(sizeof(return_statement_t));
		ret->stringify = &stringifyReturnStatement;
		(yyval.returnStatement) = ret;
	;}
    break;

  case 51:
#line 556 "a3.y"
    {
		param_list_t *paramList = (param_list_t *)malloc(sizeof(param_list_t));
		paramList->params = (param_t **)malloc(MAX_ARGS * sizeof(param_t *));
		paramList->params[paramList->paramCount++] = (yyvsp[(1) - (1)].param);
		paramList->stringify = &stringifyParamList;
		(yyval.paramList) = paramList;
	 ;}
    break;

  case 52:
#line 563 "a3.y"
    {
		(yyvsp[(1) - (3)].paramList)->params[(yyvsp[(1) - (3)].paramList)->paramCount++] = (yyvsp[(3) - (3)].param);
		(yyval.paramList) = (yyvsp[(1) - (3)].paramList);
	 ;}
    break;

  case 53:
#line 567 "a3.y"
    {
		param_list_t *paramList = (param_list_t *)malloc(sizeof(param_list_t));
		paramList->params = (param_t **)malloc(MAX_ARGS * sizeof(param_t *));
		paramList->stringify = &stringifyParamList;
		(yyval.paramList) = paramList;
	 ;}
    break;

  case 54:
#line 576 "a3.y"
    {
		param_t *param = (param_t *)malloc(sizeof(param_t));
		param->type = (yyvsp[(1) - (2)].dataType);
		strcpy(param->name, (yyvsp[(2) - (2)].id)->displayName);
		(yyval.param) = param;
    ;}
    break;

  case 55:
#line 585 "a3.y"
    {
		if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
		ifElse->isMatched = true;
		ifElse->condition = (yyvsp[(3) - (7)].con);
		ifElse->ifLineList = (yyvsp[(5) - (7)].lineList);
		ifElse->elseLineList = (yyvsp[(7) - (7)].lineList);
		ifElse->stringify = &stringifyIfElseStatement;
		(yyval.ifElseStatement) = ifElse;
	;}
    break;

  case 56:
#line 594 "a3.y"
    {
		if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
		ifElse->isMatched = false;
		ifElse->condition = (yyvsp[(3) - (5)].con);
		ifElse->ifLineList = (yyvsp[(5) - (5)].lineList);
		ifElse->stringify = &stringifyIfElseStatement;
		(yyval.ifElseStatement) = ifElse;
	;}
    break;

  case 57:
#line 605 "a3.y"
    {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = SHORT_AND;
		con->base = (yyvsp[(1) - (3)].con);
		con->chain = (yyvsp[(3) - (3)].con);
		(yyval.con) = con;
	;}
    break;

  case 58:
#line 612 "a3.y"
    {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = SHORT_OR;
		con->base = (yyvsp[(1) - (3)].con);
		con->chain = (yyvsp[(3) - (3)].con);
		(yyval.con) = con;
	;}
    break;

  case 59:
#line 619 "a3.y"
    {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = NOT;
		con->base = (yyvsp[(2) - (2)].con);
		(yyval.con) = con;
	;}
    break;

  case 60:
#line 625 "a3.y"
    {
		(yyval.con) = (yyvsp[(2) - (3)].con);
	;}
    break;

  case 61:
#line 628 "a3.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = BIN_OP;
		bin_op_t *binOp = (bin_op_t *)malloc(sizeof(bin_op_t));
		binOp->left = (yyvsp[(1) - (3)].exp);
		binOp->right = (yyvsp[(3) - (3)].exp);
		binOp->stringify = &stringifyBinOp;
		if (streq((yyvsp[(2) - (3)].str), "==", 2))
		    binOp->type = COMPAR_EQ;
		else if (streq((yyvsp[(2) - (3)].str), "!=", 2))
		    binOp->type = COMPAR_NE;
		else if (streq((yyvsp[(2) - (3)].str), "<=", 2))
		    binOp->type = COMPAR_LE;
		else if (streq((yyvsp[(2) - (3)].str), ">=", 2))
		    binOp->type = COMPAR_GE;
		else if (streq((yyvsp[(2) - (3)].str), "<", 1))
		    binOp->type = COMPAR_LT;
		else if (streq((yyvsp[(2) - (3)].str), ">", 1))
		    binOp->type = COMPAR_GT;
		else {
			printf("%s\n", (yyvsp[(1) - (3)].exp)->lValue);
		    error("Invalid comparison operator");
		}
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = SINGLE;
		con->exp = exp;
		(yyval.con) = con;
    ;}
    break;

  case 62:
#line 661 "a3.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].exp);
	;}
    break;

  case 63:
#line 664 "a3.y"
    {
		(yyval.exp) = (yyvsp[(1) - (1)].con)->exp;
	;}
    break;

  case 64:
#line 670 "a3.y"
    {
		loop_statement_t *loop = (loop_statement_t *)malloc(sizeof(loop_statement_t));
		loop->type = WHILE;
		loop->loop.whileLoop = (yyvsp[(1) - (1)].whileLoop);
		loop->stringify = &stringifyLoopStatement;
		(yyval.loopStatement) = loop;
    ;}
    break;

  case 65:
#line 677 "a3.y"
    {
		loop_statement_t *loop = (loop_statement_t *)malloc(sizeof(loop_statement_t));
		loop->type = FOR;
		loop->loop.forLoop = (yyvsp[(1) - (1)].forLoop);
		loop->stringify = &stringifyLoopStatement;
		(yyval.loopStatement) = loop;
	;}
    break;

  case 66:
#line 687 "a3.y"
    {
		while_loop_t *loop = (while_loop_t *)malloc(sizeof(while_loop_t));
		loop->condition = (yyvsp[(3) - (5)].con);
		loop->lineList = (yyvsp[(5) - (5)].lineList);
		loop->stringify = &stringifyWhileLoop;
		(yyval.whileLoop) = loop;
    ;}
    break;

  case 67:
#line 697 "a3.y"
    {
		for_loop_t *loop = (for_loop_t *)malloc(sizeof(for_loop_t));
		loop->initial = (yyvsp[(3) - (10)].assignmentStatement);
		loop->condition = (yyvsp[(4) - (10)].con);
		assignment_statement_t *update = (assignment_statement_t *)malloc(sizeof(assignment_statement_t));
		update->type = (yyvsp[(6) - (10)].id)->type;
		update->lValue = (yyvsp[(6) - (10)].id);
		update->exp = (yyvsp[(8) - (10)].exp);
		update->stringify = &stringifyAssignmentStatement;
		loop->update = update;
		loop->lineList = (yyvsp[(10) - (10)].lineList);
		loop->stringify = &stringifyForLoop;
		(yyval.forLoop) = loop;
	;}
    break;

  case 68:
#line 714 "a3.y"
    {
		line_list_t *lineList = (line_list_t *)malloc(sizeof(line_list_t));
		lineList->lines = (line_t **)malloc(MAX_LINES * sizeof(line_t *));
		lineList->lines[lineList->lineCount++] = (yyvsp[(1) - (1)].line);
		lineList->stringify = &stringifyLineList;
		(yyval.lineList) = lineList;
	;}
    break;

  case 69:
#line 721 "a3.y"
    {
		(yyval.lineList) = (yyvsp[(2) - (3)].lineList);
	;}
    break;

  case 70:
#line 727 "a3.y"
    {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, (yyvsp[(1) - (1)].str));
		id->depth = 0;
		(yyval.id) = id;
    ;}
    break;

  case 71:
#line 733 "a3.y"
    {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, (yyvsp[(1) - (2)].str));
		id->depth = (yyvsp[(2) - (2)].subscriptList)->depth;
		id->subscripts = (yyvsp[(2) - (2)].subscriptList)->subscripts;
		(yyval.id) = id;
    ;}
    break;

  case 72:
#line 740 "a3.y"
    {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, mytext);
		id->depth = 0;
		id->type = INT;
		id->isConstant = true;
		(yyval.id) = id;
    ;}
    break;

  case 73:
#line 748 "a3.y"
    {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, mytext);
		id->depth = 0;
		id->type = CHAR;
		id->isConstant = true;
		(yyval.id) = id;
	;}
    break;

  case 74:
#line 759 "a3.y"
    {
		(yyval.str) = strdup(mytext);
	;}
    break;

  case 75:
#line 765 "a3.y"
    {
		strcpy(currType, mytext);
		if (streq(mytext, "int", 3))
		    (yyval.dataType) = INT;
		else if (streq(mytext, "float", 5))
		    (yyval.dataType) = FLOAT;
		else if (streq(mytext, "char", 4))
		    (yyval.dataType) = CHAR;
    ;}
    break;

  case 76:
#line 776 "a3.y"
    {
		(yyval.str) = strdup(mytext);
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 2454 "a3.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 781 "a3.y"


void yyerror(char *message) {
    fprintf(stderr, "syntax error: %d\n", lineNumber);
    exit(1);
}

void error(char *message) {
    perror(message);
	exit(1);
}

int main(int argc, char *argv[]) {
    program = (program_t *)malloc(sizeof(program_t));
	tacList = (tac_list_t *)malloc(sizeof(tac_list_t));
	tacList->instructions = (tac_t **)calloc(MAX_TAC_INSTRUCTIONS, sizeof(tac_t *));
	x86List = (x86_list_t *)malloc(sizeof(x86_list_t));
	x86List->instructions = (x86_t **)calloc(MAX_X86_INSTRUCTIONS, sizeof(x86_t *));

	yyparse();

	stringifyProgram(program);

	int saved_stdout = dup(fileno(stdout));

    FILE *file = freopen("tac.txt", "w", stdout);
    if (file == NULL)
        error("Error opening file");

	for (int i = 0; i < tacList->tacCount; i++) {
		tac_t *tac = tacList->instructions[i];
		stringifyTAC(tac);
	}

    fflush(stdout);
    dup2(saved_stdout, fileno(stdout));
    close(saved_stdout);

	firstPassTACs(tacList);

	strcpy(currScope, "global");
    assembly_list_t *assList = parseTACs(tacList);

	EBP_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	EBP_REGISTER->type = X86_REGISTER;
	EBP_REGISTER->value.reg = 'B';

	ESP_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	ESP_REGISTER->type = X86_REGISTER;
	ESP_REGISTER->value.reg = 'S';

	EAX_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	EAX_REGISTER->type = X86_REGISTER;
	EAX_REGISTER->value.reg = 'a';

	EBX_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	EBX_REGISTER->type = X86_REGISTER;
	EBX_REGISTER->value.reg = 'b';

	ECX_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	ECX_REGISTER->type = X86_REGISTER;
	ECX_REGISTER->value.reg = 'c';

	EDX_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	EDX_REGISTER->type = X86_REGISTER;
	EDX_REGISTER->value.reg = 'd';

	ZEROF_REGISTER = (x86_location_t *)malloc(sizeof(x86_location_t));
	ZEROF_REGISTER->type = X86_REGISTER;
	ZEROF_REGISTER->value.reg = 'Z';

	ONE = (x86_location_t *)malloc(sizeof(x86_location_t));
	ONE->type = X86_INT_IMMEDIATE;
	ONE->value.intImmediate = 1;

    file = freopen("a.s", "w", stdout);
    if (file == NULL)
        error("Error opening file");

	stringifyAssList(assList);

    return 0;
}

void stringifyProgram(program_t *program) {
	line_list_t *globalDecs = program->globalDeclarations;
	for (int i = 0; i < globalDecs->lineCount; i++) {
		declaration_list_t *globalDecList = globalDecs->lines[i]->statement.declaration->declarationList;
		for (int j = 0; j < globalDecList->decCount; j++)
			newTACGlobalDec(globalDecList->declarations[j]->lValue->displayName);
	}
	program->globalDeclarations->stringify(program->globalDeclarations);
	program->funDefList->stringify(program->funDefList);
	program->main->stringify(program->main);
}

void stringifyFunctionDefList(function_def_list_t *funDefList) {
	function_def_t **functions = funDefList->functions;
	int functionCount = funDefList->functionCount;
	for (int i = 0; i < functionCount; i++)
		functions[i]->stringify(functions[i]);
}

void stringifyFunDef(function_def_t *fun) {
	newTACLabel(FUNCTION_LABEL, fun->name);
	fun->paramList->stringify(fun->paramList);
	fun->lineList->stringify(fun->lineList);
}

void stringifyParamList(param_list_t *paramList) {
	param_t **params = paramList->params;
	char tempString[MAX_IDENTIFIER_LENGTH];
	int paramCount = paramList->paramCount;
	for (int i = 0; i < paramCount; i++) {
		tac_term_t *lValue = newTACTerm(VARIABLE, 0, NULL, params[i]->name);
		sprintf(tempString, "param%d", i + 1);
		tac_term_t *lTerm = newTACTerm(PARAM, 0, NULL, tempString);
		tac_exp_t *rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		newTACAssignment(lValue, rValue);
	}
}

void stringifyLineList(line_list_t *lineList) {
	line_t **lines = lineList->lines;
	int lineCount = lineList->lineCount;
	for (int i = 0; i < lineCount; i++)
		lines[i]->stringify(lines[i]);
}

void stringifyLine(line_t *line) {
    switch (line->type) {
		case DECLARATION:
		    line->statement.declaration->stringify(line->statement.declaration);
			break;
		case ASSIGNMENT:
		    line->statement.assignment->stringify(line->statement.assignment);
			break;
		case EXPRESSION_STATEMENT:
		    line->statement.expression->stringify(line->statement.expression);
			break;
		case RETURN:
		    line->statement.ret->stringify(line->statement.ret);
			break;
		case IF_ELSE:
		    line->statement.ifElse->stringify(line->statement.ifElse);
			break;
		case LOOP:
		    line->statement.loop->stringify(line->statement.loop);
			break;
		case FUNCTION:
		    line->statement.function->stringify(line->statement.function);
			break;
		default:
		    error("Invalid line type");
	} 
}

void stringifyDeclarationStatement(declaration_statement_t *decList) {
	declaration_t **decs = decList->declarationList->declarations;
	int decCount = decList->declarationList->decCount;
	char tempString[MAX_IDENTIFIER_LENGTH];
    for (int i = 0; i < decCount; i++) {
		declaration_t *dec = decs[i];
		if (dec->exp == NULL)
			continue;
		dec->exp->stringify(dec->exp);
		tac_term_t *lValue = newTACTerm(VARIABLE, 0, NULL, dec->lValue->displayName);
		sprintf(tempString, "t%d", tCount - 1);
		tac_term_t *lTerm = newTACTerm(TEMPORARY, 0, NULL, tempString);
		tac_exp_t *rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		newTACAssignment(lValue, rValue);
	}
}

void stringifyAssignmentStatement(assignment_statement_t *ass) {
	ass->exp->stringify(ass->exp);
	for (int i = 0; i < ass->lValue->depth; i++) {
		ass->lValue->subscripts[i]->stringify(ass->lValue->subscripts[i]);
	}

	tac_term_t *lValue = newTACTerm(VARIABLE, ass->lValue->depth, ass->lValue->subscripts, ass->lValue->displayName);
	tac_term_t *lTerm = newTACTerm(VARIABLE, 0, NULL, ass->exp->lValue);
    tac_exp_t *rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
	newTACAssignment(lValue, rValue);
}

void stringifyExpression(expression_t *exp) {
    char tempString[MAX_IDENTIFIER_LENGTH];
	tac_term_t *lValue;
	tac_term_t *lTerm;
	tac_exp_t *rValue;

    switch (exp->type) {
		case INT_CONSTANT:
			sprintf(tempString, "t%d", tCount++);
			lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
			lTerm = newTACTerm(INT_LITERAL, 0, NULL, exp->lValue);
			rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		    newTACAssignment(lValue, rValue);

			sprintf(exp->lValue, "t%d", tCount - 1);
			break;
		case CHAR_CONSTANT:
			sprintf(tempString, "t%d", tCount++);
			lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
			lTerm = newTACTerm(CHAR_LITERAL, 0, NULL, exp->lValue);
			rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		    newTACAssignment(lValue, rValue);

			sprintf(exp->lValue, "t%d", tCount - 1);
			break;
		case VAR_CONSTANT:
			sprintf(tempString, "t%d", tCount++);
			lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
			lTerm = newTACTerm(VARIABLE, 0, NULL, exp->lValue);
			rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		    newTACAssignment(lValue, rValue);

			sprintf(exp->lValue, "t%d", tCount - 1);
			break;
		case BIN_OP:
			exp->child.binOp->stringify(exp, exp->child.binOp);
			sprintf(exp->lValue, "t%d", tCount - 1);
			break;
		case FUNCTION_CALL:
			exp->child.functionCall->stringify(exp->child.functionCall);

			sprintf(tempString, "t%d", tCount++);
			lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
			lTerm = newTACTerm(RETVAL, 0, NULL, "retval");
			rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		    newTACAssignment(lValue, rValue);

			sprintf(exp->lValue, "t%d", tCount - 1);
			break;
		default:
			error("Invalid expression");
	}
}

void stringifyReturnStatement(return_statement_t *ret) {
    if (ret->exp != NULL) {
		tac_term_t *lValue;
		tac_term_t *lTerm;
		tac_exp_t *rValue;
		switch (ret->exp->type) {
			case INT_CONSTANT:
				lValue = newTACTerm(RETVAL, 0, NULL, "retval");
				lTerm = newTACTerm(INT_LITERAL, 0, NULL, ret->exp->lValue);
				rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
				newTACAssignment(lValue, rValue);
				break;
			case CHAR_CONSTANT:
				lValue = newTACTerm(RETVAL, 0, NULL, "retval");
				lTerm = newTACTerm(CHAR_LITERAL, 0, NULL, ret->exp->lValue);
				rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
				newTACAssignment(lValue, rValue);
				break;
			case VAR_CONSTANT:
				lValue = newTACTerm(RETVAL, 0, NULL, "retval");
				lTerm = newTACTerm(VARIABLE, 0, NULL, ret->exp->lValue);
				rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
				newTACAssignment(lValue, rValue);
				break;
			default:
				ret->exp->stringify(ret->exp);
				lValue = newTACTerm(RETVAL, 0, NULL, "retval");
				char tempString[MAX_IDENTIFIER_LENGTH];
				sprintf(tempString, "t%d", tCount - 1);
				lTerm = newTACTerm(TEMPORARY, 0, NULL, tempString);
				rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
				newTACAssignment(lValue, rValue);
		}
	}

	newTACReturn("return");
}

void stringifyIfElseStatement(if_else_statement_t *ifElse) {
	condition_t *baseCon = ifElse->condition;
	bool rootIfElse = ifElse->trueLabel == 0 && ifElse->falseLabel == 0;
	char tempString[MAX_IDENTIFIER_LENGTH];

	if (ifElse->trueLabel == 0)
		ifElse->trueLabel = lCount++;
	if (ifElse->falseLabel == 0)
		ifElse->falseLabel = lCount++;

    if_else_statement_t *chainIfElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
    if_else_statement_t *baseIfElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));

	int tempLabel;
	char tempLabelString[MAX_IDENTIFIER_LENGTH];

	switch (baseCon->op) {
		case NOT:
			baseIfElse->condition = baseCon->base;
			baseIfElse->trueLabel = 0;
			baseIfElse->falseLabel = 0;
			baseIfElse->ifLineList = ifElse->elseLineList;
			baseIfElse->elseLineList = ifElse->ifLineList;
			baseIfElse->stringify = &stringifyIfElseStatement;
			baseIfElse->isMatched = ifElse->isMatched;
			baseIfElse->stringify(baseIfElse);
			return;
		case SHORT_AND:
			tempLabel = lCount++;
			baseIfElse->condition = baseCon->base;
			baseIfElse->trueLabel = tempLabel;
			baseIfElse->falseLabel = ifElse->falseLabel;
			baseIfElse->stringify = &stringifyIfElseStatement;
			baseIfElse->stringify(baseIfElse);


			sprintf(tempLabelString, "L%d", tempLabel);
			newTACLabel(JUMP_LABEL, tempLabelString);

			chainIfElse->condition = baseCon->chain;
			chainIfElse->trueLabel = ifElse->trueLabel;
			chainIfElse->falseLabel = ifElse->falseLabel;
			chainIfElse->stringify = &stringifyIfElseStatement;
			chainIfElse->stringify(chainIfElse);
			break;
		case SHORT_OR:
			tempLabel = lCount++;
			baseIfElse->condition = baseCon->base;
			baseIfElse->trueLabel = ifElse->trueLabel;
			baseIfElse->falseLabel = tempLabel;
			baseIfElse->stringify = &stringifyIfElseStatement;
			baseIfElse->stringify(baseIfElse);

			sprintf(tempLabelString, "L%d", tempLabel);
			newTACLabel(JUMP_LABEL, tempLabelString);

			chainIfElse->condition = baseCon->chain;
			chainIfElse->trueLabel = ifElse->trueLabel;
			chainIfElse->falseLabel = ifElse->falseLabel;
			chainIfElse->stringify = &stringifyIfElseStatement;
			chainIfElse->stringify(chainIfElse);
			break;
		case SINGLE:
			baseCon->exp->stringify(baseCon->exp);
			sprintf(tempLabelString, "L%d", ifElse->trueLabel);
			newTACGoto(IF_GOTO, tempLabelString, baseCon->exp->lValue);

			sprintf(tempLabelString, "L%d", ifElse->falseLabel);
			newTACGoto(GOTO, tempLabelString, NULL);
			break;
		default:
		    error("Invalid condition chaining");
	}

	if (ifElse->ifLineList != NULL) {
		sprintf(tempString, "L%d", ifElse->trueLabel);
		newTACLabel(JUMP_LABEL, tempString);
		ifElse->ifLineList->stringify(ifElse->ifLineList);
	}

	int exitLabel;

	if (ifElse->ifLineList != NULL & ifElse->elseLineList != NULL)
		exitLabel = lCount++;
	else if (ifElse->elseLineList != NULL)
		exitLabel = ifElse->trueLabel;
	else if (ifElse->ifLineList != NULL)
		exitLabel = ifElse->falseLabel;

	if (rootIfElse && ifElse->isMatched) {
		sprintf(tempLabelString, "L%d", exitLabel);
		newTACGoto(GOTO, tempLabelString, NULL);
	}

	if (ifElse->elseLineList != NULL) {
		sprintf(tempString, "L%d", ifElse->falseLabel);
		newTACLabel(JUMP_LABEL, tempString);
		ifElse->elseLineList->stringify(ifElse->elseLineList);
	}

	if (rootIfElse) {
		sprintf(tempString, "L%d", exitLabel);
		newTACLabel(JUMP_LABEL, tempString);
	}
}

void stringifyLoopStatement(loop_statement_t *loop) {
	switch (loop->type) {
		case WHILE:
		    loop->loop.whileLoop->stringify(loop->loop.whileLoop);
			break;
		case FOR:
		    loop->loop.forLoop->stringify(loop->loop.forLoop);
			break;
		default:
		    error("Invalid loop type");
	}
}

void stringifyWhileLoop(while_loop_t *loop) {
    loop->startLabel = lCount++;
    loop->trueLabel = lCount++;
    loop->falseLabel = lCount++;
	char tempString[MAX_IDENTIFIER_LENGTH];
	sprintf(tempString, "L%d", loop->startLabel);
	newTACLabel(JUMP_LABEL, tempString);
	if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
	ifElse->condition = loop->condition;
	ifElse->ifLineList = loop->lineList;
	ifElse->trueLabel = loop->trueLabel;
	ifElse->falseLabel = loop->falseLabel;
	ifElse->stringify = &stringifyIfElseStatement;
	ifElse->stringify(ifElse);

	sprintf(tempString, "L%d", loop->startLabel);
	newTACGoto(GOTO, tempString, NULL);
	
	sprintf(tempString, "L%d", loop->falseLabel);
	newTACLabel(JUMP_LABEL, tempString);
}

void stringifyForLoop(for_loop_t *loop) {
    loop->startLabel = lCount++;
    loop->trueLabel = lCount++;
    loop->falseLabel = lCount++;
	loop->initial->stringify(loop->initial);
	char tempString[MAX_IDENTIFIER_LENGTH];
	sprintf(tempString, "L%d", loop->startLabel);
	newTACLabel(JUMP_LABEL, tempString);
	if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
	ifElse->condition = loop->condition;
	ifElse->ifLineList = loop->lineList;
	ifElse->trueLabel = loop->trueLabel;
	ifElse->falseLabel = loop->falseLabel;
	ifElse->stringify = &stringifyIfElseStatement;
	ifElse->stringify(ifElse);
	loop->update->stringify(loop->update);

	sprintf(tempString, "L%d", loop->startLabel);
	newTACGoto(GOTO, tempString, NULL);

	sprintf(tempString, "L%d", loop->falseLabel);
	newTACLabel(JUMP_LABEL, tempString);
}

void stringifyBinOp(expression_t *exp, bin_op_t *binOp) {
	sprintf(exp->lValue, "t%d", tCount);
	expression_t *left = binOp->left;
	expression_t *right = binOp->right;

	tac_term_e leftType;
	tac_term_e rightType;

	switch (left->type) {
		case BIN_OP:
		    left->stringify(left);
			leftType = TEMPORARY;
			break;
		case FUNCTION_CALL:
		    left->stringify(left);
			leftType = TEMPORARY;
			break;
		case CHAR_CONSTANT:
			leftType = CHAR_LITERAL;
			break;
		case INT_CONSTANT:
			leftType = INT_LITERAL;
			break;
		case VAR_CONSTANT:
			leftType = VARIABLE;
			break;
		default:
		    error("Invalid expression type");
	}

	switch (right->type) {
		case BIN_OP:
		    right->stringify(right);
			rightType = TEMPORARY;
			break;
		case FUNCTION_CALL:
		    right->stringify(right);
			rightType = TEMPORARY;
			break;
		case CHAR_CONSTANT:
			rightType = CHAR_LITERAL;
			break;
		case INT_CONSTANT:
			rightType = INT_LITERAL;
			break;
		case VAR_CONSTANT:
			rightType = VARIABLE;
			break;
		default:
		    error("Invalid expression type");

	}

    char tempString[MAX_IDENTIFIER_LENGTH];
	sprintf(tempString, "t%d", tCount++);
	tac_term_t *lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
	tac_term_t *lTerm = newTACTerm(leftType, 0, NULL, left->lValue);
	tac_term_t *rTerm = newTACTerm(rightType, 0, NULL, right->lValue);
	tac_exp_t *rValue = newTACExp(TAC_BIN_OP, PLUS, lTerm, rTerm);

	switch (binOp->type) {
		case PLUS:
			rValue->op = PLUS;
			break;
		case MINUS:
			rValue->op = MINUS;
			break;
		case COMPAR_EQ:
			rValue->op = COMPAR_EQ;
			break;
		case COMPAR_NE:
			rValue->op = COMPAR_NE;
			break;
		case COMPAR_LT:
			rValue->op = COMPAR_LT;
			break;
		case COMPAR_GT:
			rValue->op = COMPAR_GT;
			break;
		case COMPAR_LE:
			rValue->op = COMPAR_LE;
			break;
		case COMPAR_GE:
			rValue->op = COMPAR_GE;
			break;
		case MULTIPLY:
			rValue->op = MULTIPLY;
			break;
		case DIVIDE:
			rValue->op = DIVIDE;
			break;
		case EXPONENT:
			rValue->op = EXPONENT;
			break;
		default:
			error("Invalid binary operation");
	}

	newTACAssignment(lValue, rValue);
}

void stringifyFunctionCall(function_call_t *fun) {
	arg_t **args = fun->argList->args;
	int argCount = fun->argList->argCount;
	char **passedParams = (char **)malloc(MAX_ARGS * sizeof(char *));
	int passedParamCount = 0;
	char tempString[MAX_IDENTIFIER_LENGTH];
	tac_term_t *lValue;
	tac_term_t *lTerm;
	tac_exp_t *rValue;

	for (int i = 0; i < argCount; i++) {
		arg_t *arg = args[i];
		passedParams[passedParamCount] = malloc(MAX_IDENTIFIER_LENGTH * sizeof(char));

		switch (arg->type) {
			case STRING:
				sprintf(tempString, "t%d", tCount);
				lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
				lTerm = newTACTerm(STRING_LITERAL, 0, NULL, arg->value.str);
				rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
				newTACAssignment(lValue, rValue);
				sprintf(passedParams[passedParamCount++], "t%d", tCount++);
				break;
			case EXPRESSION:
				switch(arg->value.exp->type) {
				    case CHAR_CONSTANT:
						lTerm = newTACTerm(CHAR_LITERAL, 0, NULL, arg->value.exp->lValue);
						break;
				    case INT_CONSTANT:
						lTerm = newTACTerm(INT_LITERAL, 0, NULL, arg->value.exp->lValue);
						break;
				    case VAR_CONSTANT:
						lTerm = newTACTerm(VARIABLE, 0, NULL, arg->value.exp->lValue);
						break;
				    default:
					    arg->value.exp->stringify(arg->value.exp);
						lTerm = newTACTerm(VARIABLE, 0, NULL, arg->value.exp->lValue);
				}

				sprintf(tempString, "t%d", tCount);
				lValue = newTACTerm(TEMPORARY, 0, NULL, tempString);
				rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
				newTACAssignment(lValue, rValue);
				sprintf(passedParams[passedParamCount++], "t%d", tCount++);
				break;
			default:
				error("Invalid argument");
		}
	}

	for (int i = 0; i < passedParamCount; i++) {
		sprintf(tempString, "param%d", i + 1);
		tac_term_t *lValue = newTACTerm(PARAM, 0, NULL, tempString);
		tac_term_t *lTerm = newTACTerm(TEMPORARY, 0, NULL, passedParams[i]);
		tac_exp_t *rValue = newTACExp(TAC_CONSTANT, 0, lTerm, NULL);
		newTACAssignment(lValue, rValue);
	}
	newTACCall(fun->name);
}

void newTAC(tac_e type, void *instruction) {
    tac_t *tac = (tac_t *)malloc(sizeof(tac_t *));
	tac->type = type;
	tac->stringify = &stringifyTAC;
	switch(tac->type) {
		case TAC_GLOBAL_DEC:
			tac->instruction.global = instruction;
		    break;
		case TAC_ASSIGNMENT:
			tac->instruction.assignment = instruction;
		    break;
		case TAC_LABEL:
			tac->instruction.label = instruction;
		    break;
		case TAC_GOTO:
			tac->instruction.jump = instruction;
		    break;
		case TAC_CALL:
			tac->instruction.call = instruction;
		    break;
		case TAC_RETURN:
			tac->instruction.ret = instruction;
		    break;
		default:
		    error("Invalid TAC type");

	}
	tacList->instructions[tacList->tacCount++] = tac;
}

void newTACGlobalDec(char value[MAX_IDENTIFIER_LENGTH]) {
    tac_global_dec_t *tacGlobal = (tac_global_dec_t *)malloc(sizeof(tac_global_dec_t));
	strcpy(tacGlobal->value, value);
	tacGlobal->stringify = &stringifyTACGlobalDec;
	newTAC(TAC_GLOBAL_DEC, tacGlobal);
}

void newTACAssignment(tac_term_t *lValue, tac_exp_t *rValue) {
    tac_ass_t *tacAss = (tac_ass_t *)malloc(sizeof(tac_ass_t));
	tacAss->lValue = lValue;
	tacAss->rValue = rValue;
	tacAss->stringify = &stringifyTACAssignment;
	newTAC(TAC_ASSIGNMENT, tacAss);
}

tac_term_t *newTACTerm(tac_term_e type, int depth, expression_t **subscripts,
                       char value[MAX_IDENTIFIER_LENGTH]) {
    tac_term_t *tacTerm = (tac_term_t *)calloc(1, sizeof(tac_term_t));
	tacTerm->type = type;
	tacTerm->depth = depth;
	tacTerm->subscripts = subscripts;
	strcpy(tacTerm->value, value);
	tacTerm->stringify = &stringifyTACTerm;

	return tacTerm;
}

tac_exp_t *newTACExp(tac_exp_e type, bin_op_e op, tac_term_t *lTerm,
                     tac_term_t *rTerm) {
    tac_exp_t *tacExp = (tac_exp_t *)malloc(sizeof(tac_exp_t));
	tacExp->type = type;
	tacExp->op = op;
	tacExp->lTerm = lTerm;
	tacExp->rTerm = rTerm;
	tacExp->stringify = &stringifyTACExp;
	return tacExp;
}

void newTACLabel(label_e type, char value[MAX_IDENTIFIER_LENGTH]) {
    tac_label_t *tacLabel = (tac_label_t *)malloc(sizeof(tac_label_t));
	tacLabel->type = type;
	strcpy(tacLabel->value, value);
	tacLabel->stringify = &stringifyTACLabel;
	newTAC(TAC_LABEL, tacLabel);
}

void newTACGoto(goto_e type, char label[MAX_IDENTIFIER_LENGTH],
                char condition[MAX_IDENTIFIER_LENGTH]) {
    tac_goto_t *tacGoto = (tac_goto_t *)calloc(1, sizeof(tac_goto_t));
	tacGoto->type = type;
	strcpy(tacGoto->label, label);
	if (tacGoto->type == IF_GOTO)
		strcpy(tacGoto->condition, condition);
	tacGoto->stringify = &stringifyTACGoto;
	newTAC(TAC_GOTO, tacGoto);
}

void newTACCall(char label[MAX_IDENTIFIER_LENGTH]) {
    tac_call_t *tacCall = (tac_call_t *)malloc(sizeof(tac_call_t));
	strcpy(tacCall->label, label);
	tacCall->stringify = &stringifyTACCall;
	newTAC(TAC_CALL, tacCall);
}

void newTACReturn(char label[MAX_IDENTIFIER_LENGTH]) {
    tac_return_t *tacRet = (tac_return_t *)malloc(sizeof(tac_return_t));
	strcpy(tacRet->label, label);
	tacRet->stringify = &stringifyTACReturn;
	newTAC(TAC_RETURN, tacRet);
}

void stringifyTAC(tac_t *tac) {
    switch (tac->type) {
		case TAC_GLOBAL_DEC:
			tac->instruction.global->stringify(tac->instruction.global);
		    break;
		case TAC_ASSIGNMENT:
			tac->instruction.assignment->stringify(tac->instruction.assignment);
		    break;
		case TAC_LABEL:
			tac->instruction.label->stringify(tac->instruction.label);
		    break;
		case TAC_GOTO:
			tac->instruction.jump->stringify(tac->instruction.jump);
		    break;
		case TAC_CALL:
			tac->instruction.call->stringify(tac->instruction.call);
		    break;
		case TAC_RETURN:
			tac->instruction.ret->stringify(tac->instruction.ret);
		    break;
		default:
		    error("Invalid TAC type");
	}
}

void stringifyTACGlobalDec(tac_global_dec_t *tac) {
    printf("global %s\n", tac->value);
}

void stringifyTACAssignment(tac_ass_t *tac) {
    tac->lValue->stringify(tac->lValue);
	printf(" = ");
    tac->rValue->stringify(tac->rValue);
	printf("\n");
}

void stringifyTACTerm(tac_term_t *term) {
	printf("%s", term->value);
	for (int i = 0; i < term->depth; i++) {
		printf("[%s]", term->subscripts[i]->lValue);
	}
}

void stringifyTACExp(tac_exp_t *exp) {
    switch (exp->type) {
		case TAC_CONSTANT:
		    exp->lTerm->stringify(exp->lTerm);
			break;
		case TAC_BIN_OP:
		    exp->lTerm->stringify(exp->lTerm);
			switch (exp->op) {
				case PLUS:
					printf(" + ");
				    break;
				case MINUS:
					printf(" - ");
				    break;
				case COMPAR_EQ:
					printf(" == ");
				    break;
				case COMPAR_NE:
					printf(" != ");
				    break;
				case COMPAR_LT:
					printf(" < ");
				    break;
				case COMPAR_GT:
					printf(" > ");
				    break;
				case COMPAR_LE:
					printf(" <= ");
				    break;
				case COMPAR_GE:
					printf(" >= ");
				    break;
				case MULTIPLY:
					printf(" * ");
				    break;
				case DIVIDE:
					printf(" / ");
				    break;
				case EXPONENT:
					printf(" ** ");
				    break;
				default:
				    error("Invalid TAC binary operation");
			}
		    exp->rTerm->stringify(exp->rTerm);
		    break;
		default:
		    error("Invalid TAC expression");
	}
}

void stringifyTACLabel(tac_label_t *tac) {
    printf("%s:\n", tac->value);
}

void stringifyTACGoto(tac_goto_t *tac) {
    switch(tac->type) {
		case IF_GOTO:
		    printf("if (%s) goto %s\n", tac->condition, tac->label);
			break;
		case GOTO:
		    printf("goto %s\n", tac->label);
			break;
		default:
		    error("Invalid jump type");
	}
}

void stringifyTACCall(tac_call_t *tac) {
    printf("call %s\n", tac->label);
}

void stringifyTACReturn(tac_return_t *tac) {
    printf("%s\n", tac->label);
}

unsigned long hash(char *str) {
	unsigned long hash = 51212421381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return hash % MAX_IDENTIFIERS;
}

symbol_table_item_t *searchSymbol(char *key, symbol_table_item_t* hashTable[]) {

	int hashIndex = hash(key);

	while(hashTable[hashIndex] != NULL) {
	  if(hashTable[hashIndex]->key == hashIndex)
		 return hashTable[hashIndex]; 
			
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}        

	return NULL;        
}

void insertSymbol(char *key, identifier_t *data, symbol_table_item_t* hashTable[]) {
	symbol_table_item_t *item;
	item = searchSymbol(key, hashTable);
	if (item != NULL && streq(key, item->data->name, strlen(key)))
		return;

	int hashIndex = hash(key);
	item = (symbol_table_item_t*) malloc(sizeof(symbol_table_item_t));
	item->data = data;
	item->key = hashIndex;

	while(hashTable[hashIndex] != NULL) {
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}

	hashTable[hashIndex] = item;
}

void firstPassTACs(tac_list_t *tacList) {
	tac_t *tac;
	int i = 0;
	char tempStr[MAX_IDENTIFIER_LENGTH];
	int currStackOffset = 0;

	while (i < tacList->tacCount) {
		tac = tacList->instructions[i];
		if (tac->type == TAC_LABEL && tac->instruction.label->type == FUNCTION_LABEL) {
			strcpy(currTACFunction, tac->instruction.label->value);
			currStackOffset = 0;
		}

		else if (tac->type == TAC_RETURN) {
			identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
			id->type = INT;
			strcpy(id->name, currTACFunction);
			strcpy(id->displayName, currTACFunction);
			id->stackOffset = currStackOffset + 4;
			insertSymbol(currTACFunction, id, symbolTable);
		    bzero(currTACFunction, MAX_IDENTIFIER_LENGTH);
		}

		else if (tac->type == TAC_ASSIGNMENT) {
			tac_ass_t *ass = tac->instruction.assignment;
			if (ass->lValue->type != TEMPORARY && ass->lValue->type != VARIABLE)
				goto continue_first_pass;

			if (ass->rValue->lTerm->type == PARAM) {
				int baseOffset = 8;
				while (tacList->instructions[i]->type == TAC_ASSIGNMENT && tacList->instructions[i]->instruction.assignment->rValue->lTerm->type == PARAM) {
					sprintf(tempStr, "%s_%s", currTACFunction, tacList->instructions[i]->instruction.assignment->lValue->value);
					symbol_table_item_t *item = searchSymbol(tempStr, symbolTable);
					if (item == NULL)
						error("Undefined parameter");

					item->data->stackOffset = baseOffset;
					baseOffset += 4;
				    i++;
				}
				continue;
			}

		    sprintf(tempStr, "%s_%s", currTACFunction, ass->lValue->value);
			symbol_table_item_t *item = searchSymbol(tempStr, symbolTable);

			if (item != NULL) {
				if (item->data->stackOffset == 0) {
				    item->data->stackOffset = -(currStackOffset + 4);
					currStackOffset += 4;
					for (int k = 0; k < item->data->depth; k++)
						switch (item->data->type) {
						    case INT:
								currStackOffset += 4 * (atoi(item->data->subscripts[k]->lValue));
								break;
						    case CHAR:
								currStackOffset += 1 * (atoi(item->data->subscripts[k]->lValue));
								break;
						    default:
								error("Arrays supported only with INT and CHAR");
						}
				}
				goto continue_first_pass;
		    } else {
				sprintf(tempStr, "global_%s", ass->lValue->value);
				item = searchSymbol(tempStr, symbolTable);
				if (item != NULL)
				    goto continue_first_pass;
			}

			identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
			tac_term_e rType = ass->rValue->lTerm->type;
			if (rType == STRING_LITERAL) {
				sprintf(tempStr, "global_%s", ass->lValue->value);
				id->type = DATA_STRING;
			} else {
				sprintf(tempStr, "%s_%s", currTACFunction, ass->lValue->value);
				id->type = rType == CHAR_LITERAL ? CHAR : INT;
			}

			strcpy(id->name, tempStr);
			strcpy(id->displayName, ass->lValue->value);
			id->stackOffset = -(currStackOffset + 4);
			id->isPointer = false;
			currStackOffset += 4;
			insertSymbol(tempStr, id, symbolTable);
		}

continue_first_pass:
		i++;
	}
}

assembly_list_t *parseTACs(tac_list_t *tacList) {
	tac_t *tac;
	assembly_list_t *assList = (assembly_list_t *)calloc(1, sizeof(assembly_list_t));
	assList->instructions = (assembly_t **)calloc(MAX_ASSEMBLY_INSTRUCTIONS, sizeof(assembly_t *));

    int i = 0, j;
	char callArgs[MAX_ARGS][MAX_IDENTIFIER_LENGTH];
	int callArgCount = 0;

    while (i < tacList->tacCount) {
		tac = tacList->instructions[i];
		switch(tac->type) {
		    case TAC_GLOBAL_DEC:
				assList->instructions[assList->assCount++] = newAssemblyGlobalDec(tac->instruction.global);
				break;
		    case TAC_ASSIGNMENT:
				if (tac->instruction.assignment->lValue->type == PARAM || tac->instruction.assignment->rValue->lTerm->type == PARAM)
				    break;
				if (streq(currScope, "global", 6) && tac->instruction.assignment->lValue->type == TEMPORARY)
					newTACGlobalDec(tac->instruction.assignment->lValue->value);

				assList->instructions[assList->assCount++] = newAssemblyAssignment(tac->instruction.assignment);
				break;
		    case TAC_LABEL:
				if (tac->instruction.label->type == FUNCTION_LABEL)
				    strcpy(currScope, tac->instruction.label->value);
				assList->instructions[assList->assCount++] = newAssemblyLabel(tac->instruction.label);
				break;
		    case TAC_GOTO:
				assList->instructions[assList->assCount++] = newAssemblyGoto(tac->instruction.jump);
				break;
		    case TAC_CALL:
				j = i - 1;
				while (j >= 0 && tacList->instructions[j]->type == TAC_ASSIGNMENT &&
				    tacList->instructions[j]->instruction.assignment->lValue->type == PARAM) {
				    strcpy(callArgs[callArgCount++],
				    tacList->instructions[j]->instruction.assignment->rValue->lTerm->value);
				    j--;
				}
				assList->instructions[assList->assCount++] = newAssemblyCall(callArgCount, callArgs, tac->instruction.call);
				callArgCount = 0;
				break;
		    case TAC_RETURN:
				assList->instructions[assList->assCount++] = newAssemblyReturn(tac->instruction.ret);
				break;
		}
		i++;
	}

	return assList;
}

assembly_t *newAssemblyGlobalDec(tac_global_dec_t *tac) {
	char temp[MAX_IDENTIFIER_LENGTH];
	sprintf(temp, "global_%s", tac->value);
	symbol_table_item_t *item = searchSymbol(temp, symbolTable);
	if (item == NULL)
		error("Global variable not found");

    assembly_bss_t *bss = (assembly_bss_t *)malloc(sizeof(assembly_bss_t));
	bss->var = item->data;
	bss->stringify = &stringifyBSS;

	assembly_t *ass = (assembly_t *)malloc(sizeof(assembly_t));
	ass->section = ASSEMBLY_BSS_SECTION;
	ass->instruction.bss = bss;

	return ass;
}

assembly_t *newAssemblyAssignment(tac_ass_t *tac) {
    assembly_t *ass = (assembly_t *)malloc(sizeof(assembly_t));

	if (tac->rValue->lTerm->type == STRING_LITERAL) {
		assembly_data_t *data = (assembly_data_t *)malloc(sizeof(assembly_data_t));
		data->id = globalDataCount++;
		strcpy(data->key, tac->lValue->value);
		strcpy(data->value, tac->rValue->lTerm->value);
		data->stringify = &stringifyData;

		ass->section = ASSEMBLY_DATA_SECTION;
		ass->instruction.data = data;
		return ass;
	}

	assembly_assignment_t *assign = (assembly_assignment_t *)malloc(sizeof(assembly_assignment_t));
	assign->lValue = newAssemblyTerm(tac->lValue);
	assembly_term_t *lTerm = newAssemblyTerm(tac->rValue->lTerm);
	assembly_term_t *rTerm;

	if (tac->rValue->type == TAC_BIN_OP)
		rTerm = newAssemblyTerm(tac->rValue->rTerm);
    else
		rTerm = NULL;

	assign->rValue = newAssemblyExp(tac->rValue->type, tac->rValue->op, lTerm, rTerm);
	assign->stringify = &stringifyAssemblyAssignment;

    assembly_text_t *text = (assembly_text_t *)malloc(sizeof(assembly_text_t));
	text->type = ASSEMBLY_ASSIGNMENT;
	text->instruction.assignment = assign;
	text->stringify = &stringifyText;

	ass->section = ASSEMBLY_TEXT_SECTION;
	ass->instruction.text = text;

	return ass;
}

assembly_t *newAssemblyLabel(tac_label_t *tac) {
	assembly_label_t *label = (assembly_label_t *)malloc(sizeof(assembly_label_t));
	label->type = tac->type;
	strcpy(label->value, tac->value);
	label->stringify = &stringifyAssemblyLabel;

    assembly_text_t *text = (assembly_text_t *)malloc(sizeof(assembly_text_t));
	text->type = ASSEMBLY_LABEL;
	text->instruction.label = label;
	text->stringify = &stringifyText;

	assembly_t *ass = (assembly_t *)malloc(sizeof(assembly_t));
	ass->section = ASSEMBLY_TEXT_SECTION;
	ass->instruction.text = text;

	return ass;
}

assembly_t *newAssemblyCall(int argCount, char arguments[MAX_ARGS][MAX_IDENTIFIER_LENGTH], tac_call_t *tac) {
	assembly_call_t *call = (assembly_call_t *)calloc(1, sizeof(assembly_call_t));

	for (int i = 0; i < argCount; i++)
		strcpy(call->arguments[call->argCount++], arguments[i]);

	strcpy(call->scope, currScope);
	strcpy(call->label, tac->label);
	call->stringify = &stringifyAssemblyCall;

    assembly_text_t *text = (assembly_text_t *)malloc(sizeof(assembly_text_t));
	text->type = ASSEMBLY_CALL;
	text->instruction.call = call;
	text->stringify = &stringifyText;

	assembly_t *ass = (assembly_t *)malloc(sizeof(assembly_t));
	ass->section = ASSEMBLY_TEXT_SECTION;
	ass->instruction.text = text;

	return ass;
}

assembly_t *newAssemblyReturn(tac_return_t *tac) {
	assembly_return_t *ret = (assembly_return_t *)malloc(sizeof(assembly_return_t));
	strcpy(ret->label, tac->label);
	ret->stringify = &stringifyAssemblyReturn;

    assembly_text_t *text = (assembly_text_t *)malloc(sizeof(assembly_text_t));
	text->type = ASSEMBLY_RETURN;
	text->instruction.ret = ret;
	text->stringify = &stringifyText;

	assembly_t *ass = (assembly_t *)malloc(sizeof(assembly_t));
	ass->section = ASSEMBLY_TEXT_SECTION;
	ass->instruction.text = text;

	return ass;
}

assembly_t *newAssemblyGoto(tac_goto_t *tac) {
	assembly_goto_t *jump = (assembly_goto_t *)malloc(sizeof(assembly_goto_t));
	jump->type = tac->type;
	strcpy(jump->label, tac->label);
	strcpy(jump->scope, currScope);
	if (jump->type == IF_GOTO)
		strcpy(jump->condition, tac->condition);
	jump->stringify = &stringifyAssemblyJump;

    assembly_text_t *text = (assembly_text_t *)malloc(sizeof(assembly_text_t));
	text->type = ASSEMBLY_GOTO;
	text->instruction.jump = jump;
	text->stringify = &stringifyText;

	assembly_t *ass = (assembly_t *)malloc(sizeof(assembly_t));
	ass->section = ASSEMBLY_TEXT_SECTION;
	ass->instruction.text = text;

	return ass;
}

assembly_exp_t *newAssemblyExp(tac_exp_e type, bin_op_e op, assembly_term_t *lTerm, assembly_term_t *rTerm) {
    assembly_exp_t *exp = (assembly_exp_t *)calloc(1, sizeof(assembly_exp_t));
	switch (type) {
		case TAC_BIN_OP:
			exp->type = ASSEMBLY_BIN_OP;
		    break;
		case TAC_CONSTANT:
			exp->type = ASSEMBLY_CONSTANT;
		    break;
	}
	exp->op = op;
	exp->lTerm = lTerm;
	exp->rTerm = rTerm;
	exp->stringify = &stringifyAssemblyExp;
	return exp;
}

assembly_term_t *newAssemblyTerm(tac_term_t *tac) {
    assembly_term_t *term = (assembly_term_t *)calloc(1, sizeof(assembly_term_t));
	bool updateScope = false;

	switch (tac->type) {
		case TEMPORARY:	
		    term->type = ASSEMBLY_VARIABLE;
			updateScope = true;
			break;
		case VARIABLE:	
		    term->type = ASSEMBLY_VARIABLE;
			updateScope = true;
			break;
		case RETVAL:	
		    term->type = EAX;
			break;
		case STRING_LITERAL:	
		    term->type = FMT;
			break;
		case CHAR_LITERAL:	
		    term->type = CHAR_IMMEDIATE;
			break;
		case INT_LITERAL:
		    term->type = INT_IMMEDIATE;
			break;
		default:
		    error("Invalid term type");
	}

	term->depth = tac->depth;
	term->subscripts = tac->subscripts;
	strcpy(term->value, tac->value);

	if (!updateScope)
		goto return_term;

	char tempStr[MAX_IDENTIFIER_LENGTH];
	sprintf(tempStr, "global_%s", tac->value);
	symbol_table_item_t *item = searchSymbol(tempStr, symbolTable);
	if (item == NULL) {
		sprintf(tempStr, "%s_%s", currScope, tac->value);
		item = searchSymbol(tempStr, symbolTable);
		if (item == NULL) {
		    error("[newAssemblyTerm] Undefined variable");
		}
		strcpy(term->scope, currScope);
	} else {
		strcpy(term->scope, "global");
	}

return_term:
	return term;
}

void stringifyAssList(assembly_list_t *assList) {
    assembly_t *ass;
	assembly_bss_list_t *bssList = (assembly_bss_list_t *)calloc(1, sizeof(assembly_bss_list_t));
	bssList->instructions = (assembly_bss_t **)calloc(MAX_ASSEMBLY_INSTRUCTIONS, sizeof(assembly_bss_t *));
	assembly_data_list_t *dataList = (assembly_data_list_t *)calloc(1, sizeof(assembly_data_list_t));
	dataList->instructions = (assembly_data_t **)calloc(MAX_ASSEMBLY_INSTRUCTIONS, sizeof(assembly_data_t *));
	assembly_text_list_t *textList = (assembly_text_list_t *)calloc(1, sizeof(assembly_text_list_t));
	textList->instructions = (assembly_text_t **)calloc(MAX_ASSEMBLY_INSTRUCTIONS, sizeof(assembly_text_t *));

    for (int i = 0; i < assList->assCount; i++) {
		ass = assList->instructions[i];
		switch(ass->section) {
		    case ASSEMBLY_BSS_SECTION:
				bssList->instructions[bssList->assCount++] = ass->instruction.bss;
				break;
		    case ASSEMBLY_DATA_SECTION:
				dataList->instructions[dataList->assCount++] = ass->instruction.data;
				break;
		    case ASSEMBLY_TEXT_SECTION:
				textList->instructions[textList->assCount++] = ass->instruction.text;
				break;
		}
	}

	stringifyBSSList(bssList);
	stringifyDataList(dataList);
	stringifyTextList(textList);
	stringifyX86List(x86List);
}

void stringifyBSSList(assembly_bss_list_t *bssList) {
    x86_section_t *x86Section = (x86_section_t *)malloc(sizeof(x86_section_t));
	x86Section->type = X86_BSS;
	addX86Instruction(x86Section, X86_SECTION);

	for (int i = 0; i < bssList->assCount; i++)
		bssList->instructions[i]->stringify(bssList->instructions[i]);
}

void stringifyDataList(assembly_data_list_t *dataList) {
    x86_section_t *x86Section = (x86_section_t *)malloc(sizeof(x86_section_t));
	x86Section->type = X86_DATA;
	addX86Instruction(x86Section, X86_SECTION);

	for (int i = 0; i < dataList->assCount; i++) {
		dataList->instructions[i]->stringify(dataList->instructions[i]);
	}
}

void stringifyTextList(assembly_text_list_t *textList) {
    x86_section_t *x86Section = (x86_section_t *)malloc(sizeof(x86_section_t));
	x86Section->type = X86_TEXT;
	addX86Instruction(x86Section, X86_SECTION);

	assembly_text_t *text;
	for (int i = 0; i < textList->assCount; i++) {
		text = textList->instructions[i];
		text->stringify(text);
	}
}

void stringifyBSS(assembly_bss_t *ass) {
	identifier_t *var = ass->var;
	int space, depth = 1;

	for (int i = 0; i < var->depth; i++)
		depth *= atoi(var->subscripts[i]->lValue);

	switch(var->type) {
		case INT:
			space = 4 * depth;
			break;
		case CHAR:
			space = 1 * depth;
			break;
		default:
		    error("Unsupported data type");
	}

	x86_space_allocation_t *x86 = (x86_space_allocation_t *)malloc(sizeof(x86_space_allocation_t));
	x86->type = X86_SPACE;
	x86->allocation.space = space;
	strcpy(x86->value, ass->var->displayName);
	addX86Instruction(x86, X86_SPACE_ALLOCATION);
}

void stringifyData(assembly_data_t *ass) {
    x86_space_allocation_t *x86 = (x86_space_allocation_t *)malloc(sizeof(x86_space_allocation_t));
	x86->type = X86_ASCIZ;
	strcpy(x86->allocation.str, ass->value);
	strcpy(x86->value, ass->key);
	addX86Instruction(x86, X86_SPACE_ALLOCATION);
}

void stringifyText(assembly_text_t *text) {
    switch (text->type) {
		case ASSEMBLY_LABEL:
		    text->instruction.label->stringify(text->instruction.label);
			break;
	    case ASSEMBLY_ASSIGNMENT:
		    text->instruction.assignment->stringify(text->instruction.assignment);
			break;
	    case ASSEMBLY_GOTO:
		    text->instruction.jump->stringify(text->instruction.jump);
			break;
	    case ASSEMBLY_CALL:
		    text->instruction.call->stringify(text->instruction.call);
			break;
	    case ASSEMBLY_RETURN:
		    text->instruction.ret->stringify(text->instruction.ret);
			break;
    }
}

void stringifyAssemblyLabel(assembly_label_t *label) {
	if (label->type == FUNCTION_LABEL) {
		strcpy(currScope, label->value);
		x86_section_t *x86Section = (x86_section_t *)malloc(sizeof(x86_section_t));
		x86Section->type = X86_GLOBL;
		strcpy(x86Section->label, label->value);
		addX86Instruction(x86Section, X86_SECTION);
	}

    x86_label_t *x86Label = (x86_label_t *)malloc(sizeof(x86_label_t));
	x86Label->type = label->type;
    strcpy(x86Label->label, label->value);
    addX86Instruction(x86Label, X86_LABEL);

	if (label->type == FUNCTION_LABEL) {
		newX86Stack(X86_PUSH, EBP_REGISTER);
		
		x86_data_movement_t *x86DataMovement = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
		x86DataMovement->op = X86_MOV;
		x86DataMovement->src = ESP_REGISTER;
		x86DataMovement->isDestAddress = false;
		x86DataMovement->dest = EBP_REGISTER;
		addX86Instruction(x86DataMovement, X86_DATA_MOVEMENT);

		symbol_table_item_t *item = searchSymbol(label->value, symbolTable);
		if (item == NULL)
		    error("Function not found");

		int stackOffset = item->data->stackOffset;
		x86_location_t *x86Location = (x86_location_t *)malloc(sizeof(x86_location_t));
		x86Location->type = X86_INT_IMMEDIATE;
		x86Location->value.intImmediate = stackOffset;
		newX86Arithmetic(X86_SUB, x86Location, ESP_REGISTER);
	}
}

void stringifyAssemblyAssignment(assembly_assignment_t *assignment) {
	x86_location_t *x86Location = getX86Location(assignment->lValue);
	expression_t *exp;
	bool hasSubscripts = false;

	for (int i = 0; i < assignment->lValue->depth; i++) {
		exp = assignment->lValue->subscripts[i];
		tac_term_t *tacTerm = newTACTerm(VARIABLE, 0, NULL, exp->lValue);
		assembly_term_t *assTerm = newAssemblyTerm(tacTerm);

		x86_data_movement_t *x86Mov = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
		x86Mov->op = X86_MOV;
		x86Mov->isDestAddress = false;
		x86Mov->src = getX86Location(assTerm);
		x86Mov->dest = EAX_REGISTER;
		addX86Instruction(x86Mov, X86_DATA_MOVEMENT);

		x86_data_movement_t *x86Lea = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
		x86Lea->op = X86_LEA;
		x86Lea->isDestAddress = false;
		x86Lea->src = x86Location;
		x86Lea->opReg = EAX_REGISTER;
		x86Lea->dest = EBX_REGISTER;
		hasSubscripts = true;
		addX86Instruction(x86Lea, X86_DATA_MOVEMENT);
	}

    assignment->rValue->stringify(assignment->rValue);

	x86_data_movement_t *x86DataMovement = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
	x86DataMovement->op = X86_MOV;
	x86DataMovement->src = EAX_REGISTER;

	if (hasSubscripts) {
		x86DataMovement->isDestAddress = true;
		x86DataMovement->dest = EBX_REGISTER;
	}
	else {
		x86DataMovement->isDestAddress = false;
		x86DataMovement->dest = x86Location;
	}

	addX86Instruction(x86DataMovement, X86_DATA_MOVEMENT);
}

void stringifyAssemblyCall(assembly_call_t *call) {
	symbol_table_item_t *item;
	char tempStr[MAX_IDENTIFIER_LENGTH];
    for (int i = 0; i < call->argCount; i++) {
		sprintf(tempStr, "%s_%s", call->scope, call->arguments[i]);
		item = searchSymbol(tempStr, symbolTable);

		if (item != NULL) {
		    x86_location_t *x86Location = (x86_location_t *)malloc(sizeof(x86_location_t));
		    x86Location->type = X86_MEMORY;
			x86Location->value.stackOffset = item->data->stackOffset;

			if (!item->data->isPointer) {
				newX86Stack(X86_PUSH, x86Location);
				continue;
		    }

			x86_data_movement_t *x86Lea = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
			x86Lea->op = X86_LEA;
			x86Lea->isDestAddress = false;
			x86Lea->src = x86Location;
			x86Lea->opReg = NULL;
			x86Lea->dest = EAX_REGISTER;
			addX86Instruction(x86Lea, X86_DATA_MOVEMENT);

			newX86Stack(X86_PUSH, EAX_REGISTER);

			continue;
		}

		sprintf(tempStr, "global_%s", call->arguments[i]);
		item = searchSymbol(tempStr, symbolTable);
		if (item == NULL)
		    error("Undefined variable");

		x86_stack_t *x86Stack = (x86_stack_t *)malloc(sizeof(x86_stack_t));
		x86Stack->op = X86_PUSH;

		x86_location_t *x86Location = (x86_location_t *)malloc(sizeof(x86_location_t));
		if (item->data->type == DATA_STRING)
		    x86Location->type = X86_DATA_FMT;
		else
		    x86Location->type = X86_GLOBAL;

		strcpy(x86Location->value.var, item->data->displayName);

		x86Stack->location = x86Location;
		addX86Instruction(x86Stack, X86_STACK);
	}

	x86_control_flow_t *x86Call = (x86_control_flow_t *)malloc(sizeof(x86_control_flow_t));
	x86Call->op = X86_CALL;
	strcpy(x86Call->label, call->label);
	addX86Instruction(x86Call, X86_CONTROL_FLOW);

	x86_location_t *x86Location = (x86_location_t *)malloc(sizeof(x86_location_t));
	x86Location->type = X86_INT_IMMEDIATE;
	x86Location->value.intImmediate = 4 * call->argCount;
	newX86Arithmetic(X86_ADD, x86Location, ESP_REGISTER);
}

void stringifyAssemblyJump(assembly_goto_t *jump) {
    x86_jump_t *x86Jump = (x86_jump_t *)malloc(sizeof(x86_jump_t));
	x86_compar_t *x86Compar = (x86_compar_t *)malloc(sizeof(x86_compar_t));
	x86_location_t *x86Location = (x86_location_t *)malloc(sizeof(x86_location_t));
	symbol_table_item_t *item;
	char tempStr[MAX_IDENTIFIER_LENGTH];
	x86_data_movement_t *x86DataMovementIntermediate = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
	x86DataMovementIntermediate->isDestAddress = false;

	strcpy(x86Jump->label, jump->label);

    switch(jump->type) {
		case IF_GOTO:
			sprintf(tempStr, "%s_%s", jump->scope, jump->condition);
			item = searchSymbol(tempStr, symbolTable);
			if (item == NULL)
				error("IF_GOTO condition not found");

		    int stackOffset = item->data->stackOffset;
			x86Location->type = X86_MEMORY;
			x86Location->value.stackOffset = stackOffset;

			x86DataMovementIntermediate->op = X86_MOV;
			x86DataMovementIntermediate->src = x86Location;
			x86DataMovementIntermediate->dest = ECX_REGISTER;
			addX86Instruction(x86DataMovementIntermediate, X86_DATA_MOVEMENT);

		    x86Compar->op = X86_CMP;
			x86Compar->src = ONE;
			x86Compar->dest = ECX_REGISTER;
			addX86Instruction(x86Compar, X86_COMPAR);

			x86Jump->op = X86_JE;
			addX86Instruction(x86Jump, X86_JUMP);
		    break;
		case GOTO:
			x86Jump->op = X86_JMP;
			addX86Instruction(x86Jump, X86_JUMP);
		    break;
		default:
		    error("Unsupported jump");
	}
}

void stringifyAssemblyReturn(assembly_return_t *ret) {
	x86_control_flow_t *leave = (x86_control_flow_t *)malloc(sizeof(x86_control_flow_t));
	leave->op = X86_LEAVE;
	addX86Instruction(leave, X86_CONTROL_FLOW);

	x86_control_flow_t *x86Ret = (x86_control_flow_t *)malloc(sizeof(x86_control_flow_t));
	x86Ret->op = X86_RET;
	addX86Instruction(x86Ret, X86_CONTROL_FLOW);
}

void stringifyAssemblyExp(assembly_exp_t *exp) {
	x86_location_t *x86LocationLTerm = getX86Location(exp->lTerm);
	x86_location_t *x86LocationRTerm = getX86Location(exp->rTerm);

	x86_data_movement_t *x86DataMovement = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
	x86DataMovement->isDestAddress = false;

	x86_data_movement_t *x86DataMovementIntermediate = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
	x86DataMovementIntermediate->isDestAddress = false;


	x86_data_movement_t *x86DataMovementIntermediate1 = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
	x86DataMovementIntermediate1->isDestAddress = false;

	x86_data_movement_t *x86DataMovementIntermediate2 = (x86_data_movement_t *)malloc(sizeof(x86_data_movement_t));
	x86DataMovementIntermediate2->isDestAddress = false;

	x86_compar_t *x86Compar = (x86_compar_t *)malloc(sizeof(x86_compar_t));
	x86_jump_t *x86Jump = (x86_jump_t *)malloc(sizeof(x86_jump_t));
	x86_arithmetic_t *x86Arithmetic = (x86_arithmetic_t *)malloc(sizeof(x86_arithmetic_t));
	x86_logic_t *x86Logic = (x86_logic_t *)malloc(sizeof(x86_logic_t));

    switch (exp->type) {
		case ASSEMBLY_BIN_OP:
			if (isComparison(exp->op)) {
				x86Logic->op = X86_XOR;
				x86Logic->src = EAX_REGISTER;
				x86Logic->dest = EAX_REGISTER;
				addX86Instruction(x86Logic, X86_LOGIC);

				x86DataMovementIntermediate1->op = X86_MOV;
				x86DataMovementIntermediate1->src = x86LocationLTerm;
				x86DataMovementIntermediate1->dest = ECX_REGISTER;
				addX86Instruction(x86DataMovementIntermediate1, X86_DATA_MOVEMENT);

				x86DataMovementIntermediate2->op = X86_MOV;
				x86DataMovementIntermediate2->src = x86LocationRTerm;
				x86DataMovementIntermediate2->dest = EDX_REGISTER;
				addX86Instruction(x86DataMovementIntermediate2, X86_DATA_MOVEMENT);

				x86Compar->op = X86_CMP;
				x86Compar->src = EDX_REGISTER;
				x86Compar->dest = ECX_REGISTER;
				addX86Instruction(x86Compar, X86_COMPAR);

				switch (exp->op) {
				    case COMPAR_EQ:
						x86DataMovement->op = X86_SETE;
						break;
				    case COMPAR_NE:
						x86DataMovement->op = X86_SETNE;
						break;
				    case COMPAR_LT:
						x86DataMovement->op = X86_SETL;
						break;
				    case COMPAR_GT:
						x86DataMovement->op = X86_SETG;
						break;
				    case COMPAR_LE:
						x86DataMovement->op = X86_SETLE;
						break;
				    case COMPAR_GE:
						x86DataMovement->op = X86_SETGE;
						break;
				    default:
						error("Invalid comparison operator");
				}

				x86DataMovement->src = ZEROF_REGISTER;
				x86DataMovement->dest = EAX_REGISTER;
				addX86Instruction(x86DataMovement, X86_DATA_MOVEMENT);
			} else {
				x86DataMovement->op = X86_MOV;
				x86DataMovement->src = x86LocationLTerm;
				x86DataMovement->dest = EAX_REGISTER;
				addX86Instruction(x86DataMovement, X86_DATA_MOVEMENT);


				switch (exp->op) {
				    case PLUS:
						x86Arithmetic = newX86Arithmetic(X86_ADD, x86LocationRTerm, EAX_REGISTER);
						break;
				    case MINUS:
						x86Arithmetic = newX86Arithmetic(X86_SUB, x86LocationRTerm, EAX_REGISTER);
						break;
				    case MULTIPLY:
						x86Arithmetic = newX86Arithmetic(X86_MUL, x86LocationRTerm, EAX_REGISTER);
						break;
				    case DIVIDE:
						x86Logic->op = X86_XOR;
						x86Logic->src = EDX_REGISTER;
						x86Logic->dest = EDX_REGISTER;
						addX86Instruction(x86Logic, X86_LOGIC);

						x86DataMovementIntermediate->op = X86_MOV;
						x86DataMovementIntermediate->src = x86LocationRTerm;
						x86DataMovementIntermediate->dest = EBX_REGISTER;
						addX86Instruction(x86DataMovementIntermediate, X86_DATA_MOVEMENT);
						x86Arithmetic = newX86Arithmetic(X86_DIV, EBX_REGISTER, NULL);
						break;
				    default:
						error("Invalid binary arithmetic operation");
				}
			}
		    break;
		case ASSEMBLY_CONSTANT:
			if (x86LocationLTerm->isPointer)
				x86DataMovement->op = X86_LEA;
			else
				x86DataMovement->op = X86_MOV;

			x86DataMovement->src = x86LocationLTerm;
			x86DataMovement->opReg = NULL;
			x86DataMovement->dest = EAX_REGISTER;
			addX86Instruction(x86DataMovement, X86_DATA_MOVEMENT);
		    break;
	}
}

bool isComparison(bin_op_e op) {
    return op == COMPAR_EQ || op == COMPAR_NE || op == COMPAR_LT || op == COMPAR_GT || op == COMPAR_LE || op == COMPAR_GE;
}

void newX86Stack(x86_stack_e op, x86_location_t *location) {
	x86_stack_t *x86 = (x86_stack_t *)malloc(sizeof(x86_stack_t));
	x86->op = op;
	x86->location = location;
	addX86Instruction(x86, X86_STACK);
}

x86_arithmetic_t *newX86Arithmetic(x86_arithmetic_e op, x86_location_t *src, x86_location_t *dest) {
	x86_arithmetic_t *x86 = (x86_arithmetic_t *)calloc(1, sizeof(x86_arithmetic_t));
	x86->op = op;
	x86->src = src;
	x86->dest = dest;
	addX86Instruction(x86, X86_ARITHMETIC);
	return x86;
}

void addX86Instruction(void *instruction, x86_e type) {
    x86_t *x86 = (x86_t *)malloc(sizeof(x86_t));
	x86->type = type;

	switch (x86->type) {
		case X86_SPACE_ALLOCATION:
			x86->instruction.spaceAllocation = (x86_space_allocation_t *)instruction;
		    break;
		case X86_DATA_MOVEMENT:
			x86->instruction.dataMovement = (x86_data_movement_t *)instruction;
		    break;
		case X86_ARITHMETIC:
			x86->instruction.arithmetic = (x86_arithmetic_t *)instruction;
		    break;
		case X86_LOGIC:
			x86->instruction.logic = (x86_logic_t *)instruction;
		    break;
		case X86_CONTROL_FLOW:
			x86->instruction.controlFlow = (x86_control_flow_t *)instruction;
		    break;
		case X86_JUMP:
			x86->instruction.jump = (x86_jump_t *)instruction;
		    break;
		case X86_COMPAR:
			x86->instruction.compar = (x86_compar_t *)instruction;
		    break;
		case X86_STACK:
			x86->instruction.stack = (x86_stack_t *)instruction;
		    break;
		case X86_SECTION:
			x86->instruction.section = (x86_section_t *)instruction;
		    break;
		case X86_LABEL:
			x86->instruction.label = (x86_label_t *)instruction;
		    break;
	}

	x86List->instructions[x86List->x86Count++] = x86;
}

void stringifyX86List(x86_list_t *x86List) {
	x86_t *x86;
    for (int i = 0; i < x86List->x86Count; i++) {
		x86 = x86List->instructions[i];
		switch (x86->type) {
		    case X86_SPACE_ALLOCATION:
				printf("%s: ", x86->instruction.spaceAllocation->value);
				switch (x86->instruction.spaceAllocation->type) {
				    case X86_SPACE:
						printf(".space %d", x86->instruction.spaceAllocation->allocation.space);
						break;
					case X86_ASCIZ:
						printf(".asciz %s", x86->instruction.spaceAllocation->allocation.str);
						break;
				}
				break;
		    case X86_DATA_MOVEMENT:
				if (x86->instruction.dataMovement->src == x86->instruction.dataMovement->dest)
				    break;

				switch (x86->instruction.dataMovement->op) {
				    case X86_MOV:
						if (x86->instruction.dataMovement->src->type == X86_CHAR_IMMEDIATE) {
						    if (x86->instruction.dataMovement->dest == EAX_REGISTER) {
								printf("xorl ");
								stringifyX86Location(x86->instruction.dataMovement->dest);
								printf(", ");
								stringifyX86Location(x86->instruction.dataMovement->dest);
								printf("\n");
								printf("movb");
								printf(" ");
								stringifyX86Location(x86->instruction.dataMovement->src);
								printf(", %%al");
								break;
						    }
							printf("movb");
						} else {
						    printf("movl");
						}
						printf(" ");
						stringifyX86Location(x86->instruction.dataMovement->src);
						printf(", ");
						if (x86->instruction.dataMovement->isDestAddress)
						    printf("(");
						stringifyX86Location(x86->instruction.dataMovement->dest);
						if (x86->instruction.dataMovement->isDestAddress)
						    printf(")");

						break;
				    case X86_LEA:
						printf("leal");
						printf(" ");
						if (x86->instruction.dataMovement->src->type == X86_MEMORY) {
						    printf("%d(%%ebp", x86->instruction.dataMovement->src->value.stackOffset);
							if (x86->instruction.dataMovement->opReg != NULL) {
								printf(", ");
								stringifyX86Location(x86->instruction.dataMovement->opReg);
							}
							printf(")");
						} else {
						    stringifyX86Location(x86->instruction.dataMovement->src);
						}
						if (x86->instruction.dataMovement->src->type == X86_GLOBAL) {
							printf("(");
							if (x86->instruction.dataMovement->opReg != NULL) {
								printf(", ");
								stringifyX86Location(x86->instruction.dataMovement->opReg);
							}
							printf(", 1)");
						}
						printf(", ");
						stringifyX86Location(x86->instruction.dataMovement->dest);
						break;
				    case X86_SETE:
						printf("sete %%al\n");
						break;
				    case X86_SETNE:
						printf("setne %%al\n");
						break;
				    case X86_SETL:
						printf("setl %%al\n");
						break;
				    case X86_SETG:
						printf("setg %%al\n");
						break;
				    case X86_SETGE:
						printf("setge %%al\n");
						break;
				    case X86_SETLE:
						printf("setle %%al\n");
						break;
				}
				break;
		    case X86_ARITHMETIC:
				switch (x86->instruction.arithmetic->op) {
				    case X86_ADD:
						printf("addl");
						break;
					case X86_SUB:
						printf("subl");
						break;
					case X86_MUL:
						printf("imull");
						break;
					case X86_DIV:
						printf("cdq\n");
						printf("idivl");
						break;
				}
				printf(" ");
				stringifyX86Location(x86->instruction.arithmetic->src);
				if (x86->instruction.arithmetic->dest != NULL) {
				    printf(", ");
					stringifyX86Location(x86->instruction.arithmetic->dest);
				}
				break;
		    case X86_LOGIC:
				switch (x86->instruction.logic->op) {
				    case X86_AND:
						printf("andl");
						break;
					case X86_NOT:
						printf("notl");
						break;
					case X86_OR:
						printf("orl");
						break;
					case X86_XOR:
						printf("xorl");
						break;
				}
				printf(" ");
				stringifyX86Location(x86->instruction.logic->src);
				if (x86->instruction.logic->dest != NULL) {
				    printf(", ");
					stringifyX86Location(x86->instruction.arithmetic->dest);
				}
				break;
		    case X86_CONTROL_FLOW:
				switch (x86->instruction.controlFlow->op) {
				    case X86_CALL:
						printf("call %s", x86->instruction.controlFlow->label);
						break;
				    case X86_RET:
						printf("ret");
						break;
				    case X86_LEAVE:
						printf("leave");
						break;
				}
				break;
		    case X86_JUMP:
				switch (x86->instruction.jump->op) {
				    case X86_JE:
						printf("je");
						break;
				    case X86_JNE:
						printf("jne");
						break;
				    case X86_JG:
						printf("jg");
						break;
				    case X86_JL:
						printf("jl");
						break;
				    case X86_JGE:
						printf("jge");
						break;
				    case X86_JLE:
						printf("jle");
						break;
				    case X86_JMP:
						printf("jmp");
						break;
				}
				printf(" .%s", x86->instruction.jump->label);
				break;
		    case X86_COMPAR:
				printf("cmpl ");
				stringifyX86Location(x86->instruction.compar->src);
				printf(", ");
				stringifyX86Location(x86->instruction.compar->dest);
				break;
		    case X86_STACK:
				switch (x86->instruction.stack->op) {
				    case X86_PUSH:
						printf("pushl");
						break;
				    case X86_POP:
						printf("popl");
						break;
				}
				printf(" ");
				stringifyX86Location(x86->instruction.stack->location);
				break;
		    case X86_SECTION:
				switch (x86->instruction.section->type) {
				    case X86_DATA:
						printf(".data");
						break;
					case X86_BSS:
						printf(".bss");
						break;
					case X86_TEXT:
						printf(".text");
						break;
					case X86_GLOBL:
						printf(".globl %s", x86->instruction.section->label);
						break;
				}
				break;
		    case X86_LABEL:
				if (x86->instruction.label->type == JUMP_LABEL)
				    printf(".");
				printf("%s:", x86->instruction.label->label);
				break;
		}
		printf("\n");
	}
}

x86_location_t *getX86Location(assembly_term_t *term) {
	if (term == NULL)
		return NULL;

	char tempStr[MAX_IDENTIFIER_LENGTH];
	x86_location_t *x86Location = (x86_location_t *)calloc(1, sizeof(x86_location_t));
	symbol_table_item_t *item;

	switch (term->type) {
		case ASSEMBLY_VARIABLE:
			sprintf(tempStr, "%s_%s", term->scope, term->value);
			item = searchSymbol(tempStr, symbolTable);
			x86Location->isPointer = item->data->isPointer;

			if (item == NULL)
				error("Assembly assignment lValue not found");

		    if (streq(term->scope, "global", 6)) {
				if (item->data->type == DATA_STRING)
				    x86Location->type = X86_DATA_FMT;
				else
				    x86Location->type = X86_GLOBAL;

				strcpy(x86Location->value.var, term->value);
			} else {
				x86Location->type = X86_MEMORY;
				x86Location->value.stackOffset = item->data->stackOffset;
			}

		    break;
		case EAX:
		    x86Location = EAX_REGISTER;
		    break;
		case CHAR_IMMEDIATE:
		    x86Location->type = X86_CHAR_IMMEDIATE;

			if (term->value[1] != '\\')
				x86Location->value.charImmediate = term->value[1];
				break;

		    switch (term->value[2]) {
				case '0':
				    x86Location->value.charImmediate = '\0';
					break;
				case 'n':
				    x86Location->value.charImmediate = '\n';
					break;
				case '\\':
				    x86Location->value.charImmediate = '\\';
					break;
		    }

		    break;
		case INT_IMMEDIATE:
		    x86Location->type = X86_INT_IMMEDIATE;
			x86Location->value.intImmediate = atoi(term->value);
		    break;
		default:
		    error("Invalid type term type");
	}

	return x86Location;
}

void stringifyX86Location(x86_location_t *location) {
    switch (location->type) {
		case X86_REGISTER:
			switch (location->value.reg) {
				case 'S':
				    printf("%%esp");
					break;
				case 'B':
				    printf("%%ebp");
					break;
				case 'a':
				    printf("%%eax");
					break;
				case 'b':
				    printf("%%ebx");
					break;
				case 'c':
				    printf("%%ecx");
					break;
				case 'd':
				    printf("%%edx");
					break;
				default:
				    error("Register type not supported");
			}
		    break;
		case X86_MEMORY:
			printf("%d(%%ebp)", location->value.stackOffset);
		    break;
		case X86_GLOBAL:
			printf("%s", location->value.var);
		    break;
		case X86_DATA_FMT:
			printf("$%s", location->value.var);
		    break;
		case X86_INT_IMMEDIATE:
			printf("$%d", location->value.intImmediate);
		    break;
		case X86_CHAR_IMMEDIATE:
			switch (location->value.charImmediate) {
				case '\0':
				    printf("$0");
					break;
				case '\n':
				    printf("$10");
					break;
				case '\\':
				    printf("$92");
					break;
				default:
				    printf("$\'%c\'", location->value.charImmediate);
			}
		    break;
	}
}

