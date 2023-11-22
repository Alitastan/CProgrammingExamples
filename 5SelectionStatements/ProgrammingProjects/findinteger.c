#include <stdio.h>

/*  Enter four integers: 21 35 10 43 
*   Largest : 43
*   Smallest: 10    
*/


int main (void)
{
    int d1, d2, d3, d4;
    int min, max;

    printf("Enter 4 integer number: ");
    scanf("%d %d %d %d", &d1, &d2, &d3, &d4);

    min = max = d1;

    if (d2 < min)
    {
        min = d2;
    }
    else if ( d2 > max)
    {
        max = d2;
    }

    if (d3 < min)
    {
        min = d3;
    }
    else if (d3 > max )
    {
        max = d3;
    }

    if (d4 < min)
    {
        min = d4;
    }
    else if (d4 > max )
    {
        max = d4;
    }

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);

        
}