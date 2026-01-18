%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "nodestructure.h"
    #include "nodestructure.c"

    int yylex(void);
    void yyerror(char const *msg);
%}

%union {
    struct tnode *node;
}

%type <node> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : BEGIN Slist END {
    $$ = $2;
    printf("Answer: %d\n", evaluate($1));
    exit(0);}
    | BEGIN END
    ;

Slist : Slist Stmt 
    | Stmt
    ;

Stmt : InputStmt 
    | OutputStmt
    | AsgStmt
    ;
InputStmt : READ '(' ID ')' ';'
            ;
OutputStmt : WRITE '(' E ')' ';'
            ;
AsgStmt : ID '=' E ';'
        ;

expr : expr PLUS expr { $$ = makeOperatorNode('+', $1, $3); }
    | expr MINUS expr { $$ = makeOperatorNode('-', $1, $3); }
    | expr MUL expr { $$ = makeOperatorNode('*', $1, $3); }
    | expr DIV expr { $$ = makeOperatorNode('/', $1, $3); }
    | '(' expr ')' { $$ = $2; }
    | NUM { $$ = $1; }
    | ID {$$=makeIdNode($1,)}
    ;

%%

void yyerror(char const *msg) {
    printf("[Error] : %s\n", msg);
    return;
}

int main() {
    return yyparse();
}