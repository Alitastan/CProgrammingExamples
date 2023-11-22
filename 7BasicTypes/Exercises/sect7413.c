#include <stdio.h>
#include <limits.h>
#include <stdint.h>

typedef char Int8;
typedef short Int16;
typedef int Int32;

int main (void)
{
    Int8 c = '\1'; // decimal 1.
    Int16 s = 2;
    Int32 i = -3;
    long m = 5;
    float f = 6.5f;
    double d = 7.5;

    printf("c * i = %d (type of int)\n", c * i);
    printf("s + m = %ld (type of long)\n", s + m);
    printf("f / c = %f (type of float)\n", f / c);
    printf("d / s = %f (type of double)\n", d / s);
    printf("f - d = %f (type of double)\n", f - d);
    printf("(int) f = %d (float variable type casted to int)\n\n", (int) f);

    float frac_part, f1;
    f1 = 5000.89f;
    frac_part = f1 - (int)f1;
    printf("Fraction part: %f", frac_part);

}