%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbolTable.h"
    #include "constants.h"
    #include "nodestructure.h"
    #include "typecheck.h"
    int yylex(void);
    void yyerror(char const *msg);
    extern FILE *yyin;
    FILE *out;
    extern int yylineno;
    extern char *yytext;
    struct Paramstruct *argList1, *argList2;
    int declCount = 0, defCount = 0;
    int current_function_type = 0;
    int testing=1;
%}

%union {
    struct tnode *node;
}
%token PLUS MINUS MUL DIV MOD LT GT LE GE NE EQ  ASSIGN
%token DO IF ELSE WHILE BREAK CONT KW_BEGIN END ENDIF THEN ENDWHILE REPEAT UNTIL
%token <node> NUM STRVAL ID READ WRITE
%token DECL ENDDECL T_INT T_STR COMMA MAIN SEMI RETURN
%token LBRACE RBRACE LBRACK RBRACK LPAREN RPAREN


%type <node> Program MainBlock FDefBlock FDef Body RetStmt
%type <node> Slist Stmt InputStmt OutputStmt AsgStmt IfStmt WhileStmt BrkStmt ContStmt repeatUntilStmt doWhileStmt
%type <node> expr id func ExprList

%right ASSIGN
%nonassoc LT GT LE GE EQ NE
%left PLUS MINUS
%left MUL DIV MOD

%%
Program : GDeclBlock FDefBlock MainBlock 
{
    printf("\n=== GST AFTER GLOBAL DECLARATIONS ===\n");
          printGSymbolTable();
          $$ = $3;
     fclose(out);
}
        | GDeclBlock MainBlock
        {
          printf("\n=== GST AFTER GLOBAL DECLARATIONS ===\n");
          printGSymbolTable();
          $$ = $2;
          fclose(out);
      }
        | MainBlock {fclose(out);}
        ;
GDeclBlock : DECL GDeclList ENDDECL {initialize();}
            | DECL ENDDECL {initialize();}
            ;
GDeclList : GDeclList GDecl 
            | GDecl
            ;
GDecl : Type GidList SEMI
    ;

Type : T_INT { declaration_type = INT; }
    | T_STR { declaration_type = STRING; }
    ;

Ftype : T_INT { fdeclaration_type = INT; }
    | T_STR { fdeclaration_type = STRING; }
    ;

GidList : GidList COMMA Gid
        | Gid
        ;
Gid : ID {
     checkAvailability($1->varname,1);   
     
     GInstall($1->varname,declaration_type,1,NULL);
}
    | ID LBRACK NUM RBRACK {
        checkAvailability($1->varname,1);   
        if($3->value.intval < 1) {
        yyerror("Invalid array size");
        exit(1);
    }
     GInstall($1->varname,declaration_type,$3->value.intval,NULL);
    }
    | ID LPAREN ParamList RPAREN {
        declCount++;
        checkAvailability($1->varname,1);
        GInstall($1->varname,declaration_type,-1,Phead);
        Phead=NULL;
        Ptail=NULL;
    }
    ;

FDefBlock : FDefBlock FDef
        | FDef
        ;
FDef : Ftype ID LPAREN ParamList RPAREN LBRACE LDeclBlock Body RBRACE  /*ftype because inside there will be other types and tree*/
        {
            defCount++;
            Gtemp = GLookup($2->varname);
            current_function_type = fdeclaration_type;
            if(Gtemp == NULL) {
                fprintf(stderr,"Function %s not declared", $2->varname);
                yyerror("");
                exit(1);
            }
            if(Gtemp->type != fdeclaration_type) {
                fprintf(stderr,"%s : Function type does not match declaration", $2->varname);
                yyerror("");
                exit(1);
            }
            argList1 = Phead;
            argList2 = Gtemp->paramlist;

            while(argList1 != NULL && argList2 != NULL) {
                if(argList1->type != argList2->type) {
                    fprintf(stderr,"%s : Conflict in argument types", $2->varname);
                    yyerror("");
                    exit(1);
                }

                if(strcmp(argList1->name, argList2->name)) {
                    fprintf(stderr,"%s : Conflict in argument names", $2->varname);
                    yyerror("");
                    exit(1);
                }

                argList1 = argList1->next;
                argList2 = argList2->next;
            }

            if ((argList1 != NULL) || (argList2 != NULL)) {
                yyerror("Not enough arguments");
                exit(1);
            }
             struct tnode *funcTree =
        createTree(
            fdeclaration_type,   // return type
            NULL,
            FUN_DEF_NODE,        // function node
            $2->varname,         // function name
            NULL,
            $8,                  // body AST
            NULL,
            NULL
        );
        printf("\n===== FUNCTION AST: %s =====\n", $2->varname);
        print(funcTree);
        printf("\n--- LOCAL SYMBOL TABLE (%s) ---\n", $2->varname);
        printLSymbolTable();
        fprintf(out, "F%d:\n",Gtemp->flabel);
        fprintf(out, "PUSH BP\n");
        fprintf(out, "MOV BP,SP\n");

        Ltemp = Lhead;
        while(Ltemp != NULL) {
            if(Ltemp->binding > 0)
                fprintf(out, "PUSH R0\n");
            Ltemp = Ltemp->next;
        }

        codegen($8);
            Phead = NULL;
            Ptail = NULL;
            Lhead = NULL;
            Ltail = NULL;
        
        }
    ;
