#include <stdio.h>

int IsPrime(int number);

int main()
{
    int num1, num2;

    printf("Enter first integer: ");
    scanf("%d", &num1);

    printf("Enter second integer: ");
    scanf("%d", &num2);

    if (IsPrime(num1))
    {
        printf("%d is Prime\n", num1);
    }
    else
    {
        printf("%d is Not Prime\n", num1);
    }

    if (IsPrime(num2))
    {
        printf("%d is Prime\n", num2);
    }
    else
    {
        printf("%d is Not Prime\n", num2);
    }

    return 0;
}

int IsPrime(int number)
{
    int i;

    if (number <= 1)
    {
        return 0; // not prime
    }

    for (i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return 0; // not prime
        }
    }

    return 1; // prime
}