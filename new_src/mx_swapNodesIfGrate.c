#include "../inc/pathfinder.h"

void swapNodesIfGreater(element_of_node **paths, int i) {
    element_of_node *temp = paths[i];
    paths[i] = paths[i + 1];
    paths[i + 1] = temp;
}


