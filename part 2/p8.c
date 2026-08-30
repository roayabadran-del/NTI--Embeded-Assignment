#include <stdio.h>
int main() {
    float cp, sp, diff;
    printf("Enter cost price: ");
    scanf("%f", &cp);
    printf("Enter selling price: ");
    scanf("%f", &sp);

    if (sp > cp) {
        diff = sp - cp;
        printf("Profit = %.0f\n", diff);
    } else if (cp > sp) {
        diff = cp - sp;
        printf("Loss = %.0f\n", diff);
    } else {
        printf("No profit no loss\n");
    }

    return 0;
}