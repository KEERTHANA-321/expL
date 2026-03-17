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
#line 1 "first.y"


    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbolTable.h"
    #include "constants.h"
    #include "nodestructure.h"
    #include "typecheck.h"
    int yylex(void);
    void yyerror(char const *msg);
    extern FILE *yyin;
    FILE *out;
    extern int yylineno;
    extern char *yytext;
    struct Paramstruct *argList1, *argList2;
    int declCount = 0, defCount = 0;
    int current_function_type = 0;
    int testing=1;

#line 92 "y.tab.c"

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
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    MUL = 260,                     /* MUL  */
    DIV = 261,                     /* DIV  */
    MOD = 262,                     /* MOD  */
    LT = 263,                      /* LT  */
    GT = 264,                      /* GT  */
    LE = 265,                      /* LE  */
    GE = 266,                      /* GE  */
    NE = 267,                      /* NE  */
    EQ = 268,                      /* EQ  */
    ASSIGN = 269,                  /* ASSIGN  */
    DO = 270,                      /* DO  */
    IF = 271,                      /* IF  */
    ELSE = 272,                    /* ELSE  */
    WHILE = 273,                   /* WHILE  */
    BREAK = 274,                   /* BREAK  */
    CONT = 275,                    /* CONT  */
    KW_BEGIN = 276,                /* KW_BEGIN  */
    END = 277,                     /* END  */
    ENDIF = 278,                   /* ENDIF  */
    THEN = 279,                    /* THEN  */
    ENDWHILE = 280,                /* ENDWHILE  */
    REPEAT = 281,                  /* REPEAT  */
    UNTIL = 282,                   /* UNTIL  */
    NUM = 283,                     /* NUM  */
    STRVAL = 284,                  /* STRVAL  */
    ID = 285,                      /* ID  */
    READ = 286,                    /* READ  */
    WRITE = 287,                   /* WRITE  */
    DECL = 288,                    /* DECL  */
    ENDDECL = 289,                 /* ENDDECL  */
    T_INT = 290,                   /* T_INT  */
    T_STR = 291,                   /* T_STR  */
    COMMA = 292,                   /* COMMA  */
    MAIN = 293,                    /* MAIN  */
    SEMI = 294,                    /* SEMI  */
    RETURN = 295,                  /* RETURN  */
    LBRACE = 296,                  /* LBRACE  */
    RBRACE = 297,                  /* RBRACE  */
    LBRACK = 298,                  /* LBRACK  */
    RBRACK = 299,                  /* RBRACK  */
    LPAREN = 300,                  /* LPAREN  */
    RPAREN = 301,                  /* RPAREN  */
    KW_BRKP = 302                  /* KW_BRKP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PLUS 258
#define MINUS 259
#define MUL 260
#define DIV 261
#define MOD 262
#define LT 263
#define GT 264
#define LE 265
#define GE 266
#define NE 267
#define EQ 268
#define ASSIGN 269
#define DO 270
#define IF 271
#define ELSE 272
#define WHILE 273
#define BREAK 274
#define CONT 275
#define KW_BEGIN 276
#define END 277
#define ENDIF 278
#define THEN 279
#define ENDWHILE 280
#define REPEAT 281
#define UNTIL 282
#define NUM 283
#define STRVAL 284
#define ID 285
#define READ 286
#define WRITE 287
#define DECL 288
#define ENDDECL 289
#define T_INT 290
#define T_STR 291
#define COMMA 292
#define MAIN 293
#define SEMI 294
#define RETURN 295
#define LBRACE 296
#define RBRACE 297
#define LBRACK 298
#define RBRACK 299
#define LPAREN 300
#define RPAREN 301
#define KW_BRKP 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "first.y"

    struct tnode *node;

#line 243 "y.tab.c"

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
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MINUS = 4,                      /* MINUS  */
  YYSYMBOL_MUL = 5,                        /* MUL  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_MOD = 7,                        /* MOD  */
  YYSYMBOL_LT = 8,                         /* LT  */
  YYSYMBOL_GT = 9,                         /* GT  */
  YYSYMBOL_LE = 10,                        /* LE  */
  YYSYMBOL_GE = 11,                        /* GE  */
  YYSYMBOL_NE = 12,                        /* NE  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_BREAK = 19,                     /* BREAK  */
  YYSYMBOL_CONT = 20,                      /* CONT  */
  YYSYMBOL_KW_BEGIN = 21,                  /* KW_BEGIN  */
  YYSYMBOL_END = 22,                       /* END  */
  YYSYMBOL_ENDIF = 23,                     /* ENDIF  */
  YYSYMBOL_THEN = 24,                      /* THEN  */
  YYSYMBOL_ENDWHILE = 25,                  /* ENDWHILE  */
  YYSYMBOL_REPEAT = 26,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 27,                     /* UNTIL  */
  YYSYMBOL_NUM = 28,                       /* NUM  */
  YYSYMBOL_STRVAL = 29,                    /* STRVAL  */
  YYSYMBOL_ID = 30,                        /* ID  */
  YYSYMBOL_READ = 31,                      /* READ  */
  YYSYMBOL_WRITE = 32,                     /* WRITE  */
  YYSYMBOL_DECL = 33,                      /* DECL  */
  YYSYMBOL_ENDDECL = 34,                   /* ENDDECL  */
  YYSYMBOL_T_INT = 35,                     /* T_INT  */
  YYSYMBOL_T_STR = 36,                     /* T_STR  */
  YYSYMBOL_COMMA = 37,                     /* COMMA  */
  YYSYMBOL_MAIN = 38,                      /* MAIN  */
  YYSYMBOL_SEMI = 39,                      /* SEMI  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_LBRACE = 41,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 42,                    /* RBRACE  */
  YYSYMBOL_LBRACK = 43,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 44,                    /* RBRACK  */
  YYSYMBOL_LPAREN = 45,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 46,                    /* RPAREN  */
  YYSYMBOL_KW_BRKP = 47,                   /* KW_BRKP  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_Program = 49,                   /* Program  */
  YYSYMBOL_GDeclBlock = 50,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 51,                 /* GDeclList  */
  YYSYMBOL_GDecl = 52,                     /* GDecl  */
  YYSYMBOL_Type = 53,                      /* Type  */
  YYSYMBOL_Ftype = 54,                     /* Ftype  */
  YYSYMBOL_GidList = 55,                   /* GidList  */
  YYSYMBOL_Gid = 56,                       /* Gid  */
  YYSYMBOL_FDefBlock = 57,                 /* FDefBlock  */
  YYSYMBOL_FDef = 58,                      /* FDef  */
  YYSYMBOL_ParamList = 59,                 /* ParamList  */
  YYSYMBOL_Param = 60,                     /* Param  */
  YYSYMBOL_LDeclBlock = 61,                /* LDeclBlock  */
  YYSYMBOL_LDeclList = 62,                 /* LDeclList  */
  YYSYMBOL_LDecl = 63,                     /* LDecl  */
  YYSYMBOL_IdList = 64,                    /* IdList  */
  YYSYMBOL_MainBlock = 65,                 /* MainBlock  */
  YYSYMBOL_Body = 66,                      /* Body  */
  YYSYMBOL_RetStmt = 67,                   /* RetStmt  */
  YYSYMBOL_Slist = 68,                     /* Slist  */
  YYSYMBOL_Stmt = 69,                      /* Stmt  */
  YYSYMBOL_InputStmt = 70,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 71,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 72,                   /* AsgStmt  */
  YYSYMBOL_IfStmt = 73,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 74,                 /* WhileStmt  */
  YYSYMBOL_BrkStmt = 75,                   /* BrkStmt  */
  YYSYMBOL_ContStmt = 76,                  /* ContStmt  */
  YYSYMBOL_repeatUntilStmt = 77,           /* repeatUntilStmt  */
  YYSYMBOL_doWhileStmt = 78,               /* doWhileStmt  */
  YYSYMBOL_expr = 79,                      /* expr  */
  YYSYMBOL_id = 80,                        /* id  */
  YYSYMBOL_ExprList = 81                   /* ExprList  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   431

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    42,    42,    49,    56,    58,    59,    61,    62,    64,
      67,    68,    71,    72,    75,    76,    78,    83,    91,   100,
     101,   103,   186,   187,   188,   190,   195,   196,   197,   199,
     200,   202,   204,   209,   216,   268,   269,   271,   281,   282,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   298,   302,   307,   312,   316,   321,   326,   330,   334,
     339,   345,   349,   353,   357,   361,   365,   369,   373,   377,
     381,   385,   389,   390,   393,   394,   395,   397,   405,   409,
     425,   437,   438
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
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "LT", "GT", "LE", "GE", "NE", "EQ", "ASSIGN", "DO", "IF",
  "ELSE", "WHILE", "BREAK", "CONT", "KW_BEGIN", "END", "ENDIF", "THEN",
  "ENDWHILE", "REPEAT", "UNTIL", "NUM", "STRVAL", "ID", "READ", "WRITE",
  "DECL", "ENDDECL", "T_INT", "T_STR", "COMMA", "MAIN", "SEMI", "RETURN",
  "LBRACE", "RBRACE", "LBRACK", "RBRACK", "LPAREN", "RPAREN", "KW_BRKP",
  "$accept", "Program", "GDeclBlock", "GDeclList", "GDecl", "Type",
  "Ftype", "GidList", "Gid", "FDefBlock", "FDef", "ParamList", "Param",
  "LDeclBlock", "LDeclList", "LDecl", "IdList", "MainBlock", "Body",
  "RetStmt", "Slist", "Stmt", "InputStmt", "OutputStmt", "AsgStmt",
  "IfStmt", "WhileStmt", "BrkStmt", "ContStmt", "repeatUntilStmt",
  "doWhileStmt", "expr", "id", "ExprList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      47,    43,   -18,    10,     2,   -67,   -67,   -67,   -67,    53,
     -67,    -7,   -17,   -67,   -18,   -67,    15,     2,   -67,   -67,
     -67,   -67,   -30,    46,   -67,     3,     5,   -67,   -67,    36,
       6,    -7,   -67,    24,     6,    50,   -67,    63,   -32,   -67,
     -67,    69,   -28,   -67,   -67,     6,   -67,    56,    82,    65,
     -67,   -67,    77,    62,   -67,   283,    76,    69,   -67,    75,
     -67,   -67,   355,    80,    81,   122,   123,   355,    70,   118,
     119,    18,   126,    99,   283,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   152,   -67,    82,   137,   -67,
     373,    18,    18,   -67,   -67,   301,    18,    18,   138,    18,
     141,   -67,   -67,    79,    18,   255,   -67,   -67,   -67,   148,
     -67,    18,   130,   -67,   128,    49,   125,   129,   213,   403,
     -16,   131,   136,   -67,    18,   147,    18,    18,    18,    18,
      18,    18,    18,    18,    18,    18,    18,   -67,   -67,   266,
     -67,    18,   151,   161,    18,   -67,    18,   139,   140,   142,
     -12,   -67,    94,    94,   -67,   -67,   -67,   418,   418,   418,
     418,   418,   418,   -67,   191,   355,   355,   202,   403,   -67,
     -67,   -67,   -67,   -13,   265,   319,   144,   -67,   355,   145,
     146,   -67,   337,   -67,   -67,   149,   -67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    10,    11,     0,
       8,     0,     0,     1,    12,    13,     0,     0,    20,     3,
       5,     7,    16,     0,    15,     0,     0,    19,     2,     0,
      24,     0,     9,     0,    24,     0,    12,     0,     0,    23,
      14,    28,     0,    17,    25,     0,    18,     0,     0,     0,
      22,    27,     0,     0,    30,     0,     0,    28,    33,     0,
      26,    29,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    34,     0,     0,    31,
       0,     0,     0,    57,    58,     0,     0,    82,     0,     0,
       0,    74,    75,    77,     0,     0,    76,    50,    36,     0,
      38,     0,     0,    32,     0,     0,     0,     0,     0,    81,
       0,     0,     0,    73,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,    35,     0,
      21,     0,     0,     0,     0,    78,     0,    79,     0,     0,
       0,    72,    61,    62,    63,    64,    71,    65,    68,    66,
      67,    69,    70,    53,     0,     0,     0,     0,    80,    49,
      51,    52,    79,     0,     0,     0,     0,    60,     0,     0,
       0,    59,     0,    55,    56,     0,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   -67,   171,   -20,    -1,   -67,   155,   -67,
     170,   156,   182,   132,   -67,   175,   -67,     0,   104,   157,
     -61,   -66,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -60,   -55,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     9,    10,    11,    37,    23,    24,    17,
      18,    38,    39,    48,    53,    54,    59,     5,    56,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,   119,   106,   120
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,    90,   166,    16,    19,    45,    95,    85,   110,    45,
      13,   105,    85,    29,    46,    30,    16,    28,    49,    85,
      12,   146,   100,    22,   110,   146,   177,    52,    25,   110,
     147,   115,   116,    52,   172,    85,   118,    14,    15,   122,
      85,    36,    15,   121,   125,    26,   101,   102,   103,    33,
      34,   139,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   104,    35,    41,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     6,     7,     8,
       1,   164,     2,    31,   167,    32,   168,    20,     7,     8,
      51,     7,     8,    44,    43,   142,    60,     7,     8,   128,
     129,   130,    47,    55,   174,   175,    57,    58,   110,   110,
      85,    85,    88,    96,    89,    97,   110,   182,    86,    85,
      85,   108,    96,    85,   124,    91,    92,    85,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,    93,    94,    98,    99,   107,   111,   113,   103,   123,
     138,   143,   140,   141,   144,   165,   166,   148,   169,   170,
      21,   171,   149,   181,   183,   184,    40,    27,   186,    87,
      42,   112,   150,   151,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,    50,    61,     0,
       0,   109,     0,     0,     0,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
      62,    63,   178,    64,    65,    66,     0,     0,   179,     0,
       0,    67,     0,     0,   137,    68,    69,    70,    62,    63,
       0,    64,    65,    66,     0,   163,     0,     0,     0,    67,
       0,     0,    72,    68,    69,    70,    62,    63,     0,    64,
      65,    66,     0,    71,     0,     0,     0,    67,   117,     0,
      72,    68,    69,    70,    62,    63,     0,    64,    65,    66,
       0,     0,     0,     0,   180,    67,     0,     0,    72,    68,
      69,    70,    62,    63,     0,    64,    65,    66,     0,     0,
     185,     0,     0,    67,     0,     0,    72,    68,    69,    70,
      62,    63,     0,    64,    65,    66,     0,     0,     0,     0,
       0,    67,     0,     0,    72,    68,    69,    70,    62,    63,
       0,   114,    65,    66,     0,     0,     0,     0,     0,    67,
       0,     0,    72,    68,    69,    70,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
      72,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1
};

static const yytype_int16 yycheck[] =
{
      55,    62,    15,     4,     4,    37,    67,    62,    74,    37,
       0,    71,    67,    43,    46,    45,    17,    17,    46,    74,
      38,    37,     4,    30,    90,    37,    39,    47,    45,    95,
      46,    91,    92,    53,    46,    90,    96,    35,    36,    99,
      95,    35,    36,    98,   104,    30,    28,    29,    30,    46,
      45,   111,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    45,    28,    41,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,    34,    35,    36,
      33,   141,    35,    37,   144,    39,   146,    34,    35,    36,
      34,    35,    36,    30,    44,    46,    34,    35,    36,     5,
       6,     7,    33,    21,   165,   166,    41,    30,   174,   175,
     165,   166,    37,    43,    39,    45,   182,   178,    42,   174,
     175,    22,    43,   178,    45,    45,    45,   182,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    39,    39,    45,    45,    39,    14,    30,    30,    28,
      22,    46,    42,    45,    45,    24,    15,    46,    39,    39,
       9,    39,    46,    39,    39,    39,    31,    17,    39,    57,
      34,    87,   124,    46,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    45,    53,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      15,    16,    17,    18,    19,    20,    -1,    -1,    23,    -1,
      -1,    26,    -1,    -1,    39,    30,    31,    32,    15,    16,
      -1,    18,    19,    20,    -1,    39,    -1,    -1,    -1,    26,
      -1,    -1,    47,    30,    31,    32,    15,    16,    -1,    18,
      19,    20,    -1,    40,    -1,    -1,    -1,    26,    27,    -1,
      47,    30,    31,    32,    15,    16,    -1,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    47,    30,
      31,    32,    15,    16,    -1,    18,    19,    20,    -1,    -1,
      23,    -1,    -1,    26,    -1,    -1,    47,    30,    31,    32,
      15,    16,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    47,    30,    31,    32,    15,    16,
      -1,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    47,    30,    31,    32,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      47,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    35,    49,    50,    65,    34,    35,    36,    51,
      52,    53,    38,     0,    35,    36,    54,    57,    58,    65,
      34,    52,    30,    55,    56,    45,    30,    58,    65,    43,
      45,    37,    39,    46,    45,    28,    35,    54,    59,    60,
      56,    41,    59,    44,    30,    37,    46,    33,    61,    46,
      60,    34,    53,    62,    63,    21,    66,    41,    30,    64,
      34,    63,    15,    16,    18,    19,    20,    26,    30,    31,
      32,    40,    47,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    80,    42,    61,    37,    39,
      68,    45,    45,    39,    39,    68,    43,    45,    45,    45,
       4,    28,    29,    30,    45,    79,    80,    39,    22,    67,
      69,    14,    66,    30,    18,    79,    79,    27,    79,    79,
      81,    80,    79,    28,    45,    79,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    39,    22,    79,
      42,    45,    46,    46,    45,    44,    37,    46,    46,    46,
      81,    46,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    39,    79,    24,    15,    79,    79,    39,
      39,    39,    46,    46,    68,    68,    46,    39,    17,    23,
      25,    39,    68,    39,    39,    23,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    51,    51,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    57,
      57,    58,    59,    59,    59,    60,    61,    61,    61,    62,
      62,    63,    64,    64,    65,    66,    66,    67,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    71,    72,    73,    73,    74,    75,    76,    77,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    80,    80,    80,
      81,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     4,     4,     2,
       1,     9,     3,     1,     0,     2,     3,     2,     0,     2,
       1,     3,     3,     1,     8,     4,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       2,     5,     5,     4,    10,     8,     8,     2,     2,     7,
       7,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     1,     1,     4,     4,
       3,     1,     0
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
  case 2: /* Program: GDeclBlock FDefBlock MainBlock  */
