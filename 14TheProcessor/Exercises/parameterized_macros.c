
#include <stdio.h>

/**
 * Has the value 1 if both x and y fall between
 * 0 and n-1, inclusive
*/
#define CHECK(x,y,n) ((x >= 0) && (y >= 0) && (x <= (n - 1)) && (y <= (n - 1)))


/**
 * Finds the median of x, y and z
*/
#define GENERIC_MEDIAN(type)    \
type type##_median(type x, type y, type z)  \
{                                           \
    type result;                            \
                                            \
    if (x <= y)                             \
    {                                       \
        if (y <= z) result = y;             \
        else if (x <= z) result = z;        \
        else result = x;                    \
    }                                       \
    else                                    \
    {                                       \
        if (z <= y) result = y;             \
        else if (x <= z) result = x;        \
        else result = z;                    \
    }                                       \
                                            \
    return result;                          \
}

/**
 * Computes the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 
*/
#define SQUARE(x) ((x) * (x))
#define QUARTIC(x) (SQUARE(x) * SQUARE(x))
#define POLYNOMIAL(x) printf("3""("#x")""^5 " "+ " "2""("#x")""^4 " "- " "5""("#x")""^3 " "- " "("#x")""^2 " "+ " "7""("#x") " "- " "6 " "= %d\n", \
 (3 * (x) * QUARTIC(x) + 2 * QUARTIC(x) - 5 * (x) * SQUARE(x) -  SQUARE(x) + 7 * (x) - 6) )        \

GENERIC_MEDIAN(double);


int main (void)
{
    unsigned int check;

    POLYNOMIAL(2);
    printf ("Median: %f\n", double_median(14.0, 21.0, 9.0));

    check = CHECK(5, 4, 8);
    printf("Check: %d\n", check);
    return 0;
}