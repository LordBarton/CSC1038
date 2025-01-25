#include <stdio.h>
#include <stdlib.h>

int main() {
    // Open the binary file for reading
    FILE *file = fopen("studentBinary.bin", "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while (!feof(file)) {
        int nameLength, collegeLength, age;
        float grade;
        char *name, *college;

        // Read the length of the student name
        if (fread(&nameLength, sizeof(int), 1, file) != 1) break;

        // Allocate memory for the name and read it
        name = (char *)malloc(nameLength + 1);
        if (!name) {
            perror("Memory allocation error");
            fclose(file);
            return 1;
        }
        if (fread(name, sizeof(char), nameLength, file) != nameLength) {
            free(name);
            break;
        }
        name[nameLength] = '\0'; // Null-terminate the string

        // Read the length of the college name
        if (fread(&collegeLength, sizeof(int), 1, file) != 1) {
            free(name);
            break;
        }

        // Allocate memory for the college name and read it
        college = (char *)malloc(collegeLength + 1);
        if (!college) {
            perror("Memory allocation error");
            free(name);
            fclose(file);
            return 1;
        }
        if (fread(college, sizeof(char), collegeLength, file) != collegeLength) {
            free(name);
            free(college);
            break;
        }
        college[collegeLength] = '\0'; // Null-terminate the string

        // Read the age and grade
        if (fread(&age, sizeof(int), 1, file) != 1 ||
            fread(&grade, sizeof(float), 1, file) != 1) {
            free(name);
            free(college);
            break;
        }

        // Display the data
        printf("Name: %s\n", name);
        printf("College: %s\n", college);
        printf("Age: %d\n", age);
        printf("Grade: %.2f\n", grade);

        // Free allocated memory
        free(name);
        free(college);
    }

    // Close the file
    fclose(file);

    return 0;
}
