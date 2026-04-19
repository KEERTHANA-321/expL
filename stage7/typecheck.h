#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "typetable.h"
extern struct Gsymbol* Gtemp;
extern struct Lsymbol* Ltemp;
extern struct Paramstruct* Ptemp;
extern struct Memberfunclist *Mtemp;
extern struct Fieldlist *Ftemp;
void assignType(struct tnode* node, int func);
int checkAvailability(char *name, int global);
void typecheck(struct Typetable* t1, struct Typetable* t2, char c);
void checkFunctionArgs(struct Gsymbol *func, struct Paramstruct *param, struct tnode *argList);
void assignTypeField(struct tnode* node, struct Fieldlist *fields);
int countArgs(struct tnode *argList);
int flattenArgs(struct tnode *argList, struct tnode **arr, int idx);
#endif