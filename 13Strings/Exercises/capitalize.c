/**
 * Write a function named capitalize that capitalizes all letters in
 * its argument. The argument will be a null-terminated string contain-
 * ing arbitrary characters, not just letters. Use array subscripting
 * to access the characters in the string.
 * 
 * Hint: Use the toupper function to convert each character to upper-case
 * 
*/

#include <stdio.h>
#include <ctype.h>

#define MESSAGE_LEN 40

void capitalize_me (char *letters, int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        if (letters[i] != '\0')
        {
            letters[i] = toupper(letters[i]);
        }
    }

}

void capitalize_me_2 (char *letters)
{

    while (*letters)
    {
        *letters = toupper(*letters);
        letters++;
    }

}

int read_letters (char *letters, int length)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < length)
            letters[i++] = ch;
    
    letters[i] = '\0'; // Null terminate the string
    return i; // Number of characters stored

}

int main (void)
{
    char letters[MESSAGE_LEN + 1];
    int length = 0;

    printf("Enter your message: ");
    length = read_letters (letters, MESSAGE_LEN);

    //capitalize_me (letters, MESSAGE_LEN);
    capitalize_me_2 (letters);

    puts (letters);
    printf("Length of the message: %d\n", length);

    return 0;



}