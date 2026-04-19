#ifndef CLASSTABLE_H
#define CLASSTABLE_H

struct Classtable {
  char *name;                           //name of the class
 struct Fieldlist *Memberfield;        //pointer to Fieldlist
 struct Memberfunclist *Vfuncptr;      //pointer to Memberfunclist
 struct Classtable *Parentptr;         //pointer to the parent's class table
 int Class_index;                      //position of the class in the virtual function table
 int Fieldcount;                       //count of fields
   int Methodcount;                      //count of methods
 struct Classtable *next;              //pointer to next class table entry
};

struct Fieldlist{
 char *name;   //name of the field
 int Fieldindex;   //position of the field
 struct Typetable *Type;  //pointer to typetable
 struct Classtable *Ctype; //pointer to the class containing the field
 struct Fieldlist *next;  //pointer to next fieldlist entry
};

struct Memberfunclist {
  char *name;                      //name of the member function in the class
 struct Typetable *Type;          //pointer to typetable
 struct Paramstruct *paramlist;   //pointer to the head of the formal parameter list
 int Funcposition;                //position of the function in the class table
  int Flabel;                      //A label for identifying the starting address of the function's code in the memory
 struct Memberfunclist *next;     //pointer to next Memberfunclist entry
};



extern struct Classtable *Chead, *Ctail, *CCurrent;
extern struct Classtable *declarationCType;
extern int classFuncLabelCount;
struct Classtable* CInstall(char *name,char *parent_class_name);
struct Classtable* CLookup(char *name);
void Class_Finstall(struct Classtable *cptr, struct Typetable *type, struct Classtable *Ctype, char *name);
struct Memberfunclist* Class_Mlookup(struct Classtable* Ctype,char* name);
struct Fieldlist* Class_Flookup(struct Classtable* Ctype,char* name);
void Class_Minstall (struct Classtable *cptr, char *name, struct Typetable *type, struct Paramstruct *Paramlist);
void printClassTable();
void printFields(struct Classtable *c) ;
void printMethods(struct Classtable *c);
// void printParamList(struct Paramstruct *p) ;
#endif