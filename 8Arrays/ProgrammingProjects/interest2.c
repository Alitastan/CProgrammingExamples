/* Prints a table of compound interest */

#include <stdio.h>

#define NUM_RATES           ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE     100.00

int main (void)
{
    int interestRate, numberOfYears, i, year, month;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &interestRate);
    printf("Enter number of years: ");
    scanf("%d", &numberOfYears);

    printf("\nYears");


    for (i = 0; i < NUM_RATES; i++)
    {
        printf("%6d%%", interestRate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");
    for (year = 1; year <= numberOfYears; year++)
    {
        printf("%3d   ", year);

        for (i = 0; i < NUM_RATES; i++)
        {
            for (month = 1; month <= 12; month++)
            {
                value[i] += ( (double)(interestRate + i) / 12 ) / 100.00 * value[i];
            }    

            printf("%7.2f", value[i]);
        }

        printf("\n");
    }

    return 0;
}