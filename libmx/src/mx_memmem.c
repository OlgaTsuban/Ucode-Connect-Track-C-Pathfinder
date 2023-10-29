#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (!big || !little || big_len == 0 || little_len == 0) {
        return NULL;
    }
    unsigned char *b = NULL;
    unsigned char *l = NULL;

    if (big_len > 0 && little_len > 0 && big_len >= little_len) {
        b = (unsigned char *)big;
        l = (unsigned char *)little;
        while (*b) {
            if (mx_memcmp(b, l, little_len - 1) == 0) {
                return b;
        }
            b++;
        }
    }
    return NULL;
}


