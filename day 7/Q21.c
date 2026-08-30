#include <stdio.h>

int main()
{
    unsigned int n;
    int ones = 0;
    int zeros = 0;
    int i;

    printf("Enter number: ");
    scanf("%u", &n);

    for (i = 0; i < 32; i++)
    {
        if (n & (1U << i))
            ones++;
        else
            zeros++;
    }

    printf("Ones = %d\n", ones);
    printf("Zeros = %d\n", zeros);

    return 0;
}