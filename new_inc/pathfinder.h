#ifndef PATHFINDER_H
#define PATHFINDER_H

#define INT_MAX 2147483647

#include "../libmx/inc/libmx.h"


typedef struct struct_node { //graph
    int total_way;
    int to_ancestor;
    char *name;
    struct struct_node* ancestor;
} element_of_node;

typedef struct struct_queue {
    int prerogative;
    element_of_node *node;
    struct struct_queue* closest;
} element_of_queue;


int main(int argc, char *argv[]);
//errors
void mx_check_cmd_line_args(int argc);
void mx_check_file_exist(int fd, const char *filename);
void mx_file_is_empty(int fd, char *filename);
void mx_check_the_1_line(char *string);
void mx_check_the_lines(char *line, int i);
void mx_check_count_islands(char **str,int first_line);
void mx_check_duplicate(char **arr_str, int size);
void mx_check_len_of_bridges(const char *inside_file);
void all_errors(int argc, char *argv[]);

char **mx_decompose_the_file(const char *str);
char **create_update_free_islands(char **matrix);
void print_node(element_of_node *);
int mx_return_index_of_island(char **all_of_islands, char *one_of_island);
int **adjacency_matrix(char **islands, char **arr, int size);
element_of_node **algoritm_for_find_path(int **arr, char **islands, int cur_x, int goal_x);

//queue
void push(element_of_queue** head, element_of_node *node);
void pop(element_of_queue** head);
int peek(element_of_queue** head);
int isEmpty(element_of_queue** head);
element_of_queue* newNode(element_of_node* node);

element_of_node **develop_successors(int **, element_of_node*, char **);
element_of_node *new_node(int, int, char *);


void output_result_node(element_of_node *node);
bool mx_equate_the_matrix_paths(element_of_node *link1, element_of_node *link2, element_of_node **outcome_temp);
void remove_dupl_get_res(element_of_node **res, int size, char **islands);
void sort_the_path_of_islands(element_of_node **paths, char **islands);
char **mx_get_name_islands(element_of_node *paths);
char **all_parts_of_name(element_of_node *node);

//additional
int count_elements_until_null(char** array);
int get_array_size(char **arr);
int count_total_nodes(int** matrix, char** islands, int size_of_isl);
element_of_node** create_node_array(int size);
element_of_node** generate_paths(int** a_matrix, char** islands, int amount_of_isl, element_of_node** res_paths, int index2);
int** create_and_initialize_2d_array(int size);
void fill_adjacency_matrix_entry(int **creation_result, char **islands, char **arr, size_t i);
void check_duplicate_islands(char** matrix, int range);
void check_duplicate_bridges(char** matrix, int range);
element_of_node** create_successors_array(int islands_num);
element_of_node** create_successors(element_of_node** successors, int index_isl, element_of_node* parent, int islands_num, int** arr, char** islands);
int get_successors_length(element_of_node** successors, int islands_num);
element_of_node** create_result_of_manipulation(int length);
element_of_node** make_result_successors(element_of_node** successors, element_of_node** successors_res, int islands_num);
void reverseNames(char** names, int size);
char** getPathNames(element_of_node* path, char** names, int size);
char** allocateNamesArray(int size);
void free_string_array(char** matrix, int l);
char** create_string_array(int range, char** str);
char** filter_and_copy_strings(int amount, int index, bool was, char** outcome, char** str);
char** create_string_array_with_null(int length);
char** duplicate_string_array(char** matrix, int length, char** outcome_matrix);
char** process_array(char** string_m, char** result, int iter );
int count_newlines(const char* inform);
void processGoalNode(element_of_node** successors, element_of_node** ways, int* num_ways, char** islands, int main_x, int i);
element_of_node** create_paths_array(int amount_of_objects);
bool isInIslands(element_of_node* node, char** islands, int amount_of_objects);
bool isInQueueWithHigherAllWay(element_of_queue* queue, element_of_node* node);
void print_route(char **names_arr, int arr_size);
void print_distance(element_of_node *node, int amount_matrix);
void print_path_info(element_of_node *node);
void print_separator_line();
element_of_node** create_res_temporary(int range);
void remove_duplicates(element_of_node** res, element_of_node** outcome, bool change, int index);
void swapNodesIfGreater(element_of_node **paths, int i);
bool compareIslandNames(char *name1, char *name2, char **islands, int *index1, int *index2);

#endif

