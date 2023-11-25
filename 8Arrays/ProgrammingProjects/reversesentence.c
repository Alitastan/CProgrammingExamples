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

#define MAX_INPUT_LENGTH        100
#define TERMINATING_CHAR_LEN    3

int main (void)
{
    char readCharacter[MAX_INPUT_LENGTH] = {'.'};
    char reversedCharacters[MAX_INPUT_LENGTH] = {'.'};
    char index[TERMINATING_CHAR_LEN] = {'?', '!', '.'};

    int i, sentenceLength = 0;
    char lastWord, finalIndex;
    int startIndex = 0;
    int jumpLocation = 0;

    printf("Enter a sentence: ");

    for (i = 0; i < MAX_INPUT_LENGTH, (readCharacter[i] = getchar()) != '\n'; i++)
    {   

        // Break if ? ! or . is encountered
       if (readCharacter[i] == (finalIndex = index[0]) ||
            readCharacter[i] == (finalIndex = index[1]) ||
            readCharacter[i] == (finalIndex = index[2]))
            {
                // Determine the length of the sentence
                sentenceLength = i;
                printf("\nFinal Index: %c\n", finalIndex);
                printf("Sentence length: %d\n\n", sentenceLength);
                break;
            }
   
 
    }

    // Reverse the sentence and place it in reversedCharacter array.
    printf("Reversed array: ");
    for (i = 0; i <= sentenceLength; i++)
    {
        reversedCharacters[i] = readCharacter[sentenceLength - i];
        //putchar(reversedCharacters[i]);
        printf("%c", reversedCharacters[i]);
    }

    printf("\n");

    
    for (i = 1; i < sentenceLength; i++)
    {
        // if space is encountered start the index
        // from the first reversed word's last letter
        // and read it backwards.
        if (reversedCharacters[i] == ' ')
        {
            jumpLocation = i;
            startIndex = jumpLocation - 1;

            while (startIndex > 0 && reversedCharacters[startIndex] != ' ')
            {
                printf("%c", reversedCharacters[startIndex]);
                startIndex--;             
            }

            printf(" ");
        }

    }

    // Print the last word (handling the special case of the last word)
    startIndex = sentenceLength;
    while (startIndex > 0 && reversedCharacters[startIndex] != ' ') {
        printf("%c", reversedCharacters[startIndex]);
        startIndex--;
    }

    // Print the terminating character
    printf("%c", finalIndex);



    
    
    
/*    
*   Then use a second loop to search backward through the array for the
*   beginning of the last word. Print the last word, then search
*   backward for the next-to-last word. Repeat until the beginning of
*   the array is reached. Finally, print the terminating character
*/
  

    


    return 0;
}