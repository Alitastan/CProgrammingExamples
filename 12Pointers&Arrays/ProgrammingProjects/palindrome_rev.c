/**
 * Write a program that reads a message, then checks whether it's a
 * palindrome (the letters in the message are the same from left to
 * right as from right to left):
*/


#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MESSAGE_LEN 100

int main (void)
{
    char message_buffer[MESSAGE_LEN], *position;
    bool is_palindrome = true;
    char *input = &message_buffer[0], *reverse_input = &message_buffer[0];
    printf("Enter a message: ");

    for (position = &message_buffer[0]; position < &message_buffer[MESSAGE_LEN]; input++ )
    {
        *input = tolower(getchar());
        if (*input == '\n')
            break;

        if (isalpha(*input))
        {
            *position = *input;
            position++;
        }
        
    }


    // for new line character
    position--;

    for ( ; position >= &message_buffer[0]; position--, reverse_input++)
    {
        if (*reverse_input != *position)
        {
            is_palindrome = false;
            break;
        }

    }

    putchar('\n');

    if (is_palindrome)
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");


    return 0;

}