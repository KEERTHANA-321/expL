
#include <stdlib.h>
#include <stdio.h>
#include "constants.h"
#include "nodestructure.h"

extern FILE * out;

int regno=-1,maxreg=20;
int i,j,counter=-1;


void freeReg(){
    if(regno>=0){
        regno--;
    }
}
int getReg(){
    if(regno==maxreg-1){
        printf("Out of registers\n");
        freeReg();
        return getReg();
    }
    else{
        regno++;
        return regno;
    }
}
void generateExitCode() {
    int reg = getReg();
    fprintf(out,"BRKP\n");
    fprintf(out, "MOV R%d, \"Exit\"\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "CALL 0\n");

    freeReg();
}
void initialize(){
    out=fopen("result.xsm","w");
    fprintf(out, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(out, "ADD SP, 26\n");
    fprintf(out,"BRKP\n");
}
int codegen(struct tnode* root){
    int r1,r2,r3,number,status=0;

    if(root==NULL){
        return -1;
    }
    else if(root->nodetype==CONNECTOR_NODE){
        codegen(root->left);
        codegen(root->right);
    }
    switch(root->nodetype){
        case NUM_NODE:{
            r1=getReg();
            fprintf(out,"MOV R%d,%d\n",r1,root->val);
            return r1;
        }
        case VARIABLE_NODE:{
            r1=getReg();
            number=4096+root->varname[0]-'a';
            fprintf(out,"MOV R%d,[%d]\n",r1,number);
            return r1;
        }
        case ADD_NODE:{
            r1 = codegen(root->left);
            r2 = codegen(root->right);
            fprintf(out,"ADD R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        }
        case SUB_NODE:{
            r1 = codegen(root->left);
            r2 = codegen(root->right);
            fprintf(out,"SUB R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        }
        case DIV_NODE:{
            r1 = codegen(root->left);
            r2 = codegen(root->right);
            fprintf(out,"DIV R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        }
        case MUL_NODE:{
            r1 = codegen(root->left);
            r2 = codegen(root->right);
            fprintf(out,"MUL R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        }
        case ASSIGN_NODE:{
            r1=codegen(root->right);
            number = 4096 + root->left->varname[0] - 'a';
            fprintf(out,"MOV [%d],R%d\n",number,r1);
            freeReg();
            return r1;
        }
        case WRITE_NODE:{
            for (i = 0; i <= counter; i++)
                fprintf(out, "PUSH R%d\n", i);
            status = counter;

            fprintf(out, "MOV R0,\"Write\"\n");
            fprintf(out, "PUSH R0\n"); // function code "Write"
            fprintf(out, "MOV R0,-2\n");
            fprintf(out, "PUSH R0\n"); //Argument 1

            r1 = codegen(root->left);
            fprintf(out, "PUSH R%d\n", r1); //Argument 2
            freeReg();
            fprintf(out, "ADD SP,2\n");
            fprintf(out, "CALL 0\n");
            fprintf(out, "SUB SP,5\n");

            for (i = status; i >= 0; i--)
                fprintf(out, "POP R%d\n", i);
            counter = status;
            break;
        }
        case READ_NODE:{
            number = 4096 + root->left->varname[0] - 'a';
            for (i = 0; i <= counter; i++)
                fprintf(out, "PUSH R%d\n", i);
            status = counter;

            fprintf(out, "MOV R0,\"Read\"\n");
            fprintf(out, "PUSH R0\n"); // function code "Write"
            fprintf(out, "MOV R0,-1\n");
            fprintf(out, "PUSH R0\n"); //Argument 1
            fprintf(out, "MOV R0,%d\n", number);
            fprintf(out, "PUSH R0\n"); //Argument 1
            fprintf(out, "ADD SP,2\n");
            fprintf(out, "CALL 0\n");
            fprintf(out, "SUB SP,5\n");

            for (i = status; i >= 0; i--)
                fprintf(out, "POP R%d\n", i);
            counter = status;
            break;
        }
    }

}