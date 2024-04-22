#include <stdio.h>

enum
{
    NORTH,
    SOUTH,
    EAST,
    WEST
} direction;



int main (void)
{
    int x = 10, y = 4;

    direction = SOUTH;

    switch (direction)
    {
        case EAST: x++; break;
        case WEST: x--; break;
        case SOUTH: y++; break;
        case NORTH: y--; break;

    }

    printf("X: %d, Y: %d\n", x, y);
}