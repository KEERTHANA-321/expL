#include "memory.h"
#include <stdlib.h>

int getAddress(char var) {
    return 4096 + (var - 'a');
}
