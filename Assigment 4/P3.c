#include <stdio.h>

int main() {
    int arr[100], evenArr[100], oddArr[100];
    int n, i, ec = 0, oc = 0;

    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter elements in the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            evenArr[ec++] = arr[i];
        else
            oddArr[oc++] = arr[i];
    }

    printf("\nElements of even array:\n");
    printf("Elements in the array: ");
    for (i = 0; i < ec; i++)
        printf("%d ", evenArr[i]);

    printf("\n\nElements of odd array:\n");
    printf("Elements in the array: ");
    for (i = 0; i < oc; i++)
        printf("%d ", oddArr[i]);
    printf("\n");
    return 0;
}