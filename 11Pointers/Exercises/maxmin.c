/*  Finds the largest and smalllest elements in an array */

#include <stdio.h>

#define LEN 10

void maxMin (int a[], int len, int *max, int *min);

int main (void)
{
    int array[LEN], i, big, small;

    printf("Enter %d numbers:", LEN );

    for (i = 0; i < LEN; i++)
        scanf("%d", &array[i]);

    maxMin(array, LEN, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
    
}


void maxMin (int a[], int len, int *max, int *min)
{
    int i;

    // Lets assume the maximum and minimum is the first element
    *max = *min = a[0];

    for (i = 1; i < len; i++)
    {
        if (a[i] > *max)
            *max = a[i];
        
        else if (a[i] < *min)
            *min = a[i];
    }
}