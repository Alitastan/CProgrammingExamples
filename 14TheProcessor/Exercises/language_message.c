

#include <stdio.h>

#define FRENCH

int main (void)
{
    #if defined(ENGLISH) && !defined(FRENCH) && !defined(SPANISH)
        printf("Insert Disk 1\n");
    #elif !defined(ENGLISH) && defined(FRENCH) && !defined(SPANISH)
        printf("Inserez Le Disque 1\n");
    #elif !defined(ENGLISH) && !defined(FRENCH) && defined(SPANISH)
        printf("Inserte El Disco 1\n");
    #else
        printf("Choose one of the languages!\n");
    #endif

    return 0;
}