#include <stdio.h>
int main() {
    int n, flipped;
    printf("Enter any number: ");
    scanf("%d", &n);

    printf("Original number = %d (in decimal)\n", n);

    flipped = ~n;

    printf("Number after bits are flipped = %d (in decimal)\n", flipped);

    return 0;
}