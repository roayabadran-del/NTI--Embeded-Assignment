#include <stdio.h>

int main()
{
    unsigned char value;
    int position;

    printf("Enter value: ");
    scanf("%hhu", &value);

    printf("Enter bit position (0-7): ");
    scanf("%d", &position);

    value = value ^ (1 << position);

    printf("Result = %u\n", value);

    return 0;
}