/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         HSQL_STYPE
#define YYLTYPE         HSQL_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         hsql_parse
#define yylex           hsql_lex
#define yyerror         hsql_error
#define yydebug         hsql_debug
#define yynerrs         hsql_nerrs


/* Copy the first part of user declarations.  */
#line 1 "bison_parser.y" /* yacc.c:339  */

/**
 * bison_parser.y
 * defines bison_parser.h
 * outputs bison_parser.c
 * 
 * Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "bison_parser.h"
#include "flex_lexer.h"

#include <stdio.h>

using namespace hsql;

int yyerror(YYLTYPE* llocp, SQLParserResult** result, yyscan_t scanner, const char *msg) {
	delete *result;

	SQLParserResult* list = new SQLParserResult();
	list->setIsValid(false);
	list->setErrorDetails(strdup(msg), llocp->first_line, llocp->first_column);

	*result = list;
	return 0;
}




#line 109 "bison_parser.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison_parser.h".  */
#ifndef YY_HSQL_BISON_PARSER_H_INCLUDED
# define YY_HSQL_BISON_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef HSQL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define HSQL_DEBUG 1
#  else
#   define HSQL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define HSQL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined HSQL_DEBUG */
#if HSQL_DEBUG
extern int hsql_debug;
#endif
/* "%code requires" blocks.  */
#line 41 "bison_parser.y" /* yacc.c:355  */

// %code requires block	

#include "../sql/statements.h"
#include "../SQLParserResult.h"
#include "parser_typedef.h"

// Auto update column and line number
#define YY_USER_ACTION \
    yylloc->first_line = yylloc->last_line; \
    yylloc->first_column = yylloc->last_column; \
    for(int i = 0; yytext[i] != '\0'; i++) { \
    	yylloc->total_column++; \
        if(yytext[i] == '\n') { \
            yylloc->last_line++; \
            yylloc->last_column = 0; \
        } \
        else { \
            yylloc->last_column++; \
        } \
    }

#line 170 "bison_parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef HSQL_TOKENTYPE
# define HSQL_TOKENTYPE
  enum hsql_tokentype
  {
    SQL_IDENTIFIER = 258,
    SQL_STRING = 259,
    SQL_FLOATVAL = 260,
    SQL_INTVAL = 261,
    SQL_NOTEQUALS = 262,
    SQL_LESSEQ = 263,
    SQL_GREATEREQ = 264,
    SQL_DEALLOCATE = 265,
    SQL_PARAMETERS = 266,
    SQL_INTERSECT = 267,
    SQL_TEMPORARY = 268,
    SQL_TIMESTAMP = 269,
    SQL_DISTINCT = 270,
    SQL_NVARCHAR = 271,
    SQL_RESTRICT = 272,
    SQL_TRUNCATE = 273,
    SQL_ANALYZE = 274,
    SQL_BETWEEN = 275,
    SQL_CASCADE = 276,
    SQL_COLUMNS = 277,
    SQL_CONTROL = 278,
    SQL_DEFAULT = 279,
    SQL_EXECUTE = 280,
    SQL_EXPLAIN = 281,
    SQL_HISTORY = 282,
    SQL_INTEGER = 283,
    SQL_NATURAL = 284,
    SQL_PREPARE = 285,
    SQL_PRIMARY = 286,
    SQL_SCHEMAS = 287,
    SQL_SPATIAL = 288,
    SQL_VIRTUAL = 289,
    SQL_BEFORE = 290,
    SQL_COLUMN = 291,
    SQL_CREATE = 292,
    SQL_DELETE = 293,
    SQL_DIRECT = 294,
    SQL_DOUBLE = 295,
    SQL_ESCAPE = 296,
    SQL_EXCEPT = 297,
    SQL_EXISTS = 298,
    SQL_GLOBAL = 299,
    SQL_HAVING = 300,
    SQL_IMPORT = 301,
    SQL_INSERT = 302,
    SQL_ISNULL = 303,
    SQL_OFFSET = 304,
    SQL_RENAME = 305,
    SQL_SCHEMA = 306,
    SQL_SELECT = 307,
    SQL_SORTED = 308,
    SQL_TABLES = 309,
    SQL_UNIQUE = 310,
    SQL_UNLOAD = 311,
    SQL_UPDATE = 312,
    SQL_VALUES = 313,
    SQL_AFTER = 314,
    SQL_ALTER = 315,
    SQL_CROSS = 316,
    SQL_DELTA = 317,
    SQL_GROUP = 318,
    SQL_INDEX = 319,
    SQL_INNER = 320,
    SQL_LIMIT = 321,
    SQL_LOCAL = 322,
    SQL_MERGE = 323,
    SQL_MINUS = 324,
    SQL_ORDER = 325,
    SQL_OUTER = 326,
    SQL_RIGHT = 327,
    SQL_TABLE = 328,
    SQL_UNION = 329,
    SQL_USING = 330,
    SQL_WHERE = 331,
    SQL_CALL = 332,
    SQL_CASE = 333,
    SQL_DATE = 334,
    SQL_DESC = 335,
    SQL_DROP = 336,
    SQL_ELSE = 337,
    SQL_FILE = 338,
    SQL_FROM = 339,
    SQL_FULL = 340,
    SQL_HASH = 341,
    SQL_HINT = 342,
    SQL_INTO = 343,
    SQL_JOIN = 344,
    SQL_LEFT = 345,
    SQL_LIKE = 346,
    SQL_LOAD = 347,
    SQL_NULL = 348,
    SQL_PART = 349,
    SQL_PLAN = 350,
    SQL_SHOW = 351,
    SQL_TEXT = 352,
    SQL_THEN = 353,
    SQL_TIME = 354,
    SQL_CHAR = 355,
    SQL_VIEW = 356,
    SQL_WHEN = 357,
    SQL_WITH = 358,
    SQL_ADD = 359,
    SQL_ALL = 360,
    SQL_AND = 361,
    SQL_ASC = 362,
    SQL_CSV = 363,
    SQL_END = 364,
    SQL_FOR = 365,
    SQL_INT = 366,
    SQL_KEY = 367,
    SQL_NOT = 368,
    SQL_OFF = 369,
    SQL_SET = 370,
    SQL_TBL = 371,
    SQL_TOP = 372,
    SQL_AS = 373,
    SQL_BY = 374,
    SQL_IF = 375,
    SQL_IN = 376,
    SQL_IS = 377,
    SQL_OF = 378,
    SQL_ON = 379,
    SQL_OR = 380,
    SQL_TO = 381,
    SQL_EQUALS = 382,
    SQL_LESS = 383,
    SQL_GREATER = 384,
    SQL_NOTNULL = 385,
    SQL_UMINUS = 386
  };
