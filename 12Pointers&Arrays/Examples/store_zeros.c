#include <stdio.h>


void store_zeros (int a[], int n);
void store_zeros_new (int a[], int n);

#define LEN 5

int main (void)
{
    int array[LEN] = {1, 2, 3, 4, 5};

    store_zeros(array, LEN);

    for (int i = 0; i < LEN; i++)
        printf(" %d", array[i]);
}

/**
 *  Rewrite the following function to use pointer arithmetic
 *  instead of array subscripting. 
 * */
void store_zeros (int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = 0;
}

void store_zeros_new (int a[], int n)
{
    int *ptr_array;

    for (ptr_array = a; ptr_array < a + n; ptr_array++)
        *ptr_array = 0;
}