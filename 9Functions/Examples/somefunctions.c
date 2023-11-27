

#include <stdio.h>

int largestElement (int a[], int len);
float average (int a[], int len);
int numberOfPositiveElements (int a[], int len);


int main (void)
{
    int array[] = {3, 5, 7, -4, -9, -20, 5, 32};
    
    printf("Largest element in the array: %d\n", largestElement(array, 8));
    printf("The average of the values: %f\n", average(array, 8));
    printf("Positive number count: %d\n", numberOfPositiveElements(array, 8));

    return 0;
}

int largestElement (int a[], int len)
{
    int i;
    int largest = a[0];

    for (i = 1; i < len; i++)
        if (a[i] > largest)
            largest = a[i];

    return largest;
}

float average (int a[], int len)
{
    int i;
    float sum = 0.0f;

    for (i = 0; i < len; i++)
        sum += a[i];

    return sum / len;
}

int numberOfPositiveElements (int a[], int len)
{
    int i;
    int positiveNumberCount = 0;

    for (i = 0; i < len; i++)
    {
        if (a[i] > 0)
            positiveNumberCount++;
    }

    return positiveNumberCount;
}