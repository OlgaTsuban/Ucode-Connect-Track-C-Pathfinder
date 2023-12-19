#include "../inc/pathfinder.h"

element_of_node** create_node_array(int size) {
    element_of_node** res_paths = (element_of_node**)malloc((size + 1) * sizeof(element_of_node*));

    if (res_paths != NULL) {
        for (int j = 0; j < size; j++) {
            res_paths[j] = NULL;
        }
    }
    return res_paths;
}


