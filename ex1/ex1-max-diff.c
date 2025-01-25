/*
LAB EXAM 1
TASK 1

Author: Bartosz Kogut
Date: 31/10/2024

This program finds the biggest difference in an array of integers. The way I did it
is I first found the biggest and smallest number in the array and substracted them from eachother. thus finding the biggest difference

Input: array of numbers
Output: Integer, biggest difference
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Declared prototype functions

int find_smallest(int arr[], int size);
int find_largest(int arr[], int size);

int main(int argc, char *argv[])
{
    // The size of the given array
    int size = argc - 1;
    int arr[size];

    // If the user provides not enough or too many cml arguments, an error message will print out accordingly
    if (argc < 3)
    {
        printf("Minimum number of elements is 2\n");
        return 1;
    }
    if (argc > 101)
    {
        printf("Maximum number of elements is 100\n");
        return 1;
    }

    // Populate the array with cml arguments

    for(int i = 0; i < size; i++)
    {
        arr[i] = atoi(argv[i + 1]);
    }

    // Assign the found numbers
    int smallest = find_smallest(arr, size);
    int largest = find_largest(arr, size);

    // Calculate and print out the difference
    int diff = largest - smallest;
    printf("%d\n", diff);
}

int find_smallest(int arr[], int size)
{
    // Store the first number as a placeholder so we can compare
    int min = arr[0];

    // I used a simple for loop to compare the numbers and store the smallest one in min variable
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            // If the current number is smaller than the min, it gets stored in min instead
            min = arr[i];
        }
    }

    // Return the smallest int
    return min;
}

int find_largest(int arr[], int size)
{
    int max = arr[0];

    // Exact same process as find_smallest except we look for bigger numbers
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}
