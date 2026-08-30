#include <stdio.h>
int main() {
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);

    if ((n >> 31) & 1)
        printf("MSB of %d is set (1).\n", n);
    else
        printf("MSB of %d is unset (0).\n", n);

    return 0;
}