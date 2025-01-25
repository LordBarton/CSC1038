#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *sort(int num, int array[], char *order)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            if ((strcmp(order, "asc") == 0 && array[j] > array[j + 1]) || (strcmp(order, "desc") == 0 && array[j] < array[j + 1]))
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
    return array;
}

int main(int argc, char *argv[])
{
    int* (*psort)(int, int[], char*) = sort;

    int num = atoi(argv[1]);
    int array[num];

    for (int i = 0; i < num; i++)
    {
        array[i] = atoi(argv[i + 2]);
    }

    char *order = argv[num + 2];

    int *sortedarray = psort(num, array, order);

    printf("Sorted numbers:");
    for (int j = 0; j < num; j++)
    {
        printf(" %d", sortedarray[j]);
    }
    printf("\n");

    return 0;
}
