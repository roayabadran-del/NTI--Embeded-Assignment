#include <stdio.h>

int main()
{
    int arr[100];
    int size;
    int target;
    int i, j = 0;

    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter array:\n");

    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    for (i = 0; i < size; i++)
    {
        if (arr[i] != target)
        {
            arr[j] = arr[i];
            j++;
        }
    }

    while (j < size)
    {
        arr[j] = target;
        j++;
    }

    printf("Result: ");

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}