#endif

/* Value type.  */
#if ! defined HSQL_STYPE && ! defined HSQL_STYPE_IS_DECLARED
typedef union HSQL_STYPE HSQL_STYPE;
union HSQL_STYPE
{
#line 100 "bison_parser.y" /* yacc.c:355  */

	double fval;
	int64_t ival;
	char* sval;
	uintmax_t uval;
	bool bval;

	hsql::SQLStatement* statement;
	hsql::SelectStatement* 	select_stmt;
	hsql::ImportStatement* 	import_stmt;
	hsql::CreateStatement* 	create_stmt;
	hsql::InsertStatement* 	insert_stmt;
	hsql::DeleteStatement* 	delete_stmt;
	hsql::UpdateStatement* 	update_stmt;
	hsql::DropStatement*   	drop_stmt;
	hsql::PrepareStatement* prep_stmt;
	hsql::ExecuteStatement* exec_stmt;

	hsql::TableRef* table;
	hsql::Expr* expr;
	hsql::OrderDescription* order;
	hsql::OrderType order_type;
	hsql::LimitDescription* limit;
	hsql::ColumnDefinition* column_t;
	hsql::GroupByDescription* group_t;
	hsql::UpdateClause* update_t;

	hsql::SQLParserResult* stmt_list;

	std::vector<char*>* str_vec;
	std::vector<hsql::TableRef*>* table_vec;
	std::vector<hsql::ColumnDefinition*>* column_vec;
	std::vector<hsql::UpdateClause*>* update_vec;
	std::vector<hsql::Expr*>* expr_vec;
	std::vector<hsql::OrderDescription*>* order_vec;

#line 351 "bison_parser.cpp" /* yacc.c:355  */
};
# define HSQL_STYPE_IS_TRIVIAL 1
# define HSQL_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined HSQL_LTYPE && ! defined HSQL_LTYPE_IS_DECLARED
typedef struct HSQL_LTYPE HSQL_LTYPE;
struct HSQL_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define HSQL_LTYPE_IS_DECLARED 1
# define HSQL_LTYPE_IS_TRIVIAL 1
#endif



int hsql_parse (hsql::SQLParserResult** result, yyscan_t scanner);

#endif /* !YY_HSQL_BISON_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 379 "bison_parser.cpp" /* yacc.c:358  */

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
         || (defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL \
             && defined HSQL_STYPE_IS_TRIVIAL && HSQL_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   442

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  152
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  325

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   386

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   138,     2,     2,
     143,   144,   136,   134,   150,   135,   145,   137,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   147,   146,
     129,   127,   130,   151,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   141,     2,   142,   139,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   148,     2,   149,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   128,   131,   132,   133,   140
};

#if HSQL_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   245,   245,   252,   253,   257,   262,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   283,   288,   296,   300,
     312,   320,   324,   334,   340,   346,   356,   357,   361,   362,
     366,   369,   376,   377,   378,   379,   389,   393,   397,   409,
     417,   429,   435,   445,   446,   456,   465,   466,   470,   482,
     483,   487,   488,   492,   502,   516,   530,   531,   532,   536,
     548,   549,   553,   557,   562,   563,   567,   572,   576,   577,
     580,   581,   585,   586,   590,   594,   595,   596,   602,   603,
     607,   608,   609,   616,   617,   621,   622,   626,   633,   634,
     635,   636,   637,   638,   642,   643,   644,   645,   646,   647,
     651,   652,   653,   657,   658,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   674,   675,   679,   680,   681,   682,
     687,   691,   692,   696,   697,   698,   699,   700,   701,   705,
     709,   713,   714,   718,   719,   720,   724,   729,   730,   734,
     738,   742,   753,   754,   764,   765,   771,   776,   777,   782,
     792,   800,   801,   806,   807,   811,   812,   820,   832,   833,
     834,   835,   836,   837,   838,   839,   840,   846,   852,   856,
     865,   866,   871,   872
};
#endif

