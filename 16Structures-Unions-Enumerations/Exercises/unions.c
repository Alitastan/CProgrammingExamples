
#include <stdio.h>
#include <string.h>

#define TITLE_LEN   100
#define AUTHOR_LEN  100
#define DESIGN_LEN  100

struct catalog_item
{
    int stock_number;
    double price;
    int item_type;
    union
    {
        struct 
        {
            char title[TITLE_LEN + 1];
            char author[AUTHOR_LEN + 1];
            int num_pages;
        }book;

        struct  
        {
            char design[DESIGN_LEN + 1];
        }mug;

        struct 
        {
            char design[DESIGN_LEN + 1];
            int colors;
            int sizes;
        }shirt;
    }item;

};

int main (void)
{
    struct catalog_item c;
    
    strcpy(c.item.mug.design, "Cats");

    printf("%s", c.item.shirt.design); // prints "Cats"

    
    
}