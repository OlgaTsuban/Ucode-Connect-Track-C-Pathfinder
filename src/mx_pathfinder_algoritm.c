#include "../inc/pathfinder.h"

t_node **pathfinder_alg(int **arr, char **islands, int cur_x, int goal_x) {
    t_node *way = new_node(0, 0, islands[cur_x]);
    
    t_queue *queue = newNode(way);
    
    t_queue *queue_close = newNode(way);
    
    
    int islands_num = 0;
    for(;islands[islands_num] != NULL; islands_num++);
    t_node **paths = (t_node **) malloc(mx_pow(islands_num, 2) * sizeof(t_node *));
    for(int i = 0; i < islands_num; i++) {
        paths[i] = (t_node*)malloc(sizeof(t_node));
        paths[i] = NULL;
    }
    int paths_index = 0;
    int check = 0;
    
    while (!isEmpty(&queue)) {
        check++;
        way = queue->node;
        pop(&queue);
        
        t_node *temp = way;
        int j = 0;
        for(; temp->parent != NULL; j++) {
            if(j > islands_num)
                break;
            temp = temp->parent;
        }
        if(j >= islands_num)
            continue;
        
        bool in_islands = false;
        for(int h = 0; h < islands_num; h++) {
            if(mx_strcmp(way->name, islands[h]) == 0) {
                in_islands = true;
            }
        }
        if(in_islands == false) {
            continue;
        }
        
        
        t_node **successors = generate_successors(arr, way, islands);
        
        for (int i = 0; successors[i] != NULL; i++) {
            successors[i]->parent = way;
        }
        
        for (int i = 0; successors[i] != NULL; i++) {
            if(mx_strcmp(successors[i]->name, islands[goal_x]) == 0) {
                paths[paths_index] = successors[i];
                paths_index++;
            }
            
            t_queue *temp_queue = queue;
            bool in_queue = false;
            while(temp_queue != NULL) {
                if(mx_strcmp(temp_queue->node->name, successors[i]->name) == 0) {
                    if(temp_queue->node->all_way < successors[i]->all_way) {
                        in_queue = true;
                        break;
                    }
                }
                temp_queue = temp_queue->next;
            }
            
            bool in_cose_queue = false;
            t_queue *queue_close_temp = queue_close;
            while(queue_close_temp != NULL) {
                if(mx_strcmp(queue_close_temp->node->name, successors[i]->name) == 0) {
                    if(queue_close_temp->node->all_way < successors[i]->all_way) {
                        in_cose_queue = true;
                        break;
                    }
                }
                queue_close_temp = queue_close_temp->next;
            }
            
            
            if(in_queue == false && in_cose_queue == false) {
                push(&queue, successors[i]);
                push(&queue_close, successors[i]);
            }
        }
    }
    return paths;
}


