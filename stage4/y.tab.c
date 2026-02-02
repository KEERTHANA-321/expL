/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include "nodestructure.h"
    #include "constants.h"
    #include "symbolTable.h"
    int yydebug = 1; 
    

    int yylex(void);
    void yyerror(char const *msg);
    extern FILE *yyin;
    FILE *out;

#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_BEGIN = 258,                /* KW_BEGIN  */
    END = 259,                     /* END  */
    READ = 260,                    /* READ  */
    WRITE = 261,                   /* WRITE  */
    PLUS = 262,                    /* PLUS  */
    MINUS = 263,                   /* MINUS  */
    MUL = 264,                     /* MUL  */
    DIV = 265,                     /* DIV  */
    NUM = 266,                     /* NUM  */
    ID = 267,                      /* ID  */
    SEMI = 268,                    /* SEMI  */
    ASSIGN = 269,                  /* ASSIGN  */
    STRVAL = 270,                  /* STRVAL  */
    LE = 271,                      /* LE  */
    LT = 272,                      /* LT  */
    GE = 273,                      /* GE  */
    GT = 274,                      /* GT  */
    NE = 275,                      /* NE  */
    EQ = 276,                      /* EQ  */
    IF = 277,                      /* IF  */
    WHILE = 278,                   /* WHILE  */
    ENDWHILE = 279,                /* ENDWHILE  */
    ENDIF = 280,                   /* ENDIF  */
    DO = 281,                      /* DO  */
    THEN = 282,                    /* THEN  */
    ELSE = 283,                    /* ELSE  */
    BREAK = 284,                   /* BREAK  */
    CONT = 285,                    /* CONT  */
    REPEAT = 286,                  /* REPEAT  */
    UNTIL = 287,                   /* UNTIL  */
    DECL = 288,                    /* DECL  */
    ENDDECL = 289,                 /* ENDDECL  */
    T_INT = 290,                   /* T_INT  */
    T_STR = 291,                   /* T_STR  */
    COMMA = 292,                   /* COMMA  */
    ASSGN = 293                    /* ASSGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_BEGIN 258
#define END 259
#define READ 260
#define WRITE 261
#define PLUS 262
#define MINUS 263
#define MUL 264
#define DIV 265
#define NUM 266
#define ID 267
#define SEMI 268
#define ASSIGN 269
#define STRVAL 270
#define LE 271
#define LT 272
#define GE 273
#define GT 274
#define NE 275
#define EQ 276
#define IF 277
#define WHILE 278
#define ENDWHILE 279
#define ENDIF 280
#define DO 281
#define THEN 282
#define ELSE 283
#define BREAK 284
#define CONT 285
#define REPEAT 286
#define UNTIL 287
#define DECL 288
#define ENDDECL 289
#define T_INT 290
#define T_STR 291
#define COMMA 292
#define ASSGN 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

    struct tnode *node;

#line 219 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_BEGIN = 3,                   /* KW_BEGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_READ = 5,                       /* READ  */
  YYSYMBOL_WRITE = 6,                      /* WRITE  */
  YYSYMBOL_PLUS = 7,                       /* PLUS  */
  YYSYMBOL_MINUS = 8,                      /* MINUS  */
  YYSYMBOL_MUL = 9,                        /* MUL  */
  YYSYMBOL_DIV = 10,                       /* DIV  */
  YYSYMBOL_NUM = 11,                       /* NUM  */
  YYSYMBOL_ID = 12,                        /* ID  */
  YYSYMBOL_SEMI = 13,                      /* SEMI  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_STRVAL = 15,                    /* STRVAL  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_GE = 18,                        /* GE  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_ENDWHILE = 24,                  /* ENDWHILE  */
  YYSYMBOL_ENDIF = 25,                     /* ENDIF  */
  YYSYMBOL_DO = 26,                        /* DO  */
  YYSYMBOL_THEN = 27,                      /* THEN  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_BREAK = 29,                     /* BREAK  */
  YYSYMBOL_CONT = 30,                      /* CONT  */
  YYSYMBOL_REPEAT = 31,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 32,                     /* UNTIL  */
  YYSYMBOL_DECL = 33,                      /* DECL  */
  YYSYMBOL_ENDDECL = 34,                   /* ENDDECL  */
  YYSYMBOL_T_INT = 35,                     /* T_INT  */
  YYSYMBOL_T_STR = 36,                     /* T_STR  */
  YYSYMBOL_COMMA = 37,                     /* COMMA  */
  YYSYMBOL_ASSGN = 38,                     /* ASSGN  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_Declarations = 43,              /* Declarations  */
  YYSYMBOL_DeclList = 44,                  /* DeclList  */
  YYSYMBOL_Decl = 45,                      /* Decl  */
  YYSYMBOL_Type = 46,                      /* Type  */
  YYSYMBOL_VarList = 47,                   /* VarList  */
  YYSYMBOL_Slist = 48,                     /* Slist  */
  YYSYMBOL_Stmt = 49,                      /* Stmt  */
  YYSYMBOL_IfStmt = 50,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 51,                 /* WhileStmt  */
  YYSYMBOL_BrkStmt = 52,                   /* BrkStmt  */
  YYSYMBOL_ContStmt = 53,                  /* ContStmt  */
  YYSYMBOL_repeatUntilStmt = 54,           /* repeatUntilStmt  */
  YYSYMBOL_doWhileStmt = 55,               /* doWhileStmt  */
  YYSYMBOL_InputStmt = 56,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 57,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 58,                   /* AsgStmt  */
  YYSYMBOL_expr = 59,                      /* expr  */
  YYSYMBOL_id = 60                         /* id  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   352

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    36,    36,    44,    48,    49,    52,    53,    56,    59,
      60,    63,    64,    67,    68,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    84,    88,    93,    98,   100,   101,
     104,   108,   111,   113,   119,   124,   129,   134,   139,   142,
     145,   148,   151,   154,   157,   158,   159,   160,   162
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_BEGIN", "END",
  "READ", "WRITE", "PLUS", "MINUS", "MUL", "DIV", "NUM", "ID", "SEMI",
  "ASSIGN", "STRVAL", "LE", "LT", "GE", "GT", "NE", "EQ", "IF", "WHILE",
  "ENDWHILE", "ENDIF", "DO", "THEN", "ELSE", "BREAK", "CONT", "REPEAT",
  "UNTIL", "DECL", "ENDDECL", "T_INT", "T_STR", "COMMA", "ASSGN", "'('",
  "')'", "$accept", "program", "Declarations", "DeclList", "Decl", "Type",
  "VarList", "Slist", "Stmt", "IfStmt", "WhileStmt", "BrkStmt", "ContStmt",
  "repeatUntilStmt", "doWhileStmt", "InputStmt", "OutputStmt", "AsgStmt",
  "expr", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,   -16,     7,     9,   -32,   -32,   -32,    -8,   -32,     1,
     -32,   187,   -32,   -32,   -32,    -5,     8,    -1,     0,   -32,
      11,    12,   281,    18,    39,   281,   199,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,    45,   -32,    49,
     -32,    50,    -6,    -6,    -6,   293,   -32,   -32,   214,    47,
     -32,    -6,   -32,    23,   -32,   -32,    -6,    48,   -32,    88,
     103,    31,    32,   -32,   318,    59,   128,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    60,    52,    54,
      -6,    -6,   -32,   -32,   -32,   331,   331,   113,   113,   153,
     153,   153,   153,    15,    15,   -32,   281,   281,   143,   168,
     226,   253,    -3,    61,    68,   281,    69,   -32,   -32,   -32,
     266,   -32,    70,   -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     5,     9,    10,     0,     7,     0,
       1,     0,     4,     6,    12,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,    14,    18,    19,
      20,    21,    22,    23,    15,    16,    17,     0,     8,     0,
       3,     0,     0,     0,     0,     0,    27,    28,     0,     0,
      13,     0,    11,     0,    45,    46,     0,     0,    47,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    31,    44,    34,    35,    36,    37,    40,
      38,    41,    39,    42,    43,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    29,    25,
       0,    26,     0,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -32,   -32,    84,   -32,   -32,   -21,   -23,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -27,   -11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     7,     8,     9,    15,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    45,     1,    50,    48,    54,    19,    10,    38,    55,
     107,    37,    11,    14,    37,    37,    59,    60,     4,     5,
       6,    40,    50,    97,    64,    50,    12,     5,     6,    66,
      53,    46,    39,    56,    37,    75,    76,    37,    41,    42,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      43,    44,    47,    98,    99,    67,    68,    69,    70,    51,
      63,    52,    19,    65,    71,    72,    73,    74,    75,    76,
      80,    81,    83,    95,   108,   100,   101,    50,    50,    96,
      97,   109,   111,   113,   110,    37,    37,    50,    77,    37,
      37,    13,     0,     0,    37,    67,    68,    69,    70,    37,
       0,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      67,    68,    69,    70,     0,     0,     0,     0,     0,    71,
      72,    73,    74,    75,    76,     0,     0,     0,    78,    71,
      72,    73,    74,    75,    76,    67,    68,    69,    70,     0,
       0,     0,     0,    79,    71,    72,    73,    74,    75,    76,
      67,    68,    69,    70,     0,     0,     0,     0,     0,    71,
      72,    73,    74,    75,    76,     0,     0,     0,    84,    -1,
      -1,    -1,    -1,    75,    76,    67,    68,    69,    70,     0,
       0,     0,     0,   102,    71,    72,    73,    74,    75,    76,
       0,    16,    17,    18,     0,     0,     0,     0,     0,    19,
       0,     0,     0,    49,    17,    18,     0,     0,   103,    20,
      21,    19,     0,    22,     0,     0,    23,    24,    25,    17,
      18,    20,    21,     0,     0,    22,    19,     0,    23,    24,
      25,    17,    18,     0,     0,     0,    20,    21,    19,     0,
      22,     0,     0,    23,    24,    25,    62,     0,    20,    21,
       0,   104,    22,     0,   105,    23,    24,    25,    17,    18,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,    17,    18,     0,     0,    20,    21,   106,    19,    22,
       0,     0,    23,    24,    25,     0,    17,    18,    20,    21,
       0,   112,    22,    19,     0,    23,    24,    25,    17,    18,
       0,     0,     0,    20,    21,    19,     0,    22,     0,     0,
      23,    24,    25,     0,     0,    20,    61,     0,     0,    22,
       0,     0,    23,    24,    25,    67,    68,    69,    70,     0,
       0,    82,     0,     0,    71,    72,    73,    74,    75,    76,
      69,    70,     0,     0,     0,     0,     0,    71,    72,    73,
      74,    75,    76
};

static const yytype_int8 yycheck[] =
{
      11,    22,    33,    26,    25,    11,    12,     0,    13,    15,
      13,    22,     3,    12,    25,    26,    43,    44,    34,    35,
      36,    13,    45,    26,    51,    48,    34,    35,    36,    56,
      41,    13,    37,    39,    45,    20,    21,    48,    39,    39,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      39,    39,    13,    80,    81,     7,     8,     9,    10,    14,
      13,    12,    12,    40,    16,    17,    18,    19,    20,    21,
      39,    39,    13,    13,    13,    96,    97,   100,   101,    27,
      26,    13,    13,    13,   105,    96,    97,   110,    40,   100,
     101,     7,    -1,    -1,   105,     7,     8,     9,    10,   110,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    40,    16,
      17,    18,    19,    20,    21,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    40,    16,    17,    18,    19,    20,    21,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    40,    16,
      17,    18,    19,    20,    21,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    40,    16,    17,    18,    19,    20,    21,
      -1,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,     4,     5,     6,    -1,    -1,    40,    22,
      23,    12,    -1,    26,    -1,    -1,    29,    30,    31,     5,
       6,    22,    23,    -1,    -1,    26,    12,    -1,    29,    30,
      31,     5,     6,    -1,    -1,    -1,    22,    23,    12,    -1,
      26,    -1,    -1,    29,    30,    31,    32,    -1,    22,    23,
      -1,    25,    26,    -1,    28,    29,    30,    31,     5,     6,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,     5,     6,    -1,    -1,    22,    23,    24,    12,    26,
      -1,    -1,    29,    30,    31,    -1,     5,     6,    22,    23,
      -1,    25,    26,    12,    -1,    29,    30,    31,     5,     6,
      -1,    -1,    -1,    22,    23,    12,    -1,    26,    -1,    -1,
      29,    30,    31,    -1,    -1,    22,    23,    -1,    -1,    26,
      -1,    -1,    29,    30,    31,     7,     8,     9,    10,    -1,
      -1,    13,    -1,    -1,    16,    17,    18,    19,    20,    21,
       9,    10,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    42,    43,    34,    35,    36,    44,    45,    46,
       0,     3,    34,    45,    12,    47,     4,     5,     6,    12,
      22,    23,    26,    29,    30,    31,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    60,    13,    37,
      13,    39,    39,    39,    39,    48,    13,    13,    48,     4,
      49,    14,    12,    60,    11,    15,    39,    59,    60,    59,
      59,    23,    32,    13,    59,    40,    59,     7,     8,     9,
      10,    16,    17,    18,    19,    20,    21,    40,    40,    40,
      39,    39,    13,    13,    40,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    13,    27,    26,    59,    59,
      48,    48,    40,    40,    25,    28,    24,    13,    13,    13,
      48,    13,    25,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    44,    45,    46,
      46,    47,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    50,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     2,     2,     1,     3,     1,
       1,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,    10,     8,     8,     2,     2,     7,
       7,     5,     5,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: Declarations KW_BEGIN Slist END SEMI  */
