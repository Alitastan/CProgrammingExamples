

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS   13
#define NUM_SUITS   4
#define NUM_CARDS   5

/*  External variables  */

bool straight, flush, four, three;
int pairs;  /* Can be 0, 1 or 2 */

/*  Prototypes  */
void readCards (int numInRank[], int numInSuit[]);
void analyzeHand (int numInRank[], int numInSuit[]);
void printResult (void);


/*
*   Calls readCards, analyzeHand and printResult
*   repeatedely.
*/
int main (void)
{
    int numInRank[NUM_RANKS];
    int numInSuit[NUM_SUITS];

    for (;;) 
    {
        readCards(numInRank, numInSuit);
        analyzeHand(numInRank, numInSuit);
        printResult();
    }
}


/*
*   Reads the cards into external variables and
*   checks for bad cards and duplicate cards.
*/
void readCards (int numInRank[], int numInSuit[])
{
    bool cardExists[NUM_RANKS][NUM_SUITS];
    char ch, rankCh, suitCh;
    int rank, suit;
    bool badCard;
    int cardsRead = 0;

    for (rank = 0; rank < NUM_RANKS; rank++)
    {
        numInRank[rank] = 0;
        for (suit = 0; suit < NUM_SUITS; suit++)
            cardExists[rank][suit] = false;
    }

    for (suit = 0; suit < NUM_SUITS; suit++)
        numInSuit[suit] = 0;

    while (cardsRead < NUM_CARDS)
    {
        badCard = false;

        printf("Enter a card: ");

        rankCh = getchar();
        switch (rankCh)
        {
            case '0':               exit(EXIT_SUCCESS);
            case '2':               rank = 0; break;
            case '3':               rank = 1; break;
            case '4':               rank = 2; break;
            case '5':               rank = 3; break;
            case '6':               rank = 4; break;
            case '7':               rank = 5; break;
            case '8':               rank = 6; break;
            case '9':               rank = 7; break;
            case 't': case 'T':     rank = 8; break;
            case 'j': case 'J':     rank = 9; break;
            case 'q': case 'Q':     rank = 10; break;
            case 'k': case 'K':     rank = 11; break;
            case 'a': case 'A':     rank = 12; break;
            default:                badCard = true;

        }

        suitCh = getchar();
        switch (suitCh)
        {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            badCard = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ') badCard = true;


        if (badCard)
            printf("Bad card; ignored.\n");
        else if (cardExists[rank][suit])
            printf("Duplicate card; ignored.\n");
        else
        {
            numInRank[rank]++;
            numInSuit[suit]++;
            cardExists[rank][suit] = true;
            cardsRead++;
        }
    }
}

/*
*   Determines whether the hand contains a straight, a flush,
*   and/or three-of-a-kind; determines the number of pairs;
*   stores the results into external variables.
*/
void analyzeHand (int numInRank[], int numInSuit[])
{
    int numConsec = 0;
    int rank, suit;
    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;

    /*  Check for flush */
    for (suit = 0; suit < NUM_SUITS; suit++)
        if (numInSuit[suit] == NUM_CARDS)
            flush = true;

    /*  Check for straight  */
    rank = 0;
    while (numInRank[rank] == 0) rank++;
    for (; rank < NUM_RANKS && numInRank[rank] > 0; rank++)
        numConsec++;
    if (numConsec == NUM_CARDS)
    {
        straight = true;
        return;
    }

    /*  Check for 4-of-a-kind, 3-of-a-kind, and pairs   */
    for (rank = 0; rank < NUM_RANKS; rank++)
    {
        if (numInRank[rank] == 4) four = true;
        if (numInRank[rank] == 3) three = true;
        if (numInRank[rank] == 2) pairs++;
    }
}

/*
*   Notifies the user of the result, using the external 
*   variables set by analyzeHand.  
*/
void printResult (void)
{  
    if (straight && flush)  printf("Straight flush");
    else if (four)          printf("Four of a kind");
    else if (three &&
            pairs == 1)     printf("Full house");
    else if (flush)         printf("Flush");
    else if (straight)      printf("Straight");
    else if (three)         printf("Three of a kind");
    else if (pairs == 2)    printf("Two pairs");
    else if (pairs == 1)    printf("Pair");
    else                    printf("High card");

    printf("\n");
}
