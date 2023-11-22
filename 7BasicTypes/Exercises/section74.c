#include <stdio.h>

int main (void)
{
    char A = 'A';
    int i = 21, j = 3;

    int result = i / j + A;

    int ii = 5;
    float ff = 2.0;
    double dd = 4.2;

    double result2 = ii * ff / dd;
    printf("result2: %lf\n", result2);

    printf("A's int value: %d\n", A);
    printf("Result: %d", result);
}