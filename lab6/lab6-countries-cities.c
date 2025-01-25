#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Country Country;

struct Country
{
    char name[30];
    char city1[30];
    float size1;
    char city2[30];
    float size2;
    char city3[30];
    float size3;
};

Country country[50];
int pcount = 0;

void find(int pcount, Country country[]);

int main(int argc, char *argv[])
{
    int index = 1;
    pcount = (argc - 1) / 7;

    for(int i = 0; i < pcount; i++)
    {
        strcpy(country[i].name, argv[index]);
        strcpy(country[i].city1, argv[index + 1]);
        country[i].size1 = atof(argv[index + 2]);
        strcpy(country[i].city2, argv[index + 3]);
        country[i].size2 = atof(argv[index + 4]);
        strcpy(country[i].city3, argv[index + 5]);
        country[i].size3 = atof(argv[index + 6]);

        index += 7;
    }

    find(pcount, country);
    return 0;
}

void find(int pcount, Country country[])
{
    for (int j = 0; j < pcount; j++)
    {
        int max = country[j].size1;
        char *biggest = country[j].city1;
        if (country[j].size2 > max)
        {
            max = country[j].size2;
            biggest = country[j].city2;
        }
        if (country[j].size3 > max)
        {
            max = country[j].size3;
            biggest = country[j].city3;
        }
        printf("%s: %s\n", country[j].name, biggest);
    }
}
