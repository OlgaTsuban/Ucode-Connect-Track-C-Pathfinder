#include "../inc/pathfinder.h"

bool compareIslandNames(char *name1, char *name2, char **islands, int *index1, int *index2) {
    for (int j = 0; islands[j] != NULL; j++) {
        if (mx_strcmp(islands[j], name1) == 0) {
            *index1 = j;
            break;
        }
        (*index1)++;
    }
    for (int j = 0; islands[j] != NULL; j++) {
        if (mx_strcmp(islands[j], name2) == 0) {
            *index2 = j;
            break;
        }
        (*index2)++;
    }
    return *index1 == *index2;
}


