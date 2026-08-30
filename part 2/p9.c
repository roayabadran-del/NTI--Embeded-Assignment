#include <stdio.h>
int main() {
    float basic, hra, da, gross;
    printf("Enter basic salary of an employee: ");
    scanf("%f", &basic);

    if (basic <= 10000) {
        hra = basic * 0.20;
        da = basic * 0.80;
    } else if (basic <= 20000) {
        hra = basic * 0.25;
        da = basic * 0.90;
    } else {
        hra = basic * 0.30;
        da = basic * 0.95;
    }

    gross = basic + hra + da;
    printf("GROSS SALARY OF EMPLOYEE = %.2f\n", gross);

    return 0;
}