#if HSQL_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "FLOATVAL",
  "INTVAL", "NOTEQUALS", "LESSEQ", "GREATEREQ", "DEALLOCATE", "PARAMETERS",
  "INTERSECT", "TEMPORARY", "TIMESTAMP", "DISTINCT", "NVARCHAR",
  "RESTRICT", "TRUNCATE", "ANALYZE", "BETWEEN", "CASCADE", "COLUMNS",
  "CONTROL", "DEFAULT", "EXECUTE", "EXPLAIN", "HISTORY", "INTEGER",
  "NATURAL", "PREPARE", "PRIMARY", "SCHEMAS", "SPATIAL", "VIRTUAL",
  "BEFORE", "COLUMN", "CREATE", "DELETE", "DIRECT", "DOUBLE", "ESCAPE",
  "EXCEPT", "EXISTS", "GLOBAL", "HAVING", "IMPORT", "INSERT", "ISNULL",
  "OFFSET", "RENAME", "SCHEMA", "SELECT", "SORTED", "TABLES", "UNIQUE",
  "UNLOAD", "UPDATE", "VALUES", "AFTER", "ALTER", "CROSS", "DELTA",
  "GROUP", "INDEX", "INNER", "LIMIT", "LOCAL", "MERGE", "MINUS", "ORDER",
  "OUTER", "RIGHT", "TABLE", "UNION", "USING", "WHERE", "CALL", "CASE",
  "DATE", "DESC", "DROP", "ELSE", "FILE", "FROM", "FULL", "HASH", "HINT",
  "INTO", "JOIN", "LEFT", "LIKE", "LOAD", "NULL", "PART", "PLAN", "SHOW",
  "TEXT", "THEN", "TIME", "CHAR", "VIEW", "WHEN", "WITH", "ADD", "ALL",
  "AND", "ASC", "CSV", "END", "FOR", "INT", "KEY", "NOT", "OFF", "SET",
  "TBL", "TOP", "AS", "BY", "IF", "IN", "IS", "OF", "ON", "OR", "TO",
  "'='", "EQUALS", "'<'", "'>'", "LESS", "GREATER", "NOTNULL", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'^'", "UMINUS", "'['", "']'", "'('", "')'",
  "'.'", "';'", "':'", "'{'", "'}'", "','", "'?'", "$accept", "input",
  "statement_list", "statement", "preparable_statement",
  "prepare_statement", "execute_statement", "import_statement",
  "import_file_type", "file_path", "create_statement", "opt_not_exists",
  "column_def_commalist", "column_def", "column_type", "drop_statement",
  "delete_statement", "truncate_statement", "insert_statement",
  "opt_column_list", "update_statement", "update_clause_commalist",
  "update_clause", "select_statement", "select_with_paren",
  "select_no_paren", "set_operator", "select_clause", "opt_distinct",
  "select_list", "from_clause", "opt_where", "opt_group", "opt_having",
  "opt_order", "order_list", "order_desc", "opt_order_type", "opt_top",
  "opt_limit", "expr_list", "literal_list", "expr_alias", "expr",
  "operand", "scalar_expr", "unary_expr", "binary_expr", "logic_expr",
  "in_expr", "case_expr", "exists_expr", "comp_expr", "function_expr",
  "between_expr", "column_name", "literal", "string_literal",
  "num_literal", "int_literal", "star_expr", "placeholder_expr",
  "table_ref", "table_ref_atomic", "table_ref_commalist", "table_ref_name",
  "table_ref_name_no_alias", "table_name", "alias", "opt_alias",
  "join_clause", "opt_join_type", "join_table", "join_condition",
  "opt_semicolon", "ident_commalist", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,    61,   382,    60,
      62,   383,   384,   385,    43,    45,    42,    47,    37,    94,
     386,    91,    93,    40,    41,    46,    59,    58,   123,   125,
      44,    63
};
# endif

#define YYPACT_NINF -259

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-259)))

