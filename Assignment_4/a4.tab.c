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




/* Copy the first part of user declarations.  */
#line 1 "a4.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "a4.h"

void yyerror(char *);
char mytext[100];
extern int yylex(void);
extern FILE *yyin;
int lineNumber = 1;

program_t *program;
symbol_table_item_t *labelTable[MAX_LINES];
symbol_table_item_t *symbolTable[MAX_IDENTIFIERS];


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
#line 26 "a4.y"
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
/* Line 193 of yacc.c.  */
#line 160 "a4.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 173 "a4.tab.c"

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
#define YYLAST   35

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  17
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  31
/* YYNRULES -- Number of states.  */
#define YYNSTATES  45

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   271

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
      15,    16
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      19,    21,    25,    29,    33,    37,    41,    43,    45,    50,
      52,    54,    61,    64,    67,    70,    73,    75,    77,    79,
      81,    83
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      18,     0,    -1,    19,    -1,    19,    20,    -1,    -1,    21,
      -1,    23,    -1,    25,    -1,    26,    -1,    27,    -1,    28,
      -1,    30,    10,    22,    -1,    30,    31,    30,    -1,    30,
      31,    29,    -1,    29,    31,    30,    -1,    29,    31,    29,
      -1,    30,    -1,    29,    -1,    30,    10,    24,    30,    -1,
       4,    -1,     7,    -1,    11,    30,     8,    30,    12,    30,
      -1,    12,    30,    -1,    30,     9,    -1,    13,    30,    -1,
      14,    30,    -1,    15,    -1,    16,    -1,     3,    -1,     4,
      -1,     5,    -1,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    60,    77,    85,    92,    99,   106,   113,
     121,   131,   140,   149,   158,   167,   176,   183,   193,   202,
     203,   207,   217,   225,   233,   239,   248,   254,   269,   270,
     271,   272
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "NOT", "COMPAR", "COLON", "EQ", "IF", "GOTO", "PRINT", "READ",
  "NUMBER_TOK", "IDENTIFIER_TOK", "$accept", "program", "lines", "line",
  "assignmentStatement", "expression", "unaryAssignmentStatement",
  "unaryOperator", "conditionalJump", "unconditionalJump",
  "labelDefinition", "ioStatement", "number", "identifier", "operator", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    17,    18,    19,    19,    20,    20,    20,    20,    20,
      20,    21,    22,    22,    22,    22,    22,    22,    23,    24,
      24,    25,    26,    27,    28,    28,    29,    30,    31,    31,
      31,    31
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     1,     1,     4,     1,
       1,     6,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,    27,     3,
       5,     6,     7,     8,     9,    10,     0,     0,    22,    24,
      25,    23,     0,     0,    19,    20,    26,    11,     0,    17,
      16,     0,    18,    28,    29,    30,    31,     0,     0,     0,
      15,    14,    13,    12,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     9,    10,    27,    11,    28,    12,    13,
      14,    15,    29,    16,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -11
static const yytype_int8 yypact[] =
{
     -11,    12,    -3,   -11,    -2,    -2,    -2,    -2,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,    16,     9,   -11,   -11,
     -11,   -11,     0,    -2,   -11,   -11,   -11,   -11,    -2,    17,
      17,    15,   -11,   -11,   -11,   -11,   -11,   -10,   -10,    -2,
     -11,   -11,   -11,   -11,   -11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,    -9,    -4,     1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      17,    18,    19,    20,    24,    26,     8,    25,     4,     5,
       6,     7,     3,     8,     8,    26,     8,    23,    30,    31,
      33,    34,    35,    36,    32,    21,    22,    39,    40,    42,
       0,    38,     0,    41,    43,    44
};

