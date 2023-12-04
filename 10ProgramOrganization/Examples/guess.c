/*  Asks user to guess a hidden number  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER  100

/*  External variable   */
int secretNumber;

/*  Prototypes  */
void initializeNumberGenerator (void);
void chooseNewSecretNumber (void);
void readGuess (void);

int main (void)
{
    char command;
    
    printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);
    initializeNumberGenerator();

    do
    {
        chooseNewSecretNumber();

        printf("A new number has been chosen.\n");

        readGuess();

        printf("Want to play again? (Y/N)");
        scanf(" %c", &command);
        printf("\n");
        
    } while (command == 'y' || command == 'Y');


    return 0;
    
}

/*  
*   Initializes the random nuber generator
*   using the time of day.
*/

void initializeNumberGenerator (void)
{
    srand ((unsigned) time (NULL));
}

/*
*   Randomly selects a number between 1 and MAX_NUMBER
*   and stores it in secretNumber
*/
void chooseNewSecretNumber (void)
{
    secretNumber = rand() % MAX_NUMBER + 1;
}

/*
*   Repeatedly reads user guesses and tells the user whether each
*   each guess is too low, too high, or correct. When the guess is
*   correct, prints the total number of guesses and returns.
*/
void readGuess (void)
{
    int guess, numOfGuesses = 0;

    for(;;)
    {
        numOfGuesses++;

        printf ("Enter guess: ");
        scanf ("%d", &guess);

        if (guess == secretNumber)
        {
            printf ("You won in %d guesses!\n\n", numOfGuesses);
            return;
        }
        else if (guess < secretNumber)
            printf("Your guess is too low! Try again.\n\n");
        
        else
            printf("Your guess is too high! Try again.\n\n");


    }
}