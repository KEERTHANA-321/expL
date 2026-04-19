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
    #include <string.h>
    #include "symbolTable.h"
    #include "constants.h"
    #include "nodestructure.h"
    #include "typecheck.h"
    #include "typetable.h"
    #include "classtable.h"
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

#line 95 "y.tab.c"

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
    KW_BRKP = 311,                 /* KW_BRKP  */
    CLASS = 312,                   /* CLASS  */
    ENDCLASS = 313,                /* ENDCLASS  */
    DELETE = 314,                  /* DELETE  */
    SELF = 315,                    /* SELF  */
    NEW = 316                      /* NEW  */
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
#define CLASS 312
#define ENDCLASS 313
#define DELETE 314
#define SELF 315
#define NEW 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "parser.y"

    struct tnode *node;

#line 274 "y.tab.c"

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
  YYSYMBOL_CLASS = 57,                     /* CLASS  */
  YYSYMBOL_ENDCLASS = 58,                  /* ENDCLASS  */
  YYSYMBOL_DELETE = 59,                    /* DELETE  */
  YYSYMBOL_SELF = 60,                      /* SELF  */
  YYSYMBOL_NEW = 61,                       /* NEW  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_Program = 63,                   /* Program  */
  YYSYMBOL_TypeDefBlock = 64,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 65,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 66,                   /* TypeDef  */
  YYSYMBOL_UserDefinedType = 67,           /* UserDefinedType  */
  YYSYMBOL_FieldDeclList = 68,             /* FieldDeclList  */
  YYSYMBOL_FieldDecl = 69,                 /* FieldDecl  */
  YYSYMBOL_ClassDefBlock = 70,             /* ClassDefBlock  */
  YYSYMBOL_ClassDefList = 71,              /* ClassDefList  */
  YYSYMBOL_ClassDef = 72,                  /* ClassDef  */
  YYSYMBOL_Cname = 73,                     /* Cname  */
  YYSYMBOL_ClassFieldDeclList = 74,        /* ClassFieldDeclList  */
  YYSYMBOL_ClassFieldDecl = 75,            /* ClassFieldDecl  */
  YYSYMBOL_ClassType = 76,                 /* ClassType  */
  YYSYMBOL_ClassMethodDefns = 77,          /* ClassMethodDefns  */
  YYSYMBOL_GDeclBlock = 78,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 79,                 /* GDeclList  */
  YYSYMBOL_GDecl = 80,                     /* GDecl  */
  YYSYMBOL_FieldType = 81,                 /* FieldType  */
  YYSYMBOL_Type = 82,                      /* Type  */
  YYSYMBOL_Ftype = 83,                     /* Ftype  */
  YYSYMBOL_Field = 84,                     /* Field  */
  YYSYMBOL_FieldFunction = 85,             /* FieldFunction  */
  YYSYMBOL_GidList = 86,                   /* GidList  */
  YYSYMBOL_Gid = 87,                       /* Gid  */
  YYSYMBOL_88_1 = 88,                      /* $@1  */
  YYSYMBOL_FDefBlock = 89,                 /* FDefBlock  */
  YYSYMBOL_FDef = 90,                      /* FDef  */
  YYSYMBOL_91_2 = 91,                      /* $@2  */
  YYSYMBOL_ParamList = 92,                 /* ParamList  */
  YYSYMBOL_Param = 93,                     /* Param  */
  YYSYMBOL_LDeclBlock = 94,                /* LDeclBlock  */
  YYSYMBOL_LDeclList = 95,                 /* LDeclList  */
  YYSYMBOL_LDecl = 96,                     /* LDecl  */
  YYSYMBOL_IdList = 97,                    /* IdList  */
  YYSYMBOL_MainBlock = 98,                 /* MainBlock  */
  YYSYMBOL_99_3 = 99,                      /* $@3  */
  YYSYMBOL_Body = 100,                     /* Body  */
  YYSYMBOL_RetStmt = 101,                  /* RetStmt  */
  YYSYMBOL_Slist = 102,                    /* Slist  */
  YYSYMBOL_Stmt = 103,                     /* Stmt  */
  YYSYMBOL_InputStmt = 104,                /* InputStmt  */
  YYSYMBOL_OutputStmt = 105,               /* OutputStmt  */
  YYSYMBOL_AsgStmt = 106,                  /* AsgStmt  */
  YYSYMBOL_IfStmt = 107,                   /* IfStmt  */
  YYSYMBOL_WhileStmt = 108,                /* WhileStmt  */
  YYSYMBOL_BrkStmt = 109,                  /* BrkStmt  */
  YYSYMBOL_ContStmt = 110,                 /* ContStmt  */
  YYSYMBOL_repeatUntilStmt = 111,          /* repeatUntilStmt  */
  YYSYMBOL_doWhileStmt = 112,              /* doWhileStmt  */
  YYSYMBOL_expr = 113,                     /* expr  */
  YYSYMBOL_id = 114,                       /* id  */
  YYSYMBOL_ExprList = 115                  /* ExprList  */
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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   551

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  304

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   316


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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    50,    50,    58,    66,    68,    69,    70,    72,    73,
      76,    79,    85,    86,    88,    98,    99,   101,   102,   104,
     114,   116,   117,   119,   123,   131,   132,   133,   143,   144,
     149,   150,   152,   153,   155,   159,   160,   161,   174,   175,
     176,   186,   187,   188,   200,   205,   208,   219,   231,   243,
     256,   257,   259,   264,   272,   272,   284,   285,   287,   287,
     388,   389,   390,   392,   400,   401,   402,   404,   405,   407,
     409,   414,   422,   421,   463,   464,   466,   483,   484,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     514,   515,   523,   530,   531,   539,   548,   552,   557,   571,
     588,   592,   597,   602,   606,   610,   615,   621,   625,   629,
     633,   637,   641,   645,   649,   653,   657,   661,   665,   669,
     673,   677,   681,   682,   687,   691,   695,   696,   697,   701,
     704,   706,   707,   718,   725,   729,   749,   761,   762
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
  "KW_BRKP", "CLASS", "ENDCLASS", "DELETE", "SELF", "NEW", "$accept",
  "Program", "TypeDefBlock", "TypeDefList", "TypeDef", "UserDefinedType",
  "FieldDeclList", "FieldDecl", "ClassDefBlock", "ClassDefList",
  "ClassDef", "Cname", "ClassFieldDeclList", "ClassFieldDecl", "ClassType",
  "ClassMethodDefns", "GDeclBlock", "GDeclList", "GDecl", "FieldType",
  "Type", "Ftype", "Field", "FieldFunction", "GidList", "Gid", "$@1",
  "FDefBlock", "FDef", "$@2", "ParamList", "Param", "LDeclBlock",
  "LDeclList", "LDecl", "IdList", "MainBlock", "$@3", "Body", "RetStmt",
  "Slist", "Stmt", "InputStmt", "OutputStmt", "AsgStmt", "IfStmt",
  "WhileStmt", "BrkStmt", "ContStmt", "repeatUntilStmt", "doWhileStmt",
  "expr", "id", "ExprList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-196)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,   103,   -17,    37,   -14,  -196,  -196,  -196,   160,  -196,
     -10,    18,  -196,    41,    72,  -196,  -196,    38,    69,  -196,
     -12,  -196,   116,   223,   168,  -196,  -196,  -196,    78,  -196,
     142,  -196,  -196,  -196,   140,  -196,  -196,  -196,  -196,   267,
    -196,   159,  -196,   -17,  -196,   166,   168,  -196,  -196,  -196,
    -196,   125,   155,  -196,  -196,  -196,   -23,    90,  -196,   130,
    -196,  -196,  -196,   164,   283,   226,  -196,   159,  -196,   252,
     298,   238,  -196,  -196,  -196,  -196,  -196,   230,   208,   252,
    -196,   241,    56,  -196,  -196,   245,   314,  -196,   375,   228,
      86,    30,  -196,    70,  -196,   252,  -196,  -196,   149,  -196,
    -196,   375,   229,   240,   251,   265,   375,   242,   263,    12,
     271,   272,    82,   286,   273,   269,   126,   259,   375,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   331,
    -196,  -196,  -196,  -196,  -196,   252,  -196,  -196,   248,   293,
    -196,  -196,   405,    82,    82,  -196,  -196,   284,   -21,   301,
     313,    82,    82,   322,    82,   325,   305,  -196,  -196,    23,
     309,  -196,    82,   352,   316,     1,  -196,   463,  -196,  -196,
     -16,   333,    82,   338,  -196,   355,  -196,    82,    80,   164,
    -196,   329,    84,   141,   330,    -5,    -3,   335,  -196,   244,
     527,   128,   158,   332,   152,  -196,   334,   350,  -196,  -196,
      82,   342,   211,   351,   353,   358,  -196,  -196,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,  -196,
       2,     7,  -196,   474,  -196,  -196,   485,   354,   238,    82,
     374,   384,    82,   359,   364,  -196,  -196,    82,   365,   369,
     370,  -196,   361,   131,  -196,  -196,   362,   363,   373,   262,
     262,  -196,  -196,  -196,   538,   538,   538,   538,   538,   538,
     379,   385,  -196,  -196,  -196,   366,   222,   375,   375,   233,
    -196,  -196,   527,  -196,  -196,  -196,    82,  -196,    82,  -196,
      82,  -196,  -196,  -196,     5,   254,   315,   386,   132,   133,
     134,  -196,   375,   389,   394,  -196,  -196,  -196,  -196,   345,
    -196,  -196,   395,  -196
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,     0,    16,     4,     6,    11,     0,     9,
       0,     0,     1,     0,     0,     5,     8,     0,     0,    20,
       0,    18,     0,     0,     0,    37,    35,    36,     0,    13,
       0,    72,    15,    17,     0,    40,    31,    38,    39,     0,
      33,     0,    43,    41,    42,     0,     0,    57,     3,    10,
      12,     0,     0,    22,    30,    32,    52,     0,    51,     0,
      56,     2,    14,    66,     0,     0,    54,     0,    34,    62,
       0,     0,    27,    29,    25,    26,    21,     0,     0,    62,
      50,     0,     0,    61,    65,     0,     0,    68,     0,     0,
       0,     0,    53,     0,    63,     0,    58,    71,     0,    64,
      67,     0,     0,     0,     0,     0,     0,     0,     0,   133,
       0,     0,     0,     0,     0,     0,     0,    88,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
      73,    41,    19,    28,    23,    62,    55,    60,     0,     0,
      69,    88,     0,     0,     0,   103,   104,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,   124,   125,   133,
       0,   129,     0,     0,     0,   127,   131,     0,   126,    90,
       0,     0,     0,     0,    75,    88,    77,     0,     0,    66,
      70,     0,     0,     0,     0,     0,     0,     0,    44,     0,
     137,     0,   133,     0,     0,   123,     0,     0,   120,   121,
     138,     0,     0,     0,     0,     0,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,    46,     0,    45,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,   134,     0,   135,     0,
       0,   130,    44,     0,   128,   122,    46,     0,    45,   107,
     108,   109,   110,   117,   111,   114,   112,   113,   115,   116,
       0,     0,    99,    98,    24,     0,     0,     0,     0,     0,
      91,    92,   136,    89,    96,    97,   138,   135,   138,   132,
     138,    94,    95,    59,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,     0,   105,    48,    47,    49,     0,
     101,   102,     0,   100
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -196,  -196,   411,  -196,  -196,   400,  -196,  -196,
     423,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   406,  -196,
     -15,  -196,   -88,  -196,  -196,   377,  -196,  -196,   -39,  -196,
     -70,   356,   268,  -196,   360,  -196,    34,  -196,   220,   -77,
    -100,  -114,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -109,   -86,  -195
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     8,     9,    10,    28,    29,    14,    20,
      21,    22,    64,    76,    77,    90,    24,    39,    40,    30,
      81,    45,   165,   166,    57,    58,    79,    46,    47,   138,
      82,    83,    71,    86,    87,    98,     5,    52,    89,   141,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   190,   168,   191
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     116,   142,   129,   167,   176,   243,   147,    60,    41,    93,
     150,   117,   173,   116,   185,   129,   205,   150,   116,   220,
     129,   268,   173,    19,    41,     1,    11,   150,   176,    65,
     116,    66,   129,   176,   182,   183,     2,    12,   197,   115,
      17,   175,   189,    13,   115,   194,    32,   206,   207,   291,
     233,   133,   234,   202,   116,    85,   129,   260,    48,   116,
     186,   129,   261,   223,   151,   178,   152,   193,   226,   198,
     199,    85,    18,    25,   134,   151,    19,   200,    26,    27,
      61,   288,   221,   289,   135,   290,   155,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    95,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      23,    96,    95,    25,   156,   157,   158,   159,    26,    27,
     266,    42,    95,   269,    31,   136,   131,    44,   272,    49,
     160,   161,    67,     6,    68,   227,   162,   132,     7,   230,
     172,   173,   163,   164,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    34,   285,   286,    62,
     237,   176,   176,   237,   237,   237,   237,    51,    53,   116,
     116,   129,   129,   238,    69,   176,   277,   296,   297,   298,
      15,   139,   299,   140,    56,     7,   231,   116,   116,   129,
     129,    59,    70,    42,   116,    63,   129,   240,    43,    44,
     151,   116,   200,   129,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    35,    78,
      88,    92,    36,    37,    38,    91,   245,   210,   211,   212,
     101,   102,   292,   103,   104,   105,    94,   284,   293,   130,
      97,   106,   174,   143,   171,   107,   108,    35,   287,   109,
     110,   111,    37,    38,   144,   145,   148,   236,   179,   112,
     101,   102,    35,   103,   104,   105,    54,    37,    38,   146,
     113,   106,   184,   114,   115,   107,   108,   149,    72,   109,
     110,   111,    73,    74,    75,   153,   154,   170,   180,   112,
     169,   101,   102,    35,   103,   104,   105,    84,    37,    38,
     113,   294,   106,   114,   115,   177,   107,   108,   188,    35,
     109,   110,   111,    99,    37,    38,   187,   192,   195,   196,
     112,   101,   102,   201,   103,   104,   105,   203,   222,   302,
     204,   113,   106,   224,   114,   115,   107,   108,   225,   235,
     109,   110,   111,   229,   232,   242,   246,   239,   247,   241,
     112,   101,   102,   248,   103,   104,   105,   244,   264,   267,
     268,   113,   106,   270,   114,   115,   107,   108,   271,   273,
     109,   110,   111,   274,   275,   276,   278,   283,   279,    16,
     112,   101,   102,   281,   181,   104,   105,   280,    50,   282,
     295,   113,   106,   300,   114,   115,   107,   108,   301,   303,
     109,   110,   111,    33,    80,    55,   100,   228,   265,     0,
     112,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,   114,   115,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,     0,
       0,     0,     0,     0,     0,     0,     0,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   263,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
      -1,    -1
};

