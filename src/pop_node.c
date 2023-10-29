#include "../inc/pathfinder.h"

t_queue* newNode(t_node *node) {
    t_queue* temp = (t_queue*)malloc(sizeof(t_queue));
    temp->priority = node->all_way;
    temp->next = NULL;
    temp->node = node;
    return temp;
}

void pop(t_queue** head) {
    t_queue* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}


