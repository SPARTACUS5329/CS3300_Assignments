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
     PLUS = 268,
     MINUS = 269,
     MULTIPLY = 270,
     DIVIDE = 271,
     EXPONENT = 272,
     VALID_TYPE = 273,
     IDENTIFIER = 274,
     NUMBER = 275,
     STRING = 276,
     IF = 277,
     ELSE = 278,
     WHILE = 279,
     FOR = 280,
     RETURN = 281,
     MAIN = 282,
     UMINUS = 283
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
#define PLUS 268
#define MINUS 269
#define MULTIPLY 270
#define DIVIDE 271
#define EXPONENT 272
#define VALID_TYPE 273
#define IDENTIFIER 274
#define NUMBER 275
#define STRING 276
#define IF 277
#define ELSE 278
#define WHILE 279
#define FOR 280
#define RETURN 281
#define MAIN 282
#define UMINUS 283




/* Copy the first part of user declarations.  */
#line 1 "a2.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "a2.h"
#define streq(str1, str2, n) (strncmp(str1, str2, n) == 0)

void yyerror(char *);
int yylex(void);
char mytext[100];
char currType[10];
char currScope[MAX_IDENTIFIER_LENGTH] = "global";
int lineNumber = 1;
static int tCount = 0;
static int lCount = 0;

hash_table_item_t *symbolTable[MAX_IDENTIFIERS];


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
#line 34 "a2.y"
{
    char *str;
    int val;
    identifier_t id;
    expression_t exp;
}
/* Line 193 of yacc.c.  */
#line 179 "a2.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 192 "a2.tab.c"

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
#define YYLAST   201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    17,    19,    21,    24,
      26,    28,    31,    33,    35,    37,    39,    43,    45,    49,
      53,    55,    60,    62,    65,    67,    70,    74,    79,    80,
      82,    86,    88,    90,    94,    98,   102,   106,   110,   114,
     117,   121,   123,   125,   132,   134,   138,   141,   142,   144,
     148,   151,   159,   165,   167,   169,   175,   186,   188,   192,
     194,   197,   199,   201,   203,   205
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      30,     0,    -1,    31,    32,    -1,    -1,    31,    47,    -1,
      59,    33,     3,    50,     4,    56,    -1,    27,    -1,    35,
      -1,    35,    34,    -1,    36,    -1,    39,    -1,    46,    11,
      -1,    49,    -1,    52,    -1,    53,    -1,    47,    -1,    59,
      37,    11,    -1,    38,    -1,    38,     9,    37,    -1,    40,
      12,    46,    -1,    40,    -1,    40,    12,    46,    11,    -1,
      60,    -1,    60,    41,    -1,    42,    -1,    42,    41,    -1,
       7,    58,     8,    -1,    60,     3,    44,     4,    -1,    -1,
      45,    -1,    45,     9,    44,    -1,    46,    -1,    21,    -1,
      46,    13,    46,    -1,    46,    14,    46,    -1,    46,    10,
      46,    -1,    46,    15,    46,    -1,    46,    16,    46,    -1,
      46,    17,    46,    -1,    14,    46,    -1,     3,    46,     4,
      -1,    43,    -1,    57,    -1,    59,    48,     3,    50,     4,
      56,    -1,    60,    -1,    26,    46,    11,    -1,    26,    11,
      -1,    -1,    51,    -1,    51,     9,    50,    -1,    59,    40,
      -1,    22,     3,    46,     4,    56,    23,    56,    -1,    22,
       3,    46,     4,    56,    -1,    54,    -1,    55,    -1,    24,
       3,    46,     4,    56,    -1,    25,     3,    39,    46,    11,
      40,    12,    46,     4,    56,    -1,    35,    -1,     5,    34,
       6,    -1,    60,    -1,    60,    41,    -1,    20,    -1,    60,
      -1,    20,    -1,    18,    -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    51,    52,    56,    60,    67,    68,    73,
      74,    75,    76,    77,    78,    79,    82,    85,    86,    89,
      96,    99,   112,   123,   136,   139,   144,   147,   150,   151,
     152,   155,   156,   159,   166,   173,   180,   187,   194,   201,
     208,   213,   217,   233,   239,   246,   250,   255,   256,   257,
     260,   263,   264,   267,   268,   271,   274,   277,   278,   281,
     288,   295,   304,   305,   308,   315
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPEN_PAREN", "CLOSE_PAREN",
  "OPEN_BRACE", "CLOSE_BRACE", "OPEN_SQUARE", "CLOSE_SQUARE", "COMMA",
  "COMPAR", "SEMI_COLON", "EQ", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "EXPONENT", "VALID_TYPE", "IDENTIFIER", "NUMBER", "STRING", "IF", "ELSE",
  "WHILE", "FOR", "RETURN", "MAIN", "UMINUS", "$accept", "program",
  "functionBlocks", "mainFunction", "mainIdentifier", "lines", "line",
  "declarationStatement", "declarations", "declaration", "assignment",
  "assignable", "subscripts", "subscript", "functionCall", "arguments",
  "argument", "expression", "functionBlock", "functionIdentifier",
  "returnStatement", "parameters", "parameter", "ifStatement",
  "loopStatement", "whileStatement", "forStatement", "body", "term",
  "index", "validType", "identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    31,    31,    32,    33,    34,    34,    35,
      35,    35,    35,    35,    35,    35,    36,    37,    37,    38,
      38,    39,    40,    40,    41,    41,    42,    43,    44,    44,
      44,    45,    45,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    47,    48,    49,    49,    50,    50,    50,
      51,    52,    52,    53,    53,    54,    55,    56,    56,    57,
      57,    57,    58,    58,    59,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     6,     1,     1,     2,     1,
       1,     2,     1,     1,     1,     1,     3,     1,     3,     3,
       1,     4,     1,     2,     1,     2,     3,     4,     0,     1,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     1,     1,     6,     1,     3,     2,     0,     1,     3,
       2,     7,     5,     1,     1,     5,    10,     1,     3,     1,
       2,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,    64,     2,     4,     0,    65,     6,
       0,     0,    44,    47,    47,     0,    48,     0,     0,     0,
      47,    50,    22,     0,     0,     0,     0,    61,     0,     0,
       0,     0,    57,     9,    10,     0,    41,     0,    15,    12,
      13,    14,    53,    54,     5,    42,     0,    59,    49,     0,
      23,    24,    43,     0,    59,     0,     7,    39,     0,     0,
       0,    46,     0,     0,     0,    11,     0,     0,     0,     0,
       0,     0,    17,    20,    22,    28,    60,    63,     0,    62,
      25,    40,    60,    58,     8,     0,     0,     0,    45,     0,
      35,    33,    34,    36,    37,    38,    16,     0,     0,    32,
       0,    29,    31,    26,     0,     0,     0,    21,    18,    19,
      27,    28,    52,    55,     0,    30,     0,     0,    51,     0,
       0,     0,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,    10,    55,    32,    33,    71,    72,
      34,    35,    50,    51,    36,   100,   101,    37,    38,    11,
      39,    15,    16,    40,    41,    42,    43,    44,    45,    78,
      46,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -23
