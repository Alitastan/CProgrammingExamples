
#include <stdio.h>


// Perfect way to define bool in C89
typedef enum
{
    FALSE,
    TRUE
}Bool;

// enum values can be arbitrary constants
enum dept
{
    RESEARCH = 20,
    PRODUCTION = 10,
    SALES = 25
};


int main(void)
{
    
    int i;

    // enum is subject to C scope rules, here it's only in main
    enum suit
    {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    }s;

    i = DIAMONDS; // i is 1
    s = 0; // s is 0 (clubs)
    s++; // s is 1 (diamonds)
    i = s + 2; // i is 3

    printf("i: %d", i);
    


}