%{
    #include "y.tab.h"
%}

%%

[a-z]+   { yylval.c=yytext; return ID; } //strcpy(yylval.c,yytext); 
[+*]    { return yytext[0]; }
\n      { return '\n'; }
[ \t]   ;
.       ;

%%

int yywrap() { return 1; }
