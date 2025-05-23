
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "bhaashakaar.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
extern int line_num;
extern FILE* yyin;
void yyerror(const char* s);
void yyrestart(FILE *input_file);

int temp_var_counter = 0;
int label_counter = 0;

typedef struct ExpressionResult {
    char* code;
    char* addr;
} ExpressionResult;

char* new_temp() {
    char* temp = (char*)malloc(16);
    sprintf(temp, "t%d", temp_var_counter++);
    return temp;
}

char* new_label() {
    char* label = (char*)malloc(16);
    sprintf(label, "L%d", label_counter++);
    return label;
}

ExpressionResult* create_expr_result() {
    ExpressionResult* result = (ExpressionResult*)malloc(sizeof(ExpressionResult));
    result->code = strdup("");
    result->addr = NULL;
    return result;
}

void append_code(ExpressionResult* result, const char* code) {
    char* new_code = (char*)malloc(strlen(result->code) + strlen(code) + 1);
    strcpy(new_code, result->code);
    strcat(new_code, code);
    free(result->code);
    result->code = new_code;
}


/* Line 189 of yacc.c  */
#line 120 "bhaashakaar.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     END = 259,
     VAR = 260,
     RETURN = 261,
     INT = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     FOR = 266,
     FUNCTION = 267,
     PRINT = 268,
     PLUS = 269,
     MINUS = 270,
     TIMES = 271,
     DIVIDE = 272,
     MOD = 273,
     GT = 274,
     LT = 275,
     ASSIGN = 276,
     LPAREN = 277,
     RPAREN = 278,
     LBRACE = 279,
     RBRACE = 280,
     SEMICOLON = 281,
     INT_LITERAL = 282,
     STRING_LITERAL = 283,
     IDENTIFIER = 284,
     LOWER_THAN_ELSE = 285
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 47 "bhaashakaar.y"

    int ival;
    char* sval;
    struct ExpressionResult* expr;



