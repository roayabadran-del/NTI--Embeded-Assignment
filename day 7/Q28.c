#include <stdio.h>

int main()
{
    int a[100], b[100];
    int size;
    int i, j;
    int found;
    int same = 1;

    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter A:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);

    printf("Enter B:\n");
    for (i = 0; i < size; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < size; i++)
    {
        found = 0;

        for (j = 0; j < size; j++)
        {
            if (a[i] == b[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            same = 0;
            break;
        }
    }

    if (same)
        printf("Same elements\n");
    else
        printf("Different elements\n");

    return 0;
}