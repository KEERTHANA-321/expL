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
    MOD = 271,                     /* MOD  */
    LE = 272,                      /* LE  */
    LT = 273,                      /* LT  */
    GE = 274,                      /* GE  */
    GT = 275,                      /* GT  */
    NE = 276,                      /* NE  */
    EQ = 277,                      /* EQ  */
    IF = 278,                      /* IF  */
    WHILE = 279,                   /* WHILE  */
    ENDWHILE = 280,                /* ENDWHILE  */
    ENDIF = 281,                   /* ENDIF  */
    DO = 282,                      /* DO  */
    THEN = 283,                    /* THEN  */
    ELSE = 284,                    /* ELSE  */
    BREAK = 285,                   /* BREAK  */
    CONT = 286,                    /* CONT  */
    REPEAT = 287,                  /* REPEAT  */
    UNTIL = 288,                   /* UNTIL  */
    DECL = 289,                    /* DECL  */
    ENDDECL = 290,                 /* ENDDECL  */
    T_INT = 291,                   /* T_INT  */
    T_STR = 292,                   /* T_STR  */
    COMMA = 293,                   /* COMMA  */
    LBRACK = 294,                  /* LBRACK  */
    RBRACK = 295,                  /* RBRACK  */
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
#define MOD 271
#define LE 272
#define LT 273
#define GE 274
#define GT 275
#define NE 276
#define EQ 277
#define IF 278
#define WHILE 279
#define ENDWHILE 280
#define ENDIF 281
#define DO 282
#define THEN 283
#define ELSE 284
#define BREAK 285
#define CONT 286
#define REPEAT 287
#define UNTIL 288
#define DECL 289
#define ENDDECL 290
#define T_INT 291
#define T_STR 292
#define COMMA 293
#define LBRACK 294
#define RBRACK 295
#define ASSGN 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

    struct tnode *node;

#line 153 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
