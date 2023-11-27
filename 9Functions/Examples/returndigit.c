
#include <math.h>
#include <stdio.h>


int digit (int n, int k);


int main (void)
{
    printf("%d\n", digit(65421, 4));
}

int digit (int n, int k)
{
    int i;

    for (i = 1; i < k; i++)
        n /= 10;

    return n % 10;
}

