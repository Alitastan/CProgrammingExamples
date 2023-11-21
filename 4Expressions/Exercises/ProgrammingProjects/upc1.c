#include <stdio.h>

/*
*   European countries use 13-digit code, known as European Article Number (EAN) 
*   instead of the 12-digit Universal Product Code (UPC) found in North America.
*   Each EAN ends with check digit and to calculate EAN:
*   1. Add the second, fourth, sixth, tenth, and twelfth digits
*   2. Add the first, third, fifth, seventh, ninth and eleventh digits
*   3. Multiply the first sum by 3 and add it to the second sum.
*   4. Substract 1 from the total.
*   5. Compute the remainder when the adjusted total is divided by 10
*   6. Substract the remainder from 9.
*/

int main(void)
{
    int  checkDigit, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
    int firstSum, secondSum, total;

    printf("Enter the first 12 digits of an EAN: ");
    scanf("%1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d", &d1, &d2, &d3, &d4, &d5, &d6,
        &d7, &d8, &d9, &d10, &d11, &d12);

    
    firstSum = d2 + d4 + d6 + d8 + d10 + d12;
    secondSum = d1 + d3 + d5 + d7 + d9 + d11;

    total = (secondSum + (3 * firstSum)) - 1;
    checkDigit = 9 - (total % 10);

    printf("Check digit: %d\n", checkDigit);

    return 0;

}