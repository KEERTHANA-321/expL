#include "typetable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct Typetable *Thead,*Ttemp,*Ttail;
struct Fieldlist *Fhead, *Ftail, *ftemp;

struct Typetable* TLookup(char *name){
    struct Typetable *temp = Thead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        temp = temp->next;
    }

    return temp;
}

int getSizefromFieldList(struct Fieldlist *fields) {
    int size = 0;
    struct Fieldlist *temp = fields;

    while (temp != NULL) {
        size ++;
        temp = temp->next;
    }

    return (size==0)?1:size;
}
void  TInstall(char *name,struct Fieldlist *fields){
    struct Typetable *temp = (struct Typetable*)malloc(sizeof(struct Typetable));
    temp->name = strdup(name);
    temp->size = getSizefromFieldList(fields);
    temp->fields = fields;
    temp->next = NULL;
    int counter = 0;

    if (Thead == NULL) {
        Thead = temp;
        Ttail = temp;
    } else {
        Ttail->next = temp;
        Ttail = temp;
    }
    ftemp = fields;
    while(ftemp != NULL) {
        if (ftemp->type == TLookup("dummy")) {
            ftemp->type = TLookup(name);
        }

        ftemp->fieldIndex = ++counter;
        ftemp = ftemp->next;
    }

    temp->fields = fields;
    temp->size = counter;

    if(counter >= 8) {
        fprintf(stderr,"Too many member fields", NULL);
        exit(1);
    }

    Fhead = NULL;
    Ftail = NULL;
    return;
}
void FInstall(char *name, struct Typetable *type) {
    struct Fieldlist *ftemp;
    ftemp = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));

    ftemp->name = strdup(name);
    strcpy(ftemp->name, name);
    ftemp->type = type;
    ftemp->next = NULL;

    if(Fhead == NULL) {
        Fhead = ftemp;
        Ftail = ftemp;
    } else {
        Ftail->next = ftemp;
        Ftail = ftemp;
    }

    return;
}

void TypeTableCreate(){
    TInstall("int", NULL);
    TInstall("str", NULL);
    TInstall("bool", NULL);
    TInstall("void", NULL);

}

struct Fieldlist *FLookup(char *name, struct Fieldlist *list) {
    while(list != NULL && strcmp(list->name, name) != 0) {
        list = list->next;
    }

    return list;
}


void printTypeTable() {
    printf("-----TYPE TABLE-----\n");
    struct Typetable *temp = Thead;
    struct Fieldlist *ftemp;
    while(temp != NULL) {
        printf("%s\t%d\n", temp->name, temp->size);
        ftemp = temp->fields;
        while(ftemp != NULL) {
            printf("\t%d\t%s\t%s\n", ftemp->fieldIndex, ftemp->name, ftemp->type->name);
            ftemp = ftemp->next;
        }
        temp = temp->next;
    }
    printf("\n");
}