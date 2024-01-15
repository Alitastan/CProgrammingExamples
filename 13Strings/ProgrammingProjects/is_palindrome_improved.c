/**
 * Write a program that reads a message, then checks whether it's a
 * palindrome (the letters in the message are the same from left to
 * right as from right to left):
*/


#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MESSAGE_LEN 100

bool is_palindrome (const char *message);
int read_line (char *str, int n);

int main (void)
{
    char message_buffer[MESSAGE_LEN];

    printf("Enter a message: ");
    read_line(message_buffer, MESSAGE_LEN);

    puts(message_buffer);
 
    if (is_palindrome(message_buffer))
        printf("Palindrome");
    else
        printf("Not palindrome");

    return 0;

}

/**
 * The function returns true if the string pointed to by
 * message is a palindrome.
*/
bool is_palindrome (const char *message)
{
    const char *position, *reverse_position;

    position = reverse_position = message;

    while (*message)
    {
        message++;
        reverse_position++;
    }

    reverse_position--;

    while (position < reverse_position)
    {
        if (*position++ != *reverse_position--)
            return false;
    }

    return true;
}

int read_line (char *str, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {
        ch = tolower(ch);

        if (i < n && isalpha(ch))
        {
            str[i++] = ch;

        }

    }

    str[i] = '\0';

    return i;
}
