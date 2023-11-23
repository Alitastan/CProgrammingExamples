/*  Write a declaration for a 8x8 char array named chessBoard
*   Then write a program fragment that declares 8x8 char array
*   named checkerBoard and then use a loop store some data*/

#include <stdio.h>

#define ROW 8
#define COLUMN  8

int main (void)
{
    int row, column;

    char chessBoard[ROW][COLUMN] = {    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                                        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                                        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                                        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                                        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                                        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                    };

    char checkerBoard[ROW][COLUMN] = {' '};

    // Generate the checkboard pattern
    for (row = 0; row < ROW; row++)
    {
        for (column = 0; column < COLUMN; column++)
        {
            if ((row + column) % 2 == 0)
                checkerBoard[row][column] = 'B';
            else
                checkerBoard[row][column] = 'R'; 
        }
    }

    for (row = 0; row < ROW; row++)
    {
        for (column = 0; column < COLUMN; column++)
        {
            printf("%4c", checkerBoard[row][column]);
        }
        printf("\n"); // Add a new line after each row.
    }


                                    
}