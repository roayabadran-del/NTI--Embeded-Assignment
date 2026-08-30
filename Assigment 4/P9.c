#include <stdio.h>

int main() {
    char str[200];
    int length = 0;
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
        length++;

    printf("Length of string: %d\n", length);
    return 0;
}