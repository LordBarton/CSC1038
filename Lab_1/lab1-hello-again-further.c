#include <stdio.h>

int main(int argc, char * argv[])
{
    char name[20];

    // prints message
    printf("Input Name: ");
    // asks user for input and stores it in name variable
    scanf("%s", name);
    // prints out hello and the name on seperate lines
    printf("Hello\n%s\n", name);
    return(0);
}
