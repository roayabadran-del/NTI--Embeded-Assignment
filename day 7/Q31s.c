#include <stdio.h>

int main()
{
    unsigned char n;
    unsigned char result;

    printf("Enter number (0-255): ");
    scanf("%hhu", &n);

    result = (n << 4) | (n >> 4);

    printf("Result = %u\n", result);

    return 0;
}