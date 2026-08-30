#include <stdio.h>

int main()
{
    int src[100];
    int dest[100];
    int seen[1000] = {0};

    int size, i, j = 0;

    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter elements:\n");

    for (i = 0; i < size; i++)
        scanf("%d", &src[i]);

    for (i = 0; i < size; i++)
    {
        if (seen[src[i]] == 0)
        {
            seen[src[i]] = 1;
            dest[j] = src[i];
            j++;
        }
    }

    printf("Unique elements: ");

    for (i = 0; i < j; i++)
        printf("%d ", dest[i]);

    return 0;
}