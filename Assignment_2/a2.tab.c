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
     SHORT_AND_TOK = 277,
     SHORT_OR_TOK = 278,
     NOT_TOK = 279,
     IF_TOK = 280,
     ELSE_TOK = 281,
     WHILE_TOK = 282,
     FOR_TOK = 283,
     RETURN_TOK = 284,
     MAIN = 285,
     UMINUS = 286
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
#define SHORT_AND_TOK 277
#define SHORT_OR_TOK 278
#define NOT_TOK 279
#define IF_TOK 280
#define ELSE_TOK 281
#define WHILE_TOK 282
#define FOR_TOK 283
#define RETURN_TOK 284
#define MAIN 285
#define UMINUS 286




/* Copy the first part of user declarations.  */
#line 1 "a2.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "a2.h"

void yyerror(char *);
int yylex(void);
char mytext[100];
char currType[10];
char currScope[MAX_IDENTIFIER_LENGTH] = "global";
expression_t args[MAX_FUNCTION_CALLS][MAX_ARGS];
int lineNumber = 1;
static int tCount = 1;
static int lCount = 1;

hash_table_item_t *symbolTable[MAX_IDENTIFIERS];
program_t *program;


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
#line 39 "a2.y"
{
    char *str;
    int val;
    identifier_t *id;
	expression_t *exp; 
	line_t *line;
	line_list_t *lineList;
	declaration_statement_t *declarationStatement;
	assignment_statement_t *assignmentStatement;
	if_else_statement_t *ifElseStatement;
	return_statement_t *returnStatement;
	loop_statement_t *loopStatement;
	function_def_t *funDef;
	function_def_list_t *funDefList;
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
#line 206 "a2.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 219 "a2.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   226

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    17,    19,    21,    24,
      26,    28,    31,    33,    35,    37,    39,    43,    45,    49,
      53,    55,    60,    62,    65,    67,    70,    74,    79,    81,
      85,    86,    88,    90,    94,    98,   102,   106,   110,   113,
     117,   119,   121,   128,   130,   134,   137,   139,   143,   144,
     147,   155,   161,   165,   169,   172,   176,   180,   182,   184,
     190,   201,   203,   207,   209,   212,   214,   216,   218,   220,
     222
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      33,     0,    -1,    34,    35,    -1,    34,    50,    -1,    -1,
      64,    36,     3,    53,     4,    60,    -1,    30,    -1,    38,
      -1,    37,    38,    -1,    39,    -1,    42,    -1,    49,    11,
      -1,    52,    -1,    55,    -1,    57,    -1,    50,    -1,    64,
      40,    11,    -1,    41,    -1,    41,     9,    40,    -1,    43,
      12,    49,    -1,    43,    -1,    43,    12,    49,    11,    -1,
      65,    -1,    65,    44,    -1,    45,    -1,    45,    44,    -1,
       7,    62,     8,    -1,    65,     3,    47,     4,    -1,    48,
      -1,    47,     9,    48,    -1,    -1,    49,    -1,    21,    -1,
      49,    13,    49,    -1,    49,    14,    49,    -1,    49,    15,
      49,    -1,    49,    16,    49,    -1,    49,    17,    49,    -1,
      14,    49,    -1,     3,    49,     4,    -1,    46,    -1,    61,
      -1,    64,    51,     3,    53,     4,    60,    -1,    65,    -1,
      29,    49,    11,    -1,    29,    11,    -1,    54,    -1,    53,
       9,    54,    -1,    -1,    64,    43,    -1,    25,     3,    56,
       4,    60,    26,    60,    -1,    25,     3,    56,     4,    60,
      -1,    56,    22,    56,    -1,    56,    23,    56,    -1,    24,
      56,    -1,     3,    56,     4,    -1,    49,    63,    49,    -1,
      58,    -1,    59,    -1,    27,     3,    49,     4,    60,    -1,
      28,     3,    42,    49,    11,    43,    12,    49,     4,    60,
      -1,    38,    -1,     5,    37,     6,    -1,    65,    -1,    65,
      44,    -1,    20,    -1,    65,    -1,    20,    -1,    10,    -1,
      18,    -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,   100,   104,   113,   124,   130,   137,   145,
     152,   159,   166,   173,   180,   187,   197,   207,   213,   220,
     226,   234,   250,   266,   285,   288,   294,   298,   309,   314,
     318,   325,   331,   340,   352,   364,   376,   388,   400,   408,
     411,   419,   437,   448,   454,   460,   468,   475,   479,   488,
     497,   506,   517,   524,   531,   537,   540,   571,   578,   588,
     597,   610,   616,   622,   628,   634,   644,   645,   649,   655,
     666
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
  "STRING_TOK", "SHORT_AND_TOK", "SHORT_OR_TOK", "NOT_TOK", "IF_TOK",
  "ELSE_TOK", "WHILE_TOK", "FOR_TOK", "RETURN_TOK", "MAIN", "UMINUS",
  "$accept", "program", "functionDefinitions", "mainFunction",
  "mainIdentifier", "lines", "line", "declarationStatement",
  "declarations", "declaration", "assignmentStatement", "assignable",
  "subscripts", "subscript", "functionCall", "arguments", "argument",
  "expression", "functionDefinition", "functionIdentifier",
  "returnStatement", "parameters", "parameter", "ifStatement", "condition",
  "loopStatement", "whileStatement", "forStatement", "body", "term",
  "index", "compar", "validType", "identifier", 0
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
     285,   286
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    36,    37,    37,    38,
      38,    38,    38,    38,    38,    38,    39,    40,    40,    41,
      41,    42,    43,    43,    44,    44,    45,    46,    47,    47,
      47,    48,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    50,    51,    52,    52,    53,    53,    53,    54,
      55,    55,    56,    56,    56,    56,    56,    57,    57,    58,
      59,    60,    60,    61,    61,    61,    62,    62,    63,    64,
      65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     6,     1,     1,     2,     1,
       1,     2,     1,     1,     1,     1,     3,     1,     3,     3,
       1,     4,     1,     2,     1,     2,     3,     4,     1,     3,
       0,     1,     1,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     6,     1,     3,     2,     1,     3,     0,     2,
       7,     5,     3,     3,     2,     3,     3,     1,     1,     5,
      10,     1,     3,     1,     2,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,    69,     2,     3,     0,    70,     6,
       0,     0,    43,    48,    48,     0,    46,     0,     0,     0,
       0,    49,    22,     0,     0,     0,     0,    65,     0,     0,
       0,     0,    61,     9,    10,     0,    40,     0,    15,    12,
      13,    14,    57,    58,     5,    41,     0,    63,    47,     0,
      23,    24,    42,     0,    63,     0,     7,    38,     0,     0,
       0,    45,     0,     0,    11,     0,     0,     0,     0,     0,
       0,    17,    20,    22,    30,    64,    67,     0,    66,    25,
      39,    64,    62,     8,     0,     0,     0,     0,     0,     0,
      44,     0,    33,    34,    35,    36,    37,    16,     0,     0,
      32,     0,    28,    31,    26,     0,     0,    54,    68,     0,
       0,     0,     0,     0,     0,    21,    18,    19,    27,     0,
      55,    56,    51,    52,    53,    59,     0,    29,     0,     0,
      50,     0,     0,     0,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,    10,    55,    32,    33,    70,    71,
      34,    35,    50,    51,    36,   101,   102,    37,    38,    11,
      39,    15,    16,    40,    87,    41,    42,    43,    44,    45,
      77,   109,    46,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -81
static const yytype_int16 yypact[] =
{
     -81,    24,    -3,   -81,   -81,   -81,   -81,   -10,   -81,   -81,
      25,    32,   -81,    -3,    -3,     4,   -81,    43,    17,    31,
      -3,   -81,    39,    31,    61,   132,    61,   -81,    70,    83,
      94,    82,   -81,   -81,   -81,    87,   -81,   183,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,    43,    54,   -81,    89,
     -81,    39,   -81,   151,    80,    49,   -81,    96,     3,    61,
      43,   -81,   190,    61,   -81,    61,    61,    61,    61,    61,
      93,   111,    88,    91,    51,   112,   -81,   117,   -81,   -81,
     -81,   -81,   -81,   -81,     3,     3,   126,    15,   165,    61,
     -81,   197,   155,   155,    96,    96,    96,   -81,    43,    61,
     -81,    75,   -81,   209,   -81,   101,    21,   -81,   -81,    61,
      31,     3,     3,    31,   204,   -81,   -81,   209,   -81,    51,
     -81,   209,   102,   -81,   -81,   -81,    43,   -81,    31,   122,
     -81,    61,   173,    31,   -81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,   -81,   -81,   -81,   -81,   -22,   -81,    46,   -81,
      77,   -16,   -40,   -81,   -81,   -81,    26,    64,   145,   -81,
     -81,   140,   136,   -81,   -80,   -81,   -81,   -81,   -21,   -81,
     -81,   -81,    27,    -7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -44
static const yytype_int16 yytable[] =
{
      12,    21,    52,    56,   106,   107,    84,    75,    19,     8,
      22,    79,    47,    20,    81,     4,    47,    26,    47,   110,
       9,    23,     8,    27,     3,   120,    20,    85,    13,     7,
      72,   123,   124,    83,    24,    14,    25,   111,   112,    73,
      17,    17,    78,   111,   112,    26,    49,    17,    47,     4,
       8,    27,    24,    22,    24,    82,    28,    74,    29,    30,
      31,    49,     8,    26,    24,    26,   -22,     4,     8,    27,
       8,    27,   100,    58,    28,    26,    29,    30,    31,   118,
       8,    27,    72,    74,   119,    24,    59,    49,    53,   122,
      57,    22,   125,    61,   -43,    62,    26,    60,    49,    63,
      99,     8,    27,    47,    97,    80,    47,   130,     8,    76,
     129,   108,   134,    69,    65,    66,    67,    68,    69,    22,
      98,    47,    86,    88,   -23,   104,    47,    91,   128,    92,
      93,    94,    95,    96,   131,    24,   108,    89,   103,    65,
      66,    67,    68,    69,   116,   127,    26,     6,   105,    86,
       4,     8,    27,   114,    18,    80,    48,    28,     0,    29,
      30,    31,     0,   117,    65,    66,    67,    68,    69,   113,
      67,    68,    69,   121,     0,    86,    86,   133,    65,    66,
      67,    68,    69,   103,     0,     0,    65,    66,    67,    68,
      69,     0,     0,     0,    64,   132,    65,    66,    67,    68,
      69,    90,     0,    65,    66,    67,    68,    69,   115,     0,
      65,    66,    67,    68,    69,   126,     0,    65,    66,    67,
      68,    69,    65,    66,    67,    68,    69
};

static const yytype_int16 yycheck[] =
{
       7,    17,    23,    25,    84,    85,     3,    47,     4,    19,
      17,    51,    19,     9,    54,    18,    23,    14,    25,     4,
      30,     4,    19,    20,     0,     4,     9,    24,     3,     2,
      46,   111,   112,    55,     3,     3,     5,    22,    23,    46,
      13,    14,    49,    22,    23,    14,     7,    20,    55,    18,
      19,    20,     3,    60,     3,     6,    25,     3,    27,    28,
      29,     7,    19,    14,     3,    14,    12,    18,    19,    20,
      19,    20,    21,     3,    25,    14,    27,    28,    29,     4,
      19,    20,    98,     3,     9,     3,     3,     7,    24,   110,
      26,    98,   113,    11,     3,    31,    14,     3,     7,    12,
      12,    19,    20,   110,    11,     4,   113,   128,    19,    20,
     126,    10,   133,    17,    13,    14,    15,    16,    17,   126,
       9,   128,    58,    59,    12,     8,   133,    63,    26,    65,
      66,    67,    68,    69,    12,     3,    10,    60,    74,    13,
      14,    15,    16,    17,    98,   119,    14,     2,    84,    85,
      18,    19,    20,    89,    14,     4,    20,    25,    -1,    27,
      28,    29,    -1,    99,    13,    14,    15,    16,    17,     4,
      15,    16,    17,   109,    -1,   111,   112,     4,    13,    14,
      15,    16,    17,   119,    -1,    -1,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    11,   131,    13,    14,    15,    16,
      17,    11,    -1,    13,    14,    15,    16,    17,    11,    -1,
      13,    14,    15,    16,    17,    11,    -1,    13,    14,    15,
      16,    17,    13,    14,    15,    16,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    34,     0,    18,    35,    50,    64,    19,    30,
      36,    51,    65,     3,     3,    53,    54,    64,    53,     4,
       9,    43,    65,     4,     3,     5,    14,    20,    25,    27,
      28,    29,    38,    39,    42,    43,    46,    49,    50,    52,
      55,    57,    58,    59,    60,    61,    64,    65,    54,     7,
      44,    45,    60,    49,    65,    37,    38,    49,     3,     3,
       3,    11,    49,    12,    11,    13,    14,    15,    16,    17,
      40,    41,    43,    65,     3,    44,    20,    62,    65,    44,
       4,    44,     6,    38,     3,    24,    49,    56,    49,    42,
      11,    49,    49,    49,    49,    49,    49,    11,     9,    12,
      21,    47,    48,    49,     8,    49,    56,    56,    10,    63,
       4,    22,    23,     4,    49,    11,    40,    49,     4,     9,
       4,    49,    60,    56,    56,    60,    11,    48,    26,    43,
      60,    12,    49,     4,    60
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
#line 93 "a2.y"
    {
		program->funDefList = (yyvsp[(1) - (2)].funDefList);
		program->main = (yyvsp[(2) - (2)].funDef);
	;}
    break;

  case 3:
#line 100 "a2.y"
    {
		(yyvsp[(1) - (2)].funDefList)->functions[(yyvsp[(1) - (2)].funDefList)->functionCount++] = (yyvsp[(2) - (2)].funDef);
		(yyval.funDefList) = (yyvsp[(1) - (2)].funDefList);
	;}
    break;

  case 4:
#line 104 "a2.y"
    {
		function_def_list_t *funDefList = (function_def_list_t *)malloc(sizeof(function_def_list_t));
		funDefList->functions = (function_def_t **)malloc(MAX_LINES * sizeof(function_def_t *));
		funDefList->stringify = &stringifyFunctionDefList;
		(yyval.funDefList) = funDefList;
	;}
    break;

  case 5:
#line 113 "a2.y"
    {
		function_def_t *fun = (function_def_t *)malloc(sizeof(function_def_t));
		strcpy(fun->name, "main");
		fun->paramList = (yyvsp[(4) - (6)].paramList);
		fun->lineList = (yyvsp[(6) - (6)].lineList);
		fun->stringify = &stringifyFunDef;
		(yyval.funDef) = fun;
	;}
    break;

  case 6:
#line 124 "a2.y"
    {
		strcpy(currScope, "main");
	;}
    break;

  case 7:
#line 130 "a2.y"
    {
		line_list_t *lineList = (line_list_t *)malloc(sizeof(line_list_t));
		lineList->lines = (line_t **)malloc(MAX_LINES * sizeof(line_t *));
		lineList->lines[lineList->lineCount++] = (yyvsp[(1) - (1)].line);
		lineList->stringify = &stringifyLineList;
		(yyval.lineList) = lineList;
	;}
    break;

  case 8:
#line 137 "a2.y"
    {
		(yyvsp[(1) - (2)].lineList)->lines[(yyvsp[(1) - (2)].lineList)->lineCount++] = (yyvsp[(2) - (2)].line);
		(yyval.lineList) = (yyvsp[(1) - (2)].lineList);
	;}
    break;

  case 9:
#line 145 "a2.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = DECLARATION;
		line->statement.declaration = (yyvsp[(1) - (1)].declarationStatement);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 10:
#line 152 "a2.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = ASSIGNMENT;
		line->statement.assignment = (yyvsp[(1) - (1)].assignmentStatement);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 11:
#line 159 "a2.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = EXPRESSION_STATEMENT;
		line->statement.expression = (yyvsp[(1) - (2)].exp);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 12:
#line 166 "a2.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = RETURN;
		line->statement.ret = (yyvsp[(1) - (1)].returnStatement);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 13:
#line 173 "a2.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = IF_ELSE;
		line->statement.ifElse = (yyvsp[(1) - (1)].ifElseStatement);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 14:
#line 180 "a2.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = LOOP;
		line->statement.loop = (yyvsp[(1) - (1)].loopStatement);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 15:
#line 187 "a2.y"
    {
		line_t *line = (line_t *)malloc(sizeof(line_t));
		line->type = FUNCTION;
		line->statement.function = (yyvsp[(1) - (1)].funDef);
		line->stringify = &stringifyLine;
		(yyval.line) = line;
	;}
    break;

  case 16:
#line 197 "a2.y"
    {
		declaration_statement_t *dec = (declaration_statement_t *)malloc(sizeof(declaration_statement_t));
		dec->type = (yyvsp[(1) - (3)].dataType);
		dec->declarationList = (yyvsp[(2) - (3)].decList);
		dec->stringify = &stringifyDeclarationStatement;
		(yyval.declarationStatement) = dec;
    ;}
    break;

  case 17:
#line 207 "a2.y"
    {
		declaration_list_t *decList = (declaration_list_t *)malloc(sizeof(declaration_list_t));
		decList->declarations = (declaration_t **)malloc(MAX_LINES * sizeof(declaration_t *));
		decList->declarations[decList->decCount++] = (yyvsp[(1) - (1)].dec);
		(yyval.decList) = decList;
	;}
    break;

  case 18:
#line 213 "a2.y"
    {
		(yyvsp[(3) - (3)].decList)->declarations[(yyvsp[(3) - (3)].decList)->decCount++] = (yyvsp[(1) - (3)].dec);
		(yyval.decList) = (yyvsp[(3) - (3)].decList);
	;}
    break;

  case 19:
#line 220 "a2.y"
    {
		declaration_t *dec = (declaration_t *)malloc(sizeof(declaration_t));
		dec->lValue = (yyvsp[(1) - (3)].id);
		dec->exp = (yyvsp[(3) - (3)].exp);
		(yyval.dec) = dec;
	;}
    break;

  case 20:
#line 226 "a2.y"
    {
		declaration_t *dec = (declaration_t *)malloc(sizeof(declaration_t));
		dec->lValue = (yyvsp[(1) - (1)].id);
		(yyval.dec) = dec;
	;}
    break;

  case 21:
#line 234 "a2.y"
    {
		hash_table_item_t *item = searchSymbol((yyvsp[(1) - (4)].id)->name, symbolTable);
		if (item == NULL) error("Undefined identifier");
		if (item->data->depth != (yyvsp[(1) - (4)].id)->depth)
		    yyerror("Invalid location");

		assignment_statement_t *ass = (assignment_statement_t *)malloc(sizeof(assignment_statement_t));
		ass->type = item->data->type;
		ass->lValue = (yyvsp[(1) - (4)].id);
		ass->exp = (yyvsp[(3) - (4)].exp);
		ass->stringify = &stringifyAssignmentStatement;
		(yyval.assignmentStatement) = ass;
	;}
    break;

  case 22:
#line 250 "a2.y"
    {
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
	;}
    break;

  case 23:
#line 266 "a2.y"
    {
	    identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, currScope);
	    strcat(id->name, "_");
	    strcat(id->name, (yyvsp[(1) - (2)].str));
	    strcpy(id->displayName, (yyvsp[(1) - (2)].str));
		if (streq(currType, "int", 3))
		    id->type = INT;
		else if (streq(currType, "float", 5))
		    id->type = FLOAT;
		else if (streq(currType, "char", 4))
		    id->type = CHAR;
	    id->depth = (yyvsp[(2) - (2)].val);
		insertSymbol(id->name, id, symbolTable);
		(yyval.id) = id;
	;}
    break;

  case 24:
#line 285 "a2.y"
    {
		(yyval.val) = 1;
	;}
    break;

  case 25:
#line 288 "a2.y"
    {
	    (yyval.val) = 1 + (yyvsp[(2) - (2)].val);
    ;}
    break;

  case 27:
#line 298 "a2.y"
    {
		arg_list_t *argList = (yyvsp[(3) - (4)].argList);
		function_call_t *fun = (function_call_t *)malloc(sizeof(function_call_t));
		strcpy(fun->name, (yyvsp[(1) - (4)].str));
		fun->argList = (yyvsp[(3) - (4)].argList);
		fun->stringify = &stringifyFunctionCall;
		(yyval.funCall) = fun;
	;}
    break;

  case 28:
#line 309 "a2.y"
    {
		(yyval.argList) = (arg_list_t *)malloc(sizeof(arg_list_t));
		(yyval.argList)->args = (arg_t **)malloc(MAX_ARGS * sizeof(arg_t *));
		(yyval.argList)->args[(yyval.argList)->argCount++] = (yyvsp[(1) - (1)].arg);
	;}
    break;

  case 29:
#line 314 "a2.y"
    {
		(yyvsp[(1) - (3)].argList)->args[(yyvsp[(1) - (3)].argList)->argCount++] = (yyvsp[(3) - (3)].arg);
		(yyval.argList) = (yyvsp[(1) - (3)].argList);
	;}
    break;

  case 30:
#line 318 "a2.y"
    {
		(yyval.argList) = (arg_list_t *)malloc(sizeof(arg_list_t));
		(yyval.argList)->args = (arg_t **)malloc(MAX_ARGS * sizeof(arg_t *));
	;}
    break;

  case 31:
#line 325 "a2.y"
    {
		arg_t *arg = (arg_t *)malloc(sizeof(arg_t));
		arg->type = EXPRESSION;
		arg->value.exp = (yyvsp[(1) - (1)].exp);
		(yyval.arg) = arg;
	;}
    break;

  case 32:
#line 331 "a2.y"
    {
		arg_t *arg = (arg_t *)malloc(sizeof(arg_t));
		arg->type = STRING;
		strcpy(arg->value.str, mytext);
		(yyval.arg) = arg;
	;}
    break;

  case 33:
#line 340 "a2.y"
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

  case 34:
#line 352 "a2.y"
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

  case 35:
#line 364 "a2.y"
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

  case 36:
#line 376 "a2.y"
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

  case 37:
#line 388 "a2.y"
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

  case 38:
#line 400 "a2.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		exp->type = CONSTANT;
		exp->child.binOp->type = EXPONENT;
		sprintf(exp->lValue, "%s", (yyvsp[(2) - (2)].exp)->lValue);
		exp->stringify = &stringifyExpression;
		(yyval.exp) = exp;
    ;}
    break;

  case 39:
#line 408 "a2.y"
    {
		(yyval.exp) = (yyvsp[(2) - (3)].exp);
    ;}
    break;

  case 40:
#line 411 "a2.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));
		strcpy(exp->lValue, "retval");
		exp->type = FUNCTION_CALL;
		exp->child.functionCall = (yyvsp[(1) - (1)].funCall);
		exp->stringify = &stringifyExpression;
		(yyval.exp) = exp;
    ;}
    break;

  case 41:
