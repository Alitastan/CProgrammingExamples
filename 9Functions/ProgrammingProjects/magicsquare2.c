/*  
*	Write a program that prints n x n magic square  (a square arrangement
*   of the numbers 1, 2, 3, ...., n * n in which the sums of the rows,
*   columns, and diagonals are all the same). The user will specify the value n:
*
		This program creates a magic square of a specified size.
		The size must be an odd number between 1 and 99.
		Enter size of magic square: 5

		17  24   1   8  15
		23   5   7  14  16
		4   6  13  20  22
		10  12  19  21   3
		11  18  25   2   9
*/


#include <stdio.h>
#include <stdbool.h>

void createMagicSquare (int magicSize, int magicSquare[magicSize][magicSize]);
void printMagicSquare (int magicSize, int magicSquare[magicSize][magicSize]);


int main (void)
{   
    int len;

    printf ("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &len);



    if (len % 2 != 0 && 1 <= len && len <= 100 )
    {
        // Store the magic square in a two dimensional array
        int userArray[len][len];

        createMagicSquare(len, userArray);

        printMagicSquare(len, userArray);

    }

    else
	{
		printf("Entered wrong value, terminating the program.\n");
		return -1;

	}


    return 0;
}


void createMagicSquare (int magicSize, int magicSquare[magicSize][magicSize])
{
    // Value to be replaced on array
    int initialValue = 1;

    // Track if a particular array element is already occupied
    bool arrayOccupied[magicSize][magicSize];

    for (int i = 0; i < magicSize; i++)
        for (int j = 0; j < magicSize; j++)
        {
            magicSquare[i][j] = 0;
            arrayOccupied[i][j] = false;
        }


    // Start by placing the number 1 in the middle of row 0
    int middle = (magicSize + 1) / 2;
    magicSquare[0][middle - 1] = initialValue;

    // Track indexes
    int rowIndex = 0, columnIndex = middle - 1;
    arrayOccupied[0][columnIndex] = true;

    /* 
    *	Place each of the remaining numbers 2, 3, ...., n * n by
    *   moving up one row and over one column. Any attempt to go
    *   outside the bounds of the array should "wrap around" to 
    *   the opposite side of the array. For example, instead of
    *   storing the next number in row - 1, we would store it in now
    *   n - 1 (the last row). Instead of storing the next number in
    *   column n, we would store it in column 0. If a particular
    *   array element is already occupied, put the number directly
    *   below the previously stored number.
    */

    int elementCount = magicSize * magicSize;

    
    while (initialValue < elementCount)
    {
        int nextRow = (rowIndex - 1 + magicSize) % magicSize;
        int nextColumn = (columnIndex + 1) % magicSize;

        if (!arrayOccupied[nextRow][nextColumn])
        {
            rowIndex = nextRow;
            columnIndex = nextColumn;
                
        }
        else
        {
            rowIndex = (rowIndex + 1) % magicSize;
        }

        initialValue++;
        magicSquare[rowIndex][columnIndex] = initialValue;
        arrayOccupied[rowIndex][columnIndex] = true;

    }
}

void printMagicSquare (int magicSize, int magicSquare[magicSize][magicSize])
{
    printf("\n");

    for (int i = 0; i < magicSize; i++)
    {
        for (int j = 0; j < magicSize; j++)
        {
            printf(" %3d", magicSquare[i][j]);
        }
        printf("\n");
    }


    printf("\nDiagonal sums: ");
    int diagonalSum = 0;
    for (int i = 0; i < magicSize; i++)
        for(int j = 0; j < magicSize; j++)
            if (i == j)
                diagonalSum += magicSquare[i][j];

    printf("%d\n", diagonalSum);    
}