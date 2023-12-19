#include "../inc/pathfinder.h"

element_of_node** generate_paths(int** a_matrix, char** islands, int amount_of_isl, element_of_node** res_paths, int index2) {
    if (res_paths != NULL) {
        for (int islands_i = 0; islands_i < amount_of_isl; islands_i++) {
            for (int islands_j = 0; islands_j < amount_of_isl; islands_j++) {
                if (islands_i != islands_j) {
                    element_of_node** a_m = algoritm_for_find_path(a_matrix, islands, islands_i, islands_j);

                    for (int j = 0; a_m[j] != NULL; j++) {
                        // Allocate memory for a new t_node
                        res_paths[index2] = (element_of_node*)malloc(sizeof(element_of_node));

                        // Copy the content of the node
                        *res_paths[index2] = *a_m[j];

                        index2++;
                    }
                }
            }
        }
    }
    return res_paths;
}


