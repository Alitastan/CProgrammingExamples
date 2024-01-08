/**
 * This program illustrates how to access command-line arguments.
 * The program is designed to check a series of strings to see which
 * ones are names of planets. When the program is run, the user will
 * put the strings to be tested on the command line:
 * 
 * example: planet Jupiter venus Earth fred
 * 
 * Then the program will indicate whether or not each string is a planet
 * name; if it is, the program will also display the planet's number (with
 * planet 1 being the one closest to the Sun):
 * 
 * Jupiter is planet 5
 * venus is not a planet
 * Earth is planet 3
 * fred is not a planet
 * 
 * The program doesn't recognize a string as a planet name unless its first
 * letter is upper-case and its remaining letters are lower-case.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_PLANETS 9

bool equal_strings (const char *s, const char *t);
bool equal_strings_v1 (const char *s, const char *t);

int main (int argc, char *argv[])
{
    char *planets[] = {"Mercury", "Venus", "Earth",
                        "Mars", "Jupiter", "Saturn",
                        "Uranus", "Neptune", "Pluto"};
    int i, j;

    for (i = 1; i < argc; i++)
    {
        for (j = 0; j < NUM_PLANETS; j++)
        {
            if (equal_strings(argv[i], planets[j]))
            {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        }
        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }

    return 0;
}

bool equal_strings (const char *s, const char *t)
{
    
    for (; toupper(*s++) == toupper(*t++);)
        if (*s == '\0')
            return true;
    return false;

}

bool equal_strings_v1 (const char *s, const char *t)
{
    int i;

    for (i = 0; toupper(s[i]) == toupper(t[i]); i++)
        if (s[i] == '\0')
            return true;
    return false;
}