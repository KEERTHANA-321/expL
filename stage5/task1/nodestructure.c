#include <stdlib.h>
#include "nodestructure.h"
#include "constants.h"
#include <string.h>
#include <stdio.h>


struct tnode* createTree(int type, union Constant *value, int nodetype, char* name, struct tnode * argList,struct tnode *l, struct tnode *r,struct tnode* mid) {
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    if(value != NULL) 
        temp->value = *value;
    temp->type = type;
    temp->nodetype = nodetype;
    if (name != NULL) {
        temp->varname = (char *)malloc(strlen(name)+1);
        strcpy(temp->varname, name);
    }
    temp->argList=argList;
    temp->left = l;
    temp->right = r;
    temp->middle=mid;
    return temp;
}
struct tnode* reverseList(struct tnode* head) {
    struct tnode *prev = NULL, *current;

    while(head != NULL) {
        current = head->argList;
        head->argList = prev;
        prev = head;
        head = current;
    }

    return prev;
}



void printNode(struct tnode *node) {
    switch (node->nodetype) {
        case FUN_DEF_NODE:
                printf("FUNCTION %s\n", node->varname);
                break;
        case CONNECTOR_NODE:
            printf("CONNECTOR\n");
            break;
        case FUN_NODE:
            printf("CALL %s\n", node->varname);
            break;
        case ARGS_NODE: //not an actual node
            printf("ARGS\n");
            break;
        case RET_NODE:
            printf("RETURN\n");
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
            printf("%d\n", node->value.intval);
            break;

        case VARIABLE_NODE:
            printf("%s\n", node->varname);
            break;
        case STRVAL_NODE:
            printf("%s\n",node->varname);
            break;
        case ARRAY_NODE:
            printf("ARRAY\n");
            break;
        // case TWOD_ARRAY_NODE:
        //     printf("2D-ARRAY\n");
        //     break;

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

        }
}
void print(struct tnode *root) {
    printf("[Printing AST]\n");
    print_tree(root, "", 1);
    printf("\n");
}


void printArgs(struct tnode *arg, char *prefix, int isLast) {
    if (!arg) return;

    /* Multiple arguments */
    if (arg->nodetype == CONNECTOR_NODE) {
        /* Left = one argument */
        printArgs(arg->left, prefix, 0);

        /* Right = remaining arguments */
        printArgs(arg->right, prefix, isLast);
    }
    else {
        /* Single argument expression */
        print_tree(arg, prefix, isLast);
    }
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

    if (root->nodetype == FUN_NODE && root->argList != NULL) {
        printf("%s└── ARGS\n", newPrefix);

        char argPrefix[1024];
        strcpy(argPrefix, newPrefix);
        strcat(argPrefix, "    ");

        printArgs(root->argList, argPrefix, 1);
        return;
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
