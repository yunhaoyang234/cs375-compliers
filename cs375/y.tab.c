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
#line 1 "parse.y" /* yacc.c:339  */
     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "pprint.h"
#include "codegen.h"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;


#line 130 "y.tab.c" /* yacc.c:339  */

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
    IDENTIFIER = 258,
    STRING = 259,
    NUMBER = 260,
    PLUS = 261,
    MINUS = 262,
    TIMES = 263,
    DIVIDE = 264,
    ASSIGN = 265,
    EQ = 266,
    NE = 267,
    LT = 268,
    LE = 269,
    GE = 270,
    GT = 271,
    POINT = 272,
    DOT = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    DIV = 277,
    MOD = 278,
    IN = 279,
    COMMA = 280,
    SEMICOLON = 281,
    COLON = 282,
    LPAREN = 283,
    RPAREN = 284,
    LBRACKET = 285,
    RBRACKET = 286,
    DOTDOT = 287,
    ARRAY = 288,
    BEGINBEGIN = 289,
    CASE = 290,
    CONST = 291,
    DO = 292,
    DOWNTO = 293,
    ELSE = 294,
    END = 295,
    FILEFILE = 296,
    FOR = 297,
    FUNCTION = 298,
    GOTO = 299,
    IF = 300,
    LABEL = 301,
    NIL = 302,
    OF = 303,
    PACKED = 304,
    PROCEDURE = 305,
    PROGRAM = 306,
    RECORD = 307,
    REPEAT = 308,
    SET = 309,
    THEN = 310,
    TO = 311,
    TYPE = 312,
    UNTIL = 313,
    VAR = 314,
    WHILE = 315,
    WITH = 316
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define PLUS 261
#define MINUS 262
#define TIMES 263
#define DIVIDE 264
#define ASSIGN 265
#define EQ 266
#define NE 267
#define LT 268
#define LE 269
#define GE 270
#define GT 271
#define POINT 272
#define DOT 273
#define AND 274
#define OR 275
#define NOT 276
#define DIV 277
#define MOD 278
#define IN 279
#define COMMA 280
#define SEMICOLON 281
#define COLON 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define DOTDOT 287
#define ARRAY 288
#define BEGINBEGIN 289
#define CASE 290
#define CONST 291
#define DO 292
#define DOWNTO 293
#define ELSE 294
#define END 295
#define FILEFILE 296
#define FOR 297
#define FUNCTION 298
#define GOTO 299
#define IF 300
#define LABEL 301
#define NIL 302
#define OF 303
#define PACKED 304
#define PROCEDURE 305
#define PROGRAM 306
#define RECORD 307
#define REPEAT 308
#define SET 309
#define THEN 310
#define TO 311
#define TYPE 312
#define UNTIL 313
#define VAR 314
#define WHILE 315
#define WITH 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 300 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   258

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    83,    83,    85,    86,    88,    90,    91,    93,    94,
      95,    96,    97,    98,   102,   104,   105,   107,   108,   110,
     112,   113,   115,   116,   118,   120,   121,   123,   124,   126,
     128,   129,   131,   132,   134,   135,   136,   138,   139,   141,
     142,   143,   144,   146,   147,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   159,   161,   163,   164,   166,   168,
     169,   171,   172,   173,   174,   176,   177,   178,   180,   181,
     182,   183,   184,   186,   187,   188,   189,   190,   191,   192,
     194,   195,   197,   198,   200,   201,   203,   204,   205,   207,
     208,   210,   211,   212,   213,   214
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "NUMBER", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "ASSIGN", "EQ", "NE", "LT", "LE", "GE", "GT",
  "POINT", "DOT", "AND", "OR", "NOT", "DIV", "MOD", "IN", "COMMA",
  "SEMICOLON", "COLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "DOTDOT", "ARRAY", "BEGINBEGIN", "CASE", "CONST", "DO", "DOWNTO", "ELSE",
  "END", "FILEFILE", "FOR", "FUNCTION", "GOTO", "IF", "LABEL", "NIL", "OF",
  "PACKED", "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "SET", "THEN",
  "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "$accept", "program",
  "id_list", "block", "sign", "constant", "vdef", "vdef_list", "vblock",
  "tdef", "tdef_list", "tblock", "cdef", "cdef_list", "cblock", "label",
  "numlist", "lblock", "simpletype", "simple_type_list", "type",
  "statement_list", "statement", "assignment", "funcall", "expr_list",
  "fields", "field_list", "variable", "plus_op", "times_op", "compare_op",
  "endpart", "endif", "term", "simple_expression", "expression", "factor", YY_NULLPTR
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
     315,   316
};
# endif

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -62

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -35,    28,    43,    22,  -123,    49,    32,    57,    49,    46,
    -123,    33,    20,    85,    86,    90,    49,  -123,  -123,  -123,
    -123,    78,    73,    75,    20,   100,   103,   129,    20,   129,
    -123,   -14,  -123,  -123,    67,   102,    93,   -23,    95,    96,
     116,   104,   -24,   110,   112,   120,  -123,   129,    20,   -14,
    -123,    97,  -123,    23,  -123,  -123,  -123,  -123,   129,   129,
    -123,   137,  -123,  -123,   134,   196,   119,   158,  -123,   101,
     140,   179,    20,  -123,  -123,   129,  -123,   164,   129,   142,
      85,  -123,    86,    47,    42,    90,  -123,    42,    49,  -123,
     146,   218,  -123,  -123,   129,    16,  -123,   212,    23,  -123,
     196,  -123,  -123,  -123,  -123,  -123,   129,  -123,  -123,  -123,
     129,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    20,   129,
     129,    20,    20,   -14,   233,  -123,   152,  -123,  -123,  -123,
    -123,  -123,   153,   183,    49,   157,    49,   156,  -123,  -123,
    -123,  -123,  -123,  -123,   129,   185,  -123,  -123,  -123,  -123,
     196,   167,   119,   233,  -123,  -123,  -123,  -123,  -123,   178,
     174,   181,   184,   171,   142,  -123,    20,    20,  -123,  -123,
     187,   186,    42,    49,  -123,  -123,  -123,  -123,   174,   166,
    -123,  -123,  -123,    42,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     4,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,    18,    23,    28,
      33,     0,    61,     0,     0,     0,     0,     0,     0,     0,
      53,     0,    47,    48,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
      61,     0,    52,     8,    12,    10,     6,     7,     0,     0,
      13,     0,    91,    93,    92,    87,    90,     0,    85,     0,
      44,     0,     0,    81,     5,     0,    64,     0,     0,     0,
      26,    27,     0,     0,     0,    21,    22,     0,    16,    17,
       0,    57,    29,    45,     0,     0,    95,     0,     8,    10,
      86,    68,    69,    72,    70,    71,     0,    65,    66,    67,
       0,    73,    76,    74,    77,    78,    75,    79,     0,     0,
       0,     0,     0,     0,    54,    63,     0,     8,    24,    25,
      30,    32,    34,     0,     0,     0,     0,     0,    39,    19,
      20,    14,    15,    55,     0,     0,     9,    11,    94,    84,
      88,    83,    89,    49,    43,    51,    80,    62,    42,     0,
       0,     0,    60,     0,     0,    56,     0,     0,    46,    35,
      38,     0,     0,     0,    41,    36,    50,    82,     0,     0,
      58,    59,    37,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,    -5,   175,   -20,   -55,  -123,   147,   195,  -123,
     154,   201,  -123,   160,   168,  -123,   170,  -123,  -122,    72,
     -85,   132,    -4,   229,    -6,   -73,  -123,    82,   -11,  -123,
    -123,  -123,   -45,  -123,   -28,   139,     1,   -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    43,    17,    95,    62,    44,    45,    18,    41,
      42,    19,    36,    37,    20,    30,    39,    21,   138,   171,
     139,    69,    70,    32,    63,    90,   162,   163,    64,   110,
     106,   119,    74,   168,    65,    66,    91,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,    34,   141,    10,    93,   126,    33,    61,    31,    61,
      12,    12,    72,    34,    34,    96,     1,    34,    33,   146,
      49,   147,    33,    22,   128,    23,    73,    61,    67,   137,
      71,     3,   137,   100,    15,    16,    16,    34,   170,    61,
     -61,   -61,    33,     4,    92,   132,    54,    55,    56,    57,
       5,    47,     6,   -61,    24,    61,   170,     8,    61,   133,
      97,    34,    25,   149,    26,    27,    33,    12,   123,    13,
     134,   165,    11,    28,    61,   135,   124,    75,   156,    14,
      29,    12,   150,    13,    76,    77,     9,   180,    35,    60,
      15,    38,    16,    40,   136,   145,    46,    78,   184,    61,
      61,    47,    48,    50,    15,   137,    16,    34,    52,   175,
      34,    34,    33,    79,   151,    33,    33,   137,   155,    80,
      82,   153,    83,   137,    61,   107,   108,    84,   137,   159,
      85,   161,    53,    54,    55,    56,    57,    87,    88,   109,
      98,    54,    99,    56,    57,   127,    54,    55,    56,    57,
      58,    76,    77,    94,    12,    34,    34,    59,    58,   120,
      33,    33,   176,   177,    78,    59,   121,   125,   161,   111,
     112,   113,   114,   115,   116,   143,    60,   132,    54,    55,
      56,    57,   117,   157,    60,    -8,   158,   160,   164,    60,
     111,   112,   113,   114,   115,   116,   111,   112,   113,   114,
     115,   116,   134,   117,   101,   102,   167,   169,   172,   117,
     173,   174,   178,   118,   183,   103,   122,   179,   104,   105,
      89,    60,   166,   111,   112,   113,   114,   115,   116,   111,
     112,   113,   114,   115,   116,   142,   117,    86,    81,   140,
     129,   148,   117,   144,   111,   112,   113,   114,   115,   116,
     182,   131,   130,   154,    51,   181,     0,   117,   152
};

