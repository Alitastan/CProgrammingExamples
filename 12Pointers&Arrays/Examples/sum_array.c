#include <stdio.h>

#define LEN 5

int sum_array (const int a[], int n);
int sum_array_new (const int *a, int n);

int main (void)
{
    const int array[LEN] = {1, 2, 3, 11, 5};

    printf("Sum: %d", sum_array_new(array, LEN));

}

/*  Rewrite the following function to use pointer arithmetic    */
int sum_array (const int a[], int n)
{
    int i, sum;
    sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum;
}


int sum_array_new (const int a[], int n)
{
    int sum = 0;
    const int *ptr_array = a;

    for (ptr_array = a; ptr_array < a + n; ptr_array++)
    {
        sum += *ptr_array;
    }
    return sum;
}