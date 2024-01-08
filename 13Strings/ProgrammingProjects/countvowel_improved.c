#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT_LEN   50

int compute_vowel_count (const char *sentence);
int read_line (char *str, int n);

int main (void)
{
    char user_input[MAX_INPUT_LEN];

    printf("Enter your sentence: ");
    read_line(user_input, MAX_INPUT_LEN);

    printf("Your sentence contains %d vowels\n", compute_vowel_count(user_input));
}


int read_line (char *str, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    
    str[i] = '\0';

    return i;
}

int compute_vowel_count (const char *sentence)
{
    int count = 0;

    while (*sentence)
    {
        switch (toupper(*sentence++))
        {
            case 'A': case 'E': case 'I': case 'O': case 'U':
                count++; break;
        }
    }

    return count;
}