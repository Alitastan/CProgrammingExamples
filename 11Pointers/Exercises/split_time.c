/**
 *  Write a function where total seconds represent time,
 *  since midnight and convert it to hours, minutes and 
 *  seconds.   */

#include <stdio.h>


#define SECONDS_IN_MINUTE           60L
#define MINUTES_IN_HOUR             60L
#define SECONDS_IN_HOUR            (SECONDS_IN_MINUTE * MINUTES_IN_HOUR)

void split_time (long total_sec, int *hr, int *min, int *sec);

int main (void)
{
    long second_input = 0;
    int hr = 0, min = 0, sec = 0;

    printf("Enter seconds: ");
    scanf("%ld", &second_input);

    split_time(second_input, &hr, &min, &sec);

    printf("\n%.2d:%.2d:%.2d", hr, min, sec);

    return 0;
}

// 3599   00:59:59
// 3601 seconds : 1:00:1   3601/60 = 60 remainder 1
// 185 seconds: 00:03:05   185/60 = 3 remainder 5

//7550 seconds 2:05:50    7550 / 3600    550 / 60   50 / 60

// 58 seconds  58 / 60 = 0

void split_time (long total_sec, int *hr, int *min, int *sec)
{
    *hr = total_sec / SECONDS_IN_HOUR;
    total_sec %= SECONDS_IN_HOUR;

    *min = total_sec / MINUTES_IN_HOUR;
    total_sec %= MINUTES_IN_HOUR;

    *sec = total_sec;

}