static const yytype_int8 yycheck[] =
{
       4,     5,     6,     7,     4,    15,    16,     7,    11,    12,
      13,    14,     0,    16,    16,    15,    16,     8,    22,    23,
       3,     4,     5,     6,    28,     9,    10,    12,    37,    38,
      -1,    30,    -1,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    19,     0,    11,    12,    13,    14,    16,    20,
      21,    23,    25,    26,    27,    28,    30,    30,    30,    30,
      30,     9,    10,     8,     4,     7,    15,    22,    24,    29,
      30,    30,    30,     3,     4,     5,     6,    31,    31,    12,
      29,    30,    29,    30,    30
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
#line 54 "a4.y"
    {
		program->lineList = (yyvsp[(1) - (1)].lineList);
	;}
    break;

  case 3:
#line 60 "a4.y"
    {
		(yyvsp[(2) - (2)].line)->prev = (line_list_t *)calloc(1, sizeof(line_list_t));
		(yyvsp[(2) - (2)].line)->prev->lines = (line_t **)calloc(MAX_LINES, sizeof(line_t *));
		(yyvsp[(2) - (2)].line)->next = (line_list_t *)calloc(1, sizeof(line_list_t));
		(yyvsp[(2) - (2)].line)->next->lines = (line_t **)calloc(MAX_LINES, sizeof(line_t *));
		(yyvsp[(2) - (2)].line)->in = (id_list_t *)calloc(1, sizeof(id_list_t));
		(yyvsp[(2) - (2)].line)->in->ids = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));
		(yyvsp[(2) - (2)].line)->out = (id_list_t *)calloc(1, sizeof(id_list_t));
		(yyvsp[(2) - (2)].line)->out->ids = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));
		(yyvsp[(2) - (2)].line)->use = (id_list_t *)calloc(1, sizeof(id_list_t));
		(yyvsp[(2) - (2)].line)->use->ids = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));
		(yyvsp[(2) - (2)].line)->def = (id_list_t *)calloc(1, sizeof(id_list_t));
		(yyvsp[(2) - (2)].line)->def->ids = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));

		(yyvsp[(1) - (2)].lineList)->lines[(yyvsp[(1) - (2)].lineList)->lineCount++] = (yyvsp[(2) - (2)].line);
		lineNumber++;
	;}
    break;

  case 4:
#line 77 "a4.y"
    {
		line_list_t *lineList = (line_list_t *)calloc(1, sizeof(line_list_t));
		lineList->lines = (line_t **)calloc(MAX_LINES, sizeof(line_t *));
		(yyval.lineList) = lineList;
	;}
    break;

  case 5:
#line 85 "a4.y"
    {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = ASS;
		line->line.ass = (yyvsp[(1) - (1)].ass);
		line->lineNumber = lineNumber;
		(yyval.line) = line;
	;}
    break;

  case 6:
#line 92 "a4.y"
    {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = UASS;
		line->line.uass = (yyvsp[(1) - (1)].uass);
		line->lineNumber = lineNumber;
		(yyval.line) = line;
	;}
    break;

  case 7:
#line 99 "a4.y"
    {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = COND_JUMP;
		line->line.condJump = (yyvsp[(1) - (1)].condJump);
		line->lineNumber = lineNumber;
		(yyval.line) = line;
	;}
    break;

  case 8:
#line 106 "a4.y"
    {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = UNCOND_JUMP;
		line->line.uncondJump = (yyvsp[(1) - (1)].ucondJump);
		line->lineNumber = lineNumber;
		(yyval.line) = line;
	;}
    break;

  case 9:
#line 113 "a4.y"
    {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = LABEL_DEF;
		line->line.labelDef = (yyvsp[(1) - (1)].labelDef);
		line->lineNumber = lineNumber;
		insertSymbol(line->line.labelDef->value->value, line, labelTable);
		(yyval.line) = line;
	;}
    break;

  case 10:
#line 121 "a4.y"
    {
		line_t *line = (line_t *)calloc(1, sizeof(line_t));
		line->type = IO;
		line->line.io = (yyvsp[(1) - (1)].io);
		line->lineNumber = lineNumber;
		(yyval.line) = line;
	;}
    break;

  case 11:
