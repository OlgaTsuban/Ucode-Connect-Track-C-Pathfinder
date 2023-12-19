#include "../inc/pathfinder.h"

char **mx_decompose_the_file(const char *str) {
    int lin_num = count_newlines(str);
    
    char **result = (char **)malloc((3 * lin_num + 1) * sizeof(char *));
    if (result == NULL) {
        return NULL;
    }
    char **string_m = mx_strsplit(str, '\n');
    if (string_m == NULL) {
        free(result);
        return NULL;
    }
    int iter = 0;

    result = process_array(string_m, result, iter);
    // Free the split lines array
    mx_del_strarr(&string_m);
    
    return result;
}


