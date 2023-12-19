#include "../inc/pathfinder.h"

int count_newlines(const char* inform) {
    int lin_num = 0;
    for (int i = 0; inform[i] != '\0'; i++) {
        if (inform[i] == '\n') {
            lin_num++;
        }
    }
    return lin_num;
}


