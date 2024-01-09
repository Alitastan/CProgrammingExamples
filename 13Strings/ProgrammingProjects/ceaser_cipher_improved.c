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
#include <string.h>

void encrypt (char *message, int shift);
void encrypt_v2 (char *message, int shift);
int read_line (char *str, int n);

#define MESSAGE_LEN 80

int main (void)
{
    char message[MESSAGE_LEN + 1];
    int shift_amount;

    printf("Enter message to be encrpyted: ");
    
    read_line (message, MESSAGE_LEN);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift_amount);

    encrypt_v2(message, shift_amount);

    printf("Encrypted message: ");

    puts(message);


}

/**
 * This function expects message to point to a string containing
 * the message to be encrypted; shift represents the amount by
 * which each letter in the message is to be shifted.
*/
void encrypt (char *message, int shift)
{
    for (int i = 0; i < strlen(message); i++)
    {
        if (isupper(message[i]))
        {
            char encrypted;
            encrypted = ( (message[i] - 'A') + shift) % 26 + 'A';
            message[i] = encrypted;
        }
        else if (islower(message[i]))
        {
            char encrypted;
            encrypted = ( (message[i] - 'a') + shift) % 26 + 'a';
            message[i] = encrypted;
        }
        else{}

    }
}

void encrypt_v2 (char *message, int shift)
{
    while (*message)
    {
        if (isupper(*message))
        {
            char encrypted;
            encrypted = ( (*message - 'A') + shift) % 26 + 'A';
            *message = encrypted;
        }
        else if (islower(*message))
        {
            char encrypted;
            encrypted = ( (*message - 'a') + shift) % 26 + 'a';
            *message = encrypted;
        }
        else{}

        message++;
    }
}

int read_line (char *str, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    
    str[i] = '\0';
    return i;
}