#line 43 "first.y"
{
    printf("\nGST AFTER GLOBAL DECLARATIONS\n");
          printGSymbolTable();
          (yyval.node) = (yyvsp[0].node);
     fclose(out);
}
#line 1479 "y.tab.c"
    break;

  case 3: /* Program: GDeclBlock MainBlock  */
#line 50 "first.y"
        {
          printf("\nGST AFTER GLOBAL DECLARATIONS\n");
          printGSymbolTable();
          (yyval.node) = (yyvsp[0].node);
          fclose(out);
      }
#line 1490 "y.tab.c"
    break;

  case 4: /* Program: MainBlock  */
#line 56 "first.y"
                    {fclose(out);}
#line 1496 "y.tab.c"
    break;

  case 5: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 58 "first.y"
                                     {initialize(); }
#line 1502 "y.tab.c"
    break;

  case 6: /* GDeclBlock: DECL ENDDECL  */
#line 59 "first.y"
                           {initialize(); }
#line 1508 "y.tab.c"
    break;

  case 10: /* Type: T_INT  */
#line 67 "first.y"
             { declaration_type = INT; }
#line 1514 "y.tab.c"
    break;

  case 11: /* Type: T_STR  */
#line 68 "first.y"
            { declaration_type = STRING; }
#line 1520 "y.tab.c"
    break;

  case 12: /* Ftype: T_INT  */
