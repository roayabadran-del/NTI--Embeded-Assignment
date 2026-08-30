#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student
{
    int id;
    int math;
    int language;
    int physics;
    int chemistry;
};

int main()
{
    struct Student students[10];
    int i;
    int studentID;

    srand(time(NULL));

    /* Assign IDs and random grades */
    for (i = 0; i < 10; i++)
    {
        students[i].id = i + 1;

        students[i].math = rand() % 101;
        students[i].language = rand() % 101;
        students[i].physics = rand() % 101;
        students[i].chemistry = rand() % 101;
    }

    printf("Enter Student ID (1-10): ");
    scanf("%d", &studentID);

    if (studentID < 1 || studentID > 10)
    {
        printf("Wrong Student ID!\n");
    }
    else
    {
        i = studentID - 1;

        printf("\nStudent ID: %d\n", students[i].id);
        printf("Math: %d\n", students[i].math);
        printf("Language: %d\n", students[i].language);
        printf("Physics: %d\n", students[i].physics);
        printf("Chemistry: %d\n", students[i].chemistry);
    }

    return 0;
}