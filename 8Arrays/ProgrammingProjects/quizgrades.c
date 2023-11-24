/*  The program promts for five quiz grades 
*   for each students, then computes the total
*   score and average score for each student,
*   and the average score, high score, and low 
*   score for each quiz.
*/

#include <stdio.h>

#define QUIZ_NUMBER     5
#define STUDENT_NUMBER  5



int main (void)
{
    float quizGrades[QUIZ_NUMBER][STUDENT_NUMBER] = {0.0f};

    int quiz, student;

    float total, high, low;

    // Get the results into the array
    for (quiz = 0; quiz < QUIZ_NUMBER; quiz++)
    {
        printf("Enter quiz %d: ", quiz + 1);

        for (student = 0; student < STUDENT_NUMBER; student++)
        {
            scanf("%f", &quizGrades[quiz][student]);
        }
        
    }

    printf("\n");

    printf("\nStudent total average\n");

    for (student = 0; student < STUDENT_NUMBER; student++)
    {
        total = 0.0f;
        printf("%4d    ", student + 1);

        for (quiz = 0; quiz < QUIZ_NUMBER; quiz++)
        {
            total += quizGrades[student][quiz];
        }

        printf("%6.2f     %6.2f\n", total, total / QUIZ_NUMBER );
    }


    printf("\nQuiz average, high and low score\n");

    for (quiz = 0; quiz < QUIZ_NUMBER; quiz++)
    {
        total = 0.0f;
        high = 0.0f;
        low = 100.0f;

        printf("%4d     ", quiz + 1);

        for (student = 0; student < STUDENT_NUMBER; student++)
        {
            total += quizGrades[quiz][student];

            if (quizGrades[quiz][student] > high)
                high = quizGrades[quiz][student];
            if (quizGrades[quiz][student] < low);
                low = quizGrades[quiz][student];
        }

        printf("%6.2f   %6.2f   %6.2f\n", total / STUDENT_NUMBER, high, low);
    }

    return 0;
}