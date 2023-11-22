/*  Displays date of the users input mm/dd/yyyy as yyyymmdd  */

#include <stdio.h>

int main(void)
{
    int day, month, year;

    printf("Enter a date (mm/dd/yyyy) :");
    scanf("%d / %d / %d", &day, &month, &year);

    printf("You entered the date: %-5d%-3.2d%-3.2d", year, month, day);

    return 0;

}