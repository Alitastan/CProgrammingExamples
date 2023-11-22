#include <stdio.h>

#define ARRAY_LEN 40

int main (void)
{
    int fibNumbers[ARRAY_LEN] = {0, 1};

    for (int i = 2; i < ARRAY_LEN; i++)
        fibNumbers[i] = fibNumbers[i - 1] + fibNumbers[i - 2];

    printf("Fibonacci array of length %d:\n\n", ARRAY_LEN);

    for(int i = 0; i < ARRAY_LEN; i++)
        printf("%-10d ", fibNumbers[i]);
}