#line 36 "parser.y"
                                               {
    (yyval.node) = (yyvsp[-2].node);
    print((yyvsp[-2].node));
    initialize();
    codegen((yyvsp[-2].node)); 
    generateExitCode();
    printSymbolTable();
    exit(0);}
#line 1379 "y.tab.c"
    break;

  case 3: /* program: Declarations KW_BEGIN END SEMI  */
#line 44 "parser.y"
                                    { (yyval.node)=NULL;}
#line 1385 "y.tab.c"
    break;

  case 9: /* Type: T_INT  */
#line 59 "parser.y"
             {declaration_type=INT;}
#line 1391 "y.tab.c"
    break;

  case 10: /* Type: T_STR  */
#line 60 "parser.y"
            {declaration_type=STRING;}
#line 1397 "y.tab.c"
    break;

  case 11: /* VarList: VarList COMMA ID  */
#line 63 "parser.y"
                           {install((yyvsp[0].node)->varname, declaration_type, 1);}
#line 1403 "y.tab.c"
    break;

  case 12: /* VarList: ID  */
#line 64 "parser.y"
             {install((yyvsp[0].node)->varname,declaration_type,1);}
#line 1409 "y.tab.c"
    break;

  case 13: /* Slist: Slist Stmt  */
#line 67 "parser.y"
                   {(yyval.node)=createTree(1,0,CONNECTOR_NODE,NULL,(yyvsp[-1].node),(yyvsp[0].node),NULL);}
