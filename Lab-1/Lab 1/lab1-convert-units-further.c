#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
    float length;

    scanf ("%f", &length);

    float length2 = length/2.54;

    printf ("%.2f\n", length2);

    return 0;
}
