/**
 * Formats a file of text
 * 
 * Heart of the program
 * 
 * for (;;)
 * {
 *      read word;
 *      if (can't read word)
 *      {
 *          write contents of line buffer without justification;
 *          terminate program;
 *      }
 *      if (word doesn't fit in line buffer)
 *      {
 *          write contents of line buffer with justification;
 *          clear line buffer;
 *       }
 *       add word to line buffer;
 * 
 *      You can use input and output redirection for a given quote
 *  file as input as follows:
 * 
 *  1) make justify
 *  2) justify <quote >newquote
 * 
 *  Where I used justify < Unjustified_text.txt > newText.txt
 * }
*/

#include "line.h"
#include "word.h"

#define MAX_WORD_LEN    20

int main (void)
{
    char word[MAX_WORD_LEN + 2];
    int word_len;

    clear_line();
    
    for (;;)
    {
        word_len = read_word(word, MAX_WORD_LEN + 1);

        if (word_len == 0)
        {
            flush_line();
            return 0;
        }

        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
            
        if (word_len + 1 > space_remaining())
        {
            write_line();
            clear_line();
        }
        add_word(word);
    }
}
