#include <stdio.h>

int main() {
    int a[100], b[100], c[200];
    int n1, n2, i;

    printf("enter size of array_1: ");
    scanf("%d", &n1);
    printf("enter elements of array_1:\n");
    for (i = 0; i < n1; i++) {
        printf("enter element_%d:", i + 1);
        scanf("%d", &a[i]);
    }

    printf("enter size of array_2: ");
    scanf("%d", &n2);
    printf("enter elements of array_2:\n");
    for (i = 0; i < n2; i++) {
        printf("enter element_%d:", i + 1);
        scanf("%d", &b[i]);
    }

    /* combine (simple concatenation) */
    for (i = 0; i < n1; i++)
        c[i] = a[i];
    for (i = 0; i < n2; i++)
        c[n1 + i] = b[i];

    int total = n1 + n2;
    int median = (c[total / 2 - 1] + c[total / 2]) / 2;

    printf("Median is %d\n", median);
    return 0;
}