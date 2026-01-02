#ifndef TREE_H
#define TREE_H

#include "constants.h"

// Tree node structure
typedef struct tnode {
    int val;
    enum varType type;
    char* varname;
    enum nodeType nodetype;
    struct tnode *left, *right;
} tnode;

#define YYSTYPE tnode*

struct tnode* makeNumNode(int val);
struct tnode* makeVarNode(char* name);
struct tnode* makeArithNode(int nodetype, struct tnode* l, struct tnode* r);
struct tnode* makeAssignNode(struct tnode* id, struct tnode* expr);
struct tnode* makeReadNode(struct tnode* id);
struct tnode* makeWriteNode(struct tnode* expr);
struct tnode* makeConnectorNode(struct tnode* l, struct tnode* r);
// Optional cleanup function
void deleteTree(tnode *root);

#endif // TREE_H
