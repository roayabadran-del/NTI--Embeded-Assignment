#include <stdio.h>

int main()
{
    int arr[100];
    int size;
    int i, j;
    int count;
    int maxCount = 0;
    int result;

    printf("Enter size: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    result = arr[0];

    for (i = 0; i < size; i++)
    {
        count = 0;

        for (j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            result = arr[i];
        }
    }

    printf("Most repeated = %d\n", result);

    return 0;
}