#include <stdio.h>

int main()
{
    int arr[100];
    int size, key;
    int low, high, mid;
    int i;
    int found = -1;

    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter sorted array:\n");

    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter key: ");
    scanf("%d", &key);

    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            found = mid;
            break;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Index = %d\n", found);

    return 0;
}