#define YYTABLE_NINF -169

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-169)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      91,    35,   101,   104,   116,   -31,    46,    48,    56,    59,
     101,    30,   -41,   152,    27,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,   108,
     178,    40,  -259,    45,   -96,    76,    76,   101,   105,   101,
     203,   202,   110,  -259,   101,   101,    88,    93,  -259,    91,
    -259,  -259,  -259,   127,  -259,   -41,   184,  -259,   251,    14,
     174,    91,   143,   101,   101,   183,  -259,   180,   122,  -259,
    -259,  -259,    11,   263,  -259,  -259,  -259,  -259,  -259,    11,
     204,   204,   203,  -259,  -259,  -259,  -259,  -259,   -45,  -259,
    -259,  -259,  -259,  -259,  -259,    27,   230,   -51,   122,    11,
    -259,   272,   277,    65,  -107,   138,   181,    23,    55,  -259,
      44,   198,   135,  -259,    97,   106,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,   159,
     -53,  -259,   137,  -259,    28,   184,   184,   241,  -259,    14,
     144,  -259,   186,   302,   188,   -72,   219,  -259,  -259,    57,
     165,  -259,   202,   306,   258,    11,   168,    55,   253,   133,
     172,    61,     2,   183,    11,  -259,    11,   315,    11,  -259,
    -259,    55,    55,    55,    55,    55,    19,   182,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    14,   263,  -259,
      11,  -259,  -259,  -259,  -259,  -259,   203,  -259,  -259,   243,
      78,    64,  -259,   -41,   101,  -259,   324,    14,    11,  -259,
     189,    58,   258,   237,  -259,  -259,   -41,  -259,   179,   275,
       9,  -259,   223,   267,  -259,  -259,  -259,   226,   270,   185,
     185,   162,   270,    55,   192,    44,   270,   185,   185,   133,
     133,   199,   199,   199,  -259,  -259,  -259,  -259,  -259,   272,
    -259,  -259,  -259,  -259,   194,  -259,   302,  -259,  -259,  -259,
      66,    74,  -259,    55,   195,   197,     2,  -259,  -259,  -259,
    -259,  -259,   271,   274,   254,   233,  -259,    55,   270,    44,
     210,   107,  -259,   356,  -259,  -259,  -259,   221,  -259,     9,
    -259,   213,  -259,  -259,     6,    11,   253,   224,   114,  -259,
    -259,   227,    55,   352,  -259,     2,   -41,  -259,   248,   -39,
    -259,  -259,  -259,   240,  -259,   229,    11,    11,  -259,  -259,
       9,   -72,  -259,   -72,  -259
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
       0,     0,     0,     0,   171,     3,     6,     5,    15,     8,
       9,    14,    11,    12,    10,    13,     7,    49,    50,    71,
       0,   151,    40,    18,     0,    27,    27,     0,     0,     0,
       0,    61,     0,   150,     0,     0,     0,     0,     1,   170,
       2,    57,    58,     0,    56,     0,    82,    38,     0,     0,
       0,     0,     0,     0,     0,    65,    21,     0,    44,   139,
      78,    60,     0,     0,    36,    37,    52,    51,     4,     0,
      71,    71,     0,    53,   152,   136,   137,   141,     0,    85,
     133,   134,   138,   135,    16,   171,     0,     0,    44,     0,
      39,     0,     0,     0,   131,     0,     0,     0,     0,   140,
       0,     0,    62,    83,   156,    88,    95,    96,    97,    90,
      93,    92,    91,   105,    98,    89,   100,   102,   101,     0,
      65,    46,    70,    72,    77,    82,    82,    80,    19,     0,
       0,    26,     0,     0,     0,    64,     0,    22,   172,     0,
       0,    42,    61,     0,     0,     0,     0,     0,   104,   103,
       0,     0,     0,    65,     0,   154,     0,     0,     0,   155,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,    76,    75,    74,    55,    54,     0,    86,    17,     0,
       0,     0,    28,     0,     0,    43,     0,     0,     0,   132,
       0,     0,     0,     0,    99,    94,     0,    63,   142,   144,
     156,   146,   166,    67,    84,   114,   153,   115,   124,   127,
     128,     0,   112,     0,     0,     0,   123,   125,   126,   107,
     106,   109,   108,   110,   111,    48,    47,    73,    81,     0,
      33,    34,    35,    32,    30,    24,     0,    25,    20,   173,
       0,     0,   121,     0,     0,     0,     0,   149,   165,   164,
     158,   159,   163,   162,     0,     0,    59,     0,   113,     0,
       0,     0,    23,     0,    29,    41,   129,     0,   122,   156,
     147,   143,   161,   160,     0,     0,   130,     0,     0,   118,
     116,     0,     0,   155,   145,     0,     0,   168,     0,    69,
     119,   117,    31,     0,   148,     0,     0,     0,    66,   120,
       0,   169,   157,    68,   167
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -259,  -259,   323,   336,   326,  -259,  -259,  -259,  -259,   145,
    -259,   357,  -259,   139,  -259,  -259,  -259,  -259,  -259,   298,
    -259,  -259,   214,  -181,    12,   -12,  -259,   343,   249,  -259,
    -259,   -87,  -259,  -259,   -40,  -259,   220,  -259,  -259,   -80,
    -140,   196,   247,   -78,  -100,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,   -46,   -98,  -259,   -36,
    -259,  -259,  -259,  -236,  -259,   118,  -259,     0,  -258,  -195,
    -259,  -259,   120,  -259,   320,  -259
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,    18,    19,    67,   146,
      20,    63,   201,   202,   254,    21,    22,    23,    24,   103,
      25,   130,   131,    26,    27,    28,    55,    29,    72,   111,
     163,   100,   276,   318,    56,   132,   133,   193,    41,    83,
     112,    88,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    90,    91,    92,
     128,    93,   217,   218,   291,   219,    42,   220,   169,   170,
     221,   274,   222,   322,    50,   149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,   134,    32,   147,    70,    31,   317,   158,   159,    31,
      43,     9,   165,    89,   104,    85,    86,    69,    85,    86,
      69,   145,   257,    99,    46,   267,   104,    85,    86,    69,
     290,   303,   161,   142,   166,   265,   152,    65,   153,    68,
     135,   136,    35,   189,    74,    75,   137,   104,    85,    86,
      69,    60,    61,   168,   105,   194,   195,   158,   104,    85,
      86,    69,   324,    97,    98,    30,   156,    80,   261,   314,
      36,   228,   229,   230,   231,   232,   223,   211,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   105,   225,   106,
     227,   151,   143,   197,   304,   281,     9,   188,   160,   138,
     165,     1,    12,    44,    31,   139,   250,    33,   191,     2,
     233,   164,   134,   171,   172,   173,     3,     9,   251,    34,
      51,     4,   106,   150,   107,   315,   174,   167,     5,     6,
      37,    45,    38,   278,   166,   192,   157,     7,     8,   298,
     234,   245,   210,     9,    39,   216,   108,   109,    10,   306,
      52,   147,    48,   168,   110,   309,   263,   107,   108,   109,
     248,    89,    87,   287,   166,    87,   110,   166,   157,   171,
     172,   173,    11,    49,    87,   252,    40,   296,    53,   108,
     109,    57,    54,   168,     1,    58,   168,   110,    59,   253,
     108,   109,     2,  -169,  -169,    87,    62,   175,   110,     3,
     264,   205,   313,   166,   258,   215,    87,   206,   255,    69,
     285,     5,     6,    66,   256,   167,   139,    71,   286,   176,
       7,     8,   168,   280,   164,    73,     9,   177,   171,   172,
     173,    10,    76,   178,    12,   179,   180,    77,   321,   323,
     181,   182,   183,   184,   185,   186,    79,   171,   172,   173,
      82,   300,   268,   175,    84,    11,    96,   164,   311,    99,
     171,   172,   173,   101,   164,   102,   129,   297,   277,   183,
     184,   185,   186,   141,    53,   213,    85,   171,   172,   173,
     148,   154,   162,   155,   269,   164,   187,   190,   270,   178,
     196,   179,   180,   198,   271,   272,   181,   182,   183,   184,
     185,   186,   199,   302,  -168,   200,   203,   204,   207,   209,
       9,   212,   175,   273,  -169,  -169,   214,    12,   226,   181,
     182,   183,   184,   185,   186,   235,   249,   259,   233,   266,
     275,   175,   166,   262,   213,   279,  -168,   283,   186,   288,
    -168,   289,   292,   294,   175,   293,  -168,  -168,   178,   319,
     179,   180,   295,   213,   299,   181,   182,   183,   184,   185,
     186,   175,   301,   305,  -168,  -168,   213,   178,   310,   179,
     180,   312,   316,   320,   181,   182,   183,   184,   185,   186,
     178,  -167,   179,   180,    95,    78,    94,   181,   182,   183,
     184,   185,   186,    64,   282,   284,   144,   178,    81,   179,
     180,   208,   246,   260,   181,   182,   183,   184,   185,   186,
     247,   224,   307,  -167,   308,   140,     0,  -167,     0,     0,
       0,     0,     0,  -167,  -167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -167,  -167
};

