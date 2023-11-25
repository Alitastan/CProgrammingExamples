/* 
*   One of the oldest known encryption techniques is the    
*   Ceaser cipher, attributed to Julius Caesar. it involves
*   replacing each letter in a message with another letter
*   that is fixed number of positions letter in the alphabet.
*   (if the replacement would go past the letter Z, the cipher
*   "wraps around" to the beginning of the alphabet.)
*/

#include <stdio.h>
#include <ctype.h>


#define MESSAGE_LEN 80

int main (void)
{
    char message[MESSAGE_LEN];
    int shiftAmount;
    int messageLength;

    printf("Enter message to be encrpyted: ");
    
    for (int i = 0; i < MESSAGE_LEN; i++)
    {
        scanf("%c", &message[i]);

        // Check for the end of input or newline character
        if (message[i] == '\n' || message[i] == '\0')
        {
            messageLength = i;
            message[i] = '\0'; // Null terminate the string

            break;
        }
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shiftAmount);

    printf("Encrypted message: ");

    for (int i = 0; i < messageLength; i++)
    {
        if (isupper(message[i]))
        {
            char encrypted;
            encrypted = ( (message[i] - 'A') + shiftAmount) % 26 + 'A';
            message[i] = encrypted;
        }
        else if (islower(message[i]))
        {
            char encrypted;
            encrypted = ( (message[i] - 'a') + shiftAmount) % 26 + 'a';
            message[i] = encrypted;
        }
        else
        {

        }
        printf("%c", message[i]);
    }



}