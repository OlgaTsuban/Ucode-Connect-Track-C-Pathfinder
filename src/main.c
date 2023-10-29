#include "../inc/pathfinder.h"

t_node *new_node(int to_parent, int all_way, char *name) {
    t_node* temp = (t_node*)malloc(sizeof(t_node));
    temp->to_parent = to_parent;
    temp->all_way = all_way;
    temp->name = mx_strdup(name);
    temp->parent = NULL;
  
    return temp;
} 


int main(int argc, char *argv[]) {
    all_errors(argc, argv);
    char *file = mx_file_to_str(argv[1]);
    char **res = mx_parsing_the_file(file);
    
    //    for(int i = 0; res[i] != NULL; ++i) {
    //
    //        printf("%s\n",res[i]);
    //
    //    }
    char **islands = list_of_islands(res);
    //    for(int i = 0; islands[i] != NULL; ++i) {
    //    
    //            printf("%s\n",islands[i]);
    //    
    //        }
    int islands_size = 0;
    for(int i = 0; islands[i] != NULL; i++) {
        islands_size++;
    }
    
    int **matrix = adjacency_matrix(islands, res, islands_size);
    
    
    int i = 0;
    for(int islands_i = 0; islands_i < islands_size; islands_i++) {
        for(int islands_j = 0; islands_j < islands_size; islands_j++) {
            if(islands_i != islands_j) {
                t_node **a = pathfinder_alg(matrix, islands, islands_i, islands_j);
                for(int j = 0; a[j] != NULL; j++) {
                    i++;
                }
            }
        }
    }
    
    
    t_node **res_paths = (t_node **) malloc((i + 1) * sizeof(t_node *));
    for(int j = 0; j < i; j++) {
        res_paths[j] = NULL;
    }
    
    int ii = 0;
    for(int islands_i = 0; islands_i < islands_size; islands_i++) {
        for(int islands_j = 0; islands_j < islands_size; islands_j++) {
            if(islands_i != islands_j) {
                
                t_node **a = pathfinder_alg(matrix, islands, islands_i, islands_j);
                
                for(int j = 0; a[j] != NULL; j++) {
                    res_paths[ii] = (t_node*)malloc(sizeof(t_node));
                    res_paths[ii] = a[j];
                    ii++;
                }
            }
        }
    }
    remove_dupl_get_res(res_paths, i, islands);
    return 0;
}



