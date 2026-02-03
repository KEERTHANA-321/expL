%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "nodestructure.h"
    #include "y.tab.h"
    #include "constants.h"

    int number;
    char *variable;
%}

%%

[0-9]+ {
    number = atoi(yytext);
    yylval.node = createTree(INT,number,NUM_NODE,NULL,NULL,NULL,NULL);
    return NUM;
}
"begin" {return KW_BEGIN;}
"read" {return READ;};
"write" {return WRITE;}
"end" {return END;}
"if" {return IF;}
"else" {return ELSE;}
"then" {return THEN;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do" {return DO;}
"endwhile" {return ENDWHILE;}
"break"     {return BREAK;}
"continue"  {return CONT;}
"repeat"    {return REPEAT;}
"until"    {return UNTIL;}
"decl"  {return DECL;}
"enddecl"   {return ENDDECL;}
"int"       {return T_INT;}
"str"       {return T_STR;}
"," {return COMMA;}
[a-zA-Z][0-9a-zA-Z]* {variable = malloc(strlen(yytext) + 1);
        strcpy(variable, yytext);
        yylval.node=createTree(INT,0,VARIABLE_NODE,variable,NULL,NULL,NULL);
        return ID;}
\"[^\n]*\" {variable = (char*)malloc(yyleng);
            strcpy(variable, yytext);
            yylval.node = createTree(STRING, 0, STRVAL_NODE, variable, NULL, NULL, NULL);
            return STRVAL;}
"=="    {return EQ;}
"!="    {return NE;}
"<="    {return LE;}
">="    {return GE;}
"<" {return LT;}
">" {return GT;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
";" {return SEMI;}
"=" {return ASSIGN;}
"[" {return LBRACK;}
"]" {return RBRACK;}
"&" {return AND;}
"%" {return MOD;}

[\t ] {}
[()] {return yytext[0];}
. {printf("unknown character %s\n", yytext); exit(1);}
[\n] {}

%%

int yywrap() {
    return 1;
}