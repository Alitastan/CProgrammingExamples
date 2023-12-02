#include <stdio.h>

#define PI  3.14f
#define VOLUME_OF_SPHERE(R)    ( (4.0f / 3.0f) * PI * R)

int main(void)
{
    float radius;
    printf("Enter the radius of the sphere: ");
    scanf("%f", &radius);
    float R = radius * radius * radius;

    printf("Volume of the sphere is: %f\n", VOLUME_OF_SPHERE(R));

    return 0;
}