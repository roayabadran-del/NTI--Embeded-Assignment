#include <stdio.h>

int main() {
    int arr[100], n, i;
    printf("enter the element of an array\n");
    printf("Enter how many elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Alternate elements of a given array\n");
    for (i = 0; i < n; i += 2)
        printf("%d\n", arr[i]);
    return 0;
}