#include <stdlib.h>
#include "tree.h"


tnode * makeLeafNode(int n){
    tnode * node=(tnode*)malloc(sizeof(tnode));
    node->val=n;
    node->op=NULL;
    node->left=NULL;
    node->right=NULL;
    return node;
}

tnode * makeOperatorNode(char op,tnode * l,tnode * r){
    tnode * node=(tnode *)malloc(sizeof(tnode));
    node->op=op;
    node->left=l;
    node->right=r;
    return node;
}