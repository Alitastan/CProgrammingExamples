/*  Finds the largest and smalllest elements in an array */

#include <stdio.h>

#define LEN 10

void maxMin (int a[], int len, int *max, int *min);

int main (void)
{
    int array[LEN], *p_array, big, small;

    printf("Enter %d numbers: ", LEN );

    for (p_array = array; p_array < array + LEN; p_array++)
        scanf("%d", p_array);

    maxMin(array, LEN, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
    
}


void maxMin (int a[], int len, int *max, int *min)
{
    int *p_max_min = a;

    // Lets assume the maximum and minimum is the first element
    *max = *min = *p_max_min;

    for (p_max_min = a + 1; p_max_min < a + len ; p_max_min++)
    {
        if (*p_max_min > *max)
            *max = *p_max_min;
        
        else if (*p_max_min < *min)
            *min = *p_max_min;
    }
}