#line 71 "first.y"
              { fdeclaration_type = INT; }
#line 1526 "y.tab.c"
    break;

  case 13: /* Ftype: T_STR  */
#line 72 "first.y"
            { fdeclaration_type = STRING; }
#line 1532 "y.tab.c"
    break;

  case 16: /* Gid: ID  */
#line 78 "first.y"
         {
     checkAvailability((yyvsp[0].node)->varname,1);   
     
     GInstall((yyvsp[0].node)->varname,declaration_type,1,NULL);
}
#line 1542 "y.tab.c"
    break;

  case 17: /* Gid: ID LBRACK NUM RBRACK  */
#line 83 "first.y"
                           {
        checkAvailability((yyvsp[-3].node)->varname,1);   
        if((yyvsp[-1].node)->value.intval < 1) {
        yyerror("Invalid array size");
        exit(1);
    }
     GInstall((yyvsp[-3].node)->varname,declaration_type,(yyvsp[-1].node)->value.intval,NULL);
    }
#line 1555 "y.tab.c"
    break;

  case 18: /* Gid: ID LPAREN ParamList RPAREN  */
#line 91 "first.y"
                                 {
        declCount++;
        checkAvailability((yyvsp[-3].node)->varname,1);
        GInstall((yyvsp[-3].node)->varname,declaration_type,-1,Phead);
        Phead=NULL;
        Ptail=NULL;
    }
