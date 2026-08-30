#include <stdio.h>

int getMax(int n)
{
    static int max = 0;

    if (n > max)
        max = n;

    return max;
}

int main()
{
    int n;

    printf("Enter numbers, -1 to stop:\n");

    while (1)
    {
        scanf("%d", &n);

        if (n == -1)
            break;

        printf("Max = %d\n", getMax(n));
    }

    return 0;
}