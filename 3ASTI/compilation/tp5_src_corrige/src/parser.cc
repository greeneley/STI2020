/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 28 "parser.ypp" /* yacc.c:339  */

#include "Attributes.h"
#include "Label.h"
#include "Register.h"
#include "Type.h"
#include "SymbolTable.h"

#include "CodeDigmips.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define PTR_SIZE 1
#define RETURN_REGISTER 2
#define ARP 7
#define SP 6
#define SPILL0 0
#define SPILL1 1


int		line_number	= 1;	/* number of current source line */
extern int	yylex();	/* lexical analyzer generated from lex.l */
extern char	*yytext;	/* last token, defined in lex.l  */

map<string,Type*> current_record; //used to set record types.
vector<Type*> arg_type; //function calls type-checking
Type* current_return_type; //return type-checking
string label_end_function; //used by return


void yyerror(char *s)
  { fprintf(stderr, 
	    "Line %d: syntax error. Last token was \"%s\"\n",
	    line_number, yytext);
    exit(1);
  }
void error(char *s)
  { fprintf(stderr, 
	    "Line %d: error: %s\n", line_number, s);
    exit(1);
  }


#line 113 "parser.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_INT_TYPE = 258,
    TK_CHAR_TYPE = 259,
    TK_VOID_TYPE = 260,
    TK_STRUCT = 261,
    TK_TYPEDEF = 262,
    TK_SIZEOF = 263,
    TK_LPAR = 264,
    TK_RPAR = 265,
    TK_COMMA = 266,
    TK_SEMI = 267,
    TK_LACC = 268,
    TK_RACC = 269,
    TK_TRUE = 270,
    TK_FALSE = 271,
    TK_GREATER = 272,
    TK_GREATER_EQ = 273,
    TK_LOWER = 274,
    TK_LOWER_EQ = 275,
    TK_EQUAL = 276,
    TK_NEQUAL = 277,
    TK_PLUS = 278,
    TK_MINUS = 279,
    TK_MUL = 280,
    TK_DIV = 281,
    TK_MOD = 282,
    TK_PLUSPLUS = 283,
    TK_NUM = 284,
    TK_ID = 285,
    TK_TYPE_ID = 286,
    TK_CHAR = 287,
    TK_STRING = 288,
    TK_LBRAC = 289,
    TK_RBRAC = 290,
    TK_REF = 291,
    TK_DOT = 292,
    TK_ALLOC = 293,
    TK_FREE = 294,
    TK_ASSIGN = 295,
    TK_IF = 296,
    TK_ELSE = 297,
    TK_WHILE = 298,
    TK_FOR = 299,
    TK_RETURN = 300,
    TK_ASM = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 80 "parser.ypp" /* yacc.c:355  */

  int integer;
  char* id_string;

  Type* type;
  LhsExpr* lhs_expr;
  RhsExpr* rhs_expr;

