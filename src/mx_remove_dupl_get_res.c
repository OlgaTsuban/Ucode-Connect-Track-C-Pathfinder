#include "../inc/pathfinder.h"

void remove_dupl_get_res(t_node **res, int size, char **islands) {

    t_node **res_temporary  = (t_node **) malloc(size * sizeof(t_node *));
    for(int i = 0; i < size; i++) {
        res_temporary[i] = NULL;
    }

    int h = 0;
    bool add = true;

    for(int i = 0; res[i] != NULL; i++) {
        for(int j = 0; res[j] != NULL; j++) {
            t_node *temp_2 = res[j];
            t_node *temp = res[i];
            if(i != j) {
                if(!mx_compare_the_paths(temp, temp_2, res_temporary)) {
                    add = false;
                    break;
                }
            }
        }
        if (add == true) {
            res_temporary[h] = res[i];
            h++;
        }
        add = true;
    }
    sort_the_path_of_islands(res_temporary, islands);
    for(int i = 0; res_temporary[i] != NULL; i++) {
        print_res_node(res_temporary[i]);
    }
}


