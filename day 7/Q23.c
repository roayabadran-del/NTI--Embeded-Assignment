#include <stdio.h>

int main()
{
    unsigned int n;
    int i;
    int gap = 0;
    int maxGap = 0;
    int foundOne = 0;

    printf("Enter number: ");
    scanf("%u", &n);

    for (i = 31; i >= 0; i--)
    {
        if (n & (1U << i))
        {
            if (foundOne && gap > maxGap)
                maxGap = gap;

            gap = 0;
            foundOne = 1;
        }
        else if (foundOne)
        {
            gap++;
        }
    }

    printf("Maximum zeros = %d\n", maxGap);

    return 0;
}