#include <stdio.h>

int main() {
    char str[200], result[200];
    int i, j = 0;
    int prevWasSpace = 0;

    printf("Enter some text\n");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            if (!prevWasSpace && j != 0)
                result[j++] = ' ';
            prevWasSpace = 1;
        } else if (str[i] == '\n') {
            break;
        } else {
            result[j++] = str[i];
            prevWasSpace = 0;
        }
    }
    if (j > 0 && result[j - 1] == ' ')
        j--;
    result[j] = '\0';

    printf("Text after removing blanks\n%s\n", result);
    return 0;
}