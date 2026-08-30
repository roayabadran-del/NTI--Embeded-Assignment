#include <stdio.h>

int main()
{
    unsigned char frame[10];
    int i;
    int sum = 0;
    int received;

    printf("Enter 8 bytes:\n");

    for (i = 0; i < 8; i++)
    {
        scanf("%hhu", &frame[i]);
        sum += frame[i];
    }

    frame[8] = (sum >> 8) & 0xFF;
    frame[9] = sum & 0xFF;

    received = (frame[8] << 8) | frame[9];

    printf("Frame:\n");

    for (i = 0; i < 10; i++)
        printf("%u ", frame[i]);

    if (sum == received)
        printf("\nChecksum is correct\n");
    else
        printf("\nChecksum is wrong\n");

    return 0;
}