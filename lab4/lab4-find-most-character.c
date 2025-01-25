#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char most(char *string);

int main(int argc, char * argv[])
{
    char *string = argv[1];
    return most(string);
}

char most(char *string)
{
    int max = 0;
    char *pstring = string;
    char result;

    while (*pstring != '\0')
    {
        int total = 0;

        for (int i = 0; i < strlen(string); i++)
        {
            if (*pstring == string[i] && *pstring != ' ')
            {
                total++;
            }
            if (total > max)
            {
                max = total;
                result = string[i];
            }
        }
        pstring++;
    }
    printf("%c\n", result);
    return 0;
}
