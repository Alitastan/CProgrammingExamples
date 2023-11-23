#include <stdio.h>


int main (void)
{
    int digitSeenCount[10] = {0};
    long long userInput;
    int digit;
    int i;

    for(;;)
    {
        printf("\nEnter a number less than or equal to 0 to terminate the program.\n");
        printf("Enter a number to test repeating digits: ");
        scanf("%lld", &userInput);

        if (userInput <= 0)
        {
            printf("Terminating the program!\n");
            return -1;
        }

        while (userInput > 0)
        {
            digit = userInput % 10;
            digitSeenCount[digit]++;
            userInput /= 10;

        }

        printf("\n\nDigit:\t\t ");
        for (i = 0; i < 10; i++)
            printf("%2d ", i);

        printf("\n");

        printf("Occurences:\t ");
        for (i = 0; i < 10; i++)
            printf("%2d ", digitSeenCount[i]);

        // Reset digit seen count for next query
        for (i = 0; i < 10; i++)
            digitSeenCount[i] = 0;
    }

    return 0;
}