ParamList : ParamList COMMA Param
        | Param
        |    /*can be empty*/
        ;
Param : Ftype ID {
                    checkAvailability($2->varname, 0);
                    PInstall($2->varname, fdeclaration_type);
                }
    ;
LDeclBlock : DECL LDeclList ENDDECL {InstallParamsInLocal();}
            | DECL ENDDECL {InstallParamsInLocal();}
            | {InstallParamsInLocal();}
            ;
LDeclList : LDeclList LDecl
            | LDecl
            ;
LDecl : Type IdList SEMI
    ;
IdList : IdList COMMA ID
    | ID {
                    checkAvailability($1->varname, 0);
                    LInstall($1->varname, declaration_type);
                }
    ;

MainBlock : T_INT MAIN LPAREN RPAREN LBRACE LDeclBlock Body RBRACE {

    if(defCount != declCount) {
        yyerror("All functions declared need to be defined\n");
        exit(1);
    }

    // if(declaration_type != INT) {
    //     yyerror("Main return type should be of integer type\n");
    //     exit(1);
    // }
    current_function_type = INT;
    struct tnode *mainTree =
        createTree(
            INT,
            NULL,
            FUN_DEF_NODE,
            "main",
            NULL,
            $7,
            NULL,
            NULL
        );

    printf("\n===== FUNCTION AST: main =====\n");
    print(mainTree);

    $$ = mainTree;

    printLSymbolTable();
    fprintf(out, "MAIN:\n");
    fprintf(out, "PUSH BP\n");
    fprintf(out, "MOV BP,SP\n");

    Ltemp = Lhead;
    while (Ltemp != NULL)
    {
        fprintf(out, "PUSH R0\n");
        Ltemp = Ltemp->next;
    }

    codegen($7);
    Lhead = NULL;
    Ltail = NULL;
    }

Body : KW_BEGIN Slist RetStmt END {$$ = createTree(NONE, NULL,CONNECTOR_NODE, NULL, NULL, $2, $3, NULL);}
    | KW_BEGIN RetStmt END {$$ = $2;}
    ;
RetStmt: RETURN expr SEMI    {
                                if(current_function_type == $2->type) {
                                    $$ = createTree(NONE, NULL,RET_NODE, NULL, NULL, $2, NULL, NULL);
                                } else {
                                    yyerror("Return type mismatch");
                                    exit(1);
                                }
                            }
       ;

Slist : Slist Stmt {$$ = createTree(NONE, NULL,CONNECTOR_NODE, NULL, NULL, $1, $2, NULL);}
    | Stmt {$$=$1;}
    
    ;
Stmt : InputStmt  {$$ = $1;}  
    | OutputStmt {$$ = $1;}   
    | AsgStmt  {$$ = $1;} 
    | IfStmt  {$$ = $1;}  
    | WhileStmt {$$ = $1;}
    | BrkStmt   {$$ = $1;}
    | ContStmt  {$$ = $1;}
    | repeatUntilStmt {$$ = $1;}
    | doWhileStmt {$$ = $1;}
    | func SEMI {$$ = $1;}
    ;
//statements
InputStmt : READ LPAREN id RPAREN SEMI {
    $$ = createTree(NONE, NULL,READ_NODE, NULL, NULL, $3,NULL, NULL);
}
            ;
OutputStmt : WRITE LPAREN expr RPAREN SEMI {
            $$ = createTree(NONE, NULL,WRITE_NODE, NULL, NULL, $3, NULL, NULL);
            
}
            ;
AsgStmt : id ASSIGN expr SEMI  {
            typecheck($1->type, $3->type, '=');
            $$ = createTree(NONE, NULL,ASSIGN_NODE, NULL, NULL, $1, $3, NULL);
        }
        ;
IfStmt:  IF LPAREN expr RPAREN THEN Slist ELSE Slist ENDIF SEMI {
        typecheck($3->type, BOOL, 'e');
        $$ = createTree(NONE, NULL,IF_ELSE_NODE, NULL, NULL, $3, $8, $6);
}
    | IF LPAREN expr RPAREN THEN Slist ENDIF SEMI {
        typecheck($3->type, BOOL, 'i');
        $$ = createTree(NONE, NULL,IF_NODE, NULL, NULL, $3, $6,NULL);
}
    ;
WhileStmt: WHILE LPAREN expr RPAREN DO Slist ENDWHILE SEMI {
        typecheck($3->type,BOOL, 'w');
        $$ = createTree(NONE, NULL,WHILE_NODE, NULL, NULL, $3, $6, NULL);
}
        ;
