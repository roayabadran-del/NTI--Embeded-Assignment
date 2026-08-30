#include <stdio.h>

int main() {
    int arr[100], n, i, sum = 0;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter %d elements in the array: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n; i++)
        sum += arr[i];

    printf("Sum of all elements of array = %d\n", sum);
    return 0;
}