#line 209 "parser.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "parser.cc" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   171,   171,   173,   175,   177,   179,   181,   186,   188,
     190,   195,   200,   205,   210,   216,   232,   236,   237,   248,
     258,   268,   273,   283,   293,   298,   304,   310,   314,   322,
     321,   340,   345,   355,   368,   389,   413,   419,   429,   448,
     468,   488,   508,   528,   548,   562,   579,   598,   612,   597,
     630,   636,   629,   660,   667,   658,   696,   712,   711,   737,
     738,   742,   743,   745,   746,   754,   755,   762,   771,   772,
     784,   785,   790,   800,   807,   799,   820,   821,   830,   829
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_INT_TYPE", "TK_CHAR_TYPE",
  "TK_VOID_TYPE", "TK_STRUCT", "TK_TYPEDEF", "TK_SIZEOF", "TK_LPAR",
  "TK_RPAR", "TK_COMMA", "TK_SEMI", "TK_LACC", "TK_RACC", "TK_TRUE",
  "TK_FALSE", "TK_GREATER", "TK_GREATER_EQ", "TK_LOWER", "TK_LOWER_EQ",
  "TK_EQUAL", "TK_NEQUAL", "TK_PLUS", "TK_MINUS", "TK_MUL", "TK_DIV",
  "TK_MOD", "TK_PLUSPLUS", "TK_NUM", "TK_ID", "TK_TYPE_ID", "TK_CHAR",
  "TK_STRING", "TK_LBRAC", "TK_RBRAC", "TK_REF", "TK_DOT", "TK_ALLOC",
  "TK_FREE", "TK_ASSIGN", "TK_IF", "TK_ELSE", "TK_WHILE", "TK_FOR",
  "TK_RETURN", "TK_ASM", "$accept", "type", "base", "pointer", "array",
  "record", "field_list", "type_def", "type_def_list", "e_expr", "t_expr",
  "f_expr", "$@1", "var_expr", "expr", "test", "stmt", "$@2", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "stmt_else", "stmt_block", "stmt_list",
  "declare_args", "declare_local_vars", "caller_arg_list", "function",
  "$@9", "$@10", "function_list", "prog", "$@11", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -80

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -67,     0,     9,    52,   -67,   -67,   -67,   -67,   -67,   -67,
      14,    52,   -67,   -11,   -67,   -67,   -67,   -67,    52,    52,
      50,   -67,    38,   -10,   104,    48,   116,     7,   -67,   -67,
      27,    68,    70,   -67,   118,   -67,   -67,   -67,   105,    52,
     -67,   124,    24,   -67,   106,    52,   -67,   126,    52,   -67,
     132,   -67,   127,    22,   -67,    63,   -67,    63,    -3,   103,
     -67,   133,   115,    36,   -67,   -67,    12,    79,   -67,   115,
     144,   103,   -67,   146,   -67,   107,   138,   -67,    79,   150,
     -67,   103,    77,   115,   147,   115,    97,   115,   -67,   115,
     149,   134,    91,    12,   169,   -67,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,    55,   -67,   -67,    91,
     -67,   102,   -67,   170,   -67,   163,   -67,   173,   -67,   -67,
     115,   138,   138,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,    55,   103,   -67,   -67,   172,   115,
     -67,   165,    65,    94,   -67,   174,   -67,   -67,   -67,   -67,
      55,   -67,   -67,   -67,   155,   159,   178,    55,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      17,    78,     0,     0,    18,    76,     1,     8,     9,    10,
       0,     0,     6,     0,     2,     3,     4,     5,     0,     0,
       0,    11,     0,     0,     0,    77,     0,     0,     7,    16,
       0,     0,     0,    13,     0,    12,    73,    14,     0,    65,
      15,     0,     0,    66,     0,     0,    68,     0,    74,    67,
       0,    63,     0,     0,    69,     0,    75,     0,    32,     0,
      50,     0,     0,     0,    64,    32,     0,    33,    57,     0,
       0,     0,    25,    32,    26,    37,    21,    24,    27,     0,
      47,     0,     0,     0,     0,     0,     0,     0,    36,    70,
       0,     0,    37,    27,     0,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    53,     0,
      56,     0,    35,     0,    71,     0,    45,     0,    31,    44,
      70,    19,    20,    22,    23,    38,    39,    40,    41,    42,
      43,    63,    61,    48,     0,     0,    34,    46,     0,     0,
      28,     0,     0,    59,    52,     0,    58,    72,    30,    62,
       0,    49,    54,    60,     0,     0,     0,     0,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,     6,   -67,   -67,   -67,   -67,   -67,   -67,   -67,    20,
      81,    82,   -67,   -53,   -61,   -66,   -50,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -63,    58,   -67,   -67,    71,
     -67,   -67,   -67,   -67,   -67,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,    27,     4,     1,    75,
      76,    77,   120,    78,    79,    80,   132,   106,   143,    81,
     134,   135,   154,    89,   151,   133,    53,    42,    48,   115,
      25,    39,    51,    18,     2,     5
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    84,    66,    64,    67,    94,    68,     3,    90,     6,
       7,     8,     9,    10,    21,   107,    11,    20,    93,    30,
      22,    33,    88,    23,    24,    26,   113,    19,   114,    63,
      93,    55,   108,    34,    44,    45,    56,    69,    12,   125,
     126,   127,   128,   129,   130,    41,    85,    57,   -79,    86,
      29,    47,    58,    63,    50,     7,     8,     9,    10,   114,
      28,    11,    35,    59,    55,    60,    61,    62,   131,   145,
      85,   144,    55,    86,    55,    21,    87,    36,   147,   149,
      57,    63,    37,    12,    23,    58,    55,   153,    57,    63,
      57,    92,    64,    65,   158,    58,    59,    63,    60,    61,
      62,   118,    57,   109,    63,   111,    59,    58,    60,    61,
      62,    70,    71,    85,    96,    97,    86,    40,    59,    46,
      60,    61,    62,    70,    83,    96,    97,   112,    57,    21,
      96,    97,    72,    73,    31,    74,   150,   136,    23,    54,
      57,    21,    82,    21,    72,    73,    32,    74,    38,    21,
      23,    21,    23,    91,    43,    95,    49,    21,    23,   110,
      23,   116,    52,    98,    99,   117,    23,   100,   101,   102,
     103,   104,   105,   138,   139,   148,   139,   121,   122,   119,
     123,   124,   137,   140,   146,   155,   152,   156,   157,   142,
       0,   141
};

