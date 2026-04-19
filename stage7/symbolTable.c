#include "symbolTable.h"
#include "typetable.h"
#include "classtable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//defintiions

struct Typetable * declaration_type;
struct Typetable * fdeclaration_type;
int start=4096;
int localbindingstart=1;
int flabelcount=0;
int pcount=0;

struct Gsymbol* Gtemp,*Ghead,*Gtail;
struct Lsymbol* Ltemp,*Lhead,*Ltail;
struct Paramstruct* Ptemp,*Phead,*Ptail;

struct Gsymbol * createNewGsymbolTableEntry(char * name,struct Typetable *type,int size) {
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

void GInstall(char *name, struct Typetable *type, int size, struct Paramstruct *paramlist, struct Classtable *ctype) {
    struct Gsymbol* temp;
    temp = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
    temp->name = malloc(strlen(name)+1);
    strcpy(temp->name, name);
    temp->type = type;
    // printf("gunction type %s name %s\n",temp->type->name,temp->name);
    temp->size = size;
    temp->next = NULL;
    temp->Ctype=ctype;

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

void LInstall(char *name,struct Typetable *type){
    struct Lsymbol * temp=(struct Lsymbol*)malloc(sizeof(struct Lsymbol));
    temp->name=name;
    temp->type=type;
    // printf("isntalling %s with %d\n", name, localbindingstart);
    temp->binding=localbindingstart;
    // localbindingstart++;
    // printf("updated: %d while installing %s\n", localbindingstart, name);
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


void PInstall(char *name, struct Typetable *type) {
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

struct Paramstruct* reverseParams(struct Paramstruct* head) {
    struct Paramstruct *prev = NULL, *current;

    while(head != NULL) {
        current = head->next;
        head->next= prev;
        prev = head;
        head = current;
    }

    return prev;
}

void installParam(char *name, struct Typetable *type) {
    struct Lsymbol * temp=(struct Lsymbol*)malloc(sizeof(struct Lsymbol));
    temp->name=name;
    temp->type=type;
    // printf("isntalling %s with %d\n", name, localbindingstart);
    temp->binding= -3 - pcount;
    // printf("updated: %d while installing %s\n", localbindingstart, name);
    temp->next=NULL;
    if(Lhead!=NULL){
        Ltail->next=temp;
        Ltail=temp;
    }
    else{
        Lhead=temp;
        Ltail=temp;
    }
    pcount++;
}

void InstallParamsInLocal() {
    pcount = 0;
    if (CCurrent != NULL) {
    installParam("self", TLookup("void"));  
}
    struct Paramstruct *temp = Phead;
    if (!temp) return;
    struct Paramstruct *t = Phead;
    // while (t) {
    //     printf("%s ", t->name);
    //     t = t ->next;
    // }
    // printf("\n");

    // printf("params called with: %d\n", localbindingstart);
   
    // printf("installing params to lst, %d", localbindingstart);
    // Phead = reverseParams(Phead);
    temp = Phead;

    while(temp != NULL) {
        installParam(temp->name, temp->type);
        temp = temp->next;
    }
    // Phead = reverseParams(Phead);
    // localbindingstart = copy;
    // printf("i was here with %d\n", localbindingstart);
    return;
}


void printGSymbolTable() {
    struct Gsymbol* temp = Ghead;

    printf("\nGLOBAL SYMBOL TABLE\n");

    while (temp != NULL) {

        if (temp->size == -1) {
            /* Function */
            printf("Function : %s  ReturnType=%s  Label=%d  Params=",
                   temp->name, (temp->type!=NULL?temp->type->name:"NULL"), temp->flabel);

            printParamList(temp->paramlist);
            printf("\n");

        } else {
            /* Variable / Array */
            printf("Variable  : %s  Size=%d  Binding=%d ",
                   temp->name, temp->size, temp->binding);
            if (temp->type != NULL)
                printf("Type=%s\n", temp->type->name);
            else if (temp->Ctype != NULL)
                printf("Type=%s (class)\n", temp->Ctype->name);
            else
                printf("Type=NULL\n");
        }

        temp = temp->next;
    }
}

void printLSymbolTable() {
    struct Lsymbol* temp = Lhead;
    printf("\nLocal Variables:\n");
    // printf("yess");
    while (temp != NULL) {
        printf("%s --- %s --- %d\n", temp->name, (temp->type ? temp->type->name : "NULL"), temp->binding);
        temp = temp->next;
    }
    // printf("yesss");
}

void printParamList(struct Paramstruct *p) {
    printf("(");
    while (p != NULL) {
        printf("%s:%s", p->name, p->type->name);
        if (p->next != NULL)
            printf(", ");
        p = p->next;
    }
    printf(")");
}