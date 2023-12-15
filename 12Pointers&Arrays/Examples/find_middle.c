
#include <stdio.h>

#define LEN 8

int *find_middle (int *a, int n);
int *find_middle_new (int *a, int n);

// a[i] = *(a + i)
// 0 1 2 3 4 5 
int main (void)
{
    int array[LEN] = {0, 1, 2, 3, 12, 5, 6, 7};
    int *p_middle, *p_middle_new;

    p_middle = find_middle(array, LEN);
    p_middle_new = find_middle_new(array, LEN);

    printf("p_middle: %p\nValue: %d\n", p_middle, *p_middle);
    printf("p_middle_new: %p\nValue: %d\n", p_middle_new, *p_middle_new);
    
}

int *find_middle (int *a, int n)
{
    return &a[n / 2];
}

int *find_middle_new (int *a, int n)
{
    return &(*((a + n / 2)));

}