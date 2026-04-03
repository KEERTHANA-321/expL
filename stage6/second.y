%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbolTable.h"
    #include "constants.h"
    #include "nodestructure.h"
    #include "typecheck.h"
    #include "typetable.h"
    int yylex(void);
    void yyerror(char const *msg);
    extern FILE *yyin;
    FILE *out;
    extern int yylineno;
    extern char *yytext;
    struct Paramstruct *argList1, *argList2;
    int declCount = 0, defCount = 0;
    struct Typetable * current_function_type = NULL;
    struct Typetable * saved_decl_type=NULL;
    int testing=1;
%}
%union {
    struct tnode *node;
}
%token PLUS MINUS MUL DIV MOD LT GT LE GE NE EQ  ASSIGN DOT
%token DO IF ELSE WHILE BREAK CONT KW_BEGIN END ENDIF THEN ENDWHILE REPEAT UNTIL TYPE ENDTYPE  FREE  INIT
%token <node> NUM STRVAL ID READ WRITE
%token DECL ENDDECL T_INT T_STR COMMA MAIN SEMI RETURN 
%token <node> EQNILL NEQNILL ALLOC NILL
%token LBRACE RBRACE LBRACK RBRACK LPAREN RPAREN KW_BRKP


%type <node> Program MainBlock FDefBlock FDef Body RetStmt
%type <node> Slist Stmt InputStmt OutputStmt AsgStmt IfStmt WhileStmt BrkStmt ContStmt BrkpStmt
%type <node> expr id ExprList
%type <node> TypeDefBlock TypeDefList TypeDef UserDefinedType 
%type <node> FieldDeclList FieldDecl Field

%right ASSIGN
%nonassoc LT GT LE GE EQ NE
%left PLUS MINUS
%left MUL DIV MOD

%%
Program : TypeDefBlock GDeclBlock FDefBlock MainBlock {
        printGSymbolTable();
        printTypeTable();
        $$ = $4;
        fclose(out);
        }
        | TypeDefBlock GDeclBlock MainBlock {
        printGSymbolTable();
        printTypeTable();
        $$ = $3;
        fclose(out);
        }
        | MainBlock {fclose(out);}
        ;

//type defiitions
TypeDefBlock: TYPE TypeDefList ENDTYPE
            | TYPE ENDTYPE
            |
            ;
TypeDefList: TypeDefList TypeDef
           | TypeDef
           ;
TypeDef: UserDefinedType LBRACE FieldDeclList RBRACE  { TInstall($1->varname, Fhead); }
       ;
UserDefinedType: ID {
                tempTNode = $1;
                $$ = $1;
                }
                ;
FieldDeclList: FieldDeclList FieldDecl
             | FieldDecl
             ;
FieldDecl: FieldType ID SEMI {
        if(FLookup($2->varname, Fhead) != NULL) {
            fprintf(stderr,"Re-declaration of Field element %s\n", $2->varname);
            yyerror("");
            exit(1);
        }
        FInstall($2->varname, declaration_type);
        }
        ;
FieldType : T_INT {declaration_type=TLookup("int");}
          | T_STR {declaration_type=TLookup("str");}
          | ID {
                declaration_type=TLookup($1->varname); 
                if(declaration_type == NULL) {
                    if(strcmp(tempTNode->varname, $1->varname) == 0) {
                        declaration_type = TLookup(tempTNode->varname);
                    } else {
                        
                        fprintf(stderr,"Undefined type %s", $1->varname);
                        exit(1);
                    }
                }
          } 
          ;

//globald eclarations
GDeclBlock : DECL GDeclList ENDDECL  {initialize(); }
            | DECL ENDDECL {initialize(); }
            ;
GDeclList : GDeclList GDecl 
            | GDecl
            ;
GDecl : Type GidList SEMI
    ;
Type : T_INT  {declaration_type = TLookup("int");}
    | T_STR  {declaration_type = TLookup("str");}
    | ID {
        declaration_type = TLookup($1->varname);
        if(declaration_type == NULL) {
            fprintf(stderr,"Unknown user-defined type %s\n", $1->varname);
            exit(1);
            }
    }
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
    | ID LPAREN {
        saved_decl_type = declaration_type;  
        }
    ParamList RPAREN {
        declCount++;
        checkAvailability($1->varname,1);
        GInstall($1->varname,saved_decl_type,-1,Phead);
        Phead=NULL;
        Ptail=NULL;
    }
    ;

