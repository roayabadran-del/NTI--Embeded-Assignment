#include <stdio.h>
#include <string.h>

int main()
{
    char stream[200];
    char pattern[100];

    int i, j;
    int streamLength;
    int patternLength;
    int found = -1;

    printf("Enter stream: ");
    fgets(stream, sizeof(stream), stdin);

    printf("Enter pattern: ");
    fgets(pattern, sizeof(pattern), stdin);

    stream[strcspn(stream, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    streamLength = strlen(stream);
    patternLength = strlen(pattern);

    for (i = 0; i <= streamLength - patternLength; i++)
    {
        j = 0;

        while (j < patternLength &&
               stream[i + j] == pattern[j])
        {
            j++;
        }

        if (j == patternLength)
        {
            found = i;
            break;
        }
    }

    printf("Index = %d\n", found);

    return 0;
}