#line 1567 "y.tab.c"
    break;

  case 21: /* FDef: Ftype ID LPAREN ParamList RPAREN LBRACE LDeclBlock Body RBRACE  */
#line 104 "first.y"
        {
            // localbindingstart = 1;
            defCount++;
            Gtemp = GLookup((yyvsp[-7].node)->varname);
            current_function_type = fdeclaration_type;
            if(Gtemp == NULL) {
                fprintf(stderr,"Function %s not declared", (yyvsp[-7].node)->varname);
                yyerror("");
                exit(1);
            }
            if(Gtemp->type != fdeclaration_type) {
                fprintf(stderr,"%s : Function type does not match declaration", (yyvsp[-7].node)->varname);
                yyerror("");
                exit(1);
            }
            
            argList1 = Phead;
            argList2 = Gtemp->paramlist;

            while(argList1 != NULL && argList2 != NULL) {
                if(argList1->type != argList2->type) {
                    fprintf(stderr,"%s : Conflict in argument types", (yyvsp[-7].node)->varname);
                    yyerror("");
                    exit(1);
                }

                if(strcmp(argList1->name, argList2->name)) {
                    fprintf(stderr,"%s : Conflict in argument names", (yyvsp[-7].node)->varname);
                    yyerror("");
                    exit(1);
                }

                argList1 = argList1->next;
                argList2 = argList2->next;
            }

            if ((argList1 != NULL) || (argList2 != NULL)) {
                yyerror("Not enough arguments");
                exit(1);
            }
            
             struct tnode *funcTree =
        createTree(
            fdeclaration_type,   // return type
            NULL,
            FUN_DEF_NODE,        // function node
            (yyvsp[-7].node)->varname,         // function name
            NULL,
            (yyvsp[-1].node),                  // body AST
            NULL,
            NULL
        );
        printf("\nFUNCTION AST: %s\n", (yyvsp[-7].node)->varname);
        // print(funcTree);
        printf("\nLOCAL SYMBOL TABLE (%s)\n", (yyvsp[-7].node)->varname);
        printLSymbolTable();
        fprintf(out, "F%d:\n",Gtemp->flabel);
        fprintf(out, "PUSH BP\n");
        fprintf(out, "MOV BP,SP\n");
        printf("value: %d\n", localbindingstart);
        fprintf(out, "ADD SP, %d\n", localbindingstart - 1);
        
        // Ltemp = Lhead;
        // while(Ltemp != NULL) {
        //     if(Ltemp->binding > 0){
        //         int k=getReg();
        //         fprintf(out, "PUSH R%d\n",k);
        //         freeReg();
        //     }
        //     Ltemp = Ltemp->next;
        // }

        codegen((yyvsp[-1].node));
            Phead = NULL;
            Ptail = NULL;
            Lhead = NULL;
            Ltail = NULL;
        localbindingstart = 1;
        printf("updated to 1 here\n");
        }
