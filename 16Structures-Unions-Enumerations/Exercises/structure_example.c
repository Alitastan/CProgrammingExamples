

#include <stdio.h>
#include <string.h>

#define NAME_LEN 25

struct 
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} part2, part1 = {.number = 528, .name = "Disk Drive", .on_hand = 10};

int main (void)
{
    printf("Part number: %d\n", part1.number);
    printf("Part name: %s\n", part1.name);
    printf("Quantity on hand: %d\n", part1.on_hand);


    part1.number = 250;
    strcpy(part1.name, "New Disk");
    part1.on_hand--;

    printf("Part number: %d\n", part1.number);
    printf("Part name: %s\n", part1.name);
    printf("Quantity on hand: %d\n", part1.on_hand);

    // Copies the structure if both are compatible
    part2 = part1;

    printf("Part 2 number: %d\n", part2.number);
    printf("Part 2 name: %s\n", part2.name);
    printf("Quantity on hand: %d\n", part2.on_hand);

    return 0;
}