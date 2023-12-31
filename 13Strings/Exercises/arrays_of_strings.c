

#include <stdio.h>

int main (void)
{
    // This wastes lots of space in the array
    char planets2[][8] = {"Mercury", "Venus", "Earth",
                        "Mars", "Jupiter", "Saturn",
                        "Uranus", "Neptune", "Pluto"};

    // planets array as an array of pointers to strings.
    // with this way we don't waste space in the array
    char *planets[] = {"Mercury", "Venus", "Earth",
                        "Mars", "Jupiter", "Saturn",
                        "Uranus", "Neptune", "Pluto"};

    for (int i = 0; i < 9; i++)
        if (planets[i][0] == 'M')
            printf("%s begins with M\n", planets[i]);

    return 0;
}