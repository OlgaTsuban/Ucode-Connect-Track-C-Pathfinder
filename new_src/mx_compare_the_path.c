#include "../inc/pathfinder.h"

bool mx_equate_the_matrix_paths(element_of_node *link1, element_of_node *link2, element_of_node **outcome_temp) {
    int len1 = 0, len2 = 0;
    // Calculate the length of the paths
    for (element_of_node *brief_link1 = link1; brief_link1->ancestor != NULL; brief_link1 = brief_link1->ancestor) {
        len1 += brief_link1->to_ancestor;
    }
    for (element_of_node *brief_link2 = link2; brief_link2->ancestor != NULL; brief_link2 = brief_link2->ancestor) {
        len2 += brief_link2->to_ancestor;
    }

    // Get first and last names of nodes
    char **brief_term1 = all_parts_of_name(link1);
    char **brief_term2 = all_parts_of_name(link2);

    if((mx_strcmp(brief_term1[0], brief_term2[0]) == 0 && mx_strcmp(brief_term1[1], brief_term2[1]) == 0)) {
        if(len1 > len2) {
            return false;
        }
    }
    else if ((mx_strcmp(brief_term1[1], brief_term2[0]) == 0 && mx_strcmp(brief_term1[0], brief_term2[1]) == 0)) {
        if(outcome_temp == NULL) {
            if(len1 >= len2)
                return false;
            return true;
        }
        for(int i = 0; outcome_temp[i] != NULL; i++) {
            element_of_node *temp = outcome_temp[i];
            if(len1 > len2 || !mx_equate_the_matrix_paths(link1, temp, NULL)) {
                return false;
            }
        }
    }
    
    return true;
}


