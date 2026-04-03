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
    #include "typetable.h"
    int yylex(void);
    void yyerror(char const *msg);
    extern FILE *yyin;
    FILE *out;
    extern int yylineno;
    extern char *yytext;
    struct Paramstruct *argList1, *argList2;
    int declCount = 0, defCount = 0;
    struct Typetable * current_function_type = NULL;
    struct Typetable * saved_decl_type=NULL;
    int testing=1;

#line 94 "y.tab.c"

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
    DOT = 270,                     /* DOT  */
    DO = 271,                      /* DO  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    WHILE = 274,                   /* WHILE  */
    BREAK = 275,                   /* BREAK  */
    CONT = 276,                    /* CONT  */
    KW_BEGIN = 277,                /* KW_BEGIN  */
    END = 278,                     /* END  */
    ENDIF = 279,                   /* ENDIF  */
    THEN = 280,                    /* THEN  */
    ENDWHILE = 281,                /* ENDWHILE  */
    REPEAT = 282,                  /* REPEAT  */
    UNTIL = 283,                   /* UNTIL  */
    TYPE = 284,                    /* TYPE  */
    ENDTYPE = 285,                 /* ENDTYPE  */
    FREE = 286,                    /* FREE  */
    INIT = 287,                    /* INIT  */
    NUM = 288,                     /* NUM  */
    STRVAL = 289,                  /* STRVAL  */
    ID = 290,                      /* ID  */
    READ = 291,                    /* READ  */
    WRITE = 292,                   /* WRITE  */
    DECL = 293,                    /* DECL  */
    ENDDECL = 294,                 /* ENDDECL  */
    T_INT = 295,                   /* T_INT  */
    T_STR = 296,                   /* T_STR  */
    COMMA = 297,                   /* COMMA  */
    MAIN = 298,                    /* MAIN  */
    SEMI = 299,                    /* SEMI  */
    RETURN = 300,                  /* RETURN  */
    EQNILL = 301,                  /* EQNILL  */
    NEQNILL = 302,                 /* NEQNILL  */
    ALLOC = 303,                   /* ALLOC  */
    NILL = 304,                    /* NILL  */
    LBRACE = 305,                  /* LBRACE  */
    RBRACE = 306,                  /* RBRACE  */
    LBRACK = 307,                  /* LBRACK  */
    RBRACK = 308,                  /* RBRACK  */
    LPAREN = 309,                  /* LPAREN  */
    RPAREN = 310,                  /* RPAREN  */
    KW_BRKP = 311                  /* KW_BRKP  */
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
#define DOT 270
#define DO 271
#define IF 272
#define ELSE 273
#define WHILE 274
#define BREAK 275
#define CONT 276
#define KW_BEGIN 277
#define END 278
#define ENDIF 279
#define THEN 280
#define ENDWHILE 281
#define REPEAT 282
#define UNTIL 283
#define TYPE 284
#define ENDTYPE 285
#define FREE 286
#define INIT 287
#define NUM 288
#define STRVAL 289
#define ID 290
#define READ 291
#define WRITE 292
#define DECL 293
#define ENDDECL 294
#define T_INT 295
#define T_STR 296
#define COMMA 297
#define MAIN 298
#define SEMI 299
#define RETURN 300
#define EQNILL 301
#define NEQNILL 302
#define ALLOC 303
#define NILL 304
#define LBRACE 305
#define RBRACE 306
#define LBRACK 307
#define RBRACK 308
#define LPAREN 309
#define RPAREN 310
#define KW_BRKP 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "first.y"

    struct tnode *node;

