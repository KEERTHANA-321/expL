#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

extern int declaration_type;
struct Gsymbol{
    char * name;
    int type;
    int size;
    int binding; //store static memory address allocated to the variable
    struct Gsymbol * next;
};
struct Gsymbol *lookup(char * name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
int install(char *name, int type, int size); // Creates a symbol table entry. 
struct Gsymbol * createNewGsymbolTableEntry(char * name,int type,int size);
void printSymbolTable();

#endif