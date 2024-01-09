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
char expression_stack[STACK_SIZE + 1];
char *ptr_stack = &expression_stack[0];

/* Prototypes */
void stackOverFlow (void);
void stackUnderFlow (void);
void makeEmpty (void);
bool isEmpty (void);
bool isFull (void);
void push (char c);
char pop (void);

int evaluate_RPN_expression (const char *expression);
int read_line (char *str, int n);


int main (void)
{

    printf("Enter an RPN expression: ");

    read_line (expression_stack, STACK_SIZE);

    printf ("Result: %d\n", evaluate_RPN_expression(expression_stack));

    return 0;
}

void stackOverFlow (void)
{
    printf("Stack Over Flow");
    exit(EXIT_SUCCESS);
}

void stackUnderFlow (void)
{
    printf("Stack Under Flow");
    exit(EXIT_SUCCESS);
}

void makeEmpty (void)
{
    for (ptr_stack = expression_stack; ptr_stack < expression_stack + STACK_SIZE; ptr_stack++)
        *ptr_stack = 0;
    //top = 0;
    // ptr_stack = &expression_stack[0];
}

bool isEmpty (void)
{
    return ptr_stack == &expression_stack[0]; 
    //return top == 0;
}

bool isFull (void)
{
    return ptr_stack == &expression_stack[STACK_SIZE];
    //return top == STACK_SIZE;
    
}

void push (char c)
{
    if (isFull())
        stackOverFlow();
    else
        *ptr_stack++ = c;
}

char pop (void)
{
    if (isEmpty())
        stackUnderFlow();
    else
        return *--ptr_stack;
}


/**
 * The function returns the value of the RPN expression
 * pointed to by expression
*/
int evaluate_RPN_expression (const char *expression)
{
    /**
     * The process continues until the user enters a character
     * that is not an operator or operand.
     * 
     * When an operand is encountered, push it onto the stack.
     * When an operator is encountered, pop its operands from the stack,
     * perform the operation on those operands, and then push the result
     * onto the stack.
    */

    char num1, num2;
    int result = 0;

    
    while(*expression)
    {

        if (isdigit(*expression))
            push(*expression - '0'); // Convert character to integer and push onto the stack
            
        else if (ispunct(*expression))
        {
            switch (*expression)
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
                    result = pop();
                    break;

                default:
                    break;
            }
        }
        expression++;
    }

    return result;
}

int read_line (char *str, int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n && !isspace(ch))
            str[i++] = ch;
    
    str[i] = '\0';
    return i;
}