static const yytype_int16 yycheck[] =
{
      53,    62,    55,    53,    57,    71,     9,     7,    69,     0,
       3,     4,     5,     6,    25,    81,     9,    11,    71,    29,
      31,    14,    10,    34,    18,    19,    87,    13,    89,    82,
      83,     9,    82,    27,    10,    11,    14,    40,    31,   100,
     101,   102,   103,   104,   105,    39,    34,    25,     0,    37,
      12,    45,    30,   106,    48,     3,     4,     5,     6,   120,
      10,     9,    35,    41,     9,    43,    44,    45,    13,   135,
      34,   134,     9,    37,     9,    25,    40,     9,   139,    14,
      25,   134,    12,    31,    34,    30,     9,   150,    25,   142,
      25,    71,   142,    30,   157,    30,    41,   150,    43,    44,
      45,    10,    25,    83,   157,    85,    41,    30,    43,    44,
      45,     8,     9,    34,    23,    24,    37,    12,    41,    13,
      43,    44,    45,     8,     9,    23,    24,    30,    25,    25,
      23,    24,    29,    30,    30,    32,    42,    35,    34,    12,
      25,    25,     9,    25,    29,    30,    30,    32,    30,    25,
      34,    25,    34,     9,    30,     9,    30,    25,    34,    12,
      34,    12,    30,    25,    26,    31,    34,    17,    18,    19,
      20,    21,    22,    10,    11,    10,    11,    96,    97,    10,
      98,    99,    12,    10,    12,    30,    12,    28,    10,   131,
      -1,   120
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    81,     7,    54,    82,     0,     3,     4,     5,
       6,     9,    31,    48,    49,    50,    51,    52,    80,    13,
      48,    25,    31,    34,    48,    77,    48,    53,    10,    12,
      29,    30,    30,    14,    48,    35,     9,    12,    30,    78,
      12,    48,    74,    30,    10,    11,    13,    48,    75,    30,
      48,    79,    30,    73,    12,     9,    14,    25,    30,    41,
      43,    44,    45,    60,    63,    30,    60,    60,     9,    40,
       8,     9,    29,    30,    32,    56,    57,    58,    60,    61,
      62,    66,     9,     9,    61,    34,    37,    40,    10,    70,
      61,     9,    56,    60,    62,     9,    23,    24,    25,    26,
      17,    18,    19,    20,    21,    22,    64,    62,    63,    56,
      12,    56,    30,    61,    61,    76,    12,    31,    10,    10,
      59,    57,    57,    58,    58,    61,    61,    61,    61,    61,
      61,    13,    63,    72,    67,    68,    35,    12,    10,    11,
      10,    76,    73,    65,    72,    62,    12,    61,    10,    14,
      42,    71,    12,    72,    69,    30,    28,    10,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    48,    48,    48,    49,    49,
      49,    50,    51,    52,    53,    53,    54,    55,    55,    56,
      56,    56,    57,    57,    57,    58,    58,    58,    58,    59,
      58,    58,    60,    60,    60,    60,    60,    61,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    64,    65,    63,
      66,    67,    63,    68,    69,    63,    63,    70,    63,    71,
      71,    72,    72,    73,    73,    74,    74,    74,    75,    75,
      76,    76,    76,    78,    79,    77,    80,    80,    82,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     2,     4,     4,     3,     4,     4,     0,     2,     3,
       3,     1,     3,     3,     1,     1,     1,     1,     4,     0,
       5,     3,     1,     2,     4,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     0,     0,     6,
       0,     0,     5,     0,     0,    11,     3,     0,     6,     0,
       2,     1,     3,     0,     2,     0,     2,     4,     0,     4,
       0,     1,     3,     0,     0,    11,     0,     2,     0,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 172 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1422 "parser.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 174 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1428 "parser.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 176 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1434 "parser.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 178 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1440 "parser.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 180 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = new Type(ID,(yyvsp[0].id_string)); }
