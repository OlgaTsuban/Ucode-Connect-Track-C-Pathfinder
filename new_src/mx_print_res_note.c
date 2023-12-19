#include "../inc/pathfinder.h"

void output_result_node(element_of_node *node) {
    print_separator_line();
    print_path_info(node);
    element_of_node *awhile = node;
    int size_for_matrix  = 0;
    while (awhile != NULL) {
        awhile = awhile->ancestor;
        size_for_matrix++;
    }

    awhile = node;
    char **names_arr = (char **) malloc(size_for_matrix * sizeof(char*));
    if (names_arr == NULL) {
        // Handle allocation failure
        return;
    }
    for (int i = 0; awhile != NULL; i++){
        names_arr[i] = mx_strdup(awhile->name);
        if (names_arr[i] == NULL) {
            // Handle allocation failure
            free(names_arr);
            return;
        }
        awhile = awhile->ancestor;
    }
    print_route(names_arr,size_for_matrix);
    print_distance(node, size_for_matrix);
    mx_printchar('\n');
    print_separator_line();
}


