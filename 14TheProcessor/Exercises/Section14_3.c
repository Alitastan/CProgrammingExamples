/**
 * Write parameterized macros that compute the following
 * values.
 * 
 * - The cube of x
 * - The remainder when n is divided by 4
 * - 1 if the product of x and y is less than 100, 0 otherwise.
*/

#define CUBE(x) (x * x * x)
#define REMAINDER_FOUR(n) (n % 4)
#define PRODUCT(x,y) (((x) * (y)) < 100 ? 1 : 0)

#define PRODUCT_PRINT(x,y) printf(#x " * " #y " = %d\n", x * y)

#include <stdio.h>

// A value outside the size of int will fail 

int main (void)
{
    int x = 26;
    int y = 4;

    printf("Cube of %d is %d\n", x, CUBE(x));
    printf("Remainder of %d by 4 is %d\n", x, REMAINDER_FOUR(x));
    printf("Product of %d by %d is %d\n", x, y, PRODUCT(x,y));

    PRODUCT_PRINT(3, 7);
    return 0;
}