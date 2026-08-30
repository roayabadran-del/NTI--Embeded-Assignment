#include <stdio.h>
int main() {
    int n, pos, bit;
    printf("Enter any number: ");
    scanf("%d", &n);
    printf("Enter nth bit to check (0-31): ");
    scanf("%d", &pos);

    bit = (n >> pos) & 1;
    printf("The %d bit is set to %d\n", pos, bit);

    return 0;
}