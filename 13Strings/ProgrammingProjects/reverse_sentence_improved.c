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
#include <string.h>

#define SENTENCE_LEN    30
#define MAX_WORD_LEN    20
#define FINAL_STRING_LEN    (SENTENCE_LEN * MAX_WORD_LEN)
#define APOSTROPHE      39


int read_line_no_punc (char str[], char *punctuation, int n);

int main (void)
{
  
    char words_array[SENTENCE_LEN][MAX_WORD_LEN + 1];
    char final_string[FINAL_STRING_LEN + 1], final_punct_string[2];
    char final_punctuation;
    int word_count = 0, i;

    printf("Enter a sentence: ");
    

    while (word_count < SENTENCE_LEN)
    {
        int word_len = 0;

        word_len = read_line_no_punc(words_array[word_count], &final_punctuation, MAX_WORD_LEN);

        if (word_len < MAX_WORD_LEN)
            word_count++;

        else if (word_len == MAX_WORD_LEN)
        {
            printf("Too much words entered! Please enter again: ");
            continue;
        }
        else{}

        // Check for punctuation and exit the loop only if the word count is reached
        if (ispunct(final_punctuation))
            break;

    }




    sprintf(final_punct_string, "%c", final_punctuation);

    printf("\nWords in Reverse\n");
    for (i = word_count; i >= 0; i--)
    {
        strcat(final_string, words_array[i]);
        if (i != word_count && i != 0)
            strcat(final_string, " ");
    }

    strcat(final_string, final_punct_string);
    puts(final_string);
    

    return 0;
}

int read_line_no_punc (char str[], char *punctuation, int n)
{
    int ch, i = 0;
    
    while (!isspace(ch = getchar()))
    {
        if (i < n)
        {
            // We want to store words such as can't isn't but not in the first letter
            if (ch == APOSTROPHE && i > 0)
            {
                str[i++] = ch;
                continue;
            }
            // Save only non punctuations
            if (!ispunct(ch))
                str[i++] = ch;
            else
            {
                // Save the final punctuation
                *punctuation = ch;
                
            } 
        }
    }


    str[i] = '\0';
    return i;
}

