#include <stdio.h>

int main (void)
{
    char ch;
    int len = 0;

    printf("Enter your message: ");

    while (getchar() != '\n')
        len++;

    printf("Your message was %d character(s) long.", len);

    return 0;
        
    

}