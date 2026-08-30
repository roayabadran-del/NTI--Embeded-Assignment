#include <stdio.h>

int main() {
    int arr[100], n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements in the array : ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nElements in array are: ");
    for (i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\n");
    return 0;
}