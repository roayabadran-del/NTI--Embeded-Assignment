#include <stdio.h>

int main()
{
    int value;
    int position;
    int choice;

    printf("Enter value: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &position);

    printf("1. Set bit\n");
    printf("2. Clear bit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        value = value | (1 << position);
    else if (choice == 2)
        value = value & ~(1 << position);

    printf("Result = %d\n", value);

    return 0;
}