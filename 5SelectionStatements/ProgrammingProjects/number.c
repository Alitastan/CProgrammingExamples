#include <stdio.h>

int main (void)
{
    int number, firstDigit, secondDigit;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    if (number <= 0 || number >= 100)
    {
        printf("Number is not a two digit number");
        return -1;
    }

    firstDigit = number % 10;
    secondDigit = number / 10;

    printf("You entered the number ");

    switch (secondDigit)
    {
        case 10: printf("Yüz"); break;
        case 9: printf("Doksan"); break;
        case 8: printf("Seksen"); break;
        case 7: printf("Yetmiş"); break;
        case 6: printf("Altmis"); break;
        case 5: printf("Elli"); break;
        case 4: printf("Kirk"); break;
        case 3: printf("Otuz"); break;
        case 2: printf("Yirmi"); break;
        case 1: printf("On"); break;

    }
    printf(" ");

    switch (firstDigit)
    {
        case 1: printf("Bir"); break;
        case 2: printf("İki"); break;
        case 3: printf("Üç"); break;
        case 4: printf("Dört"); break;
        case 5: printf("Beş"); break;
        case 6: printf("Alti"); break;
        case 7: printf("Yedi"); break;
        case 8: printf("Sekiz"); break;
        case 9: printf("Dokuz"); break;

    }
}