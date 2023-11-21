#include <stdio.h>

int main(void)
{
    int number, firstDigit, secondDigit;
    printf("Enter a two digit number: ");
    scanf("%d", &number);

    firstDigit = number / 10;
    secondDigit = number % 10;

    printf("\nThe reversal is: %d%d", secondDigit, firstDigit);

    return 0;
}