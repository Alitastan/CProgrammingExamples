#include <stdio.h>

int main (void)
{
    int day, month, year;

    int earliestDay, earliestMonth, earliestYear;

    printf("Enter a date (dd / mm / yyyy): ");
    scanf("%d /%d /%d", &day, &month, &year);

    earliestDay = day; earliestMonth = month; earliestYear = year;

    while (day || month || year)
    {

        if (year <= earliestYear || month <= earliestMonth || day <= earliestDay)
        {
            earliestDay = day;
            earliestMonth = month;
            earliestYear = year; 
        }

        printf("Enter a date (dd / mm / yyyy): ");
        scanf("%d /%d /%d", &day, &month, &year);
    }
    printf(" %.2d/%.2d/%d is the earliest date\n",
                earliestDay, earliestMonth, earliestYear);

    return 0;
}