/* Line 214 of yacc.c  */
#line 194 "bhaashakaar.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 206 "bhaashakaar.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   115

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNRULES -- Number of states.  */
#define YYNSTATES  104

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    19,    27,    29,
      32,    35,    38,    42,    44,    46,    48,    50,    54,    57,
      59,    63,    66,    72,    80,    86,    96,   106,   112,   116,
     122,   124,   126,   130,   132,   134,   138,   142,   144,   148,
     152,   154,   158,   162,   166,   168,   170,   172,   174
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,    33,    -1,    34,    -1,    35,    -1,    34,
      35,    -1,     3,    29,    24,    42,    25,     4,    -1,     3,
      29,    24,    42,    36,    25,     4,    -1,    37,    -1,    36,
      37,    -1,    43,    26,    -1,    46,    26,    -1,    13,    47,
      26,    -1,    39,    -1,    40,    -1,    41,    -1,    38,    -1,
       6,    47,    26,    -1,     6,    26,    -1,    26,    -1,    24,
      36,    25,    -1,    24,    25,    -1,     8,    22,    47,    23,
      38,    -1,     8,    22,    47,    23,    38,     9,    38,    -1,
      10,    22,    47,    23,    38,    -1,    11,    22,    43,    26,
      47,    26,    46,    23,    38,    -1,    11,    22,    46,    26,
      47,    26,    46,    23,    38,    -1,    12,    29,    22,    23,
      38,    -1,     5,    44,    29,    -1,     5,    44,    29,    21,
      47,    -1,    45,    -1,     7,    -1,    29,    21,    47,    -1,
      48,    -1,    49,    -1,    48,    20,    49,    -1,    48,    19,
      49,    -1,    50,    -1,    49,    14,    50,    -1,    49,    15,
      50,    -1,    51,    -1,    50,    16,    51,    -1,    50,    17,
      51,    -1,    50,    18,    51,    -1,    52,    -1,    53,    -1,
      29,    -1,    27,    -1,    28,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    84,    91,    95,   103,   109,   119,   123,
     131,   135,   139,   146,   150,   154,   158,   162,   169,   174,
     181,   185,   192,   204,   221,   237,   251,   268,   278,   285,
     295,   302,   306,   316,   323,   327,   336,   348,   352,   361,
     373,   377,   386,   395,   407,   414,   421,   426,   433
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "END", "VAR", "RETURN", "INT",
  "IF", "ELSE", "WHILE", "FOR", "FUNCTION", "PRINT", "PLUS", "MINUS",
  "TIMES", "DIVIDE", "MOD", "GT", "LT", "ASSIGN", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "SEMICOLON", "INT_LITERAL", "STRING_LITERAL",
  "IDENTIFIER", "LOWER_THAN_ELSE", "$accept", "program_start", "program",
  "program_body", "program_declaration", "statement_list", "statement",
  "block_statement", "if_statement", "while_statement", "for_statement",
  "function_declaration", "variable_declaration", "type", "basic_type",
  "assignment_expression", "expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "primary_expression", 0
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
     285
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    34,    34,    35,    35,    36,    36,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      38,    38,    39,    39,    40,    41,    41,    42,    43,    43,
      44,    45,    46,    47,    48,    48,    48,    49,    49,    49,
      50,    50,    50,    50,    51,    52,    53,    53,    53
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     6,     7,     1,     2,
       2,     2,     3,     1,     1,     1,     1,     3,     2,     1,
       3,     2,     5,     7,     5,     9,     9,     5,     3,     5,
       1,     1,     3,     1,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     4,     0,     1,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     8,    16,    13,    14,    15,     0,
       0,     0,    31,     0,    30,    18,    47,    48,    46,     0,
      33,    34,    37,    40,    44,    45,     0,     0,     0,     0,
      21,     0,     6,     0,     0,     9,    10,    11,     0,    28,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    20,    32,     7,    27,     0,    36,    35,
      38,    39,    41,    42,    43,     0,     0,     0,     0,    29,
      22,    24,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,    25,    26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    23,    24,    25,    26,    27,
      28,    11,    29,    33,    34,    30,    39,    40,    41,    42,
      43,    44,    45
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -56
static const yytype_int8 yypact[] =
{
       6,   -16,    19,   -56,     6,   -56,     3,   -56,   -56,     9,
      -5,    12,    18,    40,   -21,    32,    34,    41,   -17,    47,
      62,   -56,    46,    69,   -56,   -56,   -56,   -56,   -56,    42,
      52,    58,   -56,    56,   -56,   -56,   -56,   -56,   -56,    61,
      14,    36,    -2,   -56,   -56,   -56,   -17,   -17,    -3,    64,
     -56,    78,   -56,   -17,    88,   -56,   -56,   -56,    72,    76,
     -56,   -17,   -17,   -17,   -17,   -17,   -17,   -17,    77,    82,
      73,    75,   -56,   -56,   -56,   -56,   -56,   -17,    36,    36,
      -2,    -2,   -56,   -56,   -56,    72,    72,   -17,   -17,   -56,
      97,   -56,    83,    84,    72,    79,    79,   -56,    89,    90,
      72,    72,   -56,   -56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,   -56,   -56,   107,    95,   -19,   -55,   -56,   -56,
     -56,   -56,    67,   -56,   -56,   -47,   -18,   -56,     0,     1,
     -23,   -56,   -56
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      49,    71,    13,    76,    55,    35,    36,    37,    38,     1,
      36,    37,    38,     6,    65,    66,    67,    13,    14,     7,
      15,    10,    16,    17,    12,    18,    22,     9,    68,    69,
      90,    91,    55,    61,    62,    74,    19,    20,    21,    97,
      31,    22,    82,    83,    84,   102,   103,    32,    98,    99,
      63,    64,    13,    14,    46,    15,    47,    16,    17,    89,
      18,    78,    79,    48,    80,    81,    52,    53,    56,    92,
      93,    19,    50,    21,    13,    14,    22,    15,    57,    16,
      17,    58,    18,    13,    14,    59,    15,    60,    16,    17,
      72,    18,    75,    19,    54,    21,    19,    77,    22,    87,
      85,    88,    19,    73,    21,    86,    94,    22,    22,    95,
      96,     8,   100,   101,    51,    70
};