static const yytype_int16 yypact[] =
{
     -23,     2,   -10,   -23,   -23,   -23,   -23,   -12,   -23,   -23,
       8,    24,   -23,   -10,   -10,    33,    32,    28,    60,    26,
     -10,   -23,    59,    26,     3,    86,     3,   -23,    72,    73,
      75,    66,   -23,   -23,   -23,    69,   -23,   144,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,    28,    53,   -23,     5,
     -23,    59,   -23,   112,     6,    81,    86,    71,     3,     3,
      28,   -23,   152,     3,     3,   -23,     3,     3,     3,     3,
       3,    82,    83,    84,    31,     0,    91,   -23,    87,   -23,
     -23,   -23,   -23,   -23,   -23,   120,   128,     3,   -23,   160,
      42,    42,    42,    71,    71,    71,   -23,    28,     3,   -23,
     109,   108,   176,   -23,    26,    26,   168,   -23,   -23,   176,
     -23,     0,    95,   -23,    28,   -23,    26,   107,   -23,     3,
     136,    26,   -23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -23,   -23,   -23,   -23,   -23,    64,   -20,   -23,    34,   -23,
      61,   -13,   147,   -23,   -23,    36,   -23,     4,   137,   -23,
     -23,    12,   -23,   -23,   -23,   -23,   -23,   -22,   -23,   -23,
      41,    -7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -45
static const yytype_int8 yytable[] =
{
      12,    52,     3,    24,    21,    56,    24,     8,     4,    75,
      22,    13,    47,    49,    26,     9,    47,    26,    47,     8,
      27,    99,     8,    27,     8,    77,    18,    14,    53,    24,
      57,    25,    48,    73,   -44,    62,    56,    19,    49,    74,
      26,    20,    79,     7,     4,     8,    27,     8,    28,    47,
      29,    30,    31,    22,    17,    17,    75,    68,    69,    70,
      49,    17,    85,    86,    23,   -22,    49,    89,    90,    24,
      91,    92,    93,    94,    95,    58,    59,    61,    60,   102,
      26,    63,   112,   113,    73,     8,    27,    83,    70,    24,
      22,   106,    97,    96,   118,   103,    98,    47,    47,   122,
      26,   117,   109,   -23,     4,     8,    27,    22,    28,    47,
      29,    30,    31,   110,    47,   102,    81,   111,   116,   119,
      84,    87,    64,   120,   104,    66,    67,    68,    69,    70,
      64,   108,   105,    66,    67,    68,    69,    70,    64,     6,
     121,    66,    67,    68,    69,    70,    64,   115,     0,    66,
      67,    68,    69,    70,    64,    65,     0,    66,    67,    68,
      69,    70,    64,    88,     0,    66,    67,    68,    69,    70,
      64,   107,     0,    66,    67,    68,    69,    70,    64,   114,
       0,    66,    67,    68,    69,    70,    64,     0,     0,    66,
      67,    68,    69,    70,    76,     0,     0,     0,    80,     0,
       0,    82
};

static const yytype_int8 yycheck[] =
{
       7,    23,     0,     3,    17,    25,     3,    19,    18,     3,
      17,     3,    19,     7,    14,    27,    23,    14,    25,    19,
      20,    21,    19,    20,    19,    20,    14,     3,    24,     3,
      26,     5,    20,    46,     3,    31,    56,     4,     7,    46,
      14,     9,    49,     2,    18,    19,    20,    19,    22,    56,
      24,    25,    26,    60,    13,    14,     3,    15,    16,    17,
       7,    20,    58,    59,     4,    12,     7,    63,    64,     3,
      66,    67,    68,    69,    70,     3,     3,    11,     3,    75,
      14,    12,   104,   105,    97,    19,    20,     6,    17,     3,
      97,    87,     9,    11,   116,     8,    12,   104,   105,   121,
      14,   114,    98,    12,    18,    19,    20,   114,    22,   116,
      24,    25,    26,     4,   121,   111,     4,     9,    23,    12,
      56,    60,    10,   119,     4,    13,    14,    15,    16,    17,
      10,    97,     4,    13,    14,    15,    16,    17,    10,     2,
       4,    13,    14,    15,    16,    17,    10,   111,    -1,    13,
      14,    15,    16,    17,    10,    11,    -1,    13,    14,    15,
      16,    17,    10,    11,    -1,    13,    14,    15,    16,    17,
      10,    11,    -1,    13,    14,    15,    16,    17,    10,    11,
      -1,    13,    14,    15,    16,    17,    10,    -1,    -1,    13,
      14,    15,    16,    17,    47,    -1,    -1,    -1,    51,    -1,
      -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    31,     0,    18,    32,    47,    59,    19,    27,
      33,    48,    60,     3,     3,    50,    51,    59,    50,     4,
       9,    40,    60,     4,     3,     5,    14,    20,    22,    24,
      25,    26,    35,    36,    39,    40,    43,    46,    47,    49,
      52,    53,    54,    55,    56,    57,    59,    60,    50,     7,
      41,    42,    56,    46,    60,    34,    35,    46,     3,     3,
       3,    11,    46,    12,    10,    11,    13,    14,    15,    16,
      17,    37,    38,    40,    60,     3,    41,    20,    58,    60,
      41,     4,    41,     6,    34,    46,    46,    39,    11,    46,
      46,    46,    46,    46,    46,    46,    11,     9,    12,    21,
      44,    45,    46,     8,     4,     4,    46,    11,    37,    46,
       4,     9,    56,    56,    11,    44,    23,    40,    56,    12,
      46,     4,    56
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
        case 6:
#line 60 "a2.y"
    {
		printf("main:\n");
		strcpy(currScope, "main");
	;}
    break;

  case 19:
#line 89 "a2.y"
    {
		if ((yyvsp[(3) - (3)].exp).isConstant) {
				printf("t%d = %s\n", tCount, (yyvsp[(3) - (3)].exp).value);
				printf("%s = t%d\n", (yyvsp[(1) - (3)].id).displayName, tCount++);
		} else
				printf("%s = %s\n", (yyvsp[(1) - (3)].id).displayName, (yyvsp[(3) - (3)].exp).value);
	;}
    break;

  case 21:
#line 99 "a2.y"
    {
	    hash_table_item_t *item = searchSymbol((yyvsp[(1) - (4)].id).name, symbolTable);
	    if (item != NULL)
		if (item->data->depth != (yyvsp[(1) - (4)].id).depth)
		    yyerror("Invalid location");
		if ((yyvsp[(3) - (4)].exp).isConstant) {
				printf("t%d = %s\n", tCount, (yyvsp[(3) - (4)].exp).value);
				printf("%s = t%d\n", (yyvsp[(1) - (4)].id).displayName, tCount++);
		} else
				printf("%s = %s\n", (yyvsp[(1) - (4)].id).displayName, (yyvsp[(3) - (4)].exp).value);
	;}
    break;

  case 22:
#line 112 "a2.y"
    {
	    identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, currScope);
	    strcat(id->name, "_");
	    strcat(id->name, (yyvsp[(1) - (1)].str));
	    strcpy(id->displayName, (yyvsp[(1) - (1)].str));
	    strcpy(id->type, currType);
	    id->depth = 0;
		insertSymbol(id->name, id, symbolTable);
		(yyval.id) = *id;
	  ;}
    break;

  case 23:
#line 123 "a2.y"
    {
	    identifier_t *id = (identifier_t *)malloc(sizeof(identifier_t));
		strcpy(id->name, currScope);
	    strcat(id->name, "_");
	    strcat(id->name, (yyvsp[(1) - (2)].str));
	    strcpy(id->displayName, (yyvsp[(1) - (2)].str));
	    strcpy(id->type, currType);
	    id->depth = (yyvsp[(2) - (2)].val);
		insertSymbol(id->name, id, symbolTable);
		(yyval.id) = *id;
	  ;}
    break;

  case 24:
#line 136 "a2.y"
    {
		(yyval.val) = 1;
	;}
    break;

  case 25:
#line 139 "a2.y"
    {
	    (yyval.val) = 1 + (yyvsp[(2) - (2)].val);
    ;}
    break;

  case 33:
#line 159 "a2.y"
    {
		  if ((yyvsp[(1) - (3)].exp).depth != (yyvsp[(3) - (3)].exp).depth) error("Invalid operation");
		  expression_t exp = { "\0", (yyvsp[(1) - (3)].exp).depth };
		  printf("t%d = %s + %s\n", tCount, (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value);
		  sprintf(exp.value, "t%d", tCount++);
		  (yyval.exp) = exp;
    ;}
    break;

  case 34:
#line 166 "a2.y"
    {
		  if ((yyvsp[(1) - (3)].exp).depth != (yyvsp[(3) - (3)].exp).depth) error("Invalid operation");
		  expression_t exp = { "\0", (yyvsp[(1) - (3)].exp).depth };
		  printf("t%d = %s - %s\n", tCount, (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value);
		  sprintf(exp.value, "t%d", tCount++);
		  (yyval.exp) = exp;
    ;}
    break;

  case 35:
#line 173 "a2.y"
    {
		  if ((yyvsp[(1) - (3)].exp).depth != (yyvsp[(3) - (3)].exp).depth) error("Invalid operation");
		  expression_t exp = { "\0", (yyvsp[(1) - (3)].exp).depth };
		  printf("t%d = %s %s %s\n", tCount, (yyvsp[(1) - (3)].exp).value, mytext, (yyvsp[(3) - (3)].exp).value);
		  sprintf(exp.value, "t%d", tCount++);
		  (yyval.exp) = exp;
    ;}
    break;

  case 36:
#line 180 "a2.y"
    {
		  if ((yyvsp[(1) - (3)].exp).depth != (yyvsp[(3) - (3)].exp).depth) error("Invalid operation");
		  expression_t exp = { "\0", (yyvsp[(1) - (3)].exp).depth };
		  printf("t%d = %s * %s\n", tCount, (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value);
		  sprintf(exp.value, "t%d", tCount++);
		  (yyval.exp) = exp;
    ;}
    break;

  case 37:
#line 187 "a2.y"
    {
		  if ((yyvsp[(1) - (3)].exp).depth != (yyvsp[(3) - (3)].exp).depth) error("Invalid operation");
		  expression_t exp = { "\0", (yyvsp[(1) - (3)].exp).depth };
		  printf("t%d = %s / %s\n", tCount, (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value);
		  sprintf(exp.value, "t%d", tCount++);
		  (yyval.exp) = exp;
    ;}
    break;

  case 38:
#line 194 "a2.y"
    {
		  if ((yyvsp[(1) - (3)].exp).depth != (yyvsp[(3) - (3)].exp).depth) error("Invalid operation");
		  expression_t exp = { "\0", (yyvsp[(1) - (3)].exp).depth };
		  printf("t%d = %s ** %s\n", tCount, (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value);
		  sprintf(exp.value, "t%d", tCount++);
		  (yyval.exp) = exp;
    ;}
    break;

  case 39:
#line 201 "a2.y"
    {
		  expression_t exp = { "\0", (yyvsp[(2) - (2)].exp).depth };
		  printf("t%d = -%s\n", tCount++, (yyvsp[(2) - (2)].exp).value);
		  sprintf(exp.value, "%s", (yyvsp[(2) - (2)].exp).value);
		  exp.isConstant = true;
		  (yyval.exp) = exp;
    ;}
    break;

  case 40:
#line 208 "a2.y"
    {
		  expression_t exp = { "\0", (yyvsp[(2) - (3)].exp).depth }; 
		  sprintf(exp.value, "%s", (yyvsp[(2) - (3)].exp).value);
		  (yyval.exp) = exp;
    ;}
    break;

  case 41:
#line 213 "a2.y"
    {
		expression_t exp = { "\n", 0 };
		(yyval.exp) = exp;
    ;}
    break;

  case 42:
#line 217 "a2.y"
    {
		expression_t exp = { "\0", 0 };

		if (!(yyvsp[(1) - (1)].id).isConstant) {
				sprintf(mytext, "%s_%s", currScope, (yyvsp[(1) - (1)].id).name);
				hash_table_item_t *item = searchSymbol(mytext, symbolTable);
				if (item == NULL)
						error("Undefined identifier");
				exp.depth = item->data->depth - (yyvsp[(1) - (1)].id).depth;
		}
		sprintf(exp.value, "%s", (yyvsp[(1) - (1)].id).name);
		exp.isConstant = true;
		(yyval.exp) = exp;
    ;}
    break;

  case 43:
#line 233 "a2.y"
    {
			 strcpy(currScope, "global");
		;}
    break;

  case 44:
#line 239 "a2.y"
    {
				printf("%s:\n", mytext);
				strcpy(currScope, mytext);
		;}
    break;

  case 45:
#line 246 "a2.y"
    {
		printf("retval = %s\n", (yyvsp[(2) - (3)].exp).value);
		printf("return\n\n");
	;}
    break;

  case 46:
#line 250 "a2.y"
    {
		printf("return\n\n");
	;}
    break;

  case 59:
#line 281 "a2.y"
    {
		identifier_t id;
		strncpy(id.name, (char *) (yyvsp[(1) - (1)].str), sizeof(id.name) - 1);
		id.name[sizeof(id.name) - 1] = '\0';
		id.depth = 0;
		(yyval.id) = id;
    ;}
    break;

  case 60:
#line 288 "a2.y"
    {
		identifier_t id;
		strncpy(id.name, (char *) (yyvsp[(1) - (2)].str), sizeof(id.name) - 1);
		id.name[sizeof(id.name) - 1] = '\0';
		id.depth = (yyvsp[(2) - (2)].val);
		(yyval.id) = id;
    ;}
    break;

  case 61:
#line 295 "a2.y"
    {
		identifier_t id;
		strcpy(id.name, mytext);
		id.depth = 0;
		id.isConstant = true;
		(yyval.id) = id;
    ;}
    break;

  case 64:
#line 308 "a2.y"
    {
		 (yyval.str) = malloc(5 * sizeof(char));
		 strcpy((yyval.str), mytext);
		 strcpy(currType, mytext);
		;}
    break;

  case 65:
#line 315 "a2.y"
    {
		(yyval.str) = strdup(mytext);
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 1781 "a2.tab.c"
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


#line 320 "a2.y"


void yyerror(char *message) {
    fprintf(stderr, "syntax error: %d\n", lineNumber);
    exit(1);
}

void error(char *message) {
		perror(message);
		exit(1);
}

int main(void) {
    yyparse();
    return 0;
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

