#include <stdio.h>
#include <stdbool.h>

int main (void)
{
    bool digitSeen[10] = {false};
    int digit;
    long userInput;

    printf("Enter a number to test if there are any repeating digits: ");
    scanf("%ld", &userInput);

    while (userInput > 0)
    {
        digit = userInput % 10;
        if (digitSeen[digit])
            break;
        
        digitSeen[digit] = true;
        userInput /= 10;
    }

    if (userInput > 0)
        printf("Repeated digit.\n");
    else
        printf("No repeated digit.\n");

    return 0;
}