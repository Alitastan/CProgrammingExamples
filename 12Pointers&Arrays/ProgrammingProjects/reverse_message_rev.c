#include <stdio.h>

#define BUFFER_SIZE     100

int main (void)
{
    char message_buffer[BUFFER_SIZE], *p_msg;

    printf("Enter a message: ");
    for (p_msg = &message_buffer[0]; p_msg < &message_buffer[BUFFER_SIZE]; p_msg++)
    {
        *p_msg = getchar();
        if (*p_msg == '\n')
            break;
    }

    printf("Reversal is: ");
    
    // for new line character
    p_msg--;
    for ( ; p_msg >= &message_buffer[0]; p_msg--)
    {
        putchar(*p_msg);
    }

    putchar('\n');

    return 0;


}