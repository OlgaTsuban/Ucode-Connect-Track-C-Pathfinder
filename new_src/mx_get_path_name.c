#include "../inc/pathfinder.h"

char** getPathNames(element_of_node* path, char** names, int size) {
    //char** names = (char **) malloc((size) * sizeof(char *));
    for (int j = 0; j < size; j++) {
        names[j] = mx_strdup(path->name);
        path = path->ancestor;
    }
    return names;
}


