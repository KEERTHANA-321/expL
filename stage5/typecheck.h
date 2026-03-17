#ifndef TYPECHECK_H
#define TYPECHECK_H

extern struct Gsymbol* Gtemp;
extern struct Lsymbol* Ltemp;
extern struct Paramstruct* Ptemp;
void assignType(struct tnode* node, int func);
int checkAvailability(char *name, int global);
void typecheck(int t1, int t2, char c);
void checkFunctionArgs(struct Gsymbol *func, struct Paramstruct *param, struct tnode *argList);
#endif