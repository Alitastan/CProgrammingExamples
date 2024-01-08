#include <stdio.h>

int main (void)
{
    char firstName, lastName;
    printf("Enter a first and last name: ");

    
    // Skip blanks before the first name
    // This now holds the first letter of the first name
    // after skipping white spaces.
    while ((firstName = getchar()) == ' ');
 
    // Skip the rest of the first name
    while (getchar() != ' ');
 
    // Skip blanks between the first and last name and
    while ((lastName = getchar()) == ' ');

    // Output the first letter of the last name
    putchar(lastName);

    // Get the rest of the last name
    while ((lastName = getchar()) != '\n')
        putchar(lastName);


    printf(", ");

    // Output the first letter of the first name
    putchar(firstName);

    printf(".");


    
        
    return 0;


}