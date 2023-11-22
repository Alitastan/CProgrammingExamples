#include <stdio.h>

int main (void)
{
    int userInput, digitCount;

    printf("Enter a number between 0-9999: ");
    scanf("%d", &userInput);

    if (userInput >= 0 && userInput <= 9)
    {
        digitCount = 1;
        printf("The number %d has %d digits.", userInput, digitCount);
    }
    else if (userInput >= 10 && userInput <= 99)
    {
        digitCount = 2;
        printf("The number %d has %d digits.", userInput, digitCount);
    }
    else if (userInput >= 100 && userInput <= 999)
    {
        digitCount = 3;
        printf("The number %d has %d digits.", userInput, digitCount); 
    }
    else
    {
        digitCount = 4;
        printf("The number %d has %d digits.", userInput, digitCount);
    }  

}