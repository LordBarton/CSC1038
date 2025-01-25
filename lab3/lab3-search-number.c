#include<stdio.h>
#include<stdlib.h>

int find(int array[], int num, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == num)
        {
            printf("Found %i at %i\n", num, i);
            return 0;
        }
    }
    return 0;
}

int main(int argc, char * argv[])
{
    int length = argc - 2;
    int arr[length];
    int num = atoi(argv[1]);

    for (int i = 0; i < length; i++)
    {
        arr[i] = atoi(argv[i + 2]);
    }
    return find(arr, num, length);
}
