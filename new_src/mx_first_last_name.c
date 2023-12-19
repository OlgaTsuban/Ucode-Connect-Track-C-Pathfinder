#include "../inc/pathfinder.h"

char **all_parts_of_name(element_of_node *node) {
    char** fullname = (char**)malloc(2 * sizeof(char*));

    if (fullname != NULL) {
        for (int i = 0; i < 2; i++) {
            fullname[i] = NULL;
        }

        // Get the first name (name of the given node)
        fullname[0] = mx_strdup(node->name);

        // Get the last name (name of the root ancestor)
        element_of_node* object = node;
        while (object->ancestor != NULL) {
            object = object->ancestor;
        }
        fullname[1] = mx_strdup(object->name);
    }

    return fullname;
}


