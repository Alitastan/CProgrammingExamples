#ifndef STACK_H
#define STACK_H

#include <stdbool.h> /* C99 only  */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE  100


void stackOverFlow (void);
void stackUnderFlow (void);
void makeEmpty (void);
bool isEmpty (void);
bool isFull (void);
void push (char c);
char pop (void);

#endif // STACK_H