/* Sorts an array of integers using Quicksort algorithm */

#include <stdio.h>
#include "quicksort.h"


int main (void)
{
    int a[NUMBER_LIST_SIZE], i;

    printf ("Enter %d numbers to be sorted: ", NUMBER_LIST_SIZE);

    for (i = 0; i < NUMBER_LIST_SIZE; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, NUMBER_LIST_SIZE - 1);

    printf("In sorted order: ");
    for (i = 0; i < NUMBER_LIST_SIZE; i++)
        printf("%d ", a[i]);
    
    printf("\n");

    return 0;


}


