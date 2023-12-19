#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    all_errors(argc, argv);
    char *inform_in_file = mx_file_to_str(argv[1]);
    char **outcome = mx_decompose_the_file(inform_in_file);
    int size_isl = 0, index1 = 0, index2 = 0; 
    char **islands = create_update_free_islands(outcome);
    size_isl = get_array_size(islands);
    int **a_matrix = adjacency_matrix(islands, outcome, size_isl);
    
    index1 = count_total_nodes(a_matrix, islands, size_isl);
    
    element_of_node **output_paths = create_node_array(index1); 
    
    output_paths = generate_paths(a_matrix, islands, size_isl, output_paths, index2);
    remove_dupl_get_res(output_paths, index1, islands);
    return 0;
}



