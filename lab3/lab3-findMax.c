#include<stdio.h>
#include<stdlib.h>

int max(int array[], int length)
{
    int max = array[0];
    for (int i = 1; i <= length - 1; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

int main(int argc, char * argv[])
{
    int arr[argc - 1];
    int length = argc -1;

    for (int i = 0; i < length; i++)
    {
        arr[i] = atoi(argv[i + 1]);
    }
    printf("%d\n", max(arr, length));
    return 0;
}
