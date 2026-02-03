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
# define YYDEBUG 1
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
    LBRACK = 293,                  /* LBRACK  */
    RBRACK = 294,                  /* RBRACK  */
    AND = 295,                     /* AND  */
    ASSGN = 296                    /* ASSGN  */
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
#define LBRACK 293
#define RBRACK 294
#define AND 295
#define ASSGN 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

    struct tnode *node;

#line 225 "y.tab.c"

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
  YYSYMBOL_LBRACK = 38,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 39,                    /* RBRACK  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_ASSGN = 41,                     /* ASSGN  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_Declarations = 46,              /* Declarations  */
  YYSYMBOL_DeclList = 47,                  /* DeclList  */
  YYSYMBOL_Decl = 48,                      /* Decl  */
  YYSYMBOL_Type = 49,                      /* Type  */
  YYSYMBOL_VarList = 50,                   /* VarList  */
  YYSYMBOL_Slist = 51,                     /* Slist  */
  YYSYMBOL_Stmt = 52,                      /* Stmt  */
  YYSYMBOL_IfStmt = 53,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 54,                 /* WhileStmt  */
  YYSYMBOL_BrkStmt = 55,                   /* BrkStmt  */
  YYSYMBOL_ContStmt = 56,                  /* ContStmt  */
  YYSYMBOL_repeatUntilStmt = 57,           /* repeatUntilStmt  */
  YYSYMBOL_doWhileStmt = 58,               /* doWhileStmt  */
  YYSYMBOL_InputStmt = 59,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 60,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 61,                   /* AsgStmt  */
  YYSYMBOL_lvalue = 62,                    /* lvalue  */
  YYSYMBOL_expr = 63,                      /* expr  */
  YYSYMBOL_id = 64                         /* id  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      42,    43,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    46,    50,    51,    54,    55,    58,    61,
      62,    65,    66,    67,    68,    69,    75,    83,    84,    87,
      88,    89,    90,    91,    92,    93,    94,    95,   100,   104,
     109,   114,   116,   117,   120,   124,   127,   129,   135,   136,
     147,   152,   157,   162,   167,   170,   173,   176,   179,   182,
     185,   186,   187,   188,   189,   200,   212,   221,   234
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
  "UNTIL", "DECL", "ENDDECL", "T_INT", "T_STR", "COMMA", "LBRACK",
  "RBRACK", "AND", "ASSGN", "'('", "')'", "$accept", "program",
  "Declarations", "DeclList", "Decl", "Type", "VarList", "Slist", "Stmt",
  "IfStmt", "WhileStmt", "BrkStmt", "ContStmt", "repeatUntilStmt",
  "doWhileStmt", "InputStmt", "OutputStmt", "AsgStmt", "lvalue", "expr",
  "id", YY_NULLPTR
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
     -31,    -3,    20,    23,   -32,   -32,   -32,    50,   -32,    -5,
     -32,   188,   -32,   -32,    17,    -4,   -10,    27,     0,    11,
      42,    18,    29,    32,   293,    62,    74,   293,   200,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,    83,
     -32,   -32,    77,   -32,    12,   -32,    42,     3,   -32,    -1,
       3,     3,   308,   -32,   -32,   215,    87,   -32,     3,    63,
      89,    66,    67,    42,   -32,   -32,    42,     3,    60,   -32,
      70,    75,   110,   125,    71,    80,   -32,   333,   -32,   -32,
     104,   111,   -32,   -32,   140,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,   112,   -32,   -32,    96,   113,
       3,     3,   -32,    97,   -32,   -32,    73,    73,    30,    30,
     251,   251,   251,   251,    16,    16,   -32,   293,   293,   155,
     170,   -32,   227,   254,    -7,   124,   127,   293,   138,   -32,
     -32,   -32,   281,   -32,   139,   -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     5,     9,    10,     0,     7,     0,
       1,     0,     4,     6,     0,    12,     0,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,    18,
      22,    23,    24,    25,    26,    27,    19,    20,    21,     0,
      38,    16,     0,     8,     0,     3,     0,     0,    39,     0,
       0,     0,     0,    31,    32,     0,     0,    17,     0,     0,
       0,    11,     0,     0,    51,    52,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     2,     0,    14,    15,
       0,     0,    55,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,    58,     0,     0,
       0,     0,    37,     0,    35,    50,    40,    41,    42,    43,
      46,    44,    47,    45,    48,    49,    36,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,     0,    34,
      33,    29,     0,    30,     0,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -32,   -32,   -32,   -32,   131,   -32,   -32,   -19,   -27,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -28,
     -11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     7,     8,     9,    16,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    68,
      69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    57,     1,    43,    14,    52,   129,    15,    55,    48,
      70,    21,    63,    40,    64,    21,    40,    40,    65,   118,
      10,    60,    72,    73,    61,    57,    11,    44,    57,    41,
      77,     4,     5,     6,    42,    62,    93,    94,    71,    84,
      45,    40,    46,    66,    40,    67,    89,    90,    91,    92,
      93,    94,    82,    47,    21,    83,    49,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    85,    86,    87,
      88,    50,   119,   120,    51,    53,    89,    90,    91,    92,
      93,    94,    87,    88,    12,     5,     6,    54,    59,    89,
      90,    91,    92,    93,    94,    57,    57,    58,   122,   123,
      76,    79,    78,    95,    80,    57,    40,    40,   132,    96,
      81,    40,    40,   100,    97,   103,    40,    85,    86,    87,
      88,    40,   101,   117,   104,   116,    89,    90,    91,    92,
      93,    94,    85,    86,    87,    88,   121,   130,    13,   118,
     131,    89,    90,    91,    92,    93,    94,    85,    86,    87,
      88,   133,   135,    98,     0,     0,    89,    90,    91,    92,
      93,    94,    85,    86,    87,    88,     0,     0,    99,     0,
       0,    89,    90,    91,    92,    93,    94,    85,    86,    87,
      88,     0,     0,   105,     0,     0,    89,    90,    91,    92,
      93,    94,    17,    18,    19,     0,     0,    20,   124,     0,
      21,     0,     0,     0,    56,    18,    19,     0,     0,    20,
      22,    23,    21,   125,    24,     0,     0,    25,    26,    27,
      18,    19,    22,    23,    20,     0,    24,    21,     0,    25,
      26,    27,    18,    19,     0,     0,    20,    22,    23,    21,
       0,    24,     0,     0,    25,    26,    27,    75,     0,    22,
      23,     0,   126,    24,     0,   127,    25,    26,    27,    18,
      19,     0,     0,    20,     0,     0,    21,    -1,    -1,    -1,
      -1,    93,    94,     0,     0,     0,    22,    23,   128,     0,
      24,     0,     0,    25,    26,    27,    18,    19,     0,     0,
      20,     0,     0,    21,     0,     0,     0,     0,    18,    19,
       0,     0,    20,    22,    23,    21,   134,    24,     0,     0,
      25,    26,    27,    18,    19,    22,    23,    20,     0,    24,
      21,     0,    25,    26,    27,     0,     0,     0,     0,     0,
      22,    74,     0,     0,    24,     0,     0,    25,    26,    27,
      85,    86,    87,    88,     0,     0,   102,     0,     0,    89,
      90,    91,    92,    93,    94
};

static const yytype_int16 yycheck[] =
{
      11,    28,    33,    13,     9,    24,    13,    12,    27,    20,
      11,    12,     9,    24,    11,    12,    27,    28,    15,    26,
       0,     9,    50,    51,    12,    52,     3,    37,    55,    12,
      58,    34,    35,    36,    38,    46,    20,    21,    49,    67,
      13,    52,    42,    40,    55,    42,    16,    17,    18,    19,
      20,    21,    63,    42,    12,    66,    38,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     7,     8,     9,
      10,    42,   100,   101,    42,    13,    16,    17,    18,    19,
      20,    21,     9,    10,    34,    35,    36,    13,    11,    16,
      17,    18,    19,    20,    21,   122,   123,    14,   117,   118,
      13,    12,    39,    43,    38,   132,   117,   118,   127,    39,
      43,   122,   123,    42,    39,    11,   127,     7,     8,     9,
      10,   132,    42,    27,    13,    13,    16,    17,    18,    19,
      20,    21,     7,     8,     9,    10,    39,    13,     7,    26,
      13,    16,    17,    18,    19,    20,    21,     7,     8,     9,
      10,    13,    13,    43,    -1,    -1,    16,    17,    18,    19,
      20,    21,     7,     8,     9,    10,    -1,    -1,    43,    -1,
      -1,    16,    17,    18,    19,    20,    21,     7,     8,     9,
      10,    -1,    -1,    43,    -1,    -1,    16,    17,    18,    19,
      20,    21,     4,     5,     6,    -1,    -1,     9,    43,    -1,
      12,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,     9,
      22,    23,    12,    43,    26,    -1,    -1,    29,    30,    31,
       5,     6,    22,    23,     9,    -1,    26,    12,    -1,    29,
      30,    31,     5,     6,    -1,    -1,     9,    22,    23,    12,
      -1,    26,    -1,    -1,    29,    30,    31,    32,    -1,    22,
      23,    -1,    25,    26,    -1,    28,    29,    30,    31,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    -1,    -1,    29,    30,    31,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    -1,    -1,    -1,    -1,     5,     6,
      -1,    -1,     9,    22,    23,    12,    25,    26,    -1,    -1,
      29,    30,    31,     5,     6,    22,    23,     9,    -1,    26,
      12,    -1,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    26,    -1,    -1,    29,    30,    31,
       7,     8,     9,    10,    -1,    -1,    13,    -1,    -1,    16,
      17,    18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    45,    46,    34,    35,    36,    47,    48,    49,
       0,     3,    34,    48,     9,    12,    50,     4,     5,     6,
       9,    12,    22,    23,    26,    29,    30,    31,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      64,    12,    38,    13,    37,    13,    42,    42,    64,    38,
      42,    42,    51,    13,    13,    51,     4,    52,    14,    11,
       9,    12,    64,     9,    11,    15,    40,    42,    63,    64,
      11,    64,    63,    63,    23,    32,    13,    63,    39,    12,
      38,    43,    64,    64,    63,     7,     8,     9,    10,    16,
      17,    18,    19,    20,    21,    43,    39,    39,    43,    43,
      42,    42,    13,    11,    13,    43,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    13,    27,    26,    63,
      63,    39,    51,    51,    43,    43,    25,    28,    24,    13,
      13,    13,    51,    13,    25,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    47,    47,    48,    49,
      49,    50,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     2,     2,     1,     3,     1,
       1,     3,     1,     6,     4,     4,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,    10,     8,
       8,     2,     2,     7,     7,     5,     5,     4,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     2,     2,     1,     4,     4
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
#line 38 "parser.y"
                                               {
    (yyval.node) = (yyvsp[-2].node);
    print((yyvsp[-2].node));
    initialize();
    codegen((yyvsp[-2].node)); 
    generateExitCode();
    printSymbolTable();
    exit(0);}
#line 1401 "y.tab.c"
    break;

  case 3: /* program: Declarations KW_BEGIN END SEMI  */
