#include "../inc/pathfinder.h"

int count_total_nodes(int** matrix, char** islands, int size_of_isl) {
    int total_nodes = 0;
    for (int islands_i = 0; islands_i < size_of_isl; islands_i++) {
        for (int islands_j = 0; islands_j < size_of_isl; islands_j++) {
            if (islands_i != islands_j) {
                element_of_node** nodes = algoritm_for_find_path(matrix, islands, islands_i, islands_j);
                for (int j = 0; nodes[j] != NULL; j++) {
                    total_nodes++;
                }
            }
        }
    }
    return total_nodes;
}


