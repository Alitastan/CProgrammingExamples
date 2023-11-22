/* Computes the dimensional weight of a 12" x 10" 8" box */

#include <stdio.h>

int main(void)
{
    int height = 8, length = 12, width = 10;
    int volume = height * length * width;

    printf("Dimensions: %dx%dx%dx\n", length, width, height);
    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds) : %d\n", (height * length * width + 165) / 166);

    return 0;
}