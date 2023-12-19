#include "../inc/pathfinder.h"

// Function to free an array of strings
void free_string_array(char** matrix, int l) {
    if (matrix != NULL) {
        for (int i = 0; i < l; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
}


