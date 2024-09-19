#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // For using the abs function
#define PI 3.14

int main(int argc, char* argv[])
{
    // Make sure user gives an argument, if they don't then print out an error messaghe
    if (argc > 1) {

        int radius = 0;
        float area = 0.0;

        radius = atoi(argv[1]);

        // Check if radius is negative, if it is, print out error message
        if (radius < 0) {
        printf("Please use a positive number. Automatically correcting to %d.\n", abs(radius));
        radius = abs(radius);  // Convert to positive with the abs function(learned on W3 Schools)
        }

        area = radius * radius * PI;
        printf("The area of the circle is: %.2f\n", area);
    }
    else {
        printf("Please provide an input");
    }
    return 0;
}