#line 1446 "parser.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 182 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 1452 "parser.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 187 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = new Type(INT); }
#line 1458 "parser.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 189 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = new Type(CHAR); }
#line 1464 "parser.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 191 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = new Type(VOID); }
#line 1470 "parser.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 196 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = new Type(POINTER,(yyvsp[-1].type)); }
#line 1476 "parser.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 201 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = new Type(ARRAY,(yyvsp[-3].type),(yyvsp[-1].integer)); }
#line 1482 "parser.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 206 "parser.ypp" /* yacc.c:1646  */
    { (yyval.type) = new Type(RECORD,current_record); }
#line 1488 "parser.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 211 "parser.ypp" /* yacc.c:1646  */
    {
      current_record.erase(current_record.begin(),current_record.end());
      //reset 'current_record'
      current_record[string((yyvsp[-1].id_string))] = (yyvsp[-2].type);
    }
#line 1498 "parser.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 217 "parser.ypp" /* yacc.c:1646  */
    {
      string id_str = string((yyvsp[-1].id_string));

      if(current_record.find(id_str) == current_record.end())
	//field not already filled in?
	current_record[id_str] = (yyvsp[-2].type); //add to 'current_record'
      else
	{
	  cerr << "parser::field_list: duplicate field: " << id_str << endl;
	  exit(1);
	}
    }
#line 1515 "parser.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 233 "parser.ypp" /* yacc.c:1646  */
    { add_type((yyvsp[-1].id_string),(yyvsp[-2].type)); }
#line 1521 "parser.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 249 "parser.ypp" /* yacc.c:1646  */
    { 
      vector<Type*> args;
      args.push_back((yyvsp[-2].rhs_expr)->type); args.push_back((yyvsp[0].rhs_expr)->type); 
      type_check((char*)"+",args); //type checking

      int result_register = new_register(); 
      add(result_register,(yyvsp[-2].rhs_expr)->result_register,(yyvsp[0].rhs_expr)->result_register);
      (yyval.rhs_expr) = rhs(result_register,return_type((char*)"+"));
    }
#line 1535 "parser.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 259 "parser.ypp" /* yacc.c:1646  */
    { 
      vector<Type*> args;
      args.push_back((yyvsp[-2].rhs_expr)->type); args.push_back((yyvsp[0].rhs_expr)->type); 
      type_check((char*)"-",args); //type checking

      int result_register = new_register(); 
      sub(result_register,(yyvsp[-2].rhs_expr)->result_register,(yyvsp[0].rhs_expr)->result_register);
      (yyval.rhs_expr) = rhs(result_register,return_type((char*)"-"));
    }
#line 1549 "parser.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 269 "parser.ypp" /* yacc.c:1646  */
    { (yyval.rhs_expr) = (yyvsp[0].rhs_expr); }
#line 1555 "parser.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 274 "parser.ypp" /* yacc.c:1646  */
    { 
      vector<Type*> args;
      args.push_back((yyvsp[-2].rhs_expr)->type); args.push_back((yyvsp[0].rhs_expr)->type); 
      type_check((char*)"*",args); //type checking

      int result_register = new_register(); 
      mul(result_register,(yyvsp[-2].rhs_expr)->result_register,(yyvsp[0].rhs_expr)->result_register);
      (yyval.rhs_expr) = rhs(result_register,return_type((char*)"*"));
    }
#line 1569 "parser.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 284 "parser.ypp" /* yacc.c:1646  */
    { 
      vector<Type*> args;
      args.push_back((yyvsp[-2].rhs_expr)->type); args.push_back((yyvsp[0].rhs_expr)->type); 
      type_check((char*)"/",args); //type checking

      int result_register = new_register(); 
      div(result_register,(yyvsp[-2].rhs_expr)->result_register,(yyvsp[0].rhs_expr)->result_register);
      (yyval.rhs_expr) = rhs(result_register,return_type((char*)"/"));
    }
