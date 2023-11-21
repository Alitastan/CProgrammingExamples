#include <stdio.h>

int main (void)
{
    int userInput, firstDigit, secondDigit;

    firstDigit = 0; 
    secondDigit = 0;
    
    printf("Enter a two-digit number: ");
    scanf("%d", &userInput);

    if (userInput < 0 || userInput > 100)
    {
        printf("The grade is not valid.");
        return -1;
    }

    firstDigit = userInput % 10;
    secondDigit = userInput / 10;

    switch (secondDigit)
    {
        case 10: case 9: printf("A"); break;
        case 8: printf("B"); break;
        case 7: printf("C"); break;
        case 6: printf("D"); break;
        case 5: case 4: case 3: case 2: case 1: case 0: printf("F"); break;
        default: printf("ERROR!"); break;
    }

    return 0;
}