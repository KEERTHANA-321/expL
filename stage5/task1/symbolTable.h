#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

extern int declaration_type;
extern int fdeclaration_type;

extern int start;
extern int localbindingstart;
extern int flabelcount;


struct Paramstruct {
    char *name;
    int type;
    struct Paramstruct *next;
};

struct Gsymbol{
    char * name;
    int type;
    int size;
    int binding; //store static memory address allocated to the variable
    struct Paramstruct *paramlist;//pointer to the head of the formal parameter list in the case of functions
    int flabel; //a label for identifying the starting address of a function's code
    struct Gsymbol * next;
};


 struct Lsymbol{
    char *name; //name of the variable
    int type; //type of the variable:(Integer / String)
    int binding;//local binding of the variable
    struct Lsymbol *next;//points to the next Local Symbol Table entry
}; 

extern struct Gsymbol *Ghead, *Gtail;
struct Gsymbol *GLookup(char * name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
void GInstall(char *name, int type, int size,struct Paramstruct *paramlist); // Creates a symbol table entry. 
struct Gsymbol * createNewGsymbolTableEntry(char * name,int type,int size);
void printSymbolTable();


struct Lsymbol* LLookup(char *name);
void LInstall(char* name, int type);
extern struct Lsymbol *Lhead, *Ltail;


struct Paramstruct* PLookup(char *name);
void PInstall(char* name, int type);
extern struct Paramstruct *Phead, *Ptail;

void printLSymbolTable(); // FOR TESTING
void printGSymbolTable(); // FOR TESTING
void printParamList(struct Paramstruct *p) ;
void InstallParamsInLocal() ;
void initSymbolTables(void);

#endif