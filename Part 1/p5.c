#include <stdio.h>
int main() {
    int n, pos;
    printf("Enter any number: ");
    scanf("%d", &n);
    printf("Enter nth bit to clear (0-31): ");
    scanf("%d", &pos);

    printf("Bit cleared successfully.\n\n");
    printf("Number before clearing %d bit: %d (in decimal)\n", pos, n);

    n = n & ~(1 << pos);

    printf("Number after clearing %d bit: %d (in decimal)\n", pos, n);

    return 0;
}