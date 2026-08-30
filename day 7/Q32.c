#include <stdio.h>

int main()
{
    unsigned int n;
    int shift;
    unsigned int result;

    printf("Enter number: ");
    scanf("%u", &n);

    printf("Enter shift: ");
    scanf("%d", &shift);

    result = (n << shift) | (n >> (32 - shift));

    printf("Result = %u\n", result);

    return 0;
}