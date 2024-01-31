
/**
 * Let s be a string and let i be an int variable. Show the output
 * produced by each of the following program fragments
*/

#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a'+ 'A' : (c))
#define MAX_STRING_LEN  50
#define PROGRAM_FRAGMENT 0

int main (void)
{
    int i;
    char s[MAX_STRING_LEN];

    #if PROGRAM_FRAGMENT
    strcpy(s, "abcd");
    i = 0;
    putchar(TOUPPER(s[++i]));
    //expands to
    //putchar(('a' <= (s[++i]) && (s[++i]) <= 'z' ? (s[++i]) - 'a'+ 'A' : (s[++i])))
    #else
    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));
    //expands to
    //putchar(('a' <= (s[++i]) && (s[++i]) <= 'z' ? (s[++i]) - 'a'+ 'A' : (s[++i])))
    #endif
}