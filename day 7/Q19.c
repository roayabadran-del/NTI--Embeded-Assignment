#include <stdio.h>

int main()
{
    int arr[100];
    int size;
    int i;

    int max, min;
    int maxIndex, minIndex;

    printf("Enter size: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    max = min = arr[0];
    maxIndex = minIndex = 0;

    for (i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }

        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
    }

    printf("Max = %d, Index = %d\n", max, maxIndex);
    printf("Min = %d, Index = %d\n", min, minIndex);

    return 0;
}