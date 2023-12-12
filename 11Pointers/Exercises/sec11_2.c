
#include <stdio.h>

int main (void)
{
    int i = 5;
    int *p = &i;

    /**
     * Aliases for i
     * 
     *  *p, *&i, 
     * */ 

    printf("Val: %d\n", *p);

    printf("Val: %d\n", *&i);

}