#line 1415 "y.tab.c"
    break;

  case 14: /* Slist: Stmt  */
#line 68 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 1421 "y.tab.c"
    break;

  case 15: /* Stmt: InputStmt  */
#line 71 "parser.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 1427 "y.tab.c"
    break;

  case 16: /* Stmt: OutputStmt  */
#line 72 "parser.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 1433 "y.tab.c"
    break;

  case 17: /* Stmt: AsgStmt  */
#line 73 "parser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 1439 "y.tab.c"
    break;

  case 18: /* Stmt: IfStmt  */
#line 74 "parser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 1445 "y.tab.c"
    break;

  case 19: /* Stmt: WhileStmt  */
#line 75 "parser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 1451 "y.tab.c"
    break;

  case 20: /* Stmt: BrkStmt  */
#line 76 "parser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 1457 "y.tab.c"
    break;

  case 21: /* Stmt: ContStmt  */
#line 77 "parser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 1463 "y.tab.c"
    break;

  case 22: /* Stmt: repeatUntilStmt  */
#line 78 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1469 "y.tab.c"
    break;

  case 23: /* Stmt: doWhileStmt  */
#line 79 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1475 "y.tab.c"
    break;

  case 24: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF SEMI  */
#line 84 "parser.y"
                                                          {
            typecheck((yyvsp[-7].node)->type, BOOL, 'e');
            (yyval.node) = createTree(NONE, 0, IF_ELSE_NODE, NULL, (yyvsp[-7].node), (yyvsp[-2].node), (yyvsp[-4].node));
            }
