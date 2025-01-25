/*
LABSHEET 9
TASK 4
 
Author: Bartosz Kogut
Date: 11/11/2024

This program finds the longest strings in an array of strings while dynamically allocating memory.
Input: strings in command line
Output: longest strings
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Prototype function
char **find_longest(char *arr[], int len, int *count);

int main(int argc, char *argv[])
{
    int length = argc - 1;
    // The pointer stores enough memory to allocate it dynamically
    char **pStrings = malloc(length * sizeof(char *));

    // Check for error
    if(!pStrings)
    {
        printf("Failed to allocate memory\n");
        return 1;
    }

    // Populate the array with command line arguments
    for (int i = 0; i < length; i++) 
    {
        pStrings[i] = malloc((strlen(argv[i + 1]) + 1) * sizeof(char));
        strcpy(pStrings[i], argv[i + 1]);
    } 

    // Store the function's output 
    int longest_count = 0;
    char **longest_strings = find_longest(pStrings, length, &longest_count);

    // Print the longest string(s) found
    for (int i = 0; i < longest_count; i++)
    {
        printf("%s\n", longest_strings[i]);
    } 
    
    // Free memory
    for (int i = 0; i < length; i++) {
        free(pStrings[i]);
    }
    free(pStrings);
    return 0;
}

// This function iterates through the strings from the command line and finds the longest ones and returns them in an array of pointers to strings.
char **find_longest(char *arr[], int len, int *count)
{
    int maxlen = 0;

    // Find the biggest string length in the array
    for (int i = 0; i < len; i++)
    {
        if (strlen(arr[i]) > maxlen)
        {
            maxlen = strlen(arr[i]);
        }
    }

    // Count how many longest strings there are
    *count = 0;
    for (int i = 0; i < len; i++)
    {
        if (strlen(arr[i]) == maxlen)
        {
            (*count)++;
        }
    }

    // Allocate memory for the new array of longest strings
    char **longest = malloc(*count * sizeof(char *));
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (strlen(arr[i]) == maxlen)
        {
            // Allocate memory for each string and populate the new array
            longest[j] = malloc((strlen(arr[i]) + 1) * sizeof(char));
            strcpy(longest[j], arr[i]);
            j++;
        }
    }

    // Return the new array
    return longest;
}
