/**
 * Values of an enumerated type can be used as subscripts.
*/

#include <stdio.h>

enum weekdays {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY};

const char *daily_specials[] = {
    [MONDAY] = "Beef ravioli",
    [TUESDAY] = "BLTs",
    [WEDNESDAY] = "Pizza",
    [THURSDAY] = "Chicken fajitas",
    [FRIDAY] = "Macaroni and cheese"
};


int main(void)
{
    printf("%s", daily_specials[WEDNESDAY]);
}