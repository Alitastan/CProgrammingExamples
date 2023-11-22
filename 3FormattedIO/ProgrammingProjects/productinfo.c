#include <stdio.h>

int main(void)
{
    int itemNumber, day, month, year;
    float itemPrice;

    printf("Enter item number: ");
    scanf("%d", &itemNumber);
    printf("Enter unit price: ");
    scanf("%f", &itemPrice);
    printf("Enter purchase date (mm/dd/yyyy) : ");
    scanf("%d / %d / %d", &day, &month, &year);

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$%8.2f\t%.2d/%.2d/%d", itemNumber, itemPrice, month, day, year );

    return 0;
}