#line 263 "y.tab.c"

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
  YYSYMBOL_DOT = 15,                       /* DOT  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_BREAK = 20,                     /* BREAK  */
  YYSYMBOL_CONT = 21,                      /* CONT  */
  YYSYMBOL_KW_BEGIN = 22,                  /* KW_BEGIN  */
  YYSYMBOL_END = 23,                       /* END  */
  YYSYMBOL_ENDIF = 24,                     /* ENDIF  */
  YYSYMBOL_THEN = 25,                      /* THEN  */
  YYSYMBOL_ENDWHILE = 26,                  /* ENDWHILE  */
  YYSYMBOL_REPEAT = 27,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 28,                     /* UNTIL  */
  YYSYMBOL_TYPE = 29,                      /* TYPE  */
  YYSYMBOL_ENDTYPE = 30,                   /* ENDTYPE  */
  YYSYMBOL_FREE = 31,                      /* FREE  */
  YYSYMBOL_INIT = 32,                      /* INIT  */
  YYSYMBOL_NUM = 33,                       /* NUM  */
  YYSYMBOL_STRVAL = 34,                    /* STRVAL  */
  YYSYMBOL_ID = 35,                        /* ID  */
  YYSYMBOL_READ = 36,                      /* READ  */
  YYSYMBOL_WRITE = 37,                     /* WRITE  */
  YYSYMBOL_DECL = 38,                      /* DECL  */
  YYSYMBOL_ENDDECL = 39,                   /* ENDDECL  */
  YYSYMBOL_T_INT = 40,                     /* T_INT  */
  YYSYMBOL_T_STR = 41,                     /* T_STR  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_MAIN = 43,                      /* MAIN  */
  YYSYMBOL_SEMI = 44,                      /* SEMI  */
  YYSYMBOL_RETURN = 45,                    /* RETURN  */
  YYSYMBOL_EQNILL = 46,                    /* EQNILL  */
  YYSYMBOL_NEQNILL = 47,                   /* NEQNILL  */
  YYSYMBOL_ALLOC = 48,                     /* ALLOC  */
  YYSYMBOL_NILL = 49,                      /* NILL  */
  YYSYMBOL_LBRACE = 50,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 51,                    /* RBRACE  */
  YYSYMBOL_LBRACK = 52,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 53,                    /* RBRACK  */
  YYSYMBOL_LPAREN = 54,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 55,                    /* RPAREN  */
  YYSYMBOL_KW_BRKP = 56,                   /* KW_BRKP  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_Program = 58,                   /* Program  */
  YYSYMBOL_TypeDefBlock = 59,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 60,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 61,                   /* TypeDef  */
  YYSYMBOL_UserDefinedType = 62,           /* UserDefinedType  */
  YYSYMBOL_FieldDeclList = 63,             /* FieldDeclList  */
  YYSYMBOL_FieldDecl = 64,                 /* FieldDecl  */
  YYSYMBOL_GDeclBlock = 65,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 66,                 /* GDeclList  */
  YYSYMBOL_GDecl = 67,                     /* GDecl  */
  YYSYMBOL_FieldType = 68,                 /* FieldType  */
  YYSYMBOL_Type = 69,                      /* Type  */
  YYSYMBOL_Ftype = 70,                     /* Ftype  */
  YYSYMBOL_Field = 71,                     /* Field  */
  YYSYMBOL_GidList = 72,                   /* GidList  */
  YYSYMBOL_Gid = 73,                       /* Gid  */
  YYSYMBOL_74_1 = 74,                      /* $@1  */
  YYSYMBOL_FDefBlock = 75,                 /* FDefBlock  */
  YYSYMBOL_FDef = 76,                      /* FDef  */
  YYSYMBOL_77_2 = 77,                      /* $@2  */
  YYSYMBOL_ParamList = 78,                 /* ParamList  */
  YYSYMBOL_Param = 79,                     /* Param  */
  YYSYMBOL_LDeclBlock = 80,                /* LDeclBlock  */
  YYSYMBOL_LDeclList = 81,                 /* LDeclList  */
  YYSYMBOL_LDecl = 82,                     /* LDecl  */
  YYSYMBOL_IdList = 83,                    /* IdList  */
  YYSYMBOL_MainBlock = 84,                 /* MainBlock  */
  YYSYMBOL_85_3 = 85,                      /* $@3  */
  YYSYMBOL_Body = 86,                      /* Body  */
  YYSYMBOL_RetStmt = 87,                   /* RetStmt  */
  YYSYMBOL_Slist = 88,                     /* Slist  */
  YYSYMBOL_Stmt = 89,                      /* Stmt  */
  YYSYMBOL_InputStmt = 90,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 91,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 92,                   /* AsgStmt  */
  YYSYMBOL_IfStmt = 93,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 94,                 /* WhileStmt  */
  YYSYMBOL_BrkStmt = 95,                   /* BrkStmt  */
  YYSYMBOL_ContStmt = 96,                  /* ContStmt  */
  YYSYMBOL_repeatUntilStmt = 97,           /* repeatUntilStmt  */
  YYSYMBOL_doWhileStmt = 98,               /* doWhileStmt  */
  YYSYMBOL_expr = 99,                      /* expr  */
  YYSYMBOL_id = 100,                       /* id  */
  YYSYMBOL_ExprList = 101                  /* ExprList  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   460

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  245

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    47,    47,    55,    63,    65,    66,    67,    69,    70,
      73,    76,    82,    83,    85,    94,    95,    97,    98,   100,
     104,   105,   106,   119,   120,   121,   130,   131,   132,   143,
     148,   153,   154,   156,   161,   169,   169,   181,   182,   184,
     184,   270,   271,   272,   274,   282,   283,   284,   286,   287,
     289,   291,   296,   304,   303,   358,   359,   361,   378,   379,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   409,   410,   418,   425,   428,   432,   437,   459,   483,
     487,   492,   497,   501,   505,   510,   516,   520,   524,   528,
     532,   536,   540,   544,   548,   552,   556,   560,   564,   568,
     572,   576,   577,   582,   586,   590,   591,   592,   596,   599,
     602,   610,   614,   634,   646,   647
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
  "DIV", "MOD", "LT", "GT", "LE", "GE", "NE", "EQ", "ASSIGN", "DOT", "DO",
  "IF", "ELSE", "WHILE", "BREAK", "CONT", "KW_BEGIN", "END", "ENDIF",
  "THEN", "ENDWHILE", "REPEAT", "UNTIL", "TYPE", "ENDTYPE", "FREE", "INIT",
  "NUM", "STRVAL", "ID", "READ", "WRITE", "DECL", "ENDDECL", "T_INT",
  "T_STR", "COMMA", "MAIN", "SEMI", "RETURN", "EQNILL", "NEQNILL", "ALLOC",
  "NILL", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "LPAREN", "RPAREN",
  "KW_BRKP", "$accept", "Program", "TypeDefBlock", "TypeDefList",
  "TypeDef", "UserDefinedType", "FieldDeclList", "FieldDecl", "GDeclBlock",
  "GDeclList", "GDecl", "FieldType", "Type", "Ftype", "Field", "GidList",
  "Gid", "$@1", "FDefBlock", "FDef", "$@2", "ParamList", "Param",
  "LDeclBlock", "LDeclList", "LDecl", "IdList", "MainBlock", "$@3", "Body",
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

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,   -20,     9,    55,    23,   -98,   -98,   -98,   -18,   -98,
      12,    13,   -98,    87,    99,   -98,   -98,   199,    16,   -98,
     -98,   -98,   -98,   114,   -98,    68,   -98,     9,   -98,    84,
      99,   -98,   -98,   -98,   -98,   -98,    90,   -98,    88,   -98,
     -98,   -98,    66,   119,   -98,    96,   -98,   -98,   -98,   -98,
      98,    82,   118,   -98,    68,   -98,   305,   -98,   127,   159,
     305,   -98,   180,    17,   -98,   212,   194,   -98,    21,   -98,
     305,   -98,   -98,   190,   263,   -98,   360,   176,   -98,   -98,
     181,   -98,   169,   -98,   -98,   360,   195,   202,   191,   204,
     360,   207,   209,     4,   245,   246,   210,   257,     7,   282,
     360,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   293,   -98,   127,   274,   -98,   -98,   382,   210,   210,
     -98,   -98,   201,   281,   253,   285,   210,   210,   287,   210,
     286,   269,   -98,   -98,   208,   270,   -98,   210,    -7,   262,
     -98,   -98,   210,   292,   -98,   311,   -98,   210,   194,   -98,
     290,    25,    78,   295,   -11,   -10,   297,   -98,   197,   436,
      22,   172,   283,    89,   -98,   301,   -98,   -98,   210,   308,
     164,   -98,   -98,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   -98,   273,   -98,   -98,   284,   309,
     210,   339,   350,   210,   323,   324,   -98,   -98,   210,   327,
     334,   340,   -98,    24,   -98,   -98,   110,   110,   -98,   -98,
     -98,   447,   447,   447,   447,   447,   447,   -98,   -98,   -98,
     175,   360,   360,   186,   -98,   -98,   436,   -98,   -98,   -98,
     -98,    26,   294,   316,   341,   -98,   360,   342,   344,   -98,
     338,   -98,   -98,   345,   -98
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     0,     0,     0,     4,     6,    11,     0,     9,
       0,     0,     1,     0,     0,     5,     8,     0,     0,    25,
      16,    23,    24,     0,    18,     0,    28,    26,    27,     0,
       0,    38,     3,    22,    20,    21,     0,    13,     0,    53,
      15,    17,    33,     0,    32,     0,    37,     2,    10,    12,
       0,     0,     0,    35,     0,    19,    43,    14,    47,     0,
      43,    31,     0,     0,    42,     0,     0,    34,     0,    44,
       0,    39,    46,     0,     0,    49,     0,     0,    36,    41,
       0,    52,     0,    45,    48,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,    69,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    54,    47,     0,    50,    69,     0,     0,     0,
      82,    83,     0,     0,     0,     0,     0,   115,     0,     0,
       0,     0,   103,   104,   110,     0,   108,     0,   106,     0,
     105,    71,     0,     0,    56,    69,    58,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,    29,     0,   114,
       0,   110,     0,     0,   102,     0,    99,   100,   115,     0,
       0,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,    30,    55,     0,     0,
       0,     0,     0,     0,     0,     0,    74,   111,     0,   112,
       0,     0,   109,     0,   107,   101,    86,    87,    88,    89,
      96,    90,    93,    91,    92,    94,    95,    78,    77,    40,
       0,     0,     0,     0,    72,    73,   113,    70,    75,    76,
     112,     0,     0,     0,     0,    85,     0,     0,     0,    84,
       0,    80,    81,     0,    79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   -98,   -98,   374,   -98,   -98,   354,   -98,   -98,
     370,   -98,     0,   -98,   -76,   -98,   346,   -98,   -98,   376,
     -98,   347,   351,   291,   -98,   336,   -98,    39,   -98,   260,
     -25,   -84,   -97,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -69,   -74,   243
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     8,     9,    10,    36,    37,    14,    23,
      24,    38,    62,    29,   138,    43,    44,    60,    30,    31,
      80,    63,    64,    66,    74,    75,    82,     5,    51,    77,
     116,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   159,   140,   160
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,   117,   111,   146,   125,   143,   122,     1,   143,    98,
       6,   111,    15,    25,    98,     7,   111,     7,     2,   125,
     146,   142,   143,    25,    98,   146,   111,   139,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   171,
     172,    98,   222,   111,   194,   195,    98,   155,   111,   151,
     152,    99,    11,    32,   162,    12,   126,   158,   127,    70,
     163,    13,    17,    70,   198,    73,   198,    18,   170,    47,
     235,    39,    71,   185,    73,   145,    78,   199,   188,   230,
     191,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,    42,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   175,   176,   177,    52,    45,
      53,   220,    19,    50,   223,    33,    20,    21,    22,   226,
      34,    35,    58,   192,    26,   146,   146,   232,   233,    27,
      28,    48,    57,   146,   201,    98,    98,   111,   111,    19,
      56,    59,   240,    40,    21,    22,    98,    98,   111,   111,
      98,    54,   111,    55,    98,    65,   111,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   114,    67,   115,   130,    69,    76,    85,    86,   205,
      87,    88,    89,   125,   126,    81,   168,   112,    90,   153,
     231,   113,    91,    92,    33,   120,    93,    94,    95,    34,
      35,   234,   131,   132,   133,   134,    96,    19,   121,   118,
     197,    72,    21,    22,   166,   167,   119,    97,   135,   136,
     126,   123,   168,   124,   137,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,    19,   128,
     129,   141,    83,    21,    22,   144,   184,   147,   156,   149,
      85,    86,   236,    87,    88,    89,   154,   217,   237,   164,
     157,    90,   161,   165,   169,    91,    92,   186,   218,    93,
      94,    95,    85,    86,   187,    87,    88,    89,   200,    96,
      19,   196,   238,    90,   190,    21,    22,    91,    92,   193,
      97,    93,    94,    95,    85,    86,   202,    87,    88,    89,
     219,    96,   243,   204,   221,    90,   222,   224,   225,    91,
      92,   227,    97,    93,    94,    95,    85,    86,   228,    87,
      88,    89,    16,    96,   229,   239,   241,    90,   242,   244,
      49,    91,    92,    41,    97,    93,    94,    95,    85,    86,
      61,   150,    88,    89,   148,    96,    46,    68,   189,    90,
      84,   203,     0,    91,    92,     0,    97,    93,    94,    95,
       0,    79,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     173,   174,   175,   176,   177,    -1,    -1,    -1,    -1,    -1,
      -1
};

static const yytype_int16 yycheck[] =
{
      76,    85,    76,   100,    15,    15,    90,    29,    15,    85,
      30,    85,    30,    13,    90,    35,    90,    35,    40,    15,
     117,    14,    15,    23,   100,   122,   100,    96,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    46,
      47,   117,    16,   117,    55,    55,   122,   123,   122,   118,
     119,    76,    43,    14,   128,     0,    52,   126,    54,    42,
     129,    38,    50,    42,    42,    65,    42,    54,   137,    30,
      44,    55,    55,   142,    74,   100,    55,    55,   147,    55,
      55,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    35,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,     5,     6,     7,    52,    35,
      54,   190,    35,    35,   193,    35,    39,    40,    41,   198,
      40,    41,    50,    55,    35,   232,   233,   221,   222,    40,
      41,    51,    44,   240,    55,   221,   222,   221,   222,    35,
      54,    33,   236,    39,    40,    41,   232,   233,   232,   233,
     236,    42,   236,    44,   240,    38,   240,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    42,    53,    44,     4,    35,    22,    16,    17,    55,
      19,    20,    21,    15,    52,    35,    54,    51,    27,    28,
      55,    50,    31,    32,    35,    44,    35,    36,    37,    40,
      41,    55,    32,    33,    34,    35,    45,    35,    44,    54,
      53,    39,    40,    41,    46,    47,    54,    56,    48,    49,
      52,    54,    54,    54,    54,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    35,    54,
      54,    44,    39,    40,    41,    23,    44,    14,    55,    35,
      16,    17,    18,    19,    20,    21,    35,    44,    24,    33,
      35,    27,    35,    54,    54,    31,    32,    35,    44,    35,
      36,    37,    16,    17,    23,    19,    20,    21,    55,    45,
      35,    44,    26,    27,    54,    40,    41,    31,    32,    54,
      56,    35,    36,    37,    16,    17,    55,    19,    20,    21,
      51,    45,    24,    55,    25,    27,    16,    44,    44,    31,
      32,    44,    56,    35,    36,    37,    16,    17,    44,    19,
      20,    21,     8,    45,    44,    44,    44,    27,    44,    44,
      36,    31,    32,    23,    56,    35,    36,    37,    16,    17,
      54,    19,    20,    21,   113,    45,    30,    60,   148,    27,
      74,   168,    -1,    31,    32,    -1,    56,    35,    36,    37,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    40,    58,    59,    84,    30,    35,    60,    61,
      62,    43,     0,    38,    65,    30,    61,    50,    54,    35,
      39,    40,    41,    66,    67,    69,    35,    40,    41,    70,
      75,    76,    84,    35,    40,    41,    63,    64,    68,    55,
      39,    67,    35,    72,    73,    35,    76,    84,    51,    64,
      35,    85,    52,    54,    42,    44,    54,    44,    50,    33,
      74,    73,    69,    78,    79,    38,    80,    53,    78,    35,
      42,    55,    39,    69,    81,    82,    22,    86,    55,    79,
      77,    35,    83,    39,    82,    16,    17,    19,    20,    21,
      27,    31,    32,    35,    36,    37,    45,    56,    71,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,   100,    51,    50,    42,    44,    87,    88,    54,    54,
      44,    44,    88,    54,    54,    15,    52,    54,    54,    54,
       4,    32,    33,    34,    35,    48,    49,    54,    71,    99,
     100,    44,    14,    15,    23,    87,    89,    14,    80,    35,
      19,    99,    99,    28,    35,    71,    55,    35,    99,    99,
     101,    35,   100,    99,    33,    54,    46,    47,    54,    54,
      99,    46,    47,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    44,    99,    35,    23,    99,    86,
      54,    55,    55,    54,    55,    55,    44,    53,    42,    55,
      55,    55,    55,   101,    55,    55,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    44,    44,    51,
      99,    25,    16,    99,    44,    44,    99,    44,    44,    44,
      55,    55,    88,    88,    55,    44,    18,    24,    26,    44,
      88,    44,    44,    24,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    59,    59,    59,    60,    60,
      61,    62,    63,    63,    64,    65,    65,    66,    66,    67,
      68,    68,    68,    69,    69,    69,    70,    70,    70,    71,
      71,    72,    72,    73,    73,    74,    73,    75,    75,    77,
      76,    78,    78,    78,    79,    80,    80,    80,    81,    81,
      82,    83,    83,    85,    84,    86,    86,    87,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    91,    92,    92,    93,
      93,    94,    95,    96,    97,    98,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   100,   101,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     1,     3,     2,     0,     2,     1,
       4,     1,     2,     1,     3,     3,     2,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     1,     4,     0,     5,     2,     1,     0,
      10,     3,     1,     0,     2,     3,     2,     0,     2,     1,
       3,     3,     1,     0,     9,     4,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     2,     5,     5,     4,     5,     5,     4,     4,    10,
       8,     8,     2,     2,     7,     7,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     2,     1,     1,     1,     1,     3,     1,     3,
       1,     4,     4,     3,     1,     0
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
  case 2: /* Program: TypeDefBlock GDeclBlock FDefBlock MainBlock  */
