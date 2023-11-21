/* A program that computes the factorial of a positive integer */

/*  For long double 
*   Dev-c++ uses MinGW, which uses the gcc compiler and
    the Microsoft runtime library. Unfortunately, those
    components disagree on the underlying type to be used
    for long double (64 vs. 80 or 96 bits, I think). Windows
     assumes long double is the same size as double; gcc makes long double bigger.

Either choice is valid, but the combination results in a broken C and C++ implementation.*/
// double : 170!
// float : 34!
// long long : 20!
// long, int : 16!
// short : 15!

#include <stdio.h>

typedef long double Factorial;

int main (void)
{
    Factorial userInput;
    Factorial result = 1.0;

    printf ("Enter a positive integer: ");
    scanf ("%Lf", &userInput);

    for (Factorial i = userInput; i > 0; i--)
        result *= i;

    printf("Factorial of %Lf is %Lf\n", userInput, result);

}
