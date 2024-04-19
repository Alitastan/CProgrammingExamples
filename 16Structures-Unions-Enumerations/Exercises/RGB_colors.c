#include <stdio.h>
#include <stdbool.h>

struct color
{
    int red;
    int green;
    int blue;
};

struct color make_color(int red, int green, int blue)
{
    struct color make;

    if (red < 0)
        red = 0;
    if (green < 0)
        green = 0;
    if (blue < 0)
        blue = 0;
    if (red > 255)
        red = 255;
    if (green > 255)
        green = 255;
    if (blue > 255)
        blue = 255;

    make.red = red;
    make.green = green;
    make.blue = blue;

    return make;

}

int getRed(struct color c)
{
    int red;

    red = c.red;

    return red;
}

bool equal_color(struct color color1, struct color color2)
{
    if (color1.blue == color2.blue &&
        color1.green == color2.green &&
        color1.red == color2.red)
        return true;

    else return false;
}

struct color brighter(struct color c)
{
    struct color brighter;

    if (c.blue == 0 && c.green == 0 && c.red == 0)
    {
        struct color brighter = {3, 3, 3};
        return brighter;
    }

    if (c.blue > 0 && c.blue < 3)
        c.blue = 3;
    if (c.green > 0 && c.green < 3)
        c.green = 3;
    if (c.red > 0 && c.red < 3)
        c.red = 3;
    else;

    brighter.blue = (int) c.blue / 0.7;
    brighter.green = (int) c.green / 0.7;
    brighter.red = (int) c.red / 0.7;

    if (brighter.blue > 255)
        brighter.blue = 255;
    if (brighter.green > 255)
        brighter.green = 255;
    if (brighter.red > 255)
        brighter.red = 255;
    

    return brighter;


}

struct color darker(struct color c)
{
    struct color darker;

    darker.blue = (int) c.blue * 0.7;
    darker.green = (int) c.green * 0.7;
    darker.red = (int) c.red * 0.7;

    return darker;
}

int main (void)
{
    int red;

    struct color new_color = make_color(14, 168, 260);
    struct color new_color2 = make_color(14, 168, 255);

    if (equal_color(new_color, new_color2))
        printf("Colors are equal!\n");
    else
        printf("Colors are not equal!\n");
    
    printf("Red value: %d\n", getRed(new_color));

    new_color = darker(new_color);

    printf("Red: %d, Green: %d, Blue: %d\n",
     new_color.red, new_color.green, new_color.blue);
}

