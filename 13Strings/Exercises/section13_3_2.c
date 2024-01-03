#include <stdio.h>

int main (void)
{
    char *p = "abc";
    //putchar(p); not valid since putchar expects an integer as an argument
    //putchar(*p); legal. points to the first char element of the string
    puts(p); // legal
    //puts(*p);
}