static const yytype_int16 yycheck[] =
{
      12,    79,     2,   101,    40,     3,    45,   107,   108,     3,
      10,    52,     3,    59,     3,     4,     5,     6,     4,     5,
       6,    99,   203,    76,    12,   220,     3,     4,     5,     6,
     266,   289,   110,    84,   106,   216,   143,    37,   145,    39,
      80,    81,    73,   130,    44,    45,    82,     3,     4,     5,
       6,   147,   148,   125,    43,   135,   136,   157,     3,     4,
       5,     6,   320,    63,    64,    30,    43,    55,   208,   305,
     101,   171,   172,   173,   174,   175,   163,   155,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    43,   166,    78,
     168,   103,   143,   139,   289,   235,    52,   150,   110,   144,
       3,    10,   143,    73,     3,   150,    28,     3,    80,    18,
      91,   150,   190,     7,     8,     9,    25,    52,    40,     3,
      12,    30,    78,    58,   113,   306,    20,   118,    37,    38,
      84,   101,    84,   233,   106,   107,   113,    46,    47,   279,
     121,   187,   154,    52,    88,   143,   135,   136,    57,   143,
      42,   249,     0,   125,   143,   295,    98,   113,   135,   136,
     196,   207,   151,   263,   106,   151,   143,   106,   113,     7,
       8,     9,    81,   146,   151,    97,   117,   277,    70,   135,
     136,     3,    74,   125,    10,   145,   125,   143,   143,   111,
     135,   136,    18,     8,     9,   151,   120,    91,   143,    25,
     212,   144,   302,   106,   204,   144,   151,   150,   144,     6,
     144,    37,    38,   108,   150,   118,   150,    15,   144,   113,
      46,    47,   125,   235,   150,   115,    52,   121,     7,     8,
       9,    57,   144,   127,   143,   129,   130,   144,   316,   317,
     134,   135,   136,   137,   138,   139,   119,     7,     8,     9,
      66,   144,    29,    91,     3,    81,   113,   150,   144,    76,
       7,     8,     9,    83,   150,   143,     3,   279,   106,   136,
     137,   138,   139,    43,    70,   113,     4,     7,     8,     9,
       3,   143,    84,   102,    61,   150,   127,   150,    65,   127,
      49,   129,   130,   149,    71,    72,   134,   135,   136,   137,
     138,   139,   116,    82,    29,     3,   118,    88,   143,     3,
      52,   143,    91,    90,   129,   130,   144,   143,     3,   134,
     135,   136,   137,   138,   139,   143,    83,     3,    91,   150,
      63,    91,   106,   144,   113,   143,    61,   143,   139,   144,
      65,   144,    71,    89,    91,    71,    71,    72,   127,   109,
     129,   130,   119,   113,   144,   134,   135,   136,   137,   138,
     139,    91,     6,   150,    89,    90,   113,   127,   144,   129,
     130,   144,   124,   144,   134,   135,   136,   137,   138,   139,
     127,    29,   129,   130,    61,    49,    60,   134,   135,   136,
     137,   138,   139,    36,   249,   256,    98,   127,    55,   129,
     130,   152,   188,   207,   134,   135,   136,   137,   138,   139,
     190,   164,   294,    61,   294,    95,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    18,    25,    30,    37,    38,    46,    47,    52,
      57,    81,   143,   153,   154,   155,   156,   157,   158,   159,
     162,   167,   168,   169,   170,   172,   175,   176,   177,   179,
      30,     3,   219,     3,     3,    73,   101,    84,    84,    88,
     117,   190,   218,   219,    73,   101,   176,   177,     0,   146,
     226,    12,    42,    70,    74,   178,   186,     3,   145,   143,
     147,   148,   120,   163,   163,   219,   108,   160,   219,     6,
     211,    15,   180,   115,   219,   219,   144,   144,   155,   119,
     176,   179,    66,   191,     3,     4,     5,   151,   193,   208,
     209,   210,   211,   213,   156,   154,   113,   219,   219,    76,
     183,    83,   143,   171,     3,    43,    78,   113,   135,   136,
     143,   181,   192,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   212,     3,
     173,   174,   187,   188,   195,   186,   186,   211,   144,   150,
     226,    43,    84,   143,   171,   195,   161,   209,     3,   227,
      58,   177,   143,   145,   143,   102,    43,   113,   196,   196,
     177,   195,    84,   182,   150,     3,   106,   118,   125,   220,
     221,     7,     8,     9,    20,    91,   113,   121,   127,   129,
     130,   134,   135,   136,   137,   138,   139,   127,   150,   183,
     150,    80,   107,   189,   191,   191,    49,   208,   149,   116,
       3,   164,   165,   118,    88,   144,   150,   143,   180,     3,
     177,   195,   143,   113,   144,   144,   143,   214,   215,   217,
     219,   222,   224,   183,   194,   195,     3,   195,   196,   196,
     196,   196,   196,    91,   121,   143,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   208,   174,   188,   211,    83,
      28,    40,    97,   111,   166,   144,   150,   175,   219,     3,
     193,   192,   144,    98,   177,   175,   150,   221,    29,    61,
      65,    71,    72,    90,   223,    63,   184,   106,   196,   143,
     177,   192,   161,   143,   165,   144,   144,   196,   144,   144,
     215,   216,    71,    71,    89,   119,   196,   177,   192,   144,
     144,     6,    82,   220,   221,   150,   143,   217,   224,   192,
     144,   144,   144,   196,   215,   175,   124,    45,   185,   109,
     144,   195,   225,   195,   220
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   152,   153,   154,   154,   155,   155,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   157,   157,   158,   158,
     159,   160,   161,   162,   162,   162,   163,   163,   164,   164,
     165,   165,   166,   166,   166,   166,   167,   167,   167,   168,
     169,   170,   170,   171,   171,   172,   173,   173,   174,   175,
     175,   176,   176,   177,   177,   177,   178,   178,   178,   179,
     180,   180,   181,   182,   183,   183,   184,   184,   185,   185,
     186,   186,   187,   187,   188,   189,   189,   189,   190,   190,
     191,   191,   191,   192,   192,   193,   193,   194,   195,   195,
     195,   195,   195,   195,   196,   196,   196,   196,   196,   196,
     197,   197,   197,   198,   198,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   200,   200,   201,   201,   201,   201,
     202,   203,   203,   204,   204,   204,   204,   204,   204,   205,
     206,   207,   207,   208,   208,   208,   209,   210,   210,   211,
     212,   213,   214,   214,   215,   215,   215,   216,   216,   217,
     218,   219,   219,   220,   220,   221,   221,   222,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   224,   224,   225,
     226,   226,   227,   227
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     6,     2,     5,
       7,     1,     1,     8,     7,     7,     3,     0,     1,     3,
       2,     5,     1,     1,     1,     1,     3,     3,     3,     4,
       2,     8,     5,     3,     0,     5,     1,     3,     3,     1,
       1,     3,     3,     3,     5,     5,     1,     1,     1,     7,
       1,     0,     1,     2,     2,     0,     4,     0,     2,     0,
       3,     0,     1,     3,     2,     1,     1,     0,     2,     0,
       2,     4,     0,     1,     3,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     3,     5,     6,     5,     6,
       8,     4,     5,     3,     3,     3,     3,     3,     3,     5,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     1,     1,     3,     2,
       1,     1,     3,     2,     1,     1,     0,     6,     1,     1,
       2,     2,     1,     1,     1,     1,     0,     4,     1,     1,
       1,     0,     1,     3
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
      yyerror (&yylloc, result, scanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if HSQL_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult** result, yyscan_t scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult** result, yyscan_t scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, result, scanner);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, hsql::SQLParserResult** result, yyscan_t scanner)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !HSQL_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !HSQL_DEBUG */


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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, hsql::SQLParserResult** result, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* IDENTIFIER  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1580 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 4: /* STRING  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1586 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 5: /* FLOATVAL  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1592 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 6: /* INTVAL  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1598 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 7: /* NOTEQUALS  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1604 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 8: /* LESSEQ  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1610 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 9: /* GREATEREQ  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1616 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 154: /* statement_list  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).stmt_list)); }
#line 1622 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 155: /* statement  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).statement)); }
#line 1628 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 156: /* preparable_statement  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).statement)); }
#line 1634 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 157: /* prepare_statement  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).prep_stmt)); }
#line 1640 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 158: /* execute_statement  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).exec_stmt)); }
#line 1646 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 159: /* import_statement  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).import_stmt)); }
#line 1652 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 160: /* import_file_type  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1658 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 161: /* file_path  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1664 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 162: /* create_statement  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).create_stmt)); }
#line 1670 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 163: /* opt_not_exists  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1676 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 164: /* column_def_commalist  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).column_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).column_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).column_vec));
}
#line 1689 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 165: /* column_def  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).column_t)); }
#line 1695 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 166: /* column_type  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1701 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 167: /* drop_statement  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).drop_stmt)); }
#line 1707 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 168: /* delete_statement  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).delete_stmt)); }
#line 1713 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 169: /* truncate_statement  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).delete_stmt)); }
#line 1719 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 170: /* insert_statement  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).insert_stmt)); }
#line 1725 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 171: /* opt_column_list  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).str_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 1738 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 172: /* update_statement  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).update_stmt)); }
#line 1744 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 173: /* update_clause_commalist  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).update_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).update_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).update_vec));
}
#line 1757 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 174: /* update_clause  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).update_t)); }
#line 1763 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 175: /* select_statement  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1769 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 176: /* select_with_paren  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1775 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 177: /* select_no_paren  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1781 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 179: /* select_clause  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1787 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 180: /* opt_distinct  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1793 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 181: /* select_list  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1806 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 182: /* from_clause  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 1812 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 183: /* opt_where  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1818 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 184: /* opt_group  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).group_t)); }
#line 1824 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 185: /* opt_having  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1830 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 186: /* opt_order  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).order_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).order_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).order_vec));
}
#line 1843 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 187: /* order_list  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).order_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).order_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).order_vec));
}
#line 1856 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 188: /* order_desc  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).order)); }
#line 1862 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 189: /* opt_order_type  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1868 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 190: /* opt_top  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).limit)); }
#line 1874 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 191: /* opt_limit  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).limit)); }
#line 1880 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 192: /* expr_list  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1893 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 193: /* literal_list  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1906 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 194: /* expr_alias  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1912 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 195: /* expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1918 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 196: /* operand  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1924 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 197: /* scalar_expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1930 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 198: /* unary_expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1936 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 199: /* binary_expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1942 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 200: /* logic_expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1948 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 201: /* in_expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1954 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 202: /* case_expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1960 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 203: /* exists_expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1966 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 204: /* comp_expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1972 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 205: /* function_expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1978 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 206: /* between_expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1984 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 207: /* column_name  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1990 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 208: /* literal  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1996 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 209: /* string_literal  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2002 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 210: /* num_literal  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2008 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 211: /* int_literal  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2014 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 212: /* star_expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2020 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 213: /* placeholder_expr  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2026 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 214: /* table_ref  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2032 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 215: /* table_ref_atomic  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2038 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 216: /* table_ref_commalist  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).table_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).table_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).table_vec));
}
#line 2051 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 217: /* table_ref_name  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2057 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 218: /* table_ref_name_no_alias  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2063 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 219: /* table_name  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 2069 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 220: /* alias  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 2075 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 221: /* opt_alias  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 2081 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 222: /* join_clause  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2087 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 223: /* opt_join_type  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 2093 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 224: /* join_table  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2099 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 225: /* join_condition  */
#line 151 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2105 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 227: /* ident_commalist  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).str_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 2118 "bison_parser.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (hsql::SQLParserResult** result, yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 78 "bison_parser.y" /* yacc.c:1429  */
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
	yylloc.total_column = 0;
	yylloc.placeholder_id = 0;
}

