#include <stdio.h>

struct fraction
{
    int numerator, denominator;
}f, f1, f2;


int gcd (int m, int n)
{
    int remainder;

    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    return m;
}

struct fraction reduce_fraction (struct fraction a)
{
    struct fraction reduced;
    int greatcommdivis = gcd(a.numerator, a.denominator);

    reduced.numerator = a.numerator / greatcommdivis;
    reduced.denominator = a.denominator / greatcommdivis;

    return reduced;

}

struct fraction add_fraction (struct fraction a, struct fraction b)
{
    struct fraction added;
    
    if (a.denominator == b.denominator)
    {
        added.numerator = a.numerator + b.numerator;
        added.denominator = a.denominator;
    }
    else
    {
        added.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
        added.denominator = a.denominator * b.denominator;
        
    }
    added = reduce_fraction(added);
    printf("Addition: %d / %d\n", added.numerator, added.denominator);

    return added;
}

struct fraction substract_fraction (struct fraction a, struct fraction b)
{
    struct fraction substracted;

    if (a.denominator == b.denominator)
    {
        substracted.numerator = b.numerator - a.numerator;
        substracted.denominator = b.denominator;
    }
    else
    {
        substracted.numerator = b.numerator * a.denominator - a.numerator * b.denominator;
        substracted.denominator = a.denominator * b.denominator;
    }
    substracted = reduce_fraction(substracted);
    printf("Substraction: %d / %d\n", substracted.numerator, substracted.denominator);

    return substracted;
}

struct fraction multiply_fraction (struct fraction a, struct fraction b)
{
    struct fraction multiplied;

    multiplied.numerator = a.numerator * b.numerator;
    multiplied.denominator = a.denominator * b.denominator;

    multiplied = reduce_fraction(multiplied);
    printf("Multiplication: %d / %d\n", multiplied.numerator, multiplied.denominator);
    
    return multiplied;
}

struct fraction divide_fraction(struct fraction a, struct fraction b)
{
    struct fraction divided;

    if (a.denominator != 0 && b.denominator != 0)
    {
        divided.numerator = a.numerator * b.denominator;
        divided.denominator = a.denominator * b.numerator;
    }
    else
        printf ("Division by 0!\n");

    divided = reduce_fraction(divided);
    printf("Division: %d / %d\n", divided.numerator, divided.denominator);

    return divided;

    
}

int main (void)
{
    f1.numerator = 4;
    f1.denominator = 1;

    f2.numerator = 2;
    f2.denominator = 3;

    add_fraction(f1, f2);
    substract_fraction(f1,f2);
    multiply_fraction(f1, f2);
    divide_fraction(f1, f2);

    return 0;
}

