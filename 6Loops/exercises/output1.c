
#include <stdio.h>

int main (void)
{
    // Infinite loop. to solve this i >= 1 expression must be replaced with i > 1
    int i;
    for (i = 10; i >= 1; i /= 2)
        printf("%d ", i++);

        // prints 10 i is now 11
        // 11 / 2 = 5  i is now 5
        // prints 5 i is now 6
        // 6 / 2 = 3 i is now 3
        // prints 3 i is now 4
        // 4 / 2 i is now 2
        // prints 2 i is now 3
        // 3 / 2 = 1 i is now 1
        // prints 1 i is now 2
        // 2 / 2 = 1 i is now 1
        // i is now 2 i is 1
}