#line 131 "a4.y"
    {
		ass_t *ass = (ass_t *)calloc(1, sizeof(ass_t));
		ass->id = (yyvsp[(1) - (3)].id);
		ass->exp = (yyvsp[(3) - (3)].exp);
		(yyval.ass) = ass;
	;}
    break;

  case 12:
#line 140 "a4.y"
    {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = IDENTIFIER;
		exp->rType = IDENTIFIER;
		exp->isBinOp = true;
		exp->lValue.id = (yyvsp[(1) - (3)].id);
		exp->rValue.id = (yyvsp[(3) - (3)].id);
		(yyval.exp) = exp;
	;}
    break;

  case 13:
#line 149 "a4.y"
    {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = IDENTIFIER;
		exp->rType = NUMBER;
		exp->isBinOp = true;
		exp->lValue.id = (yyvsp[(1) - (3)].id);
		exp->rValue.val = (yyvsp[(3) - (3)].val);
		(yyval.exp) = exp;
	;}
    break;

  case 14:
#line 158 "a4.y"
    {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = NUMBER;
		exp->rType = IDENTIFIER;
		exp->isBinOp = true;
		exp->lValue.val = (yyvsp[(1) - (3)].val);
		exp->rValue.id = (yyvsp[(3) - (3)].id);
		(yyval.exp) = exp;
	;}
    break;

  case 15:
#line 167 "a4.y"
    {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = NUMBER;
		exp->rType = NUMBER;
		exp->isBinOp = true;
		exp->lValue.val = (yyvsp[(1) - (3)].val);
		exp->rValue.val = (yyvsp[(3) - (3)].val);
		(yyval.exp) = exp;
	;}
    break;

  case 16:
#line 176 "a4.y"
    {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = IDENTIFIER;
		exp->isBinOp = false;
		exp->lValue.id = (yyvsp[(1) - (1)].id);
		(yyval.exp) = exp;
	;}
    break;

  case 17:
#line 183 "a4.y"
    {
		exp_t *exp = (exp_t *)calloc(1, sizeof(exp_t));
		exp->lType = NUMBER;
		exp->isBinOp = false;
		exp->lValue.val = (yyvsp[(1) - (1)].val);
		(yyval.exp) = exp;
	;}
    break;

  case 18:
#line 193 "a4.y"
    {
		u_ass_t *ass = (u_ass_t *)calloc(1, sizeof(u_ass_t));
		ass->lid = (yyvsp[(1) - (4)].id);
		ass->rid = (yyvsp[(4) - (4)].id);
		(yyval.uass) = ass;
	;}
    break;

  case 21:
#line 207 "a4.y"
    {
		cond_jump_t *jump = (cond_jump_t *)calloc(1, sizeof(cond_jump_t));
		jump->lid = (yyvsp[(2) - (6)].id);
		jump->rid = (yyvsp[(4) - (6)].id);
		jump->label = (yyvsp[(6) - (6)].id);
		(yyval.condJump) = jump;
	;}
    break;

  case 22:
#line 217 "a4.y"
    {
		uncond_jump_t *jump = (uncond_jump_t *)calloc(1, sizeof(uncond_jump_t));
		jump->label = (yyvsp[(2) - (2)].id);
		(yyval.ucondJump) = jump;
	;}
    break;

  case 23:
#line 225 "a4.y"
    {
		label_def_t *labelDef = (label_def_t *)calloc(1, sizeof(label_def_t));
		labelDef->value = (yyvsp[(1) - (2)].id);
		(yyval.labelDef) = labelDef;
	;}
    break;

  case 24:
#line 233 "a4.y"
    {
		io_t *io = (io_t *)calloc(1, sizeof(io_t));
		io->id = (yyvsp[(2) - (2)].id);
		io->type = IO_PRINT;
		(yyval.io) = io;
	;}
    break;

  case 25:
#line 239 "a4.y"
    {
		io_t *io = (io_t *)calloc(1, sizeof(io_t));
		io->id = (yyvsp[(2) - (2)].id);
		io->type = IO_READ;
		(yyval.io) = io;
	;}
    break;

  case 26:
