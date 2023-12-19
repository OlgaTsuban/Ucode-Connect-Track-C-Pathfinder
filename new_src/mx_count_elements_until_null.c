#include "../inc/pathfinder.h"
int count_elements_until_null(char** array) {
    int count = 0;
    while (array[count] != NULL) {
        count++;
    }
    return count;
}