#line 2237 "bison_parser.cpp" /* yacc.c:1429  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 245 "bison_parser.y" /* yacc.c:1646  */
    {
			*result = (yyvsp[-1].stmt_list);
		}
#line 2428 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 252 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = new SQLParserResult((yyvsp[0].statement)); }
#line 2434 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 253 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].stmt_list)->addStatement((yyvsp[0].statement)); (yyval.stmt_list) = (yyvsp[-2].stmt_list); }
#line 2440 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 257 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyvsp[0].prep_stmt)->setPlaceholders(yyloc.placeholder_list);
			yyloc.placeholder_list.clear();
			(yyval.statement) = (yyvsp[0].prep_stmt);
		}
#line 2450 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 267 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 2456 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 268 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].import_stmt); }
#line 2462 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 269 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 2468 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 270 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 2474 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 271 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 2480 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 272 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 2486 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 273 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 2492 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 274 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 2498 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 275 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 2504 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 283 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.prep_stmt) = new PrepareStatement();
			(yyval.prep_stmt)->name = (yyvsp[-2].sval);
			(yyval.prep_stmt)->query = new SQLParserResult((yyvsp[0].statement));
		}
#line 2514 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 288 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.prep_stmt) = new PrepareStatement();
			(yyval.prep_stmt)->name = (yyvsp[-4].sval);
			(yyval.prep_stmt)->query = (yyvsp[-2].stmt_list);
		}
#line 2524 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 296 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[0].sval);
		}
#line 2533 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 300 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[-3].sval);
			(yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
		}
#line 2543 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 312 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.import_stmt) = new ImportStatement((ImportStatement::ImportType) (yyvsp[-4].uval));
			(yyval.import_stmt)->filePath = (yyvsp[-2].sval);
			(yyval.import_stmt)->tableName = (yyvsp[0].sval);
		}
