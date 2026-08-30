#include <stdio.h>
int main() {
    int n, ones = 0, zeros = 0, i;
    printf("Enter any number: ");
    scanf("%d", &n);

    for (i = 0; i < 32; i++) {
        if ((n >> i) & 1)
            ones++;
        else
            zeros++;
    }

    printf("Total zero bit is %d\n", zeros);
    printf("Total one bit is %d\n", ones);

    return 0;
}