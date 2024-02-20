
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

#include "stack.h"

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

