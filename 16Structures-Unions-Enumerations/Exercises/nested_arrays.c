
#include <stdio.h>
#include <string.h>

#define FIRST_NAME_LEN  40
#define LAST_NAME_LEN   40

struct person_name
{
    char first[FIRST_NAME_LEN + 1];
    char middle_initial;
    char last[LAST_NAME_LEN + 1];
};

// We can use the person_name structure as part of a larger structure
struct student
{
    struct person_name name;
    int id, age;
    char sex;
}student1, student2;

void display_name (struct student s)
{
    printf("Student name: %s\n", s.name.first);
    printf("Student middle initial: %c\n", s.name.middle_initial);
    printf("Student surname: %s\n", s.name.last);
}

int main (void)
{
    strcpy(student1.name.first, "Fred");
    printf("Student name: %s\n", student1.name.first);
    printf("\n");
    
    struct person_name new_name;
    strcpy(new_name.first, "Ali");
    strcpy(new_name.last, "Tastan");
    new_name.middle_initial = '\0';

    student2.name = new_name;

    display_name(student2);

    display_name((struct student) {.name.first = "Compound",
    .name.last = "Literal",
    .name.middle_initial = 'N'}); 
}

