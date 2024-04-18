#include <stdio.h>

typedef struct
{
    double real, imaginary;
}Complex;

Complex make_complex (double real, double imaginary);
Complex add_complex (Complex a, Complex b);

int main (void)
{
    Complex c3;
    Complex c1 = make_complex(3.1, 4.2);
    Complex c2 = make_complex(2.5, 3.4);

    c3 = add_complex(c1, c2);

    printf("%lf %lf", c3.real, c3.imaginary);

    return 0;
}


Complex make_complex (double real, double imaginary)
{
    Complex x;

    x.real = real;
    x.imaginary = imaginary;

    return x;
}

Complex add_complex (Complex a, Complex b)
{
    Complex new;
    double real, imaginary;

    new.real = a.real + b.real;
    new.imaginary = a.imaginary + b.imaginary;

    return new;
}