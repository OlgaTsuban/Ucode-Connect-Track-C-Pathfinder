#include "../inc/pathfinder.h"

int get_array_size(char **arr) {
    int size = 0;
    while (arr[size] != NULL) {
        size++;
    }
    return size;
}


