
#include <stdio.h>

int numDigits (int n);

int main (void)
{
    int number = 9999;

    printf("The number %d has %d digits\n", number, numDigits(number));

    return 0;
}

int numDigits (int n)
{
    int numberOfDivisions = 0;

    while (n > 0)
    {
        n /= 10;
        numberOfDivisions++;
    }

    return numberOfDivisions;
}