/**
 * Suppose that a program consists of three source files
 * main.c, f1.c and f2.c - plus two header files f1.h and
 * f2.h. All three source files include f1.h, but only f1.c
 * and f2.c include f2.h. Write a make file for this program
 * assuming that the compiler is gcc and that the executable
 * file is to be named demo.
*/

#include <stdio.h>
#include "f1.h"

int main (void)
{
    printf("Build successful\n");

    return 0;
}