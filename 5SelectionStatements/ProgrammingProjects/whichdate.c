#include <stdio.h>

int main (void)
{
    int d1, m1, y1;
    int d2, m2, y2;
    
    printf("Enter first date (dd / mm / yyyy): ");
    scanf("%d /%d /%d", &d1, &m1, &y1);
    printf("Enter second date (dd / mm / yyyy): ");
    scanf("%d /%d /%d", &d2, &m2, &y2);

    if (y1 < y2 || m1 < m2 || d1 < d2)
    {
        printf("%.2d/%.2d/%d is earlier than %.2d/%.2d/%d", d1, m1, y1, d2, m2, y2);
    }
    else printf("%.2d/%.2d/%d is earlier than %.2d/%.2d/%d", d2, m2, y2, d1, m1, y1);

}
