/*  Reverses a series of numbers using Variable Length Array */

#include <stdio.h>



int main (void)
{
    int n, i;

    printf("How many numbers do you want to reverse? ");
    scanf("%d", &n);

    int a[n]; // length of array depends on n

    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("In reverse order: ");
    for (i = n - 1; i >= 0; i--)
        printf(" %d", a[i]);
    
    printf("\n");

    return 0;
}