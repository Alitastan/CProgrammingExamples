/**
 * Write a function named censor that modifies a string by replacing
 * every occurence of foo by xxx.
 * 
 * For example, the string "food fool" would become "xxxd xxxl". 
 * 
 * Make the function as short as possible without sacrificing clarity.
*/

#include <stdio.h>
#include <string.h>

#define INPUT_MSG_LEN   40

void censor (char *message)
{
    int i;

    for (i = 0; message[i] != '\0'; i++)
    {
        if (message[i] == 'f' 
        && message[i + 1] == 'o' 
        && message[i + 2] == 'o')
        {
            message[i] = message[i + 1] = message[i + 2] = 'x';
        }
    }
}

void censor_2 (char *message)
{
    while (*message)
    {
        /**
         * Note that the short-circuit evaluation of && prevents
         * the if statement from testing characters that follow
         * the null character.
        */
        if (*message == 'f' 
        && *(message + 1) == 'o' 
        && *(message + 2) == 'o')
        {
            *message = *(message + 1) = *(message + 2) = 'x';
        }
        message++;
    }
}

int main (void)
{
    char message_buffer[INPUT_MSG_LEN];

    printf("Enter your message: ");
    gets_s(message_buffer, INPUT_MSG_LEN);

    puts(message_buffer);

    censor_2(message_buffer);

    puts(message_buffer);

    return 0;
}