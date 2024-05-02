/**
 * Modify Programming Project 8 from Chapter 5 so that the
 * times are stored in a single array. The elements of the
 * array will be structures, each containing a departure time
 * and the corresponding arrival time. (Each time will be an
 * integer, representing the number of minutes since midnight.)
 * The program will use a loop to search the array for the
 * departure time closest to the time entered by the user.
*/

#include <stdio.h>

#define FLIGHT_NUM 8

struct time
{
    int departure;
    int arrival;
};

int main (void)
{
    int hour, minute, userInputInMinutes;
    int i;

    const struct time flight[FLIGHT_NUM] =
    {
        {8 * 60, 10 * 60 + 16},
        {9 * 60 + 43, 11 * 60 + 52},
        {11 * 60 + 19, 13 * 60 + 31},
        {12 * 60 + 47, 15 * 60},
        {14 * 60, 16 * 60 + 8},
        {15 * 60 + 45, 17 * 60 + 55},
        {19 * 60, 21 * 60 + 20},
        {21 * 60 + 45, 23 * 60 + 58}
    };


    printf("Enter your 24-hour departure time: ");
    scanf("%d :%d", &hour, &minute);

    if (hour == 0 && minute < 60)
    {
        userInputInMinutes = minute;
        printf("00:%.2d AM\n", minute);
    }
    else if (hour < 12 && minute < 60)
    {
        userInputInMinutes = hour * 60 + minute;
        printf("%.2d:%.2d AM\n", hour, minute);
    }
    else if (hour < 24 && minute < 60)
    {
        userInputInMinutes = hour * 60 + minute;
        printf("%d:%.2d PM\n", hour - 12 , minute);
    }
    else printf("Invalid value.");


    for (i = 0; i < FLIGHT_NUM; i++)
    {
        if (userInputInMinutes < flight[i].departure)
        {
            printf("\nClosest departure time is %.2d:%.2d ",
            flight[i].departure / 60, flight[i].departure % 60);
            printf("Arriving at %.2d:%.2d\n",
            flight[i].arrival / 60, flight[i].arrival % 60);
            return 0;
        }
            
    }

    printf("There is no flight until tomorrow!\n");

    return 0;

}