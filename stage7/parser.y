%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbolTable.h"
    #include "constants.h"
    #include "nodestructure.h"
    #include "typecheck.h"
    #include "typetable.h"
    #include "classtable.h"
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
%token LBRACE RBRACE LBRACK RBRACK LPAREN RPAREN KW_BRKP CLASS ENDCLASS DELETE 
%token <node>  SELF NEW


%type <node> Program MainBlock FDefBlock FDef Body RetStmt
%type <node> Slist Stmt InputStmt OutputStmt AsgStmt IfStmt WhileStmt BrkStmt ContStmt repeatUntilStmt doWhileStmt
%type <node> expr id ExprList
%type <node> TypeDefBlock TypeDefList TypeDef UserDefinedType 
%type <node> FieldDeclList FieldDecl Field FieldFunction
%type <node> ClassDefBlock ClassType 

%right ASSIGN
%nonassoc LT GT LE GE EQ NE
%left PLUS MINUS
%left MUL DIV MOD

%%
Program : TypeDefBlock ClassDefBlock GDeclBlock FDefBlock MainBlock 
        {
            printGSymbolTable();
            printTypeTable();
            printClassTable();
                $$ = $4;
            fclose(out);
        }
        | TypeDefBlock ClassDefBlock GDeclBlock MainBlock
        {
          printGSymbolTable();
            printTypeTable();
            printClassTable();
          $$ = $4;
          fclose(out);
      }
        | MainBlock {fclose(out);}
        ;
TypeDefBlock: TYPE TypeDefList ENDTYPE { $$ = NULL; initialize(); }
            | TYPE ENDTYPE { $$ = NULL;initialize(); }
            | { $$ = NULL;initialize(); }
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
//class declarations
ClassDefBlock: CLASS ClassDefList ENDCLASS  { $$ = NULL; }
             | { $$ = NULL; }
             ;
ClassDefList: ClassDefList ClassDef
            | ClassDef
            ;
ClassDef: Cname LBRACE DECL ClassFieldDeclList ENDDECL ClassMethodDefns RBRACE {
            CCurrent = NULL;
            if(defCount != declCount) {
                yyerror("All functions declared in class need to be defined\n");
                exit(1);
            }
            declCount = 0;
            defCount = 0;
        }
        ;
Cname: ID {CCurrent = CInstall($1->varname, NULL);}
     ;
ClassFieldDeclList: ClassFieldDeclList ClassFieldDecl
              |
              ;
ClassFieldDecl: ClassType ID SEMI {
                checkAvailability($2->varname, 2);
                Class_Finstall(CCurrent, saved_decl_type, declarationCType, $2->varname);
                }
              | ClassType ID LPAREN ParamList RPAREN SEMI {
                declCount++;
                checkAvailability($2->varname, 2);
                Class_Minstall(CCurrent, $2->varname, saved_decl_type, Phead);
                Phead = NULL;
                Ptail = NULL;
                }
               ;
ClassType: T_INT  { declaration_type = TLookup("int"); saved_decl_type = declaration_type; }
         | T_STR  { declaration_type = TLookup("str"); saved_decl_type = declaration_type; }
         | ID     {
                    declaration_type = TLookup($1->varname);
                    declarationCType = CLookup($1->varname);
                    if(declaration_type == NULL && declarationCType == NULL) {
                        fprintf(stderr,"Unknown user-defined type/class %s\n", $1->varname);
                        exit(1);
                    }
                    saved_decl_type = declaration_type;
                  }
         ;
ClassMethodDefns: ClassMethodDefns FDef
                |
                ;

//global declarations

GDeclBlock : DECL GDeclList ENDDECL  //{initialize(); }
            | DECL ENDDECL //{initialize(); }
            ;
GDeclList : GDeclList GDecl 
            | GDecl
            ;
GDecl : Type GidList SEMI
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
Type : T_INT  {declaration_type = TLookup("int");}
    | T_STR  {declaration_type = TLookup("str");}
    | ID    {
                declaration_type = TLookup($1->varname);
                declarationCType = CLookup($1->varname);
                if(declaration_type == NULL && declarationCType == NULL) {
                    fprintf(stderr,"Unknown user-defined type/class %s\n", $1->varname);
                    exit(1);
                }
            }
    ;

Ftype :T_INT  {fdeclaration_type = TLookup("int");}
    | T_STR  {fdeclaration_type = TLookup("str");}
    | ID    {
                // printTypeTable();
                fdeclaration_type = TLookup($1->varname);
                declarationCType = CLookup($1->varname);
                // printf("type is set to %p %s %d\n", fdeclaration_type, $1->varname, yylineno);
                // printf("type is set to %s\n", fdeclaration_type->name);
                if(fdeclaration_type == NULL && declarationCType == NULL) {
                    fprintf(stderr,"Unknown user-defined type/class %s\n", $1->varname);
                    exit(1);
                }
            }

