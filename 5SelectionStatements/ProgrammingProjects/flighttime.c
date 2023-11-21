#include <stdio.h>


int main (void)
{
    // userInputInMinutes is calculating minutes since midnight.

    int hour, minute, userInputInMinutes;

    int departureTime1 = 8 * 60;
    int departureTime2 = 9 * 60 + 43;
    int departureTime3 = 11 * 60 + 19;
    int departureTime4 = 12 * 60 + 47;
    int departureTime5 = 14 * 60 + 0;
    int departureTime6 = 15 * 60 + 45;
    int departureTime7 = 19 * 60 + 0;
    int departureTime8 = 21 * 60 + 45;

  
    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);

    if (hour == 0 && minute < 60)
    {
        userInputInMinutes = minute;

        printf("00:%.2d AM\n", minute);
        printf("User input in minutes: %d", userInputInMinutes);
    }
    else if (hour < 12 && minute < 60)
    {
        userInputInMinutes = hour * 60 + minute;
        printf("%.2d:%.2d AM\n", hour, minute);
        printf("User input in minutes: %d", userInputInMinutes);
        
    }
    else if (hour < 24 && minute < 60)
    {
        userInputInMinutes = hour * 60 + minute;
        printf("%d:%.2d PM\n", hour - 12 , minute);
        printf("User input in minutes: %d", userInputInMinutes);
    }
    else printf("Invalid value.");

    if (userInputInMinutes < departureTime1)
    {
        printf("\nClosest departure time is 08:00 AM. Arriving at 10:16 AM\n");
    
    }
    else if (userInputInMinutes < departureTime2)
    {
        printf("\nClosest departure time is 09:43 AM. Arriving at 11:52 AM\n");
    }
    else if (userInputInMinutes < departureTime3)
    {
        printf("\nClosest departure time is 11:19 AM. Arriving at 1:31 PM\n");
    }
    else if (userInputInMinutes < departureTime4)
    {
        printf("\nClosest departure time is 12:47 PM. Arriving at 3:00 PM\n");
    }
    else if (userInputInMinutes < departureTime5)
    {
        printf("\nClosest departure time is 2:00 PM. Arriving at 4:38 PM\n");
    }
    else if (userInputInMinutes < departureTime6)
    {
        printf("\nClosest departure time is 3:45 PM. Arriving at 5:55 PM\n");
    }
    else if (userInputInMinutes < departureTime7)
    {
        printf("\nClosest departure time is 7:00 PM. Arriving at 9:20 PM\n");
    }
    else if (userInputInMinutes < departureTime8)
    {
        printf("\nClosest departure time is 9:45 PM. Arriving at 11:58 PM\n");
    }
    else printf("\nThere is no flight.");
}
