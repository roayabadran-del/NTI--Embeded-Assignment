#include <stdio.h>
int main() {
    int a[5], i;

    printf("enter the five number:\n");
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    printf("\nthe numbers that is divisable by 3 is :\n");
    for (i = 0; i < 5; i++) {
        if (a[i] % 3 == 0)
            printf("%d\n", a[i]);
    }

    return 0;
}