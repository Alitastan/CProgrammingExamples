#include <stdio.h>

int main (void)
{
    char ch;
    int len = 0;

    printf("Enter your message: ");
    ch = getchar();
    while (ch != '\n')
    {
        len++;
        ch = getchar();
    }
    printf("Your message was %d character(s) long. ", len);

    return 0;
}