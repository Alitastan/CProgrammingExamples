#include <stdio.h>

// ASCII character set for math operators

#define MULTIPLICATION  42
#define ADDITION        43
#define SUBSTRACTION    45
#define DIVISION        47

int main (void)
{
    float number1, number2;
    char operator;

    printf("Enter number 1 then enter (+,-,*,/) and then enter number 2. :");
    printf("\nType X to exit\n\n\n");
    

    while (scanf("%f %c %f", &number1, &operator, &number2) == 3)
    {

        if(getchar() == 'X')
            break;

        switch (operator)
        {
            case MULTIPLICATION:
                printf("Multiplication result: %f\n",
                    number1 * number2);
                break;
            case ADDITION:
                printf("Addition result: %f\n",
                    number1 + number2);
                break;
            case SUBSTRACTION:
                printf("Substraction result: %f\n",
                    number1 - number2);
                break;
            case DIVISION:
                if ( number2 != 0)
                    printf("Division result: %f\n",
                        (float) number1 / number2);
                else
                    printf("Division by zero is undefined here.\n");
                break;
            default:
                printf("Enter a valid math operator.\n"); break;

        }
    }

    return 0;
}