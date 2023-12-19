#include "../inc/pathfinder.h"

int get_successors_length(element_of_node** successors, int islands_num) {
    int length = 0;
    for (int i = 0; i < islands_num; i++) {
        if (successors[i] != NULL) {
            length++;
        }
    }
    return length;
}


