%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "nodestructure.h"
    #include "constants.h"
    #include "symbolTable.h"
    int yydebug = 1; 
    

    int yylex(void);
    void yyerror(char const *msg);
    extern FILE *yyin;
    FILE *out;
%}

%union {
    struct tnode *node;
}

%token KW_BEGIN END READ WRITE PLUS MINUS MUL DIV NUM ID SEMI ASSIGN STRVAL
%token LE LT GE GT NE EQ IF WHILE ENDWHILE ENDIF DO THEN ELSE
%token BREAK CONT REPEAT UNTIL DECL ENDDECL T_INT T_STR COMMA LBRACK RBRACK
%left PLUS MINUS
%left MUL DIV
%right ASSGN
%nonassoc LT GT LE GE
%right EQ NE

%type <node> NUM ID STRVAL
%type <node> program Slist Stmt InputStmt OutputStmt AsgStmt WhileStmt IfStmt expr SEMI
%type <node> BrkStmt ContStmt doWhileStmt repeatUntilStmt
%type <node> Declarations DeclList Decl VarList Type id

%%

program : Declarations KW_BEGIN Slist END SEMI {
    $$ = $3;
    print($3);
    initialize();
    codegen($3); 
    generateExitCode();
    printSymbolTable();
    exit(0);}
    |Declarations KW_BEGIN END SEMI { $$=NULL;}
    ;


Declarations : DECL DeclList ENDDECL 
            | DECL ENDDECL
            ;

DeclList : DeclList Decl 
        | Decl
        ;

Decl : Type VarList SEMI
    ;

Type : T_INT {declaration_type=INT;}
    | T_STR {declaration_type=STRING;}
    ;

VarList : VarList COMMA ID {install($3->varname, declaration_type, 1);}
        | ID {install($1->varname,declaration_type,1);}
        | VarList COMMA ID LBRACK NUM RBRACK {install($3->varname,declaration_type,$5->val);}
        | ID LBRACK NUM RBRACK {install($1->varname,declaration_type,$3->val);}
        ;

Slist : Slist Stmt {$$=createTree(1,0,CONNECTOR_NODE,NULL,$1,$2,NULL);}
    | Stmt {$$=$1;} 
    ;

Stmt : InputStmt    {$$=$1;}
    | OutputStmt    {$$=$1;}
    | AsgStmt   {$$=$1;}
    | IfStmt    {$$=$1;}
    | WhileStmt {$$=$1;}
    | BrkStmt   {$$=$1;}
    | ContStmt  {$$=$1;}
    | repeatUntilStmt { $$ = $1; }
    | doWhileStmt { $$ = $1; }
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
BrkStmt: BREAK SEMI  {$$ = createTree(NONE, 0, BREAK_NODE, NULL, NULL, NULL, NULL);}

ContStmt: CONT SEMI  {$$ = createTree(NONE, 0, CONT_NODE, NULL, NULL, NULL, NULL);}
repeatUntilStmt: REPEAT Slist UNTIL '(' expr ')' SEMI { $$ = createTree(NONE,0,REPEAT_NODE,NULL,$2, $5,NULL); }
    ;

doWhileStmt: DO Slist WHILE '(' expr ')' SEMI { $$ = createTree(NONE,0,DOWHILE_NODE,NULL,$2, $5,NULL); }
    ;


InputStmt : READ '(' id ')' SEMI { 
                $$=createTree(NONE,0,READ_NODE,NULL,$3,NULL,NULL);}
            ;
OutputStmt : WRITE '(' expr ')' SEMI {$$=createTree(NONE,0,WRITE_NODE,NULL,$3,NULL,NULL);}
            ;
AsgStmt : id ASSIGN expr SEMI {
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
    | STRVAL {$$ = $1;}
    | id { $$=$1; }
    ;
id: ID {
    $1->Gentry=lookup($1->varname);
    if($1->Gentry==NULL){
        printf("variable %s not declared\n",$1->varname);
        exit(1);
    }
    $1->type=$1->Gentry->type;
    $$=$1;
    }
    | ID LBRACK NUM RBRACK {
        $1->Gentry=lookup($1->varname);
        if($1->Gentry==NULL){
            printf("variable %s not declared\n",$1->varname);
            exit(1);
        }
        else if($3->val>=$1->Gentry->size || $3->val < 0){
            printf("Array %s out of bounds\n",$1->varname);
            exit(1);
        }
        $1->type=$1->Gentry->type;
        $$=createTree($1->type,0,ARRAY_NODE,NULL,$1,$3,NULL);
    }
    | ID LBRACK id RBRACK{
        $1->Gentry=lookup($1->varname);
        if($1->Gentry==NULL){
            printf("variable %s not declared\n",$1->varname);
            exit(1);
        }
        $1->type=$1->Gentry->type;
        $$=createTree($1->type,0,ARRAY_NODE,NULL,$1,$3,NULL);
    }

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