#include "../inc/pathfinder.h"

void print_path_info(element_of_node *node) {
    mx_printstr("Path: ");
    char **first_last = all_parts_of_name(node);
    mx_printstr(first_last[1]);
    mx_printstr(" -> ");
    mx_printstr(first_last[0]);

    mx_printchar('\n');
}


