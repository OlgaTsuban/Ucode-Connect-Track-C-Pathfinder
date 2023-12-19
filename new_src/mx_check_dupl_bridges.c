#include "../inc/pathfinder.h"

// Function to check for duplicate bridges in arr_str
void check_duplicate_bridges(char** matrix, int range) {
    for (int i = 0; i < range; i += 3) {
        for (int j = i + 3; j < range; j += 3) {
            if ((mx_strcmp(matrix[i], matrix[j]) == 0 && mx_strcmp(matrix[i + 1], matrix[j + 1]) == 0) ||
                (mx_strcmp(matrix[i + 1], matrix[j]) == 0 && mx_strcmp(matrix[i], matrix[j + 1]) == 0)) {
                mx_printerr("error: duplicate bridges\n");
                exit(1);
            }
        }
    }
}


