/*  BIFF filter substitutes characters with the following characters
*   H3Y DUD3 C 15 R1LLY C00L!!!!!!! (I might use this later :p)
*
*   Substitute characters: 
*   A -> 4, B -> 8, E -> 3, I -> 1, O -> 0, S -> 5
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH    100

int main (void)
{
    // Array of characters to store the message
    char userInput[MAX_INPUT_LENGTH];
    int i;

    printf("Enter your BIFF text please: ");

    // Take the input into the array
    for (i = 0; i < MAX_INPUT_LENGTH; i++)
    {
        scanf("%c", &userInput[i]);

        // Check for the end of input or newline character
        if (userInput[i] == '\n' || userInput[i] == '\0')
        {
            userInput[i] = '\0'; // Null terminate the string
            break;
        }
    }

    // Determine the length of the string
    int inputLength = strlen(userInput);

    // Declare new array
    char newUserInput[inputLength];

    // Initialize it with the actual user input and input length
    for (i = 0; i < inputLength; i++)
    {
        newUserInput[i] = userInput[i];
    }


    // Convert the message to upper-case letters
    for (i = 0; i < inputLength; i++)
    {
        newUserInput[i] = toupper(newUserInput[i]);
    }

    // Go back through the array, translate and print characters
    for (i = 0; i < inputLength; i++)
    {
        switch (newUserInput[i])
        {
            case 'A':
                newUserInput[i] = '4'; break;
            case 'B':
                newUserInput[i] = '8'; break;
            case 'E':
                newUserInput[i] = '3'; break;
            case 'I':
                newUserInput[i] = '1'; break;
            case 'O':
                newUserInput[i] = '0'; break;
            case 'S':
                newUserInput[i] = '5'; break;
            default:
                break;
        }
    }

    printf("\nIn BIFF speak: ");

    // Print the final array
    for (i = 0; i < inputLength; i++)
    {
        printf("%c", newUserInput[i]);
    }

    // Append some exclamation marks
    printf(" !!!!!!!!!");
}