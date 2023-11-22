#include <stdio.h>

int main (void)
{
    int n, m;
    m = 10;
    for (n = 0; m > 0; m /= 2, n++)
        printf("M : %d N : %d\n", m, n);
    
    

}