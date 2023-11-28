
#include <stdio.h>

void pb (int n)
{
    if (n != 0)
    {
        pb (n / 2);
        putchar('0' + n % 2);
    }
}



int main (void)
{   
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    pb (number);

    // When number is 20 output is 10100

    // pb(20) finds that 20 is not equal to zero calls pb(10)
    // pb(10) finds that 10 is not equal to zero calls pb(5) 
    // pb(5) finds that 5 is not equal to zero calls pb(2)
    // pb(2) finds that 2 is not equal to zero calls pb(1)
    // pb(1) finds that 1 is not equal to zero calls pb(0)

    // pb(0) returns nothing
    // pb(1) returns 1
    // pb(2) returns 0
    // pb(5) returns 1
    // pb(10) returns 0
    // pb(20) returns 0

    // The output should be 10100 

    printf("\n");


    return 0;
}