#line 46 "parser.y"
                                    { (yyval.node)=NULL;}
#line 1407 "y.tab.c"
    break;

  case 9: /* Type: T_INT  */
#line 61 "parser.y"
             {declaration_type=INT;}
#line 1413 "y.tab.c"
    break;

  case 10: /* Type: T_STR  */
#line 62 "parser.y"
            {declaration_type=STRING;}
#line 1419 "y.tab.c"
    break;

  case 11: /* VarList: VarList COMMA ID  */
#line 65 "parser.y"
                           {install((yyvsp[0].node)->varname, declaration_type, 1);}
#line 1425 "y.tab.c"
    break;

  case 12: /* VarList: ID  */
#line 66 "parser.y"
             {install((yyvsp[0].node)->varname,declaration_type,1);}
#line 1431 "y.tab.c"
    break;

  case 13: /* VarList: VarList COMMA ID LBRACK NUM RBRACK  */
#line 67 "parser.y"
                                             {install((yyvsp[-3].node)->varname,declaration_type,(yyvsp[-1].node)->val);}
#line 1437 "y.tab.c"
    break;

  case 14: /* VarList: ID LBRACK NUM RBRACK  */
#line 68 "parser.y"
                               {install((yyvsp[-3].node)->varname,declaration_type,(yyvsp[-1].node)->val);}
