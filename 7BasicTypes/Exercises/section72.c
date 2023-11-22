#include <stdio.h>

int main (void)
{
    float num1 = 010E2f;
    float num2 = 32.1E+5f;
    float num3 = 3.978e-2f;

    char num4 = 'A';

    // octal and hex values
    // \b = 010     \x08
    // \n = 012     \x0a
    // \r = 015     \x0d
    // \t = 011     \x09

    printf(" num1: %f\x0a num2: %f\x0a num3: %f\x0a num4: %d\x0a", num1, num2, num3, num4);

}