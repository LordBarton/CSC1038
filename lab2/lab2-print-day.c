#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
    char days[][10] = {
    "Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
    };

    int n = atoi(argv[1]);

    printf("%s\n", days[n - 1]);
    return 0;
}
