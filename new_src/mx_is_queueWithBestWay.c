#include "../inc/pathfinder.h"

// Function to check if a node with higher all_way is in the queue
bool isInQueueWithHigherAllWay(element_of_queue* queue, element_of_node* node) { //successors
    element_of_queue* alternative_queue = queue;
    while (alternative_queue != NULL) {
        if (mx_strcmp(alternative_queue->node->name, node->name) == 0) {
            if (alternative_queue->node->total_way < node->total_way) {
                return true; // Node with higher all_way found in the queue
            }
        }
        alternative_queue = alternative_queue->closest;
    }
    return false; // Node not found or has lower all_way in the queue
}



