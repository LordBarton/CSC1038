#include<stdio.h>
#include<stdlib.h>

int count_char(char letter, char *string);

int main(int argc, char * argv[])
{
    char letter = argv[1][0];
    char *string = argv[2];
    return count_char(letter, string);
}

int count_char(char letter, char *string)
{
    char *p = string;
    int total = 0;

    while (*p != '\0')
    {
        if (*p == letter)
        {
            total ++;
        }
        p++;
    }
    printf("%d\n", total);
    return 0;
}
