/*  
*   Write a program that reverses the words in a sentence   
*   Enter a sentence: you can cage a swallow can't you?
*   Reversal of sentence: you can't swallow a cage can you?
*   
*   Hint: Use a loop to read the characters one by one and store
*   them in a one-dimensional char array. Have the loop stop at a
*   period, question mark, or exclamation point (the "terminating
*   character"), which is saved in a separate char variable. Then
*   use a second loop to search backward through the array for the
*   beginning of the last word. Print the last word, then search
*   backward for the next-to-last word. Repeat until the beginning of
*   the array is reached. Finally, print the terminating character.
*/

/**
 * Modify this project so that it stores the words in a two dimensional
 * char array as it reads the sentence, with each row of the array storing
 * a single word. Assume that the sentence contains no more than 30 words
 * and no word is more than 20 characters long. Be sure to store a null
 * character at the end of each word so that it can be treated as a string.
 * 
*/



#include <stdio.h>
#include <ctype.h>

#define SENTENCE_LEN    3
#define MAX_WORD_LEN    (SENTENCE_LEN * 20) 


int read_line_no_punc (char str[], int n);

int main (void)
{
  
    char words_array[SENTENCE_LEN][MAX_WORD_LEN + 1];
    int word_len = 0, i;
    char final_punctuation;


    for(;;)
    {
        printf("Enter a sentence: ");

        if (word_len == SENTENCE_LEN)
        {
            printf("-- No space left to store -- \n");
            break;
        }

        read_line_no_punc(words_array[word_len], MAX_WORD_LEN );

        word_len++;
    }


    printf("\nWords Entered\n");
    for (i = 0; i < word_len; i++)
        printf("%s\n", words_array[i]);
    

    return 0;
}

int read_line_no_punc (char str[], int n)
{
    int ch, i = 0;

    while (!isspace(ch = getchar()))
        if (i < n)
            if (!ispunct(ch))
                str[i++] = ch;
            else continue;

    str[i] = '\0';
    return i;
}