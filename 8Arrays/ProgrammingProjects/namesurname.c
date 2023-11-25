

/*  The program will need to store the last name
*   (but not the first name) in an array of characters
*   until it can be printed. Assume that the last name
*   is no more than 20 characters long.*/

#include <stdio.h>

int main(void)
{
    char ch;
    char firstLetterOfName, firstLetterOfSurname;
    char firstName, lastName;
    int readingFirstName = 0;

    printf("Enter a first and last name: ");

    // Skip leading spaces
    while ((firstLetterOfName = getchar()) == ' ');

    // Process the first name
    while (getchar() != ' ');


    // Skip spaces between first and last name
    while ((firstLetterOfSurname = getchar()) == ' ');

    // Process the last name
    putchar(firstLetterOfSurname);

    while ((lastName = getchar()) != ' ' && lastName != '\n')
    {
        putchar(lastName);
    }

    // Output the result
    printf(", ");
    putchar(firstLetterOfName);
    printf(".");

    return 0;
}
