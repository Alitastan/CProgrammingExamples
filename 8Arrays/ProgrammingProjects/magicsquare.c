/*  Write a program that prints n x n magic square  (a square arrangement
*   of the numbers 1, 2, 3, ...., n * n in which the sums of the rows,
*   columns, and diagonals are all the same). The user will specify the value n:
*/


#include <stdio.h>
#include <stdbool.h>


int main (void)
{   
    int magicSize;
    int initialValue = 1;
    printf ("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &magicSize);



    if (magicSize % 2 != 0 && 1 <= magicSize && magicSize <= 100 )
    {


        // Store the magic square in a two dimensional array
        int magicSquare[magicSize][magicSize] = {0};

        // Track if a particular array element is already occupied
        bool arrayOccupied[magicSize][magicSize] = {false};

        // Start by placing the number 1 in the middle of row 0
        int middle = (magicSize + 1) / 2;
        magicSquare[0][middle - 1] = initialValue;
        arrayOccupied[0][middle - 1] = true;

        /*  Place each of the remaining numbers 2, 3, ...., n * n by
        *   moving up one row and over one column. Any attempt to go
        *   outside the bounds of the array should "wrap around" to 
        *   the opposite side of the array. For example, instead of
        *   storing the next number in row - 1, we would store it in now
        *   n - 1 (the last row). Instead of storing the next number in
        *   column n, we would store it in column 0. If a particular
        *   array element is already occupied, put the number directly
        *   below the previously stored number.*/



       int row, column;

       for (row = 0; row < magicSize;  )
       {
            for (column = middle - 1; column < magicSize;  )
            {
                if (!arrayOccupied[row][column])
                {
                    arrayOccupied[row][column] = true;
                }


            }
       }





    }

    else
        return -1;



    return 0;
}