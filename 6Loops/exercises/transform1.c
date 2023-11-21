
#include <stdio.h>

int main (void)
{
    //for (int i = 1; i <= 128; printf("%d ", i), i *= 2);

    //for (int i = 9384; i > 0; printf("%d ", i), i /= 10);

    int i = 0, j = 0, k = 0;

    while (i < 10)
    {
        printf("Example\n");
        i++;
    }

    for (; j < 10;)
    {
        printf("Example 1\n");
        j++;          
    }

    do 
    {
        printf("Example 2\n");
        k++;
    } while (k < 10);



    return 0;
}