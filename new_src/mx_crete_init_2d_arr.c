#include "../inc/pathfinder.h"

int** create_and_initialize_2d_array(int size) {
    int** result_matrix = (int**)malloc(size * sizeof(int*));
    if (result_matrix == NULL) {
        return NULL;  // Allocation failure
    }
    for (int col = 0; col < size; col++) {
        result_matrix[col] = (int*)malloc(size * sizeof(int));
        if (result_matrix[col] == NULL) {
            // Clean up memory in case of allocation failure
            for (int j = 0; j < col; j++) {
                free(result_matrix[j]);
            }
            free(result_matrix);
            return NULL;
        }
        for (int row = 0; row < size; row++) {
            result_matrix[col][row] = -1;
        }
    }
    return result_matrix;
}

