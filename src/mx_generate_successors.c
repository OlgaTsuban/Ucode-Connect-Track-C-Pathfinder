#include "../inc/pathfinder.h"

t_node **generate_successors(int **arr, t_node* parent, char **islands) {
    int index_isl = 0;
    int islands_num = 0;
    for(;mx_strcmp(islands[index_isl], parent->name) != 0; index_isl++);
    
    for(;islands[islands_num] != NULL; islands_num++);
    
    t_node **successors = (t_node **) malloc((islands_num) * sizeof(t_node *));
    for(int i = 0; i < islands_num; i++) {
        successors[i] = (t_node*)malloc(sizeof(t_node));
        successors[i] = NULL;
    }
    
    for(int i = 0; i < islands_num; i++) {
        if(i != index_isl && arr[index_isl][i] != -1 && parent != NULL) {
            t_node *temp = parent;
            bool was_in_arr = false;
            int j = 0;
            while(temp != NULL) {
                
                if(mx_strcmp(temp->name, islands[i]) == 0 || j > islands_num) {
                    was_in_arr = true;
                    break;
                }
                temp = temp->parent;
                j++;
            }
            if(j > islands_num) {
                break;
            }
            if (was_in_arr == false)
                successors[i] = new_node(arr[index_isl][i], parent->all_way + arr[index_isl][i], islands[i]);
        }
    }
    
    int lenght = 0;
    for(int i = 0; i < islands_num; i++) {
        if(successors[i] != NULL) {
            lenght++;
        }
    }
    
    t_node **successors_res = (t_node **) malloc((lenght + 1) * sizeof(t_node *));
    for(int i = 0; i < lenght + 1; i++)
        successors_res[i] = NULL;
    
    lenght = 0;
    for(int i = 0; i < islands_num; i++) {
        if(successors[i] != NULL) {
            successors_res[lenght] = (t_node *) malloc(sizeof(t_node ));
            successors_res[lenght] = successors[i];
            lenght++;
        }
    }
    
    return successors_res;
}