#line 1583 "parser.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 294 "parser.ypp" /* yacc.c:1646  */
    { (yyval.rhs_expr) = (yyvsp[0].rhs_expr); }
#line 1589 "parser.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 299 "parser.ypp" /* yacc.c:1646  */
    { 
      int result_register = new_register(); 
      ldi(result_register,(yyvsp[0].integer));
      (yyval.rhs_expr) = rhs(result_register,new Type(INT));
    }
#line 1599 "parser.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 305 "parser.ypp" /* yacc.c:1646  */
    { 
      int result_register = new_register(); 
      ldi(result_register,(yyvsp[0].integer));
      (yyval.rhs_expr) = rhs(result_register,new Type(CHAR));
    }
#line 1609 "parser.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 311 "parser.ypp" /* yacc.c:1646  */
    { 
      (yyval.rhs_expr) = rhs((yyvsp[0].lhs_expr)->result_register,(yyvsp[0].lhs_expr)->type); 
    }
#line 1617 "parser.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 315 "parser.ypp" /* yacc.c:1646  */
    {
      Type* type = get_type((yyvsp[-1].id_string));
      int result_register = new_register();
      ldi(result_register,type->size_of());
      (yyval.rhs_expr) = rhs(result_register,new Type(INT));
    }
#line 1628 "parser.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 322 "parser.ypp" /* yacc.c:1646  */
    { 
      arg_type.resize(0); //filled by caller_arg_list, type checking

      string label_call = new_label("call");
      label(label_call); //start a new basic block...

      push_all(); 
    }
#line 1641 "parser.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 331 "parser.ypp" /* yacc.c:1646  */
    { 
      type_check((yyvsp[-4].id_string),arg_type); //type checking
      call((yyvsp[-4].id_string)); pop_all(); 

      string label_end_call = new_label("end_call");
      label(label_end_call); //end the basic block

      (yyval.rhs_expr) = rhs(RETURN_REGISTER,return_type((yyvsp[-4].id_string))); 
    }
#line 1655 "parser.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 341 "parser.ypp" /* yacc.c:1646  */
    { (yyval.rhs_expr) = (yyvsp[-1].rhs_expr); }
#line 1661 "parser.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 346 "parser.ypp" /* yacc.c:1646  */
    { 
      Type* type = get_variable_type((yyvsp[0].id_string)); //type checking

      int result_register = get_register((yyvsp[0].id_string));
      (yyval.lhs_expr) = lhs(result_register,-1,type); 
    }
#line 1672 "parser.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 356 "parser.ypp" /* yacc.c:1646  */
    {
      Type* type = (yyvsp[0].lhs_expr)->type->un_ref(); //type checking

      int result_register = new_register();
      int address_register = (yyvsp[0].lhs_expr)->result_register;
      ld(result_register,address_register,0);

      (yyval.lhs_expr) = lhs(result_register,address_register,type);
    }
#line 1686 "parser.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 369 "parser.ypp" /* yacc.c:1646  */
    {
      Type* type = (yyvsp[-3].lhs_expr)->type->un_index(); //type checking

      int result_register = new_register();
      int address_register = new_register();
      int shift_register = new_register();

      copy(shift_register,(yyvsp[-1].rhs_expr)->result_register);
      for(int i=0; i<PTR_SIZE-1; i++)
	add(shift_register,shift_register,(yyvsp[-1].rhs_expr)->result_register);
      //shift = i*PTR_SIZE (strength reduction)

      sub(address_register,(yyvsp[-3].lhs_expr)->result_register,shift_register);
      ld(result_register,address_register,0); //?[i] => @(?+i)

      (yyval.lhs_expr) = lhs(result_register,address_register,type);
    }
#line 1708 "parser.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 390 "parser.ypp" /* yacc.c:1646  */
    {
      Type* type = (yyvsp[-2].lhs_expr)->type->un_field((yyvsp[0].id_string)); //type checking

      int field_rank = (yyvsp[-2].lhs_expr)->type->get_field_rank((yyvsp[0].id_string));

      int result_register = new_register();
      int address_register = new_register();

      int field_rank_register = new_register();
      int shift_register = new_register();

      ldi(field_rank_register,field_rank);
      ldi(shift_register,field_rank);
      for(int i=0; i<PTR_SIZE-1; i++)
	add(shift_register,shift_register,field_rank_register);
      //shift = field_rank*PTR_SIZE (strength reduction)

      sub(address_register,(yyvsp[-2].lhs_expr)->result_register,shift_register);
      ld(result_register,address_register,0);

      (yyval.lhs_expr) = lhs(result_register,address_register,type);
    }
