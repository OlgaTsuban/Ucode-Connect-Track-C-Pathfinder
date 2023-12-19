#include "../inc/pathfinder.h"

// Function to create an array of strings with NULL initialization
char** create_string_array_with_null(int length) {
    char** outcome_matrix = (char**)malloc((length + 1) * sizeof(char*));

    if (outcome_matrix != NULL) {
        for (int i = 0; i < length; i++) {
            outcome_matrix[i] = NULL;
        }
    }

    return outcome_matrix;
}


