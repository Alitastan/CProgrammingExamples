/**
 * Copying a string is another common operation. To introduce C's
 * "string copy" idiom, we'll develop two versions of the strcat
 * function.
 * 
*/

char *my_strcat (char *s1, const char *s2)
{
    char *p = s1;

    while (*p != '\0')
        p++;
    
    while (*s2 != '\0')
    {
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';
    return s1;
}

char *my_strcat_condensed (char *s1, const char *s2)
{
    char *p = s1;

    while (*p)
        p++;
    
     /**
     *  All characters except null character test true, so the loop won't
     *  terminate until the null character has been copied. And since the
     *  loop terminates after the assignment, we don't need a separate 
     *  statement to put a null character at the end of the new string.
     */
    while (*p++ = *s2++)
    ;
    return s1;

}