static const yytype_int16 yycheck[] =
{
       5,    12,    87,     8,    49,    78,    12,    27,    12,    29,
      34,    34,    26,    24,    25,    58,    51,    28,    24,     3,
      24,     5,    28,     3,    79,     5,    40,    47,    27,    84,
      29,     3,    87,    61,    57,    59,    59,    48,   160,    59,
      17,    18,    48,     0,    48,     3,     4,     5,     6,     7,
      28,    28,     3,    30,    34,    75,   178,    25,    78,    17,
      59,    72,    42,   106,    44,    45,    72,    34,    72,    36,
      28,   144,    26,    53,    94,    33,    75,    10,   123,    46,
      60,    34,   110,    36,    17,    18,    29,   172,     3,    47,
      57,     5,    59,     3,    52,    94,    18,    30,   183,   119,
     120,    28,    27,     3,    57,   160,    59,   118,     5,   164,
     121,   122,   118,    11,   118,   121,   122,   172,   122,    26,
      25,   120,    26,   178,   144,     6,     7,    11,   183,   134,
      26,   136,     3,     4,     5,     6,     7,    27,    26,    20,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
      21,    17,    18,    56,    34,   166,   167,    28,    21,    58,
     166,   167,   166,   167,    30,    28,    26,     3,   173,    11,
      12,    13,    14,    15,    16,    29,    47,     3,     4,     5,
       6,     7,    24,    31,    47,    32,     3,    30,    32,    47,
      11,    12,    13,    14,    15,    16,    11,    12,    13,    14,
      15,    16,    28,    24,     8,     9,    39,    29,    27,    24,
      26,    40,    25,    55,    48,    19,    37,    31,    22,    23,
      45,    47,    37,    11,    12,    13,    14,    15,    16,    11,
      12,    13,    14,    15,    16,    88,    24,    42,    37,    85,
      80,    29,    24,    25,    11,    12,    13,    14,    15,    16,
     178,    83,    82,   121,    25,   173,    -1,    24,   119
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,     3,     0,    28,     3,    64,    25,    29,
      64,    26,    34,    36,    46,    57,    59,    65,    70,    73,
      76,    79,     3,     5,    34,    42,    44,    45,    53,    60,
      77,    84,    85,    86,    90,     3,    74,    75,     5,    78,
       3,    71,    72,    64,    68,    69,    18,    28,    27,    84,
       3,    85,     5,     3,     4,     5,     6,     7,    21,    28,
      47,    66,    67,    86,    90,    96,    97,    98,    99,    83,
      84,    98,    26,    40,    94,    10,    17,    18,    30,    11,
      26,    73,    25,    26,    11,    26,    70,    27,    26,    65,
      87,    98,    84,    94,    56,    66,    99,    98,     3,     5,
      96,     8,     9,    19,    22,    23,    92,     6,     7,    20,
      91,    11,    12,    13,    14,    15,    16,    24,    55,    93,
      58,    26,    37,    84,    98,     3,    87,     3,    67,    75,
      78,    76,     3,    17,    28,    33,    52,    67,    80,    82,
      72,    82,    69,    29,    25,    98,     3,     5,    29,    99,
      96,    84,    97,    98,    83,    84,    94,    31,     3,    64,
      30,    64,    88,    89,    32,    87,    37,    39,    95,    29,
      80,    81,    27,    26,    40,    67,    84,    84,    25,    31,
      82,    89,    81,    48,    82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    66,    66,    67,    67,
      67,    67,    67,    67,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    75,    75,    76,    76,    77,
      78,    78,    79,    79,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    85,    86,    87,    87,    88,    89,
      89,    90,    90,    90,    90,    91,    91,    91,    92,    92,
      92,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    98,
      98,    99,    99,    99,    99,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     3,     1,     3,     1,     1,     1,     2,
       1,     2,     1,     1,     3,     3,     2,     3,     1,     3,
       3,     2,     3,     1,     3,     3,     2,     3,     1,     3,
       3,     1,     4,     1,     1,     3,     3,     3,     1,     1,
       6,     3,     2,     3,     1,     3,     5,     1,     1,     4,
       6,     4,     2,     1,     3,     4,     3,     1,     3,     3,
       1,     1,     4,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     0,     3,     1,     2,     1,     3,     3,
       1,     1,     1,     1,     3,     2
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
#line 83 "parse.y" /* yacc.c:1646  */
    { parseresult = makeprogram((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1])); }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 88 "parse.y" /* yacc.c:1646  */
    { (yyval) = makepnb((yyvsp[-2]),cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 93 "parse.y" /* yacc.c:1646  */
    { (yyval) = findid((yyvsp[0])); }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 94 "parse.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 96 "parse.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 98 "parse.y" /* yacc.c:1646  */
    { TOKEN tok = makeintc(0);
                                                 tok->basicdt = POINTER;
                                                 (yyval) = tok; }
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 102 "parse.y" /* yacc.c:1646  */
    { instvars((yyvsp[-2]), (yyvsp[0])); }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 107 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 110 "parse.y" /* yacc.c:1646  */
    { insttype((yyvsp[-2]), (yyvsp[0])); }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 115 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 118 "parse.y" /* yacc.c:1646  */
    { instconst((yyvsp[-2]), (yyvsp[0])); }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 123 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 126 "parse.y" /* yacc.c:1646  */
    { (yyval) = dolabel((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 128 "parse.y" /* yacc.c:1646  */
    { instlabel((yyvsp[-2])); }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 129 "parse.y" /* yacc.c:1646  */
    { instlabel((yyvsp[0])); }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 131 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 134 "parse.y" /* yacc.c:1646  */
    { (yyval) = findtype((yyvsp[0])); }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 135 "parse.y" /* yacc.c:1646  */
    { (yyval) = instenum((yyvsp[-1])); }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 136 "parse.y" /* yacc.c:1646  */
    { (yyval) = instdotdot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 138 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 139 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), NULL); }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 141 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 142 "parse.y" /* yacc.c:1646  */
    { (yyval) = instarray((yyvsp[-3]), (yyvsp[0])); }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 143 "parse.y" /* yacc.c:1646  */
    { (yyval) = instrec((yyvsp[-2]), (yyvsp[-1])); }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 144 "parse.y" /* yacc.c:1646  */
    { (yyval) = instpoint((yyvsp[-1]), (yyvsp[0])); }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 146 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 147 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), NULL); }
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 149 "parse.y" /* yacc.c:1646  */
    { (yyval) = makepnb((yyvsp[-2]),cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 150 "parse.y" /* yacc.c:1646  */
    { (yyval) = makeif((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0])); }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 153 "parse.y" /* yacc.c:1646  */
    { (yyval) = makerepeat((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 154 "parse.y" /* yacc.c:1646  */
    { (yyval) = makefor(1, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 155 "parse.y" /* yacc.c:1646  */
    { (yyval) = makewhile((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 156 "parse.y" /* yacc.c:1646  */
    { (yyval) = dogoto((yyvsp[-1]), (yyvsp[0])); }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 159 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 161 "parse.y" /* yacc.c:1646  */
    { (yyval) = makefuncall((yyvsp[-2]), (yyvsp[-3]), (yyvsp[-1])); }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 163 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 166 "parse.y" /* yacc.c:1646  */
    { (yyval) = instfields((yyvsp[-2]), (yyvsp[0])); }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 168 "parse.y" /* yacc.c:1646  */
    { (yyval) = nconc((yyvsp[-2]), (yyvsp[0])); }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 171 "parse.y" /* yacc.c:1646  */
    { (yyval) = findid((yyvsp[0])); }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 172 "parse.y" /* yacc.c:1646  */
    { (yyval) = arrayref((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 173 "parse.y" /* yacc.c:1646  */
    { (yyval) = reducedot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 174 "parse.y" /* yacc.c:1646  */
    { (yyval) = dopoint((yyvsp[-1]), (yyvsp[0])); }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 194 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-1]), (yyvsp[0])); }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 195 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 197 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 198 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 200 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 203 "parse.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 205 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 207 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 213 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 214 "parse.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1844 "y.tab.c" /* yacc.c:1646  */
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
#line 216 "parse.y" /* yacc.c:1906  */


/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG        0              /* set bits here for debugging, 0 = off  */
#define DB_CONS       1             /* bit to trace cons */
#define DB_BINOP      2             /* bit to trace binop */
#define DB_MAKEIF     4             /* bit to trace makeif */
#define DB_MAKEPROGN  8             /* bit to trace makeprogn */
#define DB_PARSERES  16             /* bit to trace parseresult */

 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int label_list[100];

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */
    op->basicdt = lhs->basicdt == 9999 ? rhs->basicdt : lhs->basicdt;
    TOKEN op_tok;
    /*======================start of second part=======================*/
    if (lhs->basicdt == REAL && rhs->basicdt == REAL) {
        op->basicdt = REAL;
    }else if(lhs->basicdt == REAL && rhs->basicdt == INTEGER){
        op->basicdt = REAL;
        op_tok = makefloat(rhs);
        lhs->link = op_tok;
    }else if(lhs->basicdt == INTEGER && rhs->basicdt == REAL){
        if(op->whichval == ASSIGNOP){
            op->basicdt = INTEGER;
            op_tok = makefix(rhs);
            lhs->link = op_tok;
        }else{
            op->basicdt = REAL;
            op_tok = makefloat(lhs);
            op_tok->link = rhs;
        }
    }else if(lhs->basicdt == INTEGER && rhs->basicdt == INTEGER){
        op->basicdt = INTEGER;
    }
    /*======================end of second part=======================*/
    if (DEBUG & DB_BINOP)
       { printf("binop\n");
         dbugprinttok(op);
         dbugprinttok(lhs);
         dbugprinttok(rhs);
       };
    return op;
  }

/*======================start of first part=======================*/
TOKEN maketok(int type, int val, TOKEN opd){
    TOKEN tok = talloc();
    tok->tokentype = type;
    tok->whichval = val;
    tok->operands = opd;
    if(DEBUG){
        printf("maketok\n");
        dbugprinttok(opd);
        dbugprinttok(tok);
    }
    return tok;
}


TOKEN copytok(TOKEN tok){
    TOKEN newtok = talloc();
    newtok->tokentype = tok->tokentype;
    newtok->whichval = tok->whichval;
    newtok->operands = tok->operands;
    newtok->link = tok->link;
    newtok->intval = tok->intval;
    newtok->realval = tok->realval;
    newtok->symtype = tok->symtype;
    newtok->symentry = tok->symentry;
    if(tok->stringval[0]!='\0')
        strncpy(newtok->stringval, tok->stringval, 16);
    if(DEBUG){
        printf("copytok\n");
    }
    return newtok;
}

TOKEN makeop(int opnum){
    return maketok(OPERATOR, opnum, NULL);
}
/*======================end of first part=======================*/

TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }

/*===================================================================
========================start of first part==========================
===================================================================*/
TOKEN makeintc(int num){
    TOKEN tok = maketok(NUMBERTOK, INTEGER, NULL);
    tok->intval = num;
    tok->basicdt = INTEGER;
    if (DEBUG) {
        printf("makeintc\n");
        dbugprinttok(tok);
    }
    return tok;
}

TOKEN makelabel(){
    TOKEN tok, inttok;
    inttok = makeintc(labelnumber);
    tok = maketok(OPERATOR, LABELOP, inttok);
    labelnumber++;
    return tok;
}

TOKEN makegoto(int label){
    if(label<0) printf("invalid makegoto");
    TOKEN tok = maketok(OPERATOR, GOTOOP, makeintc(label));
    if (DEBUG) {
        printf("makegoto\n");
        dbugprinttok(tok);
    }
    return tok;
}

TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr,
              TOKEN tokc, TOKEN statement)
{
    TOKEN label_tok, if_tok, op_tok, trace_tok, trace_tok1, trace_tok2, trace_tok3,
        asg_tok, op_tok2, goto_tok, do_tok;
    tok = makepnb(tok, asg);
    label_tok = makelabel();
    asg->link = label_tok;

    if(sign == 1)
        op_tok = makeop(LEOP);
    else
        op_tok = makeop(GEOP);
    trace_tok1 = copytok(asg->operands);
    trace_tok1->link = endexpr;
    op_tok->operands = trace_tok1;

    do_tok = talloc();
    do_tok = makepnb(do_tok, statement);

    if_tok = talloc();
    if_tok = makeif(if_tok, op_tok, do_tok, NULL);
    label_tok->link = if_tok;

    trace_tok2 = copytok(trace_tok1);
    trace_tok3 = copytok(trace_tok1);
    asg_tok = makeop(ASSIGNOP);
    if(sign == 1)
        op_tok2 = makeop(PLUSOP);
    else
        op_tok2 = makeop(MINUSOP);
    op_tok2 = binop(op_tok2, trace_tok3, makeintc(1));
    asg_tok = binop(asg_tok, trace_tok2, op_tok2);

    TOKEN statement_tok = statement;

    if(statement->whichval == PROGNOP)
        statement_tok = statement->operands;

    while(statement_tok->link != NULL){
        statement_tok = statement_tok->link;
    }
    statement_tok->link = asg_tok;

    goto_tok = makegoto(label_tok->operands->intval);
    asg_tok->link = goto_tok;

    return tok;
}

TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args)
{
    if(!strcmp(fn->stringval, "new")){
        tok = makeop(ASSIGNOP);
        TOKEN function = maketok(OPERATOR, FUNCALLOP, fn);
        SYMBOL typesym = args->symtype->datatype;
        
        tok->operands = args;
        args->link = function;
        while(typesym->kind == POINTERSYM){
            typesym = typesym->datatype;
        }
        fn->link = makeintc(typesym->size);
        if(DEBUG){
            printf("makefuncall new\n");
            dbugprinttok(fn);
            dbugprinttok(args);
            dbugprinttok(function);
        }
        return tok;
    }else if(!strcmp(fn->stringval, "write") || !strcmp(fn->stringval, "writeln")){
        if(args->basicdt == INTEGER && !strcmp(fn->stringval, "write")){
            strcpy(fn->stringval, "writei");
        }else if(args->basicdt == INTEGER && !strcmp(fn->stringval, "writeln")){
            strcpy(fn->stringval, "writelni");
        }else if(args->basicdt == REAL && !strcmp(fn->stringval, "write")){
            strcpy(fn->stringval, "writef");
        }else if(args->basicdt == REAL && !strcmp(fn->stringval, "writeln")){
            strcpy(fn->stringval, "writelnf");
        }
    }
    tok->tokentype = OPERATOR;
    tok->whichval = FUNCALLOP;
    tok->operands = fn;
    fn->link = args;
    tok->basicdt = args->basicdt;

    if(!strcmp(fn->stringval, "iround"))
        tok->basicdt = INTEGER;
    
    if(DEBUG){
        printf("makefuncall\n");
        dbugprinttok(fn);
        dbugprinttok(args);
    }
    return tok;
}

TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements)
{
    TOKEN tok, argtok;
    tok = maketok(OPERATOR, PROGRAMOP, name);
    argtok = talloc();
    argtok = makepnb(argtok, args);
    name->link = argtok;
    argtok->link = statements;
    if(DEBUG){
        printf("makeprogram\n");
        dbugprinttok(name);
        dbugprinttok(args);
        dbugprinttok(statements);
    }
    return tok;
}

TOKEN findtype(TOKEN tok){
    SYMBOL sym;
    sym = searchst(tok->stringval);
    tok->symtype = sym;
    if(DEBUG){
        printf("findtype\n");
        dbugprinttok(tok);
        dbugbprinttok(tok);
    }
    return tok;
}

TOKEN findid(TOKEN tok) {
    /* the ID token */
    SYMBOL sym, typ;

    sym = searchst(tok->stringval);

    if(sym->kind == CONSTSYM){
        tok->tokentype = NUMBERTOK;
        if(sym->basicdt == INTEGER){
            tok->basicdt = INTEGER;
            tok->intval = sym->constval.intnum;
        }
        if(sym->basicdt == REAL){
            tok->basicdt = REAL;
            tok->realval = sym->constval.realnum;
        }
        if(DEBUG){
            printf("find id\n");
            dbugprinttok(tok);
        }
        return tok;
    }
    tok->symentry = sym;
    typ = sym->datatype;
    tok->symtype = typ;

    if ( typ->kind == BASICTYPE || typ->kind == POINTERSYM)
        tok->basicdt = typ->basicdt;
    if(DEBUG){
        printf("findid\n");
        dbugprinttok(tok);
    }
    return tok;
}

/* install variables in symbol table */
void instvars(TOKEN idlist, TOKEN typetok)
{
    SYMBOL sym, typesym;
    int align;
    if(DEBUG){
        printf("instvars\n");
        dbugprinttok(idlist);
        dbugprinttok(typetok);
    }
    typesym = typetok->symtype;

    while(typesym && typesym->kind == TYPESYM){
        typesym = typesym->datatype;
    }
    align = alignsize(typesym);
    while ( idlist != NULL ) /* for each id */
    {
        sym = insertsym(idlist->stringval);
        sym->kind = VARSYM;
        sym->offset = /* "next" */
            wordaddress(blockoffs[blocknumber], align);
        sym->size = typesym->size;
        blockoffs[blocknumber] = /* "next" */
            sym->offset + sym->size;
        sym->datatype = typesym;
        sym->basicdt = typesym->basicdt;
        //idlist->basicdt = typesym->basicdt;
        idlist = idlist->link;
    };
}

void insttype(TOKEN typename, TOKEN typetok){
    SYMBOL sym, typesym;
    typesym = typetok->symtype;
    sym = searchins(typename->stringval);
    sym->kind = TYPESYM;
    sym->size = typesym->size;
    sym->datatype = typesym;
    sym->basicdt = typesym->basicdt;
    if(DEBUG){
        printf("inst type\n");
        printsymbol(sym);
    }
}

/*===================================================================
========================end of first part==========================
===================================================================*/

/*===================================================================
========================start of second part=========================
===================================================================*/

TOKEN unaryop(TOKEN op, TOKEN lhs){
    op->operands = lhs;
    op->basicdt = lhs->basicdt;
    lhs->link = NULL;
    if(DEBUG){
        printf("unaryop\n");
        dbugprinttok(op);
        dbugprinttok(lhs);
    }
    return op;
}

void instconst(TOKEN idtok, TOKEN consttok){
    SYMBOL sym = insertsym(idtok->stringval);
    sym->kind = CONSTSYM;
    sym->basicdt = consttok->basicdt;
    
    if(sym->basicdt == INTEGER){
        sym->constval.intnum = consttok->intval;
        sym->size = sizeof(int);
    }else if(sym->basicdt == REAL){
        sym->constval.realnum = consttok->realval;
        sym->size = sizeof(double);
    }    

    if (DEBUG) {
        printf("install const\n");
	dbugprinttok(idtok);
	dbugprinttok(consttok);
	printsymbol(sym);
    }
}

TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr){
    TOKEN label_tok = makelabel();
    tok = makepnb(tok, label_tok);
    
    tokb = makepnb(tokb, statements);
    label_tok->link = tokb;
    
    TOKEN goto_tok = makegoto(label_tok->operands->intval);
    TOKEN finish_tok = maketok(OPERATOR, PROGNOP, NULL);
    finish_tok->link = goto_tok;

    TOKEN if_tok = talloc();
    if_tok = makeif(if_tok, expr, finish_tok, goto_tok);
    
    tokb->link = if_tok;

    if (DEBUG) {
         printf("make repeat\n");
         dbugprinttok(tok);
    }
    return tok; 
}

TOKEN makefix(TOKEN tok){
    TOKEN fix_op;
    if(tok->tokentype == NUMBERTOK) {
        tok->basicdt = INTEGER;
        tok->intval = (int) tok->realval;
        if (DEBUG) {
            printf("make fix num tok\n");
            dbugprinttok(tok);
            dbugprinttok(fix_op);
        }
        return tok;
    }
    fix_op = makeop(FIXOP);
    fix_op->operands = tok;
    if (DEBUG) {
         printf("make fix\n");
         dbugprinttok(tok);
         dbugprinttok(fix_op);
    }
    return fix_op;
}

TOKEN makefloat(TOKEN tok){
    TOKEN float_op;
    if(tok->tokentype == NUMBERTOK) {
        tok->basicdt = REAL;
        tok->realval = (double) tok->intval;
        if (DEBUG) {
            printf("make float num tok\n");
            dbugprinttok(tok);
            dbugprinttok(float_op);
        }
        return tok;
    }
    float_op = makeop(FLOATOP);
    float_op->operands = tok;
    if (DEBUG) {
         printf("make float\n");
         dbugprinttok(tok);
         dbugprinttok(float_op);
    }
    return float_op;
}
/*===================================================================
========================end of second part===========================
===================================================================*/

/*===================================================================
========================start of third part==========================
===================================================================*/

void  instlabel (TOKEN num){
    label_list[labelnumber] = num->intval;
    labelnumber++;
    if (DEBUG) {
        printf("instlabel\n");
        dbugprinttok(num);
        printf("%d\n", labelnumber);
    }
}

TOKEN instfields(TOKEN idlist, TOKEN typetok){
    SYMBOL sym = typetok->symtype;
    TOKEN tok = idlist;
    while(tok != NULL){
        tok->symtype = sym;
        if(sym->kind != TYPESYM){
            tok->basicdt = sym->basicdt;
        }
        tok = tok->link;
    }
    if (DEBUG) {
        printf("instfields\n");
        dbugprinttok(tok);
        dbugprinttok(typetok);
        printsymbol(sym);
        //printst();
    }
    return idlist;
}

TOKEN nconc(TOKEN lista, TOKEN listb){
    TOKEN tok = lista;
    while(tok->link){
        tok = tok->link;
    }
    tok->link = listb;
    if (DEBUG) {
        printf("nconc\n");
        dbugprinttok(tok);
        dbugprinttok(lista);
        dbugprinttok(listb);
    }
    return tok;
}

int findlabelindex(int labelnum){
    int i;
    for(i=0; i<labelnumber; i++){
        if(label_list[i] == labelnum)
            return i;
    }
    return -1;
}

TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement){
    int label_index = findlabelindex(labeltok->intval);
    if(label_index != -1){
        TOKEN numtok = makeintc(label_index);
        labeltok = maketok(OPERATOR, LABELOP, numtok);
        labeltok->link = statement;
        TOKEN ret_tok = maketok(OPERATOR, PROGNOP, labeltok);
        if (DEBUG) {
            printf("dolabel\n");
            dbugprinttok(tok);
            dbugprinttok(labeltok);
        }
        return ret_tok;
    }
    printf("can't find label\n");
    return NULL;
}

TOKEN instenum(TOKEN idlist){
    int size = 0;
    TOKEN tok = idlist;
    while(tok != NULL){
        instconst(tok, makeintc(size));
        size++;
        tok = tok->link;
    }
    TOKEN ret_tok = makesubrange(idlist, 0, size - 1);
    if (DEBUG) {
        printf("instenum\n");
        dbugprinttok(idlist);
        dbugprinttok(ret_tok);
    }
    return ret_tok;
}

TOKEN makesubrange(TOKEN tok, int low, int high){
    SYMBOL sym = symalloc();
    sym->kind = SUBRANGE;
    sym->basicdt = INTEGER;
    sym->lowbound = low;
    sym->highbound = high;
    sym->size = sizeof(int);
    
    tok->symtype = sym;
    if (DEBUG) {
        printf("making subrange\n");
        dbugprinttok(tok);
        printsymbol(sym);
    }
    return tok;
}

TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok){
    dottok = makesubrange(dottok, lowtok->intval, hightok->intval);
    if (DEBUG) {
        printf("instdotdot\n");
        dbugprinttok(dottok);
    }
    return dottok;
}

TOKEN instpoint(TOKEN tok, TOKEN typename){
    SYMBOL type_sym = searchins(typename->stringval);
    SYMBOL ptr_sym = symalloc();
    
    ptr_sym->basicdt = POINTER;
    ptr_sym->kind = POINTERSYM;
	ptr_sym->size = basicsizes[POINTER];
    ptr_sym->datatype = type_sym;
    
    tok->symtype = ptr_sym;
    if (DEBUG) {
        printf("instpoint\n");
        dbugprinttok(tok);
        printsymbol(type_sym);
        printsymbol(ptr_sym);
    }
    return tok;
}

TOKEN instarray(TOKEN bounds, TOKEN typetok){ 
    SYMBOL typesym = searchst(typetok->stringval);
    TOKEN tok = bounds;
    SYMBOL rangesym;
    TOKEN nexttok = tok->link;
    SYMBOL prevsym = NULL;

    while(tok != NULL){
        SYMBOL arrsym = symalloc();
        arrsym->kind = ARRAYSYM;
	rangesym = tok->symtype;

        while(rangesym->kind == TYPESYM){
            rangesym = rangesym->datatype;
        }

	arrsym->lowbound = rangesym->lowbound;
        arrsym->highbound = rangesym->highbound;

        if(nexttok == NULL){
            arrsym->datatype = typesym;
	    arrsym->size = ((arrsym->highbound)-(arrsym->lowbound)+1)*(typesym->size);
	}
	if(prevsym){
	    prevsym->datatype = arrsym;
	}else{
	    typetok->symtype = arrsym;
	}
        prevsym = arrsym;
        tok = tok->link;
	if(nexttok) nexttok = nexttok->link;
    }
    
    findarraysize(typetok->symtype, typesym);
    if (DEBUG) {
        printf("instarray\n");
        dbugprinttok(typetok);
	printsymbol(typetok->symtype);
	//printst();
        //exit(0);
    }
    return typetok;
}

int findarraysize(SYMBOL sym, SYMBOL type){
    if(sym->datatype == type && sym->datatype->datatype != type){
        return sym->size;
    }
    sym->size = findarraysize(sym->datatype, type)*((sym->highbound)-(sym->lowbound)+1);
    return sym->size;
}

TOKEN instrec(TOKEN rectok, TOKEN argstok){
    //printf("begin of instrec\n");
    SYMBOL sym = symalloc();
    sym->kind = RECORDSYM;
    rectok->symtype = sym;
    TOKEN args = argstok;
    TOKEN args_prev = NULL;
    int size = 0, offs = 0;
    
    while(args != NULL){
	size = args->symtype->size;
        SYMBOL newsym = makesym(args->stringval);
        newsym->datatype = args->symtype;
        newsym->offset = wordaddress(offs, size);
        newsym->size = size;

        offs = newsym->offset + size;
        args->symtype = newsym;
        
        if(args_prev){
            args_prev->symtype->link = newsym;
        }else{
            sym->datatype = newsym;
        }

        args_prev = args;
        args = args->link;
    }

    sym->size = wordaddress(offs, 16);
    if (DEBUG) {
        printf("instrec\n");
        printsymbol(sym);
        dbugprinttok(rectok);
        //printst();
    }
    return rectok;
}

TOKEN dogoto(TOKEN tok, TOKEN labeltok){
    int label_index = findlabelindex(labeltok->intval);
    tok = makegoto(label_index);
    if(DEBUG){
        printf("dogoto");
        dbugprinttok(tok);
    }
    return tok;
}

TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
    int index = 0;
    int offset = 0;
    tok = maketok(OPERATOR, AREFOP, arr);
    TOKEN offs_tok = NULL;
    TOKEN trace = subs;
    SYMBOL arr_sym = arr->symtype;

    while(trace != NULL) {
        int size = arr_sym->datatype->size;

        TOKEN times_op = makeop(TIMESOP);
        TOKEN times_tok;

        TOKEN next = trace->link;

        if(trace->tokentype == NUMBERTOK)
            times_tok = makeintc((trace->intval) * size);
        else
            times_tok = binop(times_op, makeintc(size), trace);

        TOKEN plus_op = makeop(PLUSOP);
        TOKEN plus_tok;

        if(times_tok->tokentype == NUMBERTOK){
            plus_tok = makeintc((-size * arr_sym->lowbound)+(times_tok->intval));
        }else{
            plus_tok = binop(plus_op, makeintc(-size * arr_sym->lowbound), times_tok);
        }

        if(offs_tok) {
            if(plus_tok->tokentype == NUMBERTOK){
                offs_tok->operands->intval += plus_tok->intval;
            }else{
                TOKEN add_tok = makeop(PLUSOP);
                TOKEN add_offs = binop(add_tok, offs_tok, plus_tok);
                offs_tok = add_offs;
            }
        } else {
            offs_tok = plus_tok;
        }
        arr_sym = arr_sym->datatype;
        trace = next;
    }
    
    while(arr_sym->kind == TYPESYM)
        arr_sym = arr_sym->datatype;
    tok->operands->link = offs_tok;
    tok->symtype = arr_sym;
    tok->basicdt = 0;

    return tok;
}

