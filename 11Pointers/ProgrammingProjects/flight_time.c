

#include <stdio.h>
#include <math.h>

#define DEPARTURE   8   
#define ARRIVAL     8


void find_closest_flight (int desired_time, int *departure_time, int *arrival_time);

int main (void)
{

    int desired_flight_in_minutes, departure_time, arrival_time;
    printf("Enter desired time flight: ");
    scanf("%d", &desired_flight_in_minutes);

    find_closest_flight(desired_flight_in_minutes, &departure_time, &arrival_time);


    return 0;



}

void find_closest_flight (int desired_time, int *departure_time, int *arrival_time)
{
    int i, time_difference = 0;

    /* Departure and arrival times in minutes since midnight */
    int departure_times[DEPARTURE] = {8 * 60, 9 * 60 + 43, 11 * 60 + 19,
                                    12 * 60 + 47, 14 * 60, 15 * 60 + 45,
                                    19 * 60, 21 * 60 + 45};
    int arrival_times[ARRIVAL] = {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31,
                                15 * 60, 16 * 60 + 8, 17 * 60 + 55,
                                21 * 60 + 20, 23 * 60 + 58};

    for (i = 0; i < DEPARTURE; i++)
    {
        time_difference = abs(desired_time - departure_times[i]);
        if (time_difference < abs(desired_time - departure_times[i + 1]))
        {
            *departure_time = departure_times[i];
            *arrival_time = arrival_times[i];
            break;
        }
    }

    printf("Closest departure time is %.2d:%.2d | Arriving at: %.2d:%.2d",
        *departure_time / 60, *departure_time % 60, *arrival_time / 60,  *arrival_time % 60);
                                                    
}