#line 419 "a2.y"
    {
		expression_t *exp = (expression_t *)malloc(sizeof(expression_t));

		if (!(yyvsp[(1) - (1)].id)->isConstant) {
		    sprintf(mytext, "%s_%s", currScope, (yyvsp[(1) - (1)].id)->name);
			hash_table_item_t *item = searchSymbol(mytext, symbolTable);
			if (item == NULL)
				error("Undefined identifier");
		}

		sprintf(exp->lValue, "%s", (yyvsp[(1) - (1)].id)->name);
		exp->type = CONSTANT;
		exp->stringify = &stringifyExpression;
		(yyval.exp) = exp;
    ;}
    break;

  case 42:
#line 437 "a2.y"
    {
		function_def_t *fun = (function_def_t *)malloc(sizeof(function_def_t));
		strcpy(fun->name, (yyvsp[(2) - (6)].str));
		fun->paramList = (yyvsp[(4) - (6)].paramList);
		fun->lineList = (yyvsp[(6) - (6)].lineList);
		fun->stringify = &stringifyFunDef;
		(yyval.funDef) = fun;
    ;}
    break;

  case 43:
#line 448 "a2.y"
    {
		strcpy(currScope, (yyvsp[(1) - (1)].str));
		(yyval.str) = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 44:
#line 454 "a2.y"
    {
		return_statement_t *ret = (return_statement_t *)malloc(sizeof(return_statement_t));
		ret->exp = (yyvsp[(2) - (3)].exp);
		ret->stringify = &stringifyReturnStatement;
		(yyval.returnStatement) = ret;
	;}
    break;

  case 45:
#line 460 "a2.y"
    {
		return_statement_t *ret = (return_statement_t *)malloc(sizeof(return_statement_t));
		ret->stringify = &stringifyReturnStatement;
		(yyval.returnStatement) = ret;
	;}
    break;

  case 46:
#line 468 "a2.y"
    {
		param_list_t *paramList = (param_list_t *)malloc(sizeof(param_list_t));
		paramList->params = (param_t **)malloc(MAX_ARGS * sizeof(param_t *));
		paramList->params[paramList->paramCount++] = (yyvsp[(1) - (1)].param);
		paramList->stringify = &stringifyParamList;
		(yyval.paramList) = paramList;
	 ;}
    break;

  case 47:
#line 475 "a2.y"
    {
		(yyvsp[(1) - (3)].paramList)->params[(yyvsp[(1) - (3)].paramList)->paramCount++] = (yyvsp[(3) - (3)].param);
		(yyval.paramList) = (yyvsp[(1) - (3)].paramList);
	 ;}
    break;

  case 48:
#line 479 "a2.y"
    {
		param_list_t *paramList = (param_list_t *)malloc(sizeof(param_list_t));
		paramList->params = (param_t **)malloc(MAX_ARGS * sizeof(param_t *));
		paramList->stringify = &stringifyParamList;
		(yyval.paramList) = paramList;
	 ;}
    break;

  case 49:
#line 488 "a2.y"
    {
		param_t *param = (param_t *)malloc(sizeof(param_t));
		param->type = (yyvsp[(1) - (2)].dataType);
		strcpy(param->name, (yyvsp[(2) - (2)].id)->displayName);
		(yyval.param) = param;
    ;}
    break;

  case 50:
#line 497 "a2.y"
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

  case 51:
#line 506 "a2.y"
    {
		if_else_statement_t *ifElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
		ifElse->isMatched = false;
		ifElse->condition = (yyvsp[(3) - (5)].con);
		ifElse->ifLineList = (yyvsp[(5) - (5)].lineList);
		ifElse->stringify = &stringifyIfElseStatement;
		(yyval.ifElseStatement) = ifElse;
	;}
    break;

  case 52:
#line 517 "a2.y"
    {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = SHORT_AND;
		con->exp = (yyvsp[(1) - (3)].con)->exp;
		con->chain = (yyvsp[(3) - (3)].con);
		(yyval.con) = con;
	;}
    break;

  case 53:
#line 524 "a2.y"
    {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = SHORT_OR;
		con->exp = (yyvsp[(1) - (3)].con)->exp;
		con->chain = (yyvsp[(3) - (3)].con);
		(yyval.con) = con;
	;}
    break;

  case 54:
#line 531 "a2.y"
    {
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = NOT;
		con->exp = (yyvsp[(2) - (2)].con)->exp;
		(yyval.con) = con;
	;}
    break;

  case 55:
#line 537 "a2.y"
    {
		(yyval.con) = (yyvsp[(2) - (3)].con);
	;}
    break;

  case 56:
#line 540 "a2.y"
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
		else if (streq((yyvsp[(2) - (3)].str), "<", 1))
		    binOp->type = COMPAR_LT;
		else if (streq((yyvsp[(2) - (3)].str), ">", 1))
		    binOp->type = COMPAR_GT;
		else if (streq((yyvsp[(2) - (3)].str), "<=", 2))
		    binOp->type = COMPAR_LE;
		else if (streq((yyvsp[(2) - (3)].str), ">=", 2))
		    binOp->type = COMPAR_GE;
		else
		    error("Invalid comparison operator");
		exp->child.binOp = binOp;
		exp->stringify = &stringifyExpression;
		condition_t *con = (condition_t *)malloc(sizeof(condition_t));
		con->op = SINGLE;
		con->exp = exp;
		(yyval.con) = con;
    ;}
    break;

  case 57:
