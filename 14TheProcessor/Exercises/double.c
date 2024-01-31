

#include <stdio.h>

// Always put parantheses around each parameter every time it appears
// in the replacement list
#define DOUBLE(x) (2 * (x))

int main (void)
{
    printf("DOUBLE(1+2): %d\n", DOUBLE(1+2));
    printf("4 / DOUBLE(2): %d\n", 4 / DOUBLE(2));
    
    return 0;
}
