#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;

    int *p1 = &a;
    int *p2 = &b;
    int *temp;

    temp = p1;
    p1 = p2;
    p2 = temp;

    printf("p1 points to: %d\n", *p1);
    printf("p2 points to: %d\n", *p2);

    return 0;
}