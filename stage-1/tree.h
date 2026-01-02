#ifndef TREE_H
#define TREE_H

// Tree node structure
typedef struct tnode {
    int val;            // value if leaf
    char *op;           // operator name if non-leaf
    struct tnode *left;
    struct tnode *right;
} tnode;

#define YYSTYPE tnode*

// Create a leaf node
tnode* makeLeafNode(int n);

// Create an operator node (with operator string and two children)
tnode* makeOperatorNode(char *op, tnode *l, tnode *r);

// Tree traversals
void inorderTraversal(tnode *root);
void preorderTraversal(tnode *root);
void postorderTraversal(tnode *root);

// Optional cleanup function
void deleteTree(tnode *root);

#endif // TREE_H
