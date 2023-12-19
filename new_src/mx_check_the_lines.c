#include "../inc/pathfinder.h"


void mx_check_the_lines(char *line, int i) {
    int first_dash_index = mx_get_substr_index(line, "-");
    int last_dash_index = mx_get_substr_index(&line[first_dash_index + 1], "-");
    char **l = mx_strsplit(line, '-');
    char *l1 = l[0];
    char *l2 = l[1];
    char **l3 = mx_strsplit(l2, ',');
    if (first_dash_index >= 0 && last_dash_index >= 0) {
        mx_printerr("error: line ");
        char *line_number = mx_itoa(i);
        mx_printerr(line_number);
        mx_printerr(" is not valid\n");
        exit(1);
    }
    for (int j = 0; l1[j] != '\0'; j++) {
        if (!mx_isalpha(l1[j])) {
            mx_printerr("error: line ");
            char *line_number = mx_itoa(i);
            mx_printerr(line_number);
            mx_printerr(" is not valid\n");
            exit(1);
        }
    }
    for (int j = 0; l3[0][j] != '\0'; j++) {
        if (!mx_isalpha(l3[0][j])) {
            mx_printerr("error: line ");
            char *line_number = mx_itoa(i);
            mx_printerr(line_number);
            mx_printerr(" is not valid\n");
            exit(1);
        }
    }
    if (!mx_strcmp(l3[0], l1)) {
        mx_printerr("error: line ");
        char *line_number = mx_itoa(i);
        mx_printerr(line_number);
        mx_printerr(" is not valid\n");
        exit(1);
    }
    for (int j = 0; l3[1][j] != '\0'; j++) {
        if (!mx_isdigit(l3[1][j])) {
            mx_printerr("error: line ");
            char *line_number = mx_itoa(i);
            mx_printerr(line_number);
            mx_printerr(" is not valid\n");
            exit(1);
        }
    }
}


