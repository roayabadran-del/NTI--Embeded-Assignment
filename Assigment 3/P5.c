#include <stdio.h>

int main() {
    int arr[100], n, i, evenCount = 0, oddCount = 0;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter %d elements in array: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    printf("Total even elements: %d\n", evenCount);
    printf("Total odd elements: %d\n", oddCount);
    return 0;
}