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




/* Copy the first part of user declarations.  */
#line 1 "l12.y"

#include "l12.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void yyerror(char *);
int yylex(void);
char mytext[100];
extern char *yytext;
char currScope[MAX_IDENTIFIER_LENGTH];

fun_t *currFun;
symbol_table_item_t *varTable[MAX_IDENTIFIERS];
symbol_table_item_t *funTable[MAX_IDENTIFIERS];
fun_list_t *funList;
query_list_t *queryList;
int scopeReachability[MAX_DEPTH] = { 1 };
static int scopeCount = 1;


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
/* Line 193 of yacc.c.  */
#line 187 "l12.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 200 "l12.tab.c"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNRULES -- Number of states.  */
#define YYNSTATES  105

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    12,    15,    20,    23,    26,
      31,    34,    36,    38,    41,    43,    44,    51,    52,    59,
      65,    66,    69,    73,    76,    77,    79,    81,    83,    88,
      90,    92,    96,   102,   103,   114,   119,   123,   127,   131,
     135,   139,   143,   147,   149,   151,   153,   155,   157,   160
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      31,     0,    -1,    35,    29,    32,    -1,    32,    33,    -1,
      33,    -1,    22,    34,    -1,    23,    34,    28,    34,    -1,
      24,    34,    -1,    25,    34,    -1,    26,    34,    28,    34,
      -1,    27,    34,    -1,    55,    -1,     8,    -1,    36,    35,
      -1,    38,    -1,    -1,    17,    55,    37,    10,    11,    40,
      -1,    -1,     7,     8,    39,    10,    11,    40,    -1,    12,
      41,    43,    57,    13,    -1,    -1,    42,    41,    -1,     7,
      55,    14,    -1,    44,    43,    -1,    -1,    45,    -1,    46,
      -1,    51,    -1,    55,     9,    53,    14,    -1,    49,    -1,
      48,    -1,    10,    52,    11,    -1,    18,    47,    12,    43,
      13,    -1,    -1,    18,    47,    12,    43,    13,    50,    19,
      12,    43,    13,    -1,    55,    10,    11,    14,    -1,    52,
      16,    52,    -1,    52,    15,    52,    -1,    10,    52,    11,
      -1,    53,    54,    53,    -1,    53,     3,    53,    -1,    53,
       4,    53,    -1,    10,    53,    11,    -1,    55,    -1,    56,
      -1,     5,    -1,    20,    -1,    21,    -1,     6,    14,    -1,
       6,    21,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    68,    72,    81,    96,   118,   133,   148,
     170,   188,   191,   196,   200,   209,   209,   234,   234,   253,
     258,   259,   263,   278,   287,   295,   300,   303,   313,   329,
     332,   338,   348,   360,   360,   377,   395,   398,   401,   404,
     422,   425,   428,   431,   441,   447,   462,   468,   474,   475
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "COMPAR", "RETURN",
  "INT", "MAIN", "EQ", "OPEN_PAREN", "CLOSE_PAREN", "OPEN_BRACE",
  "CLOSE_BRACE", "SEMI_COLON", "SHORT_OR", "SHORT_AND", "VOID", "IF",
  "ELSE", "IDENTIFIER", "NUMBER", "DEAD_TOK", "REACHABLE_TOK",
  "SELF_RECURSIVE_TOK", "EVENTUALLY_RECURSIVE_TOK", "CO_RECURSIVE_TOK",
  "DEPTH_TOK", "COMMA", "SEPARATOR", "$accept", "program", "queries",
  "query", "functionName", "functionDefinitions", "functionDefinition",
  "@1", "mainFunction", "@2", "body", "intDeclarations", "intDeclaration",
  "statements", "statement", "assignment", "ifStatement", "ifCondition",
  "ifThenStatement", "ifThenElseStatement", "@3", "functionCall",
  "condition", "expression", "compar", "identifier", "number",
  "returnStatement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    33,    33,    33,
      33,    34,    34,    35,    35,    37,    36,    39,    38,    40,
      41,    41,    42,    43,    43,    44,    44,    44,    45,    46,
      46,    47,    48,    50,    49,    51,    52,    52,    52,    52,
      53,    53,    53,    53,    53,    54,    55,    56,    57,    57
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     2,     4,     2,     2,     4,
       2,     1,     1,     2,     1,     0,     6,     0,     6,     5,
       0,     2,     3,     2,     0,     1,     1,     1,     4,     1,
       1,     3,     5,     0,    10,     4,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    14,    17,    46,    15,
       1,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     4,     0,     0,    12,     5,    11,     0,     7,
       8,     0,    10,     3,     0,     0,     0,     0,    20,    18,
      16,     6,     9,     0,    24,    20,     0,     0,     0,    24,
      25,    26,    30,    29,    27,     0,    21,    22,     0,     0,
       0,     0,    23,     0,     0,     0,    47,     0,     0,    43,
      44,    24,    48,     0,    19,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,    45,     0,     0,    49,     0,
      28,    35,    38,    42,    37,    36,    40,    41,    39,    32,
       0,     0,    24,     0,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    21,    22,    26,     4,     5,    14,     6,    13,
      39,    44,    45,    48,    49,    50,    51,    59,    52,    53,
     100,    54,    67,    68,    86,    69,    70,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -62
