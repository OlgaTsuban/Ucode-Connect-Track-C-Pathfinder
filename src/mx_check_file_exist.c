#include "../inc/pathfinder.h"

void mx_check_file_exist(int fd, const char *filename) {
    if (fd == -1) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(1);
    }
    
}


