#include <stdio.h>

int countCalls()
{
    static int count = 0;

    count++;

    return count;
}

int main()
{
    printf("%d\n", countCalls());
    printf("%d\n", countCalls());
    printf("%d\n", countCalls());

    return 0;
}