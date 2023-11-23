#include <stdio.h>
#include <stdbool.h>

int main (void)
{
    bool digitSeen[10] = {false};
    int digitSeenCount[10] = {0};
    int digit;
    long long userInput;

    printf("Enter a number to test if there are any repeating digits: ");
    scanf("%lld", &userInput);

 

    // Determine which digits were repeated.

    while (userInput > 0)
    {
        digit = userInput % 10;
        digitSeenCount[digit] += 1;
      
        digitSeen[digit] = true;
        userInput /= 10;
    }

    // Print digits and number of occurrences

    printf("\n\nDigit:\t\t ");
    for (int i = 0; i < 10; i++)
        printf("%2d ", i);

    printf("\n");

    printf("Occurences:\t ");
    for (int i = 0; i < 10; i++)
        printf("%2d ", digitSeenCount[i]);

    return 0;
}