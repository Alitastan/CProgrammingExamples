#include <stdio.h>

int main (void)
{
    int i, j;
    char s[100];
    printf("Enter your data: ");
    /**
     * When scanf is called, it skips white space, then reads characters
     * and stores them in s until it encounters a white space character.
     * Scanf always stores a null character at the end of the string.
    */
    scanf("%d%s%d", &i, s, &j);

    printf("i: %d, j: %d\n", i, j);
    puts(s);
}