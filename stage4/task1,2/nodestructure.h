#ifndef NODESTRUCTURE_H
#define NODESTRUCTURE_H

typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct Gsymbol *Gentry;
	struct tnode *left,*right,*middle;	//left and right branches   
}tnode;

/*Create a node tnode*/
struct tnode* createTree(int type, int val, int nodetype, char* name, struct tnode *l, struct tnode *r, struct tnode *mid);// struct tnode* createNode();
// struct tnode* makeNumNode(int val,int type);
// struct tnode* makeIdNode(char * c,int type);
// struct tnode* makeArithopNode(char c,struct tnode *l,struct tnode *r);
// struct tnode* makeAssignNode(struct tnode* l,struct tnode* r);
// struct tnode* makeConnectorNode(struct tnode* l,struct tnode* r);
// struct tnode* makeReadNode(struct tnode* n);
// struct tnode* makeWriteNode(struct tnode* );
void printNode(struct tnode *node);
void print_helper(struct tnode *root);
void print(struct tnode *root);
void typecheck(int t1, int t2, char c);
void print_tree(struct tnode *root, char *prefix, int isLast);

int codegen(struct tnode* root);

#endif