Field: ID DOT ID        {
                            assignType($1, 0);
                            assignTypeField($3, $1->type->fields);
                            $$ = createTree($3->type, NULL, FIELD_NODE, NULL, NULL, $1, $3, NULL);
                        }
     | Field DOT ID     {
                            $$ = insertFieldId($1, $3);
                        }
    | SELF DOT ID      {
                            if(CCurrent == NULL) {
                                yyerror("SELF cannot be used outside a class\n");
                                exit(1);
                            }
                            $1->Ctype = CCurrent;
                            $1->Lentry = LLookup("self");
                            $$ = insertFieldId($1, $3);
                        }
     ;

FieldFunction: SELF DOT ID LPAREN ExprList RPAREN {
                        if(CCurrent == NULL) {
                            yyerror("SELF cannot be used outside a class\n");
                            exit(1);
                        }
                        $1->Ctype = CCurrent;
                        $1->Lentry = LLookup("self");
                        $3->nodetype = FUN_NODE;
                        $3->argList = $5;
                        $$ = createTree(TLookup("void"),NULL, FIELDFUNC_NODE, NULL, NULL, $1, $3, NULL);
                        assignType($$, 3);
                    }
             | ID DOT ID LPAREN ExprList RPAREN {
                        assignType($1, 0);
                        if($1->Ctype == NULL) {
                            fprintf(stderr,"%s is not a class object\n", $1->varname);
                            yyerror("");
                            exit(1);
                        }
                        $3->nodetype = FUN_NODE;
                        $3->argList = $5;
                        $$ = createTree(TLookup("void"),NULL, FIELDFUNC_NODE, NULL, NULL, $1, $3, NULL);
                        assignType($$, 3);
                    }
             | Field DOT ID LPAREN ExprList RPAREN {
                        if($1->Ctype == NULL) {
                            yyerror("Memberfield is not a class object\n");
                            exit(1);
                        }
                        $3->nodetype = FUN_NODE;
                        $3->argList = $5;
                        $$ = createTree(TLookup("void"),NULL, FIELDFUNC_NODE, NULL, NULL, $1, $3, NULL);
                        assignType($$, 3);
                    }
             ;


GidList : GidList COMMA Gid
        | Gid
        ;
Gid : ID {
     checkAvailability($1->varname,1);   
     
     GInstall($1->varname,declaration_type,1,NULL,declarationCType);
}
    | ID LBRACK NUM RBRACK {
        checkAvailability($1->varname,1);   
        if($3->value.intval < 1) {
        yyerror("Invalid array size");
        exit(1);
    }
     GInstall($1->varname,declaration_type,$3->value.intval,NULL,declarationCType);
    }
    | ID LPAREN {
        saved_decl_type = declaration_type;  
    }
    ParamList RPAREN {
        declCount++;
        checkAvailability($1->varname,1);
        GInstall($1->varname,saved_decl_type,-1,Phead,declarationCType);
        Phead=NULL;
        Ptail=NULL;
    }
    ;

FDefBlock : FDefBlock FDef
        | FDef
        ;
FDef : Ftype ID LPAREN ParamList RPAREN {
           /* mid-rule action: set return type BEFORE parsing body */
           current_function_type = fdeclaration_type;
       }LBRACE LDeclBlock Body RBRACE  /*ftype because inside there will be other types and tree*/
        {
            // localbindingstart = 1;
            defCount++;
            if(CCurrent == NULL) {
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
                
                
                argList2 = Gtemp->paramlist;
            }else {
                Mtemp = Class_Mlookup(CCurrent, $2->varname);
                current_function_type = fdeclaration_type;

                if(Mtemp == NULL) {
                    fprintf(stderr,"Function %s not declared in class", $2->varname);
                    yyerror("");
                    exit(1);
                }

                if(strcmp(Mtemp->Type->name,fdeclaration_type->name)!=0) {
                    printf("function type %s defclaration type %s\n", fdeclaration_type->name, Mtemp->Type->name);
                    fprintf(stderr,"%s : Function type does not match declaration", $2->varname);
                    yyerror("");
                    exit(1);
                }

                argList2 = Mtemp->paramlist;
            }
            argList1 = Phead;

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
            current_function_type,   // return type
            NULL,
            FUN_DEF_NODE,        // function node
            $2->varname,         // function name
            NULL,
            $9,                  // body AST
            NULL,
            NULL
        );
        printf("\nFUNCTION AST: %s\n", $2->varname);
        print(funcTree);
        printf("\nLOCAL SYMBOL TABLE (%s)\n", $2->varname);
        printLSymbolTable();
        if (CCurrent == NULL) {
            fprintf(out, "F%d:\n", Gtemp->flabel);
        } else {
            fprintf(out, "M%d:\n", Mtemp->Flabel);
        }
        fprintf(out, "PUSH BP\n");
        fprintf(out, "MOV BP,SP\n");
        // printf("value: %d\n", localbindingstart);
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
        |    /*can be empty*/
        ;