static const yytype_uint8 yycheck[] =
{
      18,    48,     5,    58,    23,    26,    27,    28,    29,     3,
      27,    28,    29,    29,    16,    17,    18,     5,     6,     0,
       8,    12,    10,    11,    29,    13,    29,    24,    46,    47,
      85,    86,    51,    19,    20,    53,    24,    25,    26,    94,
      22,    29,    65,    66,    67,   100,   101,     7,    95,    96,
      14,    15,     5,     6,    22,     8,    22,    10,    11,    77,
      13,    61,    62,    22,    63,    64,     4,    21,    26,    87,
      88,    24,    25,    26,     5,     6,    29,     8,    26,    10,
      11,    23,    13,     5,     6,    29,     8,    26,    10,    11,
      26,    13,     4,    24,    25,    26,    24,    21,    29,    26,
      23,    26,    24,    25,    26,    23,     9,    29,    29,    26,
      26,     4,    23,    23,    19,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    32,    33,    34,    35,    29,     0,    35,    24,
      12,    42,    29,     5,     6,     8,    10,    11,    13,    24,
      25,    26,    29,    36,    37,    38,    39,    40,    41,    43,
      46,    22,     7,    44,    45,    26,    27,    28,    29,    47,
      48,    49,    50,    51,    52,    53,    22,    22,    22,    47,
      25,    36,     4,    21,    25,    37,    26,    26,    23,    29,
      26,    19,    20,    14,    15,    16,    17,    18,    47,    47,
      43,    46,    26,    25,    47,     4,    38,    21,    49,    49,
      50,    50,    51,    51,    51,    23,    23,    26,    26,    47,
      38,    38,    47,    47,     9,    26,    26,    38,    46,    46,
      23,    23,    38,    38
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 3:

/* Line 1455 of yacc.c  */
#line 85 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 92 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 96 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
        append_code((yyval.expr), (yyvsp[(2) - (2)].expr)->code);
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 104 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(4) - (6)].expr);
        printf("// Three-address code for Hindi program '%s'\n", (yyvsp[(2) - (6)].sval));
        printf("%s", (yyvsp[(4) - (6)].expr)->code);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 110 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(5) - (7)].expr);
        append_code((yyval.expr), (yyvsp[(4) - (7)].expr)->code);
        printf("// Three-address code for Hindi program '%s'\n", (yyvsp[(2) - (7)].sval));
        printf("%s", (yyval.expr)->code);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 120 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 124 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
        append_code((yyval.expr), (yyvsp[(2) - (2)].expr)->code);
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 132 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 136 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (2)].expr);
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 140 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(2) - (3)].expr);
        char code[128];
        sprintf(code, "print %s\n", (yyvsp[(2) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 147 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 151 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 155 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 159 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 163 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(2) - (3)].expr);
        char code[128];
        sprintf(code, "return %s\n", (yyvsp[(2) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 170 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        append_code((yyval.expr), "return\n");
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 175 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 182 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(2) - (3)].expr);
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 186 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 193 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char* true_label = new_label();
        char* end_label = new_label();
        char code[1024];
        sprintf(code,
            "%sif %s goto %s\ngoto %s\n%s:\n%s%s:\n",
            (yyvsp[(3) - (5)].expr)->code, (yyvsp[(3) - (5)].expr)->addr, true_label, end_label,
            true_label, (yyvsp[(5) - (5)].expr)->code, end_label);
        append_code((yyval.expr), code);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 205 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char* true_label = new_label();
        char* false_label = new_label();
        char* end_label = new_label();
        char code[2048];
        sprintf(code,
            "%sif %s goto %s\ngoto %s\n%s:\n%s\ngoto %s\n%s:\n%s%s:\n",
            (yyvsp[(3) - (7)].expr)->code, (yyvsp[(3) - (7)].expr)->addr, true_label, false_label,
            true_label, (yyvsp[(5) - (7)].expr)->code, end_label,
            false_label, (yyvsp[(7) - (7)].expr)->code, end_label);
        append_code((yyval.expr), code);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 222 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char* start_label = new_label();
        char* body_label = new_label();
        char* end_label = new_label();
        char code[1024];
        sprintf(code,
            "%s:\n%sif %s goto %s\ngoto %s\n%s:\n%s\ngoto %s\n%s:\n",
            start_label, (yyvsp[(3) - (5)].expr)->code, (yyvsp[(3) - (5)].expr)->addr, body_label, end_label,
            body_label, (yyvsp[(5) - (5)].expr)->code, start_label, end_label);
        append_code((yyval.expr), code);
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 238 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char* start_label = new_label();
        char* body_label = new_label();
        char* update_label = new_label();
        char* end_label = new_label();
        char code[2048];
        sprintf(code,
            "%s%s:\n%sif %s goto %s\ngoto %s\n%s:\n%s%s:\n%s\ngoto %s\n%s:\n",
            (yyvsp[(3) - (9)].expr)->code, start_label, (yyvsp[(5) - (9)].expr)->code, (yyvsp[(5) - (9)].expr)->addr, body_label, end_label,
            body_label, (yyvsp[(9) - (9)].expr)->code, update_label, (yyvsp[(7) - (9)].expr)->code, start_label, end_label);
        append_code((yyval.expr), code);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 252 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char* start_label = new_label();
        char* body_label = new_label();
        char* update_label = new_label();
        char* end_label = new_label();
        char code[2048];
        sprintf(code,
            "%s%s:\n%sif %s goto %s\ngoto %s\n%s:\n%s%s:\n%s\ngoto %s\n%s:\n",
            (yyvsp[(3) - (9)].expr)->code, start_label, (yyvsp[(5) - (9)].expr)->code, (yyvsp[(5) - (9)].expr)->addr, body_label, end_label,
            body_label, (yyvsp[(9) - (9)].expr)->code, update_label, (yyvsp[(7) - (9)].expr)->code, start_label, end_label);
        append_code((yyval.expr), code);
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 269 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(5) - (5)].expr);
        char code[128];
        sprintf(code, "// Function: %s\n", (yyvsp[(2) - (5)].sval));
        append_code((yyval.expr), code);
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 279 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char code[128];
        sprintf(code, "// Declaration: %s\n", (yyvsp[(3) - (3)].sval));
        append_code((yyval.expr), code);
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 286 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(5) - (5)].expr);
        char code[128];
        sprintf(code, "%s = %s\n", (yyvsp[(3) - (5)].sval), (yyvsp[(5) - (5)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 296 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 302 "bhaashakaar.y"
    { (yyval.expr) = create_expr_result(); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 307 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(3) - (3)].expr);
        char code[128];
        sprintf(code, "%s = %s\n", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 317 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 324 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 328 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s < %s\n", (yyvsp[(1) - (3)].expr)->code, temp, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
        (yyval.expr)->addr = temp;
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 337 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s > %s\n", (yyvsp[(1) - (3)].expr)->code, temp, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
        (yyval.expr)->addr = temp;
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 349 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 353 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s + %s\n", (yyvsp[(1) - (3)].expr)->code, temp, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
        (yyval.expr)->addr = temp;
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 362 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s - %s\n", (yyvsp[(1) - (3)].expr)->code, temp, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
        (yyval.expr)->addr = temp;
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 374 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 378 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s * %s\n", (yyvsp[(1) - (3)].expr)->code, temp, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
        (yyval.expr)->addr = temp;
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 387 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s / %s\n", (yyvsp[(1) - (3)].expr)->code, temp, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
        (yyval.expr)->addr = temp;
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 396 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char* temp = new_temp();
        char code[128];
        sprintf(code, "%s%s = %s %% %s\n", (yyvsp[(1) - (3)].expr)->code, temp, (yyvsp[(1) - (3)].expr)->addr, (yyvsp[(3) - (3)].expr)->addr);
        append_code((yyval.expr), code);
        (yyval.expr)->addr = temp;
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 408 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 415 "bhaashakaar.y"
    {
        (yyval.expr) = (yyvsp[(1) - (1)].expr);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 422 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = strdup((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 427 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        char buf[32];
        sprintf(buf, "%d", (yyvsp[(1) - (1)].ival));
        (yyval.expr)->addr = strdup(buf);
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 434 "bhaashakaar.y"
    {
        (yyval.expr) = create_expr_result();
        (yyval.expr)->addr = strdup((yyvsp[(1) - (1)].sval));
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2012 "bhaashakaar.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 440 "bhaashakaar.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: %s at line %d\n", s, line_num);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file1> [<input_file2> ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        yyin = fopen(argv[i], "r");
        if (!yyin) {
            perror("Cannot open input file");
            continue;
        }

        line_num = 1;
        temp_var_counter = 0;
        label_counter = 0;
        yyrestart(yyin);

        printf("\n// Processing file: %s\n", argv[i]);
        yyparse();

        fclose(yyin);
    }

    return 0;
}
