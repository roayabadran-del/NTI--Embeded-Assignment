#include <stdio.h>
int main() {
    int num, rot;
    unsigned char n, left, right;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter number of rotation: ");
    scanf("%d", &rot);

    n = (unsigned char)num;

    left  = (n << rot) | (n >> (8 - rot));
    right = (n >> rot) | (n << (8 - rot));

    printf("%d left rotated %d times = %d\n\n", num, rot, left);
    printf("%d right rotated %d times = %d\n", num, rot, right);

    return 0;
}