TOKEN dopoint(TOKEN var, TOKEN tok){
    tok = maketok(OPERATOR, POINTEROP, var);
    SYMBOL sym = var->symtype;
    while(sym->kind == TYPESYM)
        sym = sym->datatype;
    tok->symtype = sym;
    if(DEBUG){
        printf("do point\n");
        //printst();
        dbugprinttok(tok);
	dbugprinttok(var);
	dbugbprinttok(var);
    }
    return tok;
}

TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok){
    if(var->tokentype==OPERATOR && var->whichval==AREFOP){
        int offset = off->intval;
        var->operands->link->operands->intval += offset;
        return var;
    }
    tok = makeop(AREFOP);
    tok->operands = var;
    var->link = off;
    if(DEBUG){
        printf("make aref\n");
        dbugprinttok(tok);
    }
    return tok;
}

TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
    int pointer = 0;

    SYMBOL recsym = var->symtype;
    if(recsym->kind == POINTERSYM) {
        recsym = recsym->datatype;
        while(recsym->kind == TYPESYM) {
            recsym = recsym->datatype;
        }
        pointer = 1;
    }

    SYMBOL trace = recsym;
    if(trace->kind == RECORDSYM){
        trace = recsym->datatype;
    }
    int ofs = 0;

    while(trace) {
        if(strcmp(trace->namestring, field->stringval)==0){
            ofs = trace->offset;
            break;
        }
        trace = trace->link;
    }
  
    if(pointer==0 && var->tokentype==OPERATOR && var->whichval==AREFOP
            && var->operands->link->tokentype==NUMBERTOK){
        dot = var;
        dot->operands->link = makeintc(ofs+var->operands->link->intval);
        dot->basicdt = trace->datatype->basicdt;
        if(DEBUG){
            printf("reduce dot\n");
            dbugprinttok(dot);
            dbugprinttok(var);
            dbugprinttok(field);
            dbugbprinttok(field);
        }
	return dot;
    }else{
        dot = makearef(var, makeintc(ofs), dot);
    }

    trace = trace->datatype;
    while(trace->kind == TYPESYM) {
        trace = trace->datatype;
    }

    dot->basicdt = trace->basicdt;
    dot->symtype = trace->datatype;

    if(DEBUG){
        printf("reduce dot\n");
        dbugprinttok(dot);
        dbugprinttok(var);
        dbugprinttok(field);
    }
    return dot;
}


TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement){
    TOKEN label_tok = makelabel();
    TOKEN goto_tok = makegoto(label_tok->operands->intval);
    TOKEN if_tok = talloc();

    if_tok = makeif(if_tok, expr, statement, NULL);
    tok = makepnb(tok, label_tok);
    
    label_tok->link = if_tok;
    TOKEN statement_tok = statement->operands;
    while(statement_tok->link != NULL)
        statement_tok = statement_tok->link;
    statement_tok->link = goto_tok;
    
    if(DEBUG){
        printf("make while\n");
        dbugprinttok(tok);
    }
    return tok;
}

TOKEN makepnb(TOKEN tok, TOKEN statements){
    if(statements->tokentype == OPERATOR && statements->whichval == PROGNOP
        && statements->link == NULL){
        return statements;
    }else{
        return makeprogn(tok, statements);
    }
}

/*===================================================================
========================end of third part============================
===================================================================*/

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }

void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

int main(void)          /*  */
  { int res;
    initsyms();
    res = yyparse();
    printstlevel(1);       /* to shorten, change to:  printstlevel(1);  */
    //printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
    /* uncomment following to call code generator. */
     
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
 
  }
