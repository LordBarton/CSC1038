#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // I set all the variables to -1 so that the following do-while loops(learned on W3 Schools) run at least once.
    int tr = -1, co = -1, pe = -1, dr = -1;

    // This one big loop checks all the variables checking if they both exist AND are non-negative.
    do {
    if (tr < 0) {
        printf("Enter try value: ");
        scanf("%d", &tr);
        // If the user input is actually negative, the programm asks them for a positive number again.
        if (tr < 0){
            printf("Please enter a positive value\n");
        }
    }
    if (co < 0) {
        printf("Enter conversion value: ");
        scanf("%d", &co);
        if (co < 0){
            printf("Please enter a positive value\n");
        }
    }
    if (pe < 0) {
        printf("Enter penalty value: ");
        scanf("%d", &pe);
        if (pe < 0){
            printf("Please enter a positive value\n");
        }
    }
    if (dr < 0) {
        printf("Enter drop-goal value: ");
        scanf("%d", &dr);
        if (dr < 0){
            printf("Please enter a positive value\n");
        }
    }
    // This runs through all the needed numbers until we get them
    } while (tr < 0 || co < 0 || pe < 0 || dr < 0);

    // After all that we sum them up and print them
    int total = tr * 5 + co * 2 + pe * 3 + dr * 3;
    printf("Total: %d\n", total);

    return 0;
    }
