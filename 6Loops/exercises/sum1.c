#include <stdio.h>

int main (void)
{
    int i, n, sum;

    printf("Enter a number: ");
    scanf("%d", &i);

    while (n < 10)
    {
        scanf("%d", &i);

        if (i == 0)
            continue;
        
        sum += i;
        n++;
    }

    printf("The variable n: %d\tSum : %d\n", n, sum);

    return 0;
}