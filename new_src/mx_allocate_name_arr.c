#include "../inc/pathfinder.h"

char** allocateNamesArray(int size) {
    char** names = (char **) malloc((size + 1) * sizeof(char *));
    for (int j = 0; j <= size; j++) {
        names[j] = NULL;
    }
    return names;
}


