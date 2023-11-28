/* Write a program that tests whether two words are anagrams */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#define ARRAY_LEN   26

// ASCII a letter is int(97) and z letter is int(122)
#define ASCII_A     97
#define ASCII_Z     122


bool letterOccurence (int array[], int n);

void readCharacterUp (char ch, int count[], bool seen[]);

void readCharacterDown (char ch, int count[], bool seen[]);



int main (void)
{
    bool letterSeen[ARRAY_LEN] = {false};
    int letterCount[ARRAY_LEN] = {0};
    char ch;

    bool isAnagram = false;

    printf ("\nEnter first word: ");

    readCharacterUp(ch, letterCount, letterSeen);

    printf ("\nEnter second word: ");

    readCharacterDown(ch, letterCount, letterSeen);

    isAnagram = letterOccurence(letterCount, ARRAY_LEN);

    if (isAnagram)
        printf("Letters are anagrams!\n");
    else
        printf("Letters are not anagrams!\n");

    return 0;
}


bool letterOccurence (int array[], int n)
{
    printf("Letters a-z:\n\t");
    for (int i = ASCII_A; i <= ASCII_Z; i++)
        printf("%3c", i);

    printf("\n\t");

    for (int i = 0; i < n; i++)
    {
        printf("%3d", array[i]);   
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        if (array[i] != 0)
            return false;
    }

    return true;
}

void readCharacterUp (char ch, int count[], bool seen[])
{
    while ((ch = getchar()) != '\n')
    {
        ch = tolower(ch);
        // if ch read is alphabet letter it returns non-zero value
        if (isalpha(ch) != 0)
        {
            count[ch - ASCII_A] += 1;
            seen[ch - ASCII_A] = true;
        }
    }
}

void readCharacterDown (char ch, int count[], bool seen[])
{
    while ((ch = getchar()) != '\n')
    {
        ch = tolower(ch);
        // if ch read is alphabet letter it returns non-zero value
        if (isalpha(ch) != 0)
        {
            count[ch - ASCII_A] -= 1;
            seen[ch - ASCII_A] = true;
        }
    }
}

