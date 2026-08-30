#include <stdio.h>

int main() {
    int age, count = 0;
    int baby = 0, school = 0, adult = 0;

    printf("Enter 15 an age\n: ");

    while (count < 15) {
        scanf("%d", &age);

        if (age >= 0 && age <= 5)
            baby++;
        else if (age >= 6 && age <= 17)
            school++;
        else if (age >= 18)
            adult++;

        count++;
    }

    printf("\n numbers of Still a baby:%d\n", baby);
    printf(" numbers of Attending school :%d\n", school);
    printf(" numbers of dult life :%d\n", adult);
    return 0;
}