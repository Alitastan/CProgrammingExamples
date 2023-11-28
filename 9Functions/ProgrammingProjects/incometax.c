/*  Income                      Amount of tax   
*   Not over $750               1% of income
*   $750 - $2,250               $7.50 + 2% of amount over $750
*   $2,250 - $3,750             $37.50 + 3% of amount over $2,250  
*   $3,750 - $5,250             $82.50 + 4% of amount over $3,750
*   $5,250 - $7,000             $142.50 + 5% of amount over $5,250   
*   Over $7000                  $230.00 + 6% of amount over $7,000  
*/  


#include <stdio.h>


double taxDue (double income);


int main (void)
{
    double income;
    printf("Enter your income: ");
    scanf("%lf", &income);


    printf("Income with Taxes: %f", taxDue(income));

    return 0;
    
}



double taxDue (double income)
{
    double tax = 0.0;

    if (income < 750.0)
        tax += income + income * 0.01;
    else if (income < 2250.0)
        tax += (income + 7.5) + income * 0.02;
    else if (income < 3750.0)
        tax += (income + 37.5) + income * 0.03;     
    else if (income < 5250.0)
        tax += (income + 82.5) + income * 0.04;
    else if (income < 7000.0)
        tax += (income + 142.5) + income * 0.05;  
    else
        tax += (income + 230.0) + income * 0.06;    

    return tax;  
}