#line 571 "a2.y"
    {
		loop_statement_t *loop = (loop_statement_t *)malloc(sizeof(loop_statement_t));
		loop->type = WHILE;
		loop->loop.whileLoop = (yyvsp[(1) - (1)].whileLoop);
		loop->stringify = &stringifyLoopStatement;
		(yyval.loopStatement) = loop;
    ;}
    break;

  case 58:
#line 578 "a2.y"
    {
		loop_statement_t *loop = (loop_statement_t *)malloc(sizeof(loop_statement_t));
		loop->type = FOR;
		loop->loop.forLoop = (yyvsp[(1) - (1)].forLoop);
		loop->stringify = &stringifyLoopStatement;
		(yyval.loopStatement) = loop;
	;}
    break;

  case 59:
#line 588 "a2.y"
    {
		while_loop_t *loop = (while_loop_t *)malloc(sizeof(while_loop_t));
		loop->condition = (yyvsp[(3) - (5)].exp);
		loop->lineList = (yyvsp[(5) - (5)].lineList);
		(yyval.whileLoop) = loop;
    ;}
    break;

  case 60:
#line 597 "a2.y"
    {
		for_loop_t *loop = (for_loop_t *)malloc(sizeof(for_loop_t));
		loop->initial = (yyvsp[(3) - (10)].assignmentStatement);
		loop->condition = (yyvsp[(4) - (10)].exp);
		assignment_statement_t *update = (assignment_statement_t *)malloc(sizeof(assignment_statement_t));
		update->type = (yyvsp[(6) - (10)].id)->type;
		update->exp = (yyvsp[(8) - (10)].exp);
		loop->update = update;
		(yyval.forLoop) = loop;
	;}
    break;

  case 61:
