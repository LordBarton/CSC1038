/*
LABSHEET 9
TASK 5
 
Author: Bartosz Kogut
Date: 12/11/2024

This program defines and prints a Student struct for 2 students with their name, programme and grade.
Then it reallocates more memory depending if there's more than 2 students provided in the input.
Input: Student struct members in CLI
Output: details of all students
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// The student struct and its members
typedef struct
{
    char name[20];
    char prog[20];
    float grade;
} Student;

// Prototype functions
void input(int argc, char *argv[], Student *pStudent, int capacity);
void out(Student *s, int capacity);

int main(int argc, char *argv[])
{
    Student *pStudent;
    
    // Initial Student capacity is set to 2
    int capacity = 2;

    // Allocate initial memory
    pStudent = calloc(capacity, sizeof(Student));
    
    int num_stud = (argc - 1) / 3;

    // If there's more than 2 students, reallocate more memory for them
    if (num_stud > 2)
    {
        capacity = num_stud;
        Student *pTemp = realloc(pStudent, capacity*sizeof(Student));
        
        if (!pTemp)
        {
            printf("Memory allocation failed\n");
            free(pStudent);
            pStudent = NULL;
            return 1;
        }

        pStudent = pTemp;
    }

    // Take student details and print them out
    input(argc, argv, pStudent, capacity);
    out(pStudent, capacity);
    
    // Free up memory
    free(pStudent);

    return 0;
}

// Function to populate the array of Student structs
void input(int argc, char *argv[], Student *pStudent, int capacity)
{
    int count = 0;
    for (int i = 0; i < capacity; i++)
    {
        strcpy(pStudent[i].name, argv[count + 1]);
        strcpy(pStudent[i].prog, argv[count + 2]);
        pStudent[i].grade = atof(argv[count + 3]);
        count += 3;
    }
}

void out(Student *s, int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        printf("%s, %s, %.2f\n", s[i].name, s[i].prog, s[i].grade);
    }
}
