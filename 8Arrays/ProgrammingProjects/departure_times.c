/*  
*   Modify Programming Project 8 from Chapter 5
*   so that the departure times are stored in an
*   array and the arrival times are stored in a second
*   array. (The times are integers, representing the number
*   of minutes since midnight.) The program will use a loop
*   to search the array of departure times for the one closest
*   to the time entered by the user.
*/

#include <stdio.h>
#include <math.h>


#define DEPARTURE   8   
#define ARRIVAL     8


int main (void)
{
    /* Departure and arrival times in minutes since midnight */
    int departureTimes[DEPARTURE] = {8 * 60, 9 * 60 + 43, 11 * 60 + 19,
                                    12 * 60 + 47, 14 * 60, 15 * 60 + 45,
                                    19 * 60, 21 * 60 + 45};
    int arrivalTimes[ARRIVAL] = {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31,
                                15 * 60, 16 * 60 + 8, 17 * 60 + 55,
                                21 * 60 + 20, 23 * 60 + 58};

    int hour, minute, userInputInMinutes;
    int timeDifference = 0, departure = 0, arrival = 0;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);

    if (hour == 0 && minute < 60)
    {
        userInputInMinutes = minute;

        printf("00:%.2d AM\n", minute);
        printf("User input in minutes: %d\n", userInputInMinutes);
    }
    else if (hour < 12 && minute < 60)
    {
        userInputInMinutes = hour * 60 + minute;
        printf("%.2d:%.2d AM\n", hour, minute);
        printf("User input in minutes: %d\n", userInputInMinutes);
        
    }
    else if (hour < 24 && minute < 60)
    {
        userInputInMinutes = hour * 60 + minute;
        printf("%d:%.2d PM\n", hour - 12 , minute);
        printf("User input in minutes: %d\n", userInputInMinutes);
    }
    else printf("Invalid value.\n");

    // Find the departure time by comparing the user input
    for (int i = 0; i < DEPARTURE; i++)
    {
        
        timeDifference = abs(userInputInMinutes - departureTimes[i]);
        if (timeDifference < abs(userInputInMinutes - departureTimes[i + 1]))
        {
            // Match the departure time with the corresponding arrival time.
            departure = departureTimes[i];
            //printf("Departure time: %d\n", departure);
            arrival = arrivalTimes[i];
            //printf("Arrival time: %d\n", arrival);
            break;
        }  

    }

    printf("Closest departure time is %.2d:%.2d | Arriving at: %.2d:%.2d", departure / 60, departure % 60,
                                                    arrival / 60,  arrival % 60);

    

}