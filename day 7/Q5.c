#include <stdio.h>

int main()
{
    int LED = 0;

    printf("LED before toggle = %d\n", LED);

    LED = !LED;

    printf("LED after toggle = %d\n", LED);

    return 0;
}