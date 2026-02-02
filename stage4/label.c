#include "label.h"
#include "constants.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int labelCount = 0;
struct labeltableEntry *head=NULL;
struct labeltableEntry *tail=NULL;

int createnewLabel() {
    return labelCount++;
}

struct labeltableEntry *createnewlabeltableEntry(char *labelname, int memAddr){
    struct  labeltableEntry *newEntry = (struct labeltableEntry *) malloc (sizeof(struct labeltableEntry));
    strcpy(newEntry->labelname, labelname);
    newEntry->memAddr = memAddr;
    newEntry->next = NULL;
    return newEntry;
}

int getmemaddr(char *labelname){
    struct labeltableEntry *curr = head;
    while(curr != NULL){
        if(strcmp(curr->labelname, labelname) == 0){
            return curr->memAddr;
        }
        curr = curr->next;
    }
    return -1;
}

int addnewLabel(char *labelname, int memAddr){
    if(getmemaddr(labelname) != -1){
        return -1;
    }
    struct labeltableEntry *newEntry = createnewlabeltableEntry(labelname, memAddr);
    if(head == NULL){
        head = newEntry;
        tail = newEntry;
    } else {
        tail->next = newEntry;
        tail = newEntry;
    }
    printf("Label added: %s -> %d\n", labelname, memAddr);
    return 0;
}

void removeLabel(char *labelname){
    struct labeltableEntry *curr = head;
    struct labeltableEntry *prev = NULL;
    while(curr != NULL){
        if(strcmp(curr->labelname, labelname) == 0){
            if(prev == NULL){
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            if(curr == tail){
                tail = prev;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}