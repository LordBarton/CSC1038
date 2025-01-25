#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 200

int main() {
    // Open the text file for reading
    FILE *file = fopen("paragraph.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_SENTENCE_LENGTH + 1]; // Buffer to store each line
    char longestLine[MAX_SENTENCE_LENGTH + 1] = ""; // To store the longest line
    int maxLength = 0; // To store the length of the longest line

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline character if present
        line[strcspn(line, "\n")] = '\0';

        int length = strlen(line);
        if (length > maxLength) {
            maxLength = length;
            strcpy(longestLine, line); // Update the longest line
        }
    }

    // Close the file
    fclose(file);

    // Display the results
    printf("%d\n", maxLength + 1);
    printf("%s\n\n", longestLine);

    return 0;
}
