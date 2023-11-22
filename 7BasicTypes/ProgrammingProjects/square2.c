#include <stdio.h>
#include <limits.h>


int main (void)
{
    int n;
    long long i;
    char ch;

    printf("This program prints table of squares.\n");
    printf("Enter number of entries in table: ");

    scanf("%d", &n);
    /* Dispose of new-line character following number of entries*/
    ch = getchar();

    for (i = 0; i <= n; i++)
    {
        printf("%15lld%15lld\n", i, i * i);
        if (i % 24 == 0)
        {
            printf("Press Enter to Continue...");
            ch = getchar();
        }

    }

    return 0;
}