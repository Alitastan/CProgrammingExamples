#include <stdbool.h>
#include <stdio.h>

#define LEN     6
bool search (const int a[], int n, int key);


int main (void)
{
    const int array[LEN] = {2, 6, 5, 9, 12, 7};
    bool key_found = false;

    key_found = search(array, LEN, 3);
    key_found = search(array, LEN, 4);
}

bool search (const int a[], int n, int key)
{
    const int *ptr_array = a;

    for (ptr_array = a; ptr_array < a + n; ptr_array++)
    {
        if (key == *ptr_array)
        {
            printf("Key [%d] found!\n", key);
            return true;
        }
    }
    printf("Key [%d] not found!\n", key);
    return false;
}