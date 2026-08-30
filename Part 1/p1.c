#include <stdio.h>
int main() {
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);

    if (n & 1)
        printf("LSB of %d is set (1).\n", n);
    else
        printf("LSB of %d is unset (0).\n", n);

    return 0;
}