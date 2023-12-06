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
#include <stdbool.h>

#define MAX_DIGITS          10
#define ROW_LENGTH          4
#define COLUMN_LENGTH   (MAX_DIGITS * ROW_LENGTH)
#define SEGMENT_LENGTH      7
#define DIGIT_WIDTH         3
#define DIGIT_HEIGHT        4
#define POS1    0
#define POS2    1
#define POS3    2
#define POS4    3
#define POS5    4
#define POS6    5
#define POS7    6

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
 
        // Convert user input to integer number
        if (isdigit(userInput))
        {
            number = userInput - '0';

            if (position < MAX_DIGITS)
            {   
                processDigit(number, position);
            }
            else
            {
                printf("Out of boundry!\n");
                break;
            }

        }

        // Characters other than digits should be ignored.
        else
        {
            continue;
        } 
        
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
    bool digitHighOrLow[SEGMENT_LENGTH];

    int row, column, segmentColumn;

    // For digit 4:     0, 1, 1, 0, 0, 1, 1

    for (segmentColumn = 0; segmentColumn < SEGMENT_LENGTH; segmentColumn++)
    {
        digitHighOrLow[segmentColumn] = (segments[digit][segmentColumn] == true) ? true: false;

        switch (segmentColumn)
        {
            case POS1:
                // row = 0, column = 0, 1, 2,  next column will be 4, 5, 6,  next column will be 8, 9, 10  etc..
                row = 0;
                column = (position * DIGIT_WIDTH) + DIGIT_WIDTH + position;
                
                if (digitHighOrLow[POS1])
                {
                    for (int newColumn = column - DIGIT_WIDTH + 1; newColumn < column - 1; newColumn++)
                            digits[row][newColumn] = '_';   
                }               
                break;
            
            case POS2:
                // column = 2, row = 0, 1.  next column will be 6 then 10, 14 etc..
                column = (DIGIT_WIDTH - 1) + (DIGIT_HEIGHT * position);

                if (digitHighOrLow[POS2])
                {
                    for (int newRow = 1; newRow < DIGIT_HEIGHT / 2; newRow++)
                            digits[newRow][column] = '|';
                }
                break;
 
            
            case POS3:
                // column = 2, row = 2, 3.  next column will be 6 then 10, 14 etc..
                column = (DIGIT_WIDTH - 1) + (DIGIT_HEIGHT * position);

                if (digitHighOrLow[POS3])
                {
                    for (int newRow = 2; newRow < DIGIT_HEIGHT; newRow++)
                            digits[newRow][column] = '|';
                }
                break;

            case POS4:
                // row = 3, column = 0, 1, 2,  next column will be 4, 5, 6,  next column will be 8, 9, 10  etc..
                row = DIGIT_WIDTH;
                column = (position * DIGIT_WIDTH) + DIGIT_WIDTH + position;
                
                if (digitHighOrLow[POS4])
                {
                    for (int newColumn = column - DIGIT_WIDTH; newColumn < column - 1; newColumn++)
                            digits[row][newColumn] = '_';
                }               
                break;
                
            case POS5:
                // column = 0, row = 2, 3.  next column will be 4 then 8, 12 etc..
                column = (DIGIT_HEIGHT * position);

                if (digitHighOrLow[POS5])
                {
                    for (int newRow = 2; newRow < DIGIT_HEIGHT; newRow++)
                            digits[newRow][column] = '|';
                }
                break;
                
            case POS6:
                // column = 0, row = 0, 1.  next column will be 4 then 8, 12 etc..
                column = (DIGIT_HEIGHT * position);

                if (digitHighOrLow[POS6])
                {
                    for (int newRow = 1; newRow < DIGIT_HEIGHT / 2; newRow++)
                            digits[newRow][column] = '|';
                }
                break;

            case POS7:
                // row = 1
                row = DIGIT_HEIGHT / 2;
                column = (position * DIGIT_WIDTH) + DIGIT_WIDTH + position;
                
                if (digitHighOrLow[POS7])
                {
                    for (int newColumn = column - DIGIT_WIDTH + 1; newColumn < column - 1; newColumn++)
                            digits[row][newColumn] = '-';
                }               
                break;
  
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