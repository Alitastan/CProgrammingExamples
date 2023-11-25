/*  
*   Store SCRABBLE values of the letters in an array.   
*   The array will have 26 elements, corresponding to the
*   the 26 letters of the alphabet. For example, element 0
*   will store 1, element 1 of the array will store 3 (because
*   the scrabble value of the letter B is 3.) and so forth.
*   As each character of the input word is read, the program will
*   use the array to determine the SCRABBLE value of the character.
*   Use an array initializer to set up the array.
*/

#include <ctype.h>
#include <stdio.h>

#define ASCII_A_CHAR    65
#define ASCII_ALPHABET_RANGE    26  

int main (void)
{
    int scrabbleValues[ASCII_ALPHABET_RANGE] = {0};
    char scrabbleAlphabet[ASCII_ALPHABET_RANGE] = {'.'};
    char keyword;
    int value = 0, sum = 0, i;
    
    // Initialize all scrabbleValues to 0
    for (int i = 0; i < ASCII_ALPHABET_RANGE; i++)
    {
        scrabbleValues[i] = 0;
    }

    // Initialize scrableAlphabet and set up scrabbleValues
    for (int i = 0; i < ASCII_ALPHABET_RANGE; i++)
    {
        scrabbleAlphabet[i] = ASCII_A_CHAR + i;
        printf(" %c", scrabbleAlphabet[i]);

        switch (scrabbleAlphabet[i])
        {
            case 'D': case 'G': 
                value = 2; break;
            case 'B': case 'C': case 'M': case 'P':
                value = 3; break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                value = 4; break;
            case 'K':
                value = 5; break;
            case 'J': case 'X':
                value = 8; break;
            case 'Q': case 'Z':
                value = 10; break;
            default:
                value = 1; break;
        }

        scrabbleValues[i] = value;

    }

    printf("\n");

    for (int i = 0; i < ASCII_ALPHABET_RANGE; i++)
    {
        printf(" %d", scrabbleValues[i]);
    }

    printf("\n\nEnter a sentence: ");

    // Works only with ASCII character set
    while ( (keyword = getchar()) != '\n')
    {
        keyword = toupper(keyword);
        int index = keyword - ASCII_A_CHAR;

        if (index >= 0 && index < ASCII_ALPHABET_RANGE)
            sum += scrabbleValues[index];

    }

    printf("\nSCRABBLE value of the sentence: %d\n", sum);

    return 0;
}