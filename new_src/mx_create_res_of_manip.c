#include "../inc/pathfinder.h"

element_of_node** create_result_of_manipulation(int length) {
    element_of_node** successors_res = (element_of_node**)malloc((length + 1) * sizeof(element_of_node*));

    if (successors_res != NULL) {
        for (int i = 0; i < length + 1; i++) {
            successors_res[i] = NULL;
        }
    }
    return successors_res;
}


