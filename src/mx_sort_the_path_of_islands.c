#include "../inc/pathfinder.h"

void sort_the_path_of_islands(t_node **paths, char **islands) {
    
    for(int i = 0; paths[i + 1] != NULL; i++) {
        
        char **paths_isl1 = first_last_name(paths[i]);
        char **paths_isl2 = first_last_name(paths[i + 1]);
        if(mx_strcmp(paths_isl1[1], paths_isl2[1]) == 0 && mx_strcmp(paths_isl1[0], paths_isl2[0]) == 0) {
            t_node *temp1 = paths[i];
            t_node *temp2 = paths[i + 1];
            char **names1 = mx_get_name_islands(temp1);
            
            char **names2 = mx_get_name_islands(temp2);
            
            int index1 = 0;
            int index2 = 0;
            for(int k = 0 ; names1[k] != NULL && names2[k] != NULL; k++) {
                if(mx_strcmp(names1[k], names2[k]) != 0) {
                    for(int j = 0; islands[j] != NULL; j++) {
                        if(mx_strcmp(islands[j], names1[k]) == 0) {
                            break;
                        }
                        index1++;
                    }
                    
                    for(int j = 0; islands[j] != NULL; j++) {
                        if(mx_strcmp(islands[j], names2[k]) == 0) {
                            break;
                        }
                        index2++;
                    }
                    
                    if(index1 != index2) {
                        break;
                    }
                }
            }
            if(index1 > index2) {
                t_node *temp = paths[i];
                paths[i] = paths[i + 1];
                paths[i + 1] = temp;
                i = 0;
            }
            
        }
    }
}


