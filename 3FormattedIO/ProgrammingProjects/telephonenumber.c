#include <stdio.h>

int main(void)
{
    int areaCode;
    int firstArea, secondArea, thirdArea, fourthArea;

    printf("Enter phone number [ (+xx) xxx-xxx-xx-xx ]: ");
    scanf("+ %d - %d - %d - %d - %d", &areaCode, &firstArea, &secondArea, &thirdArea, &fourthArea);

    printf("You entered: +%d.%d.%d.%d.%d",
        areaCode, firstArea, secondArea, thirdArea, fourthArea);

    return 0;
}