#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE  100

void stackOverFlow (void);
void stackUnderFlow (void);
void makeEmpty (void);
bool isEmpty (void);
bool isFull (void);
void push (int c);
int pop (void);

int stack_contents[STACK_SIZE];
int *top_ptr = &stack_contents[0];

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
    for (top_ptr = stack_contents; top_ptr < stack_contents + STACK_SIZE; top_ptr++)
        *top_ptr = 0;
    //top = 0;
}

bool isEmpty (void)
{
    return top_ptr == &stack_contents[0]; 
    //return top == 0;
}

bool isFull (void)
{
    return top_ptr == &stack_contents[STACK_SIZE];
    //return top == STACK_SIZE;
    
}

void push (int i)
{
    if (isFull())
        stackOverFlow();
    else
        *top_ptr++ = i;
}

int pop (void)
{
    if (isEmpty())
        stackUnderFlow();
    else
        return *--top_ptr;
}