#line 1652 "y.tab.c"
    break;

  case 25: /* Param: Ftype ID  */
#line 190 "first.y"
                 {
                    checkAvailability((yyvsp[0].node)->varname, 0);
                    PInstall((yyvsp[0].node)->varname, fdeclaration_type);
                }
#line 1661 "y.tab.c"
    break;

  case 26: /* LDeclBlock: DECL LDeclList ENDDECL  */
#line 195 "first.y"
                                    {InstallParamsInLocal();}
#line 1667 "y.tab.c"
    break;

  case 27: /* LDeclBlock: DECL ENDDECL  */
#line 196 "first.y"
                           {InstallParamsInLocal();}
#line 1673 "y.tab.c"
    break;

  case 28: /* LDeclBlock: %empty  */
#line 197 "first.y"
              {InstallParamsInLocal();}
#line 1679 "y.tab.c"
    break;

  case 32: /* IdList: IdList COMMA ID  */
#line 204 "first.y"
                         {
            checkAvailability((yyvsp[0].node)->varname, 0);
            LInstall((yyvsp[0].node)->varname, declaration_type);
            localbindingstart++;
        }
#line 1689 "y.tab.c"
    break;

  case 33: /* IdList: ID  */
#line 209 "first.y"
         {
                    checkAvailability((yyvsp[0].node)->varname, 0);
                    LInstall((yyvsp[0].node)->varname, declaration_type);
                    localbindingstart++;
                }
