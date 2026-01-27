#include "nodestructure.h"
#include "constants.h"
#include <stdio.h>
#define NUM_VARS 26

int variables[NUM_VARS];

int getVariableIndex(struct tnode *root){
    char name=root->varname[0];
    return (int)name-'a';
}

int evaluate(struct tnode *root){
    if(!root) return -1;
    int index,val;
    switch(root->nodetype){
        case CONNECTOR_NODE:
            evaluate(root->left);
            evaluate(root->right);
            return -1;
        case READ_NODE:
            index=getVariableIndex(root->left);
            printf("READ: ");
            scanf("%d",&variables[index]);
            return -1;
        case WRITE_NODE:
            val=evaluate(root->left);
            printf("WRITE:%d\n",val);
            return -1;
        case ASSIGN_NODE:
            val=evaluate(root->right);
            index=getVariableIndex(root->left);
            variables[index]=val;
            return -1;
        case VARIABLE_NODE:
            index = getVariableIndex(root);
            return variables[index];
        case NUM_NODE:
            return root->val;
        case ADD_NODE:
            int leftVal = evaluate(root->left);
            int rightVal = evaluate(root->right);
            return leftVal + rightVal;
        case SUB_NODE:
            leftVal = evaluate(root->left);
            rightVal = evaluate(root->right);
            return leftVal - rightVal;
        case MUL_NODE:
            leftVal = evaluate(root->left);
            rightVal = evaluate(root->right);
            return leftVal * rightVal;
        case DIV_NODE:
            leftVal = evaluate(root->left);
            rightVal = evaluate(root->right);
            return leftVal / rightVal;
        
        
    }
}
void evaluateAndPrint(struct tnode *root){
    for(int i=0;i<NUM_VARS;i++){
        variables[i]=0;
    }
    evaluate(root);
    for(int i=0;i<NUM_VARS;i++){
        printf("%c:%d\n",(char)(i+'a'),variables[i]);
    }
}
