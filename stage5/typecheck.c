#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "nodestructure.h"
#include "symbolTable.h"
#include "typecheck.h"

 

void yyerror(const char *msg); 
void typecheck(int t1, int t2, char c) {
    switch(c) {
        case 'w': if(t1 != t2) {
                      yyerror("Expected Boolean in WHILE check\n");
                      exit(1);
                  }
                  break;
        case 'e': if(t1 != t2) {
                      yyerror("Expected Boolean in IF ELSE check\n");
                      exit(1); 
                  }
                  break;
        case 'i': if(t1 != t2) {
                      yyerror("Expected Boolean in IF check\n");
                      exit(1);
                  }
                  break;
        case 'a': if(t1 != INT || t2 != INT) {
                      yyerror("Invalid type for arithmetic operation\n");
                      exit(1);
                  }
                  break;
        case 'b': if(t1 != INT || t2 != INT) {
                      yyerror("Invalid type for comparing (<, >, <=..) operation\n");
                      exit(1);
                  }
                  break;
        case '=': if(t1 != t2) {
                      yyerror("Invalid type for assignment operation\n");
                      exit(1);
                  }
                  break;
    }
}

int checkAvailability(char *name, int global) {
    if(global) {
        Gtemp = GLookup(name);
        if(Gtemp != NULL) {
            fprintf(stderr, "Re-initialization of variable/function '%s'\n", name);
            yyerror("");
            exit(1);
        }
    } else {
        Ltemp = LLookup(name);
        Ptemp = PLookup(name);
        if(Ptemp != NULL || Ltemp != NULL) {
           fprintf(stderr, "Re-initialization of variable/function '%s'\n", name);
            yyerror("");
            exit(1);
        }
    }

    return 1;
}



void assignType(struct tnode* node, int code) {
    // Code 0 - Local or Global Variable
    // Code 1 - Function
    // Code 2 - Array
    
    Ltemp = LLookup(node->varname);
    if(Ltemp != NULL && code == 0) { //local variable
        node->Lentry = Ltemp;
        node->type =Ltemp->type;
    } else {  
        Gtemp = GLookup(node->varname);
        if(Gtemp != NULL) { //global variable
            node->Gentry = Gtemp;
            node->type = Gtemp->type;

            if(code == 1 && Gtemp->size != -1) {  //function size is given as -1
                fprintf(stderr,"conflict in ID NodeType : Expected Function %s\n", node->varname);
                yyerror("");
                exit(1);
            }
        } else {
            if(code == 1){
                fprintf(stderr, "Function '%s' not declared!", node->varname);
                yyerror("");
                exit(1);
            }
            else{
                fprintf(stderr, "Variable '%s' not declared!", node->varname);
                yyerror("");
                exit(1);
            }
        }
    }

    return;
}

void checkFunctionArgs(struct Gsymbol *func, struct Paramstruct *param, struct tnode *argList) {
    struct tnode *arg = argList;
    if(!param && !arg) return;
    if (!param || !arg) {
        fprintf(stderr,
            "Argument count mismatch in function call %s\n",
            func->name);
        exit(1);
    }
    if(arg->nodetype==CONNECTOR_NODE){
        checkFunctionArgs(func,param,arg->left);
        checkFunctionArgs(func,param->next,arg->right);
    }
    else{
        if(param->type!=arg->type){
            fprintf(stderr,
            "Argument type mismatch in function call %s\n",
            func->name);
        exit(1);
        }
    }
}
   

    
