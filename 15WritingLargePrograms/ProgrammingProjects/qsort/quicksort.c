

#include "quicksort.h"

// Uses recursion
void quicksort (int a[], int low, int high)
{
    int middle;

    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}


int split (int a[], int low, int high)
{
    int partElement = a[low];

    for(;;)
    {
        while (low < high && partElement <= a[high])
            high--;
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= partElement)
            low++;
        if (low >= high) break;
        a[high--] = a[low];
    }
    a[high] = partElement;
    return high;
}