/*  Write a declaration for a two-dimensional array named temperatureReadings    
*   that stores one month of hourly temperature readings. Then use that array
*   compute the average temperature for a month (avereaged over all days of the
*   month and all hours of the day). */

#include <stdio.h>

#define DAYS_IN_A_MONTH 30
#define HOURS_IN_A_DAY  24
#define TOTAL_HOURS     (DAYS_IN_A_MONTH * HOURS_IN_A_DAY)

int main (void)
{

    int row, column;
    double sum = 0.0, average = 0.0;
    double temperatureReadings[DAYS_IN_A_MONTH][HOURS_IN_A_DAY] = {0};

    // Initialize all elements in temperatureReadings to 25.0
    for (row = 0; row < DAYS_IN_A_MONTH; row++)
        for (column = 0; column < HOURS_IN_A_DAY; column++)
            temperatureReadings[row][column] = 25.0;

    for (row = 0; row < DAYS_IN_A_MONTH; row++)
        for (column = 0; column < HOURS_IN_A_DAY; column++)
            sum += temperatureReadings[row][column];

    average = sum / TOTAL_HOURS;
    printf("Average: %f", average);

}