#include <stdio.h>

int main(void)
{
    int initialAmount;


    printf("Enter an amount: ");
    scanf("%d", &initialAmount);

    printf("20'lik: %d\n", initialAmount / 20 );
    initialAmount -= (20 * ( initialAmount / 20 ));
    printf("10'luk: %d\n", ( initialAmount / 10 ));
    initialAmount -= (10 * ( initialAmount / 10 ));
    printf("5'lik: %d\n",  ( initialAmount / 5 ));
    initialAmount -= (5 * ( initialAmount / 5 ));
    printf("1'lik: %d\n", ( initialAmount / 1 ));
    initialAmount -= (1 * ( initialAmount / 1 ));

    return 0;
}