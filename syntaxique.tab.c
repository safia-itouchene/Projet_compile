
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
#line 1 "syntaxique.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "quadrupler.h"
#include "quadrupler.c"
#include "optimisation.h"
#include "optimisation.c"
#include "cod_obg.c"
#include "cod_obg.h"
#include"ts.h" 
/*Définitions en langage C*/
int i=0 ,j,a=0 ,compatibilite = 0, k=1 , valuetype = 0 , nb_ligne=1 ,Col=1 , nTemp=1;
int sauvtype,fin_pos ,sauv_debut_while ,sauv_deb_for ,else_pos; 
char tempC[12]="" , val[12]="";
char  *sauv_idf ,  *id;
typedef struct{ 
	 char*  nom_idf; 
     }tab_idf;
     tab_idf  tab[20];
	 
void insert_liste_idf(int code_type){
      while(sauv_var != NULL)
        {  
            id= depiler(&sauv_var);
            inserer(strdup(id),code_type, 0 , 2);
        }
}


/* Line 189 of yacc.c  */
#line 104 "syntaxique.tab.c"

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
     commentaire = 258,
     vrg = 259,
     aff = 260,
     plus = 261,
     moin = 262,
     mult = 263,
     division = 264,
     par_ov = 265,
     par_fr = 266,
     accolade_fr = 267,
     aco_f = 268,
     aco_o = 269,
     accolade_ov = 270,
     dpts = 271,
     pts_vrg = 272,
     mc_if = 273,
     mc_else = 274,
     mc_for = 275,
     mc_while = 276,
     mc_or = 277,
     mc_and = 278,
     mc_not = 279,
     mc_var = 280,
     mc_code = 281,
     mc_struct = 282,
     mc_entier = 283,
     mc_reel = 284,
     mc_const = 285,
     entier = 286,
     reel = 287,
     idf = 288,
     G = 289,
     L = 290,
     GE = 291,
     LE = 292,
     NEQ = 293,
     EQ = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 30 "syntaxique.y"

        char* str;
        int  integer;
        float f;
        struct {
                char* res;
                 int type;
                float  val;
                }EXP;



