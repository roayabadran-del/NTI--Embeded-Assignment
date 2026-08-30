#include <stdio.h>

int main() {
    char str1[200], str2[200];
    int i, j, len1;

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    len1 = 0;
    while (str1[len1] != '\0')
        len1++;

    for (i = len1, j = 0; str2[j] != '\0'; i++, j++)
        str1[i] = str2[j];
    str1[i] = '\0';

    printf("After concatenation: %s\n", str1);
    return 0;
}