#include "../inc/pathfinder.h"

//list_of_islands
char **create_update_free_islands(char **matrix) {
    int amount = get_array_size(matrix);
    int lim = 1, range = 1;
    bool was = false;

    char** result = create_string_array(amount, matrix);
    result = filter_and_copy_strings(amount, lim, was, result, matrix);

    for(;mx_strcmp(result[0], result[range]) != 0; range++);
    char** arr_res = create_string_array_with_null(range); 

    arr_res = duplicate_string_array(result, range, arr_res);

    free_string_array(result, range);

    return arr_res;
}


