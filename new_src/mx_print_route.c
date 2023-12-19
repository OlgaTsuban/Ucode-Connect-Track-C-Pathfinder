#include "../inc/pathfinder.h"

void print_route(char **names_arr, int arr_size) {
    mx_printstr("Route: ");
    for (int i = arr_size; i > 0; i--) {
        mx_printstr(names_arr[i - 1]);
        if (i > 1) {
            mx_printstr(" -> ");
        }
    }
    mx_printchar('\n');
}


