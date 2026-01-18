%{
    #include "y.tab.h"
%}

%%

[a-z]   { yylval.c = yytext[0]; return ID; }
[+*]    { return yytext[0]; }
\n      { return '\n'; }
[ \t]   ;
.       ;

%%

int yywrap() { return 1; }
