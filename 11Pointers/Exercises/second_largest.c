

#include <stdio.h>

#define LEN 10

void find_two_largest (int a[], int n, int *largest, int *second_largest);

int main (void)
{

   int array[LEN], i, largest, second_largest;

    printf("Enter %d numbers:", LEN );

    for (i = 0; i < LEN; i++)
        scanf("%d", &array[i]);

    find_two_largest(array, LEN, &largest, &second_largest);

    printf("Largest: %d\n", largest);
    printf("second_largest: %d\n", second_largest);

    return 0;
}


void find_two_largest (int a[], int n, int *largest, int *second_largest)
{
    *largest = *second_largest = a[0];


    int i;

    for (i = 1; i < n; i++)
    {
        if (a[i] > *largest)
        {
            *largest = a[i];

        }

    }

    for (i = 1; i < n - 1; i++)
    {
        if (a[i] > *second_largest && a[i] < *largest)
            *second_largest = a[i];
    }
    
}