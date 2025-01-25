#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
    int nums[argc - 1];

    for(int i = 1; i < argc; ++i)
    {
        nums[i - 1] = atoi(argv[i]);
    }

    int total = 0;
    for(int i = 0; i < argc - 1; ++i)
    {
        if (nums[i] % 2 == 0){
            printf("%d - %d\n", i, nums[i]);
            total += 1;
        }
    }
    if (total == 0){
        printf("Not found!\n");
    }

    return 0;
}
