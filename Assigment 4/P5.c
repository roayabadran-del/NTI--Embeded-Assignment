#include <stdio.h>

int main() {
    int arr[100], temp[100];
    int size, n, i;

    printf("Enter 10 elements array: ");
    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);
    size = 10;

    printf("Enter number of times to right rotate: ");
    scanf("%d", &n);

    printf("Array before rotation:");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    n = n % size;

    for (i = 0; i < n; i++)
        temp[i] = arr[size - n + i];

    for (i = size - 1; i >= n; i--)
        arr[i] = arr[i - n];

    for (i = 0; i < n; i++)
        arr[i] = temp[i];

    printf("\nArray after rotation\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}