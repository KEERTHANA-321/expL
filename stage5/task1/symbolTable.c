#include "symbolTable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//defintiions

int declaration_type;
int fdeclaration_type;
int start=4096;
int localbindingstart=1;
int flabelcount=0;

struct Gsymbol* Gtemp,*Ghead,*Gtail;
struct Lsymbol* Ltemp,*Lhead,*Ltail;
struct Paramstruct* Ptemp,*Phead,*Ptail;

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

struct Gsymbol * GLookup(char *name){
    struct Gsymbol *curr = Ghead;
    while(curr != NULL){
        if(strcmp(curr->name, name) == 0){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

struct Lsymbol* LLookup(char *name) {
    struct Lsymbol *temp = Lhead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        temp = temp->next;
    }

    return temp;
}

struct Paramstruct* PLookup(char *name) {
    struct Paramstruct *temp = Phead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        temp = temp->next;
    }

    return temp;
}

void GInstall(char *name, int type, int size, struct Paramstruct *paramlist) {
    struct Gsymbol* temp;
    temp = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
    temp->name = malloc(strlen(name)+1);
    strcpy(temp->name, name);
    temp->type = type;
    temp->size = size;
    temp->next = NULL;

    if(paramlist != NULL)
        temp->paramlist = paramlist;

    if(size != -1) {
        temp->binding = start;
        start = start + temp->size;
    } else {
        temp->flabel = flabelcount;
        flabelcount++;
    }

    if (Ghead != NULL) {
        Gtail->next = temp;
        Gtail = temp;
    } else {
        Ghead = temp;
        Gtail = temp;
    }

    return;
}

void LInstall(char *name,int type){
    struct Lsymbol * temp=(struct Lsymbol*)malloc(sizeof(struct Lsymbol));
    temp->name=name;
    temp->type=type;
    temp->binding=localbindingstart;
    localbindingstart++;
    temp->next=NULL;
    if(Lhead!=NULL){
        Ltail->next=temp;
        Ltail=temp;
    }
    else{
        Lhead=temp;
        Ltail=temp;
    }
}


void PInstall(char *name, int type) {
    struct Paramstruct *temp;
    temp = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
    temp->name = malloc(strlen(name) + 1);
    strcpy(temp->name, name);
    temp->type = type;
    temp->next=NULL;

    if (Phead != NULL) {
        Ptail->next = temp;
        Ptail = temp;
    } else {
        Phead = temp;
        Ptail = temp;
    }

    return;
}


void InstallParamsInLocal() {
    struct Paramstruct *temp = Phead;
    int count = 0;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    localbindingstart = -1*count - 2;
    temp = Phead;
    while(temp != NULL) {
        LInstall(temp->name, temp->type);
        temp = temp->next;
    }

    localbindingstart = 1;
    return;
}


void printGSymbolTable() {
    struct Gsymbol* temp = Ghead;

    printf("\n=== GLOBAL SYMBOL TABLE ===\n");

    while (temp != NULL) {

        if (temp->size == -1) {
            /* Function */
            printf("Function  : %s  ReturnType=%d  Label=%d  Params=",
                   temp->name, temp->type, temp->flabel);

            printParamList(temp->paramlist);
            printf("\n");

        } else {
            /* Variable / Array */
            printf("Variable  : %s  Type=%d  Size=%d  Binding=%d\n",
                   temp->name, temp->type, temp->size, temp->binding);
        }

        temp = temp->next;
    }
}

void printLSymbolTable() {
    struct Lsymbol* temp = Lhead;
    printf("\nLocal Variables:\n");
    while (temp != NULL) {
        printf("%s --- %d --- %d\n", temp->name, temp->type, temp->binding);
        temp = temp->next;
    }
}

void printParamList(struct Paramstruct *p) {
    printf("(");
    while (p != NULL) {
        printf("%s:%d", p->name, p->type);
        if (p->next != NULL)
            printf(", ");
        p = p->next;
    }
    printf(")");
}