static const yytype_int16 yycheck[] =
{
      88,   101,    88,   112,   118,   200,   106,    46,    23,    79,
      15,    88,    15,   101,    35,   101,    15,    15,   106,    35,
     106,    16,    15,    35,    39,    29,    43,    15,   142,    52,
     118,    54,   118,   147,   143,   144,    40,     0,    15,    60,
      50,   118,   151,    57,    60,   154,    58,    46,    47,    44,
      55,    90,    55,   162,   142,    70,   142,    55,    24,   147,
     148,   147,    55,   172,    52,   135,    54,   153,   177,    46,
      47,    86,    54,    35,    44,    52,    35,    54,    40,    41,
      46,   276,   170,   278,    54,   280,     4,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    42,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      38,    55,    42,    35,    32,    33,    34,    35,    40,    41,
     229,    35,    42,   232,    55,    55,    40,    41,   237,    51,
      48,    49,    42,    30,    44,    55,    54,    51,    35,    55,
      14,    15,    60,    61,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    50,   267,   268,    44,
      42,   285,   286,    42,    42,    42,    42,    35,    38,   267,
     268,   267,   268,    55,    54,   299,    55,    55,    55,    55,
      30,    42,   292,    44,    35,    35,    55,   285,   286,   285,
     286,    35,    38,    35,   292,    50,   292,    55,    40,    41,
      52,   299,    54,   299,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    35,    33,
      22,    53,    39,    40,    41,    35,    55,     5,     6,     7,
      16,    17,    18,    19,    20,    21,    35,    55,    24,    51,
      35,    27,    23,    54,    15,    31,    32,    35,    55,    35,
      36,    37,    40,    41,    54,    44,    54,    53,    50,    45,
      16,    17,    35,    19,    20,    21,    39,    40,    41,    44,
      56,    27,    28,    59,    60,    31,    32,    54,    35,    35,
      36,    37,    39,    40,    41,    54,    54,    54,    35,    45,
      44,    16,    17,    35,    19,    20,    21,    39,    40,    41,
      56,    26,    27,    59,    60,    14,    31,    32,    35,    35,
      35,    36,    37,    39,    40,    41,    55,    35,    33,    54,
      45,    16,    17,    54,    19,    20,    21,    15,    35,    24,
      54,    56,    27,    35,    59,    60,    31,    32,    23,    44,
      35,    36,    37,    54,    54,    35,    35,    55,    35,    55,
      45,    16,    17,    35,    19,    20,    21,    55,    44,    25,
      16,    56,    27,    44,    59,    60,    31,    32,    44,    44,
      35,    36,    37,    44,    44,    54,    54,    51,    55,     8,
      45,    16,    17,    44,    19,    20,    21,    54,    28,    44,
      44,    56,    27,    44,    59,    60,    31,    32,    44,    44,
      35,    36,    37,    20,    67,    39,    86,   179,   228,    -1,
      45,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    60,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    40,    63,    64,    98,    30,    35,    65,    66,
      67,    43,     0,    57,    70,    30,    66,    50,    54,    35,
      71,    72,    73,    38,    78,    35,    40,    41,    68,    69,
      81,    55,    58,    72,    50,    35,    39,    40,    41,    79,
      80,    82,    35,    40,    41,    83,    89,    90,    98,    51,
      69,    35,    99,    38,    39,    80,    35,    86,    87,    35,
      90,    98,    44,    50,    74,    52,    54,    42,    44,    54,
      38,    94,    35,    39,    40,    41,    75,    76,    33,    88,
      87,    82,    92,    93,    39,    82,    95,    96,    22,   100,
      77,    35,    53,    92,    35,    42,    55,    35,    97,    39,
      96,    16,    17,    19,    20,    21,    27,    31,    32,    35,
      36,    37,    45,    56,    59,    60,    84,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   114,
      51,    40,    51,    90,    44,    54,    55,    93,    91,    42,
      44,   101,   102,    54,    54,    44,    44,   102,    54,    54,
      15,    52,    54,    54,    54,     4,    32,    33,    34,    35,
      48,    49,    54,    60,    61,    84,    85,   113,   114,    44,
      54,    15,    14,    15,    23,   101,   103,    14,    92,    50,
      35,    19,   113,   113,    28,    35,    84,    55,    35,   113,
     113,   115,    35,   114,   113,    33,    54,    15,    46,    47,
      54,    54,   113,    15,    54,    15,    46,    47,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    44,
      35,    84,    35,   113,    35,    23,   113,    55,    94,    54,
      55,    55,    54,    55,    55,    44,    53,    42,    55,    55,
      55,    55,    35,   115,    55,    55,    35,    35,    35,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
      55,    55,    44,    44,    44,   100,   113,    25,    16,   113,
      44,    44,   113,    44,    44,    44,    54,    55,    54,    55,
      54,    44,    44,    51,    55,   102,   102,    55,   115,   115,
     115,    44,    18,    24,    26,    44,    55,    55,    55,   102,
      44,    44,    24,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    63,    64,    64,    64,    65,    65,
      66,    67,    68,    68,    69,    70,    70,    71,    71,    72,
      73,    74,    74,    75,    75,    76,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    81,    81,    81,    82,    82,
      82,    83,    83,    83,    84,    84,    84,    85,    85,    85,
      86,    86,    87,    87,    88,    87,    89,    89,    91,    90,
      92,    92,    92,    93,    94,    94,    94,    95,    95,    96,
      97,    97,    99,    98,   100,   100,   101,   102,   102,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   104,   105,   106,   106,
     107,   107,   108,   109,   110,   111,   112,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   114,   114,   114,   115,   115,   115
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     1,     3,     2,     0,     2,     1,
       4,     1,     2,     1,     3,     3,     0,     2,     1,     7,
       1,     2,     0,     3,     6,     1,     1,     1,     2,     0,
       3,     2,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     6,     6,     6,
       3,     1,     1,     4,     0,     5,     2,     1,     0,    10,
       3,     1,     0,     2,     3,     2,     0,     2,     1,     3,
       3,     1,     0,     9,     4,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       2,     5,     5,     4,     5,     5,     5,     5,     4,     4,
      10,     8,     8,     2,     2,     7,     7,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     2,     1,     1,     1,     1,     3,     1,
       3,     1,     4,     1,     4,     4,     3,     1,     0
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
  case 2: /* Program: TypeDefBlock ClassDefBlock GDeclBlock FDefBlock MainBlock  */
#line 51 "parser.y"
        {
            printGSymbolTable();
            printTypeTable();
            printClassTable();
                (yyval.node) = (yyvsp[-1].node);
            fclose(out);
        }
#line 1631 "y.tab.c"
    break;

  case 3: /* Program: TypeDefBlock ClassDefBlock GDeclBlock MainBlock  */
#line 59 "parser.y"
        {
          printGSymbolTable();
            printTypeTable();
            printClassTable();
          (yyval.node) = (yyvsp[0].node);
          fclose(out);
      }
#line 1643 "y.tab.c"
    break;

  case 4: /* Program: MainBlock  */
#line 66 "parser.y"
                    {fclose(out);}
#line 1649 "y.tab.c"
    break;

  case 5: /* TypeDefBlock: TYPE TypeDefList ENDTYPE  */
#line 68 "parser.y"
                                       { (yyval.node) = NULL; initialize(); }
#line 1655 "y.tab.c"
    break;

  case 6: /* TypeDefBlock: TYPE ENDTYPE  */
#line 69 "parser.y"
                           { (yyval.node) = NULL;initialize(); }
#line 1661 "y.tab.c"
    break;

  case 7: /* TypeDefBlock: %empty  */
#line 70 "parser.y"
              { (yyval.node) = NULL;initialize(); }
#line 1667 "y.tab.c"
    break;

  case 10: /* TypeDef: UserDefinedType LBRACE FieldDeclList RBRACE  */
#line 76 "parser.y"
                                                      { TInstall((yyvsp[-3].node)->varname, Fhead); }
#line 1673 "y.tab.c"
    break;

  case 11: /* UserDefinedType: ID  */
#line 79 "parser.y"
                    {
                        tempTNode = (yyvsp[0].node);
                        (yyval.node) = (yyvsp[0].node);
                    }
#line 1682 "y.tab.c"
    break;

  case 14: /* FieldDecl: FieldType ID SEMI  */
#line 88 "parser.y"
                             {
                                if(FLookup((yyvsp[-1].node)->varname, Fhead) != NULL) {
                                    fprintf(stderr,"Re-declaration of Field element %s\n", (yyvsp[-1].node)->varname);
                                    yyerror("");
                                    exit(1);
                                }
                                FInstall((yyvsp[-1].node)->varname, declaration_type);
                            }
#line 1695 "y.tab.c"
    break;

  case 15: /* ClassDefBlock: CLASS ClassDefList ENDCLASS  */
#line 98 "parser.y"
                                            { (yyval.node) = NULL; }
#line 1701 "y.tab.c"
    break;

  case 16: /* ClassDefBlock: %empty  */
#line 99 "parser.y"
               { (yyval.node) = NULL; }
#line 1707 "y.tab.c"
    break;

  case 19: /* ClassDef: Cname LBRACE DECL ClassFieldDeclList ENDDECL ClassMethodDefns RBRACE  */
#line 104 "parser.y"
                                                                               {
            CCurrent = NULL;
            if(defCount != declCount) {
                yyerror("All functions declared in class need to be defined\n");
                exit(1);
            }
            declCount = 0;
            defCount = 0;
        }
#line 1721 "y.tab.c"
    break;

  case 20: /* Cname: ID  */
#line 114 "parser.y"
          {CCurrent = CInstall((yyvsp[0].node)->varname, NULL);}
#line 1727 "y.tab.c"
    break;

  case 23: /* ClassFieldDecl: ClassType ID SEMI  */
#line 119 "parser.y"
                                  {
                checkAvailability((yyvsp[-1].node)->varname, 2);
                Class_Finstall(CCurrent, saved_decl_type, declarationCType, (yyvsp[-1].node)->varname);
                }
#line 1736 "y.tab.c"
    break;

  case 24: /* ClassFieldDecl: ClassType ID LPAREN ParamList RPAREN SEMI  */
#line 123 "parser.y"
                                                          {
                declCount++;
                checkAvailability((yyvsp[-4].node)->varname, 2);
                Class_Minstall(CCurrent, (yyvsp[-4].node)->varname, saved_decl_type, Phead);
                Phead = NULL;
                Ptail = NULL;
                }
#line 1748 "y.tab.c"
    break;

  case 25: /* ClassType: T_INT  */
#line 131 "parser.y"
                  { declaration_type = TLookup("int"); saved_decl_type = declaration_type; }
#line 1754 "y.tab.c"
    break;

  case 26: /* ClassType: T_STR  */
#line 132 "parser.y"
                  { declaration_type = TLookup("str"); saved_decl_type = declaration_type; }
#line 1760 "y.tab.c"
    break;

  case 27: /* ClassType: ID  */
#line 133 "parser.y"
                  {
                    declaration_type = TLookup((yyvsp[0].node)->varname);
                    declarationCType = CLookup((yyvsp[0].node)->varname);
                    if(declaration_type == NULL && declarationCType == NULL) {
                        fprintf(stderr,"Unknown user-defined type/class %s\n", (yyvsp[0].node)->varname);
                        exit(1);
                    }
                    saved_decl_type = declaration_type;
                  }
#line 1774 "y.tab.c"
    break;

  case 35: /* FieldType: T_INT  */
#line 159 "parser.y"
                  {declaration_type=TLookup("int");}
#line 1780 "y.tab.c"
    break;

  case 36: /* FieldType: T_STR  */
#line 160 "parser.y"
                  {declaration_type=TLookup("str");}
#line 1786 "y.tab.c"
    break;

  case 37: /* FieldType: ID  */
#line 161 "parser.y"
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
#line 1803 "y.tab.c"
    break;

  case 38: /* Type: T_INT  */
#line 174 "parser.y"
              {declaration_type = TLookup("int");}
#line 1809 "y.tab.c"
    break;

  case 39: /* Type: T_STR  */
#line 175 "parser.y"
             {declaration_type = TLookup("str");}
#line 1815 "y.tab.c"
    break;

  case 40: /* Type: ID  */
#line 176 "parser.y"
            {
                declaration_type = TLookup((yyvsp[0].node)->varname);
                declarationCType = CLookup((yyvsp[0].node)->varname);
                if(declaration_type == NULL && declarationCType == NULL) {
                    fprintf(stderr,"Unknown user-defined type/class %s\n", (yyvsp[0].node)->varname);
                    exit(1);
                }
            }
#line 1828 "y.tab.c"
    break;

  case 41: /* Ftype: T_INT  */
#line 186 "parser.y"
              {fdeclaration_type = TLookup("int");}
#line 1834 "y.tab.c"
    break;

  case 42: /* Ftype: T_STR  */
#line 187 "parser.y"
             {fdeclaration_type = TLookup("str");}
#line 1840 "y.tab.c"
    break;

  case 43: /* Ftype: ID  */
#line 188 "parser.y"
            {
                // printTypeTable();
                fdeclaration_type = TLookup((yyvsp[0].node)->varname);
                declarationCType = CLookup((yyvsp[0].node)->varname);
                // printf("type is set to %p %s %d\n", fdeclaration_type, $1->varname, yylineno);
                // printf("type is set to %s\n", fdeclaration_type->name);
                if(fdeclaration_type == NULL && declarationCType == NULL) {
                    fprintf(stderr,"Unknown user-defined type/class %s\n", (yyvsp[0].node)->varname);
                    exit(1);
                }
            }
#line 1856 "y.tab.c"
    break;

  case 44: /* Field: ID DOT ID  */
#line 200 "parser.y"
                        {
                            assignType((yyvsp[-2].node), 0);
                            assignTypeField((yyvsp[0].node), (yyvsp[-2].node)->type->fields);
                            (yyval.node) = createTree((yyvsp[0].node)->type, NULL, FIELD_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
                        }
#line 1866 "y.tab.c"
    break;

  case 45: /* Field: Field DOT ID  */
#line 205 "parser.y"
                        {
                            (yyval.node) = insertFieldId((yyvsp[-2].node), (yyvsp[0].node));
                        }
#line 1874 "y.tab.c"
    break;

  case 46: /* Field: SELF DOT ID  */
#line 208 "parser.y"
                       {
                            if(CCurrent == NULL) {
                                yyerror("SELF cannot be used outside a class\n");
                                exit(1);
                            }
                            (yyvsp[-2].node)->Ctype = CCurrent;
                            (yyvsp[-2].node)->Lentry = LLookup("self");
                            (yyval.node) = insertFieldId((yyvsp[-2].node), (yyvsp[0].node));
                        }
#line 1888 "y.tab.c"
    break;

  case 47: /* FieldFunction: SELF DOT ID LPAREN ExprList RPAREN  */
#line 219 "parser.y"
                                                  {
                        if(CCurrent == NULL) {
                            yyerror("SELF cannot be used outside a class\n");
                            exit(1);
                        }
                        (yyvsp[-5].node)->Ctype = CCurrent;
                        (yyvsp[-5].node)->Lentry = LLookup("self");
                        (yyvsp[-3].node)->nodetype = FUN_NODE;
                        (yyvsp[-3].node)->argList = (yyvsp[-1].node);
                        (yyval.node) = createTree(TLookup("void"),NULL, FIELDFUNC_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-3].node), NULL);
                        assignType((yyval.node), 3);
                    }