#line 2553 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 320 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = ImportStatement::kImportCSV; }
#line 2559 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 324 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = strdup((yyvsp[0].expr)->name); delete (yyvsp[0].expr); }
#line 2565 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 334 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt) = new CreateStatement(CreateStatement::kTableFromTbl);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-5].bval);
			(yyval.create_stmt)->tableName = (yyvsp[-4].sval);
			(yyval.create_stmt)->filePath = (yyvsp[0].sval);
		}
#line 2576 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 340 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt) = new CreateStatement(CreateStatement::kTable);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
			(yyval.create_stmt)->tableName = (yyvsp[-3].sval);
			(yyval.create_stmt)->columns = (yyvsp[-1].column_vec);
		}
#line 2587 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 346 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt) = new CreateStatement(CreateStatement::kView);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
			(yyval.create_stmt)->tableName = (yyvsp[-3].sval);
			(yyval.create_stmt)->viewColumns = (yyvsp[-2].str_vec);
			(yyval.create_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 2599 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 356 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 2605 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 357 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 2611 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 361 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_vec) = new std::vector<ColumnDefinition*>(); (yyval.column_vec)->push_back((yyvsp[0].column_t)); }
#line 2617 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 362 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].column_vec)->push_back((yyvsp[0].column_t)); (yyval.column_vec) = (yyvsp[-2].column_vec); }
#line 2623 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 366 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.column_t) = new ColumnDefinition((yyvsp[-1].sval), (ColumnDefinition::DataType) (yyvsp[0].uval));
		}
#line 2631 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 369 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.column_t) = new ColumnDefinition((yyvsp[-4].sval), (ColumnDefinition::DataType) (yyvsp[-3].uval), (yyvsp[-1].ival));
		}
#line 2639 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 376 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = ColumnDefinition::INT; }
#line 2645 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 377 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = ColumnDefinition::INT; }
#line 2651 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 378 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = ColumnDefinition::DOUBLE; }
#line 2657 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 379 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = ColumnDefinition::TEXT; }
#line 2663 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 389 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.drop_stmt) = new DropStatement(DropStatement::kTable);
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 2672 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 393 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.drop_stmt) = new DropStatement(DropStatement::kView);
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 2681 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 397 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.drop_stmt) = new DropStatement(DropStatement::kPreparedStatement);
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 2690 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 409 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->tableName = (yyvsp[-1].sval);
			(yyval.delete_stmt)->expr = (yyvsp[0].expr);
		}
#line 2700 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 417 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->tableName = (yyvsp[0].sval);
		}
#line 2709 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 429 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.insert_stmt) = new InsertStatement(InsertStatement::kInsertValues);
			(yyval.insert_stmt)->tableName = (yyvsp[-5].sval);
			(yyval.insert_stmt)->columns = (yyvsp[-4].str_vec);
			(yyval.insert_stmt)->values = (yyvsp[-1].expr_vec);
		}
#line 2720 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 435 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.insert_stmt) = new InsertStatement(InsertStatement::kInsertSelect);
			(yyval.insert_stmt)->tableName = (yyvsp[-2].sval);
			(yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
			(yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 2731 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 445 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 2737 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 446 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.str_vec) = NULL; }
#line 2743 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 456 "bison_parser.y" /* yacc.c:1646  */
    {
		(yyval.update_stmt) = new UpdateStatement();
		(yyval.update_stmt)->table = (yyvsp[-3].table);
		(yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
		(yyval.update_stmt)->where = (yyvsp[0].expr);
	}
#line 2754 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 465 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.update_vec) = new std::vector<UpdateClause*>(); (yyval.update_vec)->push_back((yyvsp[0].update_t)); }
#line 2760 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 466 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t)); (yyval.update_vec) = (yyvsp[-2].update_vec); }
#line 2766 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 470 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.update_t) = new UpdateClause();
			(yyval.update_t)->column = (yyvsp[-2].sval);
			(yyval.update_t)->value = (yyvsp[0].expr);
		}
#line 2776 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 487 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 2782 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 488 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 2788 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 492 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.select_stmt) = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != NULL) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 2803 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 502 "bison_parser.y" /* yacc.c:1646  */
    {
			// TODO: allow multiple unions (through linked list)
			// TODO: capture type of set_operator
			// TODO: might overwrite order and limit of first select here
			(yyval.select_stmt) = (yyvsp[-4].select_stmt);
			(yyval.select_stmt)->unionSelect = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != NULL) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 2822 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 516 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.select_stmt) = (yyvsp[-4].select_stmt);
			(yyval.select_stmt)->unionSelect = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != NULL) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 2838 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 536 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.select_stmt) = new SelectStatement();
			(yyval.select_stmt)->limit = (yyvsp[-5].limit);
			(yyval.select_stmt)->selectDistinct = (yyvsp[-4].bval);
			(yyval.select_stmt)->selectList = (yyvsp[-3].expr_vec);
			(yyval.select_stmt)->fromTable = (yyvsp[-2].table);
			(yyval.select_stmt)->whereClause = (yyvsp[-1].expr);
			(yyval.select_stmt)->groupBy = (yyvsp[0].group_t);
		}
#line 2852 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 548 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 2858 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 549 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 2864 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 557 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table) = (yyvsp[0].table); }
#line 2870 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 562 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2876 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 563 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = NULL; }
#line 2882 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 567 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.group_t) = new GroupByDescription();
			(yyval.group_t)->columns = (yyvsp[-1].expr_vec);
			(yyval.group_t)->having = (yyvsp[0].expr);
		}
#line 2892 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 572 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.group_t) = NULL; }
#line 2898 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 576 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2904 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 577 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = NULL; }
#line 2910 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 580 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_vec) = (yyvsp[0].order_vec); }
#line 2916 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 581 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_vec) = NULL; }
#line 2922 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 585 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_vec) = new std::vector<OrderDescription*>(); (yyval.order_vec)->push_back((yyvsp[0].order)); }
#line 2928 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 586 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].order_vec)->push_back((yyvsp[0].order)); (yyval.order_vec) = (yyvsp[-2].order_vec); }
#line 2934 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 590 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 2940 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 594 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_type) = kOrderAsc; }
#line 2946 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 595 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_type) = kOrderDesc; }
#line 2952 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 596 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_type) = kOrderAsc; }
#line 2958 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 602 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription((yyvsp[0].expr)->ival, kNoOffset); delete (yyvsp[0].expr); }
#line 2964 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 603 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = NULL; }
#line 2970 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 607 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription((yyvsp[0].expr)->ival, kNoOffset); delete (yyvsp[0].expr); }
#line 2976 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 608 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription((yyvsp[-2].expr)->ival, (yyvsp[0].expr)->ival); delete (yyvsp[-2].expr); delete (yyvsp[0].expr); }
#line 2982 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 609 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = NULL; }
#line 2988 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 616 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 2994 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 617 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 3000 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 621 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 3006 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 622 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 3012 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 626 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = (yyvsp[-1].expr);
			(yyval.expr)->alias = (yyvsp[0].sval);
		}
