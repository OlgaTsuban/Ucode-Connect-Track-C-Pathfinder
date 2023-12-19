#include "../inc/pathfinder.h"

void fill_adjacency_matrix_entry(int **creation_result, char **islands, char **arr, size_t i) {
    int first_i = mx_return_index_of_island(islands, arr[i]);
    int second_i = mx_return_index_of_island(islands, arr[i + 1]);

    if (first_i != -1 && second_i != -1) {
        creation_result[first_i][second_i] = mx_atoi(arr[i + 2]);
        creation_result[second_i][first_i] = mx_atoi(arr[i + 2]);
    }
}


