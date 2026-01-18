%{
    #include <stdio.h>

    int yylex(void);                
    int yyerror(const char *s); 
%}

%union {
    char c;
}

%token <c> ID
%left '+'
%left '*'

%type <c> expr

%%

start : expr '\n' { printf("\n"); }
      ;

expr  : expr '+' expr { printf("+"); }
      | expr '*' expr { printf("*"); }
      | ID            { printf("%c", $1); }
      ;

%%

int yyerror(const char *s) {
    printf("Error\n");
    return 0;
}

int main() {
    yyparse();
    return 0;
}
