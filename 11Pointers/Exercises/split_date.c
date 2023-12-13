

#include <stdio.h>

#define MONTHS_IN_YEAR  12

void split_date (int day_of_year, int year, int *month, int *day);

int main (void)
{
    int day_of_year, year, month = 0, day = 0;
    printf("Enter a day of year (1-366): ");
    scanf("%d", &day_of_year);
    printf("Enter a year: ");
    scanf("%d", &year);

    split_date(day_of_year, year, &month, &day);

    printf("\nDay: %d Month: %d Year: %d", day, month, year);

    return 0;
}

/**
 * Day of year is an integer between 1 and 366, specifying a particular
 * day within the year. Month and day point to variables in which the 
 * function will store the equivalent month (1-12) and day within 
 * that month (1-31)
 * 
 * day_of_year = 100,  69, 41, 11
*/
void split_date (int day_of_year, int year, int *month, int *day)
{
    int dayNumbers[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i;
    int dayCount = 0;

    for (i = 0; i < MONTHS_IN_YEAR; i++)
    {
        day_of_year -= dayNumbers[i];

        if (day_of_year <= 0)
        {
            *month = 1;
            *day = dayNumbers[0];
            break;
        }

        else 
        {
            if (day_of_year < dayNumbers[i + 1])
            {
                *day = day_of_year;
                *month += (i + 2) % MONTHS_IN_YEAR;
                break;
            }

        }
    }

    // Adjust for leap years, assuming they are divisible by 4
    if ((year % 4 == 0 && *month > 2)  && (year % 100 != 0 || year % 400 == 0))
    {
        dayCount++;
        *day += dayCount;
    }

}