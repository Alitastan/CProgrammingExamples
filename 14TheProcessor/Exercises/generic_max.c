
#include <stdio.h>


#define GENERIC_MAX(type)           \
type type##_max(type x, type y)     \
{                                   \
    return x > y ? x : y;           \
}


/**
 * Show the preprocessor's expansion of GENERIC_MAX(long)
 * 
 * 
 * long long_max(long x, long y)
 * {
 *   return x > y ? x: y;
 * }
*/

/**
 * Explain why GENERIC_MAX doesn't work for basic types such as
 * unsigned long
 * 
 * since there is a space between unsigned and long the expansion
 * would be
 * 
 * unsigned unsigned_max(unsigned x, unsigned y)
 * {
 *  return x > y ? x: y;
 * }
*/

/**
 * Describe a technique that would allow us to use GENERIC_MAX with
 * basic types such as unsigned long.
 * 
 * typedef unsigned long ULONG;
 * GENERIC_MAX(ULONG);
*/

typedef unsigned long ULONG;

GENERIC_MAX(ULONG);

int main (void)
{
    ULONG a = 6541234, b = 421354, retval;

    retval = ULONG_max(a, b);

    printf("ret val: %ld", retval);
    return 0;
}