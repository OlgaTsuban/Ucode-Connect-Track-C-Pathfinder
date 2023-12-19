#include "../inc/pathfinder.h"

void sort_the_path_of_islands(element_of_node **paths, char **islands) {
    for(int i = 0; paths[i + 1] != NULL; i++) {
        char **paths_isl1 = all_parts_of_name(paths[i]);
        char **paths_isl2 = all_parts_of_name(paths[i + 1]);
        if(mx_strcmp(paths_isl1[1], paths_isl2[1]) == 0 && mx_strcmp(paths_isl1[0], paths_isl2[0]) == 0) {
            element_of_node *temp1 = paths[i];
            element_of_node *temp2 = paths[i + 1];
            char **names1 = mx_get_name_islands(temp1);
            
            char **names2 = mx_get_name_islands(temp2);
            
            int index1 = 0;
            int index2 = 0;
            for(int k = 0 ; names1[k] != NULL && names2[k] != NULL; k++) {
                if(mx_strcmp(names1[k], names2[k]) != 0) {
                    
                    if (!compareIslandNames(names1[k], names2[k], islands, &index1, &index2) || index1 != index2) {
                        break;
                    }
                }
            }
            if (index1 > index2) {
                swapNodesIfGreater(paths, i);
                i = 0;
            }
            
        }
    }
}


