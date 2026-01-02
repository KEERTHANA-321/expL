%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "tree.h"

    tnode *root;   /* The root of the expression tree */

    int yylex();
    void yyerror(char *s);
%}

%token NUM
%token PLUS MINUS MUL DIV
%token EOL

%left PLUS MINUS
%left MUL DIV


%%

input: 
    expr EOL {root = $1; return 0;}
    | /* empty */ {return 0;}
    ;

expr:
    expr PLUS expr {$$ = makeOperatorNode("+", $1, $3);}
    | expr MINUS expr {$$ = makeOperatorNode("-", $1, $3);}
    | expr MUL expr      { $$ = makeOperatorNode("*", $1, $3); }
    | expr DIV expr      { $$ = makeOperatorNode("/", $1, $3); }
    | NUM             { $$ = $1; }
    ;

%%

int main()
{
    printf("Enter an expression:-\n");

    yyparse();

    printf("\nPrefix order : ");
    preorderTraversal(root);
    printf("\nPostfix order: ");
    postorderTraversal(root);
    printf("\n");

    deleteTree(root);

    return 0;
}


void yyerror(char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}
