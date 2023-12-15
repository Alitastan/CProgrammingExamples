#include <stdio.h>

#define BUFFER_SIZE     100

int main (void)
{
    char message_buffer[BUFFER_SIZE];
    int i;
    printf("Enter a message: ");

    for (i = 0; i < BUFFER_SIZE; i++)
    {
        message_buffer[i] = getchar();
        if (message_buffer[i] == '\n')
            break;
    }

    printf("Reversal is: ");
    for (i--; i >= 0; i--)
        putchar(message_buffer[i]);
    putchar('\n');

    return 0;
}