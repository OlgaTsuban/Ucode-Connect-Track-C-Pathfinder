#include "../inc/pathfinder.h"

// Function to check if the node is in the islands array
bool isInIslands(element_of_node* node, char** islands, int amount_of_objects) {
    for (int h = 0; h < amount_of_objects; h++) {
        if (mx_strcmp(node->name, islands[h]) == 0) {
            return true;
        }
    }
    return false;
}


