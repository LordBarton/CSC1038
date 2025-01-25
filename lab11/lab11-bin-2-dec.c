#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to calculate the decimal equivalent of a binary string
void calculateDecimal(char *binary, int *decimal) {
    *decimal = 0;
    int length = strlen(binary);

    for (int i = 0; i < length; i++) {
        *decimal = (*decimal << 1) + (binary[i] - '0');
    }
}

int main(int argc, char *argv[]) {
    // Check if too many arguments are entered
    if (argc - 1 > 8) {
    printf("Too many binary digits entered.\n");
        return 1;
    }

    // Validate input and construct the binary string
    char binary[9] = ""; // Buffer for up to 8 digits + null terminator
    for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) != 1 || (argv[i][0] != '0' && argv[i][0] != '1')) {
            return 1;
        }
        strcat(binary, argv[i]); // Append valid binary digit to the string
    }

    int decimal = 0;

    // Calculate the decimal equivalent
    calculateDecimal(binary, &decimal);

    // Print the result
    printf("%d\n", decimal);

    return 0;
}
