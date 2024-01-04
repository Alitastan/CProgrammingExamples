





#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE  30


int my_strcmp (char *s, char *t);
int p_my_strcmp (char *s, char *t);

int main (void)
{
    char s1[ARRAY_SIZE], s2[ARRAY_SIZE];

    strcpy (s1, "computer");
    strcpy (s2, "science");

    if (p_my_strcmp (s1, s2) < 0)
        strcat (s1, s2);
    else
        strcat (s2, s1);
    
    s1[strlen(s1) - 6] = '\0';

    puts (s1);
}




int my_strcmp (char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    
    return s[i] - t[i];
    
}

// Rewriting my_strcmp function using pointer arithmetic instead.

int p_my_strcmp (char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s)
            return 0;
    
    return *s - *t;
}