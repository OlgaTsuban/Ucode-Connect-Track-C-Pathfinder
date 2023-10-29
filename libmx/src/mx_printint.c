#include "../inc/libmx.h"

void mx_printint(int n) {
    char ar[50];
    int i = 0;
    if (n == 0) mx_printchar('0');
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
    }
    if (n < 0 && n != -2147483648) {
        n *= -1;
        mx_printchar('-');
    }
    while (n != 0 && n != -2147483648) {
        ar[i++] = n % 10 + '0';
        n /= 10;
    }
    for (int k = i - 1; k >= 0; k--) {
        mx_printchar(ar[k]);
    }
}


