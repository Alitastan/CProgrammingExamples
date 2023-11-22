#include <stdio.h>

int main(void)
{
    char firstName, lastName;

    printf("Enter a first and last name: ");

    // Skip white spaces before the name
    while ((firstName = getchar()) == ' ');

    // Print the first name
    putchar(firstName);

    // Skip the rest of the first name
    while ((firstName = getchar()) != ' ' && firstName != '\n');

    // Skip white spaces between first and last name
    while ((lastName = getchar()) == ' ');

    // Print the last name
    putchar(lastName);

    // Read and skip the rest of the last name
    while ((lastName = getchar()) != ' ' && lastName != '\n');

    // If there is a first name, print a comma and the first letter of the first name
    if (firstName != '\n') {
        printf(", %c.", firstName);
    }

    return 0;
}
