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
    char message_buffer[MESSAGE_LEN];
    int position = 0;
    char input;
    bool is_palindrome = true;
    int reverse_pos = 0;

    printf("Enter a message: ");

    for (; position < MESSAGE_LEN, input = tolower(getchar()); )
    {
        if (input == '\n')
            break;

        if (isalpha(input))
        {
            message_buffer[position] = input;
            position++;
        }
        
    }




    // for new line character
    position--;

    for ( ; position >= 0; position--, reverse_pos++)
    {
        if (message_buffer[reverse_pos] != message_buffer[position])
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