#line 1905 "y.tab.c"
    break;

  case 48: /* FieldFunction: ID DOT ID LPAREN ExprList RPAREN  */
#line 231 "parser.y"
                                                {
                        assignType((yyvsp[-5].node), 0);
                        if((yyvsp[-5].node)->Ctype == NULL) {
                            fprintf(stderr,"%s is not a class object\n", (yyvsp[-5].node)->varname);
                            yyerror("");
                            exit(1);
                        }
                        (yyvsp[-3].node)->nodetype = FUN_NODE;
                        (yyvsp[-3].node)->argList = (yyvsp[-1].node);
                        (yyval.node) = createTree(TLookup("void"),NULL, FIELDFUNC_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-3].node), NULL);
                        assignType((yyval.node), 3);
                    }
#line 1922 "y.tab.c"
    break;

  case 49: /* FieldFunction: Field DOT ID LPAREN ExprList RPAREN  */
#line 243 "parser.y"
                                                   {
                        if((yyvsp[-5].node)->Ctype == NULL) {
                            yyerror("Memberfield is not a class object\n");
                            exit(1);
                        }
                        (yyvsp[-3].node)->nodetype = FUN_NODE;
                        (yyvsp[-3].node)->argList = (yyvsp[-1].node);
                        (yyval.node) = createTree(TLookup("void"),NULL, FIELDFUNC_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-3].node), NULL);
                        assignType((yyval.node), 3);
                    }
