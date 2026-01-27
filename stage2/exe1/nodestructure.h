#ifndef NODESTRUCTURE_H
#define NODESTRUCTURE_H

typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*right;	//left and right branches   
}tnode;

/*Create a node tnode*/
struct tnode* createTree(int type, int val, int nodetype, char* name, struct tnode *l, struct tnode *r);// struct tnode* createNode();
// struct tnode* makeNumNode(int val,int type);
// struct tnode* makeIdNode(char * c,int type);
// struct tnode* makeArithopNode(char c,struct tnode *l,struct tnode *r);
// struct tnode* makeAssignNode(struct tnode* l,struct tnode* r);
// struct tnode* makeConnectorNode(struct tnode* l,struct tnode* r);
// struct tnode* makeReadNode(struct tnode* n);
// struct tnode* makeWriteNode(struct tnode* );

#endif