/* Calculation of greatest common divisor with Euclid's algorithm */

#include <stdio.h>

int gcd (int m, int n);
int gcdRecursive (int m, int n);

int main (void)
{
    printf ("Greatest common divisor: %d\n", gcd (100, 16));
    printf ("Recursively: %d\n", gcdRecursive(100, 16));

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

int gcdRecursive (int m, int n)
{
    return n == 0 ? m : gcdRecursive(n, m % n);
}