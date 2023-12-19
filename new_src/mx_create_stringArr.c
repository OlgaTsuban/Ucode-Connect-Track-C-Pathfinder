#include "../inc/pathfinder.h"

char** create_string_array(int range, char** str) {
    char** outcome = (char**)malloc(range * sizeof(char*));

    if (outcome != NULL) {
        for (int i = 0; i < range; i++) {
            outcome[i] = mx_strdup(str[0]);
            if (outcome[i] == NULL) {
                // Handle allocation failure
                // You may want to free previously allocated memory here before returning
                for (int j = 0; j < i; j++) {
                    free(outcome[j]);
                }
                free(outcome);
                return NULL;
            }
        }
    }
    return outcome;
}


