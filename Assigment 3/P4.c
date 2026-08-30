#include <stdio.h>

int main() {
    int arr[1000], n, i;
    printf("Enter size of the array (1-1000): ");
    scanf("%d", &n);
    printf("Enter elements in the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int first, second;
    first = second = -2147483647; /* very small number */

    for (i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    printf("First largest = %d\n", first);
    printf("Second largest = %d\n", second);
    return 0;
}