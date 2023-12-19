#include "../inc/pathfinder.h"

void mx_check_the_1_line(char *string) {
    for (int i=0; string[i] != '\0'; i++){
        if (!mx_isdigit(string[i])) {
            mx_printerr("error: line ");
            mx_printerr("1");
            mx_printerr(" is not valid\n");
            exit(1);
        }
    }
}


