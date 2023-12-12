
#include <stdio.h>

#define LEN 5

void avg_sum (double a[], int n, double *avg, double *sum);


int main (void)
{

    double numbers[LEN] = {0.0}, average = 0.0, sum = 0.0;
    int i;

    printf("average: %f\nsum: %f\n", average, sum);

    printf("Enter double numbers: ");

    for (i = 0; i < LEN; i++)
        scanf("%lf", &numbers[i]);

    avg_sum(numbers, LEN, &average, &sum);

    printf("average: %f\nsum: %f\n", average, sum);

    return 0;
}


void avg_sum (double a[], int n, double *avg, double *sum)
{
    int i;

    *sum = 0.0;

    for (i = 0; i < n; i++)
        *sum += a[i];
    
    *avg = *sum / n;
}