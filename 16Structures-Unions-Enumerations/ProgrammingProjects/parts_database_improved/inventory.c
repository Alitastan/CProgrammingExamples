/**
 * Maintains a parts database (array version)
*/

#include <stdio.h>
#include "readline.h"

#define NAME_LEN    25
#define MAX_PARTS   100
#define UPDATE_PRICE    1
#define UPDATE_QUANTITY 2

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    float price;
};


int find_part(int number, const struct part inventory[], int num_parts);
void insert(struct part inventory[], int *num_parts);
void search(const struct part inventory[], int num_parts);
void update(struct part inventory[], int num_parts);
void print(struct part inventory[], int num_parts);
void sort_inventory (struct part inventory[], int size);



/**
 * main: Prompts the user to enter an operation code,
 * then calls a function to perform the requested action.
 * Repeats until the user enters the command 'q'. Prints
 * an error message if the user enters an illegal code.
*/
int main(void)
{
    struct part inventory[MAX_PARTS];
    char code;
    int num_parts = 0; // Number of parts currently stored

    for(;;)
    {
        printf("Enter operation code: ");
        printf("\n(i -> insert | s -> search | u -> update | p -> print | q -> exit.)\n");
        scanf(" %c", &code);
        while (getchar() != '\n') // Skips to end of line
        ;

        switch (code)
        {
            case 'i': insert(inventory, &num_parts); break;
            case 's': search(inventory, num_parts); break;
            case 'u': update(inventory, num_parts); break;
            case 'p': print(inventory, num_parts); break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

/**
 * find_part: Looks up a part number in the inventory
 * array. Returns the array index if the part number is
 * found; otherwise, returns -1.
*/
int find_part(int number, const struct part inventory[], int num_parts)
{
    int i;
    
    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;

    return -1;
}

/**
 * insert: Prompts the user for information about a new
 * part and then inserts the part into the database. Prints
 * an error message and returns prematurely if the part 
 * already exists or the database is full.
*/
void insert(struct part inventory[], int *num_parts)
{
    int part_number;

    if (*num_parts == MAX_PARTS)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number, inventory, *num_parts) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    inventory[*num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);

    printf("Enter item price: ");
    scanf("%f", &inventory[*num_parts].price);

    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);
    (*num_parts)++;
}

/**
 * search: Prompts the user to enter a part number, then
 * looks up the part in the database. If the part exists,
 * prints the name and quantity on hand; if not, prints
 * an error message.
*/
void search(const struct part inventory[], int num_parts)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inventory, num_parts);

    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Part price: %f\n", inventory[i].price);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else
    {
        printf("Part not found.\n");
    }
}

/**
 * update: Prompts the user to enter a part number.
 * Prints an error message if the part doesn't exist;
 * otherwise, prompts the user to enter change in quantity
 * on hand and updates the database.
*/
void update(struct part inventory[], int num_parts)
{
    int i, number, change, command;
    float new_price = 0.0f;
    
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, inventory, num_parts);

    if (i >= 0)
    {
        printf("Enter to update [1(PRICE), 2(QUANTITY)]: ");
        scanf("%d",&command);
        switch (command)
        {
            case UPDATE_PRICE:
                printf("Enter the new price: ");
                scanf("%f", &new_price);
                inventory[i].price = new_price;
                break;

            case UPDATE_QUANTITY: 
                printf("Enter change in quantity on hand: ");
                scanf("%d", &change);
                inventory[i].on_hand += change;
                break;
        }

    }
    else
    {
        printf("Part not found.\n");
    }
}

/**
 * print: Prints a listing of all parts in the database,
 * showing the part number, part name, and quantity on hand.
 * Parts are printed in the order in which they were entered
 * into the database.
*/
void print(struct part inventory[], int num_parts)
{
    int i;

    printf("Part Number  Part Name  Part Price     "          
    "Quantity on Hand\n");

    
    sort_inventory(inventory, num_parts);

    for (i = 0; i < num_parts; i++)
        printf("%7d      %s   %-15.4f  %d\n",
        inventory[i].number,
        inventory[i].name,
        inventory[i].price,
        inventory[i].on_hand);
    
}

// Bubble sort the inventory
void sort_inventory (struct part inventory[], int num_parts)
{
    int i, j;

    for (i = 0; i < num_parts - 1; i++)
    {
        for (j = 0; j < num_parts - i - 1; j++)
        {
            if (inventory[j].number > inventory[j + 1].number)
            {

                struct part temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;

            }

        }
    }

}