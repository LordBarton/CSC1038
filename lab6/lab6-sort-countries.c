#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Country Country;

struct Country
{
    char name[30];
    char capital[30];
    int size;
    float pop;
};

Country country[50];
int pcount = 0;

void find(int pcount, Country country[]);
void bubblesort(Country country[], int pcount);

int main(int argc, char *argv[])
{
    int index = 1;
    pcount = (argc - 1) / 4;

    for(int i = 0; i < pcount; i++)
    {
        strcpy(country[i].name, argv[index]);
        strcpy(country[i].capital, argv[index + 1]);
        country[i].pop = atof(argv[index + 2]);
        country[i].size = atoi(argv[index + 3]);

        index += 4;
    }
    bubblesort(country, pcount);
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    for (int j = 0; j < pcount; j++)
    {
        printf("%s\t\t\t", country[j].name);
        printf("%s\t\t\t", country[j].capital);
        printf("%d\t\t\t", country[j].size);
        printf("%.2f\n", country[j].pop);
    }
    return 0;
}

void bubblesort(Country country[], int pcount)
{
    for (int i = 0; i < pcount - 1; i++)
    {
        for (int j = 0; j < pcount - i - 1; j++)
        {
            if (country[j].pop < country[j + 1].pop)
            {
                Country temp = country[j];
                country[j] = country[j + 1];
                country[j + 1] = temp;
            }
        }
    }
}
