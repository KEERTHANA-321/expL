#ifndef TYPETABLE_H
#define TYPETABLE_H

struct Typetable{
    char *name;                 //type name
    int size;                   //size of the type
    struct Fieldlist *fields;   //pointer to the head of fields list
    struct Typetable *next;     // pointer to the next type table entry
};
struct Fieldlist{
  char *name;              //name of the field
  int fieldIndex;          //the position of the field in the field list
  struct Typetable *type;  //pointer to type table entry of the field's type
  struct Fieldlist *next;  //pointer to the next field
};

extern struct Typetable *Thead,*Ttemp,*Ttail;
extern struct Fieldlist *Fhead, *Ftail;

void TypeTableCreate();
struct Typetable* TLookup(char *name);
void  TInstall(char *name,struct Fieldlist *fields);
struct Fieldlist* FLookup(char *name,struct Fieldlist *list);
void FInstall(char *name, struct Typetable *type);
int GetSize(struct Typetable * type);
void printTypeTable();

#endif