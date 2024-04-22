
#include <stdio.h>

#define PI  3.1415

enum shape_kind
{
    RECTANGLE,
    CIRCLE
};

struct point
{
    int x, y;
};

struct shape
{
    enum shape_kind kind; /* RECTANGLE or CIRCLE */
    struct point center; /* coordinates of center 0 */
    union
    {
        struct
        {
            int height, width;
        }rectangle;
        
        struct
        {
            int radius;
        }circle;
    }u;
}s;

double compute_area (struct shape s)
{


    if (s.kind == RECTANGLE)
        return s.u.rectangle.height * s.u.rectangle.width;
    
    else  
        return PI * s.u.circle.radius * s.u.circle.radius;


}

struct shape move_center (struct shape s, int x_direction, int y_direction)
{
    struct shape new_shape = s;
    new_shape.center.x += x_direction;
    new_shape.center.y += y_direction;

    return new_shape;
}

struct shape scale_shape (struct shape s, double scale_factor)
{

    struct shape new_shape = s;

    if (new_shape.kind == RECTANGLE)
    {
        new_shape.u.rectangle.height *= scale_factor;
        new_shape.u.rectangle.width *= scale_factor;
    }
    else
    {
        new_shape.u.circle.radius *= scale_factor;
    }

    return new_shape;
}

int main (void)
{
    struct shape first_shape;

    first_shape.kind = RECTANGLE;
    first_shape.u.rectangle.height = 5;
    first_shape.u.rectangle.width = 4;

    printf("Height:%ld Width:%ld\n",
        first_shape.u.rectangle.height, first_shape.u.rectangle.width);
    printf("The area of rectangle is: %lf\n", compute_area(first_shape));

    first_shape.center.x = 10;
    first_shape.center.y = 20;

    printf("The center of rectangle (x,y) = (%d,%d)\n"
        ,first_shape.center.x, first_shape.center.y);
    
    first_shape = move_center(first_shape, -4, 7);

    printf("The center of rectangle (x,y) = (%d,%d)\n"
    ,first_shape.center.x, first_shape.center.y);

    first_shape = scale_shape(first_shape, 0.5);
    printf("Height:%ld Width:%ld\n",
        first_shape.u.rectangle.height, first_shape.u.rectangle.width);

}