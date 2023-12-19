#include "../inc/pathfinder.h"

element_of_node **develop_successors(int **arr, element_of_node* parent, char **islands) {
    int index_isl = 0, amount_isl = 0;
    for(;mx_strcmp(islands[index_isl], parent->name) != 0; index_isl++);
    
    amount_isl = count_elements_until_null(islands);
    
    element_of_node** successors  = create_successors_array(amount_isl);
    successors = create_successors(successors, index_isl, parent, amount_isl, arr, islands);
    
    int lenght = get_successors_length(successors, amount_isl);
    
    element_of_node** result_succesors = create_result_of_manipulation(lenght);
    
    result_succesors = make_result_successors(successors, result_succesors, amount_isl);

    return result_succesors;
}


