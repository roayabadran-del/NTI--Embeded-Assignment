#include <stdio.h>

int main() {
    int array1[20] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int array2[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n1 = 10, n2 = 10;
    int i, k, pos;

    for (i = 0; i < n2; i++) {
        /* find where array2[i] belongs inside array1 */
        for (pos = 0; pos < n1; pos++) {
            if (array2[i] < array1[pos])
                break;
        }
        /* shift everything from pos onward one step right */
        for (k = n1; k > pos; k--)
            array1[k] = array1[k - 1];

        array1[pos] = array2[i];
        n1++;
    }

    for (i = 0; i < n1; i++)
        printf("%d ", array1[i]);
    printf("\n");
    return 0;
}