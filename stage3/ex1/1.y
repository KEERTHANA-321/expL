%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "nodestructure.h"
    #include "constants.h"
    #include "evaluate.c"
    int yydebug = 1; 
    

    int yylex(void);
    void yyerror(char const *msg);
    extern FILE *yyin;
    FILE *out;
%}

%union {
    struct tnode *node;
}

%token KW_BEGIN END READ WRITE PLUS MINUS MUL DIV NUM ID SEMI ASSIGN
%token LE,LT,GE,GT,NE,EQ,IF,WHILE,ENDWHILE,ENDIF,DO,THEN,ELSE
%left PLUS MINUS
%left MUL DIV
%right ASSGN
%nonassoc LT GT LE GE
%right EQ NE

%type <node> NUM ID KW_BEGIN END READ WRITE PLUS MINUS MUL DIV ASSIGN
%type <node> IF THEN ELSE ENDIF WHILE DO ENDWHILE EQ NEQ LE GE LT GT
%type <node> program Slist Stmt InputStmt OutputStmt AsgStmt WhileStmt IfStmt expr SEMI

%%

program : KW_BEGIN Slist END SEMI {
    $$ = $2; 
    print($2);
    evaluate($2);
    exit(0);}
    | KW_BEGIN END SEMI { $$=$2;}
    ;


Slist : Slist Stmt {$$=createTree(1,0,CONNECTOR_NODE,NULL,$1,$2,NULL);}
    | Stmt {$$=$1;} 
    ;

Stmt : InputStmt  {$$=$1;}
    | OutputStmt {$$=$1;}
    | AsgStmt {$$=$1;}
    | IfStmt {$$=$1;}
    | WhileStmt {$$=$1;}
    ;

IfStmt:  IF '(' expr ')' THEN Slist ELSE Slist ENDIF SEMI {
            typecheck($3->type, BOOL, 'e');
            $$ = createTree(NONE, 0, IF_ELSE_NODE, NULL, $3, $8, $6);
            }
    | IF '(' expr ')' THEN Slist ENDIF SEMI{
            typecheck($3->type, BOOL, 'i');
            $$ = createTree(NONE, 0, IF_NODE, NULL, $3, $6, NULL);
            };

WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE SEMI
{
            typecheck($3->type, BOOL, 'e');
            $$ = createTree(NONE, 0, WHILE_NODE, NULL, $3, $6,NULL);
            };

InputStmt : READ '(' ID ')' SEMI { 
                $3->type=INT;
                $$=createTree(NONE,0,READ_NODE,NULL,$3,NULL,NULL);}
            ;
OutputStmt : WRITE '(' expr ')' SEMI {$$=createTree(NONE,0,WRITE_NODE,NULL,$3,NULL,NULL);}
            ;
AsgStmt : ID ASSIGN expr SEMI {
            typecheck($1->type, $3->type, '=');
            $1->type = $3->type;
            $$=createTree(NONE,0,ASSIGN_NODE,NULL,$1,$3,NULL);}
        ;

expr : expr PLUS expr { 
        typecheck($1->type,$3->type,'a');
        $$ = createTree(1,0,ADD_NODE,NULL, $1, $3,NULL); 
        $$->type = INT;
        }
    | expr MINUS expr {
        typecheck($1->type,$3->type,'a'); 
        $$ = createTree(1,0,SUB_NODE,NULL, $1, $3,NULL); 
        $$->type = INT;
        }
    | expr MUL expr {
        typecheck($1->type,$3->type,'a');
        $$ = createTree(1,0,MUL_NODE,NULL, $1, $3,NULL); 
        $$->type = INT;
        }
    | expr DIV expr {
        typecheck($1->type,$3->type,'a');
        $$ = createTree(1,0,DIV_NODE,NULL,$1,$3,NULL);
        $$->type = INT;
        }
    | expr LT expr {
        typecheck($1->type,$3->type,'b'); 
        $$ = createTree(BOOL,0,LT_NODE,NULL,$1,$3,NULL);}
    | expr GT expr {
        typecheck($1->type,$3->type,'b'); 
        $$ = createTree(BOOL,0,GT_NODE,NULL,$1,$3,NULL);}
    | expr LE expr {
        typecheck($1->type,$3->type,'b'); 
        $$ = createTree(BOOL,0,LE_NODE,NULL,$1,$3,NULL);}    
    | expr GE expr {
        typecheck($1->type,$3->type,'b'); 
        $$ = createTree(BOOL,0,GE_NODE,NULL,$1,$3,NULL);}
    | expr NE expr {
        typecheck($1->type,$3->type,'b'); 
        $$ = createTree(BOOL,0,NE_NODE,NULL,$1,$3,NULL);}
    | expr EQ expr {
        typecheck($1->type,$3->type,'b'); 
        $$ = createTree(BOOL,0,EQ_NODE,NULL,$1,$3,NULL);}
    | '(' expr ')' { $$ = $2; }
    | NUM { $$ = $1; }
    | ID { $$=$1; }
    ;

%%

void yyerror(char const *msg) {
    printf("[Error] : %s\n", msg);
    return;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <sourcefile>\n", argv[0]);
        return 1;
    }

    FILE *source_file = fopen(argv[1], "r");
    if (source_file == NULL) {
        perror("Error opening source file");
        return 1;
    }

    yyin = source_file;
    return yyparse();
}