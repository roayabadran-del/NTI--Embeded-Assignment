#include <stdio.h>

int main()
{
    int arr[101];
    int count[101] = {0};
    int i;
    int repeated = -1;

    printf("Enter 101 numbers from 1 to 100:\n");

    for (i = 0; i < 101; i++)
    {
        scanf("%d", &arr[i]);

        count[arr[i]]++;

        if (count[arr[i]] == 2)
        {
            repeated = arr[i];
            break;
        }
    }

    printf("Repeated number = %d\n", repeated);

    return 0;
}