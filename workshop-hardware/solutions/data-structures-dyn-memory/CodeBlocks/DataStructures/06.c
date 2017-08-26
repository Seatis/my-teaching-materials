#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {MATH, HISTORY, ENGLISH, SCIENCE} subject_t;

typedef struct {
	subject_t subject;
	int value;
} grade_t;

typedef struct {
	char name[128];
	int age;
	grade_t *grades;
	int grade_count;
} student_t;

// TODO:
// Create a function the constructs a Student (returns a pointer to a new student)
// It should take it's name and it's age as parameter
// It should allocate 5 grades
// It should set the grade_count to 0
#define GRADE_ALLOCATION 5
student_t *create_student(char *name, int age)
{
	// Allocate 5 grades
	grade_t *grades = (grade_t *)calloc(GRADE_ALLOCATION, sizeof(grade_t));
	// Create new Student
	// We have to use dynamic memory allocation
	student_t *student = (student_t *)malloc(sizeof(student_t));
	student->age = age;
	// We have to copy the content of the "name" not just copying the pointer
	strcpy(student->name, name);
	student->grades = grades;
	student->grade_count = 0;

	return student;
}

// TODO:
// Create a function that takes 3 parameters:
// A pointer to a Student
// A Subject
// An int (1-5)
// It should add a new grade of the subject to the student's grades array
void add_grade(student_t *student, subject_t subject, int num)
{
	student->grades[student->grade_count].subject = subject;
	student->grades[student->grade_count].value = num;
	student->grade_count++;
}

// TODO:
// Create a function that takes a Student as a pointer and returns the subject
// that the student has worst grade in
subject_t get_worst_grade_subjet(student_t *student)
{
	grade_t *worst_grade_ptr;
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
// Create a function that deconstructs a Student
// It should take a pointer that points to the student
// It should free each grade_t and the Student itself
void delete_student(student_t *student)
{
	free(student->grades);
	free(student);
}

int main()
{
	student_t *ili = create_student("Ili", 11);
	add_grade(ili, HISTORY, 5);
	add_grade(ili, ENGLISH, 5);
	add_grade(ili, SCIENCE, 3);

	printf("%s's worst grade subject is: %d\n", ili->name, get_worst_grade_subjet(ili));

	return 0;
}
