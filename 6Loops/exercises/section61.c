#include <stdio.h>

int main (void)
{
    int i, j;

    // Initialize i to 5 and j to 4.
    // check if i is bigger than 0 if false check if j is bigger than 0
    // prints i = 5
    // decrement the value of i and assign j = i - 1.
    // j is the final value of the expression

    // i = 5 j = 4  prints i = 5
    // i = 4 j = 3  prints i = 4
    // i = 3 j = 2  prints i = 3
    // i = 2 j = 1  prints i = 2

    printf("%d\n", 0 % 2);

    for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
        printf("i = %d j = %d\n", i, j);   
}