#line 1484 "y.tab.c"
    break;

  case 25: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF SEMI  */
#line 88 "parser.y"
                                           {
            typecheck((yyvsp[-5].node)->type, BOOL, 'i');
            (yyval.node) = createTree(NONE, 0, IF_NODE, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
            }
#line 1493 "y.tab.c"
    break;

  case 26: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE SEMI  */
#line 94 "parser.y"
{
            typecheck((yyvsp[-5].node)->type, BOOL, 'e');
            (yyval.node) = createTree(NONE, 0, WHILE_NODE, NULL, (yyvsp[-5].node), (yyvsp[-2].node),NULL);
            }
#line 1502 "y.tab.c"
    break;

  case 27: /* BrkStmt: BREAK SEMI  */
#line 98 "parser.y"
                     {(yyval.node) = createTree(NONE, 0, BREAK_NODE, NULL, NULL, NULL, NULL);}
#line 1508 "y.tab.c"
    break;

  case 28: /* ContStmt: CONT SEMI  */
#line 100 "parser.y"
                     {(yyval.node) = createTree(NONE, 0, CONT_NODE, NULL, NULL, NULL, NULL);}
#line 1514 "y.tab.c"
    break;

  case 29: /* repeatUntilStmt: REPEAT Slist UNTIL '(' expr ')' SEMI  */
#line 101 "parser.y"
                                                      { (yyval.node) = createTree(NONE,0,REPEAT_NODE,NULL,(yyvsp[-5].node), (yyvsp[-2].node),NULL); }
#line 1520 "y.tab.c"
    break;

  case 30: /* doWhileStmt: DO Slist WHILE '(' expr ')' SEMI  */
#line 104 "parser.y"
                                              { (yyval.node) = createTree(NONE,0,DOWHILE_NODE,NULL,(yyvsp[-5].node), (yyvsp[-2].node),NULL); }
#line 1526 "y.tab.c"
    break;

  case 31: /* InputStmt: READ '(' id ')' SEMI  */
#line 108 "parser.y"
                                 { 
                (yyval.node)=createTree(NONE,0,READ_NODE,NULL,(yyvsp[-2].node),NULL,NULL);}
#line 1533 "y.tab.c"
    break;

  case 32: /* OutputStmt: WRITE '(' expr ')' SEMI  */
#line 111 "parser.y"
                                     {(yyval.node)=createTree(NONE,0,WRITE_NODE,NULL,(yyvsp[-2].node),NULL,NULL);}
#line 1539 "y.tab.c"
    break;

  case 33: /* AsgStmt: id ASSIGN expr SEMI  */
#line 113 "parser.y"
                              {
            typecheck((yyvsp[-3].node)->type, (yyvsp[-1].node)->type, '=');
            (yyvsp[-3].node)->type = (yyvsp[-1].node)->type;
            (yyval.node)=createTree(NONE,0,ASSIGN_NODE,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);}
#line 1548 "y.tab.c"
    break;

  case 34: /* expr: expr PLUS expr  */
#line 119 "parser.y"
                      { 
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'a');
        (yyval.node) = createTree(1,0,ADD_NODE,NULL, (yyvsp[-2].node), (yyvsp[0].node),NULL); 
        (yyval.node)->type = INT;
        }