#line 1937 "y.tab.c"
    break;

  case 52: /* Gid: ID  */
#line 259 "parser.y"
         {
     checkAvailability((yyvsp[0].node)->varname,1);   
     
     GInstall((yyvsp[0].node)->varname,declaration_type,1,NULL,declarationCType);
}
#line 1947 "y.tab.c"
    break;

  case 53: /* Gid: ID LBRACK NUM RBRACK  */
#line 264 "parser.y"
                           {
        checkAvailability((yyvsp[-3].node)->varname,1);   
        if((yyvsp[-1].node)->value.intval < 1) {
        yyerror("Invalid array size");
        exit(1);
    }
     GInstall((yyvsp[-3].node)->varname,declaration_type,(yyvsp[-1].node)->value.intval,NULL,declarationCType);
    }
#line 1960 "y.tab.c"
    break;

  case 54: /* $@1: %empty  */
#line 272 "parser.y"
                {
        saved_decl_type = declaration_type;  
    }
#line 1968 "y.tab.c"
    break;

  case 55: /* Gid: ID LPAREN $@1 ParamList RPAREN  */
#line 275 "parser.y"
                     {
        declCount++;
        checkAvailability((yyvsp[-4].node)->varname,1);
        GInstall((yyvsp[-4].node)->varname,saved_decl_type,-1,Phead,declarationCType);
        Phead=NULL;
        Ptail=NULL;
    }
