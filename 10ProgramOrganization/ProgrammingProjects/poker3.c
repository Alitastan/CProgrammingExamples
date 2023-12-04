

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS   5
#define RANK    0
#define SUIT    1


/*  External variables  */
int hand[NUM_CARDS][2];

bool straight, flush, four, three;
int pairs;  /* Can be 0, 1 or 2 */

/*  Prototypes  */
void readCards (void);
void analyzeHand (void);
void printResult (void);


/*
*   Calls readCards, analyzeHand and printResult
*   repeatedely.
*/
int main (void)
{
    for (;;) 
    {
        readCards();
        analyzeHand();
        printResult();
    }
}


/*
*   Reads the cards into external variables and
*   checks for bad cards and duplicate cards.
*/
void readCards (void)
{

    char ch, rankCh, suitCh;
    int i, rank, suit;
    bool badCard, duplicateCard;
    int cardsRead = 0;


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
        {
            printf("Bad card; ignored.\n");
            continue;
        }

        duplicateCard = false;
        for (i = 0; i < cardsRead; i++)
        {
            if (hand[i][RANK] == rank && hand[i][SUIT] == suit)
            {
                printf("Duplicate card; ignored.\n");
                duplicateCard = true;
                break;
            }
        }

        if (!duplicateCard)
        {
            hand[cardsRead][RANK] = rank;
            hand[cardsRead][SUIT] = suit;
            cardsRead++;
        }
    }
}

/*
*   Determines whether the hand contains a straight, a flush,
*   and/or three-of-a-kind; determines the number of pairs;
*   stores the results into external variables.
*/
void analyzeHand (void)
{

    int rank, suit, card, pass, run;
    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;

    /*  sort cards by rank  */
    for (pass = 1; pass < NUM_CARDS; pass++)
        for (card = 0; card < NUM_CARDS - pass; card++)
        {
            rank = hand[card][RANK];
            suit = hand[card][SUIT];

            if (hand[card + 1][RANK] < rank)
            {
                hand[card][RANK] = hand[card + 1][RANK];
                hand[card][SUIT] = hand[card + 1][SUIT];
                hand[card + 1][RANK] = rank;
                hand[card + 1][SUIT] = suit;
            }
        }

    /*  Check for flush */
    suit = hand[0][SUIT];
    for (card = 1; card < NUM_CARDS; card++)
        if (hand[card][SUIT] != suit)
            flush = false;

    /*  Check for straight  */
    for (card = 0; card < NUM_CARDS - 1; card++)
        if (hand[card][RANK] + 1 != hand[card + 1][RANK])
            straight = false;
    
    /* 
    *   Check for 4-of-a-kind, 3-of-a-kind, and pairs by looking
    *   for "runs" of cards with identical ranks.
    */
    card = 0;
    while (card < NUM_CARDS)
    {
        rank = hand[card][RANK];
        run = 0;
        do
        {
            run++;
            card++;
        } while (card < NUM_CARDS && hand[card][RANK] == rank);
        
        switch (run)
        {
            case 2: pairs++;        break;
            case 3: three = true;   break;
            case 4: four = true;    break;
        }   
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

    printf("\n\n");
}