#line 1443 "y.tab.c"
    break;

  case 15: /* VarList: VarList COMMA MUL ID  */
#line 69 "parser.y"
                               {
            if (declaration_type == INT)
                install((yyvsp[0].node)->varname, INT_PTR, 1);
            else
                install((yyvsp[0].node)->varname, STR_PTR, 1);
        }
#line 1454 "y.tab.c"
    break;

  case 16: /* VarList: MUL ID  */
#line 75 "parser.y"
                 {
            if (declaration_type == INT)
                install((yyvsp[0].node)->varname, INT_PTR, 1);
            else
                install((yyvsp[0].node)->varname, STR_PTR, 1);
        }
#line 1465 "y.tab.c"
    break;

  case 17: /* Slist: Slist Stmt  */
#line 83 "parser.y"
                   {(yyval.node)=createTree(1,0,CONNECTOR_NODE,NULL,(yyvsp[-1].node),(yyvsp[0].node),NULL);}
#line 1471 "y.tab.c"
    break;

  case 18: /* Slist: Stmt  */
#line 84 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 1477 "y.tab.c"
    break;

  case 19: /* Stmt: InputStmt  */
#line 87 "parser.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 1483 "y.tab.c"
    break;

  case 20: /* Stmt: OutputStmt  */
#line 88 "parser.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 1489 "y.tab.c"
    break;

  case 21: /* Stmt: AsgStmt  */
