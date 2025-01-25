#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
    int width = atoi(argv[1]);

    if (width <= 0){
        return 1;
    }
    for (int i = 1; i <= width; ++i) printf("*");
    printf("\n");

    for(int i = 1; i <= width - 2; ++i){
        printf("*");
        for (int j = 1; j <= width - 2; ++j){
            printf(" ");
        }
        printf("*\n");
    }

    for (int i = 1; i <= width; ++i) printf("*");
    printf("\n");

    return 0;
}