static const yytype_int8 yypact[] =
{
      -5,     0,   -14,    11,    22,    -5,   -62,   -62,   -62,   -62,
     -62,    48,   -62,    19,    54,     2,     2,     2,     2,     2,
       2,    48,   -62,    72,    74,   -62,   -62,   -62,     3,   -62,
     -62,    24,   -62,   -62,    75,    75,     2,     2,    77,   -62,
     -62,   -62,   -62,   -14,   -15,    77,    76,    79,    80,   -15,
     -62,   -62,   -62,   -62,   -62,    70,   -62,   -62,    23,    81,
      41,    82,   -62,    38,    83,    23,   -62,    50,    73,   -62,
     -62,   -15,   -62,    84,   -62,    38,    46,    85,    52,    21,
     -62,    23,    23,    38,    38,   -62,    38,    88,   -62,    42,
     -62,   -62,   -62,   -62,    86,   -62,   -62,   -62,    78,    69,
      87,    91,   -15,    92,   -62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,   -62,    71,    20,    99,   -62,   -62,   -62,   -62,
      56,    51,   -62,   -48,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -61,   -56,   -62,    -2,   -62,   -62
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -34
static const yytype_int8 yytable[] =
{
       9,    62,     1,    47,    78,     8,     8,    76,     7,    79,
      25,    10,     2,    27,    27,    27,    27,    27,    27,    89,
      94,    95,     8,    87,    83,    84,    85,    96,    97,    23,
      98,    36,    93,    65,    27,    27,    28,    29,    30,    31,
      32,    46,    55,     8,    66,    83,    84,    55,    75,    83,
      84,    11,    37,    93,   103,    72,    41,    42,     8,    66,
      90,    80,    73,    92,    24,    81,    82,    81,    82,    55,
      15,    16,    17,    18,    19,    20,    83,    84,    85,    63,
      64,    83,    84,    34,    43,    35,    60,    38,   -33,    58,
      57,    40,    33,    71,    77,    74,    56,     0,    88,    91,
      55,    99,    82,   102,    12,   104,   101
};

static const yytype_int8 yycheck[] =
{
       2,    49,     7,    18,    65,    20,    20,    63,     8,    65,
       8,     0,    17,    15,    16,    17,    18,    19,    20,    75,
      81,    82,    20,    71,     3,     4,     5,    83,    84,    10,
      86,    28,    11,    10,    36,    37,    16,    17,    18,    19,
      20,    43,    44,    20,    21,     3,     4,    49,    10,     3,
       4,    29,    28,    11,   102,    14,    36,    37,    20,    21,
      14,    11,    21,    11,    10,    15,    16,    15,    16,    71,
      22,    23,    24,    25,    26,    27,     3,     4,     5,     9,
      10,     3,     4,    11,     7,    11,     6,    12,    19,    10,
      14,    35,    21,    12,    11,    13,    45,    -1,    14,    14,
     102,    13,    16,    12,     5,    13,    19
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    17,    31,    35,    36,    38,     8,    20,    55,
       0,    29,    35,    39,    37,    22,    23,    24,    25,    26,
      27,    32,    33,    10,    10,     8,    34,    55,    34,    34,
      34,    34,    34,    33,    11,    11,    28,    28,    12,    40,
      40,    34,    34,     7,    41,    42,    55,    18,    43,    44,
      45,    46,    48,    49,    51,    55,    41,    14,    10,    47,
       6,    57,    43,     9,    10,    10,    21,    52,    53,    55,
      56,    12,    14,    21,    13,    10,    53,    11,    52,    53,
      11,    15,    16,     3,     4,     5,    54,    43,    14,    53,
      14,    14,    11,    11,    52,    52,    53,    53,    53,    13,
      50,    19,    12,    43,    13
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
#line 61 "l12.y"
    {
		funList = (yyvsp[(1) - (3)].funList);
		queryList = (yyvsp[(3) - (3)].queryList);
	;}
    break;

  case 3:
#line 68 "l12.y"
    {
		(yyvsp[(1) - (2)].queryList)->queries[(yyvsp[(1) - (2)].queryList)->queryCount++] = (yyvsp[(2) - (2)].query);
		(yyval.queryList) = (yyvsp[(1) - (2)].queryList);
	;}
    break;

  case 4:
#line 72 "l12.y"
    {
		query_list_t *queryList = (query_list_t *)malloc(sizeof(query_list_t));
		queryList->queries = (query_t **)malloc(MAX_QUERIES * sizeof(query_t *));
		queryList->queries[queryList->queryCount++] = (yyvsp[(1) - (1)].query);
		(yyval.queryList) = queryList;
	;}
    break;

  case 5:
#line 81 "l12.y"
    {
		symbol_table_item_t *item = searchSymbol((yyvsp[(2) - (2)].str), funTable);
		if (item == NULL)
			error("Function not found");

		fun_t *fun = item->data->data.fun;

		dead_query_t *dead = (dead_query_t *)malloc(sizeof(dead_query_t));
		dead->fun = fun;

		query_t *query = (query_t *)malloc(sizeof(query_t));
		query->type = DEAD;
		query->query.dead = dead;
		(yyval.query) = query;
	;}
    break;

  case 6:
#line 96 "l12.y"
    {
		symbol_table_item_t *item = searchSymbol((yyvsp[(2) - (4)].str), funTable);
		if (item == NULL)
			error("Source function not found");

		fun_t *src = item->data->data.fun;

		item = searchSymbol((yyvsp[(4) - (4)].str), funTable);
		if (item == NULL)
			error("Destination function not found");

		fun_t *dest = item->data->data.fun;

		reach_query_t *reach = (reach_query_t *)malloc(sizeof(reach_query_t));
		reach->src = src;
		reach->dest = dest;
		
		query_t *query = (query_t *)malloc(sizeof(query_t));
		query->type = REACHABLE;
		query->query.reach = reach;
		(yyval.query) = query;
	;}
    break;

  case 7:
#line 118 "l12.y"
    {
		symbol_table_item_t *item = searchSymbol((yyvsp[(2) - (2)].str), funTable);
		if (item == NULL)
			error("Function not found");

		fun_t *fun = item->data->data.fun;

		self_recursive_query_t *selfRecursive = (self_recursive_query_t *)malloc(sizeof(self_recursive_query_t));
		selfRecursive->fun = fun;

		query_t *query = (query_t *)malloc(sizeof(query_t));
		query->type = SELF_RECURSIVE;
		query->query.selfRecursive = selfRecursive;
		(yyval.query) = query;
	;}
    break;

  case 8:
#line 133 "l12.y"
    {
		symbol_table_item_t *item = searchSymbol((yyvsp[(2) - (2)].str), funTable);
		if (item == NULL)
			error("Function not found");

		fun_t *fun = item->data->data.fun;

		eventually_recursive_query_t *eventuallyRecursive = (eventually_recursive_query_t *)malloc(sizeof(eventually_recursive_query_t));
		eventuallyRecursive->fun = fun;

		query_t *query = (query_t *)malloc(sizeof(query_t));
		query->type = EVENTUALLY_RECURSIVE;
		query->query.eventuallyRecursive = eventuallyRecursive;
		(yyval.query) = query;
	;}
    break;

  case 9:
#line 148 "l12.y"
    {
		symbol_table_item_t *item = searchSymbol((yyvsp[(2) - (4)].str), funTable);
		if (item == NULL)
			error("Source function not found");

		fun_t *fun1 = item->data->data.fun;

		item = searchSymbol((yyvsp[(4) - (4)].str), funTable);
		if (item == NULL)
			error("Destination function not found");

		fun_t *fun2 = item->data->data.fun;

		co_recursive_query_t *coRecursive = (co_recursive_query_t *)malloc(sizeof(co_recursive_query_t));
		coRecursive->fun1 = fun1;
		coRecursive->fun2 = fun2;
		
		query_t *query = (query_t *)malloc(sizeof(query_t));
		query->type = CO_RECURSIVE;
		query->query.coRecursive = coRecursive;
		(yyval.query) = query;
	;}
    break;

  case 10:
#line 170 "l12.y"
    {
		symbol_table_item_t *item = searchSymbol((yyvsp[(2) - (2)].str), funTable);
		if (item == NULL)
			error("Function not found");

		fun_t *fun = item->data->data.fun;

		depth_query_t *depth = (depth_query_t *)malloc(sizeof(depth_query_t));
		depth->fun = fun;

		query_t *query = (query_t *)malloc(sizeof(query_t));
		query->type = DEPTH;
		query->query.depth = depth;
		(yyval.query) = query;
	;}
    break;

  case 11:
#line 188 "l12.y"
    {
		(yyval.str) = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 12:
#line 191 "l12.y"
    {
		(yyval.str) = "main";
	;}
    break;

  case 13:
#line 196 "l12.y"
    {
		(yyvsp[(2) - (2)].funList)->funs[(yyvsp[(2) - (2)].funList)->numFuns++] = (yyvsp[(1) - (2)].fun);
		(yyval.funList) = (yyvsp[(2) - (2)].funList);
	;}
    break;

  case 14:
#line 200 "l12.y"
    {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_IDENTIFIERS * sizeof(fun_t *));
		funList->funs[funList->numFuns++] = (yyvsp[(1) - (1)].fun);
		(yyval.funList) = funList;
	;}
    break;

  case 15:
#line 209 "l12.y"
    { 
		symbol_table_item_t *item = searchSymbol((yyvsp[(2) - (2)].str), funTable);
		if (item == NULL) {
			currFun = (fun_t *)malloc(sizeof(fun_t));
			strcpy(currFun->name, (yyvsp[(2) - (2)].str));

			identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
			id->type = FUN;
			id->data.fun = currFun;
			insertSymbol(currFun->name, id, funTable);
		} else {
			currFun = item->data->data.fun;
		}

		strcpy(currScope, currFun->name);
	;}
    break;

  case 16:
#line 224 "l12.y"
    {
		currFun->neighbours = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		for (int i = 0; i < (yyvsp[(6) - (6)].funList)->numFuns; i++)
			currFun->neighbours[currFun->numNeighbours++] = (yyvsp[(6) - (6)].funList)->funs[i];

		(yyval.fun) = currFun;
	;}
    break;

  case 17:
#line 234 "l12.y"
    { 
		currFun = (fun_t *)malloc(sizeof(fun_t));
		strcpy(currFun->name, "main");

		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		id->type = FUN;
		id->data.fun = currFun;
		insertSymbol(currFun->name, id, funTable);

		strcpy(currScope, currFun->name);
	;}
    break;

  case 18:
#line 244 "l12.y"
    {
		currFun->neighbours = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		for (int i = 0; i < (yyvsp[(6) - (6)].funList)->numFuns; i++)
			currFun->neighbours[currFun->numNeighbours++] = (yyvsp[(6) - (6)].funList)->funs[i];
		(yyval.fun) = currFun;
	;}
    break;

  case 19:
#line 253 "l12.y"
    {
		(yyval.funList) = (yyvsp[(3) - (5)].funList);
	;}
    break;

  case 22:
#line 263 "l12.y"
    {
		char varStr[MAX_IDENTIFIER_LENGTH];
		sprintf(varStr, "%s_%s", currScope, (yyvsp[(2) - (3)].str));

		var_t *var = (var_t *)malloc(sizeof(var_t));
		strcpy(var->name, (yyvsp[(2) - (3)].str));

		identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		id->type = VAR;
		id->data.var = var;
		insertSymbol(varStr, id, varTable);
	;}
    break;

  case 23:
#line 278 "l12.y"
    {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		for (int i = 0; i < (yyvsp[(1) - (2)].funList)->numFuns; i++)
			funList->funs[funList->numFuns++] = (yyvsp[(1) - (2)].funList)->funs[i];
		for (int i = 0; i < (yyvsp[(2) - (2)].funList)->numFuns; i++)
			funList->funs[funList->numFuns++] = (yyvsp[(2) - (2)].funList)->funs[i];
		(yyval.funList) = funList;
	;}
    break;

  case 24:
#line 287 "l12.y"
    {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		(yyval.funList) = funList;
	;}
    break;

  case 25:
#line 295 "l12.y"
    {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		(yyval.funList) = funList;
	;}
    break;

  case 26:
#line 300 "l12.y"
    {
		(yyval.funList) = (yyvsp[(1) - (1)].funList);
	;}
    break;

  case 27:
#line 303 "l12.y"
    {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		funList->funs[funList->numFuns++] = (yyvsp[(1) - (1)].fun);
		(yyval.funList) = funList;
	;}
    break;

  case 28:
#line 313 "l12.y"
    {
		if (scopeReachability[scopeCount - 1]) {
			char varStr[MAX_IDENTIFIER_LENGTH];
			sprintf(varStr, "%s_%s", currScope, (yyvsp[(1) - (4)].str));

			symbol_table_item_t *item = searchSymbol(varStr, varTable);
			if (item == NULL)
				error("Undeclared variable");

			var_t *var = item->data->data.var;
			var->value = (yyvsp[(3) - (4)].val);
		}
	;}
    break;

  case 29:
#line 329 "l12.y"
    {
		(yyval.funList) = (yyvsp[(1) - (1)].funList);
	;}
    break;

  case 30:
#line 332 "l12.y"
    {
		(yyval.funList) = (yyvsp[(1) - (1)].funList);
	;}
    break;

  case 31:
#line 338 "l12.y"
    {
		if (!scopeReachability[scopeCount - 1])
			scopeReachability[scopeCount++] = 0;
		else
			scopeReachability[scopeCount++] = (yyvsp[(2) - (3)].val);
		(yyval.val) = (yyvsp[(2) - (3)].val);
	;}
    break;

  case 32:
#line 348 "l12.y"
    {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		if ((yyvsp[(2) - (5)].val) == 1)
			for (int i = 0; i < (yyvsp[(4) - (5)].funList)->numFuns; i++)
				funList->funs[funList->numFuns++] = (yyvsp[(4) - (5)].funList)->funs[i];
		scopeCount--;
		(yyval.funList) = funList;
	;}
    break;

  case 33:
#line 360 "l12.y"
    {
		scopeCount--;
	;}
    break;

  case 34:
#line 362 "l12.y"
    {
		fun_list_t *funList = (fun_list_t *)malloc(sizeof(fun_list_t));
		funList->funs = (fun_t **)malloc(MAX_FUNCTIONS * sizeof(fun_t *));
		if ((yyvsp[(2) - (10)].val) == 1)
			for (int i = 0; i < (yyvsp[(4) - (10)].funList)->numFuns; i++)
				funList->funs[funList->numFuns++] = (yyvsp[(4) - (10)].funList)->funs[i];
		else
			for (int i = 0; i < (yyvsp[(9) - (10)].funList)->numFuns; i++)
				funList->funs[funList->numFuns++] = (yyvsp[(9) - (10)].funList)->funs[i];
		scopeCount--;
		(yyval.funList) = funList;
	;}
    break;

  case 35:
#line 377 "l12.y"
    {
		symbol_table_item_t *item = searchSymbol((yyvsp[(1) - (4)].str), funTable);
		fun_t *fun;
		if (item == NULL) {
			fun = (fun_t *)malloc(sizeof(fun_t));
			strcpy(fun->name, (yyvsp[(1) - (4)].str));
			identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
			id->type = FUN;
			id->data.fun = fun;
			insertSymbol(fun->name, id, funTable);
		} else {
			fun = item->data->data.fun;
		}
		(yyval.fun) = fun;
	;}
    break;

  case 36:
#line 395 "l12.y"
    {
		(yyval.val) = (yyvsp[(1) - (3)].val) && (yyvsp[(3) - (3)].val);
	;}
    break;

  case 37:
#line 398 "l12.y"
    {
		(yyval.val) = (yyvsp[(1) - (3)].val) || (yyvsp[(3) - (3)].val);
	;}
    break;

  case 38:
#line 401 "l12.y"
    {
		(yyval.val) = (yyvsp[(2) - (3)].val);
	;}
    break;

  case 39:
#line 404 "l12.y"
    {
		switch ((yyvsp[(2) - (3)].cmp)) {
			case COMPAR_EQ:
				(yyval.val) = (yyvsp[(1) - (3)].val) == (yyvsp[(3) - (3)].val);
				break;
			case COMPAR_LT:
				(yyval.val) = (yyvsp[(1) - (3)].val) < (yyvsp[(3) - (3)].val);
				break;
			case COMPAR_GT:
				(yyval.val) = (yyvsp[(1) - (3)].val) > (yyvsp[(3) - (3)].val);
				break;
			default:
				error("Invalid comparison operation");
		}
	;}
    break;

  case 40:
#line 422 "l12.y"
    {
		(yyval.val) = (yyvsp[(1) - (3)].val) + (yyvsp[(3) - (3)].val);
	;}
    break;

  case 41:
#line 425 "l12.y"
    {
		(yyval.val) = (yyvsp[(1) - (3)].val) - (yyvsp[(3) - (3)].val);
	;}
    break;

  case 42:
#line 428 "l12.y"
    {
		(yyval.val) = (yyvsp[(2) - (3)].val);
	;}
    break;

  case 43:
#line 431 "l12.y"
    {
		char varStr[MAX_IDENTIFIER_LENGTH];
		sprintf(varStr, "%s_%s", currScope, (yyvsp[(1) - (1)].str));

		symbol_table_item_t *item = searchSymbol(varStr, varTable);
		if (item == NULL)
			error("Undeclared variable");
		var_t *var = item->data->data.var;
		(yyval.val) = var->value;
	;}
    break;

  case 44:
#line 441 "l12.y"
    {
		(yyval.val) = (yyvsp[(1) - (1)].val);
	;}
    break;

  case 45:
#line 447 "l12.y"
    {
		if (streq(mytext, "==", 2))
			(yyval.cmp) = COMPAR_EQ;
		else if (streq(mytext, "<", 1))
			(yyval.cmp) = COMPAR_LT;
		else if (streq(mytext, ">", 1))
			(yyval.cmp) = COMPAR_GT;
		else {
			printf("%s\n", mytext);
			error("Unsupported comparison operator");
		}
	;}
    break;

  case 46:
#line 462 "l12.y"
    {
		(yyval.str) = strdup(mytext);
	;}
    break;

  case 47:
#line 468 "l12.y"
    {
		(yyval.val) = atoi(mytext);
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 2003 "l12.tab.c"
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


#line 478 "l12.y"


void yyerror(char *message) {
	fprintf(stderr, "syntax error\n");
	exit(1);
}

void error(char *message) {
	perror(message);
	exit(1);
}

int main() {
	funList = (fun_list_t *)malloc(sizeof(fun_list_t));
	queryList = (query_list_t *)malloc(sizeof(query_list_t));
	yyparse();

	symbol_table_item_t *item = searchSymbol("main", funTable);
	if (item == NULL)
		error("Main function not found");

	fun_t *mainFunction = item->data->data.fun;
	query_t *query;
	bool res;
	for (int i = 0; i < queryList->queryCount; i++) {
		query = queryList->queries[i];
		switch (query->type) {
			case DEAD:
				reachable(mainFunction, query->query.dead->fun)
				? printf("No") : printf("Yes");
				break;
			case REACHABLE:
				reachable(query->query.reach->src, query->query.reach->dest)
				? printf("Yes") : printf("No");
				break;
			case SELF_RECURSIVE:
				isSelfRecursive(query->query.selfRecursive->fun)
				? printf("Yes") : printf("No");
				break;
			case EVENTUALLY_RECURSIVE:
				!isSelfRecursive(query->query.selfRecursive->fun)
				&& reachable(query->query.selfRecursive->fun, query->query.selfRecursive->fun)
				? printf("Yes") : printf("No");
				break;
			case CO_RECURSIVE:
				isCoRecursive(query->query.coRecursive->fun1, query->query.coRecursive->fun2)
				? printf("Yes") : printf("No");
				break;
			case DEPTH:
				printf("%d", depth(query->query.depth->fun));
				break;
		}
		printf("\n");
		flushVisited();
	}
}

unsigned long hash(char *str) {
	unsigned long hash = 5381;
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
	if (item != NULL)
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

void flushVisited() {
	for (int i = 0; i < funList->numFuns; i++)
		funList->funs[i]->visited = false;
}

bool reachable(fun_t *start, fun_t *target) {
	if (start->visited)
		return false;

	start->visited = true;

	for (int i = 0; i < start->numNeighbours; i++) {
		fun_t *neighbour = start->neighbours[i];
		if (neighbour == target)
			return true;
		if (reachable(neighbour, target))
			return true;
	}
	return false;
}

bool isSelfRecursive(fun_t *fun) {
	for (int i = 0; i < fun->numNeighbours; i++)
		if (fun->neighbours[i] == fun)
			return true;
	return false;
}

bool isCoRecursive(fun_t *fun1, fun_t *fun2) {
	bool flag = false;
	for (int i = 0; i < fun1->numNeighbours; i++)
		if (fun1->neighbours[i] == fun2) {
			flag = true;
			break;
		}

	if (!flag)
		return false;

	for (int i = 0; i < fun2->numNeighbours; i++)
		if (fun2->neighbours[i] == fun1)
			return true;

	return false;
}

int depth(fun_t *fun) {
	if (isSelfRecursive(fun) || reachable(fun, fun)) {
		flushVisited();
		return -1;
	}

	fun->visited = true;

	int d = 0;
	for (int i = 0; i < fun->numNeighbours; i++) {
		fun_t *neighbour = fun->neighbours[i];
		int res = depth(neighbour);
		if (res == -1)
			return -1;

		d = max(d, 1 + res);
	}

	return d;
}

int max(int a, int b) {
	return a > b ? a : b;
}