#line 1980 "y.tab.c"
    break;

  case 58: /* $@2: %empty  */
#line 287 "parser.y"
                                        {
           /* mid-rule action: set return type BEFORE parsing body */
           current_function_type = fdeclaration_type;
       }
#line 1989 "y.tab.c"
    break;

  case 59: /* FDef: Ftype ID LPAREN ParamList RPAREN $@2 LBRACE LDeclBlock Body RBRACE  */
#line 291 "parser.y"
        {
            // localbindingstart = 1;
            defCount++;
            if(CCurrent == NULL) {
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
                
                
                argList2 = Gtemp->paramlist;
            }else {
                Mtemp = Class_Mlookup(CCurrent, (yyvsp[-8].node)->varname);
                current_function_type = fdeclaration_type;

                if(Mtemp == NULL) {
                    fprintf(stderr,"Function %s not declared in class", (yyvsp[-8].node)->varname);
                    yyerror("");
                    exit(1);
                }

                if(strcmp(Mtemp->Type->name,fdeclaration_type->name)!=0) {
                    printf("function type %s defclaration type %s\n", fdeclaration_type->name, Mtemp->Type->name);
                    fprintf(stderr,"%s : Function type does not match declaration", (yyvsp[-8].node)->varname);
                    yyerror("");
                    exit(1);
                }

                argList2 = Mtemp->paramlist;
            }
            argList1 = Phead;

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
        if (CCurrent == NULL) {
            fprintf(out, "F%d:\n", Gtemp->flabel);
        } else {
            fprintf(out, "M%d:\n", Mtemp->Flabel);
        }
        fprintf(out, "PUSH BP\n");
        fprintf(out, "MOV BP,SP\n");
        // printf("value: %d\n", localbindingstart);
        fprintf(out, "ADD SP, %d\n", localbindingstart - 1);
       

        codegen((yyvsp[-1].node));
        Phead = NULL;
        Ptail = NULL;
        Lhead = NULL;
        Ltail = NULL;
        localbindingstart = 1;
        }
#line 2089 "y.tab.c"
    break;

  case 63: /* Param: Type ID  */
#line 392 "parser.y"
                {
    struct Typetable *ptype = declaration_type;
    // printf("Installing param %s of type %s\n", 
        //    $2->varname, ptype->name); 
                    checkAvailability((yyvsp[0].node)->varname, 0);
                    PInstall((yyvsp[0].node)->varname, ptype);
                }
