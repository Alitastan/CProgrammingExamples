#include <stdio.h>
#include <ctype.h>

//  Program will need to store the phone number (either in its
//  original form or in its numeric form) in an array of characters until
//  it can be printed. You may assume that the phone number is no more than
//  15 characters long.

int main (void)
{
    int i = 0;
    char ch;
    char phoneNumber[15] = {'.'};

    //  Initialize the array 
    for (i = 0; i < 15; i++)
    {
        phoneNumber[i] = '.';
    }

    printf("Enter phone number: ");

    i = 0;

    while ( (ch = getchar()) != '\n' && i < 15 )
    {

        phoneNumber[i] = ch;

        switch ( toupper(ch) )
        {
            case 'A': case 'B': case 'C':
                printf("2"); break;
            case 'D': case 'E': case 'F':
                printf("3"); break;
            case 'G': case 'H': case 'I':
                printf("4"); break;
            case 'J': case 'K': case 'L':
                printf("5"); break;
            case 'M': case 'N': case 'O':
                printf("6"); break;
            case 'P': case 'R': case 'S':
                printf("7"); break;
            case 'T': case 'U': case 'V':
                printf("8"); break;
            case 'W': case 'X': case 'Y':
                printf("9"); break;
            default:
                printf("%c", ch); break;
        }

        i++;



    }
    
    printf("\n");

    for(int j = 0; j < 15; j++)
    {
        printf("%c", phoneNumber[j]);
    }



    return 0;
}

