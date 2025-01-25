/*
LAB EXAM 2
TASK 1

Author: Bartosz Kogut
Date: 28/11/2024

This program finds the most frequent element (degree) in an array of integers from the command line and prints it out.
I decided to first sort the array with bubble sort to make it easier to iterate over the same numbers and count their frequency, comparing it with each new element.
Input: integers in CLI
Output: number of occurences of the most frequent integer
*/

#include<stdio.h>
#include<stdlib.h>

// Prototype functions
int *input(int argc, char *argv[]);
int find_freq(int array[], int len);
void bubblesort(int arr[], int n);

int main(int argc, char *argv[])
{
    int len = argc - 1;    // Length of the array input

    // Allocate memory for the input variable with a pointer
    int *array = malloc(len * sizeof(int));

    array = input(argc, argv);
    int most_freq = find_freq(array, argc - 1);

    printf("%d\n", most_freq);    // Print out the degree of the list

    free(array);    // Free up the memory
    return 0;
}

int *input(int argc, char *argv[])
{
    int len = argc - 1;

    int *array = calloc(len, sizeof(int));    // Allocate memory for the array input

    // Populate the array with integers from the CLI
    for (int i = 0; i < len; i++)
    {
        array[i] = atoi(argv[i + 1]);
    }

    return array; // Return a pointer to the array of integers

    free(array);    // Free up memory
}

int find_freq(int array[], int len)
{

    bubblesort(array, len); // Use bubble sort to sort the numbers in ascending order

    int count = 1;  // Track appearance of current number
    int max = 0;    // Store highest number of appearance

    // Iterate over the array
    for (int i = 1; i < len; i++)
    {
        // Compare if the previous number reappeared again, if yes, increment count
        if (array[i] == array[i - 1])
        {
            count++;

            // If the appearance is the highest so far, update the max variable
            if (count > max)
            {
                max = count;
            }
        }

        // If the number doesn't reappear again, start the count again
        else
        {
            count = 1;
        }
    }

    // Return the degree
    return max;
}

// Standard bubble sort algorithm in ascending order
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
