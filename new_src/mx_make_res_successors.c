#include "../inc/pathfinder.h"

element_of_node** make_result_successors(element_of_node** successors, element_of_node** successors_res, int islands_num) {
    int idx = 0;
    
    if (successors_res != NULL) {
        
        for (int i = 0; i < islands_num; i++) {
            if (successors[i] != NULL) {
                successors_res[idx] = (element_of_node*)malloc(sizeof(element_of_node));
                successors_res[idx] = successors[i];
                idx++;
            }
        }
    }
    return successors_res;
}


