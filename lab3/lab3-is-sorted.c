#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int array[], int length);
void print_sorted(int array[], int length);

void bubble_sort(int array[], int length) {
    int temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void print_sorted(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main(int argc, char * argv[])
{
    int length = argc - 1;
    int array[length];

    for (int i = 0; i < length; i++)
    {
        array[i] = atoi(argv[i + 1]);
    }

    bubble_sort(array, length);
    print_sorted(array, length);
    return 0;
}
