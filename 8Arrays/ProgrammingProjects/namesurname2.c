/*  
*   The program will need to store the last name
*   (but not the first name) in an array of characters
*   until it can be printed. Assume that the last name
*   is no more than 20 characters long.
*/

#include <stdio.h>

#define LASTNAME_LENGTH 20

int main (void)
{
    char lastName[LASTNAME_LENGTH];
    char firstName, firstNameLetter;


    printf("Enter a first name and a last name: ");

    // Skip blanks before the first name and store the first letter
    // of the first name in firstNameLetter
    while ((firstNameLetter = getchar()) == ' ');

    // Pass the first name
    while (getchar() != ' ');


    // Skip any blanks between the first name and the last name
    // store the first letter of the last name in lastName[0]
    while ((lastName[0] = getchar()) == ' ');
    putchar(lastName[0]);

    for (int i = 1; i < LASTNAME_LENGTH, (((lastName[i] = getchar()) != ' ') && (lastName[i] != '\n')); i++)
        putchar(lastName[i]);


    printf(", ");
    putchar(firstNameLetter);
    printf(".");

    return 0;
}