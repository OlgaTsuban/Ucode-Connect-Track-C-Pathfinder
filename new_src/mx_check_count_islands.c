#include "../inc/pathfinder.h"

void mx_check_count_islands(char **arr_str,int first_line) {
    int amount = 0;
    for(;arr_str[amount] != NULL; amount++);
    bool was = false;
    int temp = 1;
    char **output = (char **) malloc((amount) * sizeof(char *));
    for(int i = 0; i < amount; i++) {
        output[i] = mx_strdup(arr_str[0]);
    }
    for (int i = 0; i < amount; i++) {
        for(int j = 0; j < amount; j++) {
            if(mx_strcmp(arr_str[i], output[j]) == 0 || mx_isdigit(arr_str[i][0])) {
                was = true;
            }
        }
        if(was == false) {
            output[temp] = mx_strdup(arr_str[i]);
            temp++;
        }
        was = false;
    }
    int length = 1;
    for(;mx_strcmp(output[0], output[length]) != 0; length++);
    char **arr_res = (char **) malloc((length + 1) * sizeof(char *));
    for(int i = 0; i < length; i++) {
        arr_res[i] = NULL;
    }
    for(int i = 0; i < length; i++) {
        arr_res[i] = mx_strdup(output[i]);
    }
    for(int i = 0; i < length; i++) {
        free(output[i]);
    }
    free(output);
    int size1 = 0;
        for(int i = 0; arr_res[i] != NULL; i++) {
            size1++;
        }
    
    if (first_line != size1) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}