#line 248 "a4.y"
    {
		(yyval.val) = atoi(mytext);
	;}
    break;

  case 27:
#line 254 "a4.y"
    {
		symbol_table_item_t *item = searchSymbol(mytext, symbolTable);
		identifier_t *id;
		if (item == NULL) {
			id = (identifier_t *)calloc(1, sizeof(identifier_t));
			strcpy(id->value, mytext);
			insertSymbol(id->value, id, symbolTable);
		} else {
		    id = (identifier_t *) item->data;
		}
		(yyval.id) = id;
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 1669 "a4.tab.c"
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


#line 275 "a4.y"


void yyerror(char *message) {
    fprintf(stderr, "syntax error: %d\n", lineNumber);
    exit(1);
}

void error(char *message) {
    perror(message);
	exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3)
        error("Incorrect input arguments");

	const char *tacFileName = argv[1];
	const char *queryFileName = argv[2];

    FILE *tacFile = fopen(tacFileName, "r");
    if (tacFile == NULL)
        error("Error opening TAC file");

    program = (program_t *)calloc(1, sizeof(program_t));

	yyin = tacFile;
    yyparse();
	fclose(tacFile);

    FILE *queryFile = fopen(queryFileName, "r");
    if (queryFile == NULL)
        error("Error opening query file");

    int value;
    while (fscanf(queryFile, "%d", &value) == 1)
        program->queries[program->queryCount++] = value;

	constructCFG(program->lineList);
	// stringifyCFG(program->lineList->lines[0], program->lineList->lineCount);

	firstPass(program->lineList);
	secondPass(program->lineList);
	fixupPass(program->lineList);
	flushVisited();

	optimiseTAC(program->lineList->lines[program->lineList->lineCount - 1]);

	resolveQueries();

    return 0;
}

