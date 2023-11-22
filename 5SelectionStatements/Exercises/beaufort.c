#include <stdio.h>

int main (void)
{
    int userInput;

    printf("Enter a wind speed (in knots): ");
    scanf("%d", &userInput);

    if (userInput < 1)
    {
        printf("Calm.");
    }
    else if (userInput <= 3)
    {
        printf("Light air.");
    }
    else if (userInput <= 27)
    {
        printf("Breeze.");
    }
    else if (userInput <= 47)
    {
        printf("Gale.");
    }
    else if (userInput <= 63)
    {
        printf("Storm.");
    }
    else printf("Hurricane.");

    return 0;
}