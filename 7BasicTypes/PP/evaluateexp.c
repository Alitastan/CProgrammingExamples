#include <stdio.h>

int main (void)
{
    float operand1, operand2, operand3, result1 = 0.0f, result2 = 0.0f;
    char operator1, operator2;

    printf("Enter an expression: ");

    do 
    {
        scanf("%f %c %f %c %f", &operand1, &operator1, &operand2, &operator2, &operand3);

        switch (operator1)
        {
            case '+':
                result1 = operand1 + operand2; break;
            case '-':
                result1 = operand1 - operand2; break;
            case '*':
                result1 = operand1 * operand2; break;
            case '/':
                if(operand2 != 0 && operand3 != 0)
                    result1 = operand1 / operand2;
                else
                {
                    printf("The result is undefined.\n");
                    return -1;
                }
                break;

            default:
                printf("Please enter a valid input.\n");
                break;
          
        }


        switch (operator2)
        {
            case '+':
                result2 = result1 + operand3; break;
            case '-':
                result2 = result1 - operand3; break;
            case '*':
                result2 = result1 * operand3; break;
            case '/':
                if(operand2 != 0 && operand3 != 0)
                    result2 = result1 / operand3;
                else
                {
                    printf("The result is undefined.\n");
                    return -1;
                }
                break;

            default:
                printf("Please enter a valid input.\n");
                break;
                
          
        }

        printf("Result: %f\n", result2);

    }while (getchar() != '\n');
}