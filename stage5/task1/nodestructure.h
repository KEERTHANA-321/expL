#ifndef NODESTRUCTURE_H
#define NODESTRUCTURE_H

union Constant{
    int intval;
    char* strval;
};

typedef struct tnode { 
	union Constant value;	// value of a constant
	int type;	//type of variable NUM or STR
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct Gsymbol *Gentry;
	struct Lsymbol *Lentry;
	struct tnode * argList; //argumentss given if it is a function
	struct tnode *left,*right,*middle;	//left and right branches   
}tnode;

/*Create a node tnode*/
struct tnode* createTree(int type, union Constant *value, int nodetype, char* name,struct tnode * argList, struct tnode *l, struct tnode *r, struct tnode *mid);// struct tnode* createNode();
void print(struct tnode *root);
void print_tree(struct tnode *root, char *prefix, int isLast);

//evaluating tree
struct tnode* reverseList(struct tnode* t);
int codegen(struct tnode* root);
void printArgs(struct tnode *arg, char *prefix, int isLast);

#endif