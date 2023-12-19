#include "../inc/pathfinder.h"

void mx_check_duplicate(char **matrix_str, int s) {
    check_duplicate_islands(matrix_str, s);

    check_duplicate_bridges(matrix_str, s);
}


