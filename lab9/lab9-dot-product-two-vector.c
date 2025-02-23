/*
LABSHEET 9
TASK 1

Author: Bartosz Kogut
Date: 11/11/2024

This program uses dynamic memory allocation to store 2 vectors given in the cml and calculate their dot product.
Output: input, dot product of 2 vectors
*/

#include<stdio.h>
#include<stdlib.h>

// Prototype function
int dot_product(int *vector1, int *vector2, int length);

int main(int agrc, char *argv[])
{
    // Length of each vector is given in first argument
    int length = atoi(argv[1]);
    // Used malloc to store memory for the vector data
    int *vector1 = (int*)malloc(length*sizeof(int));
    int *vector2 = (int*)malloc(length*sizeof(int));
    int *pResult = NULL;

    // Check if the memory was allocated successfully
    if(!vector1 || !vector2)
    {
        printf("Failed to allocate memory");
        return 0;
    }

    // Populate the pointers with the vector data
    for(int i = 0; i < length; i++)
    {
        *(vector1 + i) = atoi(argv[i + 2]);
        *(vector2 + i) = atoi(argv[i + 2 + length]);
    }

    // Use calloc for practice to store the result of the dot product
    pResult = calloc(1, sizeof(int));
    *pResult = dot_product(vector1, vector2, length);

    // Print out result and free up memory
    printf("%d\n", *pResult);
    free(pResult);
    free(vector1);
    free(vector2);

    return 0;
}

int dot_product(int *vector1, int *vector2, int length)
{
    int total = 0;

    // Calculate the dot product by multiplying the adjacent vectors and adding them together
    for(int i = 0; i < length; i++)
    {
        total += *(vector1 + i) * *(vector2 + i);
    }

    return total;
}