#line 610 "a2.y"
    {
		line_list_t *lineList = (line_list_t *)malloc(sizeof(line_list_t));
		lineList->lines = (line_t **)malloc(MAX_LINES * sizeof(line_t *));
		lineList->lines[lineList->lineCount++] = (yyvsp[(1) - (1)].line);
		(yyval.lineList) = lineList;
	;}
    break;

  case 62:
#line 616 "a2.y"
    {
		(yyval.lineList) = (yyvsp[(2) - (3)].lineList);
	;}
    break;

  case 63:
#line 622 "a2.y"
    {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, (yyvsp[(1) - (1)].str));
		id->depth = 0;
		(yyval.id) = id;
    ;}
    break;

  case 64:
#line 628 "a2.y"
    {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, (yyvsp[(1) - (2)].str));
		id->depth = (yyvsp[(2) - (2)].val);
		(yyval.id) = id;
    ;}
    break;

  case 65:
#line 634 "a2.y"
    {
		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, mytext);
		id->depth = 0;
		id->isConstant = true;
		(yyval.id) = id;
    ;}
    break;

  case 68:
#line 649 "a2.y"
    {
		(yyval.str) = strdup(mytext);
	;}
    break;

  case 69:
#line 655 "a2.y"
    {
		if (streq(mytext, "int", 3))
		    (yyval.dataType) = INT;
		else if (streq(mytext, "float", 5))
		    (yyval.dataType) = FLOAT;
		else if (streq(mytext, "char", 4))
		    (yyval.dataType) = CHAR;
		strcpy(currType, mytext);
    ;}
    break;

  case 70:
