#include <stdio.h>

int main (void)
{
    int sum, i;

    sum = 0;

    printf ("%d\n\n", 11 % 24);
   /*
    for (i = 0; i < 10; i++)
    {
        if (i % 2)  // 1 3 5 7 9    0 2 4 6 8
            continue;
        sum += i;
    }
    printf("%d\n", sum); */

    for (i = 0; i < 10; i++)
    {
        if (i % 2)
            goto loopEnd;
        sum += i;

        loopEnd: ; // null statement
    }
    printf("%d\n", sum);
}