BrkStmt: BREAK SEMI  {
    $$ = createTree(NONE, NULL,BREAK_NODE, NULL, NULL, NULL, NULL, NULL);
}
        ;
ContStmt: CONT SEMI {
    $$ = createTree(NONE, NULL,CONT_NODE, NULL, NULL, NULL, NULL, NULL);
}
        ;
repeatUntilStmt: REPEAT Slist UNTIL LPAREN expr RPAREN SEMI
    ;
doWhileStmt: DO Slist WHILE LPAREN expr RPAREN SEMI
    ;
//expressions
expr : expr PLUS expr {
        typecheck($1->type, $3->type, 'a');
        $$ = createTree(INT,NULL, ADD_NODE, NULL, NULL, $1, $3, NULL);
}
    | expr MINUS expr{
        typecheck($1->type, $3->type, 'a');
        $$ = createTree(INT,NULL, SUB_NODE, NULL, NULL, $1, $3, NULL);
}
    | expr MUL expr{
        typecheck($1->type, $3->type, 'a');
        $$ = createTree(INT,NULL, MUL_NODE, NULL, NULL, $1, $3, NULL);
}
    | expr DIV expr{
        typecheck($1->type, $3->type, 'a');
        $$ = createTree(INT,NULL, DIV_NODE, NULL, NULL, $1, $3, NULL);
}
    | expr LT expr {
        typecheck($1->type, $3->type, 'b');
        $$ = createTree(BOOL,NULL, LT_NODE, NULL, NULL, $1, $3, NULL);
}
    | expr LE expr{
        typecheck($1->type, $3->type, 'b');
        $$ = createTree(BOOL,NULL, LE_NODE, NULL, NULL, $1, $3, NULL);
}
    | expr GE expr{
        typecheck($1->type, $3->type, 'b');
        $$ = createTree(BOOL,NULL, GE_NODE, NULL, NULL, $1, $3, NULL);
}
    | expr GT expr{
        typecheck($1->type, $3->type, 'b');
        $$ = createTree(BOOL,NULL, GT_NODE, NULL, NULL, $1, $3, NULL);
}
    | expr NE expr{
        typecheck($1->type, $3->type, 'b');
        $$ = createTree(BOOL,NULL, NE_NODE, NULL, NULL, $1, $3, NULL);
}
    | expr EQ expr{
        typecheck($1->type, $3->type, 'b');
        $$ = createTree(BOOL,NULL, EQ_NODE, NULL, NULL, $1, $3, NULL);
}
    | expr MOD expr{
        typecheck($1->type, $3->type, 'a');
        $$ = createTree(INT,NULL, MOD_NODE, NULL, NULL, $1, $3, NULL);
}
    | LPAREN expr RPAREN {$$ = $2;}
    | MINUS NUM {
        $2->value.intval=-1*($2->value.intval);
        $$ = $2;}
    | NUM {$$ = $1;}
    | STRVAL {$$ = $1;}
    | id {$$ = $1;}
    | func {$$ = $1;}
    ;
id : ID {
        assignType($1,0);
        $$=$1;
    }
    | ID LBRACK NUM RBRACK {
        assignType($1,2);
        $$=createTree($1->type,NULL,ARRAY_NODE,NULL,NULL,$1,$3,NULL);
    }
    | ID LBRACK id RBRACK {
        assignType($1,2);
        $$=createTree($1->type,NULL,ARRAY_NODE,NULL,NULL,$1,$3,NULL);
    }
    ;
func : ID LPAREN ExprList RPAREN {
    assignType($1,1);
    $1->nodetype=FUN_NODE;
    $1->argList=$3;
    struct Gsymbol *g=GLookup($1->varname);
    if(g == NULL) {
        fprintf(stderr, "Function %s not declared\n", $1->varname);
        yyerror("");
        exit(1);
    }
    checkFunctionArgs(g,g->paramlist, $1->argList);
    $$=$1;
}
    ;
// ArgList : ArgList COMMA expr {
//         $3->argList=$1;
//         $$=$3;
// }
//     | expr {$$=$1;}
//     | {$$=NULL;}/*can have empty???*/
//     ;
ExprList: ExprList COMMA expr {
                                $$ = createTree(
                                    NONE,
                                    NULL,
                                    CONNECTOR_NODE,
                                    NULL,
                                    NULL,
                                    $1,
                                    $3,
                                    NULL
                                );
                            }
        | expr              {$$ = $1;}
        |                   {$$ = NULL;}
        ;







%%
void initSymbolTables(void) {
    Ghead = Gtail = NULL;
    Lhead = Ltail = NULL;
    Phead = Ptail = NULL;

    declaration_type = 0;
    fdeclaration_type = 0;
    start = 4096;
    localbindingstart = 1;
    flabelcount = 0;
    declCount = 0;
    defCount = 0;
}
void yyerror(char const *msg) {
    printf("[Error] : %s\n", msg);
    fprintf(stderr,
        "Syntax error at line %d near '%s'\n",
        yylineno, yytext);
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

    initSymbolTables();
    yyin = source_file;
    return yyparse();
}