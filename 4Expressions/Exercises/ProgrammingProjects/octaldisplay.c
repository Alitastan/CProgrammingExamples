#include <stdio.h>

int main(void)
{
    int userInput, firstDigit, secondDigit, thirdDigit, fourthDigit, fifthDigit;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &userInput);

    fifthDigit = userInput % 8;
    fourthDigit = (userInput / 8) % 8;
    thirdDigit = (userInput / (8 * 8)) % 8;
    secondDigit = (userInput / (8 * 8 * 8)) % 8;
    firstDigit = (userInput / (8 * 8 * 8 * 8)) % 8;

    printf("In octal, your number is: %d%d%d%d%d", firstDigit, secondDigit,
        thirdDigit, fourthDigit, fifthDigit);

    return 0;
}