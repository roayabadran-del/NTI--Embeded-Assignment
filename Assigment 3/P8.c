#include <stdio.h>

int main() {
    int arr[100], n, i, pos;

    printf("Enter number of elements in array\n");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the location where you wish to delete element\n");
    scanf("%d", &pos);

    if (pos > n) {
        printf("Deletion not possible.\n");
        return 0;
    }

    /* shift elements left, starting at the deleted position */
    for (i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    printf("Resultant array is\n");
    for (i = 0; i < n - 1; i++)
        printf("%d\n", arr[i]);
    return 0;
}