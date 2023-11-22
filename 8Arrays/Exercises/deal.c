/* Deals a random hand of cards */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS   4
#define NUM_RANKS   13

int main (void)
{
    bool inHand[NUM_SUITS][NUM_RANKS] = {false};
    int numCards, rank, suit;
    const char rankCode[] = {'2', '3', '4', '5', '6', '7', '8',
                            '9', 't', 'j', 'q', 'k', 'a'};
    const char suitCode[] = {'c', 'd', 'h', 's'};

    // Passing the return value of time to srand prevents
    // the program from dealing the same cards every time
    // we run it. Srand initializes C's random number generator.
    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand: ");
    scanf("%d", &numCards);

    printf("Your hand:");
    
    while (numCards > 0)
    {
        suit = rand() % NUM_SUITS; // Picks a random suit
        rank = rand() % NUM_RANKS; // Picks a random rank

        if (!inHand[suit][rank])
        {
            inHand[suit][rank] = true;
            numCards--;
            printf(" %c%c", rankCode[rank], suitCode[suit]);
        }
    }

}
