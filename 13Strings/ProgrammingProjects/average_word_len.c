#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LEN   100

double compute_average_word_length (const char *sentence);
int read_line (char *str, int n);

int main (void)
{
    char user_input[MAX_INPUT_LEN];
    printf ("Enter a sentence: ");
    read_line(user_input, MAX_INPUT_LEN);

    printf("Average word count: %f\n",
         compute_average_word_length(user_input));

    return 0;
}

double compute_average_word_length (const char *sentence)
{
    int sentence_len = strlen(sentence);
    int space_count = 0;

    int letter_count = 0;

    while (*sentence)
    {
        if (*sentence++ == ' ')
            space_count++;
        
    }

    letter_count = sentence_len - space_count;
    printf("Sentence length: %d\n", sentence_len);
    printf("Space count: %d\n", space_count);

    return (double) letter_count / space_count;

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