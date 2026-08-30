#include <stdio.h>

int main() {
    int arr[100], n, i;
    printf("Enter size of the array : ");
    scanf("%d", &n);
    printf("Enter elements in array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nAll negative elements in array are : ");
    for (i = 0; i < n; i++) {
        if (arr[i] < 0)
            printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}