#line 2101 "y.tab.c"
    break;

  case 64: /* LDeclBlock: DECL LDeclList ENDDECL  */
#line 400 "parser.y"
                                    {InstallParamsInLocal();}
#line 2107 "y.tab.c"
    break;

  case 65: /* LDeclBlock: DECL ENDDECL  */
#line 401 "parser.y"
                           {InstallParamsInLocal();}
#line 2113 "y.tab.c"
    break;

  case 66: /* LDeclBlock: %empty  */
#line 402 "parser.y"
              {InstallParamsInLocal();}
#line 2119 "y.tab.c"
    break;

  case 70: /* IdList: IdList COMMA ID  */
#line 409 "parser.y"
                         {
            checkAvailability((yyvsp[0].node)->varname, 0);
            LInstall((yyvsp[0].node)->varname, declaration_type);
            localbindingstart++;
        }
#line 2129 "y.tab.c"
    break;

  case 71: /* IdList: ID  */
#line 414 "parser.y"
         {
                    checkAvailability((yyvsp[0].node)->varname, 0);
                    LInstall((yyvsp[0].node)->varname, declaration_type);
                    localbindingstart++;
                }
#line 2139 "y.tab.c"
    break;

  case 72: /* $@3: %empty  */
#line 422 "parser.y"
{
    current_function_type = TLookup("int");   // 🔥 FIX HERE
}
#line 2147 "y.tab.c"
    break;

  case 73: /* MainBlock: T_INT MAIN LPAREN RPAREN $@3 LBRACE LDeclBlock Body RBRACE  */
#line 424 "parser.y"
                               {

    if(defCount != declCount) {
        yyerror("All functions declared need to be defined\n");
        exit(1);
    }

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
 
    codegen((yyvsp[-1].node));
    Lhead = NULL;
    Ltail = NULL;
    localbindingstart = 1;

    }
#line 2190 "y.tab.c"
    break;

  case 74: /* Body: KW_BEGIN Slist RetStmt END  */
#line 463 "parser.y"
                                  {(yyval.node) = createTree(TLookup("void"), NULL,CONNECTOR_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[-1].node), NULL);}
#line 2196 "y.tab.c"
    break;

  case 75: /* Body: KW_BEGIN RetStmt END  */
#line 464 "parser.y"
                           {(yyval.node) = (yyvsp[-1].node);}
#line 2202 "y.tab.c"
    break;

  case 76: /* RetStmt: RETURN expr SEMI  */
#line 466 "parser.y"
                             {
     if((yyvsp[-1].node)->type == NULL) {
        printf("ERROR: NULL type in return\n");
        exit(1);
    }

                                // printf("curre %p , expr %p\n",current_function_type, $2->type);
                                // printf("curre %s , expr %s\n",current_function_type->name, $2->type->name);
                                if(strcmp(current_function_type->name,(yyvsp[-1].node)->type->name)==0) {
                                    (yyval.node) = createTree(TLookup("void"), NULL,RET_NODE, NULL, NULL, (yyvsp[-1].node), NULL, NULL);
                                } else {
                                    yyerror("Return type mismatch");
                                    exit(1);
                                }
                            }
#line 2222 "y.tab.c"
    break;

  case 77: /* Slist: Slist Stmt  */
#line 483 "parser.y"
                   {(yyval.node) = createTree(TLookup("void"), NULL,CONNECTOR_NODE, NULL, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);}
#line 2228 "y.tab.c"
    break;

  case 78: /* Slist: Stmt  */
#line 484 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 2234 "y.tab.c"
    break;

  case 79: /* Stmt: InputStmt  */
#line 487 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2240 "y.tab.c"
    break;

  case 80: /* Stmt: OutputStmt  */
#line 488 "parser.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 2246 "y.tab.c"
    break;

  case 81: /* Stmt: AsgStmt  */
#line 489 "parser.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 2252 "y.tab.c"
    break;

  case 82: /* Stmt: IfStmt  */
#line 490 "parser.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 2258 "y.tab.c"
    break;

  case 83: /* Stmt: WhileStmt  */
#line 491 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2264 "y.tab.c"
    break;

  case 84: /* Stmt: BrkStmt  */
#line 492 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2270 "y.tab.c"
    break;

  case 85: /* Stmt: ContStmt  */
#line 493 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2276 "y.tab.c"
    break;

  case 86: /* Stmt: repeatUntilStmt  */
#line 494 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 2282 "y.tab.c"
    break;

  case 87: /* Stmt: doWhileStmt  */
#line 495 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2288 "y.tab.c"
    break;

  case 88: /* Stmt: RetStmt  */
#line 496 "parser.y"
             {(yyval.node)=(yyvsp[0].node);}
#line 2294 "y.tab.c"
    break;

  case 89: /* Stmt: ID LPAREN ExprList RPAREN SEMI  */
#line 497 "parser.y"
                                     {
    assignType((yyvsp[-4].node),1);
    (yyvsp[-4].node)->nodetype = FUN_NODE;
    (yyvsp[-4].node)->argList = (yyvsp[-2].node);

    struct Gsymbol *g = GLookup((yyvsp[-4].node)->varname);
    if(g == NULL) {
        fprintf(stderr, "Function %s not declared\n", (yyvsp[-4].node)->varname);
        exit(1);
    }

    (yyvsp[-4].node)->type = g->type;   

    checkFunctionArgs(g, g->paramlist, (yyvsp[-4].node)->argList);

    (yyval.node) = (yyvsp[-4].node);
}
#line 2316 "y.tab.c"
    break;

  case 90: /* Stmt: KW_BRKP SEMI  */
#line 514 "parser.y"
                        { (yyval.node) = createTree(TLookup("void"), NULL, BRKP_NODE, NULL, NULL, NULL, NULL, NULL); }
#line 2322 "y.tab.c"
    break;

  case 91: /* Stmt: FREE LPAREN ID RPAREN SEMI  */
#line 515 "parser.y"
                                 {
        assignType((yyvsp[-2].node),0);
        if((yyvsp[-2].node)->type == TLookup("int") || (yyvsp[-2].node)->type == TLookup("str")) {
            yyerror("Cannot FREE a string or int variable\n");
            exit(1);
        }
        (yyval.node) = createTree(TLookup("void"),NULL, FREE_NODE, NULL, NULL, (yyvsp[-2].node), NULL, NULL);
    }
#line 2335 "y.tab.c"
    break;

  case 92: /* Stmt: FREE LPAREN Field RPAREN SEMI  */
#line 523 "parser.y"
                                        {
                                    if((yyvsp[-2].node)->type == TLookup("int") || (yyvsp[-2].node)->type == TLookup("str")) {
                                        yyerror("Cannot FREE a string or integer variable\n");
                                        exit(1);
                                    }
                                    (yyval.node) = createTree(TLookup("void"),NULL, FREE_NODE, NULL, NULL, (yyvsp[-2].node), NULL, NULL);
     }
#line 2347 "y.tab.c"
    break;

  case 93: /* Stmt: INIT LPAREN RPAREN SEMI  */
