
#include <stdio.h>

#define MAX_INPUT_LEN   100
#define MAX_NAME_LEN    50
#define MAX_SURNAME_LEN 50

void reverse_name (char *name);
int read_line (char *str, int n);

int main (void)
{
    char user_input[MAX_INPUT_LEN + 1];

    printf("Enter your first and last name: ");
    read_line(user_input, MAX_INPUT_LEN);


    reverse_name(user_input);

    return 0;

}

int read_line (char *str, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    
    str[i] = '\0';
    
    return i;
}


/**
 * The function expect name to point to a string containing a first
 * name followed by a last name. example: "Ali Tastan". It modifies 
 * the string so that the last name comes first, followed by a comma,
 * a space, the first initial, and a period. The original string may 
 * contain extra spaces before the first name, between the first and
 * last names, and after the last name. 
*/
void reverse_name (char *name)
{
    char first_initial, last_name[MAX_NAME_LEN + 1], final_string[MAX_SURNAME_LEN + 1];
    int i = 0;

    // Skip extra spaces before the first name
    while (*name == ' ')
    {
        name++;
    }

    // name now points to the first initial.
    first_initial = *name;

    // Skip the first name
    while (*name != ' ')
    {
        name++;
    }

    // We are pointing to blank space skip extra spaces between
    // name and surname
    while (*name == ' ')
    {
        name++;
    }

    // name now points to the beginning of the surname. lets store it
    while (*name != '\0' && *name != ' ')
    {
        last_name[i++] = *name++;
    }


    // Modify the final string and print it.
    sprintf(final_string, "%s, %c.", last_name, first_initial);
    printf("%s\n", final_string);

}