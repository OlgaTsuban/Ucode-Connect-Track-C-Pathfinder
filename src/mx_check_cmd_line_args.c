#include "../inc/pathfinder.h"

void mx_check_cmd_line_args(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}


