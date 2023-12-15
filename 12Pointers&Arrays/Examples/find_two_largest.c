
#include <stdio.h>

#define LEN 10

void find_two_largest (const int *a, int n, int *largest, int *second_largest);

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

void find_two_largest (const int *a, int n, int *largest, int *second_largest)
{
    const int *p_to_array = a;

    if (*p_to_array > *(p_to_array + 1))
    {
        *largest = *p_to_array;
        *second_largest = *(p_to_array + 1);
    }
    else
    {
        *largest = *(p_to_array + 1);
        *second_largest = *p_to_array;
    }

    for (p_to_array = a + 2; p_to_array < a + n; p_to_array++)
    {
        if (*p_to_array > *largest)
        {
            *second_largest = *largest;
            *largest = *p_to_array;
        }
        else if (*p_to_array > *second_largest)
        {
            *second_largest = *p_to_array;
        }
    }

}