#line 89 "parser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 1495 "y.tab.c"
    break;

  case 22: /* Stmt: IfStmt  */
#line 90 "parser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 1501 "y.tab.c"
    break;

  case 23: /* Stmt: WhileStmt  */
#line 91 "parser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 1507 "y.tab.c"
    break;

  case 24: /* Stmt: BrkStmt  */
#line 92 "parser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 1513 "y.tab.c"
    break;

  case 25: /* Stmt: ContStmt  */
#line 93 "parser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 1519 "y.tab.c"
    break;

  case 26: /* Stmt: repeatUntilStmt  */
#line 94 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1525 "y.tab.c"
    break;

  case 27: /* Stmt: doWhileStmt  */
#line 95 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1531 "y.tab.c"
    break;

  case 28: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF SEMI  */
#line 100 "parser.y"
                                                          {
            typecheck((yyvsp[-7].node)->type, BOOL, 'e');
            (yyval.node) = createTree(NONE, 0, IF_ELSE_NODE, NULL, (yyvsp[-7].node), (yyvsp[-2].node), (yyvsp[-4].node));
            }
#line 1540 "y.tab.c"
    break;

  case 29: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF SEMI  */
#line 104 "parser.y"
                                           {
            typecheck((yyvsp[-5].node)->type, BOOL, 'i');
            (yyval.node) = createTree(NONE, 0, IF_NODE, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
            }
#line 1549 "y.tab.c"
    break;

  case 30: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE SEMI  */
#line 110 "parser.y"
{
            typecheck((yyvsp[-5].node)->type, BOOL, 'e');
            (yyval.node) = createTree(NONE, 0, WHILE_NODE, NULL, (yyvsp[-5].node), (yyvsp[-2].node),NULL);
            }
#line 1558 "y.tab.c"
    break;

  case 31: /* BrkStmt: BREAK SEMI  */
#line 114 "parser.y"
                     {(yyval.node) = createTree(NONE, 0, BREAK_NODE, NULL, NULL, NULL, NULL);}
#line 1564 "y.tab.c"
    break;

  case 32: /* ContStmt: CONT SEMI  */
#line 116 "parser.y"
                     {(yyval.node) = createTree(NONE, 0, CONT_NODE, NULL, NULL, NULL, NULL);}
#line 1570 "y.tab.c"
    break;

  case 33: /* repeatUntilStmt: REPEAT Slist UNTIL '(' expr ')' SEMI  */
#line 117 "parser.y"
                                                      { (yyval.node) = createTree(NONE,0,REPEAT_NODE,NULL,(yyvsp[-5].node), (yyvsp[-2].node),NULL); }
#line 1576 "y.tab.c"
    break;

  case 34: /* doWhileStmt: DO Slist WHILE '(' expr ')' SEMI  */
#line 120 "parser.y"
                                              { (yyval.node) = createTree(NONE,0,DOWHILE_NODE,NULL,(yyvsp[-5].node), (yyvsp[-2].node),NULL); }
#line 1582 "y.tab.c"
    break;

  case 35: /* InputStmt: READ '(' id ')' SEMI  */
#line 124 "parser.y"
                                 { 
                (yyval.node)=createTree(NONE,0,READ_NODE,NULL,(yyvsp[-2].node),NULL,NULL);}
#line 1589 "y.tab.c"
    break;

  case 36: /* OutputStmt: WRITE '(' expr ')' SEMI  */
#line 127 "parser.y"
                                     {(yyval.node)=createTree(NONE,0,WRITE_NODE,NULL,(yyvsp[-2].node),NULL,NULL);}
#line 1595 "y.tab.c"
    break;

  case 37: /* AsgStmt: lvalue ASSIGN expr SEMI  */
#line 129 "parser.y"
                                  {
            typecheck((yyvsp[-3].node)->type, (yyvsp[-1].node)->type, '=');
            (yyvsp[-3].node)->type = (yyvsp[-1].node)->type;
            (yyval.node)=createTree(NONE,0,ASSIGN_NODE,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);}
#line 1604 "y.tab.c"
    break;

  case 38: /* lvalue: id  */
#line 135 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1610 "y.tab.c"
    break;

  case 39: /* lvalue: MUL id  */
#line 136 "parser.y"
             {
        if ((yyvsp[0].node)->type != INT_PTR && (yyvsp[0].node)->type != STR_PTR) {
            printf("dereferencing non-pointer\n");
            exit(1);
        }

        int t = ((yyvsp[0].node)->type == INT_PTR) ? INT : STRING;
        (yyval.node) = createTree(t, 0, DEREF_NODE, NULL, (yyvsp[0].node), NULL, NULL);
    }
#line 1624 "y.tab.c"
    break;

  case 40: /* expr: expr PLUS expr  */
#line 147 "parser.y"
                      { 
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'a');
        (yyval.node) = createTree(1,0,ADD_NODE,NULL, (yyvsp[-2].node), (yyvsp[0].node),NULL); 
        (yyval.node)->type = INT;
        }
