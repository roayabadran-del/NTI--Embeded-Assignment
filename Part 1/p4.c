#include <stdio.h>
int main() {
    int n, pos;
    printf("Enter any number: ");
    scanf("%d", &n);
    printf("Enter nth bit to set (0-31): ");
    scanf("%d", &pos);

    printf("Bit set successfully.\n\n");
    printf("Number before setting %d bit: %d (in decimal)\n", pos, n);

    n = n | (1 << pos);

    printf("Number after setting %d bit: %d (in decimal)\n", pos, n);

    return 0;
}