//function definitions
FDefBlock : FDefBlock FDef
        | FDef
        ;
FDef : Ftype ID LPAREN ParamList RPAREN {
           current_function_type = fdeclaration_type;
        }
        LBRACE LDeclBlock Body RBRACE {
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
            
             struct tnode *funcTree =createTree(current_function_type,NULL,FUN_DEF_NODE,$2->varname,NULL,$9,NULL,NULL);
            // printf("\nFUNCTION AST: %s\n", $2->varname);
            // print(funcTree);
            printf("\nLOCAL SYMBOL TABLE (%s)\n", $2->varname);
            printLSymbolTable();
            fprintf(out, "F%d:\n",Gtemp->flabel);
            fprintf(out, "PUSH BP\n");
            fprintf(out, "MOV BP,SP\n");
            printf("value: %d\n", localbindingstart);
            fprintf(out, "ADD SP, %d\n", localbindingstart - 1);
            codegen($9);
            Phead = NULL;
            Ptail = NULL;
            Lhead = NULL;
            Ltail = NULL;
            localbindingstart = 1;
        }
        ;
ParamList : ParamList COMMA Param
        | Param
        |    //can be empty
        ;
Param : Type ID {
            checkAvailability($2->varname, 0);
            PInstall($2->varname, declaration_type);
        }
        ;

//local declrations
LDeclBlock : DECL LDeclList ENDDECL {InstallParamsInLocal();}
            | DECL ENDDECL {InstallParamsInLocal();}
            | {InstallParamsInLocal();}
            ;
LDeclList : LDeclList LDecl
            | LDecl
            ;
LDecl   : Type IdList SEMI
        ;
IdList : IdList COMMA ID {
            checkAvailability($3->varname, 0);
            LInstall($3->varname, declaration_type);
            localbindingstart++;
        }
        | ID {
            checkAvailability($1->varname, 0);
            LInstall($1->varname, declaration_type);
            localbindingstart++;
        }
        ;

//main function
MainBlock : T_INT MAIN LPAREN RPAREN LBRACE LDeclBlock Body RBRACE {
            if(defCount != declCount) {
                yyerror("All functions declared need to be defined\n");
                exit(1);
            }
            current_function_type = TLookup("int");
            struct tnode *mainTree =
            createTree(TLookup("int"),NULL,FUN_DEF_NODE,"main",NULL,$7,NULL,NULL);
            // printf("\nFUNCTION AST: main\n");
            // print(mainTree);
            $$ = mainTree;
            printLSymbolTable();
            fprintf(out, "MAIN:\n");
            fprintf(out, "PUSH BP\n");
            fprintf(out, "MOV BP,SP\n");
            printf("here: %d\n", localbindingstart);
            fprintf(out, "ADD SP, %d\n", localbindingstart - 1);
            codegen($7);
            Lhead = NULL;
            Ltail = NULL;
            localbindingstart = 1;
         };
Body : KW_BEGIN Slist RetStmt END {$$ = createTree(TLookup("void"), NULL,CONNECTOR_NODE, NULL, NULL, $2, $3, NULL);}
    | KW_BEGIN RetStmt END {$$ = $2;}
    ;

