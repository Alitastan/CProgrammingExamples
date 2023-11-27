

#include <stdio.h>

double innerProduct (double a[], double b[], int n);


int main (void)
{
    double array1[] = {1, 2, 3, 4, 5};
    double array2[] = {2, 4, 6, 8, 10};

    printf("Inner product: %f\n", innerProduct(array1, array2, 5));
}

double innerProduct (double a[], double b[], int n)
{

    int i;

    double sum = 0.0;

    for (i = 0; i < n; i++)
    {
        sum += a[i] * b[i];
    }

    return sum;
}