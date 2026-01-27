#include <stdlib.h>
#include "nodestructure.h"
#include "constants.h"
#include <string.h>


struct tnode* createTree(int type, int val, int nodetype, char* name, struct tnode *l, struct tnode *r) {
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    temp->nodetype = nodetype;
    if (name != NULL) {
        temp->varname = (char *)malloc(strlen(name)+1);
        strcpy(temp->varname, name);
    }
    temp->left = l;
    temp->right = r;
    return temp;
}



void printNode(struct tnode *node) {
    switch (node->nodetype) {
        case CONNECTOR_NODE:
            printf("CONNECTOR\n");
            break;

        case ASSIGN_NODE:
            printf("ASSIGN\n");
            break;

        case READ_NODE:
            printf("READ\n");
            break;

        case WRITE_NODE:
            printf("WRITE\n");
            break;

        case EMPTY_NODE:
            printf("EMPTY\n");
            break;

        case NUM_NODE:
            printf("%d\n", node->val);
            break;

        case VARIABLE_NODE:
            printf("%s\n", node->varname);
            break;

        case ADD_NODE:
            printf("+\n");
            break;

        case SUB_NODE:
            printf("-\n");
            break;

        case MUL_NODE:
            printf("*\n");
            break;

        case DIV_NODE:
            printf("/\n");
            break;
    }
}
void print_helper(struct tnode *root) {
    static int indent = 0;
    if (!root) return;

    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    printf("|-");
    printNode(root);
    indent++;

    print_helper(root->left);
    print_helper(root->right);
    indent--;
}
void print(struct tnode *root) {
    printf("[Printing AST]\n");
    print_helper(root);
    printf("\n");
}


void inorder_helper(struct tnode *root) {
    if (!root) return;

    inorder_helper(root->left);
    printNode(root);
    inorder_helper(root->right);
}

void print_inorder(struct tnode *root) {
    printf("[PRINTING IN INORDER]");
    inorder_helper(root);
    printf("\n");
}
