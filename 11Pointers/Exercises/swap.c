

#include <stdio.h>

void swap (int *p, int *q);

int main (void)
{
    int num1 = 5, num2 = 10;

    printf("Before swap: ");
    printf("Num1: %d Num2: %d\n", num1, num2);

    swap(&num1, &num2);

    printf("After swap: ");
    printf("Num1: %d Num2: %d\n", num1, num2);

    return 0;
}


void swap (int *p, int *q)
{
    int temp;

    // Save p temporary
    temp = *p;
    // save the value of q into p
    *p = *q;
    // save the value of p into q
    *q = temp;
}