#line 1699 "y.tab.c"
    break;

  case 34: /* MainBlock: T_INT MAIN LPAREN RPAREN LBRACE LDeclBlock Body RBRACE  */
#line 216 "first.y"
                                                                   {

    if(defCount != declCount) {
        yyerror("All functions declared need to be defined\n");
        exit(1);
    }

    printf("reached main with %d\n", localbindingstart);
    // if(declaration_type != INT) {
    //     yyerror("Main return type should be of integer type\n");
    //     exit(1);
    // }
    current_function_type = INT;
    struct tnode *mainTree =
        createTree(
            INT,
            NULL,
            FUN_DEF_NODE,
            "main",
            NULL,
            (yyvsp[-1].node),
            NULL,
            NULL
        );

    printf("\nFUNCTION AST: main\n");
    // print(mainTree);

    (yyval.node) = mainTree;

    printLSymbolTable();
    fprintf(out, "MAIN:\n");
    fprintf(out, "PUSH BP\n");
    fprintf(out, "MOV BP,SP\n");
    printf("here: %d\n", localbindingstart);
    fprintf(out, "ADD SP, %d\n", localbindingstart - 1);
        // Ltemp = Lhead;
    // while (Ltemp != NULL)
    // {
    //     int k=getReg();
    //     fprintf(out, "PUSH R%d\n",k);
    //     freeReg();
    //     Ltemp = Ltemp->next;
    // }

    codegen((yyvsp[-1].node));
    Lhead = NULL;
    Ltail = NULL;
    localbindingstart = 1;

    }
#line 1755 "y.tab.c"
    break;

  case 35: /* Body: KW_BEGIN Slist RetStmt END  */
#line 268 "first.y"
                                  {(yyval.node) = createTree(NONE, NULL,CONNECTOR_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[-1].node), NULL);}
#line 1761 "y.tab.c"
    break;

  case 36: /* Body: KW_BEGIN RetStmt END  */
#line 269 "first.y"
                           {(yyval.node) = (yyvsp[-1].node);}
#line 1767 "y.tab.c"
    break;

  case 37: /* RetStmt: RETURN expr SEMI  */
#line 271 "first.y"
                             {
                                if(current_function_type == (yyvsp[-1].node)->type) {
                                    (yyval.node) = createTree(NONE, NULL,RET_NODE, NULL, NULL, (yyvsp[-1].node), NULL, NULL);
                                } else {
                                    yyerror("Return type mismatch");
                                    exit(1);
                                }
                            }
#line 1780 "y.tab.c"
    break;

  case 38: /* Slist: Slist Stmt  */
#line 281 "first.y"
                   {(yyval.node) = createTree(NONE, NULL,CONNECTOR_NODE, NULL, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);}
#line 1786 "y.tab.c"
    break;

  case 39: /* Slist: Stmt  */
#line 282 "first.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 1792 "y.tab.c"
    break;

  case 40: /* Stmt: InputStmt  */
#line 285 "first.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 1798 "y.tab.c"
    break;

  case 41: /* Stmt: OutputStmt  */
#line 286 "first.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 1804 "y.tab.c"
    break;

  case 42: /* Stmt: AsgStmt  */
#line 287 "first.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 1810 "y.tab.c"
    break;

  case 43: /* Stmt: IfStmt  */
#line 288 "first.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 1816 "y.tab.c"
    break;

  case 44: /* Stmt: WhileStmt  */
#line 289 "first.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1822 "y.tab.c"
    break;

  case 45: /* Stmt: BrkStmt  */
#line 290 "first.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1828 "y.tab.c"
    break;

  case 46: /* Stmt: ContStmt  */
