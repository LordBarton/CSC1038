#include<stdio.h>
#include<stdlib.h>

/*Declare a structure of Student */
typedef struct Student Student;

struct Student {
	char name[20];
	char programme[20];
	float grade;
	Student *next;
};

/*Functional prototype */
Student* get_students(); /* You may notice that the function get_students return the type Student*, implying that the function will return a pointer that points to a Student */
void printStudentList(Student *start); /*to print the student list */

int main()
{
	Student *start = NULL;

	start = get_students();
	printStudentList(start);
	return 0;
}

Student* get_students() /* This mean that the function will return a pointer that points to the structure Student */
{
	Student *current, *first; /*declare two pointers */
	int selection; /* to ask if the user keep entering new student data or stop */


	first = (Student*)calloc(1,sizeof(Student)); /*create the first node */
	current = first; /*Now the current node is also the first node */

	/*fill data for the first node */
	printf("Student name: \n");
	scanf("%s", current->name);
	printf("Programme: \n");
	scanf("%s", current->programme);
	printf("Grade: \n");
	scanf("%f",  &current->grade);

	printf("Add more student? (1=Y, 0 = N): \n");
	scanf("%d", &selection);

	while(selection)
	{
		current->next = (Student*)calloc(1, sizeof(Student));
		current = current->next;

		/*fill the new node */
		printf("Student name: \n");
		scanf("%s", current->name);
		printf("Programme: \n");
		scanf("%s", current->programme);
		printf("Grade: \n");
		scanf("%f",  &current->grade);

		printf("Add more student? (1=Y, 0 = N): \n");
		scanf("%d", &selection);
	}
	current->next = NULL; /* in case the last node */
	return first; /* return the address of the first node */
}

void printStudentList(Student *start)
{
	int count = 0;
	Student* p = NULL;
	for(p = start; p != NULL; p = p->next)
	{
		++count;
		printf("Student #%d: ", count);
		printf("%s, %s, %.2f\n", p->name, p->programme, p->grade);
	}
}
