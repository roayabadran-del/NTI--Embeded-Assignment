#include <stdio.h>

int main() {
    int arr[100], n, i, pos, value;
    printf("Enter size of the array : ");
    scanf("%d", &n);
    printf("Enter elements in array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to insert : ");
    scanf("%d", &value);
    printf("Enter the element position : ");
    scanf("%d", &pos);

    /* shift elements to the right starting from the end */
    for (i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = value;
    n++; /* array now has one more element */

    printf("Array elements after insertion : ");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    return 0;
}