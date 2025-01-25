/*
LABSHEET 9
TASK 3
 
Author: Bartosz Kogut
Date: 11/11/2024

This program finds the largest number in an array that is also at least twice the size of at least one other number in the array.
Input: int array in command line
Output: integer
*/

#include<stdio.h>
#include<stdlib.h>

// Prototype functions
void bubblesort(int arr[], int n);
int find_largest_twice(int arr[], int len);

int main(int argc, char *argv[])
{
    int length = argc - 1;
    // The pointer stores enough memory to allocate it dynamically
    int *pNumbers = malloc(length * sizeof(int));

    // Check for error
    if(!pNumbers)
    {
        printf("Failed to allocate memory\n");
        return 0;
    }

    // Populate the array with command line arguments
    for(int i = 0; i < length; i++)
    {
        pNumbers[i] = atoi(argv[i + 1]);
    } 

    // Return the number and free up memory 
    printf("%d\n", find_largest_twice(pNumbers, length));
    free(pNumbers);

    return 0;
}

// This function iterates through
int find_largest_twice(int arr[], int len)
{
    // Sort the array in decreasing order, so the first number is the highest 
    bubblesort(arr, len);
    
    // Initiate to 0 in case number isn't found
    int found = 0;
    
    for (int i = 0; i < len; i++)
    {
        if (arr[i] >= arr[len - 1] * 2)
        {
            found = arr[i];
            break;
        }
    }

    // Return found number
    return found;
}

// Standard bubble sort algorithm
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
