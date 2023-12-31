
#include <string.h>

size_t my_strlen (const char *s)
{
    size_t n;

    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

/* More condensed versions ahead */

size_t my_strlen_condensed_1 (const char *s)
{
    size_t n = 0;
    
    for (; *s != '\0'; s++)
        n++;
    return n;
}

/*  Notice that the condition *s != '\0' is the same as *s != 0,
*   because the integer value of the null character is 0. But testing
*   *s != 0 is the same as testing *s; both are true if *s isn't equal
*   to 0.  
*/
size_t my_strlen_condensed_2 (const char *s)
{
    size_t n = 0;

    for (; *s; s++)
        n++;
    return n;
}

/**
 * It is possible to increment s and test *s in the same expression:
*/
size_t my_strlen_condensed_3 (const char *s)
{
    size_t n = 0;

    for (; *s++; )
        n++;
    return n;
}

/**
 * Replacing the for statement with a while statament, we arrive at the
 * following version of my_strlen_condensed_3:
*/
size_t my_strlen_condensed_4 (const char *s)
{
    size_t n = 0;

    while (*s++)
        n++;
    return n;
}

/**
 * With some compilers there is a version of my_strlen_condensed_3
 * that does run faster. The improvement in speed comes from not
 * having to increment n inside the while loop. 
 * 
 * while (*s)
 *  s++;
 * 
 * and
 * 
 * while (*s++)
 * ;
 * 
 * are related idioms meaning "search for the null character at the end
 * of the string" The first version leaves s pointing to the null character.
 * The second version is more concise, but leaves s pointing just past the null
 * character.
*/
size_t my_strlen_condensed_5 (const char *s)
{
    const char *p = s;

    while (*s)
        s++;
    return s - p;

}

int main (void)
{
    return 0;
}