void resolveQueries() {
	int query;
	line_t *line;
	for (int i = 0; i < program->queryCount; i++) {
		query = program->queries[i];
		line = program->lineList->lines[query - 1];
		if (line->isDeleted)
		    printf("Line removed in optimized TAC\n");
		else
		    printSet(line->out);
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

void insertSymbol(char *key, void *data, symbol_table_item_t* hashTable[]) {
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

void constructCFG(line_list_t *lineList) {
	line_t *line;
	line_t *nextLine;
	symbol_table_item_t *item;
    for (int i = 0; i < lineList->lineCount; i++) {
		line = lineList->lines[i];
		if (i < lineList->lineCount - 1)
		    nextLine = lineList->lines[i + 1];
		else
		    nextLine = NULL;

		switch (line->type) {
		case ASS:
			if (nextLine != NULL) {
				line->next->lines[line->next->lineCount++] = nextLine;
				nextLine->prev->lines[nextLine->prev->lineCount++] = line;
			}
		    break;
		case UASS:
			if (nextLine != NULL) {
				line->next->lines[line->next->lineCount++] = nextLine;
				nextLine->prev->lines[nextLine->prev->lineCount++] = line;
			}
		    break;
		case COND_JUMP:
			if (nextLine != NULL) {
				line->next->lines[line->next->lineCount++] = nextLine;
				nextLine->prev->lines[nextLine->prev->lineCount++] = line;
			}
			item = searchSymbol(line->line.condJump->label->value, labelTable);
			nextLine = (line_t *)item->data;
			line->next->lines[line->next->lineCount++] = nextLine;
			nextLine->prev->lines[nextLine->prev->lineCount++] = line;
		    break;
		case UNCOND_JUMP:
			item = searchSymbol(line->line.uncondJump->label->value, labelTable);
			nextLine = (line_t *)item->data;
			line->next->lines[line->next->lineCount++] = nextLine;
			nextLine->prev->lines[nextLine->prev->lineCount++] = line;
		    break;
		case LABEL_DEF:
			if (nextLine != NULL) {
				line->next->lines[line->next->lineCount++] = nextLine;
				nextLine->prev->lines[nextLine->prev->lineCount++] = line;
			}
		    break;
		case IO:
			if (nextLine != NULL) {
				line->next->lines[line->next->lineCount++] = nextLine;
				nextLine->prev->lines[nextLine->prev->lineCount++] = line;
			}
		    break;
		}
	}
}

void dfs(line_t *node, int *visited) {
    if (node == NULL || visited[node->lineNumber]) {
        return;
    }

    visited[node->lineNumber] = 1;

    printf("  Node%d [label=\"Line %d\"];\n", node->lineNumber, node->lineNumber);

    if (node->next != NULL) {
        for (int i = 0; i < node->next->lineCount; i++) {
            line_t *nextLine = node->next->lines[i];
            if (nextLine != NULL) {
                printf("  Node%d -> Node%d;\n", node->lineNumber, nextLine->lineNumber);
                
                dfs(nextLine, visited);
            }
        }
    }
}

void stringifyCFG(line_t *root, int maxNodes) {
    printf("digraph CFG {\n");
    printf("  node [shape=box];\n");

    int *visited = (int *)calloc(maxNodes, sizeof(int));

    dfs(root, visited);

    printf("}\n");

    free(visited);
}

void firstPass(line_list_t *lineList) {
	line_t *line;
    for (int i = 0; i < lineList->lineCount; i++) {
		line = lineList->lines[i];
		computeUseDefSets(line);
	}
}

void secondPass(line_list_t *lineList) {
	line_t *line;
	bool printFound = false;
	for (int i = lineList->lineCount - 1; i >= 0; i--) {
		line = lineList->lines[i];
		if ((line->type != IO || line->line.io->type == IO_READ) && !printFound) {
			line->isDeleted = true;
			continue;
		}

		printFound = true;
		computeOutSet(line);
		computeInSet(line);
	}
}

void fixupPass(line_list_t *lineList) {
	line_t *line;
    for (int i = 0; i < lineList->lineCount; i++) {
		line = lineList->lines[i];
		if (line->type == COND_JUMP || line->type == UNCOND_JUMP) {
		    computeOutSet(line);
		    computeInSet(line);
			for (int j = 0; j < line->prev->lineCount; j++) {
				backProp(line->prev->lines[j]);
				flushVisited();
		    }
		}
	}
}

void computeOutSet(line_t *line) {
	line->out->idCount = 0;
	line_t *nextLine;
    for (int i = 0; i < line->next->lineCount; i++) {
		nextLine = line->next->lines[i];
		combineSets(line->out, nextLine->in);
	}
}

void computeInSet(line_t *line) {
	line->in->idCount = 0;
    combineSets(line->in, line->use);
	id_list_t *outDefDiff = diffSets(line->out, line->def);
    combineSets(line->in, outDefDiff);
}

void combineSets(id_list_t *set1, id_list_t *set2) {
	identifier_t *id;
    for (int i = 0; i < set2->idCount; i++) {
		bool elementFound = false;
		id = set2->ids[i];
		for (int j = 0; j < set1->idCount; j++) {
		    if (set1->ids[j] == id) {
				elementFound = true;
				break;
			}
		}
		if (!elementFound) {
		    set1->ids[set1->idCount++] = id;
		}
	}
}

id_list_t *diffSets(id_list_t *set1, id_list_t *set2) {
	id_list_t *idList = (id_list_t *)calloc(1, sizeof(id_list_t));
	idList->ids = (identifier_t **)calloc(MAX_IDENTIFIERS, sizeof(identifier_t *));
	identifier_t *id;
    for (int i = 0; i < set1->idCount; i++) {
		bool elementFound = false;
		id = set1->ids[i];
		for (int j = 0; j < set2->idCount; j++) {
		    if (set2->ids[j] == id) {
				elementFound = true;
				break;
			}
		}
		if (!elementFound)
		    idList->ids[idList->idCount++] = id;
	}
	return idList;
}

void printSet(id_list_t *idList) {
	qsort(idList->ids, idList->idCount, sizeof(identifier_t *), compareLex);
    for (int i = 0; i < idList->idCount; i++)
		printf("%s ", idList->ids[i]->value);
    printf("\n");
}

void optimiseTAC(line_t *line) {
	if (line->optimised)
		return;

	line->optimised = true;
    if (removable(line)) {
		deleteLine(line);
		for (int i = 0; i < line->prev->lineCount; i++) {
		    backProp(line->prev->lines[i]);
			flushVisited();
		}
	}
	for (int i = 0; i < line->prev->lineCount; i++) {
		optimiseTAC(line->prev->lines[i]);
	}
}

void flushVisited() {
    for (int i = 0; i < program->lineList->lineCount; i++)
		program->lineList->lines[i]->visited = false;
}

bool removable(line_t *line) {
    if (line->type != ASS && line->type != UASS)
		return false;

    identifier_t *defElement = line->def->ids[0];
	for (int i = 0; i < line->out->idCount; i++)
		if (line->out->ids[i] == defElement)
		    return false;

    return true;
}

void backProp(line_t *line) {
	if (line->visited)
		return;

	line->visited = true;
	computeUseDefSets(line);
	computeOutSet(line);
	computeInSet(line);
	for (int i = 0; i < line->prev->lineCount; i++)
		backProp(line->prev->lines[i]);
}

void computeUseDefSets(line_t *line) {
	line->use->idCount = 0;
	line->def->idCount = 0;

    if (line->type == ASS) {
	    line->def->ids[line->def->idCount++] = line->line.ass->id;
	    if (line->line.ass->exp->lType == IDENTIFIER)
		    line->use->ids[line->use->idCount++] = line->line.ass->exp->lValue.id;
	    if (line->line.ass->exp->isBinOp && line->line.ass->exp->rType == IDENTIFIER)
		    line->use->ids[line->use->idCount++] = line->line.ass->exp->rValue.id;
    } else if (line->type == IO && line->line.io->type == IO_READ) {
	    line->def->ids[line->def->idCount++] = line->line.io->id;
    } else if (line->type == IO && line->line.io->type == IO_PRINT) {
	    line->use->ids[line->use->idCount++] = line->line.io->id;
    } else if (line->type == UASS) {
	    line->def->ids[line->def->idCount++] = line->line.uass->lid;
	    line->use->ids[line->use->idCount++] = line->line.uass->rid;
    } else if (line->type == COND_JUMP) {
	    line->use->ids[line->use->idCount++] = line->line.condJump->lid;
	    line->use->ids[line->use->idCount++] = line->line.condJump->rid;
    }
}

void deleteLine(line_t *line) {
    line->isDeleted = true;
	line->in->idCount = 0;
	line->out->idCount = 0;
	line->use->idCount = 0;
	line->def->idCount = 0;

	line_t *prevLine = line->prev->lines[0];
	line_t *nextLine = line->next->lines[0];

	if (prevLine != NULL) {
		for (int i = 0; i < prevLine->next->lineCount; i++) {
			if (prevLine->next->lines[i] != line)
				continue;

		    if (nextLine != NULL) {
				prevLine->next->lines[i] = nextLine;
		    } else {
				prevLine->next->lines[i] = prevLine->next->lines[prevLine->next->lineCount - 1];
				prevLine->next->lineCount--;
		    }
			break;
		}
	}

	if (nextLine != NULL) {
		for (int i = 0; i < nextLine->prev->lineCount; i++) {
			if (nextLine->prev->lines[i] != line)
				continue;

		    if (prevLine != NULL) {
				nextLine->prev->lines[i] = prevLine;
		    } else {
				nextLine->prev->lines[i] = nextLine->prev->lines[nextLine->prev->lineCount - 1];
				nextLine->prev->lineCount--;
		    }
			break;
		}
	}
}

int compareLex(const void *a, const void *b) {
    identifier_t *idA = *(identifier_t **)a;
    identifier_t *idB = *(identifier_t **)b;
    return strcmp(idA->value, idB->value);
}

