#include <stdio.h>
int main() {
    int n, count = 0, i;
    printf("Enter any number: ");
    scanf("%d", &n);

    for (i = 31; i >= 0; i--) {
        if ((n >> i) & 1)
            break;
        count++;
    }

    printf("Total number of leading zeros in %d is %d\n", n, count);

    return 0;
}