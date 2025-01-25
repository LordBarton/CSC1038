/*
LABSHEET 9
TASK 7
 
Author: Bartosz Kogut
Date: 12/11/2024

This program checks if the given integer is a power of two
Input: Integer in CLI
Output: "Yes" or "No"
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);

    // A power of 2 in binary should have exactly 1 bit
    if ((n & (n - 1)) == 0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}
