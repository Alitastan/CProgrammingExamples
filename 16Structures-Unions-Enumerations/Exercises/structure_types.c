
#include <stdio.h>

#define NAME_LEN 25

// Created the "part" structure tag
struct part 
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};



int main (void)
{
    struct part part1 = {528, "Disk Drive", 8};
    struct part part2;

    part2 = part1;

    printf("Disk number: %d\n", part2.number);
    return 0;
}