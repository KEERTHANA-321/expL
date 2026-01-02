#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "constants.h"

/* Number node */
struct tnode* makeNumNode(int val) {
    struct tnode* t = malloc(sizeof(struct tnode));
    t->val = val;
    t->type = INT;
    t->varname = NULL;
    t->nodetype = NODE_NUM;
    t->left = t->right = NULL;
    return t;
}

/* Variable node */
struct tnode* makeVarNode(char* name) {
    struct tnode* t = malloc(sizeof(struct tnode));
    t->val = 0;
    // assign t->type during stage 4
    t->type = NONE;
    t->varname = strdup(name);
    t->nodetype = NODE_ID;
    t->left = t->right = NULL;
    return t;
}

/* Arithmetic node */
struct tnode* makeArithNode(int nodetype, struct tnode* l, struct tnode* r) {
    struct tnode* t = malloc(sizeof(struct tnode));
    t->val = 0;
    t->type = NONE;
    t->varname = NULL;
    t->nodetype = nodetype;
    t->left = l;
    t->right = r;
    return t;
}

/* Assignment node */
struct tnode* makeAssignNode(struct tnode* id, struct tnode* expr) {
    struct tnode* t = malloc(sizeof(struct tnode));
    struct tnode* tid = malloc(sizeof(struct tnode));
    t->val = 0;
    t->type = NONE;
    t->varname = strdup(id->varname);
    t->nodetype = NODE_ASSIGN;
    t->left = tid;
    t->right = expr;

    tid->val = expr->val;
    tid->type = INT;
    tid->varname = strdup(id->varname);
    tid->nodetype = NODE_ID;
    tid->left = NULL;
    tid->right = NULL;
    return t;
}

/* Read node */
struct tnode* makeReadNode(struct tnode* id) {
    struct tnode* t = malloc(sizeof(struct tnode));
    t->val = 0;
    t->type = NONE;
    t->varname = strdup(id->varname);
    t->nodetype = NODE_READ;
    t->left = id;
    t->right = NULL;
    return t;
}

/* Write node */
struct tnode* makeWriteNode(struct tnode* expr) {
    struct tnode* t = malloc(sizeof(struct tnode));
    t->val = 0;
    t->type = NONE;
    t->varname = NULL;
    t->nodetype = NODE_WRITE;
    t->left = expr;
    t->right = NULL;
    return t;
}

/* Connector node */
struct tnode* makeConnectorNode(struct tnode* l, struct tnode* r) {
    struct tnode* t = malloc(sizeof(struct tnode));
    t->val = 0;
    t->type = NONE;
    t->varname = NULL;
    t->nodetype = NODE_CONNECTOR;
    t->left = l;
    t->right = r;
    return t;
}


// Free the tree
void deleteTree(tnode *root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);

    // if (root->op) free(root->op); // free copied operator string
    free(root);
}
