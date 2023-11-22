#include <stdio.h>

#define TAX_PERCENT 5.0f

int main(void)
{
    float originalAmount, finalAmount;
    float tax = ( TAX_PERCENT / 100.0f );

    printf("Enter an amount :");
    scanf("%f",&originalAmount);

    finalAmount = ( originalAmount + ( originalAmount * tax ) );

    printf("With %%%.2f tax added your money: $%.2f", TAX_PERCENT, finalAmount );
    
    return 0;
}