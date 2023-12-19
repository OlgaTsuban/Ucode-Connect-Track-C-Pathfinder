#include "../inc/pathfinder.h"

void processGoalNode(element_of_node** successors, element_of_node** ways, int* num_ways, char** islands, int main_x, int i) {
        if (mx_strcmp(successors[i]->name, islands[main_x]) == 0) {
            ways[*num_ways] = successors[i];
            (*num_ways)++;
        }
    
}


