/**
 * Suppose we need a function that doesn't skip white-space characters,
 * stops reading at the first new-line character (which isn't stored in
 * the string), and discards extra chatacters. The function might have the
 * following prototype
*/

int read_line (char str[], int n);


int main (void)
{

    return 0;
}

/**
 * str represents the array into which we'll store the input,
 * and n is the maximum number of characters to be read.
 * If the input line contains more than n characters, read_line
 * will return the number of characters it actually stored in str
 * (a number anywhere from 0 to n). We may not always need read_line's
 * return value, but it doesn't hurt to have it available.
*/
int read_line (char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0'; /* Terminates string */
    return i; /* Number of characters stored */
}