/* Calculation of greatest common divisor with Euclid's algorithm */

#include <stdio.h>

int gcd (int m, int n);

int main (void)
{
    printf ("Greatest common divisor: %d\n", gcd (40, 16));

    return 0;
}

int gcd (int m, int n)
{
    int remainder;

    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    return m;
}