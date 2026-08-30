#include <stdio.h>

int main() {
    char str[200];
    char ch;
    int i, count = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter a character to find the frequency: ");
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch)
            count++;
    }

    printf("Frequency of %c = %d\n", ch, count);
    return 0;
}