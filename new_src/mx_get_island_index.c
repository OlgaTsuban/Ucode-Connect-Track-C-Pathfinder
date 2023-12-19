#include "../inc/pathfinder.h"

int mx_return_index_of_island(char **all_of_islands, char *one_of_island) {
    if (all_of_islands == NULL || one_of_island == NULL) {
        return -1;  // Input validation: handle NULL pointers
    }
    for(int i = 0; all_of_islands[i] != NULL; i++) {
        if(mx_strcmp(all_of_islands[i], one_of_island) == 0) {
            return i;
        }
    }
    return -1;
}


