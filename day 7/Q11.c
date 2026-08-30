#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    int mid;

    if (low > high)
        return -1;

    mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;

    if (arr[mid] < key)
        return binarySearch(arr, mid + 1, high, key);

    return binarySearch(arr, low, mid - 1, key);
}

int main()
{
    int arr[100];
    int size, key;
    int i, result;

    printf("Enter size: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter key: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, size - 1, key);

    printf("Index = %d\n", result);

    return 0;
}