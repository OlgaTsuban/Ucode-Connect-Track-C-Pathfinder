#include "../inc/pathfinder.h"

element_of_node** create_res_temporary(int range) {
    element_of_node** res_temporary = (element_of_node**)malloc(range * sizeof(element_of_node*));
    if (res_temporary != NULL) {
        for (int i = 0; i < range; i++) {
            res_temporary[i] = NULL;
        }
    }
    return res_temporary;
}


