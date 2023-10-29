#include "../inc/pathfinder.h"

int mx_get_island_index(char **islands, char *island) {
    for(int i = 0; islands[i] != NULL; i++) {
        if(mx_strcmp(islands[i], island) == 0) {
            return i;
        }
    }
    return -1;
}


