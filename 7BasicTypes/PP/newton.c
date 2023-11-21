/*  Newton's method to compute the square root of a positive    
*   floating-point number:
*   Enter a positive number: 3
*   Square root: 1.73205
*
*   Let x be the number entered by the user. Newton's method requires
*   an initial guess y for the square root of x (we'll use y = 1).
*   Successive guesses are found by computing the average of y and x/y
*   The following table shows how the square root of 3 would be found:
*
*
*   _________________________________________________________
    |    x       y       x/y         Average of y and x/y   |
    |_______________________________________________________|
    |    3       1       3                   2              |
    |    3       2       1.5                 1.75           |
    |    3       1.75    1.71429             1.73214        |   
    |    3       1.73214 1.73196             1.73205        |
    |    2       1.73205 1.73205             1.73205        |
    |_______________________________________________________|
        
*   Note that the values of y get progressively closer to the true 
*   square root of x. For greater accuracy we will use double rather than
*   flloat. The program will terminate when the absolute value of the difference
*   between the old value of y and the new value of y is less than the product
*   of .00001 and y. Hint: call the fabs function to find the absolute value of 
*   of a double. (include <math.h> header).*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>


int main (void)
{   
    // x
    uint32_t userInput;
    // y
    double initialGuess = 1;
    // x / y
    double quotient = 0.0;
    // average of (y + x / y)
    double average = 0.0;

    double newInitialGuess = 0.0;
    double absValue = 0.0;
    
    printf("Enter a positive number: ");
    scanf("%u", &userInput);

    do
    {
        quotient = (double) userInput / initialGuess;
        average =  ( (double) initialGuess + quotient) / 2;
        newInitialGuess = average;
        absValue = newInitialGuess - initialGuess;
        initialGuess = newInitialGuess;
    }while (fabs(absValue) > 0.00001 * initialGuess );

    printf("Average of y and x/y: %f\n", average);
    printf("initial guess: %f\n", initialGuess);
    printf("Quotient: %f\n", quotient);

    printf("Square root of %u is %f\n", userInput, average);
    
        
    return 0;
    

}