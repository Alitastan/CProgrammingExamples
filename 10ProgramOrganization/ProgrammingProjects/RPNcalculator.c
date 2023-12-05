/*  
*   Some calculators (notably those from Hewlett-Packard)   
*   use a system of writing mathematical expressions known
*   as Reverse Polish Notation (RPN). In this notation, operators
*   are placed after their operands instead of between their operands.
*   For example, 1 + 2 would be written 1 2 + in RPN, and 1 + 2 * 3
*   would be written 1 2 3 * +. RPN expressions can easily be evaluated
*   using a stack. The algorithm involves reading the operators and operands
*   in an expression from left to right, performing the following actions:
*   
*   When an operand is encountered, push it onto the stack.
*   When an operator is encountered, pop its operands from the stack, perform
*   the operation on those operands, and then push the result on the stack.
*
*   This program evaluates RPN expressions. 
*
*   Note: The operands will be single digit integers.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE  100

/* External variables */
int numbers[STACK_SIZE];
int topOfTheStack = 0;

/* Prototypes */
void stackOverFlow (void);
void stackUnderFlow (void);
void makeEmpty (void);
bool isEmpty (void);
bool isFull (void);
void push (int element);
int pop (void);



int main (void)
{
    char ch;
    int operand;
    int num1, num2 = 0;

    printf("Enter an RPN expression: ");

    /**
     * The process continues until the user enters a character
     * that is not an operator or operand.
     * 
     * When an operand is encountered, push it onto the stack.
     * When an operator is encountered, pop its operands from the stack,
     * perform the operation on those operands, and then push the result
     * onto the stack.
    */
    for(;;)
    {

        scanf(" %c", &ch);

        if (isdigit(ch))
        {
            operand = ch - '0'; // Convert char to integer

            switch (operand)
            {
                case 1:  push(operand); break;
                case 2:  push(operand); break;
                case 3:  push(operand); break;
                case 4:  push(operand); break;
                case 5:  push(operand); break;
                case 6:  push(operand); break;
                case 7:  push(operand); break;
                case 8:  push(operand); break;
                case 9:  push(operand); break;

                default: break;
            }
        }

        else if(ispunct(ch))
        {
            switch (ch)
            {
                case '+':
                    num1 = pop();
                    num2 = pop();
                    push(num1 + num2);
                    break;
                case '-':
                    num1 = pop();
                    num2 = pop();
                    push(num2 - num1);
                    break;
                case '*':
                    num1 = pop();
                    num2 = pop();
                    push(num1 * num2);
                    break;
                case '/':
                    num1 = pop();
                    num2 = pop();
                    push(num2 / num1);
                    break;
                case '=':
                    printf("Top of the stack item: %d\n"
                    , numbers[topOfTheStack - 1]);
                    // The stack is cleared after showing the result.
                    makeEmpty();
                    printf("\nEnter an RPN expression: ");
                    break;
                default:
                    break;
            }
        }
        else
        {
            // Handle invalid characters if necessary
            return -1;
        }



    }

    return 0;
}

void stackOverFlow (void)
{
    printf("Expression is too complex.");
    exit(EXIT_SUCCESS);
}

void stackUnderFlow (void)
{
    printf("Not enough operands in expression.");
    exit(EXIT_SUCCESS);
}

void makeEmpty (void)
{
    topOfTheStack = 0;
}

bool isEmpty (void)
{
    return topOfTheStack == 0;
}

bool isFull (void)
{
    return topOfTheStack == STACK_SIZE;
}

void push (int element)
{
    if(isFull())
        stackOverFlow();
    else
        numbers[topOfTheStack++] = element;
}

int pop (void)
{
    if(isEmpty())
        stackUnderFlow();
    else
        return numbers[--topOfTheStack];
}


