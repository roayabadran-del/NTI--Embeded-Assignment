#include <stdio.h>

int main()
{
    int arr[100];
    int size;
    int i, j;
    int minIndex;
    int temp;

    printf("Enter size: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    printf("Sorted array: ");

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}