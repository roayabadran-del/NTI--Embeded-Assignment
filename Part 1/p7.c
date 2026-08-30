#include <stdio.h>
int main() {
    int n, pos = 0, temp;
    printf("Enter any number: ");
    scanf("%d", &n);

    temp = n;
    while ((temp & 1) == 0) {
        pos++;
        temp = temp >> 1;
    }

    printf("Lowest order set bit in %d is %d\n", n, pos);

    return 0;
}