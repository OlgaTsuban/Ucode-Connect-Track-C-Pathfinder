#include "../inc/pathfinder.h"

char **mx_get_name_islands(element_of_node *paths) {
    int i = 0;
    element_of_node *path = paths;
    for(;path != NULL; i++)
        path = path->ancestor;

    char** names=  allocateNamesArray(i);

    path = paths;
    names  = getPathNames(path, names, i);
    
    reverseNames(names, i);
    
    return names;
}


