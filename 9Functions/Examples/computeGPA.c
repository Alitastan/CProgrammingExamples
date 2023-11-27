
#include <stdio.h>
#include <ctype.h>

#define GRADE_NUM   5

float computeGPA (char grades[], int n);

int main (void)
{
    char grade[GRADE_NUM] = {};

    printf("Enter grade letter A, B, C, D or F:  ");

    for (int i = 0; i < GRADE_NUM; i++)
        scanf(" %c", &grade[i]);

    printf ("Computed average: %f\n", computeGPA(grade, GRADE_NUM));
}


float computeGPA (char grades[], int n)
{
    float grade = 0.0f;

    for (int i = 0; i < n; i++)
    {
        switch (toupper(grades[i]))
        {
            case 'A':
                grade += 4.0f;
                break;
            case 'B':
                grade += 3.0f;
                break;
            case 'C':
                grade += 2.0f;
                break;
            case 'D':
                grade += 1.0f;
                break;
            default:
                grade += 0.0f;
                break;
        }
    }

    return grade / n;
}