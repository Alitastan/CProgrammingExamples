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

#include <stdio.h>

#define SENTENCE_LENGTH 100

int main (void)
{
    char sentence[SENTENCE_LENGTH], index;
    char *p_sentence, *p_space_location, *p_start_index, *p_word_location;

    printf("Enter a sentence: ");

    for (p_sentence = &sentence[0]; p_sentence < &sentence[SENTENCE_LENGTH]; p_sentence++)
    {
        *p_sentence = getchar();

        if (*p_sentence == '\n') break;

        if (*p_sentence == '?' ||
            *p_sentence == '!' ||
            *p_sentence == '.')
        {
            index = *p_sentence;
            printf("Caught index: %c\n", index );
            break;
        }

    }


/*
*   Then use a second loop to search backward through the array for the
*   beginning of the last word. Print the last word, then search
*   backward for the next-to-last word. Repeat until the beginning of
*   the array is reached. Finally, print the terminating character.
*/

    p_sentence--;
    p_start_index = p_sentence;

    for (; p_sentence >= &sentence[0]; p_sentence--)
    {
        //putchar(*p_sentence);

        // if space is encountered
        if (*p_sentence == ' ' || *p_sentence == '\n')
        {
            // save the space location
            p_space_location = p_sentence;

            p_word_location = p_space_location + 1;

            while (p_word_location <= p_start_index && *p_word_location != ' ')
            {
                printf("%c", *p_word_location);
                p_word_location++;
            }

            printf(" ");
        }

    }

    // Editing the last word
    p_start_index = &sentence[0];
    while (*p_start_index != ' ')
    {
        printf("%c", *p_start_index);
        p_start_index++;
    }

    // Placing the index
    printf("%c", index);
}