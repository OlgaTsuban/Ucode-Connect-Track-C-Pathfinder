#include "../inc/pathfinder.h"

element_of_queue* newNode(element_of_node *node) {
    element_of_queue* brief = (element_of_queue*)malloc(sizeof(element_of_queue));
    brief->prerogative = node->total_way;
    brief->closest = NULL;
    brief->node = node;
    return brief;
}

void pop(element_of_queue** head) {
    element_of_queue* brief = *head;
    (*head) = (*head)->closest;
    free(brief);
}


