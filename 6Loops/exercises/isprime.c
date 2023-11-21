#include <stdio.h>

int main (void)
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);
    int d;
    for ( d = 2; d < number && number % d != 0; d++ );
        if (d < number)
            printf("%d is divisible by %d\n", number, d);
        else printf("%d is a prime number. And d = %d\n", number, d);
    return 0;


}