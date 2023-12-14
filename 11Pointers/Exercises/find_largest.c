
#include <stdio.h>

#define LEN     10

int *find_largest (int a[], int n);

int main (void)
{
    int a[LEN];
    int *p_largest;

    printf("Enter %d elements: ", LEN);
    for (int i = 0; i < LEN; i++)
        scanf("%d", &a[i]);

    p_largest = find_largest(a + 5, LEN - 5);
    //p_largest = find_largest(a, LEN);
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