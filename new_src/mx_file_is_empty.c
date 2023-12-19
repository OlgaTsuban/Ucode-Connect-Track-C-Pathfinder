#include "../inc/pathfinder.h"

void mx_file_is_empty(int fd, char *filename) {
    int length = 0;
    char buffer[1];
    
    while (read(fd, buffer, 1))
        length++;
    
    if (length == 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        exit(1);
    }
}


