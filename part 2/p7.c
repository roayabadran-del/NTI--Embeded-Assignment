#include <stdio.h>
int main() {
    char op;
    float a, b, result;

    printf("Enter an operator (+, -, *,/): ");
    scanf(" %c", &op);
    printf("Enter two operands: ");
    scanf("%f %f", &a, &b);

    switch (op) {
        case '+':
            result = a + b;
            printf("%.1f + %.1f = %.1f\n", a, b, result);
            break;
        case '-':
            result = a - b;
            printf("%.1f - %.1f = %.1f\n", a, b, result);
            break;
        case '*':
            result = a * b;
            printf("%.1f * %.1f = %.1f\n", a, b, result);
            break;
        case '/':
            if (b != 0) {
                result = a / b;
                printf("%.1f / %.1f = %.1f\n", a, b, result);
            } else {
                printf("Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid operator.\n");
    }

    return 0;
}
