#include "../inc/pathfinder.h"

char **first_last_name(t_node *node) {
    char **names = (char **) malloc(2 * sizeof(char*));
    for(int i = 0; i < 2; i++) {
        names[i] = NULL;
    }
    
    t_node *temp = node;
    names[0] = mx_strdup(node->name);
    for(int i = 0; temp->parent != NULL; i++) {
        temp = temp->parent;
    }
    names[1] = mx_strdup(temp->name);
    return names;
}


