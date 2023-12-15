
#include <stdio.h>

#define LEN     10

int *find_largest (int a[], int n);
int *find_largest_new (int a[], int n);

int main (void)
{
    int a[LEN];
    int *p_numbers, *p_largest;

    printf("Enter %d elements: ", LEN);
    for (p_numbers = a; p_numbers < a + LEN; p_numbers++)
        scanf("%d", p_numbers);

    p_largest = find_largest_new(a, LEN);


    for (p_numbers = a; p_numbers < a + LEN; p_numbers++)
        printf(" %d", *p_numbers);

    printf ("\nLargest: %d\n", *p_largest);

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

int *find_largest_new (int a[], int n)
{
    int *largest = a;
    int *check_other_numbers;

    for (check_other_numbers = a + 1; check_other_numbers < a + n; check_other_numbers++)
    {
        if (*check_other_numbers > *largest)
        {
            largest = check_other_numbers;
        }
    }
    return largest;
}