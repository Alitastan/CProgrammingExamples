#include <stdio.h>

int main (void)
{

    char ch;
    int spaceCount = 0, totalLengthWithSpaces = 0, wordCount = 0;
    float averageWordLength = 0.0f;

    printf ("Enter a sentence: ");

    
    while ((ch = getchar()) != '\n')
    {
        totalLengthWithSpaces++;

        if (ch == ' ')
            spaceCount++;
    }
 
    wordCount = totalLengthWithSpaces - spaceCount;

    averageWordLength = (float) wordCount / spaceCount;

    printf("Space count: %d\n", spaceCount);
    printf("Total length with spaces: %d\n", totalLengthWithSpaces);
    printf("Letter count: %d\n", wordCount);

    printf("Average word length: %.1f\n", averageWordLength);
    
}