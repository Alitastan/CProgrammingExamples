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

    const char *rank_code[] = {"Two", "Three", "Four", "Five", "Six",
                                "Seven", "Eight", "Nine", "Ten", "Jack",
                                "Queen", "King", "Ace"};
    
    const char *suit_code[] = {"Clubs", "Diamonds", "Hearts", "Spades"};


    // Passing the return value of time to srand prevents
    // the program from dealing the same cards every time
    // we run it. Srand initializes C's random number generator.
    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand: ");
    scanf("%d", &numCards);

    printf("Your hand:\n");
    
    while (numCards > 0)
    {
        suit = rand() % NUM_SUITS; // Picks a random suit
        rank = rand() % NUM_RANKS; // Picks a random rank

        if (!inHand[suit][rank])
        {
            inHand[suit][rank] = true;
            numCards--;
            printf("%s of %s\n", rank_code[rank], suit_code[suit]);
        }
    }

}
