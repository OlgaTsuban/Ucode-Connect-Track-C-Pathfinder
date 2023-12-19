#include "../inc/pathfinder.h"

element_of_node** create_paths_array(int amount_of_objects) {
    int matrix_range = mx_pow(amount_of_objects, 2);
    element_of_node** ways = (element_of_node**)malloc(matrix_range * sizeof(element_of_node*));
    if (ways != NULL) {
        for (int i = 0; i < amount_of_objects; i++) {
            ways[i] = (element_of_node*)malloc(sizeof(element_of_node));
            ways[i] = NULL;
        }
    }
    return ways;
}


