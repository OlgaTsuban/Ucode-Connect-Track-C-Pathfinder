#ifndef PATHFINDER_H
#define PATHFINDER_H

#define INT_MAX 2147483647

#include "../libmx/inc/libmx.h"




typedef struct s_node { //graph
  
    int to_parent;
    int all_way;
    char *name;
    struct s_node* parent;
  
} t_node;

typedef struct s_queue {
  
    int priority;
    t_node *node;
    struct s_queue* next;
  
} t_queue;




int main(int argc, char *argv[]);
//errors
void mx_check_cmd_line_args(int argc);
void mx_check_file_exist(int fd, const char *filename);
void mx_file_is_empty(int fd, char *filename);
void mx_check_the_1_line(char *string);
void mx_check_the_lines(char *line, int i);
void mx_check_count_islands(char **str,int first_line);
void mx_check_dup(char **arr_str, int size);
void mx_check_len_of_bridges(const char *inside_file);
void all_errors(int argc, char *argv[]);

char **mx_parsing_the_file(const char *str);
char **list_of_islands(char **str);
void print_node(t_node *);
int mx_get_island_index(char **islands, char *island);
int **adjacency_matrix(char **islands, char **arr, int size);
t_node **pathfinder_alg(int **, char **, int, int);

//queue
int peek(t_queue** head);
int isEmpty(t_queue** head);
void push(t_queue** head, t_node *node);
void pop(t_queue** head);
t_queue* newNode(t_node* node);

t_node **generate_successors(int **, t_node*, char **);
t_node *new_node(int, int, char *);

void print_res_node(t_node *node);
bool mx_compare_the_paths(t_node *node1, t_node *node2, t_node **res_temp);
void remove_dupl_get_res(t_node **res, int size, char **islands);
void sort_the_path_of_islands(t_node **paths, char **islands);
char **mx_get_name_islands(t_node *paths);
char **first_last_name(t_node *);

#endif

