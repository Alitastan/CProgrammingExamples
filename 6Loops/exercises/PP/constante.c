#include <stdio.h>

int main (void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int denominator = 1;
    float quotient, sum = 1.0f;

    for (int i = 1; i <= n; i++)
    {
        denominator *= i;
        quotient = 1.0f / denominator;
        sum += quotient;

        printf("Quotient: %.6f\n", quotient); 
        printf("Sum: %.6f\n", sum);

    }


}