/* 
*   Write a program that generates a "random walk" across 
*   a 10 x 10 array. The array will contain characters
*   (all '.' initially). The program must randomly "walk"
*   from element to element, always going up, down, left
*   or right by one element. The elements visited by the
*   program will be labeled with the letters A through Z,
*   in the order visited.

    // ASCII character set: A (65) - Z (90) consecutive numbers
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define X_LEN           10
#define Y_LEN           10
#define DIRECTION       4 // up, down, left or right
#define ASCII_A_CHAR    65
#define MAX_STEPS       25
#define BLOCK_THRESHOLD 10
   
#define UP      3
#define DOWN    0
#define LEFT    1
#define RIGHT   2   

int main (void)
{
    char randomWalk[X_LEN][Y_LEN] = {'.'};
    bool letterAssigned[X_LEN][Y_LEN] = {false};
    int x, y, direction, steps = 0, consecutiveBlockCount = 0;
    bool blocked[4] = {false};
    
    // initial coordinates of the first character 'A'
    int X, Y;

    // Initialize all elements with '.'
    for (x = 0; x < X_LEN; x++)
    {
        for(y = 0; y < Y_LEN; y++)
        {
            randomWalk[x][y] = '.';
        }
    }

    // Passing the return value of time to srand prevents
    // the program from dealing the same cards every time
    // we run it. Srand initializes C's random number generator.
    srand((unsigned) time(NULL));


    // Random initial coordinates for 'A' between (0-9)
    X = rand() % X_LEN;
    Y = rand() % Y_LEN;

    // Place the first character 'A' on inital coordinates
    randomWalk[X][Y] = ASCII_A_CHAR;
    letterAssigned[X][Y] = true;

    //  Before performing a move, check that it won't go outside the array,
    //  and it doesn't take us to an element that already has a letter assigned.
    //  if either condition is violated, try moving in another direction. if all
    //  four directions are blocked, the program must terminate.
    while (steps < MAX_STEPS)
    {
        // Check if all directions are blocked
        if (blocked[UP] && blocked[DOWN] && blocked[LEFT] && blocked[RIGHT])
        {
            printf("No way to go. Terminating.\n");
            return -1;
        }

        // First reset blocked direction flags
        for (int i = 0; i < 4; i++)
            blocked[i] = false;

        // Determine which way to go. 4 possible values UP(3), DOWN(0), LEFT(1), RIGHT(2)
        direction = rand() % DIRECTION;
  

        switch (direction)
        {
            case UP:  

                if (X > 0 && !letterAssigned[X - 1][Y])
                {
                    X--;
                    // Reset block count
                    consecutiveBlockCount = 0;
                }
                else
                {
                    blocked[UP] = true;
                    consecutiveBlockCount++;
                }       
                break;

            case DOWN:

                if (X < X_LEN - 1 && !letterAssigned[X + 1][Y])
                {
                    X++;
                    // Reset block count
                    consecutiveBlockCount = 0;
                }
                else
                {
                    blocked[DOWN] = true;
                    consecutiveBlockCount++;
                }
                break;
                
            case LEFT:

                if (Y > 0 && !letterAssigned[X][Y - 1])
                {
                    Y--;
                    consecutiveBlockCount = 0;
                }
                else
                {
                    blocked[LEFT] = true;
                    consecutiveBlockCount++;
                }
                break;

            case RIGHT:
                
                if (Y < Y_LEN - 1 && !letterAssigned[X][Y + 1])
                {
                    Y++;
                    consecutiveBlockCount = 0;
                }
                else
                {
                    blocked[RIGHT] = true;
                    consecutiveBlockCount++;
                }
                break;

            default:
                printf("Invalid direction.");
                break;

        }

        // Check if consecutive blocked count exceeds a threshold
        if (consecutiveBlockCount > BLOCK_THRESHOLD)
        {
            printf("Stuck in a loop. Terminating. \n");

            printf("Array state before termination:\n");
            for (x = 0; x < X_LEN; x++)
            {
                for (y = 0; y < Y_LEN; y++)
                {
                    printf(" %c", randomWalk[x][y]);
                }
                printf("\n");
            }          

            printf("No way to go. Terminating.\n");
            return -1;
        }

        // Mark the visited cell with the corresponding letter
        if (!letterAssigned[X][Y])
        {
            letterAssigned[X][Y] = true;
            randomWalk[X][Y] = ASCII_A_CHAR + steps + 1;
            steps++;
        }


    }


    // Print
    for (x = 0; x < X_LEN; x++)
    {
        for (y = 0; y < Y_LEN; y++)
        {
            printf(" %c", randomWalk[x][y]);
        }

        printf("\n");
    }


}