#include <stdio.h>

struct
{
    double real, imaginary;
}c1 = {.real = 0.0, .imaginary = 1.0}, c2 = {.real = 1.0, .imaginary = 0.0}, c3;


int main (void)
{
    /**
     * Write statements that copy the members of c2 into c1
     * Can this be done in one statement or does it require two?
    */
   
   printf("C1, Real: %lf, Imaginary: %lf\n"
   ,c1.real, c1.imaginary);

      printf("C2, Real: %lf, Imaginary: %lf\n"
   ,c2.real, c2.imaginary);

    // Copy with single statement
   c1 = c2;

    printf("New C1, Real: %lf, Imaginary: %lf\n"
   ,c1.real, c1.imaginary);

    // Write statements that adds c1 and c2 and stores in c3
   c3.real = c1.real + c2.real;
   c3.imaginary = c1.imaginary + c2.imaginary;

    printf("C3, Real: %lf, Imaginary: %lf\n"
   ,c3.real, c3.imaginary);
}