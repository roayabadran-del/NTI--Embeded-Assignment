#include <stdio.h>
int main() {
    int n, i;
    printf("Input the number (Table to be calculated) : ");
    scanf("%d", &n);

    printf("\n");
    for (i = 1; i <= 10; i++) {
        printf("%d X %d = %d\n", n, i, n * i);
    }

    return 0;
}