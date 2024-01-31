/**
 * Write a macro NELEMS(a) that computes the number of elements
 * in a one-dimensional array a.
*/


#include <stdio.h>

#define NELEMS(a) ((int) sizeof(a) / sizeof(a[0]))

int main (void)
{
    int array[] = {5, 9, 10, 35, -5, -40, 22, 41};

    printf("size of array: %d\n", NELEMS(array));

    return 0;
}