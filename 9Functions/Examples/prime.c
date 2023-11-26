/* Tests whether a number is prime  */

#include <stdbool.h>
#include <stdio.h>

bool isPrime (int n)
{
    int divisor;

    if (n <= 1)
        return false;
    
    for (divisor = 2; divisor * divisor <= n; divisor++)
    {
        if (n % divisor == 0)
            return false;
    }

    return true;
}

int main (void)
{
    int n;

    printf ("Enter a number: ");
    scanf ("%d", &n);

    if (isPrime(n))
        printf ("Prime\n");
    else
        printf ("Not prime\n");
        
    return 0;
}