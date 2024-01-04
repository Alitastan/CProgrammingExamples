
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define FILE_NAME_LEN   100
#define EXTENSION_LEN   10

void get_extension (const char *file_name, char *extension);
bool test_extension (const char *file_name, const char *extension);


int main (void)
{
    char file_name[FILE_NAME_LEN], extension_name[EXTENSION_LEN];

    printf ("Enter file name: ");
    gets_s (file_name, FILE_NAME_LEN);

    get_extension (file_name, extension_name);

    printf("Test Extension: %d\n",
     test_extension (file_name, "txt"));

    puts (extension_name);
    puts (file_name);

    return 0;
}


/**
 * file_name points to a string containing a file name. The function
 * should store the extension on the file name in the string pointed
 * to by extension.
 * 
 * For example, if the file name is "memo.txt", the function will store
 * "txt" in the string pointed to by extension. If the file name doesn't
 * have an extension, the function should store an empty string (a single
 * null character) in the string pointed to by extension.
 * 
 * Note: Keep the function as simple as possible by having it use the
 * strlen and strcpy functions
*/
void get_extension (const char *file_name, char *extension)
{
    while (*file_name)
    {
        if (*file_name == '.')
        {
            // Found an extension

            // Skip the dot
            file_name++;

            while (*file_name)
                *extension++ = *file_name++;
            
            *extension = '\0';
        }
        else
        {
            // No extension
            strcpy (extension, "");
        }

        file_name++;
    }
}

/**
 * file_name points to a string containing a file name. The function
 * should return true if the file's extension matches the string pointed
 * to by extension, ignoring the case of letters. For example, the call
 * test_extension("memo.txt", "TXT") would return true. Incorporate the
 * "search for the end of a string" idiom into your function.
 * 
 * Hint: Use the toupper function to convert characters to upper-case
 * before comparing them.
*/
bool test_extension (const char *file_name, const char *extension)
{
    char cpy_file_name[FILE_NAME_LEN], cpy_extension_name[EXTENSION_LEN];
    char *p_file_name = cpy_file_name, *p_extension_name = cpy_extension_name;

    // Copying file_name and extension and converting characters to upper-case
    strcpy (cpy_file_name, file_name);
    strcpy (cpy_extension_name, extension);

    while (*p_file_name)
        *p_file_name++ = toupper (*p_file_name);

    while (*p_extension_name)
        *p_extension_name++ = toupper (*p_extension_name);

    // Re initializing pointers to first elements 
    p_file_name = cpy_file_name;
    p_extension_name = cpy_extension_name;

    while (*p_file_name)
    {
        if (*p_file_name == '.')
        {
            // Found an extension

            // Skip the dot
            p_file_name++;

            while (*p_file_name)
            {
                // Compare the rest of the text with the extension
                if (strcmp (p_file_name++, p_extension_name++) == 0)
                    return true;
                
            }
        }

        p_file_name++;

    }

    return false;
}