Param : Type ID {
    struct Typetable *ptype = declaration_type;
    // printf("Installing param %s of type %s\n", 
        //    $2->varname, ptype->name); 
                    checkAvailability($2->varname, 0);
                    PInstall($2->varname, ptype);
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

MainBlock : T_INT MAIN LPAREN RPAREN 
{
    current_function_type = TLookup("int");   // 🔥 FIX HERE
}LBRACE LDeclBlock Body RBRACE {

    if(defCount != declCount) {
        yyerror("All functions declared need to be defined\n");
        exit(1);
    }

    current_function_type = TLookup("int");
    struct tnode *mainTree =
        createTree(
            TLookup("int"),
            NULL,
            FUN_DEF_NODE,
            "main",
            NULL,
            $8,
            NULL,
            NULL
        );

    printf("\nFUNCTION AST: main\n");
    print(mainTree);

    $$ = mainTree;

    printLSymbolTable();
    fprintf(out, "MAIN:\n");
    fprintf(out, "PUSH BP\n");
    fprintf(out, "MOV BP,SP\n");
    printf("here: %d\n", localbindingstart);
    fprintf(out, "ADD SP, %d\n", localbindingstart - 1);
 
    codegen($8);
    Lhead = NULL;
    Ltail = NULL;
    localbindingstart = 1;

    }

Body : KW_BEGIN Slist RetStmt END {$$ = createTree(TLookup("void"), NULL,CONNECTOR_NODE, NULL, NULL, $2, $3, NULL);}
    | KW_BEGIN RetStmt END {$$ = $2;}
    ;
RetStmt: RETURN expr SEMI    {
     if($2->type == NULL) {
        printf("ERROR: NULL type in return\n");
        exit(1);
    }

                                // printf("curre %p , expr %p\n",current_function_type, $2->type);
                                // printf("curre %s , expr %s\n",current_function_type->name, $2->type->name);
                                if(strcmp(current_function_type->name,$2->type->name)==0) {
                                    $$ = createTree(TLookup("void"), NULL,RET_NODE, NULL, NULL, $2, NULL, NULL);
                                } else {
                                    yyerror("Return type mismatch");
                                    exit(1);
                                }
                            }
       ;

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
    |RetStmt {$$=$1;}
    | ID LPAREN ExprList RPAREN SEMI {
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
    | KW_BRKP SEMI      { $$ = createTree(TLookup("void"), NULL, BRKP_NODE, NULL, NULL, NULL, NULL, NULL); }
    | FREE LPAREN ID RPAREN SEMI {
        assignType($3,0);
        if($3->type == TLookup("int") || $3->type == TLookup("str")) {
            yyerror("Cannot FREE a string or int variable\n");
            exit(1);
        }
        $$ = createTree(TLookup("void"),NULL, FREE_NODE, NULL, NULL, $3, NULL, NULL);
    }
     | FREE LPAREN Field RPAREN SEMI    {
                                    if($3->type == TLookup("int") || $3->type == TLookup("str")) {
                                        yyerror("Cannot FREE a string or integer variable\n");
                                        exit(1);
                                    }
                                    $$ = createTree(TLookup("void"),NULL, FREE_NODE, NULL, NULL, $3, NULL, NULL);
     }
     | INIT LPAREN RPAREN SEMI        {$$ = createTree(TLookup("void"),NULL, INIT_NODE, NULL, NULL, NULL, NULL, NULL);}
     | DELETE LPAREN ID RPAREN SEMI     {
                                    assignType($3, 0);
                                    if($3->Ctype == NULL) {
                                        yyerror("Cannot DELETE a non class variable\n");
                                        exit(1);
                                    }
                                    $$ = createTree(TLookup("void"), NULL,DELETE_NODE, NULL, NULL, $3, NULL, NULL);
                                }
    | DELETE LPAREN Field RPAREN SEMI  {
                                    if($3->Ctype == NULL) {
                                        yyerror("Cannot DELETE a non class variable\n");
                                        exit(1);
                                    }
                                    $$ = createTree(TLookup("void"),NULL, DELETE_NODE, NULL, NULL, $3, NULL, NULL);
                                }
    ;
//statements
InputStmt : READ LPAREN id RPAREN SEMI {
    $$ = createTree(TLookup("void"), NULL,READ_NODE, NULL, NULL, $3,NULL, NULL);
}
            ;
OutputStmt : WRITE LPAREN expr RPAREN SEMI {
            $$ = createTree(TLookup("void"), NULL,WRITE_NODE, NULL, NULL, $3, NULL, NULL);
            
}
            ;
AsgStmt : id ASSIGN expr SEMI  {
            if ($3->nodetype == ALLOC_NODE) {
                $3->type = $1->type;
            }   
             if ($3->nodetype == NEW_NODE) {
        if ($1->Ctype != $3->Ctype) {
            yyerror("Type mismatch in new() assignment\n");
            exit(1);
        }
    } else {
        typecheck($1->type, $3->type, '=');
    }
            $$ = createTree(TLookup("void"), NULL,ASSIGN_NODE, NULL, NULL, $1, $3, NULL);
        }
       | Field ASSIGN expr SEMI           {
         if ($3->nodetype == ALLOC_NODE) {
            $3->type = $1->type;
        }
         if ($3->nodetype == NEW_NODE) {
        if ($1->Ctype != $3->Ctype) {
            yyerror("Type mismatch in new() assignment\n");
            exit(1);
        }
    } else {
        typecheck($1->type, $3->type, '=');
    }
        $$ = createTree(TLookup("void"), NULL,ASSIGN_NODE, NULL, NULL, $1, $3, NULL);
                    
        }
        
       ;
IfStmt:  IF LPAREN expr RPAREN THEN Slist ELSE Slist ENDIF SEMI {
        typecheck($3->type, TLookup("bool"), 'e');
        $$ = createTree(TLookup("void"), NULL,IF_ELSE_NODE, NULL, NULL, $3, $8, $6);
}
    | IF LPAREN expr RPAREN THEN Slist ENDIF SEMI {
        typecheck($3->type, TLookup("bool"), 'i');
        $$ = createTree(TLookup("void"), NULL,IF_NODE, NULL, NULL, $3, $6,NULL);
}
    ;
WhileStmt: WHILE LPAREN expr RPAREN DO Slist ENDWHILE SEMI {
        typecheck($3->type,TLookup("bool"), 'w');
        $$ = createTree(TLookup("void"), NULL,WHILE_NODE, NULL, NULL, $3, $6, NULL);
}
        ;
BrkStmt: BREAK SEMI  {
    $$ = createTree(TLookup("void"), NULL,BREAK_NODE, NULL, NULL, NULL, NULL, NULL);
}
        ;
ContStmt: CONT SEMI {
    $$ = createTree(TLookup("void"), NULL,CONT_NODE, NULL, NULL, NULL, NULL, NULL);
}
        ;
repeatUntilStmt: REPEAT Slist UNTIL LPAREN expr RPAREN SEMI {
    typecheck($5->type, TLookup("bool"), 'r');
    $$ = createTree(TLookup("void"), NULL, REPEAT_NODE, NULL, NULL, $2, $5, NULL);
}
    ;
doWhileStmt: DO Slist WHILE LPAREN expr RPAREN SEMI {
    typecheck($5->type, TLookup("bool"), 'd');
    $$ = createTree(TLookup("void"), NULL, DOWHILE_NODE, NULL, NULL, $2, $5, NULL);
}
    ;
//expressions
expr : expr PLUS expr {
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
    | expr LT expr {
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
    | expr MOD expr{
        typecheck($1->type, $3->type, 'a');
        $$ = createTree(TLookup("int"),NULL, MOD_NODE, NULL, NULL, $1, $3, NULL);
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
                            $$ = createTree(TLookup("bool"),NULL, EQ_NODE,  NULL, NULL, $1, $2, NULL);
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
    | FieldFunction    {$$ = $1;}
    | NEW LPAREN ID RPAREN {
           struct Classtable *c = CLookup($3->varname);
           if (c == NULL) {
               fprintf(stderr, "Unknown class '%s' in new()\n", $3->varname);
               yyerror(""); exit(1);
           }
           $1->Ctype = c;
           $1->type=TLookup("void");
           $$ = $1;
       }
    ;
id : ID {
        if(CLookup($1->varname) != NULL) {
            $$=$1;
        }
        else {assignType($1,0);
        $$=$1;}
    }
    | ID LBRACK expr RBRACK {
        assignType($1,2);
        $$=createTree($1->type,NULL,ARRAY_NODE,NULL,NULL,$1,$3,NULL);
    }
    | ID LPAREN ExprList RPAREN {
    assignType($1,1);
    $1->nodetype=FUN_NODE;
    $1->argList=$3;
    struct Gsymbol *g=GLookup($1->varname);
    if(g == NULL) {
        fprintf(stderr, "Function %s not declared\n", $1->varname);
        yyerror("");
        exit(1);
    }
    $1->type=g->type;
    // printf("function %s type %s\n",$1->varname,g->type->name);
    
    checkFunctionArgs(g,g->paramlist, $1->argList);
    $$=$1;
    // printf("function call type %s %s\n",$1->type->name,$1->varname);
}
    ;
 
  
ExprList: ExprList COMMA expr {
                                $$ = createTree(
                                    TLookup("void"),
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