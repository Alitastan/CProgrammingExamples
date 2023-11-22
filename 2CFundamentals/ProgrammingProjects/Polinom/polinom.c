#include <stdio.h>
#include <math.h>

int main(void)
{
    float x;

    printf("Enter value for x: ");
    scanf("%f", &x);

    //  3 (x^5) + 2 (x^4) - 5 (x^3) - (x^2) + 7 (x) - 6

    // Horners method though not working here uses fewer multiplications.

    float hornersMethod = ((((( 3 * x + 2 ) * ( x - 5 )) * ( x - 1 )) * ( x + 7 )) * ( x - 6 ) ) ;
    float result;
    result = ( 3 * pow(x, 5.0) + 2 * pow(x, 4.0) - 5 * pow(x, 3.0) - pow(x, 2.0) + 7 * x - 6);
    printf("The result of the polynomial: %.2f\n", result);

    printf("The result with Horners method: %.2f", hornersMethod);

    return 0;

}