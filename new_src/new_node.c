#include "../inc/pathfinder.h"

element_of_node *new_node(int to_ancestor, int all_way, char *name) {
    element_of_node* temp = (element_of_node*)malloc(sizeof(element_of_node));
    temp->to_ancestor = to_ancestor;
    temp->total_way = all_way;
    temp->name = mx_strdup(name);
    temp->ancestor = NULL;
    return temp;
} 


