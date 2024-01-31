/**
 * For each of the following macros, give an example that illustrates
 * a problem with the macro and show how to fix it.
*/

#include <stdio.h>

//#define AVG(x,y) (x + y) / 2
#define AVG(x,y) (((x) + (y)) / 2)
//#define AREA(x,y) (x) * (y)
#define AREA(x,y) ((x) * (y))

int main (void)
{
    int a, b, x, y;

    // (1 / (x + y)) / 2
    a = 1 / AVG(x, y);

    // (1 / (x)) * (y)
    b = 1 / AREA(x,y);


}

