#include "../inc/pathfinder.h"

void print_distance(element_of_node *node, int amount_matrix) {
    mx_printstr("Distance: ");

    if (amount_matrix == 2) {
        mx_printint(node->to_ancestor);
    } else {
        element_of_node *t = node;
        int *num_matrix = (int *) malloc(amount_matrix * sizeof(int));
        for (int i = 0; t != NULL; i++){
            num_matrix[i] = t->to_ancestor;
            t = t->ancestor;
        }
        for (int i = amount_matrix - 2; i >= 0; i--) {
            mx_printint(num_matrix[i]);
            if (i > 0) {
                mx_printstr(" + ");
            }
        }
        mx_printstr(" = ");

        int sum = 0;
        for (int i = 0; i < amount_matrix - 1; i++) {
            sum += num_matrix[i];
        }
        mx_printint(sum);
    }
}


