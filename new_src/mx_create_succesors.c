#include "../inc/pathfinder.h"

element_of_node** create_successors(element_of_node** successors, int index_isl, element_of_node* parent, int islands_num, int** arr, char** islands) {
    if (successors != NULL) {
        for (int i = 0; i < islands_num; i++) {
            //successors[i] = NULL;
            if (i != index_isl && arr[index_isl][i] != -1 && parent != NULL) {
                element_of_node* temp = parent;
                bool was_in_arr = false;
                int j = 0;
                while (temp != NULL) {
                    if (mx_strcmp(temp->name, islands[i]) == 0 || j > islands_num) {
                        was_in_arr = true;
                        break;
                    }
                    temp = temp->ancestor;
                    j++;
                }
                if (j > islands_num) {
                    break;
                }
                if (!was_in_arr) {
                    successors[i] = new_node(arr[index_isl][i], parent->total_way + arr[index_isl][i], islands[i]);
                }
            }
        }
    }
    return successors;
}



