/* Write a program that tests whether two words are anagrams */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#define ARRAY_LEN   26

// ASCII a letter is int(97) and z letter is int(122)
#define ASCII_A     97
#define ASCII_Z     122


bool are_anagrams (const char *word1, const char *word2);
int read_line (char *str, int n);


int main (void)
{
    int letterCount[ARRAY_LEN] = {0};
    char first_word[ARRAY_LEN + 1], second_word[ARRAY_LEN + 1];

    bool isAnagram = false;

    printf ("\nEnter first word: ");
    read_line (first_word, ARRAY_LEN);

    printf ("\nEnter second word: ");
    read_line (second_word, ARRAY_LEN);


    isAnagram = are_anagrams(first_word, second_word);

    if (isAnagram)
        printf("The words are anagrams!\n");
    else
        printf("The words are not anagrams!\n");

    return 0;

}


/**
 * The function returns true if the strings pointed to by
 * word1 and word2 are anagrams.
*/
bool are_anagrams (const char *word1, const char *word2)
{
    int letter_count[ARRAY_LEN] = {0};
    int i;

    while (*word1)
    {
        letter_count[*word1 - ASCII_A] += 1;
        word1++;
    }

    while (*word2)
    {
        letter_count[*word2 - ASCII_A] -= 1;
        word2++;
    }

    // Check if the word counts are matched and return
    for (i = 0; i < ARRAY_LEN; i++)
    {
        if (letter_count[i])
            return false;
    }

    return true;

}

/**
 * Read only if the inputs are alphabets.
*/
int read_line (char *str, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n && isalpha(ch))
            str[i++] = tolower(ch);


    str[i] = '\0';
    return i;
}