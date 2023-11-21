#include <stdio.h>

int main(void)
{
    int number, firstDigit, secondDigit, thirdDigit, fourthDigit;
    printf("Enter a two digit number: ");
    scanf("%d", &number);

    firstDigit = number % 10;
    secondDigit = (number / 10) % 10;
    thirdDigit = (number / 100) % 10;
    fourthDigit = (number / 1000);

    printf("\nThe reversal is: %d%d%d%d", firstDigit, secondDigit, thirdDigit, fourthDigit);

    return 0;
}