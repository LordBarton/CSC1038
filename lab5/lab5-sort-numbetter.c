#include<stdio.h>
#include<stdlib.h>

void bubblesort(int arr[], int n, int order);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int arr[n];
    int order = 0;

    for (int i = 0; i < n; i++)
    {
        arr[i] = atoi(argv[i + 2]);
    }
    if (strcmp(argv[argc - 1], "asc") == 0)
    {
        order = 1;
    }
    else if (strcmp(argv[argc - 1], "desc") == 0)
    {
        order = 2;
    }

    bubblesort(arr, n, order);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void bubblesort(int arr[], int n, int order)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (order == 1 && arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else if (order == 2 && arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
