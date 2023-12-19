#include "../inc/pathfinder.h"

char** process_array(char** string_m, char** result, int iter ) {
    int arr_size = 0;
    // Count the number of elements in arr_str
    for (; string_m[arr_size] != NULL; arr_size++);
    if (result != NULL) {
        for (int i = 0; i < arr_size; i++) {
            char* trimmed_line = mx_strtrim(string_m[i]);
            char** arr_temp = mx_strsplit(trimmed_line, '-');
            free(trimmed_line);
            if (arr_temp[0] && arr_temp[1]) {
                char* first_part = mx_strdup(arr_temp[0]);
                char* second_part = mx_strdup(mx_strsplit(arr_temp[1], ',')[0]);
                char* third_part = mx_strdup(mx_strsplit(arr_temp[1], ',')[1]);
                result[iter++] = first_part;
                result[iter++] = second_part;
                result[iter++] = third_part;
            }

            // Free temporary arrays
            mx_strdel(&arr_temp[0]);
            mx_strdel(&arr_temp[1]);
            free(arr_temp);
        }
        mx_check_duplicate(result, iter);
        result[iter] = NULL; 
    }
    return result;
}


