%option yylineno
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "constants.h"
    #include "nodestructure.h"
    #include "typetable.h"
    int number;
    char *variable;
%}

%%

[0-9]+ {
    number = atoi(yytext);
    union Constant *value=(union Constant *) malloc(sizeof(union Constant));
    value->intval=number;
    yylval.node = createTree(TLookup("int"),value,NUM_NODE,NULL,NULL,NULL,NULL,NULL);
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
"main" {return MAIN;}
"return" {return RETURN;}
"brkp"  { return KW_BRKP; }
"endtype" {return ENDTYPE;}
"type" {return TYPE;}
"null" {return NILL;}
"class" {return CLASS;}
"endclass" {return ENDCLASS;}
"=="[ ]*"null" 	{
                    yylval.node = createTree(TLookup("int"),NULL, NULL_NODE, NULL, NULL, NULL, NULL, NULL);
                    return EQNILL;
		}
"!="[ ]*"null" 	{
                    yylval.node = createTree(TLookup("int"),NULL, NULL_NODE, NULL, NULL, NULL, NULL, NULL);
                    return NEQNILL;
		}
"free" {return FREE;}
"alloc" {
                yylval.node = createTree(NULL, NULL,ALLOC_NODE,NULL, NULL, NULL, NULL, NULL);
                return ALLOC;
            }
"initialize" {return INIT;}
"delete"    {return DELETE;}
"self"      {
                yylval.node = createTree(NULL,NULL, SELF_NODE, NULL, NULL, NULL, NULL, NULL);
                return SELF;
            }
"new"       {
                variable = malloc(strlen(yytext) + 1);
                strcpy(variable, yytext);
                yylval.node = createTree(TLookup("int"),NULL, NEW_NODE, variable, NULL, NULL, NULL, NULL);
                return NEW;
            }

"," {return COMMA;}
[a-zA-Z_][0-9a-zA-Z_]* {
            variable = malloc(strlen(yytext) + 1);
            strcpy(variable, yytext);
            yylval.node=createTree(TLookup("int"),NULL,VARIABLE_NODE,variable,NULL,NULL,NULL,NULL);
            return ID;
        }
\"[^\n]*\" {variable = (char*)malloc(yyleng+1);
            strcpy(variable, yytext);
            union Constant *value=(union Constant *) malloc(sizeof(union Constant));
            value->strval=variable;
            yylval.node = createTree(TLookup("str"), value, STRVAL_NODE, NULL,NULL, NULL, NULL, NULL);
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
"(" {return LPAREN;}
")" {return RPAREN;}
"{" {return LBRACE;}
"}" {return RBRACE;}
"%" {return MOD;}
"." {return DOT;}


[\t ] {}
. {printf("unknown character %s\n", yytext); exit(1);}
[\n] {}

%%

int yywrap() {
    return 1;
}