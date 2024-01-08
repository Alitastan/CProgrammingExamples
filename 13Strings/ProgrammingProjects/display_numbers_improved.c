#include <stdio.h>

int main (void)
{
    int number, f_digit, s_digit;

    const char *first_digit[] = {"", "One", "Two", "Three", "Four", "Five",
                                "Six", "Seven", "Eight", "Nine", "Ten"};

    const char *second_digit[] = {"", "Ten", "Twenty", "Thirty", "Fourty",
                                "Fifty", "Sixty", "Seventy", "Eighty",
                                "Ninety", "Hundred"};

    const char *exceptional_numbers[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen",
                                "Fiveteen", "Sixteen", "Seventeen", "Eighteen",
                                "Nineteen"}; 

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    if (number <= 0 || number >= 100)
    {
        printf("Number is not a two digit number");
        return -1;
    }

    f_digit = number % 10;
    s_digit = number / 10;

    if (10 < number && number < 20)
        printf("You entered the number %s!",
            exceptional_numbers[f_digit]);
    else
        printf("You entered the number %s %s!",
            second_digit[s_digit], first_digit[f_digit]);

   
}