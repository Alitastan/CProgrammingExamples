

#include <string.h>
#include <stdio.h>

#define DOMAIN_LEN  50
#define FINAL_DOMAIN_LEN    100

void build_index_url (const char *domain, char *index_url);
void remove_filename (char *url);

int main (void)
{
    char domain[DOMAIN_LEN], final_domain[FINAL_DOMAIN_LEN];
    printf ("Enter your domain (knking.com): ");
    gets_s (domain, DOMAIN_LEN);

    build_index_url (domain, final_domain );

    puts (final_domain);
    
    remove_filename (final_domain);

    puts (final_domain);

    return 0;
}



/**
 * Domain points to a string containing an Internet domain, such as
 * "knking.com". The function should add "http://www." to the beginning
 * of this string and "/index.html" to the end of the string, storing
 * the result in the string pointed to by index_url. (In this example,
 * the result will be "http://www.knking.com/index.html".) You may assume
 * that index_url points to a variable that is long enough to hold the
 * resulting string. Keep the function as simple as possible by having
 * it use the strcat and strcpy functions.
 * 
*/
void build_index_url (const char *domain, char *index_url)
{
    char domain_cpy[DOMAIN_LEN];
    strcpy (domain_cpy, domain);

    char p_beginning[] = "http://www.";
    char p_ending[] = "/index.html";

    strcpy(index_url, strcat (p_beginning, strcat (domain_cpy, p_ending)));
}

/**
 * url points to a string containing a URL that ends with a file name
 * such as ("http://www.knking.com/index.html"). The function should
 * modify the string by removing the file name and the preceding slash.
 * (In this example, the result will be "http://www.knking.com".) 
 * 
 * Incorporate the "search for the end of a string" idiom into your
 * function.
 * 
 * Hint: Have the function replace the last slash in the string by a null
 * character.
*/
void remove_filename (char *url)
{

    // Go to the end of the string
    while (*url)
        url++;

    // Go back until finding a '/'
    while (strcmp(url--, "/") != 0)
    {
        if (*url == '/')
        {
            *url = '\0';
            break;
        }
    }
   
}