//statements
Slist : Slist Stmt {$$ = createTree(TLookup("void"), NULL,CONNECTOR_NODE, NULL, NULL, $1, $2, NULL);}
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
    | RetStmt {$$=$1;}
    | BrkpStmt
    | ID LPAREN ExprList RPAREN SEMI {  //function call statement
        assignType($1,1);
        $1->nodetype = FUN_NODE;
        $1->argList = $3;
        struct Gsymbol *g = GLookup($1->varname);
        if(g == NULL) {
            fprintf(stderr, "Function %s not declared\n", $1->varname);
            exit(1);
        }
        $1->type = g->type; 
        checkFunctionArgs(g, g->paramlist, $1->argList);
        $$ = $1;
    }
    | FREE LPAREN ID RPAREN SEMI { //free statement
        assignType($3,0);
        if($3->type == TLookup("int") || $3->type == TLookup("str")) {
            yyerror("Cannot FREE a string or int variable\n");
            exit(1);
        }
        $$ = createTree(TLookup("void"),NULL, FREE_NODE, NULL, NULL, $3, NULL, NULL);
    }
     | FREE LPAREN Field RPAREN SEMI  {
        if($3->type == TLookup("int") || $3->type == TLookup("str")) {
            yyerror("Cannot FREE a string or integer variable\n");
            exit(1);
        }
        $$ = createTree(TLookup("void"),NULL, FREE_NODE, NULL, NULL, $3, NULL, NULL);
     }
     | INIT LPAREN RPAREN SEMI { //initalize statement
        $$ = createTree(TLookup("void"),NULL, INIT_NODE, NULL, NULL, NULL, NULL, NULL);
    }
    ;


//assignment statement
AsgStmt : id ASSIGN expr SEMI  {
            typecheck($1->type, $3->type, '=');
            $$ = createTree(TLookup("void"), NULL,ASSIGN_NODE, NULL, NULL, $1, $3, NULL);
        }
        | Field ASSIGN expr SEMI {
            typecheck($1->type, $3->type, '=');
            $$ = createTree(TLookup("void"), NULL,ASSIGN_NODE, NULL, NULL, $1, $3, NULL);

        }
        ;

//conditional statement
IfStmt:  IF LPAREN expr RPAREN THEN Slist ELSE Slist ENDIF SEMI {
        typecheck($3->type, TLookup("bool"), 'e');
        $$ = createTree(TLookup("void"), NULL,IF_ELSE_NODE, NULL, NULL, $3, $8, $6);
    }
    | IF LPAREN expr RPAREN THEN Slist ENDIF SEMI {
        typecheck($3->type, TLookup("bool"), 'i');
        $$ = createTree(TLookup("void"), NULL,IF_NODE, NULL, NULL, $3, $6,NULL);
    }
    ;

//iterative statement
WhileStmt: WHILE LPAREN expr RPAREN DO Slist ENDWHILE SEMI {
        typecheck($3->type,TLookup("bool"), 'w');
        $$ = createTree(TLookup("void"), NULL,WHILE_NODE, NULL, NULL, $3, $6, NULL);
    }
    ;

//return statmnt
RetStmt: RETURN expr SEMI{
        // printf("curre %s , expr %s\n",current_function_type->name, $2->type->name);
        if(strcmp(current_function_type->name,$2->type->name)==0) {
            $$ = createTree(TLookup("void"), NULL,RET_NODE, NULL, NULL, $2, NULL, NULL);
        } else {
            yyerror("Return type mismatch");
            exit(1);
        }
        }
       ;

//input and output
InputStmt : READ LPAREN id RPAREN SEMI {
    $$ = createTree(TLookup("void"), NULL,READ_NODE, NULL, NULL, $3,NULL, NULL);
    }
            ;
OutputStmt : WRITE LPAREN expr RPAREN SEMI {
            $$ = createTree(TLookup("void"), NULL,WRITE_NODE, NULL, NULL, $3, NULL, NULL);
            
    }

//brk and continue
BrkStmt: BREAK SEMI  {
    $$ = createTree(TLookup("void"), NULL,BREAK_NODE, NULL, NULL, NULL, NULL, NULL);
    }
        ;
ContStmt: CONT SEMI {
    $$ = createTree(TLookup("void"), NULL,CONT_NODE, NULL, NULL, NULL, NULL, NULL);
    }
        ;
BrkpStmt:KW_BRKP SEMI {
    $$ = createTree(TLookup("void"), NULL, BRKP_NODE, NULL, NULL, NULL, NULL, NULL);
    }
        ;
