
#include <stdio.h>


int gcd (int m, int n);
void reduce (int numerator, int denominator,
    int* reduced_numerator, int *reduced_denominator);

int main (void)
{
    int numerator, denomanitor;
    int reduced_num, reduced_denom;
    printf ("Enter a number / number: ");
    scanf ("%d / %d", &numerator, &denomanitor);

    reduce (numerator, denomanitor, &reduced_num, &reduced_denom);

    printf ("\nReduced num: %d Reduced denom: %d", reduced_num, reduced_denom);


    return 0;
}




void reduce (int numerator, int denominator,
    int* reduced_numerator, int *reduced_denominator)
    {
        int remainder;
        int num = numerator;
        int denom = denominator;

        while (denominator != 0)
        {
            /* Find the greatest common divisor*/

            remainder = numerator % denominator;
            numerator = denominator;
            denominator = remainder;

        }
        printf ("GCD: %d\n", numerator);
        *reduced_numerator = num / numerator;
        *reduced_denominator = denom / numerator;
    }
