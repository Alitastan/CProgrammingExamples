/* Adds two fractions */

#include <stdio.h>

int main(void)
{
    float num1, denom1, num2, denom2, resultNum, resultDenom;

    printf("Enter two fractions separated by a plus sign: ");
    scanf("%f / %f + %f / %f", &num1, &denom1, &num2, &denom2);

    resultNum = num1 * denom2 + num2 * denom1;
    resultDenom = denom1 * denom2;

    printf("The sum = %.2f / %.2f\nAnd the result = %.2f\n", resultNum, resultDenom, resultNum / resultDenom);

    return 0;
}