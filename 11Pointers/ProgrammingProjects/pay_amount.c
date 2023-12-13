

#include <stdio.h>

void pay_amount (int dollars, int *twenties, int *tens, int *fives, int *ones);

int main (void)
{
    int dollars = 226;
    int twenties, tens, fives, ones;


    pay_amount(dollars, &twenties, &tens, &fives, &ones);

    printf("Dollars: %d\n", dollars);

    printf("Twenties: %d, tens: %d, fives: %d, ones: %d",
            twenties, tens, fives, ones);

}

void pay_amount (int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars / 20;
    dollars -= (20 * ( dollars / 20));

    *tens = dollars / 10;
    dollars -= (10 * ( dollars / 10));

    *fives = dollars / 5;
    dollars -= (5 * (dollars / 5));

    *ones = dollars;
    dollars -= dollars;
}