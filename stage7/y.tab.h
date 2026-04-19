/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 193 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
