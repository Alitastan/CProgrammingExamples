
#include <stdio.h>


#define ERROR(string, index) fprintf(stderr, string, index)


int main (void)
{
    int index = 5;
    ERROR("Range error: index = %d\n", index);

    return 0;
}