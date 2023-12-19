#include "../inc/pathfinder.h"

char** duplicate_string_array(char** matrix, int length, char** outcome_matrix) {
    if (outcome_matrix != NULL) {
        for (int i = 0; i < length; i++) {
            outcome_matrix[i] = mx_strdup(matrix[i]);

            if (outcome_matrix[i] == NULL) {
                // Handle memory allocation failure
                // Free previously allocated memory before returning
                for (int j = 0; j < i; j++) {
                    free(outcome_matrix[j]);
                }
                free(outcome_matrix);
                return NULL;
            }
        }
    }
    return outcome_matrix;
}