/* Line 214 of yacc.c  */
#line 192 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 204 "syntaxique.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     8,    17,    20,    23,    24,    26,    28,
      30,    32,    34,    36,    43,    46,    49,    50,    52,    57,
      61,    65,    69,    73,    77,    79,    83,    90,    95,    97,
      99,   101,   104,   107,   108,   110,   112,   114,   116,   121,
     123,   128,   133,   144,   146,   148,   153,   158,   161,   168,
     171,   177,   181,   185,   189,   193,   197,   201,   204,   208,
     212,   214,   216,   220,   224,   228,   232,   236,   238,   240
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    33,    15,    42,    12,    -1,    25,    15,
      43,    12,    26,    15,    57,    12,    -1,    44,    43,    -1,
       3,    43,    -1,    -1,    50,    -1,    52,    -1,    54,    -1,
      45,    -1,    46,    -1,    49,    -1,    27,    15,    47,    12,
      33,    17,    -1,    48,    47,    -1,     3,    47,    -1,    -1,
      52,    -1,    27,    33,    53,    17,    -1,    30,    51,    17,
      -1,    33,     5,    31,    -1,    33,     5,    32,    -1,    56,
      53,    17,    -1,    33,     4,    53,    -1,    33,    -1,    56,
      55,    17,    -1,    33,    14,    31,    13,     4,    55,    -1,
      33,    14,    31,    13,    -1,    28,    -1,    29,    -1,    58,
      -1,    59,    58,    -1,     3,    58,    -1,    -1,    60,    -1,
      62,    -1,    65,    -1,    67,    -1,    61,     5,    72,    17,
      -1,    33,    -1,    33,    14,    31,    13,    -1,    63,    15,
      58,    12,    -1,    20,    10,    33,    16,    64,    16,    31,
      16,    64,    11,    -1,    31,    -1,    33,    -1,    66,    15,
      58,    12,    -1,    21,    10,    70,    11,    -1,    68,    12,
      -1,    68,    12,    19,    15,    58,    12,    -1,    69,    58,
      -1,    18,    10,    70,    11,    15,    -1,    71,    39,    71,
      -1,    71,    38,    71,    -1,    71,    35,    71,    -1,    71,
      34,    71,    -1,    71,    36,    71,    -1,    71,    37,    71,
      -1,    24,    71,    -1,    70,    22,    70,    -1,    70,    23,
      70,    -1,    71,    -1,    72,    -1,    72,     6,    72,    -1,
      72,     7,    72,    -1,    72,     8,    72,    -1,    72,     9,
      72,    -1,    10,    72,    11,    -1,    33,    -1,    31,    -1,
      32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    56,    58,    59,    60,    63,    64,    65,
      66,    68,    69,    71,    73,    74,    75,    77,    79,    81,
      83,    85,    88,    90,    95,   101,   103,   105,   108,   109,
     112,   114,   115,   116,   118,   119,   120,   121,   124,   131,
     133,   137,   143,   148,   149,   152,   155,   159,   161,   164,
     167,   171,   175,   179,   183,   187,   191,   195,   199,   203,
     207,   210,   212,   214,   216,   218,   223,   225,   233,   241
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "commentaire", "vrg", "aff", "plus",
  "moin", "mult", "division", "par_ov", "par_fr", "accolade_fr", "aco_f",
  "aco_o", "accolade_ov", "dpts", "pts_vrg", "mc_if", "mc_else", "mc_for",
  "mc_while", "mc_or", "mc_and", "mc_not", "mc_var", "mc_code",
  "mc_struct", "mc_entier", "mc_reel", "mc_const", "entier", "reel", "idf",
  "G", "L", "GE", "LE", "NEQ", "EQ", "$accept", "S", "COR_PRG",
  "LISTE_DEC", "DEC", "DEC_STRUCT", "DEF_STRUCT", "COR_STRUCT",
  "LISTE_DEC_STR", "VAR_STRUCT", "DEC_CST", "AFF_CONST", "DEC_VAR",
  "LISTE_IDF", "DEC_TAB", "LISTE_TAB", "TYPE_VAR", "MAIN",
  "LISTE_INSTRUCTION", "INSTRUCTION", "INSTRUCTION_AFFECTATION",
  "PARTIE_GOUCHE", "LOOP_FOR", "DEBUT_FOR", "INIT", "LOOP_WHAILE",
  "DEBUT_WHILE", "IF_ELSE", "A", "B", "CONDITION", "EXP_AR", "EXP", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    43,    43,    43,    44,    44,    44,
      44,    45,    45,    46,    47,    47,    47,    48,    49,    50,
      51,    51,    52,    53,    53,    54,    55,    55,    56,    56,
      57,    58,    58,    58,    59,    59,    59,    59,    60,    61,
      61,    62,    63,    64,    64,    65,    66,    67,    67,    68,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    72,    72,    72,    72,    72,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     8,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     6,     2,     2,     0,     1,     4,     3,
       3,     3,     3,     3,     1,     3,     6,     4,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     1,     4,     1,
       4,     4,    10,     1,     1,     4,     4,     2,     6,     2,
       5,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     6,     2,     6,
       0,    28,    29,     0,     0,     6,    10,    11,    12,     7,
       8,     9,     0,     5,    16,     0,     0,     0,     0,     4,
      24,     0,     0,    16,     0,    16,    17,     0,    24,     0,
       0,    19,     0,     0,     0,    22,    25,    15,     0,    14,
      18,    20,    21,    33,    23,     0,     0,    33,     0,     0,
       0,    39,     0,    30,    33,    34,     0,    35,     0,    36,
       0,    37,     0,    33,    27,    13,    32,     0,     0,     0,
       0,     3,    31,     0,    33,    33,    47,    49,     0,     0,
       0,    68,    69,    67,     0,    60,    61,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    40,    38,    41,    45,    33,    66,    50,
      58,    59,    54,    53,    55,    56,    52,    51,    62,    63,
      64,    65,    43,    44,     0,     0,     0,    48,     0,     0,
       0,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    14,    15,    16,    17,    34,    35,    18,
      19,    27,    20,    31,    21,    32,    22,    62,    63,    64,
      65,    66,    67,    68,   144,    69,    70,    71,    72,    73,
      94,    95,    96
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -82
static const yytype_int8 yypact[] =
{
     -23,     7,    15,    48,   -82,    76,    85,    14,   -82,    14,
     -10,   -82,   -82,    65,    88,    14,   -82,   -82,   -82,   -82,
     -82,   -82,    66,   -82,     1,    68,    97,    86,    78,   -82,
       5,    89,    90,     1,    93,     1,   -82,    68,   104,    92,
      20,   -82,    95,    68,    80,   -82,   -82,   -82,    79,   -82,
     -82,   -82,   -82,     0,   -82,   100,    98,     0,   106,   107,
     108,   105,   102,   -82,     0,   -82,   115,   -82,   109,   -82,
     110,   -82,   111,     0,   117,   -82,   -82,    30,    94,    30,
      91,   -82,   -82,    24,     0,     0,   112,   -82,    96,    24,
      24,   -82,   -82,   -82,     3,    47,    87,   114,    49,   113,
      58,   116,   120,   118,   121,   -82,    81,   -82,   119,    30,
      30,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,   -20,   -82,   -82,   -82,   -82,   -82,     0,   -82,   -82,
     -82,   122,   -82,   -82,   -82,   -82,   -82,   -82,    50,    50,
     -82,   -82,   -82,   -82,   123,   124,   125,   -82,   126,   -20,
     127,   -82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   -82,   -82,    -3,   -82,   -82,   -82,    41,   -82,   -82,
     -82,   -82,    44,    10,   -82,    52,    45,   -82,   -57,   -82,
     -82,   -82,   -82,   -82,   -12,   -82,   -82,   -82,   -82,   -82,
     -78,   -66,   -81
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      76,    98,   100,    57,    33,    24,    23,    82,   106,    43,
       1,   142,    29,   143,   108,     4,    87,     9,    58,    44,
      59,    60,     3,    25,   107,   109,   110,   101,   102,    11,
      12,   130,   131,    61,    89,    39,   138,   139,   140,   141,
      89,    10,    11,    12,    13,   132,   133,   134,   135,   136,
     137,    51,    52,    54,    90,    91,    92,    93,   119,   120,
     122,    91,    92,    93,   117,   118,   119,   120,    36,    37,
     145,   109,   110,     5,    47,   124,    49,    36,    37,    36,
      37,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     7,   128,   117,   118,   119,   120,     8,    26,    30,
      28,    38,    40,    41,    42,    48,    45,    46,    43,    50,
      53,    55,    56,    74,    81,    75,    77,    78,    79,    80,
      83,    88,    99,    86,    84,    85,   123,    97,   125,   104,
     121,   103,   126,   127,   129,    44,   147,   150,   151,   146,
     105,     0,   149,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148
};

