#include "../inc/pathfinder.h"

void reverseNames(char** names, int size) {
    for (int j = 0; j < size / 2; j++) {
        char* temp = names[j];
        names[j] = names[size - 1 - j];
        names[size - 1 - j] = temp;
    }
}


