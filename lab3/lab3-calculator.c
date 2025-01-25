#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

float mult(float a, float b)
{
    return a * b;
}

float divi(float a, float b)
{
    return a / b;
}

int main(int argc, char * argv[])
{
    char *operation = argv[1];
    float a = atof(argv[2]);
    float b = atof(argv[3]);

    if (strcmp(operation, "multiply") == 0)
    {
        printf("%f\n", mult(a, b));
    }
    else if (strcmp(operation, "divide") == 0)
    {
        if (isinf(divi(a,b)))
        {
            printf("invalid\n");
        }
        else
        {
            printf("%f\n", divi(a, b));
        }
    }

    return 0;
}