#line 48 "first.y"
{
    printf("\nGST AFTER GLOBAL DECLARATIONS\n");
          printGSymbolTable();
    printTypeTable();
          (yyval.node) = (yyvsp[0].node);
     fclose(out);
}
#line 1559 "y.tab.c"
    break;

  case 3: /* Program: TypeDefBlock GDeclBlock MainBlock  */
#line 56 "first.y"
        {
          printf("\nGST AFTER GLOBAL DECLARATIONS\n");
          printGSymbolTable();
            printTypeTable();
          (yyval.node) = (yyvsp[0].node);
          fclose(out);
      }
#line 1571 "y.tab.c"
    break;

  case 4: /* Program: MainBlock  */
#line 63 "first.y"
                    {fclose(out);}
#line 1577 "y.tab.c"
    break;

  case 10: /* TypeDef: UserDefinedType LBRACE FieldDeclList RBRACE  */
#line 73 "first.y"
                                                      { TInstall((yyvsp[-3].node)->varname, Fhead); }
#line 1583 "y.tab.c"
    break;

  case 11: /* UserDefinedType: ID  */
#line 76 "first.y"
                    {
                        tempTNode = (yyvsp[0].node);
                        (yyval.node) = (yyvsp[0].node);
                    }
#line 1592 "y.tab.c"
    break;

  case 14: /* FieldDecl: FieldType ID SEMI  */
