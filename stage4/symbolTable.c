#include "symbolTable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Gsymbol *s_head=NULL;
struct Gsymbol *s_tail=NULL;
int start=4096;
int declaration_type=0;

struct Gsymbol * createNewGsymbolTableEntry(char * name,int type,int size) {
    struct Gsymbol * new=(struct Gsymbol*)malloc(sizeof(struct  Gsymbol));
    new->type=type;
    new->size=size;
    new->binding=start;
    start+=size;
    new->name=name;
    new->next=NULL;
    return new;
}

struct Gsymbol * lookup(char *name){
    struct Gsymbol *curr = s_head;
    while(curr != NULL){
        if(strcmp(curr->name, name) == 0){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

int install(char *name, int type, int size){
    if(lookup(name) != NULL){
        printf("Variable Defined already\n");
        exit(1);
    }
    struct Gsymbol *newEntry = createNewGsymbolTableEntry(name,type,size);
    if(s_head == NULL){
        s_head = newEntry;
        s_tail = newEntry;
    } else {
        s_tail->next = newEntry;
        s_tail = newEntry;
    }
    // printf("Label added: %s -> %d\n", name, type,size);
    return 0;
}
void printSymbolTable() {
    struct Gsymbol* temp = s_head;
    while (temp != NULL) {
        printf("%s---%d---%d\n", temp->name, temp->type, temp->binding);
        temp = temp->next;
    }
}