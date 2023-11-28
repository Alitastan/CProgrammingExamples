

#include <stdio.h>

void selectionSort (int array[], int length);


int main (void)
{
    int len;
    int i;
    printf("How many integers do you want to test? : ");
    scanf("%d", &len);

    // Variable length array
    int integers[len];

    printf("Enter a series of integers: ");

    for (i = 0; i < len; i++)
    {
        scanf("%d", &integers[i]);

    }

    printf("Original array: ");
    for (i = 0; i < len; i++)
        printf(" %d", integers[i]);

    printf("\n");


    selectionSort(integers, len);

    printf("Sorted array: ");
    for (i = 0; i < len; i++)
        printf(" %d", integers[i]);


}



void selectionSort (int array[], int length)
{

    if (length <= 1)
        return; // Array with 1 or 0 elements is already sorted

    int largestIndex = 0;

        for (int i = 1; i < length; i++)
        {
            if (array[i] > array[largestIndex])
            {
                // Search the array to find the largest element
                largestIndex = i;

            }
        }
        
        // Swap the largest element with the last element
        int temp = array[largestIndex];
        array[largestIndex] = array[length - 1];
        array[length - 1] = temp;

        // Call selectionSort recursively to sort the first
        // n - 1 elements of the array.

        selectionSort(array, length - 1);
}