#line 291 "first.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 1834 "y.tab.c"
    break;

  case 47: /* Stmt: repeatUntilStmt  */
#line 292 "first.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1840 "y.tab.c"
    break;

  case 48: /* Stmt: doWhileStmt  */
#line 293 "first.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 1846 "y.tab.c"
    break;

  case 49: /* Stmt: ID LPAREN ExprList RPAREN SEMI  */
#line 294 "first.y"
                                     {(yyval.node) = (yyvsp[-4].node);}
#line 1852 "y.tab.c"
    break;

  case 50: /* Stmt: KW_BRKP SEMI  */
#line 295 "first.y"
                        { (yyval.node) = createTree(NONE, NULL, BRKP_NODE, NULL, NULL, NULL, NULL, NULL); }
#line 1858 "y.tab.c"
    break;

  case 51: /* InputStmt: READ LPAREN id RPAREN SEMI  */
#line 298 "first.y"
                                       {
    (yyval.node) = createTree(NONE, NULL,READ_NODE, NULL, NULL, (yyvsp[-2].node),NULL, NULL);
}
#line 1866 "y.tab.c"
    break;

  case 52: /* OutputStmt: WRITE LPAREN expr RPAREN SEMI  */
#line 302 "first.y"
                                           {
            (yyval.node) = createTree(NONE, NULL,WRITE_NODE, NULL, NULL, (yyvsp[-2].node), NULL, NULL);
            
}
#line 1875 "y.tab.c"
    break;

  case 53: /* AsgStmt: id ASSIGN expr SEMI  */
#line 307 "first.y"
                               {
            typecheck((yyvsp[-3].node)->type, (yyvsp[-1].node)->type, '=');
            (yyval.node) = createTree(NONE, NULL,ASSIGN_NODE, NULL, NULL, (yyvsp[-3].node), (yyvsp[-1].node), NULL);
        }
#line 1884 "y.tab.c"
    break;

  case 54: /* IfStmt: IF LPAREN expr RPAREN THEN Slist ELSE Slist ENDIF SEMI  */
#line 312 "first.y"
                                                                {
        typecheck((yyvsp[-7].node)->type, BOOL, 'e');
        (yyval.node) = createTree(NONE, NULL,IF_ELSE_NODE, NULL, NULL, (yyvsp[-7].node), (yyvsp[-2].node), (yyvsp[-4].node));
}
#line 1893 "y.tab.c"
    break;

  case 55: /* IfStmt: IF LPAREN expr RPAREN THEN Slist ENDIF SEMI  */
#line 316 "first.y"
                                                  {
        typecheck((yyvsp[-5].node)->type, BOOL, 'i');
        (yyval.node) = createTree(NONE, NULL,IF_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-2].node),NULL);
}
#line 1902 "y.tab.c"
    break;

  case 56: /* WhileStmt: WHILE LPAREN expr RPAREN DO Slist ENDWHILE SEMI  */
