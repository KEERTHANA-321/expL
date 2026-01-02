#include "register.h"
#include <stdlib.h>

// Track how many registers are currently in use
static int regCount;

// Initialize or reset register counter
void initReg() {
    regCount = -1;  // no registers allocated
}

// Allocate the lowest numbered free register
int getReg() {
    if (regCount < MAX_REGS - 1) {
        regCount++;
        return regCount;
    }
    fprintf(stderr, "Out of registers\n");
    exit(1);
}

// Free the highest numbered register currently in use
void freeReg() {
    if (regCount >= 0) {
        regCount--;
    }
}

