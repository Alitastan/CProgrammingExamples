/*  Write a program that reads a 5 x 5 array of integers and then
*   prints the row sums and column sums.    
*/

#include <stdio.h>

#define ROW_LEN   5
#define COLUMN_LEN  5
int main (void)
{
    // Declare 5 x 5 array of integers
    int userArray[ROW_LEN][COLUMN_LEN], rowSum[ROW_LEN] = {0}, columnSum[COLUMN_LEN] = {0};
    int row, column;


    // Get each row
    for (row = 0; row < ROW_LEN; row++)
    {    
        printf("Enter row %d: ", row + 1);

        for (column = 0; column < COLUMN_LEN; column++)
        {

            scanf("%d", &userArray[row][column]);

        }
    }

    printf("\n");

    // Sum rows and columns

    printf("Row totals: ");

    for (row = 0; row < ROW_LEN; row++)
    {
        for (column = 0; column < COLUMN_LEN; column++)
        {
            rowSum[row] += userArray[row][column];

        }

        printf("%d ", rowSum[row]);
    }

    printf("\n");
    printf("Column totals: ");

    for (column = 0; column < COLUMN_LEN; column++)
    {
        for (row = 0; row < ROW_LEN; row++)
        {
            columnSum[column] += userArray[row][column];
        }
        
        printf("%d ", columnSum[column]);
    }



  

    
}