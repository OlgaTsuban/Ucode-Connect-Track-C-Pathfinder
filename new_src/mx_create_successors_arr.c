#include "../inc/pathfinder.h"

element_of_node** create_successors_array(int islands_num) {
    element_of_node** successors = (element_of_node**)malloc(islands_num * sizeof(element_of_node*));
    if (successors != NULL) {
        for (int i = 0; i < islands_num; i++) {
            successors[i] = NULL;
        }
    }
    return successors;
}


