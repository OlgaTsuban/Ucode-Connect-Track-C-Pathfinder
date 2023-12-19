#include "../inc/pathfinder.h"

int **adjacency_matrix(char **islands, char **matrix, int range) {
    if (islands == NULL || matrix == NULL || range <= 0) {
        return NULL;  // Input validation: handle NULL pointers or non-positive size
    }
    
    int** creation_result = create_and_initialize_2d_array(range);
    int size_for_arr = get_array_size(matrix);

    for(int i = 0; i < size_for_arr; i += 3) {
        fill_adjacency_matrix_entry(creation_result, islands, matrix, i);
    }
    return creation_result;
}


