/*  Decompose a variable to its integer and fraction parts. */

#include <stdio.h>

void decompose (double x, long * intPart, double * fractionPart);

int main (void)
{
    double number = 3.123456;
    long integer;
    double fraction;

    decompose(number, &integer, &fraction);
    
    //printf("Int part: %d\nFraction part: %f", integer, fraction);

    return 0;
}


void decompose (double x, long * intPart, double * fractionPart)
{
    *intPart = (long) x;
    *fractionPart = x - *intPart;

    printf("Int part: %d\nFraction part: %f", *intPart, *fractionPart);
}