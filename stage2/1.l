%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "nodestructure.h"
    #include "y.tab.h"

    int number;
    char *id;
%}

%%

[0-9]+ {
    number = atoi(yytext);
    yylval.node = makeLeafNode(number);
    return NUM;
}
"begin" {return BEGIN;}
"read" {return READ;};
"write" {return WRITE;}
"end" {return END;}
[a-z]+ {id=*yytext;
        yylval.node=makeIdNode(id);
        return ID;} 
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}

[\t ] {}
[()] {return yytext[0];}
[\n] {return END;}
. {printf("unknown character %s\n", yytext); exit(1);}

%%

int yywrap() {
    return 1;
}