#line 1735 "parser.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 414 "parser.ypp" /* yacc.c:1646  */
    { (yyval.lhs_expr) = (yyvsp[-1].lhs_expr); }
#line 1741 "parser.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 420 "parser.ypp" /* yacc.c:1646  */
    { (yyval.rhs_expr) = (yyvsp[0].rhs_expr); }
#line 1747 "parser.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 430 "parser.ypp" /* yacc.c:1646  */
    { 
      string label_true = new_label("greater");
      string label_false = new_label("not_greater");
      int result_register = new_register(); 

      cjump((yyvsp[-2].rhs_expr)->result_register,G,(yyvsp[0].rhs_expr)->result_register,label_true);
      //$1 > $3 => goto true_label
      ldi(result_register,0); 
      //else, set result to false
      j(label_false);
      //goto not_greater
      label(label_true);
      ldi(result_register,1); 
      //set result to true
      label(label_false);

      (yyval.integer) = result_register;
    }
#line 1770 "parser.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 449 "parser.ypp" /* yacc.c:1646  */
    { 
      //Almost a copy/paste of TK_GREATER
      string label_true = new_label("greater_eq");      //
      string label_false = new_label("not_greater_eq"); // copy/paste difference
      int result_register = new_register(); 

      cjump((yyvsp[-2].rhs_expr)->result_register,GE,(yyvsp[0].rhs_expr)->result_register,label_true);
      //$1 >= $3 => goto true_label                       
      ldi(result_register,0); 
      //else, set result to false
      j(label_false);
      //goto not_greater
      label(label_true);
      ldi(result_register,1); 
      //set result to true
      label(label_false);

      (yyval.integer) = result_register;
    }
#line 1794 "parser.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 469 "parser.ypp" /* yacc.c:1646  */
    { 
      //Almost a copy/paste of TK_GREATER
      string label_true = new_label("lower");      //
      string label_false = new_label("not_lower"); // copy/paste difference
      int result_register = new_register(); 

      cjump((yyvsp[-2].rhs_expr)->result_register,L,(yyvsp[0].rhs_expr)->result_register,label_true);
      //$1 < $3 => goto true_label                       
      ldi(result_register,0); 
      //else, set result to false
      j(label_false);
      //goto not_greater
      label(label_true);
      ldi(result_register,1); 
      //set result to true
      label(label_false);

      (yyval.integer) = result_register;
    }
#line 1818 "parser.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 489 "parser.ypp" /* yacc.c:1646  */
    { 
      //Almost a copy/paste of TK_GREATER
      string label_true = new_label("lower_eq");      //
      string label_false = new_label("not_lower_eq"); // copy/paste difference
      int result_register = new_register(); 

      cjump((yyvsp[-2].rhs_expr)->result_register,LE,(yyvsp[0].rhs_expr)->result_register,label_true); 
      //$1 <= $3 => goto true_label                       
      ldi(result_register,0); 
      //else, set result to false
      j(label_false);
      //goto not_greater
      label(label_true);
      ldi(result_register,1); 
      //set result to true
      label(label_false);

      (yyval.integer) = result_register;
    }
#line 1842 "parser.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 509 "parser.ypp" /* yacc.c:1646  */
    { 
      //Almost a copy/paste of TK_GREATER
      string label_true = new_label("equal");  //
      string label_false = new_label("equal"); // copy/paste difference
      int result_register = new_register(); 

      cjump((yyvsp[-2].rhs_expr)->result_register,E,(yyvsp[0].rhs_expr)->result_register,label_true);  
      //$1 == $3 => goto true_label                       
      ldi(result_register,0); 
      //else, set result to false
      j(label_false);
      //goto not_greater
      label(label_true);
      ldi(result_register,1); 
      //set result to true
      label(label_false);

      (yyval.integer) = result_register;
    }
