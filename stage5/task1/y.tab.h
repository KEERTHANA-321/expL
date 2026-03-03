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
    RPAREN = 301                   /* RPAREN  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "first.y"

    struct tnode *node;

#line 163 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
