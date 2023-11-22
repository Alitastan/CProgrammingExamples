#include <stdio.h>

int main (void)
{
    int octal = 077;
    int hex1 = 0x77;
    int hex2 = 0XABC;

    printf("octal: %d hex1: %d hex2: %d", octal, hex1, hex2);

    return 0;
}