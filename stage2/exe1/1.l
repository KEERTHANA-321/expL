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
    yylval.node = createTree(1,number,NUM_NODE,NULL,NULL,NULL);
    return NUM;
}
"begin" {return KW_BEGIN;}
"read" {return READ;};
"write" {return WRITE;}
"end" {return END;}
[a-z]+ {variable = (char*)malloc(sizeof(yytext));
        strcpy(variable, yytext);
        yylval.node=createTree(1,0,VARIABLE_NODE,variable,NULL,NULL);
        return ID;} 
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
";" {return SEMI;}
"=" {return ASSIGN;}

[\t ] {}
[()] {return yytext[0];}
. {printf("unknown character %s\n", yytext); exit(1);}

%%

int yywrap() {
    return 1;
}