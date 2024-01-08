#include <ctype.h>
#include <stdio.h>

#define MAX_INPUT_LEN   100

int compute_scrabble_value (const char *word);
int read_line (char *str, int n);

int main (void)
{
    char user_input[MAX_INPUT_LEN];

    printf("Enter a word: ");
    read_line(user_input, MAX_INPUT_LEN);


    printf("Scrabble value: %d\n",
        compute_scrabble_value(user_input));

    return 0;
}


int compute_scrabble_value (const char *word)
{
    int scrabble_value = 0;

    while (*word)
    {
        switch (toupper(*word++))
        {
            case 'D': case 'G': 
                scrabble_value += 2; break;
            case 'B': case 'C': case 'M': case 'P':
                scrabble_value += 3; break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                scrabble_value += 4; break;
            case 'K':
                scrabble_value += 5; break;
            case 'J': case 'X':
                scrabble_value += 8; break;
            case 'Q': case 'Z':
                scrabble_value += 10; break;
            default:
                scrabble_value++; break;
        }
    }

    return scrabble_value;
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

