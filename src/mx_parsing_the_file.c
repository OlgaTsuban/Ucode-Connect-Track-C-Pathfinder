#include "../inc/pathfinder.h"

char **mx_parsing_the_file(const char *str) {
    int lin_num = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            lin_num++;
        }
    }
    
    char **str_res = (char **)malloc((3 * lin_num + 1) * sizeof(char *));
    if (str_res == NULL) {
        return NULL;
    }
    char **arr_str = mx_strsplit(str, '\n');
    if (arr_str == NULL) {
        
        free(str_res);
        return NULL;
    }
    int iter = 0;
    
    for (int i = 0; arr_str[i] != NULL; i++) {
        char *trimmed_line = mx_strtrim(arr_str[i]);
        char **arr_temp = mx_strsplit(trimmed_line, '-');
        
        free(trimmed_line);
        
        if (arr_temp[0] && arr_temp[1]) {
            char *first_part = mx_strdup(arr_temp[0]);
            char *second_part = mx_strdup(mx_strsplit(arr_temp[1], ',')[0]);
            char *third_part = mx_strdup(mx_strsplit(arr_temp[1], ',')[1]);
            
            
            str_res[iter++] = first_part;
            str_res[iter++] = second_part;
            str_res[iter++] = third_part;
        }
        
        // Free temporary arrays
        mx_strdel(&arr_temp[0]);
        mx_strdel(&arr_temp[1]);
        free(arr_temp);
    }
    
    mx_check_dup(str_res, iter);
    
    str_res[iter] = NULL;
    // Free the split lines array
    mx_del_strarr(&arr_str);
    
    return str_res;
}


