#include<stdio.h>
#include<stdlib.h>

int dup(int array[], int length);

int main(int argc, char * argv[])
{
    int length = argc - 1;
    int array[length];

    for (int i = 0; i < length; i++)
    {
        array[i] = atoi(argv[i + 1]);
    }
    return dup(array, length);
}

int dup(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (array[i] == array[j])
            {
                printf("%d\n", array[i]);
                return 0;
            }
        }
    }
    printf("no duplicated number\n");
    return 0;
}
