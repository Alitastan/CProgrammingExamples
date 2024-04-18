#include <stdio.h>

/**
 * Show how to declare a tag named complex for a structure
 * with two members, real and imaginary, of type double
*/

struct complex
{
    double real, imaginary;
};

struct complex make_complex (double real, double imaginary);
struct complex add_complex (struct complex a, struct complex b);

/**
 * Use the complex tag to declare variables named c1, c2 and c3
*/

int main (void)
{
    struct complex c3;

    struct complex c1 = make_complex(2.0, 3.0);
    struct complex c2 = make_complex(3.2, 4.5);
    
    c3 = add_complex (c1, c2);
    
    printf("C3 real: %lf C3 imaginary: %lf", c3.real, c3.imaginary);

}

struct complex make_complex (double real, double imaginary)
{
    struct complex x;

    x.real = real;
    x.imaginary = imaginary;

    return x;
}

struct complex add_complex (struct complex a, struct complex b)
{
    struct complex new;
    double real, imaginary;

    new.real = a.real + b.real;
    new.imaginary = a.imaginary + b.imaginary;

    return new;
}