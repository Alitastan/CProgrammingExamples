
#include <stdio.h>

#define M   10


int main (void)
{
    #if !defined(M)
        int code = 5;
        printf("Code: %d\n", code);
    #endif
    return 0;
}