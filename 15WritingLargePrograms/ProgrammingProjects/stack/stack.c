
#include "stack.h"

/* External variables   */
char contents[STACK_SIZE];
int top = 0;

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