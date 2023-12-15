
#include <stdio.h>

#define LEN 6

double inner_product (const double *a, const double *b, int n);

int main (void)
{
    const double array1[LEN] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    const double array2[LEN] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    
    inner_product(array1, array2, LEN);
}

/**
 * A and B both point to arrays of length n. The function should
 * return a[0] * b[0] + a[1] * b[1] + ... + a[n - 1] * b[n - 1]
 * Use pointer arithmetic - not subscripting - to visit array elements.
*/
double inner_product (const double *a, const double *b, int n)
{
    const double *ptr_a, *ptr_b;
    double sum = 0.0;

    for (ptr_a = a, ptr_b = b; ptr_a < a + n, ptr_b < b + n; ptr_a++, ptr_b++)
    {
       sum += (*ptr_a) * (*ptr_b);
    }
    printf("Sum: %f", sum);
    return sum;
}