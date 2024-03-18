

#include <stdio.h>

struct Number
{
    enum {INT_KIND, DOUBLE_KIND} kind; // Tag field
    union
    {
        int i;
        double d;
    }u;
};

void print_number(struct Number n);

int main (void)
{
    struct Number n;

    n.kind = INT_KIND;
    n.u.i = 82;

    print_number(n);

    n.kind = DOUBLE_KIND;
    n.u.d = 75.254;

    print_number(n);
}

/**
 * It is the program's responsibility to change the tag
 * field each time an assignment is made to a member of 
 * the union.
*/
void print_number(struct Number n)
{
    if (n.kind == INT_KIND)
        printf("%d\n", n.u.i);
    else
        printf("%g\n", n.u.d);
}