#line 666 "a2.y"
    {
		(yyval.str) = strdup(mytext);
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 2297 "a2.tab.c"
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


#line 671 "a2.y"


void yyerror(char *message) {
    fprintf(stderr, "syntax error: %d\n", lineNumber);
    exit(1);
}

void error(char *message) {
		perror(message);
		exit(1);
}

int main(void) {
    program = (program_t *)malloc(sizeof(program_t));
	yyparse();
	stringifyProgram(program);
    return 0;
}

void stringifyProgram(program_t *program) {
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
    printf("%s:\n", fun->name);
	fun->paramList->stringify(fun->paramList);
	fun->lineList->stringify(fun->lineList);
}

void stringifyParamList(param_list_t *paramList) {
	param_t **params = paramList->params;
	int paramCount = paramList->paramCount;
	for (int i = 0; i < paramCount; i++)
		printf("%s = param%d\n", params[i]->name, i + 1);
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
    for (int i = 0; i < decCount; i++) {
		declaration_t *dec = decs[i];
		if (dec->exp == NULL)
			continue;
		dec->exp->stringify(dec->exp);
		printf("%s = t%d\n", dec->lValue->displayName, tCount - 1);
	}
}

void stringifyAssignmentStatement(assignment_statement_t *ass) {
	ass->exp->stringify(ass->exp);
	printf("%s = t%d\n", ass->lValue->displayName, tCount - 1);
}

void stringifyExpression(expression_t *exp) {
    switch (exp->type) {
		case CONSTANT:
			printf("t%d = %s\n", tCount++, exp->lValue);
			break;
		case BIN_OP:
			exp->child.binOp->stringify(exp, exp->child.binOp);
			break;
		case FUNCTION_CALL:
			exp->child.functionCall->stringify(exp->child.functionCall);
			break;
		default:
			error("Invalid expression");
	}
}

void stringifyReturnStatement(return_statement_t *ret) {
    if (ret->exp != NULL) {
		switch (ret->exp->type) {
			case CONSTANT:
				printf("retval = %s\n", ret->exp->lValue);
				break;
			default:
				ret->exp->stringify(ret->exp);
				printf("retval = t%d\n", tCount++);
		}
	}
	printf("return\n");
}

void stringifyIfElseStatement(if_else_statement_t *ifElse) {
	condition_t *baseCon = ifElse->condition;
	baseCon->exp->stringify(baseCon->exp);
	bool rootIfElse = ifElse->trueLabel == 0 && ifElse->falseLabel == 0;
	if (ifElse->trueLabel == 0)
		ifElse->trueLabel = lCount++;
	if (ifElse->falseLabel == 0)
		ifElse->falseLabel = ifElse->isMatched ? lCount++ : lCount;

    if_else_statement_t *chainIfElse = (if_else_statement_t *)malloc(sizeof(if_else_statement_t));
	switch (baseCon->op) {
		case NOT:
		    printf("t%d = not %s\n", tCount, baseCon->exp->lValue);
			printf("if (t%d) goto L%d\n", tCount++, ifElse->trueLabel);
			printf("goto L%d\n", ifElse->falseLabel);
			printf("L%d:\n", ifElse->trueLabel);
			ifElse->ifLineList->stringify(ifElse->ifLineList);
			break;
		case SHORT_AND:
		    printf("if (%s) goto L%d\n", baseCon->exp->lValue, ifElse->trueLabel);
			printf("goto L%d\n", ifElse->falseLabel);
			printf("L%d:\n", ifElse->trueLabel);
			chainIfElse->condition = baseCon->chain;
			chainIfElse->falseLabel = ifElse->falseLabel;
			chainIfElse->ifLineList = ifElse->ifLineList;
			chainIfElse->stringify = &stringifyIfElseStatement;
			chainIfElse->stringify(chainIfElse);
			break;
		case SHORT_OR:
		    printf("if (%s) goto L%d\n", baseCon->exp->lValue, ifElse->trueLabel);
			chainIfElse->condition = baseCon->chain;
			chainIfElse->trueLabel = ifElse->trueLabel;
			chainIfElse->falseLabel = ifElse->falseLabel;
			chainIfElse->ifLineList = ifElse->ifLineList;
			chainIfElse->stringify = &stringifyIfElseStatement;
			chainIfElse->stringify(chainIfElse);
			break;
		case SINGLE:
		    printf("if (%s) goto L%d\n", baseCon->exp->lValue, ifElse->trueLabel);
			printf("goto L%d\n", ifElse->falseLabel);
			printf("L%d:\n", ifElse->trueLabel);
			ifElse->ifLineList->stringify(ifElse->ifLineList);
			break;
		default:
		    error("Invalid condition chaining");
	}
	int exitLabel = lCount++;
	if (rootIfElse && ifElse->isMatched)
		printf("goto L%d\n", exitLabel);
	if (ifElse->isMatched) {
		printf("L%d:\n", ifElse->falseLabel);
		ifElse->elseLineList->stringify(ifElse->elseLineList);
	}
	if (rootIfElse)
		printf("L%d:\n", exitLabel);
}

void stringifyLoopStatement(loop_statement_t *loopStatement) {
	printf("LOOP_STATEMENT\n");
}

void stringifyBinOp(expression_t *exp, bin_op_t *binOp) {
	sprintf(exp->lValue, "t%d", tCount);
	expression_t *left = binOp->left;
	expression_t *right = binOp->right;
	if (left->type != CONSTANT)
		left->stringify(left);
	if (right->type != CONSTANT)
		right->stringify(right);

	switch (binOp->type) {
		case PLUS:
			printf("t%d = %s + %s\n", tCount++, left->lValue, right->lValue);
			break;
		case MINUS:
			printf("t%d = %s - %s\n", tCount++, left->lValue, right->lValue);
			break;
		case COMPAR_EQ:
			printf("t%d = %s == %s\n", tCount++, left->lValue, right->lValue);
			break;
		case COMPAR_NE:
			printf("t%d = %s != %s\n", tCount++, left->lValue, right->lValue);
			break;
		case COMPAR_LT:
			printf("t%d = %s < %s\n", tCount++, left->lValue, right->lValue);
			break;
		case COMPAR_GT:
			printf("t%d = %s > %s\n", tCount++, left->lValue, right->lValue);
			break;
		case COMPAR_LE:
			printf("t%d = %s <= %s\n", tCount++, left->lValue, right->lValue);
			break;
		case COMPAR_GE:
			printf("t%d = %s >= %s\n", tCount++, left->lValue, right->lValue);
			break;
		case MULTIPLY:
			printf("t%d = %s * %s\n", tCount++, left->lValue, right->lValue);
			break;
		case DIVIDE:
			printf("t%d = %s / %s\n", tCount++, left->lValue, right->lValue);
			break;
		case EXPONENT:
			printf("t%d = %s ** %s\n", tCount++, left->lValue, right->lValue);
			break;
		default:
			error("Invalid binary operation");
	}
}

void stringifyFunctionCall(function_call_t *fun) {
	arg_t **args = fun->argList->args;
	int argCount = fun->argList->argCount;
	char **passedParams = (char **)malloc(MAX_ARGS * sizeof(char *));
	int passedParamCount = 0;
	for (int i = 0; i < argCount; i++) {
		arg_t *arg = args[i];
		passedParams[passedParamCount] = malloc(MAX_IDENTIFIER_LENGTH * sizeof(char));
		switch (arg->type) {
			case STRING:
				printf("t%d = \"%s\"", tCount, arg->value.str);
				sprintf(passedParams[passedParamCount++], "t%d", tCount++);
				break;
			case EXPRESSION:
				if (arg->value.exp->type != CONSTANT)
					arg->value.exp->stringify(arg->value.exp);
				printf("t%d = %s\n", tCount, arg->value.exp->lValue);
				sprintf(passedParams[passedParamCount++], "t%d", tCount++);
				break;
			default:
				error("Invalid argument");
		}
	}
	for (int i = 0; i < passedParamCount; i++)
		printf("param%d = %s\n", i + 1, passedParams[i]);
	printf("call %s\n", fun->name);
}

unsigned long hash(char *str) {
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return hash % MAX_IDENTIFIERS;
}

hash_table_item_t *searchSymbol(char *key, hash_table_item_t* hashTable[]) {

	int hashIndex = hash(key);

	while(hashTable[hashIndex] != NULL) {
	  if(hashTable[hashIndex]->key == hashIndex)
		 return hashTable[hashIndex]; 
			
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}        

	return NULL;        
}

void insertSymbol(char *key, identifier_t *data, hash_table_item_t* hashTable[]) {
	hash_table_item_t *item;
	item = searchSymbol(key, hashTable);
	if (item != NULL) {
		item->data = data;
		return;
	}
	int hashIndex = hash(key);
	item = (hash_table_item_t*) malloc(sizeof(hash_table_item_t));
	item->data = data;
	item->key = hashIndex;

	while(hashTable[hashIndex] != NULL) {
	  ++hashIndex;
	  hashIndex %= MAX_IDENTIFIERS;
	}

	hashTable[hashIndex] = item;
}

