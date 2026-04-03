#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "nodestructure.h"
#include "symbolTable.h"
#include "typecheck.h"
#include "typetable.h"

 

void yyerror(const char *msg); 
void typecheck(struct Typetable *t1, struct Typetable *t2, char c) {
    switch(c) {
        case 'w': if(strcmp(t1->name,t2->name)!=0) {
                      yyerror("Expected Boolean in WHILE check\n");
                      exit(1);
                  }
                  break;
        case 'e': if(strcmp(t1->name,t2->name)!=0) {
                      yyerror("Expected Boolean in IF ELSE check\n");
                      exit(1); 
                  }
                  break;
        case 'i': if(strcmp(t1->name,t2->name)!=0) {
                      yyerror("Expected Boolean in IF check\n");
                      exit(1);
                  }
                  break;
        case 'a': if(t1 != TLookup("int") || t2 != TLookup("int")) {
                      yyerror("Invalid type for arithmetic operation\n");
                      exit(1);
                  }
                  break;
        case 'b': if(t1 != TLookup("int") || t2 != TLookup("int")) {
                      yyerror("Invalid type for comparing (<, >, <=..) operation\n");
                      exit(1);
                  }
                  break;
        case '=':

            // rhs is ALLOC
            if(t2 == NULL) {
                if(t1 == TLookup("int") || t1 == TLookup("str")) {
                    yyerror("Cannot assign alloc() to int/str\n");
                    exit(1);
                }
                return;
            }

            // rhs is NILL
            if(t2 == TLookup("void")) {   
                if(t1 == TLookup("int") || t1 == TLookup("str")) {
                    yyerror("Cannot assign NULL to int/str\n");
                    exit(1);
                }
                return;
            }
            if(strcmp(t1->name,t2->name)!=0) {
                printf("%s %s\n", t1->name, t2->name);
                yyerror("Type mismatch in assignment\n");
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

// void checkFunctionArgs(struct Gsymbol *func, struct Paramstruct *param, struct tnode *argList) {
//     struct tnode *arg = argList;
//     if(!param && !arg) return;
//     if (!param || !arg) {
//         fprintf(stderr,
//             "Argument count mismatch in function call %s\n",
//             func->name);
//         exit(1);
//     }

//     if(arg->nodetype==CONNECTOR_NODE){
//         checkFunctionArgs(func,param,arg->left);
//         struct Paramstruct *p = param;
//         struct tnode *left = argList->left;
//         while (left != NULL && left->nodetype == CONNECTOR_NODE) {
//             p = p->next;
//             left = left->left;
//         }
//         p = p->next; 
//         checkFunctionArgs(func,p,arg->right);
//         return;
//     }
//     else{
//         printf("Param: %s, Arg: %s\n", param->type->name, argList->type->name);
//         if(strcmp(param->type->name,arg->type->name)!=0){
//             fprintf(stderr,
//             "Argument type mismatch in function call %s\n",
//             func->name);
//         exit(1);
//         }
//     }
// }


int countArgs(struct tnode *argList) {
    if (argList == NULL) return 0;
    if (argList->nodetype != CONNECTOR_NODE) return 1;
    return countArgs(argList->left) + countArgs(argList->right);
}

// Flatten args into array (fills right-to-left due to tree shape)
int flattenArgs(struct tnode *argList, struct tnode **arr, int idx) {
    if (argList == NULL) return idx;
    if (argList->nodetype != CONNECTOR_NODE) {
        arr[idx] = argList;
        return idx + 1;
    }
    idx = flattenArgs(argList->left, arr, idx);
    idx = flattenArgs(argList->right, arr, idx);
    return idx;
}

void checkFunctionArgs(struct Gsymbol *func, struct Paramstruct *param, struct tnode *argList) {
    struct tnode *args[64];
    int n = flattenArgs(argList, args, 0);

    struct Paramstruct *p = param;
    int i = 0;
    while (p != NULL && i < n) {
        printf("Param: %s, Arg: %s\n", p->type->name, args[i]->type->name);
        if (strcmp(p->type->name, args[i]->type->name) != 0) {
            fprintf(stderr, "Argument type mismatch in function call %s\n", func->name);
            exit(1);
        }
        p = p->next;
        i++;
    }
    if (p != NULL || i < n) {
        fprintf(stderr, "Argument count mismatch in function call %s\n", func->name);
        exit(1);
    }
}
void assignTypeField(struct tnode* node, struct Fieldlist *fields) {
    struct Fieldlist *temp = FLookup(node->varname, fields);
    if(temp == NULL) {
        fprintf(stderr,"No member field named '%s'", node->varname);
        exit(1);
    }
    node->type = temp->type;
}
   

    
