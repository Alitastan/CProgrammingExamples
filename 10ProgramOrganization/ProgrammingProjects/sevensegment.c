/**
 * Write a program that prompts the user for a number and then displays
 * the number, using characters to simulate the effect of a seven-segment
 * display. Characters other than digits should be ignored. Write a program
 * so that the maximum number of digits is controlled by a macro named MAX_DIGITS
 * which has the value 10. If the number contains more than this number of digits,
 * the extra digits are ignored. 
*/

#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS  10
#define ROW_LENGTH  4
#define COLUMN_LENGTH   (MAX_DIGITS * ROW_LENGTH)
#define SEGMENT_LENGTH  7

// External variables

/**
 *  Suppose that we want to set up an array that remembers which 
 *  segments should be "on" for each digit. Represents numbers from
 *  0 to 9.
*/
const int segments[MAX_DIGITS][SEGMENT_LENGTH] = {   {1, 1, 1, 1, 1, 1, 0}, 
                                                    {0, 1, 1, 0, 0, 0, 0},
                                                    {1, 1, 0, 1, 1, 0, 1},
                                                    {1, 1, 1, 1, 0, 0, 1},
                                                    {0, 1, 1, 0, 0, 1, 1},
                                                    {1, 0, 1, 1, 0, 1, 1},
                                                    {1, 0, 1, 1, 1, 1, 1},
                                                    {1, 1, 1, 0, 0, 0, 0},
                                                    {1, 1, 1, 1, 1, 1, 1},
                                                    {1, 1, 1, 1, 0, 1, 1}   }; 


/**
 * This array with 4 rows (since each segmented digit is four characters
 * high) and MAX_DIGITS * 4 columns (digits are three characters wide,
 * but a space is needed between digits for readability.)
*/
char digits[ROW_LENGTH][COLUMN_LENGTH];

// Prototypes

void clearDigitsArray (void);
void processDigit (int digit, int position);
void printDigitsArray (void);

int main (void)
{
    char userInput;
    int number, position = 0;

    clearDigitsArray();

    printf("Enter a number: ");

    while ((userInput = getchar()) != '\n')
    {
        // convert user input to integer number
        if (isdigit(userInput))
            number = userInput - '0'; 
        
        if (position < MAX_DIGITS - 1)
            processDigit(number, position);
        else break;
            
        position++;

    }
    

    printDigitsArray();

    return 0;
}


/**
 * This function will store blank characters into all elements of 
 * digits array.
*/
void clearDigitsArray (void)
{
    int i, j;
    
    for (i = 0; i < ROW_LENGTH; i++)
        for (j = 0; j < COLUMN_LENGTH; j++)
            digits[i][j] = ' ';
}

/**
 * This function will store the seven-segment representation of digit
 * into a specified position in the digits array (positions range from
 * 0 to MAX_DIGITS - 1).
*/
void processDigit (int digit, int position)
{
    int row, column;
    int sevenSegmentRepresentaton[SEGMENT_LENGTH];
    
    row = digit;


    for (column = 0; column < SEGMENT_LENGTH; column++)
    {   
        // Example output: {0, 1, 1, 0, 0, 1, 1}
        sevenSegmentRepresentaton[column] = segments[row][column];

        switch (sevenSegmentRepresentaton[column])
        {
            case 0: case 3: case 6: printf("-"); break;
            case 1: case 2: case 4: case 5: printf("|"); break;

            default: break;
        }

        
    }
    


}

/**
 * This function will display the rows of the digits array, each on a 
 * single line, producing output which is easily readable.
*/
void printDigitsArray (void)
{
    int i, j;
    
    for (i = 0; i < ROW_LENGTH; i++)
    {
        for (j = 0; j < COLUMN_LENGTH; j++)
        {
            printf(" %c", digits[i][j]);
        }
        
        printf("\n");
    }

            
}