#include <stdlib.h>
#include "exprtree.h"


struct tnode* makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    temp->flag=0;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    temp->flag=1;
    return temp;
}

int evaluate(struct tnode *t){
    if(t->op == NULL)
    {
        return t->val;
    }
    else{
        switch(*(t->op)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
    }
}

void print_helper(struct tnode *root) {
    if (root) {
        if (root->op) {
            printf("OP: %c\n", *(root->op));
        } else {
            printf("NUM: %d\n", root->val);
        }

        print_helper(root->left);
        print_helper(root->right);
    }
}
void print(struct tnode *root) {
    printf("[Printing Tree]\n");

    print_helper(root);
}

void prefix(struct tnode* root){
    if(root!=NULL){
        if(root->flag){
            printf("%c ",*(root->op));
        }
        else
        printf("%d ",root->val);
        prefix(root->left);
        prefix(root->right);
    }
}
void postfix(struct tnode* root){
    if(root!=NULL){
        postfix(root->left);
        postfix(root->right);
        if(root->flag){
            printf("%c ",*(root->op));
        }
        else
        printf("%d ",root->val);
        
    }
}