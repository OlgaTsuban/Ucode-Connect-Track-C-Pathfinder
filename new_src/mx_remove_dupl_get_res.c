#include "../inc/pathfinder.h"

void remove_dupl_get_res(element_of_node **res, int size, char **islands) {
    element_of_node** outcome = create_res_temporary(size);
    int index = 0;
    bool was_change = true;
    remove_duplicates(res, outcome, was_change, index);
    sort_the_path_of_islands(outcome, islands);
    for(int i = 0; outcome[i] != NULL; i++) {
        output_result_node(outcome[i]);
    }
}


