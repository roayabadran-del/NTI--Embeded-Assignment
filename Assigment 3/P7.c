#include <stdio.h>

int main() {
    int a[100], b[100], c[200];
    int n1, n2, i, j, k;

    printf("Input number of elements in first array\n");
    scanf("%d", &n1);
    printf("Input %d integers\n", n1);
    for (i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    printf("Input number of elements in second array\n");
    scanf("%d", &n2);
    printf("Input %d integers\n", n2);
    for (i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    i = j = k = 0;

    /* merge while both arrays have elements left */
    while (i < n1 && j < n2) {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    /* copy remaining elements, if any */
    while (i < n1)
        c[k++] = a[i++];
    while (j < n2)
        c[k++] = b[j++];

    printf("Sorted array:\n");
    for (i = 0; i < k; i++)
        printf("%d\n", c[i]);
    return 0;
}