#line 3021 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 642 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 3027 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 647 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeSelect((yyvsp[-1].select_stmt)); }
#line 3033 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 657 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(Expr::UMINUS, (yyvsp[0].expr)); }
#line 3039 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 658 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(Expr::NOT, (yyvsp[0].expr)); }
#line 3045 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 663 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '-', (yyvsp[0].expr)); }
#line 3051 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 664 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '+', (yyvsp[0].expr)); }
#line 3057 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 665 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '/', (yyvsp[0].expr)); }
#line 3063 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 666 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '*', (yyvsp[0].expr)); }
#line 3069 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 667 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '%', (yyvsp[0].expr)); }
#line 3075 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 668 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '^', (yyvsp[0].expr)); }
#line 3081 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 669 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::LIKE, (yyvsp[0].expr)); }
#line 3087 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 670 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), Expr::NOT_LIKE, (yyvsp[0].expr)); }
#line 3093 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 674 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::AND, (yyvsp[0].expr)); }
#line 3099 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 675 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::OR, (yyvsp[0].expr)); }
#line 3105 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 679 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].expr_vec)); }
#line 3111 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 680 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(Expr::NOT, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].expr_vec))); }
#line 3117 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 681 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].select_stmt)); }
#line 3123 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 682 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(Expr::NOT, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].select_stmt))); }
#line 3129 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 687 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeCase((yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 3135 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 691 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeExists((yyvsp[-1].select_stmt)); }
#line 3141 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 692 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(Expr::NOT, Expr::makeExists((yyvsp[-1].select_stmt))); }
#line 3147 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 696 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '=', (yyvsp[0].expr)); }
#line 3153 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 697 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::NOT_EQUALS, (yyvsp[0].expr)); }
#line 3159 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 698 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '<', (yyvsp[0].expr)); }
#line 3165 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 699 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '>', (yyvsp[0].expr)); }
#line 3171 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 700 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::LESS_EQ, (yyvsp[0].expr)); }
#line 3177 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 701 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::GREATER_EQ, (yyvsp[0].expr)); }
#line 3183 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 705 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr_vec), (yyvsp[-2].bval)); }
#line 3189 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 709 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeBetween((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3195 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 713 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 3201 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 714 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 3207 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 724 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 3213 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 729 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 3219 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 734 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 3225 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 738 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Expr(kExprStar); }
#line 3231 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 742 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = Expr::makePlaceholder(yylloc.total_column);
			yyloc.placeholder_list.push_back((yyval.expr));
		}
#line 3240 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 754 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyvsp[0].table_vec)->push_back((yyvsp[-2].table));
			auto tbl = new TableRef(kTableCrossProduct);
			tbl->list = (yyvsp[0].table_vec);
			(yyval.table) = tbl;
		}
#line 3251 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 765 "bison_parser.y" /* yacc.c:1646  */
    {
			auto tbl = new TableRef(kTableSelect);
			tbl->select = (yyvsp[-2].select_stmt);
			tbl->alias = (yyvsp[0].sval);
			(yyval.table) = tbl;
		}
#line 3262 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 776 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table_vec) = new std::vector<TableRef*>(); (yyval.table_vec)->push_back((yyvsp[0].table)); }
#line 3268 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 777 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].table_vec)->push_back((yyvsp[0].table)); (yyval.table_vec) = (yyvsp[-2].table_vec); }
#line 3274 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 782 "bison_parser.y" /* yacc.c:1646  */
    {
			auto tbl = new TableRef(kTableName);
			tbl->name = (yyvsp[-1].sval);
			tbl->alias = (yyvsp[0].sval);
			(yyval.table) = tbl;
		}
#line 3285 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 792 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.table) = new TableRef(kTableName);
			(yyval.table)->name = (yyvsp[0].sval);
		}
#line 3294 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 806 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 3300 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 812 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 3306 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 821 "bison_parser.y" /* yacc.c:1646  */
    { 
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = (JoinType) (yyvsp[-4].uval);
			(yyval.table)->join->left = (yyvsp[-5].table);
			(yyval.table)->join->right = (yyvsp[-2].table);
			(yyval.table)->join->condition = (yyvsp[0].expr);
		}
#line 3319 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 832 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinInner; }
#line 3325 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 833 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinOuter; }
#line 3331 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 834 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinLeftOuter; }
#line 3337 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 835 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinRightOuter; }
#line 3343 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 836 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinLeft; }
#line 3349 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 837 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinRight; }
#line 3355 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 838 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinCross; }
#line 3361 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 839 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinNatural; }
#line 3367 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 840 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinInner; }
#line 3373 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 846 "bison_parser.y" /* yacc.c:1646  */
    {
			auto tbl = new TableRef(kTableSelect);
			tbl->select = (yyvsp[-2].select_stmt);
			tbl->alias = (yyvsp[0].sval);
			(yyval.table) = tbl;
		}
#line 3384 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 871 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.str_vec) = new std::vector<char*>(); (yyval.str_vec)->push_back((yyvsp[0].sval)); }
#line 3390 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 872 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval)); (yyval.str_vec) = (yyvsp[-2].str_vec); }
#line 3396 "bison_parser.cpp" /* yacc.c:1646  */
    break;


#line 3400 "bison_parser.cpp" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, result, scanner, YY_("syntax error"));
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
        yyerror (&yylloc, result, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, result, scanner);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, result, scanner);
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
#line 875 "bison_parser.y" /* yacc.c:1906  */

/*********************************
 ** Section 4: Additional C code
 *********************************/

/* empty */

