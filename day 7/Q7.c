#include <stdio.h>

int main()
{
    int potValue;
    int brightness;

    printf("Enter potentiometer value (0-1023): ");
    scanf("%d", &potValue);

    brightness = (potValue * 255) / 1023;

    printf("Brightness = %d\n", brightness);

    return 0;
}