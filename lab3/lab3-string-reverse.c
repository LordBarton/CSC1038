#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char rev(char *string)
{
    int len = strlen(string);

    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }
    printf("\n");
}

int main(int argc, char*argv[])
{
    rev(argv[1]);
    return 0;
}
