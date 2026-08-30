#include <stdio.h>

int main()
{
    unsigned char a, b;
    unsigned char result;
    int safeResult;

    printf("Enter two numbers: ");
    scanf("%hhu %hhu", &a, &b);

    result = a + b;
    safeResult = a + b;

    printf("Unsigned char result = %u\n", result);
    printf("Full result = %d\n", safeResult);

    return 0;
}