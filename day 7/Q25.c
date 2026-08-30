#include <stdio.h>

int main()
{
    unsigned char n;
    unsigned char result = 0;
    int i;

    printf("Enter number (0-255): ");
    scanf("%hhu", &n);

    for (i = 0; i < 8; i++)
    {
        result = (result << 1) | (n & 1);
        n = n >> 1;
    }

    printf("Reversed = %u\n", result);

    return 0;
}