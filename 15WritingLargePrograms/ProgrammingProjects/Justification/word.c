#include <stdio.h>
#include "word.h"

int read_char (void)
{
    int ch = getchar();

    return (ch == '\n' || ch == '\t') ? ' ' : ch;

}

int read_word (char *word, int len)
{
    int ch, pos = 0;

    // Skip spaces
    while ((ch = read_char()) == ' ')
    ;

    // Read until encountering space or EOF
    while (ch != ' ' && ch != EOF)
    {
        if (pos < len)
            word[pos++] = ch;
        if (pos > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        
        ch = read_char();
    }
    word[pos] = '\0';
    return pos;
}