#include <stdio.h>

#define N 10
#define INC(x) ((x) + 1)
#define SUB(x,y) ((x) - (y))
#define SQR(x) ((x) * (x))
#define CUBE(x) (SQR(x) * (x))
#define M1(x,y) (x##y)
#define M2(x,y) (#x #y)

int main (void)
{
    int a[N], i, j, k, m, jk;

    #ifdef N
        i = j;
    #else
        j = i;
    #endif
    
    i = 10 * INC(j); // 10 * (j + 1)
    i = SUB(j, k); // i = j - k
    i = SQR(SQR(j)); // i = j^4
    i = CUBE(j); // i = j^3
    i = M1(j, k); // i = jk
    puts(M2(i, j)); // "i j"

    #undef SQR
        i = SQR(j);
    #define SQR
        i = SQR(j);

    return 0;
}