#line 85 "first.y"
                             {
                                if(FLookup((yyvsp[-1].node)->varname, Fhead) != NULL) {
                                    fprintf(stderr,"Re-declaration of Field element %s\n", (yyvsp[-1].node)->varname);
                                    yyerror("");
                                    exit(1);
                                }
                                FInstall((yyvsp[-1].node)->varname, declaration_type);
                            }
#line 1605 "y.tab.c"
    break;

  case 15: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 94 "first.y"
                                     {initialize(); }
#line 1611 "y.tab.c"
    break;

  case 16: /* GDeclBlock: DECL ENDDECL  */
#line 95 "first.y"
                           {initialize(); }
#line 1617 "y.tab.c"
    break;

  case 20: /* FieldType: T_INT  */
#line 104 "first.y"
                  {declaration_type=TLookup("int");}
#line 1623 "y.tab.c"
    break;

  case 21: /* FieldType: T_STR  */
#line 105 "first.y"
                  {declaration_type=TLookup("str");}
#line 1629 "y.tab.c"
    break;

  case 22: /* FieldType: ID  */
#line 106 "first.y"
               {
                declaration_type=TLookup((yyvsp[0].node)->varname); 
                if(declaration_type == NULL) {
                    if(strcmp(tempTNode->varname, (yyvsp[0].node)->varname) == 0) {
                        declaration_type = TLookup(tempTNode->varname);
                    } else {
                        
                        fprintf(stderr,"Undefined type %s", (yyvsp[0].node)->varname);
                        exit(1);
                    }
                }
          }
#line 1646 "y.tab.c"
    break;

  case 23: /* Type: T_INT  */
#line 119 "first.y"
              {declaration_type = TLookup("int");}
#line 1652 "y.tab.c"
    break;

  case 24: /* Type: T_STR  */
