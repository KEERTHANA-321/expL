#include "classtable.h"
#include "constants.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "typetable.h"
#include "symbolTable.h"
void yyerror(const char *msg);

struct Classtable *Chead = NULL, *Ctail = NULL, *CCurrent = NULL;
struct Classtable *declarationCType = NULL;
int classFuncLabelCount = 0;
struct Classtable* CLookup(char *name) {
    struct Classtable *temp = Chead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        temp = temp->next;
    }
    return temp;
}



struct Memberfunclist* Class_Mlookup(struct Classtable* Ctype, char* name) {
    struct Memberfunclist *temp = Ctype->Vfuncptr; 

    while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        temp = temp->next;
    }
    return temp;
}

struct Fieldlist* Class_Flookup(struct Classtable* Ctype,char * name){
    struct Fieldlist *temp=Ctype->Memberfield;
    while(temp!=NULL && (strcmp(temp->name,name)!=0)){
        temp=temp->next;
    }
    return temp;
}

void Class_Minstall (struct Classtable *cptr, char *name, struct Typetable *type, struct Paramstruct *Paramlist){
    struct Memberfunclist *mtemp, * funcIter;
    mtemp=(struct Memberfunclist*)malloc(sizeof(struct Memberfunclist));
    mtemp->name = (char*)malloc(strlen(name) + 1);
    strcpy(mtemp->name, name);
    mtemp->Flabel = classFuncLabelCount++;
    mtemp->Type = type;
    mtemp->paramlist = Paramlist;
    mtemp->next = NULL;
    cptr->Methodcount++;
    if(cptr->Methodcount > 8) {
        yyerror("More than 8 methods not allowed\n");
        exit(1);
    }
    funcIter = cptr->Vfuncptr;
     if(funcIter == NULL) {
        mtemp->Funcposition = 0;
        cptr->Vfuncptr = mtemp;
    } else {
        while(funcIter->next != NULL) {
            funcIter = funcIter->next;
        }
        mtemp->Funcposition = funcIter->Funcposition + 1;
        funcIter->next = mtemp;
    }
    
    return;
}

void Class_Finstall(struct Classtable *cptr, struct Typetable *type, struct Classtable *Ctype, char *name) {
    struct Fieldlist *ftemp, *fieldIter;
    ftemp = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
    ftemp->name = (char*)malloc(strlen(name) + 1);
    strcpy(ftemp->name, name);
    ftemp->next = NULL;
    ftemp->Type = type;
    ftemp->Ctype = Ctype;
    cptr->Fieldcount++;
    if(cptr->Fieldcount > 8) {
        yyerror("More than 8 member fields\n");
        exit(1);
    }
    fieldIter = cptr->Memberfield;
    if(fieldIter == NULL) {
        ftemp->Fieldindex= 0;
        cptr->Memberfield = ftemp;
    } else {
        while(fieldIter->next != NULL) {
            fieldIter = fieldIter->next;
        }
        ftemp->Fieldindex= fieldIter->Fieldindex+ 1;
        fieldIter->next = ftemp;
    }

    return;

}
struct Classtable* CInstall(char *name, char *parent_class_name) {
    struct Typetable *Ttemp = TLookup(name);
    struct Classtable *Ctemp = CLookup(name);
    if(Ttemp != NULL || Ctemp != NULL) {
        fprintf(stderr,"Re-declaration of class OR UDT with same name exists: %s", name);
        yyerror("");
        exit(1);
    }

    Ctemp = (struct Classtable*)malloc(sizeof(struct Classtable));
    Ctemp->name = (char*)malloc(strlen(name) + 1);
    strcpy(Ctemp->name, name);
    Ctemp->Fieldcount = 0;
    Ctemp->Methodcount = 0;
    Ctemp->Memberfield = NULL;
    Ctemp->Vfuncptr = NULL;
    Ctemp->next = NULL;
    Ctemp->Parentptr = NULL;

    if(parent_class_name != NULL) {
        Ctemp->Parentptr = CLookup(parent_class_name);
        if(Ctemp->Parentptr == NULL) {
            fprintf(stderr,"Invalid parent class %s\n", parent_class_name);
            yyerror("");
            exit(1);
        }
    }

    if(Chead != NULL) {
        Ctemp->Class_index = Ctail->Class_index + 1;
        Ctail->next = Ctemp;
        Ctail = Ctemp;
    } else {
        Ctemp->Class_index = 0;
        Chead = Ctemp;
        Ctail = Ctemp;
    }

    return Ctemp;
}

void printClassTable() {
    struct Classtable *c = Chead;

    printf("\nCLASS TABLE\n");

    while (c != NULL) {
        printf("\nClass: %s\n", c->name);
        printf("Class Index: %d\n", c->Class_index);

        // if (c->Parentptr)
        //     printf("Parent: %s\n", c->Parentptr->name);
        // else
        //     printf("Parent: NULL\n");

        printf("Field Count: %d\n", c->Fieldcount);
        printf("Method Count: %d\n", c->Methodcount);

        printFields(c);
        printMethods(c);

        c = c->next;
    }
}

void printFields(struct Classtable *c) {
    struct Fieldlist *f = c->Memberfield;

    printf("\n  Fields:\n");

    if (f == NULL) {
        printf("    (none)\n");
        return;
    }

    while (f != NULL) {
        printf("%d %s : ", f->Fieldindex, f->name);

        if (f->Type)
            printf("%s", f->Type->name);
        else if (f->Ctype)
            printf("%s (class)", f->Ctype->name);
        else
            printf("UNKNOWN");

        printf("\n");

        f = f->next;
    }
}
void printMethods(struct Classtable *c) {
    struct Memberfunclist *m = c->Vfuncptr;

    printf("\n  Methods:\n");

    if (m == NULL) {
        printf("    (none)\n");
        return;
    }

    while (m != NULL) {
        printf("%d %s() : %s , Flabel: %d\n",
               m->Funcposition,
               m->name,
               m->Type ? m->Type->name : "void",
               m->Flabel);

        printParamList(m->paramlist);

        m = m->next;
    }
 }
