#include "../inc/pathfinder.h"

void push(element_of_queue** head, element_of_node *node) {
    element_of_queue* start = (*head);
    element_of_queue* temp = newNode(node);
    if((*head) == NULL) {
        (*head) = temp;
        return;
    }
    if ((*head)->prerogative > node->total_way) {
        temp->closest = *head;
        (*head) = temp;
    }
    else {
        while (start->closest != NULL && start->closest->prerogative < node->total_way) {
            start = start->closest;
        }
  
        temp->closest = start->closest;
        start->closest = temp;
    }
}