//expressions
expr : expr PLUS expr {   //arithmetic expressions
        typecheck($1->type, $3->type, 'a');
        $$ = createTree(TLookup("int"),NULL, ADD_NODE, NULL, NULL, $1, $3, NULL);   
    }
    | expr MINUS expr{
        typecheck($1->type, $3->type, 'a');
        $$ = createTree(TLookup("int"),NULL, SUB_NODE, NULL, NULL, $1, $3, NULL);
    }
    | expr MUL expr{
        typecheck($1->type, $3->type, 'a');
        $$ = createTree(TLookup("int"),NULL, MUL_NODE, NULL, NULL, $1, $3, NULL);
    }
    | expr DIV expr{
        typecheck($1->type, $3->type, 'a');
        $$ = createTree(TLookup("int"),NULL, DIV_NODE, NULL, NULL, $1, $3, NULL);
    }
    | expr MOD expr{
        typecheck($1->type, $3->type, 'a');
        $$ = createTree(TLookup("int"),NULL, MOD_NODE, NULL, NULL, $1, $3, NULL);
    }
    | expr LT expr {  //logical expresiions
        typecheck($1->type, $3->type, 'b');
        $$ = createTree(TLookup("bool"),NULL, LT_NODE, NULL, NULL, $1, $3, NULL);
    }
    | expr LE expr{
        typecheck($1->type, $3->type, 'b');
        $$ = createTree(TLookup("bool"),NULL, LE_NODE, NULL, NULL, $1, $3, NULL);
    }
    | expr GE expr{
        typecheck($1->type, $3->type, 'b');
        $$ = createTree(TLookup("bool"),NULL, GE_NODE, NULL, NULL, $1, $3, NULL);
    }
    | expr GT expr{
        typecheck($1->type, $3->type, 'b');
        $$ = createTree(TLookup("bool"),NULL, GT_NODE, NULL, NULL, $1, $3, NULL);
    }
    | expr NE expr{
        typecheck($1->type, $3->type, 'b');
        $$ = createTree(TLookup("bool"),NULL, NE_NODE, NULL, NULL, $1, $3, NULL);
    }
    | expr EQ expr{
        typecheck($1->type, $3->type, 'b');
        $$ = createTree(TLookup("bool"),NULL, EQ_NODE, NULL, NULL, $1, $3, NULL);
    }
    
    | Field EQNILL    {
                            typecheck($1->type, NULL, '!');
                            $$ = createTree(TLookup("bool"),NULL, EQ_NODE,  NULL, NULL, $1, $2, NULL);
                        }
     | Field NEQNILL    {
                            typecheck($1->type, NULL, '!');
                            $$ = createTree(TLookup("bool"),NULL, NE_NODE, NULL, NULL, $1, $2, NULL);
                        }
     | ID EQNILL       {
                            assignType($1, 0);
                            $$ = createTree(TLookup("bool"),NULL, EQ,  NULL, NULL, $1, $2, NULL);
                        }
     | ID NEQNILL       {
                            assignType($1, 0);
                            $$ = createTree(TLookup("bool"),NULL, NE_NODE, NULL, NULL, $1, $2, NULL);
                        }
    | LPAREN expr RPAREN {$$ = $2;}
    | MINUS NUM {
        $2->value.intval=-1*($2->value.intval);
        $$ = $2;
        $$->type=TLookup("int");
        }
    | NUM {
        $$ = $1;
        $$->type=TLookup("int");
        }
    | STRVAL {
        $$ = $1;
        $$->type=TLookup("str");
        }
    | id {$$ = $1;}
    | Field {$$ = $1;}
    | ALLOC LPAREN RPAREN {
        $$ = $1; 
        $$->type = TLookup("void");  
    }
    | NILL{
        $$=createTree(TLookup("void"),NULL,NULL_NODE,NULL,NULL,NULL,NULL,NULL);
    }
    | INIT LPAREN RPAREN        
    {$$ = createTree(TLookup("int"),NULL, INIT_NODE, NULL, NULL, NULL, NULL, NULL);}  
    ;

%%
void initSymbolTables(void) {
    Ghead = Gtail = NULL;
    Lhead = Ltail = NULL;
    Phead = Ptail = NULL;

    declaration_type = NULL;
    fdeclaration_type = NULL;
    start = 4096;
    // printf("initialized: 1\n");
    localbindingstart = 1;
    flabelcount = 0;
    declCount = 0;
    defCount = 0;
}
void yyerror(char const *msg) {
    fprintf(stderr,
        "Syntax error at line %d near '%s' with msg: %s\n",
        yylineno, yytext, msg);
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
    TypeTableCreate();
    initSymbolTables();
    yyin = source_file;
    return yyparse();
}