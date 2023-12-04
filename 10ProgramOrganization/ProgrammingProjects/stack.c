
/*
   Hint: As the program reads characters, have it push each left
   parenthesis or left brace. When it reads a right parenthesis or,
   brace, have it pop the stack and check that the item popped is a
   matching parenthesis or brace. (If not, the parenthesis / braces
   aren't nested properly.) When the program reads the new-line
   character, have it check whether the stack is empty; if so, the
   parenthesis / braces are matched. If the stack isn't empty. (or
   if stackUnderFlow is ever called), the parenthesis / braces aren't 
   matched. If stackOverFlow is called, have the program print the message
   Stack over flow and terminate immediately. 
*/

#include <stdbool.h> /* C99 only  */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE  100

/* External variables   */
char contents[STACK_SIZE];
int top = 0;

void stackOverFlow (void);
void stackUnderFlow (void);
void makeEmpty (void);
bool isEmpty (void);
bool isFull (void);
void push (char c);
char pop (void);


int main (void)
{
    char match;
    char command;


    printf("Enter parentheses and / or braces: ");
    
    while ((command = getchar()) != '\n')
    {
        if (command == '(' || command == '{')
            push(command);
        
        if (command == ')' || command == '}')
        {
            match = pop();

            if (match != '(' && match != '{')
            {
                printf("Parenthesis / Braces are not nested properly!\n");
            }
        }



    }

    // When the program reads the new-line character
    if(isEmpty())
        printf("Parenthesis / Braces are matched properly!\n");
    else
        printf("Parenthesis / Braces are not matched!\n");
    
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
    top = 0;
}

bool isEmpty (void)
{
    return top == 0;
}

bool isFull (void)
{
    return top == STACK_SIZE;
}

void push (char c)
{
    if (isFull())
        stackOverFlow();
    else
        contents[top++] = c;
}

char pop (void)
{
    if (isEmpty())
        stackUnderFlow();
    else
        return contents[--top];
}