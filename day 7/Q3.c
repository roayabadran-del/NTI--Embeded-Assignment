#include <stdio.h>

int main()
{
    int x[5], y[5];
    int i, temp;

    printf("Enter array X:\n");
    for (i = 0; i < 5; i++)
        scanf("%d", &x[i]);

    printf("Enter array Y:\n");
    for (i = 0; i < 5; i++)
        scanf("%d", &y[i]);

    for (i = 0; i < 5; i++)
    {
        temp = x[i];
        x[i] = y[i];
        y[i] = temp;
    }

    printf("X: ");
    for (i = 0; i < 5; i++)
        printf("%d ", x[i]);

    printf("\nY: ");
    for (i = 0; i < 5; i++)
        printf("%d ", y[i]);

    return 0;
}