static const yytype_int16 yycheck[] =
{
      57,    79,    83,     3,     3,    15,     9,    64,    89,     4,
      33,    31,    15,    33,    11,     0,    73,     3,    18,    14,
      20,    21,    15,    33,    90,    22,    23,    84,    85,    28,
      29,   109,   110,    33,    10,    25,   117,   118,   119,   120,
      10,    27,    28,    29,    30,   111,   112,   113,   114,   115,
     116,    31,    32,    43,    24,    31,    32,    33,     8,     9,
      11,    31,    32,    33,     6,     7,     8,     9,    24,    24,
     127,    22,    23,    25,    33,    17,    35,    33,    33,    35,
      35,    34,    35,    36,    37,    38,    39,     6,     7,     8,
       9,    15,    11,     6,     7,     8,     9,    12,    33,    33,
      12,    33,     5,    17,    26,    12,    17,    17,     4,    17,
      15,    31,    33,    13,    12,    17,    10,    10,    10,    14,
       5,     4,    31,    12,    15,    15,    13,    33,    12,    33,
      16,    19,    12,    15,    15,    14,    12,   149,    11,    16,
      88,    -1,    16,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    41,    15,     0,    25,    42,    15,    12,     3,
      27,    28,    29,    30,    43,    44,    45,    46,    49,    50,
      52,    54,    56,    43,    15,    33,    33,    51,    12,    43,
      33,    53,    55,     3,    47,    48,    52,    56,    33,    53,
       5,    17,    26,     4,    14,    17,    17,    47,    12,    47,
      17,    31,    32,    15,    53,    31,    33,     3,    18,    20,
      21,    33,    57,    58,    59,    60,    61,    62,    63,    65,
      66,    67,    68,    69,    13,    17,    58,    10,    10,    10,
      14,    12,    58,     5,    15,    15,    12,    58,     4,    10,
      24,    31,    32,    33,    70,    71,    72,    33,    70,    31,
      72,    58,    58,    19,    33,    55,    72,    71,    11,    22,
      23,    34,    35,    36,    37,    38,    39,     6,     7,     8,
       9,    16,    11,    13,    17,    12,    12,    15,    11,    15,
      70,    70,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    31,    33,    64,    58,    16,    12,    31,    16,
      64,    11
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
        case 2:

/* Line 1455 of yacc.c  */
#line 54 "syntaxique.y"
    {printf("\n \n programme syntaxiquement correct ^_^ .\n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 84 "syntaxique.y"
    {doubleDeclaration(strdup((yyvsp[(1) - (3)].str))); inserer(strdup((yyvsp[(1) - (3)].str)),1,0,1); inser_val(strdup((yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].integer));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 86 "syntaxique.y"
    {doubleDeclaration(strdup((yyvsp[(1) - (3)].str))); inserer(strdup((yyvsp[(1) - (3)].str)),2,0,1); inser_val(strdup((yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].f));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 91 "syntaxique.y"
    {
            empiler_Str(&sauv_var,strdup((yyvsp[(1) - (3)].str))); doubleDeclaration(strdup((yyvsp[(1) - (3)].str)));
            insert_liste_idf(sauvtype);
           ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 96 "syntaxique.y"
    {
            empiler_Str(&sauv_var,strdup((yyvsp[(1) - (1)].str))); doubleDeclaration(strdup((yyvsp[(1) - (1)].str))); 
            insert_liste_idf(sauvtype);
          ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 104 "syntaxique.y"
    {doubleDeclaration(strdup((yyvsp[(1) - (6)].str))); inserer(strdup((yyvsp[(1) - (6)].str)), sauvtype , (yyvsp[(3) - (6)].integer) ,2);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 106 "syntaxique.y"
    {doubleDeclaration(strdup((yyvsp[(1) - (4)].str))); inserer(strdup((yyvsp[(1) - (4)].str)), sauvtype , (yyvsp[(3) - (4)].integer) ,2);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 108 "syntaxique.y"
    {  sauvtype = 1;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 109 "syntaxique.y"
    {  sauvtype = 2;;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 125 "syntaxique.y"
    { 
                          if(a != compatibilite){yyerror("\n\n type incompatible");}                   
                          compatibilite=0;  quadrupler (":=",(yyvsp[(3) - (4)].EXP).res,"",sauv_idf);
                          inser_val(sauv_idf,(yyvsp[(3) - (4)].EXP).val);  
                        ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 132 "syntaxique.y"
    {dec ((yyvsp[(1) - (1)].str)); a = returntype((yyvsp[(1) - (1)].str));   sauv_idf=strdup((yyvsp[(1) - (1)].str));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 134 "syntaxique.y"
    {dec ((yyvsp[(1) - (4)].str)); a = returntype((yyvsp[(1) - (4)].str)); veriftailletab((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].integer)); sauv_idf=strdup((yyvsp[(1) - (4)].str));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 138 "syntaxique.y"
    { 
           sauv_idf = depiler(&sauv_var); quadrupler("+",strdup(sauv_idf),"1",strdup(sauv_idf)); 
           sauv_deb_for = depiler_qc(&pileFOR); quadrupler("BR",ToSTR(sauv_deb_for),"",""); q[sauv_deb_for].op1= ToSTR(indq); 
         ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 144 "syntaxique.y"
    { 
            dec((yyvsp[(3) - (10)].str)); quadrupler("=",(yyvsp[(5) - (10)].EXP).res,"",(yyvsp[(3) - (10)].str)); empiler_qc(&pileFOR,indq); quadrupler("BG","",(yyvsp[(3) - (10)].str),(yyvsp[(9) - (10)].EXP).res); empiler_Str(&sauv_var, (yyvsp[(3) - (10)].str));
          ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 148 "syntaxique.y"
    {(yyval.EXP).res = ToSTR((yyvsp[(1) - (1)].integer));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 149 "syntaxique.y"
    { (yyval.EXP).res = strdup((yyvsp[(1) - (1)].str)); dec((yyvsp[(1) - (1)].str));  if(returntype((yyvsp[(1) - (1)].str)) != 1) yyerror("type incompatible"); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 153 "syntaxique.y"
    {quadrupler("BR",ToSTR(sauv_debut_while),"",""); q[sauv_debut_while].op1= ToSTR(indq); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 156 "syntaxique.y"
    {empiler_qc(&pile2,indq); sauv_debut_while= depiler_qc(&pile2);  quadrupler("BZ","",strdup((yyvsp[(3) - (4)].EXP).res),"");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 160 "syntaxique.y"
    {indq--; fin_pos = depiler_qc(&pile1);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 162 "syntaxique.y"
    {fin_pos = depiler_qc(&pile1); q[fin_pos].op1= ToSTR(indq);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 165 "syntaxique.y"
    {else_pos = depiler_qc(&pile1); q[else_pos].op1= ToSTR(indq+ 1); empiler_qc(&pile1, indq); quadrupler("BR","","","");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 168 "syntaxique.y"
    {empiler_qc(&pile1, indq); quadrupler("BZ","",strdup((yyvsp[(3) - (5)].EXP).res),"");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 172 "syntaxique.y"
    {  sprintf(tempC, "T%d",nTemp);
             nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0'; 
             createquadruplerCompare (2,(yyvsp[(1) - (3)].EXP).res,(yyvsp[(3) - (3)].EXP).res,(yyval.EXP).res);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 176 "syntaxique.y"
    {  sprintf(tempC, "T%d",nTemp);
             nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0'; 
             createquadruplerCompare (1,(yyvsp[(1) - (3)].EXP).res,(yyvsp[(3) - (3)].EXP).res,(yyval.EXP).res);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 180 "syntaxique.y"
    {   sprintf(tempC, "T%d",nTemp);
              nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerCompare (3,(yyvsp[(1) - (3)].EXP).res,(yyvsp[(3) - (3)].EXP).res,(yyval.EXP).res);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 184 "syntaxique.y"
    {   sprintf(tempC, "T%d",nTemp);
              nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerCompare (4,(yyvsp[(1) - (3)].EXP).res,(yyvsp[(3) - (3)].EXP).res,(yyval.EXP).res);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 188 "syntaxique.y"
    {   sprintf(tempC, "T%d",nTemp);
              nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerCompare (5,(yyvsp[(1) - (3)].EXP).res,(yyvsp[(3) - (3)].EXP).res,(yyval.EXP).res);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 192 "syntaxique.y"
    {   sprintf(tempC, "T%d",nTemp);
              nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerCompare (6,(yyvsp[(1) - (3)].EXP).res,(yyvsp[(3) - (3)].EXP).res,(yyval.EXP).res);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 196 "syntaxique.y"
    {   sprintf(tempC, "T%d",nTemp);
              nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerLogic   (1,(yyvsp[(2) - (2)].EXP).res,NULL,(yyval.EXP).res);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 200 "syntaxique.y"
    {   sprintf(tempC, "T%d",nTemp);
              nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerLogic   (2,(yyvsp[(1) - (3)].EXP).res,(yyvsp[(3) - (3)].EXP).res,(yyval.EXP).res);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 204 "syntaxique.y"
    {   sprintf(tempC, "T%d",nTemp);
              nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerLogic   (3,(yyvsp[(1) - (3)].EXP).res,(yyvsp[(3) - (3)].EXP).res,(yyval.EXP).res);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 210 "syntaxique.y"
    {(yyval.EXP).res = (yyvsp[(1) - (1)].EXP).res; compatibilite=0;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 213 "syntaxique.y"
    {sprintf(tempC, "T%d",nTemp);nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0';quadrupler ("+",(yyvsp[(1) - (3)].EXP).res,(yyvsp[(3) - (3)].EXP).res,(yyval.EXP).res);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 215 "syntaxique.y"
    {sprintf(tempC, "T%d",nTemp);nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0';quadrupler ("-",(yyvsp[(1) - (3)].EXP).res,(yyvsp[(3) - (3)].EXP).res,(yyval.EXP).res);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 217 "syntaxique.y"
    {sprintf(tempC, "T%d",nTemp);nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0';quadrupler ("*",(yyvsp[(1) - (3)].EXP).res,(yyvsp[(3) - (3)].EXP).res,(yyval.EXP).res);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 219 "syntaxique.y"
    {
      if ((yyvsp[(3) - (3)].EXP).val==0){yyerror("\n\ndivision sur 0") ;}
      sprintf(tempC, "T%d",nTemp);nTemp++;(yyval.EXP).res=strdup(tempC);tempC[0]='\0'; quadrupler ("/",(yyvsp[(1) - (3)].EXP).res,(yyvsp[(3) - (3)].EXP).res,(yyval.EXP).res);
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 224 "syntaxique.y"
    {(yyval.EXP).type=(yyvsp[(2) - (3)].EXP).type; (yyval.EXP).res=(yyvsp[(2) - (3)].EXP).res;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 226 "syntaxique.y"
    { dec ((yyvsp[(1) - (1)].str));        
      if(compatibilite == 0) {compatibilite = returntype(strdup((yyvsp[(1) - (1)].str))) ;  } 
      else { 
            if(compatibilite != returntype(strdup((yyvsp[(1) - (1)].str)))) { yyerror("\n\ntype incompatible") ;}
           }  
         (yyval.EXP).res=strdup((yyvsp[(1) - (1)].str));      (yyval.EXP).val=1;                
      ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 234 "syntaxique.y"
    {    
       if(compatibilite == 0) {compatibilite = 1; }
       else{ 
             if (compatibilite != 1 ){ yyerror("\n\ntype incompatible") ;}
           }     
            sprintf(val, "%d",(yyvsp[(1) - (1)].integer)); (yyval.EXP).res=strdup(val); (yyval.EXP).val=(yyvsp[(1) - (1)].integer); 
     ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 242 "syntaxique.y"
    {  
        if(compatibilite == 0) {compatibilite = 2;} 
        else  { 
               if (compatibilite != 2 ){ yyerror("\n\ntype incompatible") ;}
              }
             sprintf(val, "%f",(yyvsp[(1) - (1)].f)); (yyval.EXP).res=strdup(val);  (yyval.EXP).val=(yyvsp[(1) - (1)].f);    
      ;}
    break;



/* Line 1455 of yacc.c  */
#line 1861 "syntaxique.tab.c"
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
#line 251 "syntaxique.y"

/*Redéfinitions des fonctions prédéfinies*/
yyerror(char*msg)           
 {
	printf(" %s a la ligne %d et a la colonne %d \n",msg, nb_ligne, Col);
	exit (0);
 }
main()
{
init();
yyparse();

printf("\n------------------LES quadruplerRUPLETS AVANT OPTIMISATION ----------------------\n");
afficherquadrupler();

optimisation();

printf("\n------------------LES quadruplerRUPLETS APRES OPTIMISATION----------------------\n");
afficherquadrupler();

//code assembleur
assembler();

//table des mots clés et séparateurs
afficher();    
printf("\n \n");

//la table des IDF 
printHachTable();
printf("\n \n");

}
yywrap()
{}

