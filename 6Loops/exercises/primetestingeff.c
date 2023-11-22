/* Check if a number is prime 
*/
#include <stdio.h>
#include <stdbool.h>

int main (void)
{
    int d, n;
    bool flag = true;
    
    printf("Enter a number: ");
    scanf("%d", &n);


    for (d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            printf("Found a divisor: %d. Breaking the loop.\n", d);
            flag = false;
            break;
        }
         
    }

    if (flag)
        printf("%d is a prime number\n", n); 
    else
        printf("%d is not a prime number!\n", n);


}