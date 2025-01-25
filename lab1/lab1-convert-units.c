#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
    float length = 0.0;

    length = atoi(argv[1]);

    // 2.54 cm for every inch, stored in a float to give an accurate conversion
    float length2 = length/2.54;

    printf ("%.2f\n", length2);

    return 0;
}
