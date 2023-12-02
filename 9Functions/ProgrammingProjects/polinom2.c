/* 
*   Write a function that computes the value of the following polynomial 
*   3 (x^5) + 2 (x^4) - 5 (x^3) - (x^2) + 7 (x) - 6
*/

// ( 3 * pow(x, n) + 2 * pow(x, n) - 5 * pow(x, n) - pow(x, n) + 7 * x - 6);


#include <stdio.h>
#include <math.h>



double myPowerFunc (double x, double n);


int powerRecursive (int x, int n);

int main(void)
{
    int result;
    int x;
    printf("Enter X: ");
    scanf("%d", &x);

    result = ( 3 * powerRecursive(x, 5) + 2 * powerRecursive(x, 4) - 5 * powerRecursive(x, 3) - powerRecursive(x, 2) + 7 * x - 6);

    printf("Polynomial Result: %d\n", result);

    return 0;

}


double myPowerFunc (double x, double n)
{
    double power = 1.0;

    while (n != 0)
    {
        power *= x;
        n--;
    }

    return power;
}


int powerRecursive (int x, int n)
{
    int power = 1;

    if (n == 0)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        int halfPower = powerRecursive(x, n / 2);
        power = halfPower * halfPower;
    }

    else
    {
        power = x * powerRecursive(x, n - 1);
    }

    return power;

}
