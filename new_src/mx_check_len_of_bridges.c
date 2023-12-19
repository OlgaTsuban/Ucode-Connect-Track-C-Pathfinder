#include "../inc/pathfinder.h"

void mx_check_len_of_bridges(const char *inside_file) {
    int num = 0;
    long int count_len = 0;
    char **lines = mx_strsplit(inside_file, '\n');
    if (lines) {
        for (int i = 1; lines[i] != NULL; ++i) {
            char **l = mx_strsplit(lines[i], ',');
            num = mx_atoi(l[1]);
            
            count_len += num;
            
            mx_del_strarr(&l);
            free(lines[i]);
        }
        free(lines);
    }
    if (count_len > INT_MAX) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(1);
    }
}



