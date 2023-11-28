

#include <stdio.h>

int fact (int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fact (n - 1);
}


int factcondensed (int n)
{
    return n <= 1 ? 1 : n * fact (n - 1);
}


int factNonRecursive (int n)
{
    int result = 1;

    while (n >= 1)
    {
        result *= n;
        n--;
    }
}

int factNonRecursive2 (int n)
{
    int i, result = 1;


    for (i = 2; i <= n; i++)
        result *= i;

    return result;
}

int main (void)
{
    int number = 6;

    printf("Factorial of %d is %d\n", number, factNonRecursive(number));

    return 0;
}