/**
 * Suppose that we need a function that counts the number of spaces
 * in a string. Using array subscripting, we might write the function
 * in the following way:
*/

/**
 * Since s is a string we don't need a second argument specifying its length
 * The function can determine the length of the string by checking the null
 * character.
*/

#include <stdio.h>

int count_spaces (const char s[]);
int count_spaces_2 (const char *s);
int count_spaces_3 (const char *s);
int count_spaces_4 (const char *s);


int main (void)
{

    char str[] = "We are going to have fun!";
    int space_count = 0;

    space_count = count_spaces_4(str);
    printf("Space Count: %d\n", space_count);

    return 0;
}



int count_spaces (const char s[])
{
    int count = 0, i;

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == ' ')
            count++;
    return count;
}


int count_spaces_2 (const char *s)
{
    int count = 0;

    for (; *s != '\0'; s++)
        if (*s == ' ')
            count++;
    return count;
}

int count_spaces_3 (const char *s)
{
    int count = 0;

    while (*s)
    {
        if (*s == ' ')
            count++;
        
        s++;
    }

    return count;
}

int count_spaces_4 (const char *s)
{
    int count = 0;

    while (*s)
        if (*s++ == ' ')
            count++;
    
    return count;

    
}


