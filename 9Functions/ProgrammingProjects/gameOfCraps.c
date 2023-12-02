/* 
*   Write a program that simulates the game of craps, which is played
*   with two dice. On the first roll, the player wins if the sum of
*   the dice is 7 or 11. The player loses if the sum is 2, 3, or 12
*   Any other roll is called "the point" and the game continues.
*   On each subsequent roll, the player wins if he or she rolls the
*   point again. The player loses by rolling 7. Any other roll is
*   ignored and the game continues. At the end of the game, the program
*   will ask the user whether or not to play again. When the user enters
*   a response other than y or Y, the program will display the number of
*   wins and losses and then terminate.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int rollDice (void);
bool playGame (void);

int lastPoint = 0;
int point = 0;

int main (void)
{
    // Passing the return value of time to srand prevents
    // the program from dealing the same cards every time
    // we run it. Srand initializes C's random number generator.
    srand((unsigned) time(NULL));


    bool play = playGame();
    lastPoint = point;

    printf("Your point %d\n", lastPoint);

    for(;;)
    {

        if (play)
        {
            printf("You won!\n");
            break;
        }
        else
        {
            while(1)
            {
                playGame();
                if (point == 7)
                {
                    printf("You lost!\n");
                    break;
                }
                if (lastPoint == point)
                {
                    printf("You won!\n");
                    break;
                }
                
            }

            break;

        }

    }

    return 0;

}


int rollDice (void)
{
    int sum = 0;
    int firstNum, secondNum;

    firstNum = rand() % 6 + 1;
    secondNum = rand() % 6 + 1;

    sum = firstNum + secondNum;

    return sum;
}

bool playGame (void)
{
    point = rollDice();

    printf ("You rolled: %d\n", point);


    if (point == 7 || point == 11)
        return true;
    else if (point == 2 || point == 3 || point == 12)
        return false;
    else
        return false;

}