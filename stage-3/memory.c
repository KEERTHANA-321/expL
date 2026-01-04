#include "memory.h"
#include <stdlib.h>

int getAddress(char var) {
    return STACK_START + (var - 'a');
}
