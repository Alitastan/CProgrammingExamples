
#include <stdio.h>

#define LEN     5

int *find_largest (int a[], int n);

int main (void)
{
    int a[LEN];
    int *p_largest;

    printf("Enter 5 elements: ");
    for (int i = 0; i < LEN; i++)
        scanf("%d", &a[i]);

    p_largest = find_largest(a, LEN);

    printf("%p\n", p_largest);
    printf("Value: %d\n", *p_largest);
}


int *find_largest (int a[], int n)
{
    int *largest = &a[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (a[i] > *largest)
            *largest = a[i];
    }

    return largest;
}