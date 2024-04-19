/**
 * The following structures are designed to store information
 * about objects on a graphics screen
*/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>


struct point
{
    int x, y;
};

struct rectangle
{
    struct point upper_left, lower_right;
};

double compute_area(struct rectangle r);
struct point compute_center(struct rectangle r);
struct rectangle move_rectangle(struct rectangle r, int x, int y);
bool is_within_rectangle(struct rectangle r, struct point p);

int main (void)
{
    struct rectangle rectangle1;



    struct point upper_coord = {-6, 3};
    struct point lower_coord = {4, -2};

    rectangle1.upper_left = upper_coord;
    rectangle1.lower_right = lower_coord;

    struct point center = compute_center(rectangle1);
    printf("Center of the rectangle | x: %d y: %d \n", center.x, center.y);

    printf("The area of the rectangle: %lf\n", compute_area(rectangle1));

    struct rectangle moved_rectangle = move_rectangle(rectangle1, 3, -2);

    printf("New coordinates upper left | x: %d y: %d \n", moved_rectangle.upper_left.x, moved_rectangle.upper_left.y);
    printf("New coordinates lower right | x: %d y: %d \n", moved_rectangle.lower_right.x, moved_rectangle.lower_right.y);

    if (is_within_rectangle(moved_rectangle, (struct point) {-10, 4}))
        printf("within rectangle!\n");
    else
        printf("Not within rectangle!\n");

    
}


double compute_area(struct rectangle r)
{
    double area = 0.0;
    int base, height;

    height = abs(r.upper_left.y) + abs(r.lower_right.y);
    base = abs(r.upper_left.x) + abs(r.lower_right.x);

    area = height * base;

    return area;

    
}

struct point compute_center(struct rectangle r)
{
    struct point middle;

    middle.x = (r.upper_left.x + r.lower_right.x) / 2;
    middle.y = (r.upper_left.y + r.lower_right.y) / 2;

    return middle;
}

struct rectangle move_rectangle(struct rectangle r, int x, int y)
{
    struct rectangle new_rectangle_coord;

    if (x > 0 && y > 0)
    {
        new_rectangle_coord.upper_left.x = r.upper_left.x - x;
        new_rectangle_coord.upper_left.y = r.upper_left.y + y;
        new_rectangle_coord.lower_right.x = r.lower_right.x + x;
        new_rectangle_coord.lower_right.y = r.lower_right.y + y;
        
    }
    else if (x > 0 && y < 0)
    {
        new_rectangle_coord.upper_left.x = r.upper_left.x - x;
        new_rectangle_coord.upper_left.y = r.upper_left.y - y;
        new_rectangle_coord.lower_right.x = r.lower_right.x + x;
        new_rectangle_coord.lower_right.y = r.lower_right.y - y;
    }
    else if (x < 0 && y > 0)
    {
        new_rectangle_coord.upper_left.x = r.upper_left.x + x;
        new_rectangle_coord.upper_left.y = r.upper_left.y + y;
        new_rectangle_coord.lower_right.x = r.lower_right.x - x;
        new_rectangle_coord.lower_right.y = r.lower_right.y + y;
    }
    else if (x < 0 && y < 0)
    {
        new_rectangle_coord.upper_left.x = r.upper_left.x + x;
        new_rectangle_coord.upper_left.y = r.upper_left.y - y;
        new_rectangle_coord.lower_right.x = r.lower_right.x - x;
        new_rectangle_coord.lower_right.y = r.lower_right.y - y;
    }
    else;


    return new_rectangle_coord;

}

bool is_within_rectangle(struct rectangle r, struct point p)
{

    if (p.x >= r.upper_left.x && p.x <= r.lower_right.x &&
    p.y >= r.lower_right.y && p.y <= r.upper_left.y)
        return true;
    
    else return false;
}
