#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
    int tr = atoi(argv[1]);
    int co = atoi(argv[2]);
    int pe = atoi(argv[3]);
    int dr = atoi(argv[4]);

    int total = tr * 5 + co * 2 + pe * 3 + dr * 3;
    printf("%d\n", total);
}
