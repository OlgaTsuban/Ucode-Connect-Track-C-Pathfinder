#include "../inc/pathfinder.h"

void remove_duplicates(element_of_node** res, element_of_node** outcome, bool change, int index) {
    for (int i = 0; res[i] != NULL; i++) {
        for (int j = 0; res[j] != NULL; j++) {
            if (i != j) {
                if (!mx_equate_the_matrix_paths(res[i], res[j], outcome)) {
                    change = false;
                    break;
                }
            }
        }
        if (change) {
            outcome[index] = res[i];
            index++;
        }
        change = true;
    }
}


