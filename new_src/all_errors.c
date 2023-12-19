#include "../inc/pathfinder.h"

void all_errors(int argc, char *argv[]) {
    mx_check_cmd_line_args(argc);
    int fd = open(argv[1], O_RDONLY);
    //if file exists
    mx_check_file_exist(fd, argv[1]);
    //if file empty
    mx_file_is_empty(fd, argv[1]);
    const char* inside_file = mx_file_to_str(argv[1]);
    int i = 0;
    char* s = malloc(mx_strlen(inside_file) + 1);
    while (inside_file[i] != '\n') {
        s[i] += inside_file[i];
        i++;
    }
    s[i] = '\0';
    
    mx_check_the_1_line(s);
    
    char **lines = mx_strsplit(inside_file, '\n');
    if (lines) {
        for (int i = 1; lines[i] != NULL; ++i) {
            
            mx_check_the_lines(lines[i],i+1);
            
            free(lines[i]);
        }
        free(lines);
    }
    char **res = mx_decompose_the_file(inside_file);
    int first_line = mx_atoi(inside_file);
    
    mx_check_count_islands(res, first_line);

    mx_check_len_of_bridges(inside_file);
    free(s);
    close(fd);
    
}


