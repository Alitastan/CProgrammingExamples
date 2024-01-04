

#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE  30

int main (void)
{
    char array[ARRAY_SIZE] = "Some text dude";

    // Rewrite the string
    strcpy (array, "tire-bouchon");

    // Rewrite the string from the 4th element of the array
    strcpy(&array[4], "d-or-wi");

    // Appends "red" to the end of the string array.
    strcat (array, "red?");

    // Final string is tired-or-wired?
    puts (array);



    return 0;
}