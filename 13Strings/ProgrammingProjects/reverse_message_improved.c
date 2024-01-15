
#include <stdio.h>

#define MESSAGE_LEN 100

void reverse (char *message);

int main (void)
{
    char message[MESSAGE_LEN];

    printf ("Enter your message: ");
    gets_s (message, MESSAGE_LEN);

    printf("Original message: ");
    puts (message);

    reverse (message);
    
    printf("Message reversed: ");
    puts (message);

    return 0;

}


/**
 * The function reverses the string pointed to by message.
 * 
 * Hint: Use two pointers, one initially pointing to the
 * first character of the string and the other initially
 * pointing to the last character. Have the function reverse
 * these characters and then move the pointers towards each
 * other, repeating the process until the pointers meet.
*/
void reverse (char *message)
{
    char *first_ptr, *second_ptr, temp;

    // Store the address of the first character
    first_ptr = second_ptr = message;

    // Move second_ptr through the null character
    while (*message)
    {
        message++;
        second_ptr++;
    }

    // Decrease second_ptr to point to the last character
    second_ptr--;

    while (first_ptr < second_ptr)
    {
        temp = *first_ptr;
        *first_ptr = *second_ptr;
        *second_ptr = temp;
        first_ptr++;
        second_ptr--;
    }

}

