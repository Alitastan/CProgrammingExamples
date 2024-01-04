
#include <string.h>
#include <stdio.h>

#define ARRAY_LEN   4

int main (void)
{
    char str[ARRAY_LEN + 1] = "abcd";

    //*str = 0; // null terminate the string from the beginning

    //str[0] = '\0'; // null terminate the string from the beginning

    //strcpy (str, ""); // str now contains null character

    strcat (str, ""); // appends null character to the end of the string

    puts (str); 

    return 0;
    
}