#line 321 "first.y"
                                                           {
        typecheck((yyvsp[-5].node)->type,BOOL, 'w');
        (yyval.node) = createTree(NONE, NULL,WHILE_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
}
#line 1911 "y.tab.c"
    break;

  case 57: /* BrkStmt: BREAK SEMI  */
#line 326 "first.y"
                     {
    (yyval.node) = createTree(NONE, NULL,BREAK_NODE, NULL, NULL, NULL, NULL, NULL);
}
#line 1919 "y.tab.c"
    break;

  case 58: /* ContStmt: CONT SEMI  */
#line 330 "first.y"
                    {
    (yyval.node) = createTree(NONE, NULL,CONT_NODE, NULL, NULL, NULL, NULL, NULL);
}
#line 1927 "y.tab.c"
    break;

  case 59: /* repeatUntilStmt: REPEAT Slist UNTIL LPAREN expr RPAREN SEMI  */
#line 334 "first.y"
                                                            {
    typecheck((yyvsp[-2].node)->type, BOOL, 'r');
    (yyval.node) = createTree(NONE, NULL, REPEAT_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
}
#line 1936 "y.tab.c"
    break;

  case 60: /* doWhileStmt: DO Slist WHILE LPAREN expr RPAREN SEMI  */
#line 339 "first.y"
                                                    {
    typecheck((yyvsp[-2].node)->type, BOOL, 'd');
    (yyval.node) = createTree(NONE, NULL, DOWHILE_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
}
#line 1945 "y.tab.c"
    break;

  case 61: /* expr: expr PLUS expr  */
#line 345 "first.y"
                      {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(INT,NULL, ADD_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 1954 "y.tab.c"
    break;

  case 62: /* expr: expr MINUS expr  */
#line 349 "first.y"
                     {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(INT,NULL, SUB_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 1963 "y.tab.c"
    break;

  case 63: /* expr: expr MUL expr  */
#line 353 "first.y"
                   {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(INT,NULL, MUL_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 1972 "y.tab.c"
    break;

  case 64: /* expr: expr DIV expr  */
#line 357 "first.y"
                   {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(INT,NULL, DIV_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 1981 "y.tab.c"
    break;

  case 65: /* expr: expr LT expr  */
#line 361 "first.y"
                   {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(BOOL,NULL, LT_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 1990 "y.tab.c"
    break;

  case 66: /* expr: expr LE expr  */
#line 365 "first.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(BOOL,NULL, LE_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 1999 "y.tab.c"
    break;

  case 67: /* expr: expr GE expr  */
#line 369 "first.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(BOOL,NULL, GE_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2008 "y.tab.c"
    break;

  case 68: /* expr: expr GT expr  */
#line 373 "first.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(BOOL,NULL, GT_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2017 "y.tab.c"
    break;

  case 69: /* expr: expr NE expr  */
#line 377 "first.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(BOOL,NULL, NE_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2026 "y.tab.c"
    break;

  case 70: /* expr: expr EQ expr  */
#line 381 "first.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(BOOL,NULL, EQ_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2035 "y.tab.c"
    break;

  case 71: /* expr: expr MOD expr  */
#line 385 "first.y"
                   {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(INT,NULL, MOD_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2044 "y.tab.c"
    break;

  case 72: /* expr: LPAREN expr RPAREN  */
#line 389 "first.y"
                         {(yyval.node) = (yyvsp[-1].node);}
#line 2050 "y.tab.c"
    break;

  case 73: /* expr: MINUS NUM  */
#line 390 "first.y"
                {
        (yyvsp[0].node)->value.intval=-1*((yyvsp[0].node)->value.intval);
        (yyval.node) = (yyvsp[0].node);}
#line 2058 "y.tab.c"
    break;

  case 74: /* expr: NUM  */
#line 393 "first.y"
          {(yyval.node) = (yyvsp[0].node);}
#line 2064 "y.tab.c"
    break;

  case 75: /* expr: STRVAL  */
#line 394 "first.y"
             {(yyval.node) = (yyvsp[0].node);}
#line 2070 "y.tab.c"
    break;

  case 76: /* expr: id  */
#line 395 "first.y"
         {(yyval.node) = (yyvsp[0].node);}
#line 2076 "y.tab.c"
    break;

  case 77: /* id: ID  */
#line 397 "first.y"
        {
        assignType((yyvsp[0].node),0);
        (yyval.node)=(yyvsp[0].node);
    }
#line 2085 "y.tab.c"
    break;

  case 78: /* id: ID LBRACK expr RBRACK  */
#line 405 "first.y"
                            {
        assignType((yyvsp[-3].node),2);
        (yyval.node)=createTree((yyvsp[-3].node)->type,NULL,ARRAY_NODE,NULL,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
    }
#line 2094 "y.tab.c"
    break;

  case 79: /* id: ID LPAREN ExprList RPAREN  */
#line 409 "first.y"
                                {
    assignType((yyvsp[-3].node),1);
    (yyvsp[-3].node)->nodetype=FUN_NODE;
    (yyvsp[-3].node)->argList=(yyvsp[-1].node);
    struct Gsymbol *g=GLookup((yyvsp[-3].node)->varname);
    if(g == NULL) {
        fprintf(stderr, "Function %s not declared\n", (yyvsp[-3].node)->varname);
        yyerror("");
        exit(1);
    }
    checkFunctionArgs(g,g->paramlist, (yyvsp[-3].node)->argList);
    (yyval.node)=(yyvsp[-3].node);
}
#line 2112 "y.tab.c"
    break;

  case 80: /* ExprList: ExprList COMMA expr  */
#line 425 "first.y"
                              {
                                (yyval.node) = createTree(
                                    NONE,
                                    NULL,
                                    CONNECTOR_NODE,
                                    NULL,
                                    NULL,
                                    (yyvsp[-2].node),
                                    (yyvsp[0].node),
                                    NULL
                                );
                            }
#line 2129 "y.tab.c"
    break;

  case 81: /* ExprList: expr  */
#line 437 "first.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2135 "y.tab.c"
    break;

  case 82: /* ExprList: %empty  */
#line 438 "first.y"
                            {(yyval.node) = NULL;}
#line 2141 "y.tab.c"
    break;


#line 2145 "y.tab.c"

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

#line 447 "first.y"

void initSymbolTables(void) {
    Ghead = Gtail = NULL;
    Lhead = Ltail = NULL;
    Phead = Ptail = NULL;

    declaration_type = 0;
    fdeclaration_type = 0;
    start = 4096;
    printf("initialized: 1\n");
    localbindingstart = 1;
    flabelcount = 0;
    declCount = 0;
    defCount = 0;
}
void yyerror(char const *msg) {
    fprintf(stderr,
        "Syntax error at line %d near '%s'\n",
        yylineno, yytext);
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

    initSymbolTables();
    yyin = source_file;
    return yyparse();
}