#line 1634 "y.tab.c"
    break;

  case 41: /* expr: expr MINUS expr  */
#line 152 "parser.y"
                      {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'a'); 
        (yyval.node) = createTree(1,0,SUB_NODE,NULL, (yyvsp[-2].node), (yyvsp[0].node),NULL); 
        (yyval.node)->type = INT;
        }
#line 1644 "y.tab.c"
    break;

  case 42: /* expr: expr MUL expr  */
#line 157 "parser.y"
                    {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'a');
        (yyval.node) = createTree(1,0,MUL_NODE,NULL, (yyvsp[-2].node), (yyvsp[0].node),NULL); 
        (yyval.node)->type = INT;
        }
#line 1654 "y.tab.c"
    break;

  case 43: /* expr: expr DIV expr  */
#line 162 "parser.y"
                    {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'a');
        (yyval.node) = createTree(1,0,DIV_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
        (yyval.node)->type = INT;
        }
#line 1664 "y.tab.c"
    break;

  case 44: /* expr: expr LT expr  */
#line 167 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'b'); 
        (yyval.node) = createTree(BOOL,0,LT_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1672 "y.tab.c"
    break;

  case 45: /* expr: expr GT expr  */
#line 170 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'b'); 
        (yyval.node) = createTree(BOOL,0,GT_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1680 "y.tab.c"
    break;

  case 46: /* expr: expr LE expr  */
#line 173 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'b'); 
        (yyval.node) = createTree(BOOL,0,LE_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1688 "y.tab.c"
    break;

  case 47: /* expr: expr GE expr  */
#line 176 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'b'); 
        (yyval.node) = createTree(BOOL,0,GE_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1696 "y.tab.c"
    break;

  case 48: /* expr: expr NE expr  */
#line 179 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'b'); 
        (yyval.node) = createTree(BOOL,0,NE_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1704 "y.tab.c"
    break;

  case 49: /* expr: expr EQ expr  */
#line 182 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type,(yyvsp[0].node)->type,'b'); 
        (yyval.node) = createTree(BOOL,0,EQ_NODE,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1712 "y.tab.c"
    break;

  case 50: /* expr: '(' expr ')'  */
#line 185 "parser.y"
                   { (yyval.node) = (yyvsp[-1].node); }
#line 1718 "y.tab.c"
    break;

  case 51: /* expr: NUM  */
#line 186 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1724 "y.tab.c"
    break;

  case 52: /* expr: STRVAL  */
#line 187 "parser.y"
             {(yyval.node) = (yyvsp[0].node);}
#line 1730 "y.tab.c"
    break;

  case 53: /* expr: id  */
#line 188 "parser.y"
         { (yyval.node)=(yyvsp[0].node); }
#line 1736 "y.tab.c"
    break;

  case 54: /* expr: AND id  */
#line 189 "parser.y"
             {if ((yyvsp[0].node)->type == INT)
                    (yyval.node)->type = INT_PTR;
                else if ((yyvsp[0].node)->type == STRING)
                    (yyval.node)->type = STR_PTR;
                else{
                    printf("addressing error\n");
                    exit(1);
                    }

            (yyval.node)=createTree((yyval.node)->type,0,ADDR_NODE,NULL,(yyvsp[0].node),NULL,NULL);
    }
#line 1752 "y.tab.c"
    break;

  case 55: /* expr: MUL id  */
#line 200 "parser.y"
             {if ((yyvsp[0].node)->type == INT_PTR)
                    (yyval.node)->type = INT;
                else if ((yyvsp[0].node)->type == STR_PTR)
                    (yyval.node)->type = STRING;
                else{
                    printf("dereferencing error\n");
                    exit(1);
                }
            (yyval.node)=createTree((yyval.node)->type,0,DEREF_NODE,NULL,(yyvsp[0].node),NULL,NULL);

    }
#line 1768 "y.tab.c"
    break;

  case 56: /* id: ID  */
#line 212 "parser.y"
       {
    (yyvsp[0].node)->Gentry=lookup((yyvsp[0].node)->varname);
    if((yyvsp[0].node)->Gentry==NULL){
        printf("variable %s not declared\n",(yyvsp[0].node)->varname);
        exit(1);
    }
    (yyvsp[0].node)->type=(yyvsp[0].node)->Gentry->type;
    (yyval.node)=(yyvsp[0].node);
    }
#line 1782 "y.tab.c"
    break;

  case 57: /* id: ID LBRACK NUM RBRACK  */
#line 221 "parser.y"
                           {
        (yyvsp[-3].node)->Gentry=lookup((yyvsp[-3].node)->varname);
        if((yyvsp[-3].node)->Gentry==NULL){
            printf("variable %s not declared\n",(yyvsp[-3].node)->varname);
            exit(1);
        }
        else if((yyvsp[-1].node)->val>=(yyvsp[-3].node)->Gentry->size || (yyvsp[-1].node)->val < 0){
            printf("Array %s out of bounds\n",(yyvsp[-3].node)->varname);
            exit(1);
        }
        (yyvsp[-3].node)->type=(yyvsp[-3].node)->Gentry->type;
        (yyval.node)=createTree((yyvsp[-3].node)->type,0,ARRAY_NODE,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
    }
#line 1800 "y.tab.c"
    break;

  case 58: /* id: ID LBRACK id RBRACK  */
#line 234 "parser.y"
                         {
        (yyvsp[-3].node)->Gentry=lookup((yyvsp[-3].node)->varname);
        if((yyvsp[-3].node)->Gentry==NULL){
            printf("variable %s not declared\n",(yyvsp[-3].node)->varname);
            exit(1);
        }
        (yyvsp[-3].node)->type=(yyvsp[-3].node)->Gentry->type;
        (yyval.node)=createTree((yyvsp[-3].node)->type,0,ARRAY_NODE,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
    }
#line 1814 "y.tab.c"
    break;


#line 1818 "y.tab.c"

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

#line 244 "parser.y"


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