#line 530 "parser.y"
                                      {(yyval.node) = createTree(TLookup("void"),NULL, INIT_NODE, NULL, NULL, NULL, NULL, NULL);}
#line 2353 "y.tab.c"
    break;

  case 94: /* Stmt: DELETE LPAREN ID RPAREN SEMI  */
#line 531 "parser.y"
                                        {
                                    assignType((yyvsp[-2].node), 0);
                                    if((yyvsp[-2].node)->Ctype == NULL) {
                                        yyerror("Cannot DELETE a non class variable\n");
                                        exit(1);
                                    }
                                    (yyval.node) = createTree(TLookup("void"), NULL,DELETE_NODE, NULL, NULL, (yyvsp[-2].node), NULL, NULL);
                                }
#line 2366 "y.tab.c"
    break;

  case 95: /* Stmt: DELETE LPAREN Field RPAREN SEMI  */
#line 539 "parser.y"
                                       {
                                    if((yyvsp[-2].node)->Ctype == NULL) {
                                        yyerror("Cannot DELETE a non class variable\n");
                                        exit(1);
                                    }
                                    (yyval.node) = createTree(TLookup("void"),NULL, DELETE_NODE, NULL, NULL, (yyvsp[-2].node), NULL, NULL);
                                }
#line 2378 "y.tab.c"
    break;

  case 96: /* InputStmt: READ LPAREN id RPAREN SEMI  */
#line 548 "parser.y"
                                       {
    (yyval.node) = createTree(TLookup("void"), NULL,READ_NODE, NULL, NULL, (yyvsp[-2].node),NULL, NULL);
}
#line 2386 "y.tab.c"
    break;

  case 97: /* OutputStmt: WRITE LPAREN expr RPAREN SEMI  */
#line 552 "parser.y"
                                           {
            (yyval.node) = createTree(TLookup("void"), NULL,WRITE_NODE, NULL, NULL, (yyvsp[-2].node), NULL, NULL);
            
}
#line 2395 "y.tab.c"
    break;

  case 98: /* AsgStmt: id ASSIGN expr SEMI  */
#line 557 "parser.y"
                               {
            if ((yyvsp[-1].node)->nodetype == ALLOC_NODE) {
                (yyvsp[-1].node)->type = (yyvsp[-3].node)->type;
            }   
             if ((yyvsp[-1].node)->nodetype == NEW_NODE) {
        if ((yyvsp[-3].node)->Ctype != (yyvsp[-1].node)->Ctype) {
            yyerror("Type mismatch in new() assignment\n");
            exit(1);
        }
    } else {
        typecheck((yyvsp[-3].node)->type, (yyvsp[-1].node)->type, '=');
    }
            (yyval.node) = createTree(TLookup("void"), NULL,ASSIGN_NODE, NULL, NULL, (yyvsp[-3].node), (yyvsp[-1].node), NULL);
        }
#line 2414 "y.tab.c"
    break;

  case 99: /* AsgStmt: Field ASSIGN expr SEMI  */
#line 571 "parser.y"
                                          {
         if ((yyvsp[-1].node)->nodetype == ALLOC_NODE) {
            (yyvsp[-1].node)->type = (yyvsp[-3].node)->type;
        }
         if ((yyvsp[-1].node)->nodetype == NEW_NODE) {
        if ((yyvsp[-3].node)->Ctype != (yyvsp[-1].node)->Ctype) {
            yyerror("Type mismatch in new() assignment\n");
            exit(1);
        }
    } else {
        typecheck((yyvsp[-3].node)->type, (yyvsp[-1].node)->type, '=');
    }
        (yyval.node) = createTree(TLookup("void"), NULL,ASSIGN_NODE, NULL, NULL, (yyvsp[-3].node), (yyvsp[-1].node), NULL);
                    
        }
#line 2434 "y.tab.c"
    break;

  case 100: /* IfStmt: IF LPAREN expr RPAREN THEN Slist ELSE Slist ENDIF SEMI  */
#line 588 "parser.y"
                                                                {
        typecheck((yyvsp[-7].node)->type, TLookup("bool"), 'e');
        (yyval.node) = createTree(TLookup("void"), NULL,IF_ELSE_NODE, NULL, NULL, (yyvsp[-7].node), (yyvsp[-2].node), (yyvsp[-4].node));
}
#line 2443 "y.tab.c"
    break;

  case 101: /* IfStmt: IF LPAREN expr RPAREN THEN Slist ENDIF SEMI  */
#line 592 "parser.y"
                                                  {
        typecheck((yyvsp[-5].node)->type, TLookup("bool"), 'i');
        (yyval.node) = createTree(TLookup("void"), NULL,IF_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-2].node),NULL);
}
#line 2452 "y.tab.c"
    break;

  case 102: /* WhileStmt: WHILE LPAREN expr RPAREN DO Slist ENDWHILE SEMI  */