#line 120 "first.y"
             {declaration_type = TLookup("str");}
#line 1658 "y.tab.c"
    break;

  case 25: /* Type: ID  */
#line 121 "first.y"
            {
                declaration_type = TLookup((yyvsp[0].node)->varname);
                if(declaration_type == NULL) {
                    fprintf(stderr,"Unknown user-defined type %s\n", (yyvsp[0].node)->varname);
                    exit(1);
                }
            }
#line 1670 "y.tab.c"
    break;

  case 26: /* Ftype: T_INT  */
#line 130 "first.y"
              {fdeclaration_type = TLookup("int");}
#line 1676 "y.tab.c"
    break;

  case 27: /* Ftype: T_STR  */
#line 131 "first.y"
             {fdeclaration_type = TLookup("str");}
#line 1682 "y.tab.c"
    break;

  case 28: /* Ftype: ID  */
#line 132 "first.y"
            {
                // printTypeTable();
                fdeclaration_type = TLookup((yyvsp[0].node)->varname);
                printf("type is set to %p %s %d\n", fdeclaration_type, (yyvsp[0].node)->varname, yylineno);
                printf("type is set to %s\n", fdeclaration_type->name);
                if(fdeclaration_type == NULL) {
                    fprintf(stderr,"Unknown user-defined type %s\n", (yyvsp[0].node)->varname);
                    exit(1);
                }
            }
#line 1697 "y.tab.c"
    break;

  case 29: /* Field: ID DOT ID  */
