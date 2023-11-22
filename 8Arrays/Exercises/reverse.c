/*  Reverses a series of numbers    */

#include <stdio.h>

#define LEN 5

int main (void)
{
    int a[LEN], i;

    printf("Enter %d numbers:\t ", LEN);

    for (i = 0; i < LEN; i++)
        scanf("%d", &a[i]);
    
    printf("In reverse order:\t");
    
    for (i = LEN - 1; i >= 0; i--)
        printf(" %d", a[i]);
    
    printf("\n");

    return 0;

}