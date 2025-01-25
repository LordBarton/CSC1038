#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Country Country;

struct Country
{
    char name[20];
    char cap[20];
    float popul;
    int size;
};

Country country[50];
int pcount = 0;
float total_pop = 0;

void input(int agrc, char *argv[]);
float avg(float total_pop, int pcount);

int main(int argc, char *argv[])
{
    input(argc, argv);
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation");
    printf("\n");

    for(int i = 0; i < pcount; i++)
    {
        printf("%s\t\t\t", country[i].name);
        printf("%s\t\t\t", country[i].cap);
        printf("%d\t\t\t", country[i].size);
        printf("%.2f\n", country[i].popul);
    }
    printf("Population average: %.2f\n", avg(total_pop, pcount));
    return 0;
}

void input(int argc, char *argv[])
{
    int index = 1;
    pcount = (argc - 1) / 4;

    for(int i = 0; i < pcount; i++)
    {
        strcpy(country[i].name, argv[index]);
        strcpy(country[i].cap, argv[index + 1]);
        country[i].popul = atof(argv[index + 2]);
        country[i].size = atoi(argv[index + 3]);

        total_pop += country[i].popul;
        index += 4;
    }
}

float avg(float total_pop, int pcount)
{
    return total_pop / pcount;
}
