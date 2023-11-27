
#include <stdbool.h>
#include <stdio.h>

bool check (int x, int y, int n);

int main (void)
{
    bool value;

    value = check(1,3,4);

    printf("%d", value);

    return 0;
}

bool check (int x, int y, int n)
{
    return  ((x >= 0 && x <= n - 1) && (y >= 0 && y <= n - 1)) ? true : false;  
}