#line 1558 "y.tab.c"
    break;

  case 35: /* expr: expr MINUS expr  */
#line 124 "parser.y"
                      {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'a'); 
        (yyval.node) = createTree(1,0,SUB_NODE,NULL, (yyvsp[-2].node), (yyvsp[0].node),NULL); 
        (yyval.node)->type = INT;
        }
#line 1568 "y.tab.c"
    break;

  case 36: /* expr: expr MUL expr  */
#line 129 "parser.y"
                    {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'a');
        (yyval.node) = createTree(1,0,MUL_NODE,NULL, (yyvsp[-2].node), (yyvsp[0].node),NULL); 
        (yyval.node)->type = INT;
        }
#line 1578 "y.tab.c"
    break;

  case 37: /* expr: expr DIV expr  */
#line 134 "parser.y"
                    {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'a');
        (yyval.node) = createTree(1,0,DIV_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
        (yyval.node)->type = INT;
        }
#line 1588 "y.tab.c"
    break;

  case 38: /* expr: expr LT expr  */
#line 139 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'b'); 
        (yyval.node) = createTree(BOOL,0,LT_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1596 "y.tab.c"
    break;

  case 39: /* expr: expr GT expr  */
#line 142 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'b'); 
        (yyval.node) = createTree(BOOL,0,GT_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1604 "y.tab.c"
    break;

  case 40: /* expr: expr LE expr  */
#line 145 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'b'); 
        (yyval.node) = createTree(BOOL,0,LE_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1612 "y.tab.c"
    break;

  case 41: /* expr: expr GE expr  */
#line 148 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'b'); 
        (yyval.node) = createTree(BOOL,0,GE_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1620 "y.tab.c"
    break;

  case 42: /* expr: expr NE expr  */
#line 151 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'b'); 
        (yyval.node) = createTree(BOOL,0,NE_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1628 "y.tab.c"
    break;

  case 43: /* expr: expr EQ expr  */
#line 154 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'b'); 
        (yyval.node) = createTree(BOOL,0,EQ_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1636 "y.tab.c"
    break;

  case 44: /* expr: '(' expr ')'  */
#line 157 "parser.y"
                   { (yyval.node) = (yyvsp[-1].node); }
#line 1642 "y.tab.c"
    break;

  case 45: /* expr: NUM  */
#line 158 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1648 "y.tab.c"
    break;

  case 46: /* expr: STRVAL  */
#line 159 "parser.y"
             {(yyval.node) = (yyvsp[0].node);}
#line 1654 "y.tab.c"
    break;

  case 47: /* expr: id  */
#line 160 "parser.y"
         { (yyval.node)=(yyvsp[0].node); }
#line 1660 "y.tab.c"
    break;

  case 48: /* id: ID  */
#line 162 "parser.y"
       {
    (yyvsp[0].node)->Gentry=lookup((yyvsp[0].node)->varname);
    if((yyvsp[0].node)->Gentry==NULL){
        printf("variable %s not declared\n",(yyvsp[0].node)->varname);
        exit(1);
    }
    (yyvsp[0].node)->type=(yyvsp[0].node)->Gentry->type;
    (yyval.node)=(yyvsp[0].node);
}
#line 1674 "y.tab.c"
    break;


#line 1678 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 172 "parser.y"


void yyerror(char const *msg) {
    printf("[Error] : %s\n", msg);
    return;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <sourcefile>\n", argv[0]);
        return 1;
    }

    FILE *source_file = fopen(argv[1], "r");
    if (source_file == NULL) {
        perror("Error opening source file");
        return 1;
    }

    yyin = source_file;
    return yyparse();
}
