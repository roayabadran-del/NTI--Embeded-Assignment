#include <stdio.h>

int main() {
    int arr[100], n, i, sum = 0, expectedSum;

    /* "size" here is the range 1..n; only (n-1) numbers are entered
       because exactly one number in that range is missing */
    printf("Enter size of array : ");
    scanf("%d", &n);
    printf("Enter elements into array :\n");
    for (i = 0; i < n - 1; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n - 1; i++)
        sum += arr[i];

    expectedSum = n * (n + 1) / 2;

    printf("Missing element is : %d\n", expectedSum - sum);
    return 0;
}