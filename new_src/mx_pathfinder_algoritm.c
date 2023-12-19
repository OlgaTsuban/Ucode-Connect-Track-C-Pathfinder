#include "../inc/pathfinder.h"

element_of_node **algoritm_for_find_path(int **arr, char **islands, int cur_x, int goal_x) {
    element_of_node *plan = new_node(0, 0, islands[cur_x]);
    element_of_queue *end_queue = newNode(plan);
    element_of_queue *one_of_queue = newNode(plan);
     
    int amount_of_objects = 0;
    amount_of_objects = count_elements_until_null(islands);
    element_of_node** paths = create_paths_array(amount_of_objects);
    
    int way_num = 0;
    int audit = 0;
    
    while (!isEmpty(&one_of_queue)) {
        audit++;
        plan = one_of_queue->node;
        pop(&one_of_queue);
        
        element_of_node *for_time = plan;
        int j = 0;
        for(; for_time->ancestor != NULL; j++) {
            if(j > amount_of_objects)
                break;
            for_time = for_time->ancestor;
        }
        if(j >= amount_of_objects)
            continue;

        if(!isInIslands(plan, islands, amount_of_objects)) { 
            continue;
        }
        
        element_of_node **successors = develop_successors(arr, plan, islands);
        
        for (int i = 0; successors[i] != NULL; i++) {
            successors[i]->ancestor = plan;
        }
        for (int i = 0; successors[i] != NULL; i++) {
            processGoalNode(successors, paths, &way_num, islands, goal_x, i);
            //this is the best possible way
            element_of_queue *temp_queue = one_of_queue;
            element_of_queue *queue_close_temp = end_queue;
            bool in_queue = isInQueueWithHigherAllWay(temp_queue, successors[i]);
            bool in_close_queue = isInQueueWithHigherAllWay(queue_close_temp, successors[i]);
            
            if(in_queue == false && in_close_queue == false) {
                push(&one_of_queue, successors[i]);
                push(&end_queue, successors[i]);
            }
        }
    }
    return paths;
}


