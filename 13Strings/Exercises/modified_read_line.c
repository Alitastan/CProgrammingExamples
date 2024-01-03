#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MESSAGE_LEN 15


int my_read_line_1 (char str[], int n);
int my_read_line_2 (char str[], int n);
int my_read_line_3 (char str[], int n);
int my_read_line_4 (char str[], int n);


int main (void)
{
    char message_buffer[MESSAGE_LEN + 1];
    //my_read_line_1 (message_buffer, MESSAGE_LEN);
    //my_read_line_2 (message_buffer, MESSAGE_LEN);
    //my_read_line_3 (message_buffer, MESSAGE_LEN);
    my_read_line_4 (message_buffer, MESSAGE_LEN);
    puts(message_buffer);

    //printf("Message length: %d\n", strlen(message_buffer));

}




/**
 * Have it skip white space before beginning to store input
 * characters.
*/
int my_read_line_1 (char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i == 0 && isspace(ch))
        ; /* ignore */
        else if (i < n)
            str[i++] = ch;
    
    str[i] = '\0';
    return i;

}


/**
 * Have it stop reading at the first white-space character.
 * Hint: To determine whether or not a character is white space,
 * call the isspace function.
 * 
 */  

int my_read_line_2 (char str[], int n)
{
    int ch, i = 0;

    while (!isspace(ch = getchar()))
        if (i < n)
            str[i++] = ch;
    
    str[i] = '\0';
    return i;

}

/**
 * Have it stop reading at the first new-line character, then store
 * the new-line character in the string.
*/
int my_read_line_3 (char str[], int n)
{
    int ch, i = 0;

    do
    {
        ch = getchar();
        if (i < n)
            str[i++] = ch;

    } while (ch != '\n');

    str[i] = '\0';
    return i;
    

}


/**
* Have it leave behind characters that it doesn't have room 
* to store.
*/
int my_read_line_4 (char str[], int n)
{
    int ch, i;

    for (i = 0; i < n; i++)
    {
        ch = getchar();
        if (ch == '\n')
            break;
        str[i] = ch;
    }
    str[i] = '\0';
    return i;

}
