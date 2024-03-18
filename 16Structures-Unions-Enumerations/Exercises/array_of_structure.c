
#include <stdio.h>

#define NAME_LEN    50

struct dialing_code
{
    char *country;
    int code;
};

struct part 
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

const struct dialing_code country_codes[] =
{{"Argentina", 54}, {"Bangladesh", 880},
{"Brazil", 55}, {"Colombia", 57},
{"Turkiye", 90}, {"Poland", 48}};

int main (void)
{
    printf("Country: %s, Code: %d", country_codes[4].country, country_codes[4].code);

    // Initialize the inventory array to contain a single part
    struct part inventory[100] = 
    {[0].number = 528, [0].on_hand = 10, [0].name = '\0'};
}