#line 1866 "parser.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 529 "parser.ypp" /* yacc.c:1646  */
    { 
      //Almost a copy/paste of TK_GREATER
      string label_true = new_label("nequal");      //
      string label_false = new_label("not_nequal"); // copy/paste difference
      int result_register = new_register(); 

      cjump((yyvsp[-2].rhs_expr)->result_register,NE,(yyvsp[0].rhs_expr)->result_register,label_true); 
      //$1 != $3 => goto true_label                       
      ldi(result_register,0); 
      //else, set result to false
      j(label_false);
      //goto not_greater
      label(label_true);
      ldi(result_register,1); 
      //set result to true
      label(label_false);

      (yyval.integer) = result_register;
    }
#line 1890 "parser.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 549 "parser.ypp" /* yacc.c:1646  */
    { (yyval.integer) = (yyvsp[-1].integer); }
#line 1896 "parser.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 563 "parser.ypp" /* yacc.c:1646  */
    { 
      Type& lhs_type = *(get_variable_type((yyvsp[-3].id_string)));
      Type& rhs_type = *((yyvsp[-1].rhs_expr)->type);
      if(!((lhs_type == rhs_type) || 
	   (lhs_type.is_base() && rhs_type.is_base())))
	{ 
	  cerr << "Line " << line_number << ": error: assignment: type mismatch"
	       << endl;
	  exit(1);
	}
      //Type checking

      copy(get_register((yyvsp[-3].id_string)),(yyvsp[-1].rhs_expr)->result_register); 
    }
#line 1915 "parser.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 580 "parser.ypp" /* yacc.c:1646  */
    { 
      Type& lhs_type = *((yyvsp[-3].lhs_expr)->type);
      Type& rhs_type = *((yyvsp[-1].rhs_expr)->type);
      if(!((lhs_type == rhs_type) || 
	   (lhs_type.is_base() && rhs_type.is_base())))
	{ 
	  cerr << "Line " << line_number << ": error: assignment: type mismatch"
	       << endl;
	  exit(1);
	}
      //Type checking

      st((yyvsp[-3].lhs_expr)->address_register,0,(yyvsp[-1].rhs_expr)->result_register);
    }
#line 1934 "parser.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 598 "parser.ypp" /* yacc.c:1646  */
    { 
      string label_else = new_label("else");
      string label_then = new_label("then");
      int true_register = new_register();

      ldi(true_register,1);
      cjump((yyvsp[0].integer),E,true_register,label_then);
      //if false => goto label_else
      j(label_else);
      label(label_then);

      push_label(label_else);
    }
#line 1952 "parser.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 612 "parser.ypp" /* yacc.c:1646  */
    { 
      string label_else = pop_label();
      string label_endif = new_label("end_if");

      j(label_endif);
      label(label_else);

      push_label(label_endif);
    }
#line 1966 "parser.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 622 "parser.ypp" /* yacc.c:1646  */
    {
      string label_endif = pop_label();
      label(label_endif);
    }
#line 1975 "parser.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 630 "parser.ypp" /* yacc.c:1646  */
    {
      string label_while = new_label("while");
      label(label_while);
      push_label(label_while);
    }
#line 1985 "parser.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 636 "parser.ypp" /* yacc.c:1646  */
    {
      string label_end = new_label("end_while"); 
      string label_continue = new_label("continue_while"); 
      int true_register = new_register();

      ldi(true_register,1);
      cjump((yyvsp[0].integer),E,true_register,label_continue);
      j(label_end); //if false => goto label_end
      label(label_continue);

      push_label(label_end);
    }
#line 2002 "parser.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 649 "parser.ypp" /* yacc.c:1646  */
    { 
      string label_end = pop_label();
      string label_while = pop_label();
      j(label_while);
      label(label_end);
    }
#line 2013 "parser.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 660 "parser.ypp" /* yacc.c:1646  */
    {
      string label_begin_for = new_label("for");
      label(label_begin_for);
      //begin_for:
      push_label(label_begin_for);
    }
#line 2024 "parser.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 667 "parser.ypp" /* yacc.c:1646  */
    {
      string label_end_for = new_label("end_for");
      string label_continue_for = new_label("continue_for");
      int true_register = new_register();
      ldi(true_register,1);
      cjump((yyvsp[-1].integer),E,true_register,label_continue_for);
      j(label_end_for); //if false => goto label_end
      label(label_continue_for);

      push_label(label_end_for);
    }
