/*
LABSHEET 9
TASK 2

Author: Bartosz Kogut
Date: 11/11/2024

This program finds the second largest number in an array of floats by using bubble sort and looking for the second biggest float.
Input: float array in command line
Output: float, second largest number
*/

#include<stdio.h>
#include<stdlib.h>

// Prototype functions
void bubblesort(float arr[], int n);
float find_second(float arr[], int len);

int main(int argc, char *argv[])
{
    int length = argc - 1;
    // The pointer stores enough memory to allocate dynamically
    float *pNumbers = (float*)malloc(length * sizeof(float));

    // Check for error
    if(!pNumbers)
    {
        printf("Failed to allocate memory\n");
        return 0;
    }

    // Populate the array with command line arguments
    for(int i = 0; i < length; i++)
    {
        *(pNumbers + i) = atof(argv[i + 1]);
    }

    // Sort the array decreasingly, so the first number is the highest 
    bubblesort(pNumbers, length);

    // Return the second biggest float and free up memory 
    printf("%.1f\n", find_second(pNumbers, length));
    free(pNumbers);

    return 0;
}

// This function checks for duplicates of the highest value and returns the largest second number after that.
float find_second(float arr[], int len)
{
    int i = 0;
    float biggest = arr[0];

    // While biggest number has duplicates, we iterate over the array
    while (arr[i] == biggest && i < len)
    {
        i++;
    }
    return arr[i];
}

// Standard bubble sort algorithm
void bubblesort(float arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