#line 597 "parser.y"
                                                           {
        typecheck((yyvsp[-5].node)->type,TLookup("bool"), 'w');
        (yyval.node) = createTree(TLookup("void"), NULL,WHILE_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
}
#line 2461 "y.tab.c"
    break;

  case 103: /* BrkStmt: BREAK SEMI  */
#line 602 "parser.y"
                     {
    (yyval.node) = createTree(TLookup("void"), NULL,BREAK_NODE, NULL, NULL, NULL, NULL, NULL);
}
#line 2469 "y.tab.c"
    break;

  case 104: /* ContStmt: CONT SEMI  */
#line 606 "parser.y"
                    {
    (yyval.node) = createTree(TLookup("void"), NULL,CONT_NODE, NULL, NULL, NULL, NULL, NULL);
}
#line 2477 "y.tab.c"
    break;

  case 105: /* repeatUntilStmt: REPEAT Slist UNTIL LPAREN expr RPAREN SEMI  */
#line 610 "parser.y"
                                                            {
    typecheck((yyvsp[-2].node)->type, TLookup("bool"), 'r');
    (yyval.node) = createTree(TLookup("void"), NULL, REPEAT_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
}
#line 2486 "y.tab.c"
    break;

  case 106: /* doWhileStmt: DO Slist WHILE LPAREN expr RPAREN SEMI  */
#line 615 "parser.y"
                                                    {
    typecheck((yyvsp[-2].node)->type, TLookup("bool"), 'd');
    (yyval.node) = createTree(TLookup("void"), NULL, DOWHILE_NODE, NULL, NULL, (yyvsp[-5].node), (yyvsp[-2].node), NULL);
}
#line 2495 "y.tab.c"
    break;

  case 107: /* expr: expr PLUS expr  */
#line 621 "parser.y"
                      {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(TLookup("int"),NULL, ADD_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2504 "y.tab.c"
    break;

  case 108: /* expr: expr MINUS expr  */
#line 625 "parser.y"
                     {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(TLookup("int"),NULL, SUB_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2513 "y.tab.c"
    break;

  case 109: /* expr: expr MUL expr  */
#line 629 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(TLookup("int"),NULL, MUL_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2522 "y.tab.c"
    break;

  case 110: /* expr: expr DIV expr  */
#line 633 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(TLookup("int"),NULL, DIV_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2531 "y.tab.c"
    break;

  case 111: /* expr: expr LT expr  */
#line 637 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(TLookup("bool"),NULL, LT_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2540 "y.tab.c"
    break;

  case 112: /* expr: expr LE expr  */
#line 641 "parser.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(TLookup("bool"),NULL, LE_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2549 "y.tab.c"
    break;

  case 113: /* expr: expr GE expr  */
#line 645 "parser.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(TLookup("bool"),NULL, GE_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2558 "y.tab.c"
    break;

  case 114: /* expr: expr GT expr  */
#line 649 "parser.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(TLookup("bool"),NULL, GT_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2567 "y.tab.c"
    break;

  case 115: /* expr: expr NE expr  */
#line 653 "parser.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(TLookup("bool"),NULL, NE_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2576 "y.tab.c"
    break;

  case 116: /* expr: expr EQ expr  */
#line 657 "parser.y"
                  {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'b');
        (yyval.node) = createTree(TLookup("bool"),NULL, EQ_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2585 "y.tab.c"
    break;

  case 117: /* expr: expr MOD expr  */
#line 661 "parser.y"
                   {
        typecheck((yyvsp[-2].node)->type, (yyvsp[0].node)->type, 'a');
        (yyval.node) = createTree(TLookup("int"),NULL, MOD_NODE, NULL, NULL, (yyvsp[-2].node), (yyvsp[0].node), NULL);
}
#line 2594 "y.tab.c"
    break;

  case 118: /* expr: Field EQNILL  */
#line 665 "parser.y"
                      {
                            typecheck((yyvsp[-1].node)->type, NULL, '!');
                            (yyval.node) = createTree(TLookup("bool"),NULL, EQ_NODE,  NULL, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                        }
#line 2603 "y.tab.c"
    break;

  case 119: /* expr: Field NEQNILL  */
#line 669 "parser.y"
                        {
                            typecheck((yyvsp[-1].node)->type, NULL, '!');
                            (yyval.node) = createTree(TLookup("bool"),NULL, NE_NODE, NULL, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                        }
#line 2612 "y.tab.c"
    break;

  case 120: /* expr: ID EQNILL  */
#line 673 "parser.y"
                       {
                            assignType((yyvsp[-1].node), 0);
                            (yyval.node) = createTree(TLookup("bool"),NULL, EQ_NODE,  NULL, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                        }
#line 2621 "y.tab.c"
    break;

  case 121: /* expr: ID NEQNILL  */
#line 677 "parser.y"
                        {
                            assignType((yyvsp[-1].node), 0);
                            (yyval.node) = createTree(TLookup("bool"),NULL, NE_NODE, NULL, NULL, (yyvsp[-1].node), (yyvsp[0].node), NULL);
                        }
#line 2630 "y.tab.c"
    break;

  case 122: /* expr: LPAREN expr RPAREN  */
#line 681 "parser.y"
                         {(yyval.node) = (yyvsp[-1].node);}
#line 2636 "y.tab.c"
    break;

  case 123: /* expr: MINUS NUM  */
#line 682 "parser.y"
                {
        (yyvsp[0].node)->value.intval=-1*((yyvsp[0].node)->value.intval);
        (yyval.node) = (yyvsp[0].node);
        (yyval.node)->type=TLookup("int");
        }
#line 2646 "y.tab.c"
    break;

  case 124: /* expr: NUM  */
#line 687 "parser.y"
          {
        (yyval.node) = (yyvsp[0].node);
        (yyval.node)->type=TLookup("int");
        }
#line 2655 "y.tab.c"
    break;

  case 125: /* expr: STRVAL  */
#line 691 "parser.y"
             {
        (yyval.node) = (yyvsp[0].node);
        (yyval.node)->type=TLookup("str");
        }
#line 2664 "y.tab.c"
    break;

  case 126: /* expr: id  */
#line 695 "parser.y"
         {(yyval.node) = (yyvsp[0].node);}
#line 2670 "y.tab.c"
    break;

  case 127: /* expr: Field  */
#line 696 "parser.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 2676 "y.tab.c"
    break;

  case 128: /* expr: ALLOC LPAREN RPAREN  */
#line 697 "parser.y"
                          {
        (yyval.node) = (yyvsp[-2].node); 
        (yyval.node)->type = TLookup("void");  
    }
#line 2685 "y.tab.c"
    break;

  case 129: /* expr: NILL  */
#line 701 "parser.y"
          {
        (yyval.node)=createTree(TLookup("void"),NULL,NULL_NODE,NULL,NULL,NULL,NULL,NULL);
    }
#line 2693 "y.tab.c"
    break;

  case 130: /* expr: INIT LPAREN RPAREN  */
#line 705 "parser.y"
    {(yyval.node) = createTree(TLookup("int"),NULL, INIT_NODE, NULL, NULL, NULL, NULL, NULL);}
#line 2699 "y.tab.c"
    break;

  case 131: /* expr: FieldFunction  */
#line 706 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 2705 "y.tab.c"
    break;

  case 132: /* expr: NEW LPAREN ID RPAREN  */
#line 707 "parser.y"
                           {
           struct Classtable *c = CLookup((yyvsp[-1].node)->varname);
           if (c == NULL) {
               fprintf(stderr, "Unknown class '%s' in new()\n", (yyvsp[-1].node)->varname);
               yyerror(""); exit(1);
           }
           (yyvsp[-3].node)->Ctype = c;
           (yyvsp[-3].node)->type=TLookup("void");
           (yyval.node) = (yyvsp[-3].node);
       }
#line 2720 "y.tab.c"
    break;

  case 133: /* id: ID  */
#line 718 "parser.y"
        {
        if(CLookup((yyvsp[0].node)->varname) != NULL) {
            (yyval.node)=(yyvsp[0].node);
        }
        else {assignType((yyvsp[0].node),0);
        (yyval.node)=(yyvsp[0].node);}
    }
#line 2732 "y.tab.c"
    break;

  case 134: /* id: ID LBRACK expr RBRACK  */
#line 725 "parser.y"
                            {
        assignType((yyvsp[-3].node),2);
        (yyval.node)=createTree((yyvsp[-3].node)->type,NULL,ARRAY_NODE,NULL,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
    }
#line 2741 "y.tab.c"
    break;

  case 135: /* id: ID LPAREN ExprList RPAREN  */
#line 729 "parser.y"
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
    // printf("function %s type %s\n",$1->varname,g->type->name);
    
    checkFunctionArgs(g,g->paramlist, (yyvsp[-3].node)->argList);
    (yyval.node)=(yyvsp[-3].node);
    // printf("function call type %s %s\n",$1->type->name,$1->varname);
}
#line 2763 "y.tab.c"
    break;

  case 136: /* ExprList: ExprList COMMA expr  */
#line 749 "parser.y"
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
#line 2780 "y.tab.c"
    break;

  case 137: /* ExprList: expr  */
#line 761 "parser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2786 "y.tab.c"
    break;

  case 138: /* ExprList: %empty  */
#line 762 "parser.y"
                            {(yyval.node) = NULL;}
#line 2792 "y.tab.c"
    break;


#line 2796 "y.tab.c"

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

#line 771 "parser.y"

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