#line 2040 "parser.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 681 "parser.ypp" /* yacc.c:1646  */
    {
      string label_end_for = pop_label();
      string label_begin_for = pop_label();
      int counter = get_register((yyvsp[-3].id_string));
      int one_reg = new_register();
      ldi(one_reg,1);
      add(counter,counter,one_reg); 
      //counter++
      j(label_begin_for);
      //goto begin_for
      label(label_end_for);
    }
#line 2057 "parser.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 697 "parser.ypp" /* yacc.c:1646  */
    { 
      if(!(*((yyvsp[-1].rhs_expr)->type) == *current_return_type))
	{
	  cerr << "Line " << line_number << ": error: wrong return type"
	       << endl;
	  exit(1);
	} //Type checking

      copy(RETURN_REGISTER,(yyvsp[-1].rhs_expr)->result_register); 
      j(label_end_function); 
    }
#line 2073 "parser.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 712 "parser.ypp" /* yacc.c:1646  */
    { 
      arg_type.resize(0); //filled by caller_arg_list, type checking

      string label_call = new_label("call");
      label(label_call); //start a new basic block...

      push_all(); 
    }
#line 2086 "parser.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 721 "parser.ypp" /* yacc.c:1646  */
    { 
      type_check((yyvsp[-5].id_string),arg_type); 
      if(return_type((yyvsp[-5].id_string))->type_id != VOID)
	{
	  cerr << "Line " << line_number << ": error: procedure must return "
	       << "void" << endl;
	  exit(1);
	}
      //type checking

      call((yyvsp[-5].id_string)); pop_all(); 

      string label_end_call = new_label("end_call");
      label(label_end_call); //end the basic block...
    }
#line 2106 "parser.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 756 "parser.ypp" /* yacc.c:1646  */
    { 
      Type* type = (yyvsp[-1].type);
      normalize_type(type); //substitute type IDs
      add_argument_type(type); //type checking
      add_argument((yyvsp[0].id_string),type); 
    }
#line 2117 "parser.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 763 "parser.ypp" /* yacc.c:1646  */
    { 
      Type* type = (yyvsp[-1].type);
      normalize_type(type); //substitute type IDs
      add_argument_type(type); //type checking
      add_argument((yyvsp[0].id_string),type); 
    }
#line 2128 "parser.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 773 "parser.ypp" /* yacc.c:1646  */
    { 
      Type* type = (yyvsp[-2].type);
      normalize_type(type); //substitute type IDs
      add_local_var((yyvsp[-1].id_string),type); 
    }
#line 2138 "parser.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 786 "parser.ypp" /* yacc.c:1646  */
    { 
      arg_type.push_back((yyvsp[0].rhs_expr)->type); //type checking
      push((yyvsp[0].rhs_expr)->result_register); 
    }
#line 2147 "parser.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 791 "parser.ypp" /* yacc.c:1646  */
    { 
      arg_type.push_back((yyvsp[0].rhs_expr)->type); //type checking
      push((yyvsp[0].rhs_expr)->result_register); 
    }
#line 2156 "parser.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 800 "parser.ypp" /* yacc.c:1646  */
    { 
      add_function((yyvsp[-1].id_string),(yyvsp[-2].type)); 
      current_return_type = (yyvsp[-2].type); //type checking
      reset_registers(); reset_variables(); 
    }
#line 2166 "parser.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 807 "parser.ypp" /* yacc.c:1646  */
    {
      label((yyvsp[-6].id_string)); 
      label_end_function = string((yyvsp[-6].id_string));
      label_end_function += "_end";
      prelude();
    }
#line 2177 "parser.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 814 "parser.ypp" /* yacc.c:1646  */
    {
      label(label_end_function);
      postlude();
    }
#line 2186 "parser.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 830 "parser.ypp" /* yacc.c:1646  */
    { 
      normalize_types(); reset_functions(); //type checking

      //Jump to the program's entry point
      reset_registers();

      //1) init the stack
      ldi(SP,255); 

      //2) init the heap
      label(new_label("call"));
      push_all();          
      call("__init_heap"); 
      pop_all(); 
      label(new_label("end_call"));

      //3) Jump to the entry point
      label(new_label("call"));
      push_all(); 
      call("main");
      pop_all();
      label(new_label("end_call"));
      
      label("stop"); j("stop");
    }
#line 2216 "parser.cc" /* yacc.c:1646  */
    break;


#line 2220 "parser.cc" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
