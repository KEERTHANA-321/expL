#include <stdlib.h>
#include "nodestructure.h"
#include "constants.h"
#include <string.h>
#include <stdio.h>


struct tnode* createTree(int type, int val, int nodetype, char* name, struct tnode *l, struct tnode *r,struct tnode* mid) {
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
    temp->middle=mid;
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
        case BREAK_NODE:
            printf("BREAK\n");
            break;
        case CONT_NODE:
            printf("CONTINUE\n");
            break;
        case DOWHILE_NODE:
            printf("DOWHILE\n");
            break;
        case REPEAT_NODE:
            printf("REPEAT UNTIL\n");
            break;
        case NUM_NODE:
            printf("%d\n", node->val);
            break;

        case VARIABLE_NODE:
            printf("%s\n", node->varname);
            break;
        case STRVAL_NODE:
            printf("%s\n",node->varname);
            break;
        case ARRAY_NODE:
            printf("ARRAY\n");

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
        case MOD_NODE:
            printf("MOD\n");
            break;
        case IF_NODE:
            printf("IF\n");
            break;

        case IF_ELSE_NODE:
            printf("IF_ELSE\n");
            break;

        case WHILE_NODE:
            printf("WHILE\n");
            break;

        case LT_NODE:
            printf("<\n");
            break;

        case GT_NODE:
            printf(">\n");
            break;

        case LE_NODE:
            printf("<=\n");
            break;

        case GE_NODE:
            printf(">=\n");
            break;

        case EQ_NODE:
            printf("==\n");
            break;

        case NE_NODE:
            printf("!=\n");
            break;

        case ADDR_NODE:
            printf("ADDRESSING\n");
            break;
        case DEREF_NODE:
            printf("DEREFERENSING\n");
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
    print_helper(root->middle);
    print_helper(root->right);
    indent--;
}
void print(struct tnode *root) {
    printf("[Printing AST]\n");
    print_tree(root, "", 1);
    printf("\n");
}



void print_tree(struct tnode *root, char *prefix, int isLast) {
    if (!root) return;

    printf("%s", prefix);

    if (isLast) {
        printf("└── ");
    } else {
        printf("├── ");
    }

    printNode(root);

    char newPrefix[1024];
    strcpy(newPrefix, prefix);

    if (isLast) {
        strcat(newPrefix, "    ");
    } else {
        strcat(newPrefix, "│   ");
    }

    /* Collect children */
    struct tnode *children[3];
    int count = 0;

    if (root->left)   children[count++] = root->left;
    if (root->middle) children[count++] = root->middle;
    if (root->right)  children[count++] = root->right;

    for (int i = 0; i < count; i++) {
        print_tree(children[i], newPrefix, i == count - 1);
    }
}
