#include "../inc/pathfinder.h"

// Function to check for duplicate island names in arr_str
void check_duplicate_islands(char** matrix, int range) {
    for (int i = 0; i < range; i += 3) {
        if (mx_strcmp(matrix[i], matrix[i + 1]) == 0) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa((i / 3) + 2));
            mx_printerr(" is not valid\n");
            exit(1);
        }
    }
}


