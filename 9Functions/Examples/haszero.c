


#include <stdbool.h>
#include <stdio.h>

bool hasZero (int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        if (a[i] == 0)
            return true;

    return false;
}

int main (void)
{
    int array[] = {1, 0, -4, 1, 5};

    printf("%d", hasZero(array, 5));

    return 0;
}