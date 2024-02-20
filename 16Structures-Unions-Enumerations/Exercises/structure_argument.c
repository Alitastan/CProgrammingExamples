
#include <stdio.h>
#include <string.h>

#define NAME_LEN 25

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};


void print_part (struct part p)
{
    printf("Part number: %d\n", p.number);
    printf("Part name: %s\n", p.name);
    printf("Quantity on hand: %d\n", p.on_hand);
}

struct part build_part (int number, const char *name,
                        int on_hand)
{
    struct part p;

    p.number = number;
    strcpy(p.name, name);
    p.on_hand = on_hand;

    return p;
}                        

int main (void)
{
    struct part part1 = {.number = 20, .name = "Dofus", .on_hand = 12};
    struct part part2;

    print_part(part1);

    printf("\n");

    part2 = build_part(510, "Apex Legends", 10);
    print_part(part2);

    printf("\n");
    // Compount Literal can be used to create unnamed arrays
    print_part ((struct part) {450, "New Game", 5});

    struct part part3 = (struct part) {400, "Other", 4};

    print_part ((struct part) {.number = 5,
                                .name = "AC",
                                .on_hand = 4});
}