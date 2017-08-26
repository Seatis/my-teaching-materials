#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {MATH, HISTORY, ENGLISH, SCIENCE} subject;

typedef struct {
	subject subject;
	int value;
} grade;

typedef struct {
	char name[128];
	int age;
	grade *grades;
	int grade_count;
} student;

// TODO:
// Create a function the constructs a student (returns a pointer to a new student)
// It should take it's name and it's age as parameter
// It should allocate 5 grades
// It should set the grade_count to 0
#define GRADE_ALLOCATION 5
student *create_student(char *name, int age)
{
	// Allocate 5 grades
	grade *grades = (grade *)calloc(GRADE_ALLOCATION, sizeof(grade));
	// Create new student
	// We have to use dynamic memory allocation
	student *stud = (student *)malloc(sizeof(student));
	stud->age = age;
	// We have to copy the content of the "name" not just copying the pointer
	strcpy(stud->name, name);
	stud->grades = grades;
	stud->grade_count = 0;

	return stud;
}

// TODO:
// Create a function that takes 3 parameters:
// A pointer to a student
// A subject
// An int (1-5)
// It should add a new grade of the subject to the student's grades array
void add_grade(student *student, subject subject, int num)
{
	student->grades[student->grade_count].subject = subject;
	student->grades[student->grade_count].value = num;
	student->grade_count++;
}

// TODO:
// Create a function that takes a student as a pointer and returns the subject
// that the student has worst grade in
subject get_worst_grade_subject(student *student)
{
	grade *worst_grade_ptr;
	int worst_grade_value = 5;
	for (int i = 0; i < student->grade_count; i++) {
		if (student->grades[i].value < worst_grade_value) {
			worst_grade_value = student->grades[i].value;
			worst_grade_ptr = &(student->grades[i]);
		}
	}

	return worst_grade_ptr->subject;
}

// TODO:
// Create a function that deconstructs a student
// It should take a pointer that points to the student
// It should free each grade and the student itself
void Deletestudent(student *student)
{
	free(student->grades);
	free(student);
}

int main()
{
	student *ili = create_student("Ili", 11);
	add_grade(ili, HISTORY, 5);
	add_grade(ili, ENGLISH, 5);
	add_grade(ili, SCIENCE, 3);

	printf("%s's worst grade subject is: %d\n", ili->name, get_worst_grade_subject(ili));

	return 0;
}
