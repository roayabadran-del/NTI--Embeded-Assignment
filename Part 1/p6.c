#include <stdio.h>
int main() {
    int n, pos = -1, temp;
    printf("Enter any number: ");
    scanf("%d", &n);

    temp = n;
    while (temp) {
        pos++;
        temp = temp >> 1;
    }

    printf("Highest order set bit in %d is %d\n", n, pos);

    return 0;
}