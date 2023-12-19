#include "../inc/pathfinder.h"

// Function to filter duplicates and numeric strings from an array of strings
char** filter_and_copy_strings(int amount, int index, bool was, char** outcome, char** str) {
    if (outcome != NULL) {
        for (int i = 0; i < amount; i++) {
            for (int j = 0; j < amount; j++) {
                if (mx_strcmp(str[i], outcome[j]) == 0 || mx_isdigit(str[i][0])) {
                    was = true;
                    break;
                }
            }

            if (!was) {
                outcome[index] = mx_strdup(str[i]);
                index++;
            }
            was = false;
        }
    }
    return outcome;
}


