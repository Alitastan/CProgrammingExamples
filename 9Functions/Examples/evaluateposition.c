

#include <stdio.h>

#define ROW 8
#define COLUMN  8


int evaluatePosition (char board [][COLUMN]);

int main (void)
{

    char chessBoard[ROW][COLUMN] = {    {'r', 'n', ' ', 'q', 'k', 'b', 'n', 'r'},
                                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                                        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                                        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                                        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                                        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                                        {'P', ' ', 'P', 'P', 'P', 'P', 'P', 'P'},
                                        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                    };


    // Positive if white has advantage in material
    // Negative if black has advantage in material
    printf ("Check advantage: %d\n", evaluatePosition(chessBoard));

    return 0;

}

int evaluatePosition (char board [][COLUMN])
{
    int row, column;
    int sumWhite = 0, sumBlack = 0;
    char ch;

    for (row = 0; row < ROW; row++)
    {
        for (column = 0; column < COLUMN; column++)
        {
            ch = board[row][column];

            // For white pieces
            if ('a' <= ch && ch <= 'z')
            {
                switch (ch)
                {
                    case 'p': sumWhite += 1; break;
                    case 'n': case'b': sumWhite += 3; break;
                    case 'r': sumWhite += 5; break;
                    case 'q': sumWhite += 9; break;
                    default: break;       
                }
            }
            // For black pieces
            if ('A' <= ch && ch <= 'Z')
            {
                switch (ch)
                {
                    case 'P': sumBlack += 1; break;
                    case 'N': case'B': sumBlack += 3; break;
                    case 'R': sumBlack += 5; break;
                    case 'Q': sumBlack += 9; break;
                    default: break;       
                }
            }
        }
    }

    // positive if white has an advantage in material
    // negative if black has an advantage in material
    return sumWhite - sumBlack;
}