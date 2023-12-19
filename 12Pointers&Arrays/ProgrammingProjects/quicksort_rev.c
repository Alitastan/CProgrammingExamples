/* Sorts an array of integers using Quicksort algorithm */

#include <stdio.h>

#define N   7

void quicksort (int *array, int *low, int *high);
int *split (int *array, int *low, int *high);

int main (void)
{
    int a[N], *p_array, *low, *high;



    printf ("Enter %d numbers to be sorted: ", N);

    for (p_array = a; p_array < a + N; p_array++)
        scanf("%d", p_array);





    low = a;                //low = &a[0];
    high = a + N - 1;       //high = &a[N-1];

    quicksort(a, low, high);

    printf("In sorted order: ");
    for (p_array = a; p_array < a + N; p_array++)
        printf(" %d", *p_array);
    
    printf("\n");

    return 0;


}


// Uses recursion
void quicksort (int *array, int *low, int *high)
{
    int *middle;

    if (low >= high) return;

    middle = split (array, low, high);
    quicksort (array, low, middle - 1);
    quicksort (array, middle + 1, high);
}

int *split (int *array, int *low, int *high)
{
    int part_element = *low;

    for (;;)
    {
        while (low < high && part_element <= *high)
            high--;
        if (low >= high) break;
        *low++ = *high;

        while (low < high && *low <= part_element)
            low++;
        if (low >= high) break;
        *high-- = *low;
    }
    *high = part_element;
    return high;
}