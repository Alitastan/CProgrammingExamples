#include <stdio.h>


int dayOfYear (int day, int month, int year);

int main (void)
{
    printf("The day of the year: %d\n", dayOfYear(15,3,1997));
}

int dayOfYear (int day, int month, int year)
{
    int dayNumbers[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayCount = 0;
    int i;

    for (i = 1; i < month; i++)
    {
        dayCount += dayNumbers[i - 1];
    }

    // Adjust for leap years, assuming they are divisible by 4
    if ((year % 4 == 0 && month > 2)  && (year % 100 != 0 || year % 400 == 0))
        dayCount++;
    
    return dayCount + day;

}