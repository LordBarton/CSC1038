#include<stdio.h>
#include<stdlib.h>
#define PI 3.1415

int main(int argc, char * argv[])
{
    int radius, height;
    double area;

    if (argc == 1)
    {
        printf("No input given!");
    }
    else if (argc == 2)
    {
        printf("Two arguments needed!");
    }
    else
    {
        radius = atoi(argv[1]);
        height = atoi(argv[2]);
        if (radius < 0 || height < 0)
        {
            printf("The radius or height cannot be negative!\n");
        }
        else
        {
            area = 2 * PI * radius * height + 2 * PI * radius*radius;
            printf("%.2f\n", area);
        }
    }
    return 0;
}
