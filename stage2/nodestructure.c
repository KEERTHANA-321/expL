#include <stdlib.h>
#include "nodestructure.h"


struct tnode* makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeIdNode(char * n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->left = l;
    temp->right = r;
    return temp;
}




// void prefix(struct tnode* root){
//     if(root!=NULL){
//         if(root->flag){
//             printf("%c ",*(root->op));
//         }
//         else
//         printf("%d ",root->val);
//         prefix(root->left);
//         prefix(root->right);
//     }
// }
// void postfix(struct tnode* root){
//     if(root!=NULL){
//         postfix(root->left);
//         postfix(root->right);
//         if(root->flag){
//             printf("%c ",*(root->op));
//         }
//         else
//         printf("%d ",root->val);
        
//     }
// }