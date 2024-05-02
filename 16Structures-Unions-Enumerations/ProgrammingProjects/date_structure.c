/**
 * Modify Programming Project 9 from Chapter 5 so that each
 * date entered by the user is stored in a date structure
 * (see Exercise 5). Incorporate the compare_dates function
 * of Exercise 5 in your program.
*/

#include <stdio.h>

#define MAX_DATE_STORAGE    100
#define DAYS_IN_A_YEAR  365

struct date
{
    int day, month, year;
};

int day_of_year (struct date d);
int compare_dates(struct date d1, struct date d2);
void print(struct date d[], int input_num);
void insert(struct date d[], int *input_num);
void sort_dates(struct date d[], int input_num);

int main (void)
{
    struct date user_input[MAX_DATE_STORAGE];

    int input_num = 0;
    char code;


    for (;;)
    {
        printf("Enter operation code:");
        printf("\n(i -> insert | p -> print | q -> exit.): ");
        scanf(" %c", &code);

        while (getchar() != '\n') // Skips to end of line
        ;

        switch (code)
        {
            case 'i': 
                insert(user_input, &input_num);
                break;
            case 'p':
                print(user_input, input_num);
                break;
                
            case 'q':
                return 0;
        }
        printf("\n");
    }
    

    return 0;

}


int day_of_year (struct date d)
{
    int dayNumbers[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayCount = 0;
    int i;

    for (i = 1; i < d.month; i++)
    {
        dayCount += dayNumbers[i - 1];
    }

    // Adjust for leap years, assuming they are divisible by 4
    if ((d.year % 4 == 0 && d.month > 2)  && (d.year % 100 != 0 || d.year % 400 == 0))
        dayCount++;
    
    return dayCount + d.day + (d.year * DAYS_IN_A_YEAR);
}

int compare_dates(struct date d1, struct date d2)
{
    if (day_of_year(d1) < day_of_year(d2))
        return -1; 
    else if (day_of_year(d1) > day_of_year(d2))
        return 1;  
    else 
        return 0;
}

void sort_dates(struct date d[], int input_num)
{
    int i, j;

    for (i = 0; i < input_num - 1; i++)
    {
        for (j = 0; j < input_num - i - 1; j++)
        { 
            if (compare_dates(d[j], d[j + 1]) > 0)
            {
                struct date temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
            }  

        }
    }


}

void print(struct date d[], int input_num)
{
    int i;
    printf("input num: %d\n", input_num);

    sort_dates(d, input_num);

    printf("Day / Month / Year\n");

    for(i = 0; i < input_num; i++)
    {
        printf("%.2d/%.2d/%d\n",
        d[i].day,
        d[i].month,
        d[i].year
        );
    }

}

void insert(struct date d[], int *input_num)
{

    if (*input_num == MAX_DATE_STORAGE)
    {
        printf("Database is full; can't add more dates.\n");
        return;
    }

    printf("Enter date (dd/mm/yyyy): ");


    scanf("%d%*c%d%*c%d",
    &d[*input_num].day,
    &d[*input_num].month,
    &d[*input_num].year);


    (*input_num)++;
}
