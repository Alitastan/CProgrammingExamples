#include <stdio.h>




int main (void)
{
    char c;
    int i;
    short s;
    long l;
    float f;
    double d;
    long long ll;
    long double ld;

    printf("Size of char: %zu\n", sizeof(c));
    printf("Size of short: %zu\n", sizeof(s));
    printf("Size of int: %zu\n", sizeof(i));
    printf("Size of long: %zu\n", sizeof(l));
    printf("Size of float: %zu\n", sizeof(f));
    printf("Size of double: %zu\n", sizeof(d));
    printf("Size of long long: %zu\n", sizeof(ll));
    printf("Size of long double: %zu\n", sizeof(ld));
}