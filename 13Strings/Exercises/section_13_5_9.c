

#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE  30

int main (void)
{
    char s1[ARRAY_SIZE], s2[ARRAY_SIZE];

    strcpy (s1, "computer");
    strcpy (s2, "science");

    if (strcmp (s1, s2) < 0)
        strcat (s1, s2);
    else
        strcat (s2, s1);
    
    s1[strlen(s1) - 6] = '\0';

    puts (s1);
}