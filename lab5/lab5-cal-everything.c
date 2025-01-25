#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float add(int a, int b)
{
    return a + b;
}

float dif(int a, int b)
{
    return a - b;
}

float prd(int a, int b)
{
    return a * b;
}

float dvn(float a, float b)
{
    return a / b;
}

float pwr(int a, int b)
{
    return pow(a, b);
}

float nlg(int a, int b)
{
    return log(a) + log(b);
}

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("%.2f\n", add(a, b));
    printf("%.2f\n", dif(a, b));
    printf("%.2f\n", prd(a, b));
    printf("%.2f\n", dvn(a, b));
    printf("%.2f\n", pwr(a, b));
    printf("%.2f\n", nlg(a, b));

    return 0;
}
