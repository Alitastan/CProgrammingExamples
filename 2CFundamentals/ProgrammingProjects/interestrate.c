#include <stdio.h>

/*  Write a program that calculates the remaining balance
*   on a loan after the first, second, and third monthly
*   payments.
*/

int main(void)
{
    float loan, interestRate, monthlyPayment, balance, monthlyInterestRate;


    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthlyPayment);

    monthlyInterestRate = (interestRate / 100.0f ) / 12.0f;

    loan += (loan * monthlyInterestRate) - monthlyPayment;
    printf(" Balance remaining after first payment $%.2f\n", loan);
    loan += (loan * monthlyInterestRate) - monthlyPayment;
    printf(" Balance remaining after second payment $%.2f\n", loan);
    loan += (loan * monthlyInterestRate) - monthlyPayment;
    printf(" Balance remaining after third payment $%.2f\n", loan);

    return 0;
    
}