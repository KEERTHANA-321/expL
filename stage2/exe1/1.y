%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "nodestructure.h"
    #include "nodestructure.c"
    #include "constants.h"
    #include "codegen.c"
    #include "evaluate.c"

    int yylex(void);
    void yyerror(char const *msg);
    extern FILE *yyin;
    FILE *out;
%}

%union {
    struct tnode *node;
}

%token KW_BEGIN END READ WRITE PLUS MINUS MUL DIV ASSGN NUM ID SEMI ASSIGN
%left PLUS MINUS
%left MUL DIV

%type <node> NUM ID KW_BEGIN END READ WRITE PLUS MINUS MUL DIV ASSGN
%type <node> program Slist Stmt InputStmt OutputStmt AsgStmt expr SEMI

%%

program : KW_BEGIN Slist END SEMI {
    $$ = $2; 
    evaluate($2);
    exit(0);}
    | KW_BEGIN END SEMI { $$=$2;}
    ;

Slist : Slist Stmt {$$=createTree(1,0,CONNECTOR_NODE,NULL,$1,$2);}
    | Stmt {$$=$1;} 
    ;

Stmt : InputStmt  {$$=$1;}
    | OutputStmt {$$=$1;}
    | AsgStmt {$$=$1;}
    ;
InputStmt : READ '(' ID ')' SEMI {$$=createTree(1,0,READ_NODE,NULL,$3,NULL);}
            ;
OutputStmt : WRITE '(' expr ')' SEMI {$$=createTree(1,0,WRITE_NODE,NULL,$3,NULL);}
            ;
AsgStmt : ID ASSIGN expr SEMI {$$=createTree(1,0,ASSIGN_NODE,NULL,$1,$3);}
        ;

expr : expr PLUS expr { $$ = createTree(1,0,ADD_NODE,NULL, $1, $3); }
    | expr MINUS expr { $$ = createTree(1,0,SUB_NODE,NULL, $1, $3); }
    | expr MUL expr { $$ = createTree(1,0,MUL_NODE,NULL, $1, $3); }
    | expr DIV expr { $$ = createTree(1,0,DIV_NODE,NULL,$1,$3);}
    | '(' expr ')' { $$ = $2; }
    | NUM { $$ = $1; }
    | ID { $$=$1; }
    ;

%%

void yyerror(char const *msg) {
    printf("[Error] : %s\n", msg);
    return;
}

int main() {
    FILE *source_file = fopen(SOURCE_FILE, "r");
    yyin = source_file;
    return yyparse();
}