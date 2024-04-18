#include <stdio.h>

struct time
{
    int seconds, minutes, hours;
};



struct time split_time (long total_seconds)
{
    struct time final_time;

    final_time.hours = total_seconds / 3600;
    total_seconds -= final_time.hours * 3600;

    final_time.minutes = total_seconds / 60;
    total_seconds -= final_time.minutes * 60;

    final_time.seconds = total_seconds;

    return final_time;
}

int main (void)
{
    struct time x = split_time(7400);
    printf("%2.2d:%2.2d:%2.2d",
    x.hours, x.minutes, x.seconds);
}