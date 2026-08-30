#include <stdio.h>
int main() {
    int amount, n500, n100, n50, n20, n10, n5, n2, n1;
    printf("Enter amount: ");
    scanf("%d", &amount);

    n500 = amount / 500; amount %= 500;
    n100 = amount / 100; amount %= 100;
    n50  = amount / 50;  amount %= 50;
    n20  = amount / 20;  amount %= 20;
    n10  = amount / 10;  amount %= 10;
    n5   = amount / 5;   amount %= 5;
    n2   = amount / 2;   amount %= 2;
    n1   = amount;

    printf("Total number of notes = \n");
    printf("500 = %d\n", n500);
    printf("100 = %d\n", n100);
    printf("50 = %d\n", n50);
    printf("20 = %d\n", n20);
    printf("10 = %d\n", n10);
    printf("5 = %d\n", n5);
    printf("2 = %d\n", n2);
    printf("1 = %d\n\n", n1);

    return 0;
}