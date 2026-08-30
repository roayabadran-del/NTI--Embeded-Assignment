#include <stdio.h>

int main()
{
    int arr[100];
    int size, i;
    int sum = 0;
    float average;

    printf("Enter size: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = (float)sum / size;

    printf("Average = %.2f\n", average);

    return 0;
}