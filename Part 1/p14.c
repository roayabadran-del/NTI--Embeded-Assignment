#include <stdio.h>
int main() {
    int n, i;
    printf("Enter any number: ");
    scanf("%d", &n);

    printf("Converted binary: ");
    for (i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");

    return 0;
}