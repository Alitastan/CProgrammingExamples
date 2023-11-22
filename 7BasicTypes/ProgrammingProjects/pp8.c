#include <stdio.h>
#include <ctype.h>


int main (void)
{
    char ch;
    int minute, hour;
    printf("Enter a 12-hour time: ");
    scanf("%d :%d", &hour, &minute);
    
    
    while ( (ch = getchar()) != '\n' )
    {
        switch (toupper(ch))
        {
            case 'P': 
                printf("%.2d:%.2d PM", 12 + hour, minute); break;
            case 'A': 
                printf("%.2d:%.2d AM", hour, minute); break;
            default: break;
        }

    }



    return 0;
}