#line 143 "first.y"
                        {
                            assignType((yyvsp[-2].node), 0);
                            assignTypeField((yyvsp[0].node), (yyvsp[-2].node)->type->fields);
                            (yyval.node) = createTree((yyvsp[0].node)->type, NULL, FIELD_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
                        }
#line 1707 "y.tab.c"
    break;

  case 30: /* Field: Field DOT ID  */
#line 148 "first.y"
                        {
                            (yyval.node) = insertFieldId((yyvsp[-2].node), (yyvsp[0].node));
                        }
#line 1715 "y.tab.c"
    break;

  case 33: /* Gid: ID  */
#line 156 "first.y"
         {
     checkAvailability((yyvsp[0].node)->varname,1);   
     
     GInstall((yyvsp[0].node)->varname,declaration_type,1,NULL);
}
#line 1725 "y.tab.c"
    break;

  case 34: /* Gid: ID LBRACK NUM RBRACK  */
#line 161 "first.y"
                           {
        checkAvailability((yyvsp[-3].node)->varname,1);   
        if((yyvsp[-1].node)->value.intval < 1) {
        yyerror("Invalid array size");
        exit(1);
    }
     GInstall((yyvsp[-3].node)->varname,declaration_type,(yyvsp[-1].node)->value.intval,NULL);
    }
#line 1738 "y.tab.c"
    break;

  case 35: /* $@1: %empty  */
#line 169 "first.y"
                {
        saved_decl_type = declaration_type;  
    }
#line 1746 "y.tab.c"
    break;

  case 36: /* Gid: ID LPAREN $@1 ParamList RPAREN  */
#line 172 "first.y"
                     {
        declCount++;
        checkAvailability((yyvsp[-4].node)->varname,1);
        GInstall((yyvsp[-4].node)->varname,saved_decl_type,-1,Phead);
        Phead=NULL;
        Ptail=NULL;
    }
#line 1758 "y.tab.c"
    break;

  case 39: /* $@2: %empty  */
#line 184 "first.y"
                                        {
           /* mid-rule action: set return type BEFORE parsing body */
           current_function_type = fdeclaration_type;
       }
#line 1767 "y.tab.c"
    break;

  case 40: /* FDef: Ftype ID LPAREN ParamList RPAREN $@2 LBRACE LDeclBlock Body RBRACE  */
#line 188 "first.y"
        {
            // localbindingstart = 1;
            defCount++;
            Gtemp = GLookup((yyvsp[-8].node)->varname);
            current_function_type = fdeclaration_type;
            if(Gtemp == NULL) {
                fprintf(stderr,"Function %s not declared", (yyvsp[-8].node)->varname);
                yyerror("");
                exit(1);
            }
            if(Gtemp->type != fdeclaration_type) {
                fprintf(stderr,"%s : Function type does not match declaration", (yyvsp[-8].node)->varname);
                yyerror("");
                exit(1);
            }
            
            argList1 = Phead;
            argList2 = Gtemp->paramlist;

            while(argList1 != NULL && argList2 != NULL) {
                if(argList1->type != argList2->type) {
                    fprintf(stderr,"%s : Conflict in argument types", (yyvsp[-8].node)->varname);
                    yyerror("");
                    exit(1);
                }

                if(strcmp(argList1->name, argList2->name)) {
                    fprintf(stderr,"%s : Conflict in argument names", (yyvsp[-8].node)->varname);
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
            current_function_type,   // return type
            NULL,
            FUN_DEF_NODE,        // function node
            (yyvsp[-8].node)->varname,         // function name
            NULL,
            (yyvsp[-1].node),                  // body AST
            NULL,
            NULL
        );
        printf("\nFUNCTION AST: %s\n", (yyvsp[-8].node)->varname);
        print(funcTree);
        printf("\nLOCAL SYMBOL TABLE (%s)\n", (yyvsp[-8].node)->varname);
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
#line 1852 "y.tab.c"
    break;

  case 44: /* Param: Type ID  */
#line 274 "first.y"
                {
    struct Typetable *ptype = declaration_type;
    printf("Installing param %s of type %s\n", 
           (yyvsp[0].node)->varname, ptype->name); 
                    checkAvailability((yyvsp[0].node)->varname, 0);
                    PInstall((yyvsp[0].node)->varname, ptype);
                }
#line 1864 "y.tab.c"
    break;

  case 45: /* LDeclBlock: DECL LDeclList ENDDECL  */
#line 282 "first.y"
                                    {InstallParamsInLocal();}
#line 1870 "y.tab.c"
    break;

  case 46: /* LDeclBlock: DECL ENDDECL  */
#line 283 "first.y"
                           {InstallParamsInLocal();}
#line 1876 "y.tab.c"
    break;

  case 47: /* LDeclBlock: %empty  */
#line 284 "first.y"
              {InstallParamsInLocal();}
#line 1882 "y.tab.c"
    break;

  case 51: /* IdList: IdList COMMA ID  */
#line 291 "first.y"
                         {
            checkAvailability((yyvsp[0].node)->varname, 0);
            LInstall((yyvsp[0].node)->varname, declaration_type);
            localbindingstart++;
        }
#line 1892 "y.tab.c"
    break;

  case 52: /* IdList: ID  */
#line 296 "first.y"
         {
                    checkAvailability((yyvsp[0].node)->varname, 0);
                    LInstall((yyvsp[0].node)->varname, declaration_type);
                    localbindingstart++;
                }
#line 1902 "y.tab.c"
    break;

  case 53: /* $@3: %empty  */
#line 304 "first.y"
{
    current_function_type = TLookup("int");   // 🔥 FIX HERE
}
#line 1910 "y.tab.c"
    break;

  case 54: /* MainBlock: T_INT MAIN LPAREN RPAREN $@3 LBRACE LDeclBlock Body RBRACE  */
#line 306 "first.y"
                               {

    if(defCount != declCount) {
        yyerror("All functions declared need to be defined\n");
        exit(1);
    }

    // printf("reached main with %d\n", localbindingstart);
    // if(declaration_type != INT) {
    //     yyerror("Main return type should be of int type\n");
    //     exit(1);
    // }
    current_function_type = TLookup("int");
    struct tnode *mainTree =
        createTree(
            TLookup("int"),
            NULL,
            FUN_DEF_NODE,
            "main",
            NULL,
            (yyvsp[-1].node),
            NULL,
            NULL
        );

    printf("\nFUNCTION AST: main\n");
    print(mainTree);

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
#line 1966 "y.tab.c"
    break;

  case 55: /* Body: KW_BEGIN Slist RetStmt END  */
#line 358 "first.y"
                                  {(yyval.node) = createTree(TLookup("void"), NULL,CONNECTOR_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[-1].node), NULL);}
#line 1972 "y.tab.c"
    break;

  case 56: /* Body: KW_BEGIN RetStmt END  */
#line 359 "first.y"
                           {(yyval.node) = (yyvsp[-1].node);}
#line 1978 "y.tab.c"
    break;

  case 57: /* RetStmt: RETURN expr SEMI  */
#line 361 "first.y"
                             {
     if((yyvsp[-1].node)->type == NULL) {
        printf("ERROR: NULL type in return\n");
        exit(1);
    }

                                printf("curre %p , expr %p\n",current_function_type, (yyvsp[-1].node)->type);
                                printf("curre %s , expr %s\n",current_function_type->name, (yyvsp[-1].node)->type->name);
                                if(strcmp(current_function_type->name,(yyvsp[-1].node)->type->name)==0) {
                                    (yyval.node) = createTree(TLookup("void"), NULL,RET_NODE, NULL, NULL, (yyvsp[-1].node), NULL, NULL);
                                } else {
                                    yyerror("Return type mismatch");
                                    exit(1);
                                }
                            }
#line 1998 "y.tab.c"
    break;

  case 58: /* Slist: Slist Stmt  */
#line 378 "first.y"
                   {(yyval.node) = createTree(TLookup("void"), NULL,CONNECTOR_NODE, NULL, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);}
#line 2004 "y.tab.c"
    break;

  case 59: /* Slist: Stmt  */
#line 379 "first.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 2010 "y.tab.c"
    break;

  case 60: /* Stmt: InputStmt  */
#line 382 "first.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2016 "y.tab.c"
    break;

  case 61: /* Stmt: OutputStmt  */
#line 383 "first.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 2022 "y.tab.c"
    break;

  case 62: /* Stmt: AsgStmt  */
#line 384 "first.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 2028 "y.tab.c"
    break;

  case 63: /* Stmt: IfStmt  */
#line 385 "first.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 2034 "y.tab.c"
    break;

  case 64: /* Stmt: WhileStmt  */
#line 386 "first.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2040 "y.tab.c"
    break;

  case 65: /* Stmt: BrkStmt  */
#line 387 "first.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2046 "y.tab.c"
    break;

  case 66: /* Stmt: ContStmt  */
#line 388 "first.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2052 "y.tab.c"
    break;

  case 67: /* Stmt: repeatUntilStmt  */
#line 389 "first.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 2058 "y.tab.c"
    break;

  case 68: /* Stmt: doWhileStmt  */
#line 390 "first.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2064 "y.tab.c"
    break;

  case 69: /* Stmt: RetStmt  */
#line 391 "first.y"
             {(yyval.node)=(yyvsp[0].node);}
#line 2070 "y.tab.c"
    break;

  case 70: /* Stmt: ID LPAREN ExprList RPAREN SEMI  */
#line 392 "first.y"
                                     {
    assignType((yyvsp[-4].node),1);
    (yyvsp[-4].node)->nodetype = FUN_NODE;
    (yyvsp[-4].node)->argList = (yyvsp[-2].node);

    struct Gsymbol *g = GLookup((yyvsp[-4].node)->varname);
    if(g == NULL) {
        fprintf(stderr, "Function %s not declared\n", (yyvsp[-4].node)->varname);
        exit(1);
    }

    (yyvsp[-4].node)->type = g->type;   // 🔥 CRITICAL FIX

    checkFunctionArgs(g, g->paramlist, (yyvsp[-4].node)->argList);

    (yyval.node) = (yyvsp[-4].node);
}
#line 2092 "y.tab.c"
    break;

  case 71: /* Stmt: KW_BRKP SEMI  */
#line 409 "first.y"
                        { (yyval.node) = createTree(TLookup("void"), NULL, BRKP_NODE, NULL, NULL, NULL, NULL, NULL); }
#line 2098 "y.tab.c"
    break;

  case 72: /* Stmt: FREE LPAREN ID RPAREN SEMI  */
#line 410 "first.y"
                                 {
        assignType((yyvsp[-2].node),0);
        if((yyvsp[-2].node)->type == TLookup("int") || (yyvsp[-2].node)->type == TLookup("str")) {
            yyerror("Cannot FREE a string or int variable\n");
            exit(1);
        }
        (yyval.node) = createTree(TLookup("void"),NULL, FREE_NODE, NULL, NULL, (yyvsp[-2].node), NULL, NULL);
    }
#line 2111 "y.tab.c"
    break;

  case 73: /* Stmt: FREE LPAREN Field RPAREN SEMI  */
#line 418 "first.y"
                                        {
                                    if((yyvsp[-2].node)->type == TLookup("int") || (yyvsp[-2].node)->type == TLookup("str")) {
                                        yyerror("Cannot FREE a string or integer variable\n");
                                        exit(1);
                                    }
                                    (yyval.node) = createTree(TLookup("void"),NULL, FREE_NODE, NULL, NULL, (yyvsp[-2].node), NULL, NULL);
     }
#line 2123 "y.tab.c"
    break;

  case 74: /* Stmt: INIT LPAREN RPAREN SEMI  */
#line 425 "first.y"
                                      {(yyval.node) = createTree(TLookup("void"),NULL, INIT_NODE, NULL, NULL, NULL, NULL, NULL);}
#line 2129 "y.tab.c"
    break;

  case 75: /* InputStmt: READ LPAREN id RPAREN SEMI  */
#line 428 "first.y"
                                       {
    (yyval.node) = createTree(TLookup("void"), NULL,READ_NODE, NULL, NULL, (yyvsp[-2].node),NULL, NULL);
}
#line 2137 "y.tab.c"
    break;

  case 76: /* OutputStmt: WRITE LPAREN expr RPAREN SEMI  */
#line 432 "first.y"
                                           {
            (yyval.node) = createTree(TLookup("void"), NULL,WRITE_NODE, NULL, NULL, (yyvsp[-2].node), NULL, NULL);
            
}
#line 2146 "y.tab.c"
    break;

  case 77: /* AsgStmt: id ASSIGN expr SEMI  */
#line 437 "first.y"
                               {
            if ((yyvsp[-1].node)->nodetype == ALLOC_NODE) {
        (yyvsp[-1].node)->type = (yyvsp[-3].node)->type;
    }   
            typecheck((yyvsp[-3].node)->type, (yyvsp[-1].node)->type, '=');
            (yyval.node) = createTree(TLookup("void"), NULL,ASSIGN_NODE, NULL, NULL, (yyvsp[-3].node), (yyvsp[-1].node), NULL);
        }
#line 2158 "y.tab.c"
    break;

  case 78: /* AsgStmt: Field ASSIGN expr SEMI  */
#line 459 "first.y"
                                          {
         if ((yyvsp[-1].node)->nodetype == ALLOC_NODE) {
        (yyvsp[-1].node)->type = (yyvsp[-3].node)->type;
    }
                                            typecheck((yyvsp[-3].node)->type, (yyvsp[-1].node)->type, '=');
                                            (yyval.node) = createTree(TLookup("void"), NULL,ASSIGN_NODE, NULL, NULL, (yyvsp[-3].node), (yyvsp[-1].node), NULL);
                    
                                        }
#line 2171 "y.tab.c"
    break;

  case 79: /* IfStmt: IF LPAREN expr RPAREN THEN Slist ELSE Slist ENDIF SEMI  */
#line 483 "first.y"
                                                                {
        typecheck((yyvsp[-7].node)->type, TLookup("bool"), 'e');
        (yyval.node) = createTree(TLookup("void"), NULL,IF_ELSE_NODE, NULL, NULL, (yyvsp[-7].node), (yyvsp[-2].node), (yyvsp[-4].node));
}
#line 2180 "y.tab.c"
    break;

  case 80: /* IfStmt: IF LPAREN expr RPAREN THEN Slist ENDIF SEMI  */
#line 487 "first.y"
                                                  {
        typecheck((yyvsp[-5].node)->type, TLookup("bool"), 'i');
        (yyval.node) = createTree(TLookup("void"), NULL,IF_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-2].node),NULL);
}
#line 2189 "y.tab.c"
    break;

  case 81: /* WhileStmt: WHILE LPAREN expr RPAREN DO Slist ENDWHILE SEMI  */
#line 492 "first.y"
                                                           {
        typecheck((yyvsp[-5].node)->type,TLookup("bool"), 'w');
        (yyval.node) = createTree(TLookup("void"), NULL,WHILE_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
}
#line 2198 "y.tab.c"
    break;

  case 82: /* BrkStmt: BREAK SEMI  */
#line 497 "first.y"
                     {
    (yyval.node) = createTree(TLookup("void"), NULL,BREAK_NODE, NULL, NULL, NULL, NULL, NULL);
}
#line 2206 "y.tab.c"
    break;

  case 83: /* ContStmt: CONT SEMI  */
#line 501 "first.y"
                    {
    (yyval.node) = createTree(TLookup("void"), NULL,CONT_NODE, NULL, NULL, NULL, NULL, NULL);
}
#line 2214 "y.tab.c"
    break;

  case 84: /* repeatUntilStmt: REPEAT Slist UNTIL LPAREN expr RPAREN SEMI  */
#line 505 "first.y"
                                                            {
    typecheck((yyvsp[-2].node)->type, TLookup("bool"), 'r');
    (yyval.node) = createTree(TLookup("void"), NULL, REPEAT_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
}
#line 2223 "y.tab.c"
    break;

  case 85: /* doWhileStmt: DO Slist WHILE LPAREN expr RPAREN SEMI  */
#line 510 "first.y"
                                                    {
    typecheck((yyvsp[-2].node)->type, TLookup("bool"), 'd');
    (yyval.node) = createTree(TLookup("void"), NULL, DOWHILE_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
}
#line 2232 "y.tab.c"
    break;

  case 86: /* expr: expr PLUS expr  */
#line 516 "first.y"
                      {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(TLookup("int"),NULL, ADD_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2241 "y.tab.c"
    break;

  case 87: /* expr: expr MINUS expr  */
#line 520 "first.y"
                     {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(TLookup("int"),NULL, SUB_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2250 "y.tab.c"
    break;

  case 88: /* expr: expr MUL expr  */
#line 524 "first.y"
                   {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(TLookup("int"),NULL, MUL_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2259 "y.tab.c"
    break;

  case 89: /* expr: expr DIV expr  */
#line 528 "first.y"
                   {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(TLookup("int"),NULL, DIV_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2268 "y.tab.c"
    break;

  case 90: /* expr: expr LT expr  */
#line 532 "first.y"
                   {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(TLookup("bool"),NULL, LT_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2277 "y.tab.c"
    break;

  case 91: /* expr: expr LE expr  */
#line 536 "first.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(TLookup("bool"),NULL, LE_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2286 "y.tab.c"
    break;

  case 92: /* expr: expr GE expr  */
#line 540 "first.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(TLookup("bool"),NULL, GE_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2295 "y.tab.c"
    break;

  case 93: /* expr: expr GT expr  */
#line 544 "first.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(TLookup("bool"),NULL, GT_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2304 "y.tab.c"
    break;

  case 94: /* expr: expr NE expr  */
#line 548 "first.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(TLookup("bool"),NULL, NE_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2313 "y.tab.c"
    break;

  case 95: /* expr: expr EQ expr  */
#line 552 "first.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(TLookup("bool"),NULL, EQ_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2322 "y.tab.c"
    break;

  case 96: /* expr: expr MOD expr  */
#line 556 "first.y"
                   {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(TLookup("int"),NULL, MOD_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2331 "y.tab.c"
    break;

  case 97: /* expr: Field EQNILL  */
#line 560 "first.y"
                      {
                            typecheck((yyvsp[-1].node)->type, NULL, '!');
                            (yyval.node) = createTree(TLookup("bool"),NULL, EQ_NODE,  NULL, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                        }
#line 2340 "y.tab.c"
    break;

  case 98: /* expr: Field NEQNILL  */
#line 564 "first.y"
                        {
                            typecheck((yyvsp[-1].node)->type, NULL, '!');
                            (yyval.node) = createTree(TLookup("bool"),NULL, NE_NODE, NULL, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                        }
#line 2349 "y.tab.c"
    break;

  case 99: /* expr: ID EQNILL  */
#line 568 "first.y"
                       {
                            assignType((yyvsp[-1].node), 0);
                            (yyval.node) = createTree(TLookup("bool"),NULL, EQ_NODE,  NULL, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                        }
#line 2358 "y.tab.c"
    break;

  case 100: /* expr: ID NEQNILL  */
#line 572 "first.y"
                        {
                            assignType((yyvsp[-1].node), 0);
                            (yyval.node) = createTree(TLookup("bool"),NULL, NE_NODE, NULL, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                        }
#line 2367 "y.tab.c"
    break;

  case 101: /* expr: LPAREN expr RPAREN  */
#line 576 "first.y"
                         {(yyval.node) = (yyvsp[-1].node);}
#line 2373 "y.tab.c"
    break;

  case 102: /* expr: MINUS NUM  */
#line 577 "first.y"
                {
        (yyvsp[0].node)->value.intval=-1*((yyvsp[0].node)->value.intval);
        (yyval.node) = (yyvsp[0].node);
        (yyval.node)->type=TLookup("int");
        }
#line 2383 "y.tab.c"
    break;

  case 103: /* expr: NUM  */
#line 582 "first.y"
          {
        (yyval.node) = (yyvsp[0].node);
        (yyval.node)->type=TLookup("int");
        }
#line 2392 "y.tab.c"
    break;

  case 104: /* expr: STRVAL  */
#line 586 "first.y"
             {
        (yyval.node) = (yyvsp[0].node);
        (yyval.node)->type=TLookup("str");
        }
#line 2401 "y.tab.c"
    break;

  case 105: /* expr: id  */
#line 590 "first.y"
         {(yyval.node) = (yyvsp[0].node);}
#line 2407 "y.tab.c"
    break;

  case 106: /* expr: Field  */
#line 591 "first.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 2413 "y.tab.c"
    break;

  case 107: /* expr: ALLOC LPAREN RPAREN  */
#line 592 "first.y"
                          {
        (yyval.node) = (yyvsp[-2].node); 
        (yyval.node)->type = TLookup("void");  
    }
#line 2422 "y.tab.c"
    break;

  case 108: /* expr: NILL  */
#line 596 "first.y"
          {
        (yyval.node)=createTree(TLookup("void"),NULL,NULL_NODE,NULL,NULL,NULL,NULL,NULL);
    }
#line 2430 "y.tab.c"
    break;

  case 109: /* expr: INIT LPAREN RPAREN  */
#line 600 "first.y"
    {(yyval.node) = createTree(TLookup("int"),NULL, INIT_NODE, NULL, NULL, NULL, NULL, NULL);}
#line 2436 "y.tab.c"
    break;

  case 110: /* id: ID  */
#line 602 "first.y"
        {
        assignType((yyvsp[0].node),0);
        (yyval.node)=(yyvsp[0].node);
    }
#line 2445 "y.tab.c"
    break;

  case 111: /* id: ID LBRACK expr RBRACK  */
#line 610 "first.y"
                            {
        assignType((yyvsp[-3].node),2);
        (yyval.node)=createTree((yyvsp[-3].node)->type,NULL,ARRAY_NODE,NULL,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
    }
#line 2454 "y.tab.c"
    break;

  case 112: /* id: ID LPAREN ExprList RPAREN  */
#line 614 "first.y"
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
    (yyvsp[-3].node)->type=g->type;
    printf("function %s type %s\n",(yyvsp[-3].node)->varname,g->type->name);
    
    checkFunctionArgs(g,g->paramlist, (yyvsp[-3].node)->argList);
    (yyval.node)=(yyvsp[-3].node);
    printf("function call type %s %s\n",(yyvsp[-3].node)->type->name,(yyvsp[-3].node)->varname);
}
#line 2476 "y.tab.c"
    break;

  case 113: /* ExprList: ExprList COMMA expr  */
#line 634 "first.y"
                              {
                                (yyval.node) = createTree(
                                    TLookup("void"),
                                    NULL,
                                    CONNECTOR_NODE,
                                    NULL,
                                    NULL,
                                    (yyvsp[-2].node),
                                    (yyvsp[0].node),
                                    NULL
                                );
                            }
#line 2493 "y.tab.c"
    break;

  case 114: /* ExprList: expr  */
#line 646 "first.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2499 "y.tab.c"
    break;

  case 115: /* ExprList: %empty  */
#line 647 "first.y"
                            {(yyval.node) = NULL;}
#line 2505 "y.tab.c"
    break;


#line 2509 "y.tab.c"

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

#line 656 "first.y"

void initSymbolTables(void) {
    Ghead = Gtail = NULL;
    Lhead = Ltail = NULL;
    Phead = Ptail = NULL;

    declaration_type = NULL;
    fdeclaration_type = NULL;
    start = 4096;
    // printf("initialized: 1\n");
    localbindingstart = 1;
    flabelcount = 0;
    declCount = 0;
    defCount = 0;
}
void yyerror(char const *msg) {
    fprintf(stderr,
        "Syntax error at line %d near '%s' with msg: %s\n",
        yylineno, yytext, msg);
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
    TypeTableCreate();
    initSymbolTables();
    yyin = source_file;
    return yyparse();
}
