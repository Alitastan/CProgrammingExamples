#include <stdio.h>


struct date
{
    int day, month, year;
};

int day_of_year (struct date d)
{
    int dayNumbers[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayCount = 0;
    int i;

    for (i = 1; i < d.month; i++)
    {
        dayCount += dayNumbers[i - 1];
    }

    // Adjust for leap years, assuming they are divisible by 4
    if ((d.year % 4 == 0 && d.month > 2)  && (d.year % 100 != 0 || d.year % 400 == 0))
        dayCount++;
    
    return dayCount + d.day;
}

int compare_dates(struct date d1, struct date d2)
{
    if (day_of_year(d1) < day_of_year(d2))
        return -1;
    else if (day_of_year(d1) > day_of_year(d2))
        return 1;
    else return 0;
}

int main (void)
{
    struct date first_date = {.day = 02, .month = 06, .year = 1998};
    struct date second_date = {.day = 02, .month = 06, .year = 1998};

    printf("Res: %d", compare_dates(first_date,second_date));
}