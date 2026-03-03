#ifndef LABEL_H
#define LABEL_H

#define MAX_LABEL_LENGTH 10

typedef struct labeltableEntry {
    char labelname[MAX_LABEL_LENGTH];
    int memAddr;
    struct labeltableEntry *next;

} labeltableEntry;

extern int labelCount;
extern struct labeltableEntry *head;
extern struct labeltableEntry *tail;

int createnewLabel();
struct labeltableEntry *createnewlabeltableEntry(char *labelname, int memAddr);
int getmemaddr(char *labelname);
int addnewLabel(char *labelname, int memAddr);
void removeLabel(char *labelname);

#endif