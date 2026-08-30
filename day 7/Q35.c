#include <stdio.h>

int main()
{
    int x, y;
    int sum, multiplication;

    printf("Enter x and y: ");
    scanf("%d %d", &x, &y);

    sum = x + y;
    multiplication = x * y;

    printf("Sum = %d\n", sum);
    printf("Multiplication = %d\n", multiplication);

    return 0;
}